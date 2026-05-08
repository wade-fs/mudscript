package parser

import (
	"fmt"
	"strconv"
	"strings" // [新增] 用來處理字串切分

	"mudscript/ast"
	"mudscript/lexer"
	"mudscript/token"
)

const (
	_ int = iota
	LOWEST
	ASSIGN      // = += -= *= /=
	LOGICAL_OR	// ||
	LOGICAL_AND	// &&
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
	token.OR:       LOGICAL_OR,
	token.AND:      LOGICAL_AND,
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
	token.MOD:      PRODUCT,
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
		token.LARRAY:   p.parseLPCArrayLiteral,

		token.LBRACKET_MAP: p.parseMappingLiteral,
		token.SCOPE:        p.parsePrefixScope,
		token.LPAREN_COLON: p.parseClosureLiteral,
	}

	p.infixParseFns = map[token.TokenType]infixParseFn{
		token.PLUS:     p.parseInfixExpression,
		token.MINUS:    p.parseInfixExpression,
		token.ASTARISK: p.parseInfixExpression,
		token.SLASH:    p.parseInfixExpression,
		token.MOD:		p.parseInfixExpression,
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
		token.AND: p.parseInfixExpression,
 		token.OR:  p.parseInfixExpression,
	}

	p.nextToken()
	p.nextToken()

	return p
}

func (p *Parser) nextToken() {
	p.curToken = p.peekToken
	p.peekToken = p.l.NextToken()
}

func (p *Parser) Errors() []string {
	return p.errors
}

// ==========================================
// [新增] 強大的錯誤產生器
// ==========================================
func (p *Parser) addError(tok token.Token, format string, args ...interface{}) {
	baseMsg := fmt.Sprintf(format, args...)
	
	// 從 lexer 取得完整的原始程式碼，切分成行
	lines := strings.Split(p.l.GetInput(), "\n")
	lineContent := ""
	if tok.Line > 0 && tok.Line <= len(lines) {
		lineContent = lines[tok.Line-1] // 陣列索引是從 0 開始
	}

	// 去除多餘空白，讓終端機顯示更好看
	lineContent = strings.TrimSpace(lineContent)

	// 組裝帶有行號與程式碼內容的錯誤訊息
	finalMsg := fmt.Sprintf("[Line %d] %s\n    > %s", tok.Line, baseMsg, lineContent)
	p.errors = append(p.errors, finalMsg)
}

func (p *Parser) peekError(typ token.TokenType) {
	p.addError(p.peekToken, "預期下一個符號為 '%s'，但得到了 '%s' (%s)", typ, p.peekToken.TokenType, p.peekToken.Literal)
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

	for p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
	}
	return stmt
}

func (p *Parser) parseExpression(precedence int) ast.Expression {
	prefix := p.prefixParseFns[p.curToken.TokenType]
	if prefix == nil {
		p.addError(p.curToken, "無法解析開頭為 '%s' 的語法 (找不到對應的前綴處理器)", p.curToken.TokenType)
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
		p.addError(p.curToken, "無法將 '%s' 解析為整數", p.curToken.Literal)
		return nil
	}

	lit.Value = val
	return lit
}

