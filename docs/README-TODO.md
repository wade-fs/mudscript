# 目前完成的部分 ✅

已就緒的基礎架構：

- token/ — LPC 型別 token 全部定義完成
- lexer/ — 基礎詞法分析（繼承自 Monkey）
- ast/ — TypedVarDecl、FunctionDef、TypedParam、InheritStatement 已新增
- parser/ — parseTypedDeclarationStatement、parseFunctionDefinition、parseInheritStatement 已完成
- evaluator/ — evalTypedVarDecl、evalFunctionDef 已實作
- object/ — LPCObject（含 Location/Inventory/IsDestructed）、Mapping 已定義
- driver/ — LoadObject、CloneObject、CallFunction、MoveObject、DestructObject、heartbeat loop、CallOut 全部骨架完成
- driver/efun.go — write、say、this_object、environment、move_object、destruct、clone_object、time、random、call_out、sizeof、explode、implode

# 接下來的工作清單

## 🔴 P0 — 語言核心缺口（直接影響任何 LPC 腳本能不能跑）

### T-01：Lexer — 補上缺失的 LPC 符號識別
目前缺少：
- ->  (ARROW，call_other 語法)
- ::  (SCOPE，繼承呼叫)
- ([  ])  (LBRACKET_MAP / RBRACKET_MAP，mapping 字面值)
- %  (PERCENT，取餘數)
- +=  -=  *=  /=  (複合賦值)
- ++  --  (自增自減)
- &&  ||  (邏輯運算子，目前只有 !)
- /* ... */ (多行註解)
- #include  #define  (前處理器)
- 'c'  (字元字面值，CHAR token)

### T-02：AST + Parser — 補上複合賦值與自增減
新增節點：
- AssignStatement  (x = expr，目前只有 let/typed 宣告)
- CompoundAssign   (x += 1、x -= 1、x *= 2 等)
- PostfixExpression (x++、x--)
- ForStatement      (for(init; cond; post) { })
- WhileStatement    (while(cond) { })
- DoWhileStatement  (do { } while(cond);)
- SwitchStatement   (switch(x) { case 1: ... })
- BreakStatement / ContinueStatement

目前的 if/return 都有了，但 for/while/switch 是 LPC 腳本最常用的！

### T-03：Evaluator — 處理 T-02 所有新節點
- evalAssignment (變數重新賦值，目前無法做 hp = hp - 10)
- evalForStatement
- evalWhileStatement
- evalDoWhileStatement
- evalSwitchStatement
- evalBreak / evalContinue (需要加 BreakValue/ContinueValue 物件)
- evalCompoundAssign
- evalPostfix (++/--)

### T-04：Parser — MappingLiteral 語法 ([ key: val, ... ])

目前 token 有 LBRACKET_MAP / RBRACKET_MAP 但 lexer 和 parser

都還沒實作識別 ([ 與 ]) 的邏輯

### T-05：Evaluator — evalMappingLiteral 與 Mapping 操作

目前 object.Mapping 存在但 key 只支援 string。

需要改為支援任意 Hashable key（int/string/object）。

## 🟡 P1 — Driver 完整性（讓腳本能正確載入與繼承）

### T-06：Inherit 機制實作

目前 InheritStatement 只有 AST 節點，driver.LoadObject 
完全沒有處理 inherit。

需要：
1. evaluator 遇到 InheritStatement 時，通知 driver 去載入父物件
2. LPCObject.Inherits 欄位要填入真正的父物件
3. CallFunction 查不到函式時，往 Inherits 鏈向上找（方法繼承）
4. 父物件的全域變數需要合入子物件的環境（變數繼承）

### T-07：:: (SCOPE) 呼叫支援

LPC 中 ::func() 表示呼叫父物件的同名函式
(例如 ::create() 在 override create 時很常用)

### T-08：-> (call_other) 支援

ob->func(args) 等同於 call_other(ob, "func", args)
這是 MUD 腳本中物件互動的核心語法
需要：AST 節點、Parser、Evaluator 全部補上

### T-09：Driver — master.c 載入流程

目前 MasterObject 欄位存在但從未被使用。
需要：
1. Driver.Start() 先 LoadObject("master.c")
2. 呼叫 master.c 的 get_root_uid()、get_bb_uid()
3. 連線時呼叫 master.c 的 connect(interactive)
4. 錯誤時呼叫 master.c 的 runtime_error()

### T-10：前處理器 (#include / #define)

