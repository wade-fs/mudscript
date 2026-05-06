// parser/parser_test.go
package parser

import (
	"testing"
	"mudscript/ast"
	"mudscript/lexer"
)

// 輔助函式：檢查 Parser 是否有錯誤
func checkParserErrors(t *testing.T, p *Parser) {
	errors := p.Errors()
	if len(errors) == 0 {
		return
	}
	t.Errorf("parser has %d errors", len(errors))
	for _, msg := range errors {
		t.Errorf("parser error: %q", msg)
	}
	t.FailNow()
}

// 測試：複合賦值與自增減 (Assign & Postfix)
func TestAssignAndPostfixExpressions(t *testing.T) {
	input := `
		x = 5;
		y += 10;
		z++;
	`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 3 {
		t.Fatalf("program.Statements does not contain 3 statements. got=%d", len(program.Statements))
	}

	// 1. 測試 x = 5
	stmt1 := program.Statements[0].(*ast.ExpressionStatement)
	assign1, ok := stmt1.Expression.(*ast.AssignExpression)
	if !ok { t.Fatalf("stmt1 is not AssignExpression. got=%T", stmt1.Expression) }
	if assign1.Operator != "=" { t.Errorf("operator is not '='. got=%s", assign1.Operator) }
	if assign1.Left.String() != "x" { t.Errorf("left is not 'x'. got=%s", assign1.Left.String()) }

	// 2. 測試 y += 10
	stmt2 := program.Statements[1].(*ast.ExpressionStatement)
	assign2, ok := stmt2.Expression.(*ast.AssignExpression)
	if !ok { t.Fatalf("stmt2 is not AssignExpression. got=%T", stmt2.Expression) }
	if assign2.Operator != "+=" { t.Errorf("operator is not '+='. got=%s", assign2.Operator) }
	if assign2.Left.String() != "y" { t.Errorf("left is not 'y'. got=%s", assign2.Left.String()) }

	// 3. 測試 z++
	stmt3 := program.Statements[2].(*ast.ExpressionStatement)
	postfix, ok := stmt3.Expression.(*ast.PostfixExpression)
	if !ok { t.Fatalf("stmt3 is not PostfixExpression. got=%T", stmt3.Expression) }
	if postfix.Operator != "++" { t.Errorf("operator is not '++'. got=%s", postfix.Operator) }
	if postfix.Left.String() != "z" { t.Errorf("left is not 'z'. got=%s", postfix.Left.String()) }
}

// 測試：For 迴圈
func TestForStatement(t *testing.T) {
	input := `for (i = 0; i < 10; i++) { x += i; }`
	l := lexer.New(input)
	p := New(l)
	program := p.ParseProgram()
	checkParserErrors(t, p)

	if len(program.Statements) != 1 {
		t.Fatalf("program.Statements does not contain 1 statement. got=%d", len(program.Statements))
	}

	forStmt, ok := program.Statements[0].(*ast.ForStatement)
	if !ok {
		t.Fatalf("stmt is not ForStatement. got=%T", program.Statements[0])
	}

	// 檢查 Init (i = 0)
	if forStmt.Init == nil { t.Error("ForStatement Init is nil") }
	// 檢查 Condition (i < 10)
	if forStmt.Condition == nil { t.Error("ForStatement Condition is nil") }
	// 檢查 Post (i++)
	if forStmt.Post == nil { t.Error("ForStatement Post is nil") }
	// 檢查 Body
	if len(forStmt.Body.Statements) != 1 {
		t.Errorf("ForStatement Body should have 1 statement. got=%d", len(forStmt.Body.Statements))
	}
}

// 測試：While 與 Do-While
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
		t.Fatalf("program.Statements does not contain 2 statements. got=%d", len(program.Statements))
	}

	// 1. While
	whileStmt, ok := program.Statements[0].(*ast.WhileStatement)
	if !ok { t.Fatalf("stmt[0] is not WhileStatement. got=%T", program.Statements[0]) }
	if whileStmt.Condition == nil { t.Error("WhileStatement Condition is nil") }

	// 2. Do-While
	doWhileStmt, ok := program.Statements[1].(*ast.DoWhileStatement)
	if !ok { t.Fatalf("stmt[1] is not DoWhileStatement. got=%T", program.Statements[1]) }
	if doWhileStmt.Condition == nil { t.Error("DoWhileStatement Condition is nil") }
	if len(doWhileStmt.Body.Statements) == 0 { t.Error("DoWhileStatement Body is empty") }
}

// 測試：Switch
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
		t.Fatalf("program.Statements does not contain 1 statement. got=%d", len(program.Statements))
	}

	switchStmt, ok := program.Statements[0].(*ast.SwitchStatement)
	if !ok { t.Fatalf("stmt is not SwitchStatement. got=%T", program.Statements[0]) }
	if switchStmt.Value.String() != "status" {
		t.Errorf("Switch value not 'status'. got=%s", switchStmt.Value.String())
	}

	if len(switchStmt.Cases) != 2 {
		t.Fatalf("Expected 2 cases, got=%d", len(switchStmt.Cases))
	}

	// 檢查 case 1:
	if switchStmt.Cases[0].Value.String() != "1" {
		t.Errorf("First case value not '1'. got=%s", switchStmt.Cases[0].Value.String())
	}
	if len(switchStmt.Cases[0].Body) != 2 {
		t.Errorf("First case body should have 2 statements (x=10, break). got=%d", len(switchStmt.Cases[0].Body))
	}

	// 檢查 default:
	if switchStmt.Cases[1].Value != nil {
		t.Errorf("Second case should be default (nil value). got=%v", switchStmt.Cases[1].Value)
	}
}
