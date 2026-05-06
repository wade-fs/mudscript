package main

import (
	"fmt"
	"time"

	"mudscript/driver"
	"mudscript/evaluator"
	"mudscript/lexer"
	"mudscript/object"
	"mudscript/parser"
)

func main() {
	// 模擬一個完整的 LPC 腳本內容
	lpcScript := `
		int hp = 100;
		
		void create() {
			write("怪物被創造出來了！目前 HP: ");
			// (備註：為了簡化，目前的 write 只接受一個字串，我們暫不實作數字轉字串的 + 運算)
			write("100\n");

			// 安排 2 秒後發動突襲
			call_out("sneak_attack", 2, 50);
		}

		void sneak_attack(int damage) {
			write("怪物發動了突襲！造成了傷害！\n");
			hp = hp + 10;
			write("怪物吸血恢復了體力...\n");
		}
	`

	l := lexer.New(lpcScript)
	p := parser.New(l)
	program := p.ParseProgram()
	
	// 初始化 Driver (設定 heartbeat 為 1 秒)
	d := driver.New(driver.DriverConfig{HeartBeatTick: 1 * time.Second})
	
	// 為了測試，我們手動執行 LoadObject 的流程
	env := object.NewEnvironment()
	obj := &object.LPCObject{Filename: "/obj/monster.c", Vars: env}
	
	d.SetupEfuns(obj)             // 注入 write, call_out 等
	evaluator.Eval(program, env)  // 解析變數與函式
	
	// 啟動 Driver 的心跳與排程迴圈 (背景執行)
	d.Start()
	
	fmt.Println(">>> Driver 已啟動，開始呼叫 create() <<<")
	d.CallFunction(obj, "create", nil)

	fmt.Println(">>> 程式進入等待，觀察 call_out 是否會觸發... <<<")
	// 讓主程式等待 3 秒鐘，以便觀察 call_out 的延遲執行
	time.Sleep(3 * time.Second)

	fmt.Println(">>> 測試結束，關閉 Driver <<<")
	d.Stop()
}
