package lexer

import "mudscript/token"

// Lexer represents a lexer for Monkey programming language.
type Lexer interface {
	// NextToken returns a next token.
	NextToken() token.Token
}

type lexer struct {
	input string
	// current position in input (points to current char)
	position int
	// current reading position in input (after current char)
	readPosition int
	// current char under examination
	ch byte
}

// New returns a new Lexer.
func New(input string) Lexer {
	l := &lexer{input: input}
	l.readChar()
	return l
}

func (l *lexer) readChar() {
	if l.readPosition >= len(l.input) {
		l.ch = 0
	} else {
		l.ch = l.input[l.readPosition]
	}
	l.position = l.readPosition
	l.readPosition++
}

func (l *lexer) NextToken() token.Token {
	var tok token.Token

	l.skipWhitespace()

	// skip comments
	for l.ch == '/' {
		if l.peekChar() == '/' {
			l.skipSingleLineComment()
			l.skipWhitespace()
		} else if l.peekChar() == '*' {
			l.skipMultiLineComment()
			l.skipWhitespace()
		} else {
			break
		}
	}

	switch l.ch {
	case '-':
		if l.peekChar() == '>' { // 處理 ->
			ch := l.ch
			l.readChar()
			literal := string(ch) + string(l.ch)
			tok = token.Token{TokenType: token.ARROW, Literal: literal}
		} else {
			tok = newToken(token.MINUS, l.ch)
		}
	case ':':
		if l.peekChar() == ':' { // 處理 ::
			ch := l.ch
			l.readChar()
			literal := string(ch) + string(l.ch)
			tok = token.Token{TokenType: token.SCOPE, Literal: literal}
		} else {
			tok = newToken(token.COLON, l.ch)
		}
	case '(':
		if l.peekChar() == '[' { // 處理 ([
			ch := l.ch
			l.readChar()
			literal := string(ch) + string(l.ch)
			tok = token.Token{TokenType: token.LBRACKET_MAP, Literal: literal}
		} else {
			tok = newToken(token.LPAREN, l.ch)
		}
	case ')':
		tok = newToken(token.RPAREN, l.ch)
	case ']':
		if l.peekChar() == ')' { // 處理 ])
			// 注意：這部分的實作取決於你的 Parser 是把 ]) 當作一個 token 還是兩個
			ch := l.ch
			l.readChar()
			literal := string(ch) + string(l.ch)
			tok = token.Token{TokenType: token.RBRACKET_MAP, Literal: literal}
		} else {
			tok = newToken(token.RBRACKET, l.ch)
		}
	case '[':
		tok = newToken(token.LBRACKET, l.ch)
	case '=':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{
				TokenType:    token.EQ,
				Literal: string(ch) + string(l.ch),
			}
		} else {
			tok = newToken(token.ASSIGN, l.ch)
		}
	case '!':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{
				TokenType:    token.NEQ,
				Literal: string(ch) + string(l.ch),
			}
		} else {
			tok = newToken(token.BANG, l.ch)
		}
	case ';':
		tok = newToken(token.SEMICOLON, l.ch)
	case ',':
		tok = newToken(token.COMMA, l.ch)
	case '+':
		tok = newToken(token.PLUS, l.ch)
	case '*':
		tok = newToken(token.ASTARISK, l.ch)
	case '/':
		tok = newToken(token.SLASH, l.ch)
	case '<':
		tok = newToken(token.LT, l.ch)
	case '>':
		tok = newToken(token.GT, l.ch)
	case '{':
		tok = newToken(token.LBRACE, l.ch)
	case '}':
		tok = newToken(token.RBRACE, l.ch)
	case '"':
		tok.TokenType = token.STRING
		tok.Literal = l.readString()
	case 0:
		tok.Literal = ""
		tok.TokenType = token.EOF
	default:
		if isDigit(l.ch) {
			return l.readNumberToken()
		}

		if isLetter(l.ch) {
			tok.Literal = l.readIdent()
			tok.TokenType = token.LookupIdent(tok.Literal)
			return tok
		}

		tok = newToken(token.ILLEGAL, l.ch)
	}

	l.readChar()
	return tok
}

func (l *lexer) skipMultiLineComment() {
	l.readChar() // 吃掉 '/'
	l.readChar() // 吃掉 '*'
	for l.ch != 0 {
		if l.ch == '*' && l.peekChar() == '/' {
			l.readChar() // 吃掉 '*'
			l.readChar() // 吃掉 '/'
			return
		}
		l.readChar()
	}
}

func (l *lexer) skipSingleLineComment() {
	l.readChar() // 吃掉 '/'
	l.readChar() // 吃掉 '/'
	for l.ch != 0 {
		if l.ch == '\n' {
			l.readChar() // 吃掉 '\n'
			return
		}
		l.readChar()
	}
}

func (l *lexer) skipWhitespace() {
	for l.ch == ' ' || l.ch == '\t' || l.ch == '\n' || l.ch == '\r' {
		l.readChar()
	}
}

func (l *lexer) skipComment() {
	for l.ch != '\n' && l.ch != '\r' {
		l.readChar()
	}
	l.skipWhitespace()
}

func (l *lexer) peekChar() byte {
	if l.readPosition >= len(l.input) {
		return 0
	}
	return l.input[l.readPosition]
}

func (l *lexer) readString() string {
	position := l.position + 1
	for {
		l.readChar()
		if l.ch == '"' || l.ch == 0 {
			break
		}
	}
	return l.input[position:l.position]
}

func (l *lexer) read(checkFn func(byte) bool) string {
	position := l.position
	for checkFn(l.ch) {
		l.readChar()
	}
	return l.input[position:l.position]
}

func (l *lexer) readIdent() string {
	return l.read(isLetter)
}

func (l *lexer) readNumber() string {
	return l.read(isDigit)
}

func (l *lexer) readNumberToken() token.Token {
	intPart := l.readNumber()
	if l.ch != '.' {
		return token.Token{
			TokenType:    token.INT,
			Literal: intPart,
		}
	}

	l.readChar()
	fracPart := l.readNumber()
	return token.Token{
		TokenType:    token.FLOAT,
		Literal: intPart + "." + fracPart,
	}
}

func isLetter(ch byte) bool {
	return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_'
}

func isDigit(ch byte) bool {
	return '0' <= ch && ch <= '9'
}

func newToken(tokenType token.TokenType, ch byte) token.Token {
	return token.Token{
		TokenType:    tokenType,
		Literal: string(ch),
	}
}
