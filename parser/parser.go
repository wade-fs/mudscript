package parser

import (
	"fmt"
	"strconv"

	"mudscript/ast"
	"mudscript/lexer"
	"mudscript/token"
)

const (
	_ int = iota
	LOWEST
	ASSIGN      // = += -= *= /=
	EQUALS      // == !=
	LESSGREATER // > < >= <=
	SUM         // + -
	PRODUCT     // * / %
	PREFIX      // -X or !X
	CALL        // myFunction(X)
	INDEX       // array[index]
	SCOPE_PREC  // 作用域解析的優先權極高
	POSTFIX     // X++ X--
)

var precedences = map[token.TokenType]int{
	token.EQ:       EQUALS,
	token.NEQ:      EQUALS,
	token.LT:       LESSGREATER,
	token.GT:       LESSGREATER,
	token.GTE:      LESSGREATER,
	token.LTE:      LESSGREATER,
	token.PLUS:     SUM,
	token.MINUS:    SUM,
	token.SLASH:    PRODUCT,
	token.ASTARISK: PRODUCT,
	token.LPAREN:   CALL,
	token.LBRACKET: INDEX,
	token.ARROW:    CALL,

	token.ASSIGN:          ASSIGN,
	token.PLUS_EQUALS:     ASSIGN,
	token.MINUS_EQUALS:    ASSIGN,
	token.ASTERISK_EQUALS: ASSIGN,
	token.SLASH_EQUALS:    ASSIGN,
	token.INC:             POSTFIX,
	token.DEC:             POSTFIX,
	token.SCOPE:           SCOPE_PREC,
}

type (
	prefixParseFn func() ast.Expression
	infixParseFn  func(ast.Expression) ast.Expression
)

// Parser is a parser of Monkey programming language.
type Parser struct {
	l      lexer.Lexer
	errors []string

	curToken  token.Token
	peekToken token.Token

	prefixParseFns map[token.TokenType]prefixParseFn
	infixParseFns  map[token.TokenType]infixParseFn
}

// New returns a new Parser.
func New(l lexer.Lexer) *Parser {
	p := &Parser{
		l:      l,
		errors: []string{},
	}

	p.prefixParseFns = map[token.TokenType]prefixParseFn{
		token.IDENT:    p.parseIdent,
		token.INT:      p.parseIntegerLiteral,
		token.FLOAT:    p.parseFloatLiteral,
		token.BANG:     p.parsePrefixExpression,
		token.MINUS:    p.parsePrefixExpression,
		token.TRUE:     p.parseBoolean,
		token.FALSE:    p.parseBoolean,
		token.LPAREN:   p.parseGroupedExpression,
		token.IF:       p.parseIfExpression,
		token.FUNCTION: p.parseFunctionLiteral,
		token.STRING:   p.parseStringLiteral,
		token.LBRACKET: p.parseArrayLiteral,
		token.LBRACE:   p.parseHashLiteral,
		token.MACRO:    p.parseMacroLiteral,

		token.LBRACKET_MAP: p.parseMappingLiteral,
		token.SCOPE:        p.parsePrefixScope,
		token.LPAREN_COLON: p.parseClosureLiteral,
	}

	p.infixParseFns = map[token.TokenType]infixParseFn{
		token.PLUS:     p.parseInfixExpression,
		token.MINUS:    p.parseInfixExpression,
		token.ASTARISK: p.parseInfixExpression,
		token.SLASH:    p.parseInfixExpression,
		token.EQ:       p.parseInfixExpression,
		token.NEQ:      p.parseInfixExpression,
		token.LT:       p.parseInfixExpression,
		token.GT:       p.parseInfixExpression,
		token.LTE:      p.parseInfixExpression,
		token.GTE:      p.parseInfixExpression,
		token.LPAREN:   p.parseCallExpression,
		token.LBRACKET: p.parseIndexExpression,
		token.ASSIGN:   p.parseAssignExpression,
		token.PLUS_EQUALS:     p.parseAssignExpression,
		token.MINUS_EQUALS:    p.parseAssignExpression,
		token.ASTERISK_EQUALS: p.parseAssignExpression,
		token.SLASH_EQUALS:    p.parseAssignExpression,
		token.INC:      p.parsePostfixExpression,
		token.DEC:      p.parsePostfixExpression,

		token.SCOPE:    p.parseInfixScope,
		token.ARROW:    p.parseCallOtherExpression,
	}

	// Read two tokens, so curToken and peekToken are both set
	p.nextToken()
	p.nextToken()

	return p
}

