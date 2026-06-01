// driver/driver.go
package driver

import (
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
	"sync"
	"time"

	"mudscript/evaluator"
	"mudscript/object"
)

// DriverConfig 運行時期的配置
type DriverConfig struct {
	MudLibPath      string
	MasterFile      string
	HeartBeatTick   time.Duration
	CleanUpInterval time.Duration // 🚀 新增：垃圾回收間隔
	EmbeddedFS      fs.FS
	EmbeddedPath    string // 🚀 新增：嵌入式路徑前綴
	GlobalInclude   string // 🚀 新增：全域自動引入標頭檔
	SimulEfunFile   string // 🚀 新增：指定 SimulEfun 檔案路徑
}

// Driver MUD 伺服器核心
type Driver struct {
	mu           sync.RWMutex
	ObjectTable  map[string]*object.LPCObject
	UUIDTable    map[string]*object.LPCObject // 🚀 新增：UUID 快速索引表
	Heartbeats   map[*object.LPCObject]bool
	CallOuts     []*ScheduledCall
	Config       DriverConfig
	shutdownCh   chan struct{}
	MasterObject *object.LPCObject
	SimulEfunObj *object.LPCObject // 🚀 新增：模擬 Efun 物件
	StartTime    time.Time
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

	// 🚀 初始化全域內建函式表 (用於變數遮蔽時的 fallback)
	evaluator.RegisterBuiltin("time", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return &object.Integer{Value: time.Now().Unix()}
		},
	})
	evaluator.RegisterBuiltin("ctime", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return &object.String{Value: ""}
			}
			if t, ok := args[0].(*object.Integer); ok {
				return &object.String{Value: time.Unix(t.Value, 0).Format(time.ANSIC)}
			}
			return &object.String{Value: ""}
		},
	})

	return &Driver{
		ObjectTable: make(map[string]*object.LPCObject),
		UUIDTable:   make(map[string]*object.LPCObject),
		Heartbeats:  make(map[*object.LPCObject]bool),
		CallOuts:    make([]*ScheduledCall, 0),
		Config:      config,
		shutdownCh:  make(chan struct{}),
		StartTime:   time.Now(),
	}
}

func (d *Driver) Start() error {
	masterFile := d.Config.MasterFile
	if masterFile == "" {
		masterFile = d.DiscoverMasterFile()
	}

	fmt.Println("🚀 Driver 啟動中... 準備載入 Master Object:", masterFile)
	// 1. 只載入不執行 create
	master, _, err := d.loadObjectInternal(masterFile)
	if err != nil {
		return fmt.Errorf("致命錯誤: 無法載入 master.c: %v", err)
	}

	d.mu.Lock()
	d.MasterObject = master
	d.mu.Unlock()

	simulFile := d.Config.SimulEfunFile

	// 2. 如果 Config 沒指定，則從 Master 物件詢問 SimulEfun 路徑
	if simulFile == "" {
		if res := d.CallFunction(master, "get_simul_efun", nil); res != nil {
			if s, ok := res.(*object.String); ok && s.Value != "" {
				simulFile = s.Value
			}
		}
	}

	if simulFile != "" {
		simul, _, err := d.loadObjectInternal(simulFile)
		if err == nil {
			d.mu.Lock()
			d.SimulEfunObj = simul
			d.mu.Unlock()
			fmt.Printf("✅ SimulEfun 載入成功: %s\n", simulFile)

			// 注入 SimulEfuns 到已經載入的 master
			d.RegisterSimulEfuns(master)

			// 執行 SimulEfun 的 create
			d.CallFunction(simul, "create", nil)
		} else {
			fmt.Printf("⚠️ 無法載入 SimulEfun (%s): %v\n", simulFile, err)
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

func (d *Driver) Stop() {
	close(d.shutdownCh)
}
