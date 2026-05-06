// lexer/lexer_test.go
package lexer

import (
	"testing"
	"mudscript/token"
)

func TestNextToken_LPCSymbols(t *testing.T) {
	input := `
#include <ansi.h>

/* 這是一段
   多行註解測試 */
void main() {
    object ob = this_player();
    ob->add_hp(10);
    base::create();

    mapping m = ([ "key": 'a' ]);
    
    int x = 10 % 3;
    x += 1;
    x -= 1;
    x *= 1;
    x /= 1;
    x++;
    x--;

    if (x > 0 && x < 10 || x == 5) {
        // 單行註解
        return;
    }
}
`

	tests := []struct {
		expectedType    token.TokenType
		expectedLiteral string
	}{
		{token.PREPROCESSOR, "#include <ansi.h>"},
		// 注意：多行註解應該被直接略過，不產生 Token
		{token.VOID_TYPE, "void"},
		{token.IDENT, "main"},
		{token.LPAREN, "("},
		{token.RPAREN, ")"},
		{token.LBRACE, "{"},

		{token.OBJECT_TYPE, "object"},
		{token.IDENT, "ob"},
		{token.ASSIGN, "="},
		{token.IDENT, "this_player"},
		{token.LPAREN, "("},
		{token.RPAREN, ")"},
		{token.SEMICOLON, ";"},

		{token.IDENT, "ob"},
		{token.ARROW, "->"},
		{token.IDENT, "add_hp"},
		{token.LPAREN, "("},
		{token.INT, "10"},
		{token.RPAREN, ")"},
		{token.SEMICOLON, ";"},

		{token.IDENT, "base"},
		{token.SCOPE, "::"},
		{token.IDENT, "create"},
		{token.LPAREN, "("},
		{token.RPAREN, ")"},
		{token.SEMICOLON, ";"},

		{token.MAPPING_TYPE, "mapping"},
		{token.IDENT, "m"},
		{token.ASSIGN, "="},
		{token.LBRACKET_MAP, "(["},
		{token.STRING, "key"},
		{token.COLON, ":"},
		{token.CHAR, "a"},
		{token.RBRACKET_MAP, "])"},
		{token.SEMICOLON, ";"},

		{token.INT_TYPE, "int"},
		{token.IDENT, "x"},
		{token.ASSIGN, "="},
		{token.INT, "10"},
		{token.PERCENT, "%"},
		{token.INT, "3"},
		{token.SEMICOLON, ";"},

		{token.IDENT, "x"},
		{token.PLUS_EQUALS, "+="},
		{token.INT, "1"},
		{token.SEMICOLON, ";"},

		{token.IDENT, "x"},
		{token.MINUS_EQUALS, "-="},
		{token.INT, "1"},
		{token.SEMICOLON, ";"},

		{token.IDENT, "x"},
		{token.ASTERISK_EQUALS, "*="},
		{token.INT, "1"},
		{token.SEMICOLON, ";"},

		{token.IDENT, "x"},
		{token.SLASH_EQUALS, "/="},
		{token.INT, "1"},
		{token.SEMICOLON, ";"},

		{token.IDENT, "x"},
		{token.INC, "++"},
		{token.SEMICOLON, ";"},

		{token.IDENT, "x"},
		{token.DEC, "--"},
		{token.SEMICOLON, ";"},

		{token.IF, "if"},
		{token.LPAREN, "("},
		{token.IDENT, "x"},
		{token.GT, ">"},
		{token.INT, "0"},
		{token.AND, "&&"},
		{token.IDENT, "x"},
		{token.LT, "<"},
		{token.INT, "10"},
		{token.OR, "||"},
		{token.IDENT, "x"},
		{token.EQ, "=="},
		{token.INT, "5"},
		{token.RPAREN, ")"},
		{token.LBRACE, "{"},

		// 單行註解也應該被忽略
		{token.RETURN, "return"},
		{token.SEMICOLON, ";"},
		{token.RBRACE, "}"},
		{token.RBRACE, "}"},
		{token.EOF, ""},
	}

	l := New(input)

	for i, tt := range tests {
		tok := l.NextToken()

		if tok.TokenType != tt.expectedType {
			t.Fatalf("tests[%d] - tokentype wrong. expected=%q, got=%q",
				i, tt.expectedType, tok.TokenType)
		}

		if tok.Literal != tt.expectedLiteral {
			t.Fatalf("tests[%d] - literal wrong. expected=%q, got=%q",
				i, tt.expectedLiteral, tok.Literal)
		}
	}
}
