// driver/driver.go
package driver

import (
	"bytes"
	"fmt"
	"net"
	"os"
	"path/filepath"
	"runtime"
	"strconv"
	"strings"
	"sync"
	"time"

	"mudscript/ast"
	"mudscript/evaluator"
	"mudscript/lexer"
	"mudscript/object"
	"mudscript/parser"
	"mudscript/preprocessor"
)

// DriverConfig 運行時期的配置
type DriverConfig struct {
	MudLibPath    string
	MasterFile    string
	HeartBeatTick time.Duration
}

type ScheduledCall struct {
	Caller   *object.LPCObject
	FuncName string
	Args     []object.Object
	FireTime time.Time
}

type PlayerConnection struct {
	Conn     net.Conn
	Object   *object.LPCObject
	IsActive bool

	History  []string
	MaxHist  int
	sendChan chan string
}

func NewPlayerConnection(conn net.Conn, obj *object.LPCObject) *PlayerConnection {
	p := &PlayerConnection{
		Conn:     conn,
		Object:   obj,
		IsActive: true,
		History:  make([]string, 0),
		MaxHist:  20,                           // 最多記錄 20 筆
		sendChan: make(chan string, 256),       // 256 筆訊息的緩衝區
	}

	// 啟動專屬的「背景發送寫手」，避免阻塞主程式
	go p.writePump()
	return p
}

// 背景發送迴圈 (Write Pump)
func (p *PlayerConnection) writePump() {
	defer p.Conn.Close()
	for msg := range p.sendChan {
		if !p.IsActive { break }
		_, err := p.Conn.Write([]byte(msg))
		if err != nil {
			p.IsActive = false
			break
		}
	}
}

func (p *PlayerConnection) Send(msg string) {
	if !p.IsActive { return }
	
	select {
	case p.sendChan <- msg:
		// 成功放入緩衝區
	default:
		// 緩衝區滿了 (玩家網路太卡)，為了保護伺服器，直接丟棄訊息
		// TODO: 強制斷線 p.IsActive = false
	}
}

// 處理命令歷史與 ! 展開
func (p *PlayerConnection) ExpandHistory(input string) string {
	input = strings.TrimSpace(input)
	if input == "" { return "" }

	// 如果輸入 !!，展開為上一次的指令
	if input == "!!" {
		if len(p.History) == 0 {
			p.Send("沒有歷史指令可供重複。\r\n")
			return ""
		}
		cmd := p.History[len(p.History)-1]
		p.Send(cmd + "\r\n") // 顯示展開後的指令
		return cmd
	}

	// 處理 ! 開頭但不是 !! 的狀況 (可後續擴充如 !1, !2 等)
	if strings.HasPrefix(input, "!") {
		// TODO: 這裡先簡單支援 !!，其他的你可以擴充
		p.Send("目前僅支援 !! 重發上一個指令。\r\n")
		return ""
	}

	// 處理一般指令：加入歷史紀錄
	if len(p.History) == 0 || p.History[len(p.History)-1] != input {
		p.History = append(p.History, input)
		// 限制歷史紀錄長度
		if len(p.History) > p.MaxHist {
			p.History = p.History[1:]
		}
	}

	return input
}

// 註冊與取得互動玩家
func (d *Driver) RegisterInteractive(obj *object.LPCObject, conn *PlayerConnection) {
	if obj == nil || conn == nil { return }
    d.interactiveObjects.Store(obj.Filename, conn)
    obj.IsInteractive = true
    fmt.Printf("DEBUG: RegisterInteractive -> %s\n", obj.Filename)
}

func (d *Driver) UnregisterInteractive(obj *object.LPCObject) {
	if obj == nil { return }
    d.interactiveObjects.Delete(obj.Filename)
    obj.IsInteractive = false
    fmt.Printf("DEBUG: UnregisterInteractive -> %s\n", obj.Filename)
}

