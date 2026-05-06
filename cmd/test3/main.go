package main

import (
	"fmt"
	"mudscript/driver"
	"mudscript/lexer"
	"mudscript/object"
	"mudscript/parser"
	"mudscript/evaluator"
)

func main() {
	// 模擬一個 LPC 腳本內容
	lpcScript := `
		int hp = 100;
		
		void create() {
			hp = 150; // 初始化時提升血量
		}

		int take_damage(int amount) {
			hp = hp - amount;
			return hp;
		}
	`

	// 1. 直接解析腳本並準備環境 (模擬 load_object 流程)
	l := lexer.New(lpcScript)
	p := parser.New(l)
	program := p.ParseProgram()
	
	env := object.NewEnvironment()
	evaluator.Eval(program, env)

	// 2. 封裝成 LPCObject
	obj := &object.LPCObject{
		Filename: "/obj/monster.c",
		Vars:     env,
	}

	// 3. 啟動 Driver
	d := driver.New(driver.DriverConfig{})

	// 測試 A：手動呼叫 create()
	if hpObj, ok := env.Get("hp"); ok {
		fmt.Println("呼叫 create() 之前，hp =", hpObj.(*object.Integer).Value) // 預期 100
	}
	
	d.CallFunction(obj, "create", nil)
	
	if hpObj, ok := env.Get("hp"); ok {
		fmt.Println("呼叫 create() 之後，hp =", hpObj.(*object.Integer).Value) // 預期 150
	}

	// 測試 B：呼叫帶有參數的函式
	args := []object.Object{&object.Integer{Value: 30}}
	result := d.CallFunction(obj, "take_damage", args)
	
	fmt.Println("呼叫 take_damage(30) 的回傳值 =", result.(*object.Integer).Value) // 預期 120
	
	if hpObj, ok := env.Get("hp"); ok {
		fmt.Println("物件最終的 hp =", hpObj.(*object.Integer).Value)          // 預期 120
	}
}
