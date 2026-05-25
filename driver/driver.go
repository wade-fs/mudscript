// driver/driver.go
package driver

import (
	"bytes"
	"fmt"
	"io/fs"
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

type RuntimeError struct {
	Message  string
	File     string
	Function string
	Stack    []string // 呼叫堆疊
}

type callFrame struct {
	File     string
	Function string
	Object   *object.LPCObject // 🚀 新增：執行此框架的物件
}

func (d *Driver) getCallStack() []callFrame {
	gid := getGID()
	if val, ok := d.callStacks.Load(gid); ok {
		return val.([]callFrame)
	}
	return nil
}

func (d *Driver) pushFrame(f callFrame) {
	gid := getGID()
	stack := d.getCallStack()
	d.callStacks.Store(gid, append(stack, f))
}

func (d *Driver) popFrame() {
	gid := getGID()
	stack := d.getCallStack()
	if len(stack) > 0 {
		d.callStacks.Store(gid, stack[:len(stack)-1])
	} else {
		d.callStacks.Delete(gid)
	}
}

func (d *Driver) buildCallStack() []string {
	stack := d.getCallStack()
	var s []string
	for _, f := range stack {
		s = append(s, fmt.Sprintf("%s::%s()", f.File, f.Function))
	}
	return s
}

func (d *Driver) GetPreviousObject() *object.LPCObject {
	stack := d.getCallStack()
	if len(stack) < 2 {
		return nil
	}
	
	// 堆疊頂端是目前正在執行的 (this_object)
	// 前一個就是 previous_object
	// 但要排除連續在同一個物件內的函式呼叫
	currentObj := stack[len(stack)-1].Object
	for i := len(stack) - 2; i >= 0; i-- {
		if stack[i].Object != currentObj {
			return stack[i].Object
		}
	}
	return nil
}

func (e *RuntimeError) Error() string {
	var sb strings.Builder
	sb.WriteString(fmt.Sprintf("🔥 Runtime Error in %s::%s()\n", e.File, e.Function))
	sb.WriteString(fmt.Sprintf("   %s\n\n", e.Message))

	if len(e.Stack) > 0 {
		sb.WriteString("Call Stack:\n")
		for i, frame := range e.Stack {
			sb.WriteString(fmt.Sprintf("  %2d. %s\n", len(e.Stack)-i, frame))
		}
	}
	return sb.String()
}

// DriverConfig 運行時期的配置
type DriverConfig struct {
	MudLibPath      string
	MasterFile      string
	HeartBeatTick   time.Duration
	CleanUpInterval time.Duration // 🚀 新增：垃圾回收間隔
	EmbeddedFS      fs.FS
}

type ScheduledCall struct {
	Caller   *object.LPCObject
	FuncName string
	Args     []object.Object
	FireTime time.Time
}

type PlayerConnection struct {
	SessionID      string // 🚀 新增：WebSocket 工作階段 ID
	Conn           net.Conn
	Object         *object.LPCObject
	Username       string
	IsActive       bool
	History        []string
	MaxHist        int
	sendChan       chan string
	NextInputFunc  string
	InputHidden    bool
	OutputCallback func(msg string)
	CurrentVerb    string // 🚀 新增：儲存當前執行的指令動詞
}

func NewPlayerConnection(conn net.Conn, obj *object.LPCObject) *PlayerConnection {
	p := &PlayerConnection{
		Conn:     conn,
		Object:   obj,
		IsActive: true,
		History:  make([]string, 0),
		MaxHist:  20,                     // 最多記錄 20 筆
		sendChan: make(chan string, 256), // 256 筆訊息的緩衝區
	}

	// 啟動專屬的「背景發送寫手」，避免阻塞主程式
	go p.writePump()
	return p
}

// 背景發送迴圈 (Write Pump)
func (p *PlayerConnection) writePump() {
	// 如果是傳統 TCP 連線，才需要 defer 關閉
	if p.Conn != nil {
		defer p.Conn.Close()
	}

	for msg := range p.sendChan {
		if !p.IsActive {
			break
		}

		// 👉 優先判定：如果有設定 Callback，就走 WebSocket 輸出
		if p.OutputCallback != nil {
			p.OutputCallback(msg)
			continue
		}

		// 否則，如果連線存在，走傳統 TCP 輸出
		if p.Conn != nil {
			_, err := p.Conn.Write([]byte(msg))
			if err != nil {
				p.IsActive = false
				break
			}
		}
	}
}

func (p *PlayerConnection) Send(msg string) {
	if !p.IsActive {
		return
	}

	select {
	case p.sendChan <- msg:
		// 成功放入緩衝區
	default:
		// 緩衝區滿了 (彈性丟棄)
	}
}

// 處理命令歷史與 ! 展開
func (p *PlayerConnection) ExpandHistory(input string) string {
	input = strings.TrimSpace(input)
	if input == "" {
		return ""
	}

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

	if strings.HasPrefix(input, "!") {
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
	if obj == nil || conn == nil {
		return
	}
	d.interactiveObjects.Store(obj.Filename, conn)
	obj.IsInteractive = true
}

func (d *Driver) UnregisterInteractive(obj *object.LPCObject) {
	if obj == nil {
		return
	}
	d.interactiveObjects.Delete(obj.Filename)
	obj.IsInteractive = false
}

// 🚀 新增：更新玩家顯示名稱到連線中
func (d *Driver) UpdatePlayerUsername(obj *object.LPCObject, name string) {
	if obj == nil { return }
	if val, ok := d.interactiveObjects.Load(obj.Filename); ok {
		if conn, ok := val.(*PlayerConnection); ok && conn != nil {
			conn.Username = name

			// 🚀 通知信令中心同步名稱
			if d.OnUsernameUpdate != nil {
				d.OnUsernameUpdate(conn.SessionID, name)
			}
		}
	}
}

func (d *Driver) GetConnectionFromObject(obj *object.LPCObject) *PlayerConnection {
	if obj == nil {
		return nil
	}
	if conn, ok := d.interactiveObjects.Load(obj.Filename); ok {
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
	SimulEfunObj *object.LPCObject // 🚀 新增：模擬 Efun 物件
	RootUID      string
	BackboneUID  string

	// 使用 Goroutine ID 來追蹤當前正在執行的玩家
	playerContexts     sync.Map
	interactiveObjects sync.Map
	callStacks         sync.Map // 🚀 新增：goroutine ID -> []callFrame

	// 🚀 P2P 整合
	OnP2PMessage     func(sender, content string)
	P2PSendChat      func(sender, content string)
	OnUsernameUpdate func(sid string, newName string)
}

func New(config DriverConfig) *Driver {
	os.MkdirAll(filepath.Join(config.MudLibPath, "data/user"), 0755)
	if config.HeartBeatTick == 0 {
		config.HeartBeatTick = 2 * time.Second
	}
	if config.CleanUpInterval == 0 {
		config.CleanUpInterval = 5 * time.Minute // 🚀 預設 5 分鐘
	}
	return &Driver{
		ObjectTable: make(map[string]*object.LPCObject),
		Heartbeats:  make(map[*object.LPCObject]bool),
		CallOuts:    make([]*ScheduledCall, 0),
		Config:      config,
		shutdownCh:  make(chan struct{}),
	}
}

//取得當前 Goroutine ID
func getGID() uint64 {
	b := make([]byte, 64)
	b = b[:runtime.Stack(b, false)]
	b = bytes.TrimPrefix(b, []byte("goroutine "))
	b = b[:bytes.IndexByte(b, ' ')]
	n, _ := strconv.ParseUint(string(b), 10, 64)
	return n
}

func (d *Driver) GetThisObject() *object.LPCObject {
	if p := d.GetCurrentPlayer(); p != nil && p.Object != nil {
		return p.Object
	}
	return nil
}

// 🚀 新增：暫時設定玩家上下文，回傳恢復函式
func (d *Driver) setPlayerContext(p *PlayerConnection) func() {
	gid := getGID()
	old, ok := d.playerContexts.Load(gid)
	d.playerContexts.Store(gid, p)
	return func() {
		if ok {
			d.playerContexts.Store(gid, old)
		} else {
			d.playerContexts.Delete(gid)
		}
	}
}

// 🚀 新增：尋找物件對應的網路連線
func (d *Driver) getPlayerConnection(obj *object.LPCObject) *PlayerConnection {
	if obj == nil {
		return nil
	}
	if val, ok := d.interactiveObjects.Load(obj.Filename); ok {
		return val.(*PlayerConnection)
	}
	// 備援：全域掃描
	var found *PlayerConnection
	d.interactiveObjects.Range(func(key, value interface{}) bool {
		p := value.(*PlayerConnection)
		if p.Object == obj {
			found = p
			return false
		}
		return true
	})
	return found
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
	oldContext, hasOld := d.playerContexts.Load(gid)
	if p != nil {
		d.playerContexts.Store(gid, p)
	}
	defer func() {
		if hasOld {
			d.playerContexts.Store(gid, oldContext)
		} else {
			d.playerContexts.Delete(gid)
		}
	}()
	return d.CallFunction(obj, funcName, args)
}

func (d *Driver) NormalizePath(path string) string {
	cleanPath := filepath.Clean(path)
	cleanPath = filepath.ToSlash(cleanPath)
	if !strings.HasPrefix(cleanPath, "/") {
		cleanPath = "/" + cleanPath
	}
	return cleanPath
}

// 🚀 新增：路徑解析 (支援 ./ 與 ../，以及跨服沙盒自動映射)
func (d *Driver) ResolvePath(basePath, relPath string) string {
	// 1. 處理相對路徑
	if strings.HasPrefix(relPath, ".") {
		dir := filepath.Dir(basePath)
		resolved := filepath.Join(dir, relPath)
		res := filepath.ToSlash(resolved)
		if !strings.HasPrefix(res, "/") {
			res = "/" + res
		}
		return res
	}

	// 2. 處理絕對路徑 (關鍵：跨服沙盒自動重導向)
	// 如果發起呼叫的物件 (basePath) 位於遠端緩存目錄中
	// 例如：/data/fs_cache/fantasy.space/area/newbie/room_0_0.c
	if strings.HasPrefix(basePath, "/data/fs_cache/") {
		// 提取 mudlib_id
		parts := strings.Split(strings.TrimPrefix(basePath, "/data/fs_cache/"), "/")
		if len(parts) > 0 {
			mudlibID := parts[0]
			sandboxPrefix := "/data/fs_cache/" + mudlibID

			// 如果目標路徑是以 / 開頭的絕對路徑，且不在「全域白名單」中
			if strings.HasPrefix(relPath, "/") {
				// 白名單：不需要重導向的目錄
				if !strings.HasPrefix(relPath, "/std/") &&
					!strings.HasPrefix(relPath, "/secure/") &&
					!strings.HasPrefix(relPath, "/include/") &&
					!strings.HasPrefix(relPath, "/cmds/") &&
					!strings.HasPrefix(relPath, "/data/fs_cache/") {
					
					// 自動加上沙盒前綴
					// 例如：/area/newbie/... -> /data/fs_cache/fantasy.space/area/newbie/...
					return sandboxPrefix + relPath
				}
			}
		}
	}

	// 3. 一般絕對路徑處理
	if !strings.HasPrefix(relPath, "/") {
		return "/" + relPath
	}
	return relPath
}

// 🚀 新增：混合模式讀取檔案
// 🚀 新增：混合模式讀取檔案 (支援 .c 尾碼自動修復)
func (d *Driver) ReadFile(filename string) ([]byte, error) {
	tryFiles := []string{filename}
	if !strings.HasSuffix(filename, ".c") {
		tryFiles = append(tryFiles, filename+".c")
	}

	for _, f := range tryFiles {
		relPath := strings.TrimPrefix(f, "/")

		// 1. 優先從實體磁碟讀取
		fullPath := filepath.Join(d.Config.MudLibPath, relPath)
		if _, err := os.Stat(fullPath); err == nil {
			return os.ReadFile(fullPath)
		}

		// 2. 備援從嵌入式系統讀取
		if d.Config.EmbeddedFS != nil {
			embedPath := filepath.Join("mudlib", relPath)
			if content, err := fs.ReadFile(d.Config.EmbeddedFS, embedPath); err == nil {
				return content, nil
			}
		}
	}

	return nil, fmt.Errorf("file not found: %s", filename)
}
// LoadObject 載入並編譯一個 LPC 檔案成為藍圖物件 (含執行 create)
func (d *Driver) LoadObject(filename string) (*object.LPCObject, error) {
	obj, err := d.loadObjectInternal(filename)
	if err != nil {
		return nil, err
	}
	
	d.CallFunction(obj, "create", nil)
	return obj, nil
}

func (d *Driver) loadObjectInternal(filename string) (*object.LPCObject, error) {
	filename = d.NormalizePath(filename)
	d.mu.RLock()
	if obj, exists := d.ObjectTable[filename]; exists {
		d.mu.RUnlock()
		return obj, nil
	}
	d.mu.RUnlock()

	// 使用混合模式讀取檔案內容
	content, err := d.ReadFile(filename)
	if err != nil {
		return nil, err
	}

	pp := preprocessor.New(d.Config.MudLibPath)
	if d.Config.EmbeddedFS != nil {
		pp.SetEmbeddedFS(d.Config.EmbeddedFS)
	}
	processedContent, err := pp.Process(filename, string(content))
	if err != nil {
		return nil, fmt.Errorf("preprocessor error: %v", err)
	}

	l := lexer.New(processedContent)
	p := parser.New(l)
	program := p.ParseProgram()

	if len(p.Errors()) > 0 {
		return nil, d.formatParserErrors(filename, p.Errors())
	}

	env := object.NewEnvironment()
	lpcObj := &object.LPCObject{
		Filename:     filename,
		Vars:         env,
		Functions:    make(map[string]*object.Function),
		Inherits:     make([]*object.LPCObject, 0),
		LastActivity: time.Now().Unix(),
	}

	// 🚩 關鍵：先註冊到 ObjectTable 再初始化，防止循環繼承/移動导致的崩潰
	d.mu.Lock()
	d.ObjectTable[filename] = lpcObj
	d.mu.Unlock()

	for _, stmt := range program.Statements {
		if inheritStmt, ok := stmt.(*ast.InheritStatement); ok {
			parentFile := d.ResolvePath(filename, inheritStmt.Path)
			if !strings.HasSuffix(parentFile, ".c") {
				parentFile += ".c"
			}
			parentObj, err := d.loadObjectInternal(parentFile)
			if err != nil {
				return nil, fmt.Errorf("無法繼承 %s: %v", parentFile, err)
			}
			lpcObj.Inherits = append(lpcObj.Inherits, parentObj)

			for k, v := range parentObj.Vars.GetAll() {
				if _, isBuiltin := v.(*object.Builtin); isBuiltin {
					continue
				}
				var copiedVal object.Object
				if fn, ok := v.(*object.Function); ok {
					copiedVal = &object.Function{
						Parameters: fn.Parameters,
						Body:       fn.Body,
						Env:        env, // 👈 關鍵：指派為子物件的環境
						OriginFile: fn.OriginFile,
					}
				} else {
					copiedVal = deepCopyLPCValue(v)
				}
				env.Set(k, copiedVal)
			}
		}
	}

	d.SetupEfuns(lpcObj)
	env.Set("__file__", &object.String{Value: filename})

	res := evaluator.Eval(program, env)
	if errObj, ok := res.(*object.Error); ok {
		return nil, fmt.Errorf("evaluation error in %s: %s", filename, errObj.Message)
	}

	return lpcObj, nil
}

func (d *Driver) CloneObject(filename string) (*object.LPCObject, error) {
	blueprint, err := d.LoadObject(filename)
	if err != nil {
		return nil, err
	}

	clone := &object.LPCObject{
		Filename:     filename + "#" + generateCloneID(),
		Vars:         object.NewEnvironment(),
		Functions:    blueprint.Functions,
		Inherits:     blueprint.Inherits,
		LastActivity: time.Now().Unix(),
	}

	d.SetupEfuns(clone)
	for k, v := range blueprint.Vars.GetAll() {
		if _, isBuiltin := v.(*object.Builtin); isBuiltin {
			continue
		}
		var copiedVal object.Object
		if fn, ok := v.(*object.Function); ok {
			copiedVal = &object.Function{
				Parameters: fn.Parameters,
				Body:       fn.Body,
				Env:        clone.Vars,
				OriginFile: fn.OriginFile,
			}
		} else {
			copiedVal = deepCopyLPCValue(v)
		}
		clone.Vars.Set(k, copiedVal)
	}

	dummyConn := &PlayerConnection{Object: clone}
	gid := getGID()
	oldContext, hasOld := d.playerContexts.Load(gid)
	d.playerContexts.Store(gid, dummyConn)
	defer func() {
		if hasOld {
			d.playerContexts.Store(gid, oldContext)
		} else {
			d.playerContexts.Delete(gid)
		}
	}()

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
		masterFile = d.DiscoverMasterFile()
	}

	fmt.Println("🚀 Driver 啟動中... 準備載入 Master Object:", masterFile)
	// 1. 只載入不執行 create
	master, err := d.loadObjectInternal(masterFile)
	if err != nil {
		return fmt.Errorf("致命錯誤: 無法載入 master.c: %v", err)
	}

	d.mu.Lock()
	d.MasterObject = master
	d.mu.Unlock()

	// 2. 從 Master 物件詢問 SimulEfun 路徑並載入
	if res := d.CallFunction(master, "get_simul_efun", nil); res != nil {
		if s, ok := res.(*object.String); ok && s.Value != "" {
			simul, err := d.loadObjectInternal(s.Value)
			if err == nil {
				d.mu.Lock()
				d.SimulEfunObj = simul
				d.mu.Unlock()
				fmt.Printf("✅ SimulEfun 載入成功: %s\n", s.Value)
				
				// 注入 SimulEfuns 到已經載入的 master (因為 master 載入時 SimulEfunObj 還沒設定)
				d.RegisterSimulEfuns(master)
				
				// 執行 SimulEfun 的 create
				d.CallFunction(simul, "create", nil)
			} else {
				fmt.Printf("⚠️ 無法載入 SimulEfun (%s): %v\n", s.Value, err)
			}
		}
	}

	// 3. 取得 UIDs (在執行 create 之前)
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

	fmt.Printf("✅ Master 準備就緒 (RootUID: %s, BackboneUID: %s)，開始執行初始化...\n", d.RootUID, d.BackboneUID)
	
	// 4. 執行 Master 的 create
	d.CallFunction(master, "create", nil)

	go d.runGameLoop()
	go d.runCleanUpLoop() // 🚀 啟動垃圾回收
	return nil
}
func (d *Driver) DiscoverMasterFile() string {
	configPath := filepath.Join(d.Config.MudLibPath, "include/config.h")
	content, err := os.ReadFile(configPath)
	if err != nil {
		return "/master.c"
	}
	lines := strings.Split(string(content), "\n")
	for _, line := range lines {
		if strings.Contains(line, "#define MASTER_FILE") {
			parts := strings.Fields(line)
			if len(parts) >= 3 {
				path := strings.Trim(parts[2], "\"")
				return path
			}
		}
	}
	return "/master.c"
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
		if obj != nil && !obj.IsDestructed {
			targets = append(targets, obj)
		}
	}
	d.mu.RUnlock()

	for _, obj := range targets {
		if obj.IsDestructed {
			continue
		}
		if conn := d.GetConnectionFromObject(obj); conn != nil {
			gid := getGID()
			d.playerContexts.Store(gid, conn)
			d.CallFunction(obj, "heart_beat", nil)
			d.playerContexts.Delete(gid)
		} else {
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
		if conn := d.GetConnectionFromObject(call.Caller); conn != nil {
			gid := getGID()
			d.playerContexts.Store(gid, conn)
			d.CallFunction(call.Caller, call.FuncName, call.Args)
			d.playerContexts.Delete(gid)
		} else {
			d.CallFunction(call.Caller, call.FuncName, call.Args)
		}
	}
}

func (d *Driver) SetHeartBeat(obj *object.LPCObject, enable bool) {
	if obj == nil || obj.IsDestructed {
		return
	}
	d.mu.Lock()
	defer d.mu.Unlock()
	if enable {
		d.Heartbeats[obj] = true
	} else {
		delete(d.Heartbeats, obj)
	}
}

// ProcessAnsi 將自定義的 {r} 標籤轉換為 ANSI 色碼 (用於終端機)
func (d *Driver) ProcessAnsi(text string) string {
	colorMap := map[string]string{
		"r":  "\x1b[31m",
		"g":  "\x1b[32m",
		"y":  "\x1b[33m",
		"b":  "\x1b[34m",
		"m":  "\x1b[35m",
		"c":  "\x1b[36m",
		"w":  "\x1b[37m",
		"gr": "\x1b[90m",
		"n":  "\x1b[0m",
	}

	res := text
	for tag, code := range colorMap {
		res = strings.ReplaceAll(res, "{"+tag+"}", code)
	}
	return res
}

func (d *Driver) CallFunction(obj *object.LPCObject, funcName string, args []object.Object) object.Object {
	if obj == nil || obj.IsDestructed {
	        return &object.Integer{Value: 0}
	}

	// 🚀 更新活動時間
	obj.LastActivity = time.Now().Unix()

	frame := callFrame{File: obj.Filename, Function: funcName, Object: obj}

	d.pushFrame(frame)
	defer d.popFrame()

	if obj.Vars != nil {
		obj.Vars.Set("this_object", &object.Builtin{
			Fn: func(args ...object.Object) object.Object { return obj },
		})
	}
	fnObj, ok := obj.Vars.Get(funcName)
	if !ok {
		// 🚀 關鍵：如果當前物件找不到函式，且有設定 SimulEfun 物件，則去那裡找
		if d.SimulEfunObj != nil && obj != d.SimulEfunObj {
			return d.CallFunction(d.SimulEfunObj, funcName, args)
		}
		return nil
	}
	if builtin, ok := fnObj.(*object.Builtin); ok {
		return builtin.Fn(args...)
	}
	fn, ok := fnObj.(*object.Function)
	if !ok {
		return object.NewError("%s is not a function", funcName)
	}

	extendedEnv := object.NewEnclosedEnvironment(obj.Vars)
	extendedEnv.Set("__origin_file", &object.String{Value: fn.OriginFile})

	for i, param := range fn.Parameters {
		if i < len(args) {
			extendedEnv.Set(param.Value, args[i])
		} else {
			extendedEnv.Set(param.Value, &object.Nil{})
		}
	}
	evaluated := evaluator.Eval(fn.Body, extendedEnv)
	if errObj, ok := evaluated.(*object.Error); ok {
		runtimeErr := &RuntimeError{
			Message:  errObj.Message,
			File:     obj.Filename,
			Function: funcName,
			Stack:    d.buildCallStack(),
		}
		if d.MasterObject != nil && obj != d.MasterObject {
			d.CallFunction(d.MasterObject, "runtime_error", []object.Object{
				&object.String{Value: runtimeErr.Error()},
				&object.String{Value: obj.Filename},
			})
		} else {
			fmt.Println(runtimeErr.Error())
		}
		return nil
	}
	if returnValue, ok := evaluated.(*object.ReturnValue); ok {
		return returnValue.Value
	}
	return evaluated
}

func (d *Driver) MoveObject(item *object.LPCObject, dest *object.LPCObject) {
	if item == nil {
		return
	}
	// 如果物件已銷毀，只允許移往 nil (即移出目前房間)
	if item.IsDestructed && dest != nil {
		return
	}

	if item.Location != nil {
		oldInv := item.Location.Inventory
		newInv := make([]*object.LPCObject, 0, len(oldInv))
		for _, obj := range oldInv {
			if obj != item {
				newInv = append(newInv, obj)
			}
		}
		item.Location.Inventory = newInv
	}

	item.Location = dest
	if dest != nil && !dest.IsDestructed {
		dest.Inventory = append(dest.Inventory, item)
	}

	// 已銷毀物件不觸發 init
	if item.IsDestructed {
		return
	}

	// 🚀 改良版 init 觸發機制 (接近 MudOS 標準)

	// 1. 如果移動的是生物，清除其 Actions (指令集) 並準備重建
	if item.IsLiving {
		item.Actions = make(map[string]*object.Action)
	}

	// A. 如果 item 是生物，它進入了一個新環境
	if item.IsLiving {
		pConn := d.getPlayerConnection(item)
		if pConn == nil {
			pConn = &PlayerConnection{Object: item, IsActive: true}
		}

		restore := d.setPlayerContext(pConn)
		// item->init() 在 dest 與 dest 內的所有物件
		if dest != nil {
			d.CallFunction(dest, "init", nil)
			// 注意：這裡要預先複製一份 inventory，避免 init 過程中 inventory 變動導致 iterator 崩潰
			inv := make([]*object.LPCObject, len(dest.Inventory))
			copy(inv, dest.Inventory)
			for _, obj := range inv {
				if obj != item && obj != nil && !obj.IsDestructed {
					d.CallFunction(obj, "init", nil)
				}
			}
		}
		// item 也要 init 自己身上的東西 (例如包包裡的物品要註冊指令給玩家)
		invSelf := make([]*object.LPCObject, len(item.Inventory))
		copy(invSelf, item.Inventory)
		for _, obj := range invSelf {
			if obj != nil && !obj.IsDestructed {
				d.CallFunction(obj, "init", nil)
			}
		}
		restore()
	}

	// B. 如果 dest 是生物 (例如物品進了玩家背包)
	if dest != nil && dest.IsLiving {
		pConn := d.getPlayerConnection(dest)
		if pConn == nil {
			pConn = &PlayerConnection{Object: dest, IsActive: true}
		}

		restore := d.setPlayerContext(pConn)
		d.CallFunction(item, "init", nil)
		restore()
	}

	// C. 如果 item 進入一個環境 dest，且環境內有其他生物 O (且 item 不是 O)
	if dest != nil {
		inv := make([]*object.LPCObject, len(dest.Inventory))
		copy(inv, dest.Inventory)
		for _, o := range inv {
			if o != nil && o != item && o.IsLiving && !o.IsDestructed {
				pConn := d.getPlayerConnection(o)
				if pConn == nil {
					pConn = &PlayerConnection{Object: o, IsActive: true}
				}

				restore := d.setPlayerContext(pConn)
				d.CallFunction(item, "init", nil)
				// 如果 item 也是生物，則 O 也要在 item 身上 init (互看)
				if item.IsLiving {
					d.CallFunction(o, "init", nil)
				}
				restore()
			}
		}
	}
}

func (d *Driver) DestructObject(obj *object.LPCObject) {
	if obj == nil || obj.IsDestructed {
		return
	}
	d.SetHeartBeat(obj, false)

	// 🚩 關鍵：先移出房間再標記銷毀，否則 MoveObject 會攔截導致移不出去
	if obj.Location != nil {
		d.MoveObject(obj, nil)
	}

	obj.IsDestructed = true

	var targetConn *PlayerConnection
	if conn, ok := d.interactiveObjects.Load(obj.Filename); ok {
		targetConn = conn.(*PlayerConnection)
	}
	if targetConn == nil {
		d.interactiveObjects.Range(func(key, value interface{}) bool {
			if pconn, ok := value.(*PlayerConnection); ok && pconn.Object == obj {
				targetConn = pconn
				return false
			}
			return true
		})
	}
	if targetConn != nil {
		targetConn.IsActive = false
		if targetConn.Conn != nil {
			targetConn.Conn.Close()
		}
		d.UnregisterInteractive(targetConn.Object)
	}
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
	if obj == nil {
		return nil
	}
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

func (d *Driver) AcceptConnection(pConn *PlayerConnection, lang string) *object.LPCObject {
	if d.MasterObject == nil {
		return nil
	}
	gid := getGID()
	d.playerContexts.Store(gid, pConn)
	defer d.playerContexts.Delete(gid)
	
	args := []object.Object{&object.String{Value: lang}}
	result := d.CallFunction(d.MasterObject, "connect", args)
	if loginObj, ok := result.(*object.LPCObject); ok {
		return loginObj
	}
	return nil
}

func (d *Driver) formatParserErrors(filename string, errors []string) error {
	var sb strings.Builder
	sb.WriteString(fmt.Sprintf("❌ 語法錯誤 in %s\n\n", filename))
	for i, err := range errors {
		sb.WriteString(fmt.Sprintf("   %2d. %s\n", i+1, err))
	}
	sb.WriteString("\n💡 提示：常見原因：\n")
	sb.WriteString("   • mapping 寫法錯誤 → 應使用 ([ key: value ])\n")
	sb.WriteString("   • closure 寫法錯誤 → (: this_object, \"func\" :)\n")
	sb.WriteString("   • 缺少分號、括號不匹配、型別宣告錯誤\n")
	return fmt.Errorf("%s", sb.String())
}

func (d *Driver) TransferConnection(target *object.LPCObject, src *object.LPCObject) bool {
	if target == nil || src == nil {
		return false
	}
	d.mu.Lock()
	defer d.mu.Unlock()
	var connToMove *PlayerConnection
	if conn, ok := d.interactiveObjects.Load(src.Filename); ok {
		connToMove = conn.(*PlayerConnection)
	} else {
		d.interactiveObjects.Range(func(key, value interface{}) bool {
			if pconn, ok := value.(*PlayerConnection); ok && pconn.Object == src {
				connToMove = pconn
				return false
			}
			return true
		})
	}
	if connToMove == nil {
		return false
	}
	d.interactiveObjects.Delete(src.Filename)
	src.IsInteractive = false
	connToMove.Object = target
	d.interactiveObjects.Store(target.Filename, connToMove)
	target.IsInteractive = true
	gid := getGID()
	d.playerContexts.Store(gid, connToMove)
	return true
}

// TellObject 向指定物件發送訊息 (封裝通訊邏輯)
func (d *Driver) TellObject(target *object.LPCObject, msg string) {
	if target == nil || target.IsDestructed {
		return
	}

	// 1. 若為連線中的玩家，直接透過 Socket 發送
	conn := d.GetConnectionFromObject(target)
	if conn != nil {
		safeMsg := strings.ReplaceAll(msg, "\r\n", "\n")
		safeMsg = strings.ReplaceAll(safeMsg, "\n", "\r\n")
		conn.Send(safeMsg)
	}

	// 2. 不論是否為玩家，都觸發 catch_tell 函式 (供 NPC 或腳本攔截訊息)
	initiator := d.GetCurrentPlayer()
	if initiator != nil {
		d.RunCommand(initiator, target, "catch_tell", []object.Object{&object.String{Value: msg}})
	} else {
		d.CallFunction(target, "catch_tell", []object.Object{&object.String{Value: msg}})
	}
}

// TellRoom 向指定房間內的所有物件廣播訊息 (支援排除清單)
func (d *Driver) TellRoom(room *object.LPCObject, msg string, exclude []*object.LPCObject) {
	if room == nil || room.IsDestructed {
		return
	}

	for _, item := range room.Inventory {
		if item == nil || item.IsDestructed {
			continue
		}

		shouldExclude := false
		for _, ex := range exclude {
			if item == ex {
				shouldExclude = true
				break
			}
		}

		if !shouldExclude {
			d.TellObject(item, msg)
		}
	}
}

func (d *Driver) runCleanUpLoop() {
	ticker := time.NewTicker(d.Config.CleanUpInterval)
	defer ticker.Stop()
	for {
		select {
		case <-ticker.C:
			d.processCleanUp()
		case <-d.shutdownCh:
			return
		}
	}
}

func (d *Driver) processCleanUp() {
	d.mu.Lock()
	objs := make([]*object.LPCObject, 0, len(d.ObjectTable))
	for _, obj := range d.ObjectTable {
		if obj != nil && !obj.IsDestructed {
			objs = append(objs, obj)
		}
	}
	d.mu.Unlock()

	now := time.Now().Unix()
	for _, obj := range objs {
		// 如果是 Master Object 或正在線上的玩家，不清理
		if obj == d.MasterObject || obj.IsInteractive {
			continue
		}

		// 呼叫 LPC 層級的 clean_up(inherited_count)
		// 這裡傳入 0 代表目前不追蹤繼承計數 (或是可以簡單實作)
		d.CallFunction(obj, "clean_up", []object.Object{&object.Integer{Value: 0}})
		
		// 檢查是否最後活動時間過久 (預設 30 分鐘沒活動)
		// 這只是個保險，真正的清理邏輯應該在 LPC 的 clean_up 中決定是否 destruct
		if now - obj.LastActivity > 1800 {
			// 如果物件沒人(Inventory為空) 且是 Clone，則考慮主動回收
			// 這部分通常交給 LPC 的 clean_up 實作會更精確
		}
	}
}
