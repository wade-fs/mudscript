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

	l.skipWhitespaceAndComments()

	switch l.ch {
	case '(':
		if l.peekChar() == '[' { // 原有的: 處理 ([
			ch := l.ch
			l.readChar()
			literal := string(ch) + string(l.ch)
			tok = token.Token{TokenType: token.LBRACKET_MAP, Literal: literal}
		} else if l.peekChar() == ':' { // [新增]: 處理 (: 
			ch := l.ch
			l.readChar()
			literal := string(ch) + string(l.ch)
			tok = token.Token{TokenType: token.LPAREN_COLON, Literal: literal}
		} else {
			tok = newToken(token.LPAREN, l.ch)
		}
	case ':':
		if l.peekChar() == ':' { // 原有的: 處理 ::
			ch := l.ch
			l.readChar()
			literal := string(ch) + string(l.ch)
			tok = token.Token{TokenType: token.SCOPE, Literal: literal}
		} else if l.peekChar() == ')' { // [新增]: 處理 :)
			ch := l.ch
			l.readChar()
			literal := string(ch) + string(l.ch)
			tok = token.Token{TokenType: token.COLON_RPAREN, Literal: literal}
		} else {
			tok = newToken(token.COLON, l.ch)
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
	case '&':
		if l.peekChar() == '&' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.AND, Literal: string(ch) + string(l.ch)}
		} else {
			tok = newToken(token.ILLEGAL, l.ch) // MUD 暫不支援單一的 & (位元運算可後續加)
		}
	case '|':
		if l.peekChar() == '|' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.OR, Literal: string(ch) + string(l.ch)}
		} else {
			tok = newToken(token.ILLEGAL, l.ch) 
		}
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
		if l.peekChar() == '+' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.INC, Literal: string(ch) + string(l.ch)}
		} else if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.PLUS_EQUALS, Literal: string(ch) + string(l.ch)}
		} else {
			tok = newToken(token.PLUS, l.ch)
		}
	case '-':
		if l.peekChar() == '>' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.ARROW, Literal: string(ch) + string(l.ch)}
		} else if l.peekChar() == '-' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.DEC, Literal: string(ch) + string(l.ch)}
		} else if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.MINUS_EQUALS, Literal: string(ch) + string(l.ch)}
		} else {
			tok = newToken(token.MINUS, l.ch)
		}
	case '*':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.ASTERISK_EQUALS, Literal: string(ch) + string(l.ch)}
		} else {
			tok = newToken(token.ASTARISK, l.ch)
		}
	case '/':
		// 註解已經在最上面過濾掉了，這裡處理 /= 和 /
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.SLASH_EQUALS, Literal: string(ch) + string(l.ch)}
		} else {
			tok = newToken(token.SLASH, l.ch)
		}
	case '%':
		tok = newToken(token.MOD, l.ch)
	case '<':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.LTE, Literal: string(ch) + string(l.ch)}
		} else {
			tok = newToken(token.LT, l.ch)
		}
	case '>':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{TokenType: token.GTE, Literal: string(ch) + string(l.ch)}
		} else {
			tok = newToken(token.GT, l.ch)
		}
	case '{':
		tok = newToken(token.LBRACE, l.ch)
	case '}':
		tok = newToken(token.RBRACE, l.ch)
	case '"':
		tok.TokenType = token.STRING
		tok.Literal = l.readString()
	case '\'':
		tok.TokenType = token.CHAR
		tok.Literal = l.readCharLiteral()
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
    // 一直讀取字元，直到遇到換行符號 '\n' 或是字串結尾的 0
    for l.ch != '\n' && l.ch != 0 {
        l.readChar()
    }
    l.skipWhitespace() // 註解結束後，繼續跳過後面的空白
}

func (l *lexer) skipWhitespace() {
	for l.ch == ' ' || l.ch == '\t' || l.ch == '\n' || l.ch == '\r' {
		l.readChar()
	}
}

func (l *lexer) peekChar() byte {
	if l.readPosition >= len(l.input) {
		return 0
	}
	return l.input[l.readPosition]
}

func (l *lexer) readString() string {
	var out []byte
	for {
		l.readChar()
		if l.ch == '"' || l.ch == 0 {
			break
		}

		// 處理轉義字元 (Escape Sequences)
		if l.ch == '\\' {
			l.readChar() // 讀取斜線後面的字元
			switch l.ch {
			case 'n':
				out = append(out, '\n')
			case 't':
				out = append(out, '\t')
			case 'r':
				out = append(out, '\r')
			case '"':
				out = append(out, '"')
			case '\\':
				out = append(out, '\\')
			default:
				// 如果是不認識的轉義，保留原樣
				out = append(out, '\\', l.ch)
			}
		} else {
			out = append(out, l.ch)
		}
	}
	return string(out)
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
	position := l.position

	// 檢查是否為 16 進位 (0x 或 0X)
	if l.ch == '0' && (l.peekChar() == 'x' || l.peekChar() == 'X') {
		l.readChar() // 讀掉 0
		l.readChar() // 讀掉 x
		for isHexDigit(l.ch) {
			l.readChar()
		}
		return l.input[position:l.position]
	}

	// 否則照舊處理一般 10 進位或浮點數
	for isDigit(l.ch) {
		l.readChar()
	}
	// 這裡可以保留你原本處理浮點數 (float) 小數點的邏輯...
	return l.input[position:l.position]
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

// 讀取單字元 (例如 'c')
func (l *lexer) readCharLiteral() string {
	l.readChar() // 讀掉開頭的單引號
	char := l.ch
	l.readChar() // 讀掉字元本身
	if l.ch == '\'' {
		// 注意這裡不呼叫 l.readChar()，因為 NextToken 最後面會統一呼叫
	}
	return string(char)
}

// 判斷是否為十六進位字元
func isHexDigit(ch byte) bool {
	return isDigit(ch) || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F')
}

// 為了讓註解處理更強健，我們把略過空白與註解的邏輯包裝起來
func (l *lexer) skipWhitespaceAndComments() {
	for {
		l.skipWhitespace()
		if l.ch == '/' && l.peekChar() == '/' {
			l.skipSingleLineComment()
		} else if l.ch == '/' && l.peekChar() == '*' {
			l.skipMultiLineComment()
		} else {
			break
		}
	}
}
