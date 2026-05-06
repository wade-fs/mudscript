// driver/driver.go
package driver

import (
	"fmt"
	"os"
	"sync"
	"time"

	"mudscript/evaluator"
	"mudscript/lexer"
	"mudscript/object"
	"mudscript/parser"
)

// DriverConfig 運行時期的配置
type DriverConfig struct {
	MudLibPath    string        // MUD 腳本的根目錄 (例如 "./mudlib")
	HeartBeatTick time.Duration // heart_beat 的觸發間隔 (LPC 預設通常是 2 秒)
}

// PlayerConnection 玩家連線 (Phase 4 實作，先放個空殼)
type PlayerConnection struct{}

// ScheduledCall 用於 call_out 排程
type ScheduledCall struct {
	Caller   *object.LPCObject // 呼叫 call_out 的物件
	FuncName string            // 要延遲執行的函式名稱
	Args     []object.Object   // 傳入的參數
	FireTime time.Time         // 預定執行的時間
}

// Driver MUD 伺服器核心
type Driver struct {
	mu           sync.RWMutex                     // 保護全域資料結構的並發安全
	ObjectTable  map[string]*object.LPCObject     // 已載入的藍圖物件 (Blueprint)
	MasterObject *object.LPCObject                // master.c
	PlayerConns  []*PlayerConnection              // 玩家連線清單
	Heartbeats   map[*object.LPCObject]bool       // 註冊 heart_beat() 的物件集合 (用 map 方便 O(1) 增刪)
	CallOuts     []*ScheduledCall                 // call_out 排程佇列
	Config       DriverConfig

	shutdownCh   chan struct{}                    // 用於安全關閉 Driver 的 channel
}

// New 建立新的 Driver 實例
func New(config DriverConfig) *Driver {
	if config.HeartBeatTick == 0 {
		config.HeartBeatTick = 2 * time.Second // 預設 2 秒一跳
	}

	return &Driver{
		ObjectTable: make(map[string]*object.LPCObject),
		Heartbeats:  make(map[*object.LPCObject]bool),
		CallOuts:    make([]*ScheduledCall, 0),
		Config:      config,
		shutdownCh:  make(chan struct{}),
	}
}

// LoadObject 載入並快取 LPC 物件 (回傳 Blueprint)
func (d *Driver) LoadObject(filename string) (*object.LPCObject, error) {
	// 1. 檢查快取：如果已經載入過，直接回傳
	d.mu.RLock()
	if obj, exists := d.ObjectTable[filename]; exists {
		d.mu.RUnlock()
		return obj, nil
	}
	d.mu.RUnlock()

	// 2. 讀取實體檔案
	filepath := d.Config.MudLibPath + filename
	content, err := os.ReadFile(filepath)
	if err != nil {
		return nil, fmt.Errorf("failed to read file %s: %v", filename, err)
	}

	// 3. 進行解析 (Lexing & Parsing)
	l := lexer.New(string(content))
	p := parser.New(l)
	program := p.ParseProgram()

	if len(p.Errors()) > 0 {
		return nil, fmt.Errorf("parse error in %s: %v", filename, p.Errors())
	}

	// 4. 建立物件的獨立變數空間 (Environment)
	env := object.NewEnvironment()

	// 5. 執行 Evaluator 來初始化這個物件的變數與函式
	// (此時 evaluator 會把 int x = 1; 以及函式定義存入 env 中)
	evaluator.Eval(program, env)

	// 6. 封裝成 LPCObject
	lpcObj := &object.LPCObject{
		Filename:  filename,
		Vars:      env,
		Functions: make(map[string]*object.Function), // 這裡可以從 env 中萃取出函式放入
	}

	// 從 Environment 萃取函式存入 LPCObject (分離變數與函式)
	// (實作細節取決於你的 Environment 如何儲存，通常可以遍歷 env 找出 type 為 FUNCTION 的項目)

	// 7. 寫入 ObjectTable 快取
	d.mu.Lock()
	d.ObjectTable[filename] = lpcObj
	d.mu.Unlock()

	// MudOS 特性：載入後通常會自動呼叫 create() 函式初始化
	d.CallFunction(lpcObj, "create", nil)

	return lpcObj, nil
}

// CloneObject 建立物件副本 (複製 Blueprint 產生新實體)
func (d *Driver) CloneObject(filename string) (*object.LPCObject, error) {
	// 1. 確保藍圖已經載入
	blueprint, err := d.LoadObject(filename)
	if err != nil {
		return nil, err
	}

	// 2. 建立新實體
	// 真正的 LPC 複製，函式指標共用，但變數空間 (Vars) 是全新的！
	// 為了簡化，我們這裡重新建立一個空的 Environment 並讓 Evaluator 重新賦值，
	// 或是實作一個 DeepCopyEnvironment 的輔助函式。
	clone := &object.LPCObject{
		Filename:  filename + "#" + generateCloneID(), // 例如 "/std/room.c#123"
		Vars:      object.NewEnvironment(),            // 全新的變數空間
		Functions: blueprint.Functions,                // 函式直接共用藍圖的
		Inherits:  blueprint.Inherits,
	}

	// TODO: 將藍圖的初始變數值複製到 clone.Vars 中

	// 呼叫新物件的 create()
	d.CallFunction(clone, "create", nil)

	return clone, nil
}