func (p *Parser) parseFloatLiteral() ast.Expression {
	val, err := strconv.ParseFloat(p.curToken.Literal, 64)
	if err != nil {
		p.addError(p.curToken, "無法將 '%s' 解析為浮點數", p.curToken.Literal)
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

	if !p.expectPeek(token.LPAREN) { return nil }
	p.nextToken()
	expression.Condition = p.parseExpression(LOWEST)
	if !p.expectPeek(token.RPAREN) { return nil }

	// ▼ [關鍵修正]：Consequence (If 成立的分支)
	if p.peekTokenIs(token.LBRACE) {
		p.nextToken()
		expression.Consequence = p.parseBlockStatement()
	} else {
		// 處理單行 if (例如: if(x) return 1;)
		p.nextToken()
		stmt := p.parseStatement()
		expression.Consequence = &ast.BlockStatement{
			Token:      p.curToken,
			Statements: []ast.Statement{stmt},
		}
	}

	if p.peekTokenIs(token.ELSE) {
		p.nextToken() 

		if p.peekTokenIs(token.IF) {
			p.nextToken() 
			elseIfNode := p.parseIfExpression()
			expression.Alternative = &ast.BlockStatement{
				Token: p.curToken,
				Statements: []ast.Statement{
					&ast.ExpressionStatement{
						Token:      p.curToken,
						Expression: elseIfNode,
					},
				},
			}
		} else if p.peekTokenIs(token.LBRACE) {
			p.nextToken()
			expression.Alternative = p.parseBlockStatement()
		} else {
			// ▼ [關鍵修正]：處理單行 else (例如: else return 0;)
			p.nextToken()
			stmt := p.parseStatement()
			expression.Alternative = &ast.BlockStatement{
				Token:      p.curToken,
				Statements: []ast.Statement{stmt},
			}
		}
	}

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
	for p.curTokenIs(token.PRIVATE) || p.curTokenIs(token.STATIC) ||
		p.curTokenIs(token.PROTECTED) || p.curTokenIs(token.VARARGS) ||
		p.curTokenIs(token.NOSAVE) || p.curTokenIs(token.NOMASK) {
		p.nextToken()
	}

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
	return p.parseExpressionStatement()
}

func (p *Parser) parseTypedDeclarationStatement() ast.Statement {
	typeToken := p.curToken 

	// ▼ [關鍵修正]：處理變數宣告中的 '*'
	if p.peekTokenIs(token.ASTARISK) {
		p.nextToken()
	}

	if !p.expectPeek(token.IDENT) { 
		return nil
	}

	name := &ast.Ident{Token: p.curToken, Value: p.curToken.Literal}

	if p.peekTokenIs(token.LPAREN) {
		return p.parseFunctionDefinition(typeToken, name)
	}

	return p.parseTypedVariableDeclaration(typeToken, name)
}

func (p *Parser) parseTypedVariableDeclaration(typeToken token.Token, name *ast.Ident) ast.Statement {
	stmt := &ast.TypedVarDecl{
		Token: typeToken,
		Name:  name,
	}

	if p.peekTokenIs(token.ASSIGN) {
		p.nextToken() 
		p.nextToken() 
		stmt.Value = p.parseExpression(LOWEST)
	}

	for p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
	}

	return stmt
}

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

		// ▼ [關鍵修正]：如果下一個是 '*' (如 string *paths)，將其吃掉
		if p.peekTokenIs(token.ASTARISK) {
			p.nextToken()
		}

		if !p.expectPeek(token.IDENT) {
			return nil
		}
		
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

	if !p.expectPeek(token.STRING) {
		return nil
	}

	stmt.Path = p.curToken.Literal

	if p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
	}

	return stmt
}

func (p *Parser) parseAssignExpression(left ast.Expression) ast.Expression {
	expr := &ast.AssignExpression{
		Token:    p.curToken,
		Operator: p.curToken.Literal,
		Left:     left,
	}
	prec := p.curPrecedence()
	p.nextToken()
	expr.Value = p.parseExpression(prec - 1) 
	return expr
}