func (p *Parser) nextToken() {
	p.curToken = p.peekToken
	p.peekToken = p.l.NextToken()
}

// Errors returns error messages.
func (p *Parser) Errors() []string {
	return p.errors
}

func (p *Parser) peekError(typ token.TokenType) {
	msg := fmt.Sprintf("expected next token to be %s, got %s instead", typ, p.peekToken.TokenType)
	p.errors = append(p.errors, msg)
}

func (p *Parser) curTokenIs(typ token.TokenType) bool {
	return p.curToken.TokenType == typ
}

func (p *Parser) peekTokenIs(typ token.TokenType) bool {
	return p.peekToken.TokenType == typ
}

func (p *Parser) expectPeek(typ token.TokenType) bool {
	if p.peekTokenIs(typ) {
		p.nextToken()
		return true
	}

	p.peekError(typ)
	return false
}

// ParseProgram parses a program and returns a new Program AST node.
func (p *Parser) ParseProgram() *ast.Program {
	program := &ast.Program{
		Statements: []ast.Statement{},
	}

	for !p.curTokenIs(token.EOF) {
		stmt := p.parseStatement()
		if stmt != nil {
			program.Statements = append(program.Statements, stmt)
		}
		p.nextToken()
	}

	return program
}

func (p *Parser) parseLetStatement() *ast.LetStatement {
	stmt := &ast.LetStatement{Token: p.curToken}

	if !p.expectPeek(token.IDENT) {
		return nil
	}

	stmt.Name = &ast.Ident{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}

	if !p.expectPeek(token.ASSIGN) {
		return nil
	}

	p.nextToken()

	stmt.Value = p.parseExpression(LOWEST)

	for p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
	}

	return stmt
}

func (p *Parser) parseReturnStatement() *ast.ReturnStatement {
	stmt := &ast.ReturnStatement{
		Token: p.curToken,
	}

	p.nextToken()
	if p.curTokenIs(token.SEMICOLON) {
		return stmt
	}

	stmt.ReturnValue = p.parseExpression(LOWEST)

	for p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
	}

	return stmt
}

func (p *Parser) parseExpressionStatement() *ast.ExpressionStatement {
	stmt := &ast.ExpressionStatement{
		Token:      p.curToken,
		Expression: p.parseExpression(LOWEST),
	}

	if p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
	}

	return stmt
}

func (p *Parser) parseExpression(precedence int) ast.Expression {
	prefix := p.prefixParseFns[p.curToken.TokenType]
	if prefix == nil {
		msg := fmt.Sprintf("no prefix parse function for %s found", p.curToken.TokenType)
		p.errors = append(p.errors, msg)
		return nil
	}

	leftExp := prefix()

	for !p.curTokenIs(token.SEMICOLON) && precedence < p.peekPrecedence() {
		infix := p.infixParseFns[p.peekToken.TokenType]
		if infix == nil {
			return leftExp
		}

		p.nextToken()

		leftExp = infix(leftExp)
	}

	return leftExp
}

func (p *Parser) parseIdent() ast.Expression {
	return &ast.Ident{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}
}

func (p *Parser) parseIntegerLiteral() ast.Expression {
	lit := &ast.IntegerLiteral{Token: p.curToken}

	val, err := strconv.ParseInt(p.curToken.Literal, 0, 64)
	if err != nil {
		msg := fmt.Sprintf("could not parse %q as integer", p.curToken.Literal)
		p.errors = append(p.errors, msg)
		return nil
	}

	lit.Value = val
	return lit
}

func (p *Parser) parseFloatLiteral() ast.Expression {
	val, err := strconv.ParseFloat(p.curToken.Literal, 64)
	if err != nil {
		msg := fmt.Sprintf("could not parse %q as float", p.curToken.Literal)
		p.errors = append(p.errors, msg)
		return nil
	}

	return &ast.FloatLiteral{
		Token: p.curToken,
		Value: val,
	}
}