func (d *Driver) GetConnectionFromObject(obj *object.LPCObject) *PlayerConnection {
	if obj == nil { return nil }
    
    // 直接用 Filename 查
    if conn, ok := d.interactiveObjects.Load(obj.Filename); ok {
        return conn.(*PlayerConnection)
    }
    
    // 相容舊的 pointer 查詢（防萬一）
    if conn, ok := d.interactiveObjects.Load(obj); ok {
        return conn.(*PlayerConnection)
    }
    
    return nil
}

// Driver MUD 伺服器核心
type Driver struct {
	mu           sync.RWMutex
	ObjectTable  map[string]*object.LPCObject
	Heartbeats   map[*object.LPCObject]bool
	CallOuts     []*ScheduledCall
	Config       DriverConfig
	shutdownCh   chan struct{}

	MasterObject *object.LPCObject
	RootUID      string
	BackboneUID  string

	// 使用 Goroutine ID 來追蹤當前正在執行的玩家
	playerContexts sync.Map 
	interactiveObjects sync.Map
}

func New(config DriverConfig) *Driver {
	if config.HeartBeatTick == 0 {
		config.HeartBeatTick = 2 * time.Second
	}
	return &Driver{
		ObjectTable: make(map[string]*object.LPCObject),
		Heartbeats:  make(map[*object.LPCObject]bool),
		CallOuts:    make([]*ScheduledCall, 0),
		Config:      config,
		shutdownCh:  make(chan struct{}),
	}
}

// === [並發安全上下文機制] ===

// 取得當前 Goroutine ID
func getGID() uint64 {
	b := make([]byte, 64)
	b = b[:runtime.Stack(b, false)]
	b = bytes.TrimPrefix(b, []byte("goroutine "))
	b = b[:bytes.IndexByte(b, ' ')]
	n, _ := strconv.ParseUint(string(b), 10, 64)
	return n
}

// 取得當前 Goroutine 對應的玩家
func (d *Driver) GetCurrentPlayer() *PlayerConnection {
	if p, ok := d.playerContexts.Load(getGID()); ok {
		return p.(*PlayerConnection)
	}
	return nil
}

// 專門給玩家網路層呼叫的進入點 (自動綁定上下文)
func (d *Driver) RunCommand(p *PlayerConnection, obj *object.LPCObject, funcName string, args []object.Object) object.Object {
	gid := getGID()
	// 執行前，將當前 goroutine 綁定給這個玩家
	d.playerContexts.Store(gid, p)
	
	// 執行完畢後自動清理，避免記憶體洩漏與污染
	defer d.playerContexts.Delete(gid)

	// 呼叫原本的執行邏輯
	return d.CallFunction(obj, funcName, args)
}

// ============================

