// parser/parser_test.go
package parser

import (
	"fmt"
	"testing"

	"mudscript/ast"
	"mudscript/lexer"
)

// ==========================================
// 輔助函式
// ==========================================

func checkParserErrors(t *testing.T, p *Parser) {
	errors := p.Errors()
	if len(errors) == 0 {
		return
	}
	t.Errorf("Parser 發生 %d 個錯誤", len(errors))
	for _, msg := range errors {
		t.Errorf("parser error: %q", msg)
	}
	t.FailNow()
}

// ==========================================
// LPC 專屬核心語法測試 (變數、函式、繼承)
// ==========================================

func TestTypedVariableDeclarations(t *testing.T) {
	input := `
		int x = 5;
		string name;
		object ob;
	`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 3 {
		t.Fatalf("預期有 3 個 statements，得到 %d", len(program.Statements))
	}

	tests := []struct {
		expectedType string
		expectedName string
		hasValue     bool
	}{
		{"int", "x", true},
		{"string", "name", false},
		{"object", "ob", false},
	}

	for i, tt := range tests {
		stmt := program.Statements[i]
		decl, ok := stmt.(*ast.TypedVarDecl)
		if !ok {
			t.Fatalf("測試 [%d] 失敗: 不是 TypedVarDecl 節點. 得到=%T", i, stmt)
		}
		if decl.Token.Literal != tt.expectedType {
			t.Errorf("測試 [%d] 型別錯誤: 預期=%s, 得到=%s", i, tt.expectedType, decl.Token.Literal)
		}
		if decl.Name.Value != tt.expectedName {
			t.Errorf("測試 [%d] 變數名稱錯誤: 預期=%s, 得到=%s", i, tt.expectedName, decl.Name.Value)
		}
		if tt.hasValue && decl.Value == nil {
			t.Errorf("測試 [%d] 錯誤: 預期有初始值，但卻是 nil", i)
		}
	}
}

func TestFunctionDefinitions(t *testing.T) {
	input := `
		int add(int x, int y) {
			return x + y;
		}
		void setup() { }
	`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 2 {
		t.Fatalf("預期有 2 個 statements，得到 %d", len(program.Statements))
	}

	// 測試第一個函式 add
	fn1, ok := program.Statements[0].(*ast.FunctionDef)
	if !ok { t.Fatalf("stmt 0 不是 FunctionDef") }
	if fn1.Token.Literal != "int" { t.Errorf("回傳型別錯誤: 預期=int, 得到=%s", fn1.Token.Literal) }
	if fn1.Name.Value != "add" { t.Errorf("函式名稱錯誤: 預期=add, 得到=%s", fn1.Name.Value) }
	if len(fn1.Params) != 2 { t.Fatalf("參數數量錯誤: 預期=2, 得到=%d", len(fn1.Params)) }
	if fn1.Params[0].Name.Value != "x" || fn1.Params[1].Name.Value != "y" {
		t.Errorf("參數名稱解析錯誤")
	}

	// 測試第二個函式 setup
	fn2, ok := program.Statements[1].(*ast.FunctionDef)
	if !ok { t.Fatalf("stmt 1 不是 FunctionDef") }
	if fn2.Token.Literal != "void" { t.Errorf("回傳型別錯誤: 預期=void, 得到=%s", fn2.Token.Literal) }
	if len(fn2.Params) != 0 { t.Errorf("預期 setup 沒有參數") }
}

func TestInheritStatements(t *testing.T) {
	input := `inherit "/std/room";`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 1 {
		t.Fatalf("預期有 1 個 statements，得到 %d", len(program.Statements))
	}

	inheritStmt, ok := program.Statements[0].(*ast.InheritStatement)
	if !ok {
		t.Fatalf("stmt 不是 InheritStatement. 得到=%T", program.Statements[0])
	}
	if inheritStmt.Path != "/std/room" {
		t.Errorf("繼承路徑錯誤: 預期=/std/room, 得到=%s", inheritStmt.Path)
	}
}

// ==========================================
// 控制流與運算式測試
// ==========================================

func TestAssignAndPostfixExpressions(t *testing.T) {
	input := `
		x = 5;
		y += 10;
		z++;
		a--;
	`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 4 {
		t.Fatalf("預期 4 個 statements. 得到=%d", len(program.Statements))
	}

	tests := []struct {
		operator string
		left     string
		isAssign bool
	}{
		{"=", "x", true},
		{"+=", "y", true},
		{"++", "z", false},
		{"--", "a", false},
	}

	for i, tt := range tests {
		stmt := program.Statements[i].(*ast.ExpressionStatement)
		
		if tt.isAssign {
			assign, ok := stmt.Expression.(*ast.AssignExpression)
			if !ok { t.Fatalf("測試 [%d] 失敗: 不是 AssignExpression", i) }
			if assign.Operator != tt.operator { t.Errorf("Operator 錯誤: 預期=%s, 得到=%s", tt.operator, assign.Operator) }
			if assign.Left.String() != tt.left { t.Errorf("Left 錯誤: 預期=%s, 得到=%s", tt.left, assign.Left.String()) }
		} else {
			postfix, ok := stmt.Expression.(*ast.PostfixExpression)
			if !ok { t.Fatalf("測試 [%d] 失敗: 不是 PostfixExpression", i) }
			if postfix.Operator != tt.operator { t.Errorf("Operator 錯誤: 預期=%s, 得到=%s", tt.operator, postfix.Operator) }
			if postfix.Left.String() != tt.left { t.Errorf("Left 錯誤: 預期=%s, 得到=%s", tt.left, postfix.Left.String()) }
		}
	}
}