func (p *Parser) parsePrefixExpression() ast.Expression {
	expr := &ast.PrefixExpression{
		Token:    p.curToken,
		Operator: p.curToken.Literal,
	}

	p.nextToken()

	expr.Right = p.parseExpression(PREFIX)
	return expr
}

func (p *Parser) peekPrecedence() int {
	if p, ok := precedences[p.peekToken.TokenType]; ok {
		return p
	}
	return LOWEST
}

func (p *Parser) curPrecedence() int {
	if p, ok := precedences[p.curToken.TokenType]; ok {
		return p
	}
	return LOWEST
}

func (p *Parser) parseInfixExpression(left ast.Expression) ast.Expression {
	expr := &ast.InfixExpression{
		Token:    p.curToken,
		Operator: p.curToken.Literal,
		Left:     left,
	}

	prec := p.curPrecedence()

	p.nextToken()

	expr.Right = p.parseExpression(prec)
	return expr
}

func (p *Parser) parseBoolean() ast.Expression {
	return &ast.Boolean{
		Token: p.curToken,
		Value: p.curTokenIs(token.TRUE),
	}
}

func (p *Parser) parseGroupedExpression() ast.Expression {
	p.nextToken()

	expr := p.parseExpression(LOWEST)

	if !p.expectPeek(token.RPAREN) {
		return nil
	}

	return expr
}

func (p *Parser) parseIfExpression() ast.Expression {
	expression := &ast.IfExpression{Token: p.curToken}

	if !p.expectPeek(token.LPAREN) {
		return nil
	}

	p.nextToken()
	expression.Condition = p.parseExpression(LOWEST)

	if !p.expectPeek(token.RPAREN) {
		return nil
	}

	if !p.expectPeek(token.LBRACE) {
		return nil
	}

	expression.Consequence = p.parseBlockStatement()

	// === [修改開始] 處理 else 與 else if ===
	if p.peekTokenIs(token.ELSE) {
		p.nextToken() // 移動到 'else'

		if p.peekTokenIs(token.IF) {
			// 1. 發現是 else if！
			p.nextToken() // 移動到 'if'

			// 2. 遞迴解析這個新的 if 結構
			elseIfNode := p.parseIfExpression()

			// 3. 語法糖魔法：建構一個隱形的 BlockStatement 把 else if 包起來
			expression.Alternative = &ast.BlockStatement{
				Token: p.curToken, // 借用當前的 token
				Statements: []ast.Statement{
					&ast.ExpressionStatement{
						Token:      p.curToken,
						Expression: elseIfNode,
					},
				},
			}
		} else {
			// 4. 一般的 else { ... }
			if !p.expectPeek(token.LBRACE) {
				return nil
			}
			expression.Alternative = p.parseBlockStatement()
		}
	}
	// === [修改結束] ===

	return expression
}

func (p *Parser) parseBlockStatement() *ast.BlockStatement {
	block := &ast.BlockStatement{
		Token:      p.curToken,
		Statements: []ast.Statement{},
	}

	p.nextToken()

	for !p.curTokenIs(token.RBRACE) && !p.curTokenIs(token.EOF) {
		stmt := p.parseStatement()
		if stmt != nil {
			block.Statements = append(block.Statements, stmt)
		}

		p.nextToken()
	}

	return block
}

func (p *Parser) parseFunctionLiteral() ast.Expression {
	lit := &ast.FunctionLiteral{Token: p.curToken}

	if !p.expectPeek(token.LPAREN) {
		return nil
	}

	lit.Parameters = p.parseFunctionParameters()

	if !p.expectPeek(token.LBRACE) {
		return nil
	}

	lit.Body = p.parseBlockStatement()

	return lit
}

func (p *Parser) parseFunctionParameters() []*ast.Ident {
	idents := []*ast.Ident{}

	if p.peekTokenIs(token.RPAREN) {
		p.nextToken()
		return idents
	}

	p.nextToken()

	ident := &ast.Ident{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}
	idents = append(idents, ident)

	for p.peekTokenIs(token.COMMA) {
		p.nextToken()
		p.nextToken()
		ident := &ast.Ident{
			Token: p.curToken,
			Value: p.curToken.Literal,
		}
		idents = append(idents, ident)
	}

	if !p.expectPeek(token.RPAREN) {
		return nil
	}

	return idents
}

