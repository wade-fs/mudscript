package object

import (
	"bytes"
	"fmt"
	"hash/fnv"
	"strconv"
	"strings"

	"mudscript/ast"
)

// TokenType is a type of objects.
type TokenType string

const (
	// IntegerType represents a type of integers.
	IntegerType TokenType = "Integer"
	// FloatType represents a type of floating point numbers.
	FloatType = "Float"
	// BooleanType represents a type of booleans.
	BooleanType = "Boolean"
	// NilType represents a type of nil.
	NilType = "Nil"
	// ReturnValueType represents a type of return values.
	ReturnValueType = "ReturnValue"
	// ErrorType represents a type of errors.
	ErrorType = "Error"
	// FunctionType represents a type of functions.
	FunctionType = "Function"
	// StringType represents a type of strings.
	StringType = "String"
	// BuiltinType represents a type of builtin functions.
	BuiltinType = "Builtin"
	// ArrayType represents a type of arrays.
	ArrayType = "Array"
	// HashType represents a type of hashes.
	HashType = "Hash"
	// QuoteType represents a type of quotes used for macros.
	QuoteType = "Quote"
	// MacroType represents a type of macros.
	MacroType = "Macro"

	////////////////////////////////////////////
	// mudscript
	LPC_OBJECT_OBJ = "LPC_OBJECT"
	MAPPING_OBJ    = "MAPPING"
)

// Object represents an object of Monkey language.
type Object interface {
	TokenType() TokenType
	Inspect() string
}

// HashKey represents a key of a hash.
type HashKey struct {
	TokenType  TokenType
	Value uint64
}

// Hashable is the interface that is able to become a hash key.
type Hashable interface {
	HashKey() HashKey
}

// Integer represents an integer.
type Integer struct {
	Value int64
}

// TokenType returns the type of the Integer.
func (i *Integer) TokenType() TokenType {
	return IntegerType
}

// Inspect returns a string representation of the Integer.
func (i *Integer) Inspect() string {
	return strconv.FormatInt(i.Value, 10)
}

// HashKey returns a hash key object for i.
func (i *Integer) HashKey() HashKey {
	return HashKey{
		TokenType:  i.TokenType(),
		Value: uint64(i.Value),
	}
}

// Float represents an integer.
type Float struct {
	Value float64
}

// TokenType returns the type of f.
func (f *Float) TokenType() TokenType {
	return FloatType
}

// Inspect returns a string representation of f.
func (f *Float) Inspect() string {
	return strconv.FormatFloat(f.Value, 'f', -1, 64)
}

// HashKey returns a hash key object for f.
func (f *Float) HashKey() HashKey {
	s := strconv.FormatFloat(f.Value, 'f', -1, 64)
	h := fnv.New64a()
	h.Write([]byte(s))

	return HashKey{
		TokenType:  f.TokenType(),
		Value: h.Sum64(),
	}
}

// Boolean represents a boolean.
type Boolean struct {
	Value bool
}

// TokenType returns the type of the Boolean.
func (b *Boolean) TokenType() TokenType {
	return BooleanType
}

// Inspect returns a string representation of the Boolean.
func (b *Boolean) Inspect() string {
	return strconv.FormatBool(b.Value)
}

// HashKey returns a hash key object for b.
func (b *Boolean) HashKey() HashKey {
	key := HashKey{TokenType: b.TokenType()}
	if b.Value {
		key.Value = 1
	}
	return key
}

// Nil represents the absence of any value.
type Nil struct{}

// TokenType returns the type of the Nil.
func (n *Nil) TokenType() TokenType {
	return NilType
}

// Inspect returns a string representation of the Nil.
func (n *Nil) Inspect() string {
	return "nil"
}

// ReturnValue represents a return value.
type ReturnValue struct {
	Value Object
}

// TokenType returns the type of the ReturnValue.
func (rv *ReturnValue) TokenType() TokenType {
	return ReturnValueType
}

// Inspect returns a string representation of the ReturnValue.
func (rv *ReturnValue) Inspect() string {
	return rv.Value.Inspect()
}

// Error represents an error.
type Error struct {
	Message string
}

func NewError(format string, a ...interface{}) *Error {
	return &Error{Message: fmt.Sprintf(format, a...)}
}

// TokenType returns the type of the Error.
func (e *Error) TokenType() TokenType {
	return ErrorType
}

// Inspect returns a string representation of the Error.
func (e *Error) Inspect() string {
	return "Error: " + e.Message
}

// Function represents a function.
type Function struct {
	Parameters []*ast.Ident
	Body       *ast.BlockStatement
	Env        Environment
}

// TokenType returns the type of the Function.
func (f *Function) TokenType() TokenType {
	return FunctionType
}

// Inspect returns a string representation of the Function.
func (f *Function) Inspect() string {
	var out bytes.Buffer

	params := make([]string, 0, len(f.Parameters))
	for _, p := range f.Parameters {
		params = append(params, p.String())
	}

	out.WriteString("fn(")
	out.WriteString(strings.Join(params, ", "))
	out.WriteString(") {\n")
	out.WriteString(f.Body.String())
	out.WriteString("\n}")

	return out.String()
}

