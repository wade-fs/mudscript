我想從 https://github.com/skatsuta/monkey-interpreter 擴充來建立 mudos 的 mud driver,
例如底下比較與計劃，請分階段一點一點擴充
```
特性| Monkey | LPC (MudOS) | 需要的工作 
----|--------|-------------|------------
型別系統  | 動態、隱式          | int, string, float, object, array, mapping, mixed | 擴充 token/object
變數宣告  | let x = 1           | int x = 1;                                        | 改 parser
函式定義  |  let f = fn(x){...} | int func(int x){...}                              | 改 parser
繼承      | 無                  | inherit "path/to/base";                           | 新增
物件系統  | 無                  | object ob = new("file")                           | 新增
Mapping   | Hash（{})           | mapping m = ([ "key": val ])                      | 擴充語法
前處理器  | 無                  | #include, #define                                 | 新增 preprocessor
efuns     | 少量 built-in       | 大量系統 efun（write(), say(), tell_object()...） | 大量新增
多物件載入| 無                  | driver 管理 object registry                       | 新增 driver 核心
網路連線  | 無                  | TCP socket、玩家連線                              | 新增
```

例如：
Phase 1：LPC 語言核心
從 Monkey 的架構出發，逐步改造成 LPC 語法：
1.1 Token 擴充

// token/token.go 新增
INT_TYPE    // "int"
STRING_TYPE // "string"  
FLOAT_TYPE  // "float"
OBJECT_TYPE // "object"
MAPPING_TYPE// "mapping"
MIXED_TYPE  // "mixed"
VOID_TYPE   // "void"
INHERIT     // "inherit"
NEW         // "new"
CLONE_OBJECT// "clone_object"

1.2 Lexer 擴充

支援 #include "file.c" / #define MACRO val
支援 /* ... */ 多行註解（Monkey 已有 //）
支援 0x 十六進位、'c' 字元字面量

1.3 AST 節點擴充

// 新增節點
type TypedVarDecl struct {
    TypeToken token.Token  // int, string...
    Name      *Identifier    Value
    Expression
}

type FunctionDef struct {
    ReturnType token.Token
    Name       *Identifier
    Params     []*TypedParam
    Body       *BlockStatement
}

type InheritStatement struct {
    Path string
}

type MappingLiteral struct {
    Pairs map[Expression]Expression
}

1.4 Object 系統擴充

// object/object.go 新增
type LPCObject struct {
    Filename  string
    Vars      map[string]Object
    Functions map[string]*FunctionDef
    Inherits  []*LPCObject
}

type Mapping struct {
    Pairs map[Object]Object
}

Phase 2：Driver 核心
這是 MudOS 的靈魂——負責管理所有 LPC 物件的 runtime：

// driver/driver.go
type Driver struct {
    ObjectTable  map[string]*LPCObject  // 已載入的物件
    MasterObject *LPCObject             // master.c
    PlayerConns  []*PlayerConnection    // 玩家連線
    CallOuts     []ScheduledCall        // call_out() 排程
    Heartbeats   []*LPCObject           // 有 heart_beat() 的物件
    Config       DriverConfig           // runtime config
}

關鍵 driver 功能：

load_object(filename) — 載入並快取 LPC 物件
clone_object(filename) — 建立物件副本（clone）
call_out(func, delay, args) — 延遲呼叫
heart_beat 機制（每隔固定時間呼叫物件的 heart_beat()）

Phase 3：EFun（External Functions）
MudOS 的 efun 是 driver 提供給 LPC 的內建函式，相當於 syscall：

// efun/efun.go
var Efuns = map[string]object.GoFunction{
    // I/O
    "write":        efunWrite,
    "say":          efunSay,
    "tell_object":  efunTellObject,
    "tell_room":    efunTellRoom,
    // 物件
    "this_object":  efunThisObject,
    "this_player":  efunThisPlayer,
    "environment":  efunEnvironment,
    "all_inventory":efunAllInventory,
    "move_object":  efunMoveObject,
    // 字串
    "sprintf":      efunSprintf,
    "explode":      efunExplode,
    "implode":      efunImplode,
    "lower_case":   efunLowerCase,
    // 陣列/Mapping
    "keys":         efunKeys,
    "values":       efunValues,
    "member_array": efunMemberArray,
    // 時間/系統
    "time":         efunTime,
    "call_out":     efunCallOut,
}

Phase 4：網路層（Telnet Server）

// net/telnet.go
type TelnetServer struct {
    Driver   *driver.Driver
    Listener net.Listener
    Port     int
}

func (s *TelnetServer) Accept() {
    for {
        conn, _ := s.Listener.Accept()
        player := NewPlayerConnection(conn)
        s.Driver.AddPlayer(player)        // 呼叫 master.c 的 connect()
        s.Driver.CallMaster("connect", player)
    }
}
