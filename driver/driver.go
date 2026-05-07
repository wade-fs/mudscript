// driver/driver.go
package driver

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"sync"
	"time"

	"mudscript/ast"
	"mudscript/evaluator"
	"mudscript/lexer"
	"mudscript/object"
	"mudscript/parser"
)

// DriverConfig 運行時期的配置
type DriverConfig struct {
	MudLibPath    string        // MUD 腳本的根目錄 (例如 "./mudlib")
	MasterFile    string        // master.c 的路徑 (預設 "/master.c" 或 "/adm/obj/master.c")
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
	PlayerConns  []*PlayerConnection              // 玩家連線清單
	Heartbeats   map[*object.LPCObject]bool       // 註冊 heart_beat() 的物件集合 (用 map 方便 O(1) 增刪)
	CallOuts     []*ScheduledCall                 // call_out 排程佇列
	Config       DriverConfig
	shutdownCh   chan struct{}                    // 用於安全關閉 Driver 的 channel

	MasterObject *object.LPCObject                // master.c
	RootUID      string // 儲存最高權限 UID (通常是 "Root")
	BackboneUID  string // 儲存背景執行 UID (通常是 "Backbone")
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
	lpcFile := d.Config.MudLibPath + filename
	content, err := os.ReadFile(lpcFile)
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
	lpcObj := &object.LPCObject{
		Filename:  filename,
		Vars:      env,
		Functions: make(map[string]*object.Function), 
		Inherits:  make([]*object.LPCObject, 0),
	}

	// ==========================================
	// 5. 處理 Inherit 語法 (在編譯期載入父物件)
	// ==========================================
	for _, stmt := range program.Statements {
		if inheritStmt, ok := stmt.(*ast.InheritStatement); ok {
			
			// 處理路徑 (LPC 腳本常省略 .c)
			parentFile := inheritStmt.Path
			if !strings.HasSuffix(parentFile, ".c") {
				parentFile += ".c"
			}

			// 遞迴載入父物件 (Blueprint)
			parentObj, err := d.LoadObject(parentFile)
			if err != nil {
				return nil, fmt.Errorf("無法繼承 %s: %v", parentFile, err)
			}

			lpcObj.Inherits = append(lpcObj.Inherits, parentObj)
			baseName := strings.TrimSuffix(filepath.Base(parentFile), ".c")

			// 將父物件的變數與函式深拷貝到當前物件的環境中
			for k, v := range parentObj.Vars.GetAll() {
				env.Set(k, deepCopyLPCValue(v))
				
				// ==========================================
				// 備份父物件的函式，以支援 Scope 呼叫！
				// ==========================================
				if _, isFunc := v.(*object.Function); isFunc {
					// 避免備份到父物件自己已經加過 :: 前綴的函式，只備份最乾淨的原始名稱
					if !strings.Contains(k, "::") {
						// 支援 ::func()
						env.Set("::"+k, v) 
						// 支援 monster::func()
						env.Set(baseName+"::"+k, v) 
					}
				}
			}
		}
	}

	// 6. 注入 Efuns
	d.SetupEfuns(lpcObj)

	// 7. 執行 Evaluator (此時腳本內的程式已經可以使用 write 等函式了)
	evaluator.Eval(program, env)

	// 8. 寫入 ObjectTable 快取
	d.mu.Lock()
	d.ObjectTable[filename] = lpcObj
	d.mu.Unlock()

	// 9. 呼叫 create()
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

	// 替分身注入它專屬的 Efuns
	d.SetupEfuns(clone)

	for k, v := range blueprint.Vars.GetAll() {
		clone.Vars.Set(k, deepCopyLPCValue(v))
	}

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
func (d *Driver) Start() error {
	masterFile := d.Config.MasterFile
	if masterFile == "" {
		masterFile = "/master.c" // 預設路徑
	}

	fmt.Println("🚀 Driver 啟動中... 準備載入 Master Object:", masterFile)
	
	// 1. 載入 master.c
	master, err := d.LoadObject(masterFile)
	if err != nil {
		return fmt.Errorf("致命錯誤: 無法載入 master.c: %v", err)
	}
	d.MasterObject = master

	// 2. 呼叫 get_root_uid()
	if res := d.CallFunction(master, "get_root_uid", nil); res != nil {
		if s, ok := res.(*object.String); ok {
			d.RootUID = s.Value
		}
	}

	// 3. 呼叫 get_bb_uid()
	if res := d.CallFunction(master, "get_bb_uid", nil); res != nil {
		if s, ok := res.(*object.String); ok {
			d.BackboneUID = s.Value
		}
	}

	fmt.Printf("✅ Master 載入成功 (RootUID: %s, BackboneUID: %s)\n", d.RootUID, d.BackboneUID)

	// 啟動心跳引擎
	go d.runGameLoop()
	return nil
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
	extendedEnv := object.NewEnclosedEnvironment(obj.Vars)

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

	// ==========================================
	// 攔截執行期錯誤 (Runtime Error)
	// ==========================================
	if errObj, ok := evaluated.(*object.Error); ok {
		// 為了避免 runtime_error 裡面自己也寫錯導致無限遞迴，我們檢查 obj != d.MasterObject
		if d.MasterObject != nil && obj != d.MasterObject {
			// 呼叫 master.c 的 runtime_error(string error_msg, string filename)
			d.CallFunction(d.MasterObject, "runtime_error", []object.Object{
				&object.String{Value: errObj.Message},
				&object.String{Value: obj.Filename},
			})
		} else {
			// 如果是 master.c 自己爆了，只能印在 Server Console 上
			fmt.Printf("🔥 MasterObject 崩潰: %s\n", errObj.Message)
		}
		return nil // 發生錯誤時回傳 nil (LPC 的 0)
	}

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

// driver/driver.go

// MoveObject 處理物件在容器間的轉移
func (d *Driver) MoveObject(item *object.LPCObject, dest *object.LPCObject) {
	if item == nil || dest == nil || item.IsDestructed || dest.IsDestructed {
		return
	}

	// 1. 如果物品原本有地方，先從原地點移除
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

	// 2. 放入新地點
	item.Location = dest
	dest.Inventory = append(dest.Inventory, item)

	// MUD 慣例：移動後通常會觸發 init() 讓房間內的物件互相認識
	d.CallFunction(item, "init", nil)
}

// DestructObject 徹底摧毀物件
func (d *Driver) DestructObject(obj *object.LPCObject) {
	if obj == nil || obj.IsDestructed {
		return
	}
	obj.IsDestructed = true

	// 1. 從心跳名單移除
	d.SetHeartBeat(obj, false)

	// 2. 把它身上的東西掉到它所在的環境
	for _, item := range obj.Inventory {
		d.MoveObject(item, obj.Location)
	}

	// 3. 把它從目前的環境中移除
	if obj.Location != nil {
		d.MoveObject(obj, nil) // 這裡傳 nil 代表移出空間
	}

	// 4. (可選) 從 Driver 的 ObjectTable 快取中移除 (如果是 clone 的話)
	d.mu.Lock()
	delete(d.ObjectTable, obj.Filename)
	d.mu.Unlock()
}

// deepCopyLPCValue 負責深拷貝陣列與 Mapping，避免父子或本尊分身共用記憶體
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
		// 整數、浮點、字串、函式 (Function) 等皆為傳值或不可變參考，直接回傳即可
		return obj
	}
}

// AcceptConnection 模擬新玩家連線的掛勾
func (d *Driver) AcceptConnection() *object.LPCObject {
	if d.MasterObject == nil {
		fmt.Println("⚠️ 拒絕連線：系統尚未準備好 (無 Master Object)")
		return nil
	}

	// 呼叫 master.c 的 connect()
	result := d.CallFunction(d.MasterObject, "connect", nil)
	
	// 預期 master.c 會 clone 一個 login 物件並回傳給我們
	if loginObj, ok := result.(*object.LPCObject); ok {
		fmt.Printf("🔗 新連線建立！分配的登入物件: %s\n", loginObj.Filename)
		return loginObj
	}

	fmt.Println("❌ 連線失敗：master->connect() 沒有回傳合法的 LPCObject")
	return nil
}
