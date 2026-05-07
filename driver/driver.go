// driver/driver.go
package driver

import (
	"bufio"
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
	Reader   *bufio.Reader
	Object   *object.LPCObject
	IsActive bool
}

func (p *PlayerConnection) Send(msg string) {
	if p.Conn != nil {
		p.Conn.Write([]byte(msg))
	}
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

	// [核心魔法] 使用 Goroutine ID 來追蹤當前正在執行的玩家
	playerContexts sync.Map 
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
		d.CallFunction(obj, "heart_beat", nil)
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
	fnObj, ok := obj.Vars.Get(funcName)
	if !ok { return nil }

	fn, ok := fnObj.(*object.Function)
	if !ok { return object.NewError("%s is not a function", funcName) }

	extendedEnv := object.NewEnclosedEnvironment(obj.Vars)
	for i, param := range fn.Parameters {
		if i < len(args) {
			extendedEnv.Set(param.Value, args[i])
		} else {
			extendedEnv.Set(param.Value, &object.Integer{Value: 0})
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

func (d *Driver) AcceptConnection() *object.LPCObject {
	if d.MasterObject == nil { return nil }
	result := d.CallFunction(d.MasterObject, "connect", nil)
	if loginObj, ok := result.(*object.LPCObject); ok {
		return loginObj
	}
	return nil
}