func (d *Driver) LoadObject(filename string) (*object.LPCObject, error) {
	d.mu.RLock()
	if obj, exists := d.ObjectTable[filename]; exists {
		d.mu.RUnlock()
		return obj, nil
	}
	d.mu.RUnlock()

	cleanName := strings.TrimPrefix(filename, "/")
	fullPath := filepath.Join(d.Config.MudLibPath, cleanName)

	content, err := os.ReadFile(fullPath)
	if err != nil {
		return nil, fmt.Errorf("failed to read file %s: %v", filename, err)
	}

	pp := preprocessor.New(d.Config.MudLibPath)
	processedContent, err := pp.Process(filename, string(content))
	if err != nil {
		return nil, fmt.Errorf("preprocessor error: %v", err)
	}

	l := lexer.New(processedContent)
	p := parser.New(l)
	program := p.ParseProgram()

	if len(p.Errors()) > 0 {
		return nil, fmt.Errorf("parse error in %s: %v", filename, p.Errors())
	}

	env := object.NewEnvironment()
	lpcObj := &object.LPCObject{
		Filename:  filename,
		Vars:      env,
		Functions: make(map[string]*object.Function),
		Inherits:  make([]*object.LPCObject, 0),
	}

	for _, stmt := range program.Statements {
		if inheritStmt, ok := stmt.(*ast.InheritStatement); ok {
			parentFile := inheritStmt.Path
			if !strings.HasSuffix(parentFile, ".c") {
				parentFile += ".c"
			}
			parentObj, err := d.LoadObject(parentFile)
			if err != nil {
				return nil, fmt.Errorf("無法繼承 %s: %v", parentFile, err)
			}
			lpcObj.Inherits = append(lpcObj.Inherits, parentObj)
			baseName := strings.TrimSuffix(filepath.Base(parentFile), ".c")

			for k, v := range parentObj.Vars.GetAll() {
				env.Set(k, deepCopyLPCValue(v))
				if _, isFunc := v.(*object.Function); isFunc {
					if !strings.Contains(k, "::") {
						env.Set("::"+k, v)
						env.Set(baseName+"::"+k, v)
					}
				}
			}
		}
	}

	d.SetupEfuns(lpcObj)
	evaluator.Eval(program, env)

	d.mu.Lock()
	d.ObjectTable[filename] = lpcObj
	d.mu.Unlock()

	d.CallFunction(lpcObj, "create", nil)
	return lpcObj, nil
}

func (d *Driver) CloneObject(filename string) (*object.LPCObject, error) {
	blueprint, err := d.LoadObject(filename)
	if err != nil {
		return nil, err
	}

	clone := &object.LPCObject{
		Filename:  filename + "#" + generateCloneID(),
		Vars:      object.NewEnvironment(),
		Functions: blueprint.Functions,
		Inherits:  blueprint.Inherits,
	}

	d.SetupEfuns(clone)
	for k, v := range blueprint.Vars.GetAll() {
		clone.Vars.Set(k, deepCopyLPCValue(v))
	}

	d.CallFunction(clone, "create", nil)
	return clone, nil
}

var cloneCounter int
func generateCloneID() string {
	cloneCounter++
	return fmt.Sprintf("%d", cloneCounter)
}

func (d *Driver) Start() error {
	masterFile := d.Config.MasterFile
	if masterFile == "" {
		masterFile = "/master.c"
	}

	fmt.Println("🚀 Driver 啟動中... 準備載入 Master Object:", masterFile)
	master, err := d.LoadObject(masterFile)
	if err != nil {
		return fmt.Errorf("致命錯誤: 無法載入 master.c: %v", err)
	}

	d.mu.Lock()
	d.MasterObject = master
	d.mu.Unlock()

	if res := d.CallFunction(master, "get_root_uid", nil); res != nil {
		if s, ok := res.(*object.String); ok {
			d.RootUID = s.Value
		}
	}
	if res := d.CallFunction(master, "get_bb_uid", nil); res != nil {
		if s, ok := res.(*object.String); ok {
			d.BackboneUID = s.Value
		}
	}

	fmt.Printf("✅ Master 載入成功 (RootUID: %s, BackboneUID: %s)\n", d.RootUID, d.BackboneUID)
	go d.runGameLoop()
	return nil
}

func (d *Driver) Stop() {
	close(d.shutdownCh)
}

func (d *Driver) runGameLoop() {
	ticker := time.NewTicker(d.Config.HeartBeatTick)
	defer ticker.Stop()

	for {
		select {
		case <-ticker.C:
			d.processHeartBeats()
			d.processCallOuts()
		case <-d.shutdownCh:
			return
		}
	}
}