func (p *Parser) parseExpressionList(end token.TokenType) []ast.Expression {
	list := make([]ast.Expression, 0)

	if p.peekTokenIs(end) {
		p.nextToken()
		return list
	}

	p.nextToken()
	list = append(list, p.parseExpression(LOWEST))

	for p.peekTokenIs(token.COMMA) {
		p.nextToken()
		p.nextToken()
		list = append(list, p.parseExpression(LOWEST))
	}

	if !p.expectPeek(end) {
		return nil
	}

	return list
}

func (p *Parser) parseCallExpression(function ast.Expression) ast.Expression {
	return &ast.CallExpression{
		Token:     p.curToken,
		Function:  function,
		Arguments: p.parseExpressionList(token.RPAREN),
	}
}

func (p *Parser) parseStringLiteral() ast.Expression {
	return &ast.StringLiteral{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}
}

func (p *Parser) parseArrayLiteral() ast.Expression {
	return &ast.ArrayLiteral{
		Token:    p.curToken,
		Elements: p.parseExpressionList(token.RBRACKET),
	}
}

func (p *Parser) parseIndexExpression(left ast.Expression) ast.Expression {
	expr := &ast.IndexExpression{
		Token: p.curToken,
		Left:  left,
	}

	p.nextToken()
	expr.Index = p.parseExpression(LOWEST)

	if !p.expectPeek(token.RBRACKET) {
		return nil
	}

	return expr
}

func (p *Parser) parseHashLiteral() ast.Expression {
	hash := &ast.HashLiteral{
		Token: p.curToken,
		Pairs: make(map[ast.Expression]ast.Expression),
	}

	for !p.peekTokenIs(token.RBRACE) {
		p.nextToken()
		key := p.parseExpression(LOWEST)

		if !p.expectPeek(token.COLON) {
			return nil
		}

		p.nextToken()
		value := p.parseExpression(LOWEST)
		hash.Pairs[key] = value

		if !p.peekTokenIs(token.RBRACE) && !p.expectPeek(token.COMMA) {
			return nil
		}
	}

	if !p.expectPeek(token.RBRACE) {
		return nil
	}

	return hash
}

func (p *Parser) parseMacroLiteral() ast.Expression {
	tok := p.curToken

	if !p.expectPeek(token.LPAREN) {
		return nil
	}

	params := p.parseFunctionParameters()

	if !p.expectPeek(token.LBRACE) {
		return nil
	}

	body := p.parseBlockStatement()

	return &ast.MacroLiteral{
		Token:      tok,
		Parameters: params,
		Body:       body,
	}
}

// 判斷是否為 LPC 的型別 Token
func (p *Parser) isTypeToken(t token.TokenType) bool {
	switch t {
	case token.INT_TYPE, token.STRING_TYPE, token.OBJECT_TYPE, 
	     token.MAPPING_TYPE, token.FLOAT_TYPE, token.MIXED_TYPE, token.VOID_TYPE:
		return true
	default:
		return false
	}
}

func (p *Parser) parseStatement() ast.Statement {
	if p.isTypeToken(p.curToken.TokenType) {
		return p.parseTypedDeclarationStatement()
	}

	switch p.curToken.TokenType {
	case token.RETURN:
		return p.parseReturnStatement()
	case token.INHERIT:
		return p.parseInheritStatement()
	case token.FOR:
		return p.parseForStatement()
	case token.WHILE:
		return p.parseWhileStatement()
	case token.DO:
		return p.parseDoWhileStatement()
	case token.SWITCH:
		return p.parseSwitchStatement()
	case token.BREAK:
		return p.parseBreakStatement()
	case token.CONTINUE:
		return p.parseContinueStatement()
	case token.FOREACH:
		return p.parseForEachStatement()
	default:
		return p.parseExpressionStatement()
	}
}

// 處理型別宣告（例如 int x = 1; 或 int func() {}）
func (p *Parser) parseTypedDeclarationStatement() ast.Statement {
	typeToken := p.curToken // 記住型別 (e.g., INT_TYPE)

	if !p.expectPeek(token.IDENT) { // 下一個必須是變數或函式名稱
		return nil
	}

	// 這裡改用 &ast.Ident
	name := &ast.Ident{Token: p.curToken, Value: p.curToken.Literal}

	if p.peekTokenIs(token.LPAREN) {
		return p.parseFunctionDefinition(typeToken, name)
	}

	return p.parseTypedVariableDeclaration(typeToken, name)
}

