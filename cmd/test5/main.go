package main

import (
	"fmt"
	"mudscript/lexer"
	"mudscript/parser"
	"mudscript/evaluator"
	"mudscript/object"
)

func main() {
	input := `
		int hp = 100;

		void take_damage() {
			hp -= 15;
		}

		void heal() {
			hp++;
		}
	`

	l := lexer.New(input)
	p := parser.New(l)
	program := p.ParseProgram()
	
	// 建立最外層環境 (模擬 LPCObject 的 Vars)
	env := object.NewEnvironment()
	evaluator.Eval(program, env)

	fmt.Println("=== 戰鬥測試開始 ===")
	// 確認初始 HP
	if hpObj, ok := env.Get("hp"); ok {
		fmt.Printf("初始 HP: %d\n", hpObj.(*object.Integer).Value)
	}

	// 取得並執行 take_damage 函式
	fnObj, _ := env.Get("take_damage")
	takeDamageFn := fnObj.(*object.Function)
	
	// 建立函式的執行環境 (模擬 CallFunction 的行為)
	callEnv1 := object.NewEnclosedEnvironment(takeDamageFn.Env)
	evaluator.Eval(takeDamageFn.Body, callEnv1)

	if hpObj, ok := env.Get("hp"); ok {
		fmt.Printf("受到攻擊後 HP: %d\n", hpObj.(*object.Integer).Value) // 預期 85
	}

	// 取得並執行 heal 函式
	fnObj2, _ := env.Get("heal")
	healFn := fnObj2.(*object.Function)
	
	callEnv2 := object.NewEnclosedEnvironment(healFn.Env)
	evaluator.Eval(healFn.Body, callEnv2)

	if hpObj, ok := env.Get("hp"); ok {
		fmt.Printf("使用治癒後 HP: %d\n", hpObj.(*object.Integer).Value) // 預期 86
	}
}