var cloneCounter int
func generateCloneID() string {
	cloneCounter++
	return fmt.Sprintf("%d", cloneCounter)
}

// Start 啟動 Driver 的背景迴圈
func (d *Driver) Start() {
	go d.runGameLoop()
}

// Stop 停止 Driver
func (d *Driver) Stop() {
	close(d.shutdownCh)
}

// runGameLoop 是 MudOS 的心跳引擎
func (d *Driver) runGameLoop() {
	ticker := time.NewTicker(d.Config.HeartBeatTick)
	defer ticker.Stop()

	for {
		select {
		case <-ticker.C:
			d.processHeartBeats()
			d.processCallOuts()
		case <-d.shutdownCh:
			fmt.Println("Driver shutting down...")
			return
		}
	}
}

// processHeartBeats 觸發所有註冊的 heart_beat
func (d *Driver) processHeartBeats() {
	d.mu.RLock()
	// 複製一份名單，避免在執行 heart_beat() 時物件自我摧毀導致 deadlock
	targets := make([]*object.LPCObject, 0, len(d.Heartbeats))
	for obj := range d.Heartbeats {
		targets = append(targets, obj)
	}
	d.mu.RUnlock()

	for _, obj := range targets {
		// 對每個物件呼叫 heart_beat()
		d.CallFunction(obj, "heart_beat", nil)
	}
}

// CallOut 新增延遲呼叫排程
func (d *Driver) CallOut(caller *object.LPCObject, funcName string, delay time.Duration, args ...object.Object) {
	fireTime := time.Now().Add(delay)

	d.mu.Lock()
	defer d.mu.Unlock()

	d.CallOuts = append(d.CallOuts, &ScheduledCall{
		Caller:   caller,
		FuncName: funcName,
		Args:     args,
		FireTime: fireTime,
	})
}

// processCallOuts 檢查並執行時間到了的 call_out
func (d *Driver) processCallOuts() {
	now := time.Now()
	
	d.mu.Lock()
	var pending []*ScheduledCall
	var ready []*ScheduledCall

	// 篩選出時間已到的任務
	for _, call := range d.CallOuts {
		if now.After(call.FireTime) || now.Equal(call.FireTime) {
			ready = append(ready, call)
		} else {
			pending = append(pending, call)
		}
	}
	// 更新佇列，保留還沒到的任務
	d.CallOuts = pending
	d.mu.Unlock()

	// 執行任務 (在 Lock 之外執行，防止腳本死鎖)
	for _, call := range ready {
		d.CallFunction(call.Caller, call.FuncName, call.Args)
	}
}

// SetHeartBeat 供物件開啟或關閉自己的 heart_beat
func (d *Driver) SetHeartBeat(obj *object.LPCObject, enable bool) {
	d.mu.Lock()
	defer d.mu.Unlock()

	if enable {
		d.Heartbeats[obj] = true
	} else {
		delete(d.Heartbeats, obj)
	}
}

// CallFunction 在指定的 LPC 物件環境中尋找並執行函式
func (d *Driver) CallFunction(obj *object.LPCObject, funcName string, args []object.Object) object.Object {
	// 1. 從物件的變數環境中尋找該函式
	// (因為我們在 Phase 1 的 Eval 中，已經把 FunctionDef 存進 Env 了)
	fnObj, ok := obj.Vars.Get(funcName)
	if !ok {
		// 在 LPC 中，呼叫不存在的函式（例如沒有定義 create 或 heart_beat）是合法的，直接忽略即可
		return nil
	}

	// 2. 確定找到的是一個函式物件
	fn, ok := fnObj.(*object.Function)
	if !ok {
		return object.NewError("%s is not a function in %s", funcName, obj.Filename)
	}

	// 3. 建立執行環境 (Closure)
	// 將這個物件本身的 Env 作為外層環境，這樣函式內就能存取該物件的全域變數 (例如 hp, name)
	extendedEnv := object.NewEnclosedEnvironment(fn.Env)

	// 4. 將傳入的引數 (Arguments) 綁定到函式的參數 (Parameters) 上
	for i, param := range fn.Parameters {
		if i < len(args) {
			extendedEnv.Set(param.Value, args[i])
		} else {
			// 如果傳入的參數不夠，LPC 預設給整數 0 或是 null
			extendedEnv.Set(param.Value, &object.Integer{Value: 0})
		}
	}

	// 5. 交給 Evaluator 執行函式主體
	evaluated := evaluator.Eval(fn.Body, extendedEnv)

	// 6. 處理 Return 值 (去除 ReturnWrapper)
	return unwrapReturnValue(evaluated)
}

// 輔助函式：剝除 Evaluator 的 ReturnValue 封裝
func unwrapReturnValue(obj object.Object) object.Object {
	if returnValue, ok := obj.(*object.ReturnValue); ok {
		return returnValue.Value
	}
	return obj
}