func (d *Driver) processHeartBeats() {
	d.mu.RLock()
	targets := make([]*object.LPCObject, 0, len(d.Heartbeats))
	for obj := range d.Heartbeats {
		targets = append(targets, obj)
	}
	d.mu.RUnlock()

	for _, obj := range targets {
		// 若這個物件是互動玩家，heart_beat() 執行期間需要綁定玩家 context，
		// 這樣 write() 才能把訊息正確送給對應的 TCP 連線。
		if conn := d.GetConnectionFromObject(obj); conn != nil {
			gid := getGID()
			d.playerContexts.Store(gid, conn)
			d.CallFunction(obj, "heart_beat", nil)
			d.playerContexts.Delete(gid)
		} else {
			// 非互動物件（NPC、房間）直接呼叫
			d.CallFunction(obj, "heart_beat", nil)
		}
	}
}

func (d *Driver) CallOut(caller *object.LPCObject, funcName string, delay time.Duration, args ...object.Object) {
	fireTime := time.Now().Add(delay)
	d.mu.Lock()
	defer d.mu.Unlock()
	d.CallOuts = append(d.CallOuts, &ScheduledCall{
		Caller: caller, FuncName: funcName, Args: args, FireTime: fireTime,
	})
}

func (d *Driver) processCallOuts() {
	now := time.Now()
	d.mu.Lock()
	var pending, ready []*ScheduledCall
	for _, call := range d.CallOuts {
		if now.After(call.FireTime) || now.Equal(call.FireTime) {
			ready = append(ready, call)
		} else {
			pending = append(pending, call)
		}
	}
	d.CallOuts = pending
	d.mu.Unlock()

	for _, call := range ready {
		d.CallFunction(call.Caller, call.FuncName, call.Args)
	}
}

func (d *Driver) SetHeartBeat(obj *object.LPCObject, enable bool) {
	d.mu.Lock()
	defer d.mu.Unlock()
	if enable {
		d.Heartbeats[obj] = true
	} else {
		delete(d.Heartbeats, obj)
	}
}

func (d *Driver) CallFunction(obj *object.LPCObject, funcName string, args []object.Object) object.Object {
	fmt.Printf("DEBUG: [%s]->%s() 被呼叫\n", obj.Filename, funcName)
	if obj.Vars != nil {
		obj.Vars.Set("this_object", &object.Builtin{
			Fn: func(args ...object.Object) object.Object { return obj },
		})
	}

	fnObj, ok := obj.Vars.Get(funcName)
	if !ok { return nil }

	fn, ok := fnObj.(*object.Function)
	if !ok { return object.NewError("%s is not a function", funcName) }

	extendedEnv := object.NewEnclosedEnvironment(obj.Vars)
	for i, param := range fn.Parameters {
		if i < len(args) {
			extendedEnv.Set(param.Value, args[i])
		} else {
			extendedEnv.Set(param.Value, &object.Nil{})
		}
	}

	evaluated := evaluator.Eval(fn.Body, extendedEnv)

	if errObj, ok := evaluated.(*object.Error); ok {
		if d.MasterObject != nil && obj != d.MasterObject {
			d.CallFunction(d.MasterObject, "runtime_error", []object.Object{
				&object.String{Value: errObj.Message},
				&object.String{Value: obj.Filename},
			})
		} else {
			fmt.Printf("🔥 系統崩潰: %s\n", errObj.Message)
		}
		return nil
	}

	if returnValue, ok := evaluated.(*object.ReturnValue); ok {
		return returnValue.Value
	}
	return evaluated
}

func (d *Driver) MoveObject(item *object.LPCObject, dest *object.LPCObject) {
	if item == nil || dest == nil || item.IsDestructed || dest.IsDestructed { return }
	if item.Location != nil {
		oldInv := item.Location.Inventory
		newInv := make([]*object.LPCObject, 0, len(oldInv))
		for _, obj := range oldInv {
			if obj != item { newInv = append(newInv, obj) }
		}
		item.Location.Inventory = newInv
	}
	item.Location = dest
	dest.Inventory = append(dest.Inventory, item)
	d.CallFunction(item, "init", nil)
}