func (p *Parser) parsePostfixExpression(left ast.Expression) ast.Expression {
	return &ast.PostfixExpression{
		Token:    p.curToken,
		Operator: p.curToken.Literal,
		Left:     left,
	}
}

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
func (p *Parser) parseForStatement() ast.Statement {
	stmt := &ast.ForStatement{Token: p.curToken}
	if !p.expectPeek(token.LPAREN) {
		return nil
	}
	p.nextToken() // 從 '(' 移到下一個 token (Init 的開頭)

	// 1. 解析 Init (可能是 int i = 0; 或是空 ;)
	if !p.curTokenIs(token.SEMICOLON) {
		stmt.Init = p.parseStatement()
	}
	
	// 處理分號：由於 parseStatement 有時會吃掉結尾的分號，我們必須彈性判斷
	if p.curTokenIs(token.SEMICOLON) {
		p.nextToken() // 吃掉分號，移動到 Condition 的開頭
	} else if p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
		p.nextToken()
	} else {
		p.addError(p.curToken, "for 迴圈初始化區塊缺少分號 ';'")
		return nil
	}

	// 2. 解析 Condition
	if !p.curTokenIs(token.SEMICOLON) {
		stmt.Condition = p.parseExpression(LOWEST)
		p.nextToken() // 表達式解析完後，手動往下推一格
	}
	
	// 處理分號
	if p.curTokenIs(token.SEMICOLON) {
		p.nextToken() // 吃掉分號，移動到 Post 的開頭
	} else if p.peekTokenIs(token.SEMICOLON) {
		p.nextToken()
		p.nextToken()
	} else {
		p.addError(p.curToken, "for 迴圈條件區塊缺少分號 ';'")
		return nil
	}

	// 3. 解析 Post (例如 i++)
	if !p.curTokenIs(token.RPAREN) {
		stmt.Post = p.parseExpression(LOWEST)
		p.nextToken() // 手動往下推一格
	}
	
	// 確保收尾是 ')'
	if !p.curTokenIs(token.RPAREN) {
		if p.peekTokenIs(token.RPAREN) {
			p.nextToken()
		} else {
			p.addError(p.curToken, "for 迴圈缺少結尾的 ')'")
			return nil
		}
	}

	// 4. 解析 Body
	if !p.expectPeek(token.LBRACE) {
		return nil
	}
	stmt.Body = p.parseBlockStatement()

	return stmt
}

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
			
			for !p.curTokenIs(token.CASE) && !p.curTokenIs(token.DEFAULT) && !p.curTokenIs(token.RBRACE) && !p.curTokenIs(token.EOF) {
				s := p.parseStatement()
				if s != nil { caseStmt.Body = append(caseStmt.Body, s) }
				p.nextToken()
			}
			stmt.Cases = append(stmt.Cases, caseStmt)
		} else {
			p.nextToken() 
		}
	}
	return stmt
}

func (p *Parser) parseMappingLiteral() ast.Expression {
	mapping := &ast.MappingLiteral{
		Token: p.curToken,
		Pairs: make(map[ast.Expression]ast.Expression),
	}

	for !p.peekTokenIs(token.RBRACKET) { 
		p.nextToken()
		
		key := p.parseExpression(LOWEST)

		if !p.expectPeek(token.COLON) {
			return nil
		}

		p.nextToken()
		value := p.parseExpression(LOWEST)
		mapping.Pairs[key] = value

		if !p.peekTokenIs(token.RBRACKET) && !p.expectPeek(token.COMMA) { 
			return nil
		}
	}

	if !p.expectPeek(token.RBRACKET) { 
		return nil
	}

	if !p.expectPeek(token.RPAREN) { 
		return nil
	}

	return mapping
}

func (p *Parser) parsePrefixScope() ast.Expression {
	if !p.expectPeek(token.IDENT) {
		return nil
	}
	return &ast.Ident{
		Token: p.curToken, 
		Value: "::" + p.curToken.Literal,
	}
}

func (p *Parser) parseInfixScope(left ast.Expression) ast.Expression {
	leftIdent, ok := left.(*ast.Ident)
	if !ok {
		p.addError(p.curToken, "在 '::' 前面必須是變數或類別名稱")
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

	if !p.expectPeek(token.IDENT) {
		return nil
	}

	expr.Method = &ast.Ident{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}

	if !p.expectPeek(token.LPAREN) {
		return nil
	}

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

	firstIdent := &ast.Ident{Token: p.curToken, Value: p.curToken.Literal}
	
	p.nextToken() 

	if p.curToken.TokenType == token.COMMA {
		stmt.Key = firstIdent
		p.nextToken() 
		stmt.Value = &ast.Ident{Token: p.curToken, Value: p.curToken.Literal}
		p.nextToken()
	} else {
		stmt.Value = firstIdent
	}

	if p.curToken.TokenType != token.IN {
		p.addError(p.curToken, "foreach 語法缺少 'in' 關鍵字")
		return nil
	}
	p.nextToken() 

	stmt.Collection = p.parseExpression(LOWEST)

	if !p.expectPeek(token.RPAREN) { return nil }
	if !p.expectPeek(token.LBRACE) { return nil }

	stmt.Body = p.parseBlockStatement()

	return stmt
}

func (p *Parser) parseLPCArrayLiteral() ast.Expression {
	return &ast.ArrayLiteral{
		Token:    p.curToken,
		Elements: p.parseExpressionList(token.RARRAY),
	}
}
