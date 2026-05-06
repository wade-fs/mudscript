package main

import (
	"fmt"
	"mudscript/lexer"
	"mudscript/parser"
)

func main() {
	// 這裡放完整的腳本，Lexer 會一次拿到所有的換行符號
	input := `
int calculate_damage(int base_atk, float rate) {
    int final_damage = base_atk * rate;
    return final_damage;
}

string get_greeting(string name) {
    return "你好，" + name;
}

void setup() {
    int default_level = 1;
}
`

	l := lexer.New(input)
	p := parser.New(l)
	program := p.ParseProgram()

	// 檢查 Parser 是否有抓到錯誤
	if len(p.Errors()) != 0 {
		fmt.Println("❌ Parser 發生語法錯誤:")
		for _, msg := range p.Errors() {
			fmt.Println("\t", msg)
		}
		return
	}

	// 如果沒有錯誤，印出 AST 還原後的程式碼
	fmt.Println("✅ AST 解析成功！還原結果如下：")
	fmt.Println(program.String())
}
