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
		// 初始化 Mapping
		mapping m = ([ "hp": 100, "name": "Goblin" ]);
		
		// 讀取與修改 Mapping
		m["hp"] -= 20;
		m["level"] = 5; // 新增 Key

		// 注意：如果你的 Token 定義是用 int array，這裡先用 mixed 或 array 測試
		mixed arr = [10, 20, 30]; 
		arr[1] += 5;
	`

	l := lexer.New(input)
	p := parser.New(l)
	program := p.ParseProgram()
	
	if len(p.Errors()) != 0 {
		fmt.Println("解析錯誤:")
		for _, msg := range p.Errors() {
			fmt.Println("\t", msg)
		}
		return
	}

	env := object.NewEnvironment()
	
	// 執行並捕捉最外層可能發生的錯誤
	result := evaluator.Eval(program, env)
	if result != nil && result.TokenType() == object.ErrorType {
		fmt.Println("❌ 執行期錯誤:", result.Inspect())
		return // 如果有錯誤就提早結束，避免後面的 nil 指標
	}

	fmt.Println("✅ 執行成功！")

	// 安全地驗證 Mapping
	if mObj, ok := env.Get("m"); ok && mObj != nil {
		fmt.Println("Mapping 的最終狀態:", mObj.Inspect()) 
	} else {
		fmt.Println("⚠️ 找不到變數 m")
	}

	// 安全地驗證 Array
	if arrObj, ok := env.Get("arr"); ok && arrObj != nil {
		fmt.Println("Array 的最終狀態:", arrObj.Inspect()) 
	} else {
		fmt.Println("⚠️ 找不到變數 arr")
	}
}