func (d *Driver) DestructObject(obj *object.LPCObject) {
	if obj == nil || obj.IsDestructed { return }
	
	fmt.Printf("DEBUG: DestructObject called on %s\n", obj.Filename)

	// === 核心修正：精準找到對應的連線 ===
	var targetConn *PlayerConnection

	// 方法1：直接用 Filename 查（推薦主要方式）
	if conn, ok := d.interactiveObjects.Load(obj.Filename); ok {
		targetConn = conn.(*PlayerConnection)
		fmt.Printf("DEBUG: 直接透過 Filename 找到連線 %s\n", obj.Filename)
	}

	// 方法2：如果沒找到，用 pointer 比對（防 clone 後 Filename 不同的情況）
	if targetConn == nil {
		d.interactiveObjects.Range(func(key, value interface{}) bool {
			if pconn, ok := value.(*PlayerConnection); ok {
				if pconn.Object == obj {  // 嚴格比對 pointer
					targetConn = pconn
					fmt.Printf("DEBUG: 透過 pointer 比對找到連線 %s\n", pconn.Object.Filename)
					return false
				}
			}
			return true
		})
	}

	// 方法3：最後手段 - 根據 Filename 前綴（只在必要時使用）
	if targetConn == nil && strings.HasPrefix(obj.Filename, "/user.c") {
		d.interactiveObjects.Range(func(key, value interface{}) bool {
			if pconn, ok := value.(*PlayerConnection); ok {
				if pconn.Object != nil && pconn.Object.Filename == obj.Filename {
					targetConn = pconn
					fmt.Printf("DEBUG: 透過精準 Filename 前綴找到 %s\n", pconn.Object.Filename)
					return false
				}
			}
			return true
		})
	}

	// === 執行斷線 ===
	if targetConn != nil {
		fmt.Printf("DEBUG: 強制關閉玩家連線 %s\n", targetConn.Object.Filename)
		targetConn.IsActive = false
		if targetConn.Conn != nil {
			targetConn.Conn.Close()
		}
		d.UnregisterInteractive(targetConn.Object)
	} else {
		fmt.Printf("DEBUG: 完全找不到對應連線 for %s\n", obj.Filename)
	}

	// 後續清理邏輯...
	obj.IsDestructed = true
	d.SetHeartBeat(obj, false)

	for _, item := range obj.Inventory {
		d.MoveObject(item, obj.Location)
	}

	if obj.Location != nil {
		d.MoveObject(obj, nil)
	}

	d.mu.Lock()
	delete(d.ObjectTable, obj.Filename)
	d.mu.Unlock()
}

func deepCopyLPCValue(obj object.Object) object.Object {
	if obj == nil { return nil }
	switch o := obj.(type) {
	case *object.Array:
		newElems := make([]object.Object, len(o.Elements))
		for i, el := range o.Elements {
			newElems[i] = deepCopyLPCValue(el)
		}
		return &object.Array{Elements: newElems}
	case *object.Mapping:
		newPairs := make(map[object.HashKey]object.HashPair)
		for k, v := range o.Pairs {
			newPairs[k] = object.HashPair{
				Key:   deepCopyLPCValue(v.Key),
				Value: deepCopyLPCValue(v.Value),
			}
		}
		return &object.Mapping{Pairs: newPairs}
	default:
		return obj
	}
}

// AcceptConnection 為新連線建立玩家物件，並在 master.connect() 執行期間
// 將玩家上下文綁定到當前 goroutine，讓 connect() 內的 write() 能正確輸出。
func (d *Driver) AcceptConnection(pConn *PlayerConnection) *object.LPCObject {
	if d.MasterObject == nil { return nil }

	// 先暫時把 pConn 綁到當前 goroutine，讓 master.connect() 裡的 write() 能用
	gid := getGID()
	d.playerContexts.Store(gid, pConn)
	defer d.playerContexts.Delete(gid)

	result := d.CallFunction(d.MasterObject, "connect", nil)
	if loginObj, ok := result.(*object.LPCObject); ok {
		return loginObj
	}
	return nil
}
