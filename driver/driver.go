// driver/driver.go
package driver

import (
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
	"sync"
	"time"

	"mudscript/object"
)

// DriverConfig 運行時期的配置
type DriverConfig struct {
	MudLibPath      string
	MasterFile      string
	HeartBeatTick   time.Duration
	CleanUpInterval time.Duration // 🚀 新增：垃圾回收間隔
	EmbeddedFS      fs.FS
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

	// 2. 從 Master 物件詢問 SimulEfun 路徑並載入
	if res := d.CallFunction(master, "get_simul_efun", nil); res != nil {
		if s, ok := res.(*object.String); ok && s.Value != "" {
			simul, _, err := d.loadObjectInternal(s.Value)
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

func (d *Driver) Stop() {
	close(d.shutdownCh)
}
