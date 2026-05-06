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
		// ==========================================
		// 1. 測試一般 Mapping (字串與整數 Key)
		// ==========================================
		mapping m = ([ "hp": 100, "name": "Goblin", 1: "one" ]);
		
		m["hp"] -= 20;      // 測試複合賦值 (預期 hp 變 80)
		m["level"] = 5;     // 測試動態新增 Key
		m[1] = "uno";       // 測試整數 Key 修改

		// ==========================================
		// 2. 測試 Array 索引修改
		// ==========================================
		mixed arr = [10, 20, 30]; 
		arr[1] += 5;        // 預期中間變成 25
		arr[0] = 99;        // 預期開頭變成 99

		// ==========================================
		// 3. 測試進階 Hashable: 物件 (函式) 作為 Key
		// ==========================================
		void dummy() { }
		
		// 將 dummy 這個函式參照當作 key 存入 mapping
		mapping obj_map = ([ dummy: 500 ]);
		
		// 透過相同的函式參照去讀取並修改它
		obj_map[dummy] += 100; // 預期變成 600
	`

	l := lexer.New(input)
	p := parser.New(l)
	program := p.ParseProgram()

	// 1. 檢查解析錯誤
	if len(p.Errors()) != 0 {
		fmt.Println("❌ 解析發生錯誤:")
		for _, msg := range p.Errors() {
			fmt.Println("\t", msg)
		}
		return
	}

	env := object.NewEnvironment()

	// 2. 執行腳本
	result := evaluator.Eval(program, env)
	if result != nil && result.TokenType() == object.ErrorType {
		fmt.Println("❌ 執行期發生錯誤:", result.Inspect())
		return
	}

	fmt.Println("✅ 腳本執行成功！以下是變數的最終記憶體狀態：\n")

	// 3. 驗證 Mapping m
	if mObj, ok := env.Get("m"); ok && mObj != nil {
		fmt.Println("📦 [Mapping m] 最終狀態:")
		fmt.Println("  ", mObj.Inspect())
	}

	// 4. 驗證 Array arr
	if arrObj, ok := env.Get("arr"); ok && arrObj != nil {
		fmt.Println("\n📦 [Array arr] 最終狀態:")
		fmt.Println("  ", arrObj.Inspect())
	}

	// 5. 驗證 Mapping obj_map (確認函式作為 Key 成功運作)
	if objMap, ok := env.Get("obj_map"); ok && objMap != nil {
		fmt.Println("\n📦 [Mapping obj_map] (物件作為 Key) 最終狀態:")
		fmt.Println("  ", objMap.Inspect())
	}
}