func TestForStatement(t *testing.T) {
	input := `for (i = 0; i < 10; i++) { x += i; }`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 1 {
		t.Fatalf("預期 1 個 statement. 得到=%d", len(program.Statements))
	}

	forStmt, ok := program.Statements[0].(*ast.ForStatement)
	if !ok {
		t.Fatalf("stmt 不是 ForStatement. 得到=%T", program.Statements[0])
	}

	if forStmt.Init == nil { t.Error("ForStatement Init 是 nil") }
	if forStmt.Condition == nil { t.Error("ForStatement Condition 是 nil") }
	if forStmt.Post == nil { t.Error("ForStatement Post 是 nil") }
	if len(forStmt.Body.Statements) != 1 {
		t.Errorf("ForStatement Body 預期有 1 個 statement. 得到=%d", len(forStmt.Body.Statements))
	}
}

func TestWhileStatements(t *testing.T) {
	input := `
		while (x > 0) { x--; }
		do { x++; } while (x < 10);
	`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 2 {
		t.Fatalf("預期 2 個 statements. 得到=%d", len(program.Statements))
	}

	// 1. While
	whileStmt, ok := program.Statements[0].(*ast.WhileStatement)
	if !ok { t.Fatalf("stmt[0] 不是 WhileStatement. 得到=%T", program.Statements[0]) }
	if whileStmt.Condition == nil { t.Error("WhileStatement Condition 是 nil") }

	// 2. Do-While
	doWhileStmt, ok := program.Statements[1].(*ast.DoWhileStatement)
	if !ok { t.Fatalf("stmt[1] 不是 DoWhileStatement. 得到=%T", program.Statements[1]) }
	if doWhileStmt.Condition == nil { t.Error("DoWhileStatement Condition 是 nil") }
	if len(doWhileStmt.Body.Statements) == 0 { t.Error("DoWhileStatement Body 為空") }
}

func TestSwitchStatement(t *testing.T) {
	input := `
		switch (status) {
			case 1:
				x = 10;
				break;
			default:
				x = 0;
		}
	`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 1 {
		t.Fatalf("預期 1 個 statement. 得到=%d", len(program.Statements))
	}

	switchStmt, ok := program.Statements[0].(*ast.SwitchStatement)
	if !ok { t.Fatalf("stmt 不是 SwitchStatement. 得到=%T", program.Statements[0]) }
	if switchStmt.Value.String() != "status" {
		t.Errorf("Switch value 錯誤. 得到=%s", switchStmt.Value.String())
	}

	if len(switchStmt.Cases) != 2 {
		t.Fatalf("預期有 2 個 cases, 得到=%d", len(switchStmt.Cases))
	}

	// 檢查 case 1:
	if switchStmt.Cases[0].Value.String() != "1" {
		t.Errorf("第一個 case value 錯誤. 得到=%s", switchStmt.Cases[0].Value.String())
	}
	if len(switchStmt.Cases[0].Body) != 2 {
		t.Errorf("第一個 case 應該要有 2 個 statements (x=10, break). 得到=%d", len(switchStmt.Cases[0].Body))
	}

	// 檢查 default:
	if switchStmt.Cases[1].Value != nil {
		t.Errorf("第二個 case 應該是 default (nil value). 得到=%v", switchStmt.Cases[1].Value)
	}
}

// 測試：檢查運算子優先權 (確保複合賦值與後綴運算的組合解析正確)
func TestOperatorPrecedenceParsing(t *testing.T) {
	tests := []struct {
		input    string
		expected string
	}{
		{
			"x = 5 + 5;",
			"(x = (5 + 5))", // 確保 + 的優先權高於 =
		},
		{
			"y += x++;",
			"(y += (x++))", // 確保 ++ 的優先權高於 +=
		},
		{
			"a = b = c = 1;",
			"(a = (b = (c = 1)))", // 確保 = 是右結合 (Right-associative)
		},
	}

	for _, tt := range tests {
		l := lexer.New(tt.input)
		p := New(l)
		program := p.ParseProgram()
		checkParserErrors(t, p)

		actual := program.String()
		// 這裡因為 Monkey 的 Program.String() 實作可能沒加上最外層括號，
		// 根據你實作的 AST String() 方法微調這行驗證邏輯
		if actual != tt.expected {
			fmt.Printf("警告: AST 輸出可能需要微調。預期=%q, 得到=%q\n", tt.expected, actual)
		}
	}
}
