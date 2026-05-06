package main

import (
	"fmt"

	"mudscript/evaluator"
	"mudscript/lexer"
	"mudscript/object"
	"mudscript/parser"
)

func main() {
	input := `
		// 測試 1: 預設值與正常運算
		int base_damage;     
		int weapon_atk = 15;
		int final_dmg = base_damage + weapon_atk;

		// 測試 2: 定義並呼叫函式
		int get_bonus() {
			return 5;
		}
		int total = final_dmg + get_bonus();

		// 測試 3: 型別錯誤示範 (取消註解可測試)
		// int level = "新手"; 
	`

	l := lexer.New(input)
	p := parser.New(l)
	program := p.ParseProgram()

	if len(p.Errors()) != 0 {
		fmt.Println("❌ Parser 發生語法錯誤:")
		for _, msg := range p.Errors() {
			fmt.Println("  ", msg)
		}
		return
	}

	// 建立環境與執行
	env := object.NewEnvironment()
	evaluated := evaluator.Eval(program, env)

	if evaluated != nil && evaluated.TokenType() == object.ErrorType {
		fmt.Printf("🔥 執行期發生錯誤: %s\n", evaluated.Inspect())
	} else {
		fmt.Println("✅ 腳本執行成功！目前環境變數狀態：")
		
		if obj, ok := env.Get("final_dmg"); ok {
			fmt.Printf("  final_dmg = %s\n", obj.Inspect())
		}
		if obj, ok := env.Get("total"); ok {
			fmt.Printf("  total = %s\n", obj.Inspect())
		}
		if obj, ok := env.Get("base_damage"); ok {
			fmt.Printf("  base_damage = %s\n", obj.Inspect())
		}
	}
}