// 注意參數 name 的型別改為 *ast.Ident
func (p *Parser) parseTypedVariableDeclaration(typeToken token.Token, name *ast.Ident) ast.Statement {
	stmt := &ast.TypedVarDecl{
		Token: typeToken,
		Name:  name,
	}

	// 檢查是否有賦值運算子 '='
	if p.peekTokenIs(token.ASSIGN) {
		p.nextToken() // 移動到 '='
		p.nextToken() // 移動到值的部分
		
		stmt.Value = p.parseExpression(LOWEST)
	}

	if p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
	}

	return stmt
}

// 注意參數 name 的型別改為 *ast.Ident
func (p *Parser) parseFunctionDefinition(typeToken token.Token, name *ast.Ident) ast.Statement {
	stmt := &ast.FunctionDef{
		Token: typeToken,
		Name:  name,
	}

	if !p.expectPeek(token.LPAREN) {
		return nil
	}

	stmt.Params = p.parseTypedParameters()

	if !p.expectPeek(token.LBRACE) {
		return nil
	}

	stmt.Body = p.parseBlockStatement()

	return stmt
}

// 輔助函式：解析帶型別的參數
func (p *Parser) parseTypedParameters() []*ast.TypedParam {
	var params []*ast.TypedParam

	if p.peekTokenIs(token.RPAREN) {
		p.nextToken()
		return params
	}

	p.nextToken()

	for {
		if !p.isTypeToken(p.curToken.TokenType) {
			return nil
		}
		paramType := p.curToken

		if !p.expectPeek(token.IDENT) {
			return nil
		}
		
		// 這裡改用 &ast.Ident
		paramName := &ast.Ident{Token: p.curToken, Value: p.curToken.Literal}

		params = append(params, &ast.TypedParam{
			TypeToken: paramType,
			Name:      paramName,
		})

		if p.peekTokenIs(token.COMMA) {
			p.nextToken()
			p.nextToken()
		} else {
			break
		}
	}

	if !p.expectPeek(token.RPAREN) {
		return nil
	}

	return params
}

func (p *Parser) parseInheritStatement() ast.Statement {
	stmt := &ast.InheritStatement{Token: p.curToken}

	// 預期下一個 Token 必須是字串 (STRING)
	if !p.expectPeek(token.STRING) {
		return nil
	}

	stmt.Path = p.curToken.Literal

	// 處理結尾的分號
	if p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
	}

	return stmt
}

// 解析 x = 5, x += 2
func (p *Parser) parseAssignExpression(left ast.Expression) ast.Expression {
	expr := &ast.AssignExpression{
		Token:    p.curToken,
		Operator: p.curToken.Literal,
		Left:     left,
	}
	// 賦值是右結合的 (Right-associative)，所以我們用 prec - 1
	prec := p.curPrecedence()
	p.nextToken()
	expr.Value = p.parseExpression(prec - 1) 
	return expr
}

// 解析 x++, x--
func (p *Parser) parsePostfixExpression(left ast.Expression) ast.Expression {
	// Postfix 不需要向右繼續解析
	return &ast.PostfixExpression{
		Token:    p.curToken,
		Operator: p.curToken.Literal,
		Left:     left,
	}
}

// --- 實作 Break / Continue ---
func (p *Parser) parseBreakStatement() ast.Statement {
	stmt := &ast.BreakStatement{Token: p.curToken}
	if p.peekTokenIs(token.SEMICOLON) { p.nextToken() }
	return stmt
}
func (p *Parser) parseContinueStatement() ast.Statement {
	stmt := &ast.ContinueStatement{Token: p.curToken}
	if p.peekTokenIs(token.SEMICOLON) { p.nextToken() }
	return stmt
}

// --- 實作 While ---
func (p *Parser) parseWhileStatement() ast.Statement {
	stmt := &ast.WhileStatement{Token: p.curToken}
	if !p.expectPeek(token.LPAREN) { return nil }
	p.nextToken()
	stmt.Condition = p.parseExpression(LOWEST)
	if !p.expectPeek(token.RPAREN) { return nil }
	if !p.expectPeek(token.LBRACE) { return nil }
	stmt.Body = p.parseBlockStatement()
	return stmt
}