// String represents a string.
type String struct {
	Value string
}

// TokenType returns the type of the String.
func (s *String) TokenType() TokenType {
	return StringType
}

// Inspect returns a string representation of the String.
func (s *String) Inspect() string {
	return s.Value
}

// HashKey returns a hash key object for s.
func (s *String) HashKey() HashKey {
	h := fnv.New64a()
	h.Write([]byte(s.Value))

	return HashKey{
		TokenType:  s.TokenType(),
		Value: h.Sum64(),
	}
}

// BuiltinFunction represents a function signature of builtin functions.
type BuiltinFunction func(args ...Object) Object

// Builtin represents a builtin function.
type Builtin struct {
	Fn BuiltinFunction
}

// TokenType returns the type of the Builtin.
func (b *Builtin) TokenType() TokenType {
	return BuiltinType
}

// Inspect returns a string representation of the Builtin.
func (b *Builtin) Inspect() string {
	return "builtin function"
}

// Array represents an array.
type Array struct {
	Elements []Object
}

// TokenType returns the type of the Array.
func (*Array) TokenType() TokenType {
	return ArrayType
}

// Inspect returns a string representation of the Array.
func (a *Array) Inspect() string {
	if a == nil {
		return ""
	}

	elements := make([]string, 0, len(a.Elements))
	for _, e := range a.Elements {
		elements = append(elements, e.Inspect())
	}

	var out bytes.Buffer
	out.WriteString("[")
	out.WriteString(strings.Join(elements, ", "))
	out.WriteString("]")
	return out.String()
}

// HashPair represents a key-value pair in a hash.
type HashPair struct {
	Key   Object
	Value Object
}

// Hash represents a hash.
type Hash struct {
	Pairs map[HashKey]HashPair
}

// TokenType returns the type of the Hash.
func (*Hash) TokenType() TokenType {
	return HashType
}

// Inspect returns a string representation of the Hash.
func (h *Hash) Inspect() string {
	if h == nil {
		return ""
	}

	pairs := make([]string, 0, len(h.Pairs))
	for _, pair := range h.Pairs {
		pairs = append(pairs, pair.Key.Inspect()+": "+pair.Value.Inspect())
	}

	var out bytes.Buffer
	out.WriteString("{")
	out.WriteString(strings.Join(pairs, ", "))
	out.WriteString("}")
	return out.String()
}

// Quote represents a quote, i.e. an unevaluated expression.
type Quote struct {
	ast.Node
}

// TokenType returns the type of `q`.
func (q *Quote) TokenType() TokenType {
	return QuoteType
}

// Inspect returns a string representation of `q`.
func (q *Quote) Inspect() string {
	return fmt.Sprintf("%s(%s)", QuoteType, q.Node.String())
}

// Macro represents a macro.
type Macro struct {
	Parameters []*ast.Ident
	Body       *ast.BlockStatement
	Env        Environment
}

// TokenType returns the type of `m`.
func (m *Macro) TokenType() TokenType {
	return MacroType
}

// Inspect returns a string representation of `m`.
func (m *Macro) Inspect() string {
	var out bytes.Buffer

	params := make([]string, 0, len(m.Parameters))
	for _, p := range m.Parameters {
		params = append(params, p.String())
	}

	out.WriteString("macro(")
	out.WriteString(strings.Join(params, ", "))
	out.WriteString(") {\n")
	out.WriteString(m.Body.String())
	out.WriteString("\n}")

	return out.String()
}

////////////////////////////////////////////////
// mudscript

// LPCObject: 代表一個載入記憶體中的 LPC 物件實體 (.c 檔)
type LPCObject struct {
	Filename    string
	Vars        Environment
	Functions   map[string]*Function
	Inherits    []*LPCObject
	
	// --- 新增：空間與生命週期狀態 ---
	Location    *LPCObject   // 這個物件目前在哪裡？ (例如在某個房間，或某個玩家身上)
	Inventory   []*LPCObject // 這個物件裡面裝了什麼？
	IsDestructed bool        // 標記是否已經被摧毀
}

// TokenType implements Object interface
func (o *LPCObject) TokenType() TokenType {
	return LPC_OBJECT_OBJ
}

func (o *LPCObject) Inspect() string {
	return "<object: " + o.Filename + ">"
}

// Mapping: LPC 專用的 mapping 結構
type Mapping struct {
	Pairs map[string]Object
}

// TokenType implements Object interface
func (m *Mapping) TokenType() TokenType {
	return MAPPING_OBJ
}

func (m *Mapping) Inspect() string {
	var out bytes.Buffer
	var pairs []string

	for key, val := range m.Pairs {
		pairs = append(pairs, `"`+key+`": `+val.Inspect())
	}

	out.WriteString("([ ")
	out.WriteString(strings.Join(pairs, ", "))
	out.WriteString(" ])")

	return out.String()
}