新增 preprocessor/ 套件，在 Lexer 之前執行：
- #include "path/to/file.h" → 把檔案內容展開
- #define MACRO value → 字串替換
- #ifdef / #ifndef / #endif → 條件編譯
	(這對於 mudlib 中大量 #include "include/config.h" 是必要的)

### T-11: 進階處理 LPC

- sscanf 語法與「傳址參考 (Pass by Reference)」
	- 情境：MUD 最常用來解析玩家指令的神兵利器，例如 sscanf(str, "give %d %s to %s", amount, item, target);。
	- 挑戰：這需要 Evaluator 支援將變數「傳址」給函式，並直接修改該變數在 Environment 裡的值。
- 進階陣列/映射表操作 (Advanced EFuns)
	- 情境：在 MUD 中走訪資料，常會用到 keys(mapping)、values(mapping)，或者是高階陣列操作如 filter_array()、map_array()。
	- 挑戰：擴充 efun.go，實作這些將陣列與 Mapping 發揮到極致的內建函式。
- 錯誤攔截 catch 與 throw
	- 情境：當腳本預期某些操作可能會失敗（例如除以零、轉型失敗），但不希望觸發 master->runtime_error() 導致全域崩潰時，可以用 mixed err = catch( do_something() ); 來將錯誤捕捉下來處理。
	- 挑戰：在 Evaluator 實作 catch 節點，讓它能夠吸收 object.Error 並轉化為字串傳回給 LPC 變數。
- 函數指標 / 閉包 (Closures / Function Pointers)
	- 情境：LPC 支援高階函數傳遞，例如 function f = (: this_object(), "take_damage" :); 或是 evaluate(f, 10);。
	- 挑戰：在 Object System 中擴充 FunctionPointer 型別，並在 Parser 支援 (: ... :) 的特殊語法。

## 🟡 P2 — 網路層（讓玩家能連進來）

### T-12：Telnet Server 實作

新增 net/ 套件：
- TelnetServer.Listen(port)
- TelnetServer.Accept() → 建立 PlayerConnection
- 處理 Telnet 協議的基本 IAC 命令（WILL ECHO, WILL SGA 等）
- 輸入緩衝與換行處理

### T-13：PlayerConnection 物件

目前是空殼，需要：
- net.Conn 持有連線
- 輸入命令佇列
- receive_message(string) → 寫入到玩家的 TCP 緩衝
- tell_object(player, msg) efun 實作

### T-14：Interactive Object 概念

玩家在 LPC 中是一個 interactive object（有連線的 LPCObject）

需要區分 interactive 與 non-interactive 物件：
- this_player() efun 需要能回傳當前的 interactive object
- enable_commands() / add_action() 機制（讓玩家能輸入指令）

## 🟢 P3 — 補充 Efun（讓 mudlib 腳本跑起來）

### T-15：字串 Efun

- lower_case(str)
- upper_case(str)
- strlen(str)
- substr(str, start, len)
- strsrch(str, pattern)
- capitalize(str)
- trim(str)
- foreach

### T-16：陣列 Efun

- filter(arr, func)
- map(arr, func)           ← 注意不要跟 mapping 型別衝突
- sort_array(arr, func)
- member_array(val, arr)   ← 查找元素位置
- unique_array(arr)

### T-17：Mapping Efun

- keys(mapping)
- values(mapping)
- m_delete(mapping, key)
- m_add(mapping, key, val)

### T-18: 補完 Inherit

### T-19：物件查詢 Efun

- all_inventory(ob)
- deep_inventory(ob)
- first_inventory(ob)
- present(str, ob)         ← 在某容器中找同 id 的物件
- find_object(filename)    ← 在 ObjectTable 中找
- object_name(ob)          ← 回傳 ob.Filename
- living(ob)               ← 是否有 heart_beat 啟用
- interactive(ob)          ← 是否是玩家連線

### T-20：set_heart_beat efun 注入

目前 driver.SetHeartBeat 存在，
但沒有把 set_heart_beat(int) 注入到每個物件的 efun 中

## 🔵 P4 — 品質與測試

### T-21：補全現有功能的 Unit Test

目前只有 driver/efun_test.go，需要補：
- lexer_test.go：測試 ->、::、([])、%、++、+=
- parser_test.go：測試 for/while/switch/assignment
- evaluator_test.go：測試 for 迴圈、mapping 操作、繼承

### T-22：錯誤處理強化

- 目前 Eval 回傳 nil 的地方沒有統一處理
- runtime error 應通知 master.c 的 runtime_error() 函式
- 加入 call stack / stack trace 機制方便偵錯

### T-23：整合測試用 Mudlib 骨架

建立 mudlib/ 目錄：
```
mudlib/
├── master.c          ← Driver 啟動時第一個載入
├── include/
│   └── config.h      ← 常數定義
├── std/
│   ├── room.c        ← 基礎房間
│   └── living.c      ← 生物基礎
└── obj/
    └── player.c      ← 玩家物件
```

## 建議的執行順序
- 本週：T-01 → T-02 → T-03  (先讓 for/while/賦值能跑)
- 下週：T-04 → T-05 → T-06  (Mapping + Inherit，核心中的核心)
- 之後：T-08 → T-10 → T-11  (call_other + 前處理器 + 網路)
- 最後：T-14~T-18 efun 補齊，搭配 T-21 真正的 mudlib 跑起來