// --- 實作 For ---
// --- 實作 For ---
func (p *Parser) parseForStatement() ast.Statement {
	stmt := &ast.ForStatement{Token: p.curToken}
	if !p.expectPeek(token.LPAREN) {
		return nil
	}
	p.nextToken() // 移動到 Init 的第一個 Token

	// 1. 解析 Init (可能是 int x = 0; 或 x = 0; 或是空的)
	if !p.curTokenIs(token.SEMICOLON) {
		stmt.Init = p.parseStatement()
	}
	
	// parseStatement() 結束後，curToken 通常會停在 ';' 上
	if p.curTokenIs(token.SEMICOLON) {
		p.nextToken() // 吃掉 ';'，進入 Condition
	} else {
		p.peekError(token.SEMICOLON)
		return nil
	}

	// 2. 解析 Condition (例如 i < 10)
	if !p.curTokenIs(token.SEMICOLON) {
		stmt.Condition = p.parseExpression(LOWEST)
		p.nextToken() // parseExpression 不會自動前進到下一個符號，所以手動移動到 ';'
	}
	
	if p.curTokenIs(token.SEMICOLON) {
		p.nextToken() // 吃掉 ';'，進入 Post
	} else {
		p.peekError(token.SEMICOLON)
		return nil
	}

	// 3. 解析 Post (例如 i++)
	if !p.curTokenIs(token.RPAREN) {
		stmt.Post = p.parseExpression(LOWEST)
		p.nextToken() // 移動到 ')'
	}
	
	// 確認現在確實踩在 ')' 上
	if !p.curTokenIs(token.RPAREN) {
		p.peekError(token.RPAREN)
		return nil
	}

	// 預期接下來是 '{' 開啟 Body
	if !p.expectPeek(token.LBRACE) {
		return nil
	}
	stmt.Body = p.parseBlockStatement()
	
	return stmt
}

// --- 實作 Do-While ---
func (p *Parser) parseDoWhileStatement() ast.Statement {
	stmt := &ast.DoWhileStatement{Token: p.curToken}
	if !p.expectPeek(token.LBRACE) { return nil }
	stmt.Body = p.parseBlockStatement()
	if !p.expectPeek(token.WHILE) { return nil }
	if !p.expectPeek(token.LPAREN) { return nil }
	p.nextToken()
	stmt.Condition = p.parseExpression(LOWEST)
	if !p.expectPeek(token.RPAREN) { return nil }
	if p.peekTokenIs(token.SEMICOLON) { p.nextToken() }
	return stmt
}

// --- 實作 Switch ---
func (p *Parser) parseSwitchStatement() ast.Statement {
	stmt := &ast.SwitchStatement{Token: p.curToken}
	if !p.expectPeek(token.LPAREN) { return nil }
	p.nextToken()
	stmt.Value = p.parseExpression(LOWEST)
	if !p.expectPeek(token.RPAREN) { return nil }
	if !p.expectPeek(token.LBRACE) { return nil }

	p.nextToken()
	for !p.curTokenIs(token.RBRACE) && !p.curTokenIs(token.EOF) {
		if p.curTokenIs(token.CASE) || p.curTokenIs(token.DEFAULT) {
			caseStmt := &ast.CaseStatement{Token: p.curToken}
			if p.curTokenIs(token.CASE) {
				p.nextToken()
				caseStmt.Value = p.parseExpression(LOWEST)
			}
			if !p.expectPeek(token.COLON) { return nil }
			p.nextToken()
			
			// 讀取 Case 裡的 statements，直到遇到下一個 case/default 或 }
			for !p.curTokenIs(token.CASE) && !p.curTokenIs(token.DEFAULT) && !p.curTokenIs(token.RBRACE) && !p.curTokenIs(token.EOF) {
				s := p.parseStatement()
				if s != nil { caseStmt.Body = append(caseStmt.Body, s) }
				p.nextToken()
			}
			stmt.Cases = append(stmt.Cases, caseStmt)
		} else {
			p.nextToken() // 錯誤恢復：如果不是 case/default 則跳過
		}
	}
	return stmt
}

func (p *Parser) parseMappingLiteral() ast.Expression {
	mapping := &ast.MappingLiteral{
		Token: p.curToken,
		Pairs: make(map[ast.Expression]ast.Expression),
	}

	// 只要還沒遇到結尾的 '])'，就繼續解析鍵值對
	for !p.peekTokenIs(token.RBRACKET_MAP) {
		p.nextToken()
		
		// 1. 解析 Key
		key := p.parseExpression(LOWEST)

		// 2. 預期接下來是冒號 ':'
		if !p.expectPeek(token.COLON) {
			return nil
		}

		p.nextToken()
		
		// 3. 解析 Value
		value := p.parseExpression(LOWEST)
		
		mapping.Pairs[key] = value

		// 4. 處理逗號：如果下一個不是 '])'，那就必須是逗號 ','
		// 這同時支援了尾隨逗號 (trailing comma) 的寫法：([ "a":1, ])
		if !p.peekTokenIs(token.RBRACKET_MAP) && !p.expectPeek(token.COMMA) {
			return nil
		}
	}

	// 最後確保完美收尾在 '])' 上
	if !p.expectPeek(token.RBRACKET_MAP) {
		return nil
	}

	return mapping
}

// 處理 ::func()
func (p *Parser) parsePrefixScope() ast.Expression {
	if !p.expectPeek(token.IDENT) {
		return nil
	}
	return &ast.Ident{
		Token: p.curToken, // IDENT token
		Value: "::" + p.curToken.Literal,
	}
}

// 處理 parent::func()
func (p *Parser) parseInfixScope(left ast.Expression) ast.Expression {
	leftIdent, ok := left.(*ast.Ident)
	if !ok {
		p.errors = append(p.errors, "expected identifier before ::")
		return nil
	}

	if !p.expectPeek(token.IDENT) {
		return nil
	}

	return &ast.Ident{
		Token: p.curToken,
		Value: leftIdent.Value + "::" + p.curToken.Literal,
	}
}

func (p *Parser) parseCallOtherExpression(left ast.Expression) ast.Expression {
	expr := &ast.CallOtherExpression{
		Token:  p.curToken,
		Object: left,
	}

	// 預期 -> 後面必須緊接著一個識別字 (函式名稱)
	if !p.expectPeek(token.IDENT) {
		return nil
	}

	expr.Method = &ast.Ident{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}

	// 預期函式名稱後面必須接著 '('
	if !p.expectPeek(token.LPAREN) {
		return nil
	}

	// 沿用原本解析參數列表的輔助函式
	expr.Arguments = p.parseExpressionList(token.RPAREN)

	return expr
}

func (p *Parser) parseClosureLiteral() ast.Expression {
	lit := &ast.ClosureLiteral{Token: p.curToken}
	lit.Elements = p.parseExpressionList(token.COLON_RPAREN)
	return lit
}

func (p *Parser) parseForEachStatement() ast.Statement {
	stmt := &ast.ForEachStatement{Token: p.curToken}

	if !p.expectPeek(token.LPAREN) { return nil }
	p.nextToken()

	// 讀取第一個變數 (可能只是 item，也可能是 mapping 的 key)
	firstIdent := &ast.Ident{Token: p.curToken, Value: p.curToken.Literal}
	
	p.nextToken() // 偷看下一個符號

	if p.curToken.TokenType == token.COMMA {
		// 如果有逗號，代表是 foreach(key, value in mapping)
		stmt.Key = firstIdent
		p.nextToken() // 跳過逗號
		stmt.Value = &ast.Ident{Token: p.curToken, Value: p.curToken.Literal}
		p.nextToken()
	} else {
		// 只有一個變數，代表是 foreach(item in array)
		stmt.Value = firstIdent
	}

	// 預期接下來是 'in' 關鍵字
	if p.curToken.TokenType != token.IN {
		p.errors = append(p.errors, "foreach 語法缺少 'in' 關鍵字")
		return nil
	}
	p.nextToken() // 跳過 'in'

	stmt.Collection = p.parseExpression(LOWEST)

	if !p.expectPeek(token.RPAREN) { return nil }
	if !p.expectPeek(token.LBRACE) { return nil }

	stmt.Body = p.parseBlockStatement()

	return stmt
}
