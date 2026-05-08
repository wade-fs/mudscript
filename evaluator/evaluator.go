package evaluator

import (
	"fmt"
	"regexp"
	"strconv"
	"strings"

	"mudscript/ast"
	"mudscript/object"
)

var (
	// NilValue represents a value of nil reference.
	NilValue = &object.Nil{}
	// TrueValue represents a value of true literals.
	TrueValue = &object.Boolean{Value: true}
	// FalseValue represents a value of false literals.
	FalseValue = &object.Boolean{Value: false}
)

// Eval evaluates the given node and returns an evaluated object.
func Eval(node ast.Node, env object.Environment) object.Object {
	switch node := node.(type) {
	// Statements

	case *ast.Program:
		return evalProgram(node, env)

	case *ast.ExpressionStatement:
		return Eval(node.Expression, env)

	case *ast.ReturnStatement:
		// 支援 return; (空回傳)
		if node.ReturnValue == nil {
			return &object.ReturnValue{Value: &object.Integer{Value: 0}}
		}
		value := Eval(node.ReturnValue, env)
		if isError(value) {
			return value
		}
		return &object.ReturnValue{Value: value}

	case *ast.BlockStatement:
		return evalBlockStatement(node, env)

	case *ast.LetStatement:
		value := Eval(node.Value, env)
		if isError(value) {
			return value
		}
		env.Set(node.Name.Value, value)

	// Expressions

	case *ast.IntegerLiteral:
		return &object.Integer{Value: node.Value}

	case *ast.FloatLiteral:
		return &object.Float{Value: node.Value}

	case *ast.Boolean:
		return nativeBoolToBooleanObject(node.Value)

	case *ast.PrefixExpression:
		right := Eval(node.Right, env)
		if isError(right) {
			return right
		}
		return evalPrefixExpression(node.Operator, right)

	case *ast.InfixExpression:
		left := Eval(node.Left, env)
		if isError(left) {
			return left
		}
		right := Eval(node.Right, env)
		if isError(right) {
			return right
		}
		return evalInfixExpression(node.Operator, left, right)

	case *ast.IfExpression:
		return evalIfExpression(node, env)

	case *ast.Ident:
		return evalIdent(node, env)

	case *ast.FunctionLiteral:
		return &object.Function{
			Parameters: node.Parameters,
			Body:	   node.Body,
			Env:		env,
		}

	case *ast.CallExpression:
		// 攔截 catch 錯誤捕捉
		if ident, ok := node.Function.(*ast.Ident); ok && ident.Value == "catch" {
			return evalCatch(node, env)
		}

		// 攔截 sscanf (作為編譯器級別的關鍵字處理)
		if ident, ok := node.Function.(*ast.Ident); ok && ident.Value == "sscanf" {
			return evalSscanf(node, env)
		}

		function := Eval(node.Function, env)
		if isError(function) {
			return function
		}

		args := evalExpressions(node.Arguments, env)
		if len(args) == 1 && isError(args[0]) {
			return args[0]
		}

		return applyFunction(function, args)

	case *ast.StringLiteral:
		return &object.String{Value: node.Value}

	case *ast.ArrayLiteral:
		elems := evalExpressions(node.Elements, env)
		if len(elems) == 1 && isError(elems[0]) {
			return elems[0]
		}
		return &object.Array{Elements: elems}

	case *ast.IndexExpression:
		left := Eval(node.Left, env)
		if isError(left) {
			return left
		}
		index := Eval(node.Index, env)
		if isError(index) {
			return index
		}
		return evalIndexExpression(left, index)

	case *ast.HashLiteral:
		return evalHashLiteral(node, env)

	// 處理強型別變數宣告 (int x = 10;)
	case *ast.TypedVarDecl:
		return evalTypedVarDecl(node, env)

	// 處理函式定義 (int main() { ... })
	case *ast.FunctionDef:
		return evalFunctionDef(node, env)

	// 重新賦值與複合賦值 (x = 1, x += 2)
	case *ast.AssignExpression:
		return evalAssignExpression(node, env)
	
	// 自增減 (x++, x--)
	case *ast.PostfixExpression:
		return evalPostfixExpression(node, env)

	// 控制流與迴圈
	case *ast.ForStatement:
		return evalForStatement(node, env)
	case *ast.WhileStatement:
		return evalWhileStatement(node, env)
	case *ast.DoWhileStatement:
		return evalDoWhileStatement(node, env)
	case *ast.SwitchStatement:
		return evalSwitchStatement(node, env)
	case *ast.BreakStatement:
		return &object.BreakValue{}
	case *ast.ContinueStatement:
		return &object.ContinueValue{}
	case *ast.MappingLiteral:
		return evalMappingLiteral(node, env)
	case *ast.CallOtherExpression:
		// 1. 先計算左邊的目標物件 (例如 start_room)
		targetObj := Eval(node.Object, env)
		if isError(targetObj) {
			return targetObj
		}

		// 2. 利用我們在 efun 已經註冊好的 call_other 來執行！
		// 這是一個魔法：我們不需要把 Driver 傳進 Evaluator，直接借用環境裡的 efun
		callOtherFn, ok := env.Get("call_other")
		if !ok {
			return newError("系統錯誤：找不到 call_other 內建函式")
		}

		builtin, ok := callOtherFn.(*object.Builtin)
		if !ok {
			return newError("系統錯誤：call_other 不是內建函式")
		}

		// 3. 處理傳入的參數
		args := evalExpressions(node.Arguments, env)
		if len(args) == 1 && isError(args[0]) {
			return args[0]
		}

		// 4. 組裝給 call_other 的最終參數：[目標物件, 函式名稱字串, 參數1, 參數2...]
		finalArgs := []object.Object{targetObj, &object.String{Value: node.Method.Value}}
		finalArgs = append(finalArgs, args...)

		// 5. 執行！
		return builtin.Fn(finalArgs...)
	case *ast.ClosureLiteral:
		elements := evalExpressions(node.Elements, env)
		if len(elements) == 1 && isError(elements[0]) { return elements[0] }
		if len(elements) == 0 { return newError("閉包不能為空") }

		closure := &object.Closure{}

		// 判斷第一項參數是什麼型別
		if str, ok := elements[0].(*object.String); ok {
			// 語法: (: "func_name", arg1, arg2 :)
			closure.Target = nil // 延遲綁定為當前物件
			closure.FuncName = str.Value
			closure.BoundArgs = elements[1:]
		} else if target, ok := elements[0].(*object.LPCObject); ok {
			// 語法: (: obj, "func_name", arg1, arg2 :)
			if len(elements) < 2 { return newError("跨物件閉包必須提供函式名稱") }
			str, ok := elements[1].(*object.String)
			if !ok { return newError("跨物件閉包的第二個參數必須是字串 (函式名稱)") }
			
			closure.Target = target
			closure.FuncName = str.Value
			closure.BoundArgs = elements[2:]
		} else {
			return newError("不合法的閉包格式，第一個參數必須是字串或物件")
		}
		return closure
	case *ast.ForEachStatement:
		collection := Eval(node.Collection, env)
		if isError(collection) { return collection }

		switch coll := collection.(type) {
		case *object.Array:
			for _, element := range coll.Elements {
				loopEnv := object.NewEnclosedEnvironment(env)
				loopEnv.Set(node.Value.Value, element)
				// 如果陣列也硬傳了兩個變數，Key 就當作 Index (整數)
				if node.Key != nil {
					// TODO: 這裡其實應該傳入真實的 index，我們為了簡化可以略過或支援
					loopEnv.Set(node.Key.Value, &object.Nil{}) 
				}

				res := Eval(node.Body, loopEnv)
				
				if res != nil {
					if res.TokenType() == object.BREAK_VALUE_OBJ { break }
					if res.TokenType() == object.CONTINUE_VALUE_OBJ { continue }
					if res.TokenType() == object.ReturnValueType || res.TokenType() == object.ErrorType {
						return res
					}
				}
			}
		case *object.Mapping:
			for _, pair := range coll.Pairs {
				loopEnv := object.NewEnclosedEnvironment(env)
				loopEnv.Set(node.Value.Value, pair.Value)
				if node.Key != nil {
					loopEnv.Set(node.Key.Value, pair.Key)
				}

				res := Eval(node.Body, loopEnv)
				
				if res != nil {
					if res.TokenType() == object.BREAK_VALUE_OBJ { break }
					if res.TokenType() == object.CONTINUE_VALUE_OBJ { continue }
					if res.TokenType() == object.ReturnValueType || res.TokenType() == object.ErrorType {
						return res
					}
				}
			}
		default:
			return newError("foreach 只能用於 array 或 mapping")
		}
		return nil
	}

	return nil
}

func evalProgram(program *ast.Program, env object.Environment) object.Object {
	var result object.Object

	for _, stmt := range program.Statements {
		result = Eval(stmt, env)

		switch result := result.(type) {
		case *object.ReturnValue:
			return result.Value
		case *object.Error:
			return result
		}
	}

	return result
}

func nativeBoolToBooleanObject(input bool) *object.Boolean {
	if input {
		return TrueValue
	}
	return FalseValue
}

func evalPrefixExpression(operator string, right object.Object) object.Object {
	switch operator {
	case "!":
		return evalBangOperatorExpression(right)
	case "-":
		return evalMinusPrefixOperatorExpression(right)
	default:
		return newError("unknown operator: %s%s", operator, right.TokenType())
	}
}

func evalBangOperatorExpression(right object.Object) object.Object {
	if right == NilValue || right == FalseValue {
		return TrueValue
	}
	return FalseValue
}

func evalMinusPrefixOperatorExpression(right object.Object) object.Object {
	switch right := right.(type) {
	case *object.Integer:
		return &object.Integer{Value: -right.Value}
	case *object.Float:
		return &object.Float{Value: -right.Value}
	default:
		return newError("unknown operator: -%s", right.TokenType())
	}
}

func evalInfixExpression(operator string, left, right object.Object) object.Object {
	switch {
	case left.TokenType() == object.IntegerType && right.TokenType() == object.IntegerType:
		return evalIntegerInfixExpression(operator, left, right)
	case left.TokenType() == object.FloatType || right.TokenType() == object.FloatType:
		return evalFloatInfixExpression(operator, left, right)

	// 只要運算子是 '+'，且其中一邊是字串，就強制轉型並串接
	case operator == "+" && (left.TokenType() == object.StringType || right.TokenType() == object.StringType):
		return evalStringConcatExpression(left, right)

	case left.TokenType() == object.StringType && right.TokenType() == object.StringType:
		return evalStringInfixExpression(operator, left, right)
	case operator == "==":
		return nativeBoolToBooleanObject(left == right)
	case operator == "!=":
		return nativeBoolToBooleanObject(left != right)
	case left.TokenType() != right.TokenType():
		return newError("type mismatch: %s %s %s", left.TokenType(), operator, right.TokenType())
	default:
		return newError("unknown operator: %s %s %s", left.TokenType(), operator, right.TokenType())
	}
}

func evalIntegerInfixExpression(operator string, left, right object.Object) object.Object {
	leftVal := left.(*object.Integer).Value
	rightVal := right.(*object.Integer).Value

	switch operator {
	case "+":
		return &object.Integer{Value: leftVal + rightVal}
	case "-":
		return &object.Integer{Value: leftVal - rightVal}
	case "*":
		return &object.Integer{Value: leftVal * rightVal}
	case "/":
		return &object.Integer{Value: leftVal / rightVal}
	case "%":
		if rightVal == 0 {
			return newError("modulo by zero")
		}
		return &object.Integer{Value: leftVal % rightVal}
	case "<":
		return nativeBoolToBooleanObject(leftVal < rightVal)
	case ">":
		return nativeBoolToBooleanObject(leftVal > rightVal)
	case "<=":
		return nativeBoolToBooleanObject(leftVal <= rightVal)
	case ">=":
		return nativeBoolToBooleanObject(leftVal >= rightVal)
	case "==":
		return nativeBoolToBooleanObject(leftVal == rightVal)
	case "!=":
		return nativeBoolToBooleanObject(leftVal != rightVal)
	default:
		return newError("unknown operator: %s %s %s", left.TokenType(), operator, right.TokenType())
	}
}

func evalFloatInfixExpression(operator string, left, right object.Object) object.Object {
	var leftVal, rightVal float64

	switch left := left.(type) {
	case *object.Integer:
		leftVal = float64(left.Value)
	case *object.Float:
		leftVal = left.Value
	default:
		return newError("unknown operator: %s %s %s", left.TokenType(), operator, right.TokenType())
	}

	switch right := right.(type) {
	case *object.Integer:
		rightVal = float64(right.Value)
	case *object.Float:
		rightVal = right.Value
	default:
		return newError("unknown operator: %s %s %s", left.TokenType(), operator, right.TokenType())
	}

	switch operator {
	case "+":
		return &object.Float{Value: leftVal + rightVal}
	case "-":
		return &object.Float{Value: leftVal - rightVal}
	case "*":
		return &object.Float{Value: leftVal * rightVal}
	case "/":
		return &object.Float{Value: leftVal / rightVal}
	case "<":
		return nativeBoolToBooleanObject(leftVal < rightVal)
	case ">":
		return nativeBoolToBooleanObject(leftVal > rightVal)
	case "<=":
		return nativeBoolToBooleanObject(leftVal <= rightVal)
	case ">=":
		return nativeBoolToBooleanObject(leftVal >= rightVal)
	case "==":
		return nativeBoolToBooleanObject(leftVal == rightVal)
	case "!=":
		return nativeBoolToBooleanObject(leftVal != rightVal)
	default:
		return newError("unknown operator: %s %s %s", left.TokenType(), operator, right.TokenType())
	}
}

func evalStringInfixExpression(operator string, left, right object.Object) object.Object {
	leftVal := left.(*object.String).Value
	rightVal := right.(*object.String).Value

	switch operator {
	case "+":
		return &object.String{Value: leftVal + rightVal}
	case "==":
		return nativeBoolToBooleanObject(leftVal == rightVal)
	case "!=":
		return nativeBoolToBooleanObject(leftVal != rightVal)
	default:
		return newError("unknown operator: %s %s %s", left.TokenType(), operator, right.TokenType())
	}
}

func evalBlockStatement(block *ast.BlockStatement, env object.Environment) object.Object {
	var result object.Object

	for _, stmt := range block.Statements {
		result = Eval(stmt, env)
		if result == nil {
			continue
		}

		rt := result.TokenType()
		// 遇到 Return、Error、Break、Continue 都要立刻把訊號往上傳
		if rt == object.ReturnValueType || rt == object.ErrorType || 
		   rt == object.BREAK_VALUE_OBJ || rt == object.CONTINUE_VALUE_OBJ {
			return result
		}
	}

	return result
}

func evalIfExpression(ie *ast.IfExpression, env object.Environment) object.Object {
	condition := Eval(ie.Condition, env)
	if isError(condition) {
		return condition
	}

	if isTruthy(condition) {
		return Eval(ie.Consequence, env)
	} else if ie.Alternative != nil {
		return Eval(ie.Alternative, env)
	}
	return NilValue
}

func isTruthy(obj object.Object) bool {
	return obj != NilValue && obj != FalseValue
}

func newError(format string, a ...interface{}) *object.Error {
	return &object.Error{Message: fmt.Sprintf(format, a...)}
	msg := fmt.Sprintf(format, a...)
	// TODO: 可以這裡記錄呼叫位置（進階）
	return &object.Error{Message: msg}
}

func isError(obj object.Object) bool {
	return obj != nil && obj.TokenType() == object.ErrorType
}

func evalIdent(node *ast.Ident, env object.Environment) object.Object {
	name := node.Value

	// 支援 ::func() 繼承呼叫
	if strings.HasPrefix(name, "::") {
		funcName := strings.TrimPrefix(name, "::")
		if thisObj, ok := env.Get("this_object"); ok {
			if lpcObj, ok := thisObj.(*object.LPCObject); ok {
				// 從繼承鏈由上往下找
				for _, parent := range lpcObj.Inherits {
					if fn, exists := parent.Vars.Get(funcName); exists {
						return fn
					}
				}
			}
		}
	}

	if val, ok := env.Get(name); ok {
		return val
	}

	if builtin, ok := builtins[name]; ok {
		return builtin
	}

	return newError("identifier not found: %s", name)
}

func evalExpressions(exprs []ast.Expression, env object.Environment) []object.Object {
	result := make([]object.Object, 0, len(exprs))

	for _, expr := range exprs {
		evaluated := Eval(expr, env)
		if isError(evaluated) {
			return []object.Object{evaluated}
		}
		result = append(result, evaluated)
	}

	return result
}

func extendFunctionEnv(fn *object.Function, args []object.Object) object.Environment {
	env := object.NewEnclosedEnvironment(fn.Env)

	for i, param := range fn.Parameters {
		env.Set(param.Value, args[i])
	}

	return env
}

func applyFunction(fn object.Object, args []object.Object) object.Object {
	switch fn := fn.(type) {
	case *object.Function:
		extendedEnv := extendFunctionEnv(fn, args)
		evaluated := Eval(fn.Body, extendedEnv)
		return unwrapReturnValue(evaluated)
	case *object.Builtin:
		return fn.Fn(args...)
	default:
		return newError("not a function: %s", fn.TokenType())
	}
}

func unwrapReturnValue(obj object.Object) object.Object {
	if returnValue, ok := obj.(*object.ReturnValue); ok {
		return returnValue.Value
	}
	return obj
}

func evalIndexExpression(left, index object.Object) object.Object {
	switch {
	case left.TokenType() == object.ArrayType && index.TokenType() == object.IntegerType:
		return evalArrayIndexExpression(left, index)
	case left.TokenType() == object.HashType:
		return evalHashIndexExpression(left, index)
	case left.TokenType() == object.MAPPING_OBJ:
		return evalMappingIndexExpression(left, index)
	default:
		return newError("index operator not supported: %s", left.TokenType())
	}
}

func evalArrayIndexExpression(array, index object.Object) object.Object {
	arrObj := array.(*object.Array)
	idx := index.(*object.Integer).Value
	max := int64(len(arrObj.Elements) - 1)

	if idx < 0 || idx > max {
		return NilValue
	}

	return arrObj.Elements[idx]
}

func evalHashLiteral(node *ast.HashLiteral, env object.Environment) object.Object {
	pairs := make(map[object.HashKey]object.HashPair, len(node.Pairs))

	for keyNode, valueNode := range node.Pairs {
		key := Eval(keyNode, env)
		if isError(key) {
			return key
		}

		hashKey, ok := key.(object.Hashable)
		if !ok {
			return newError("unusable as hash key: %s", key.TokenType())
		}

		value := Eval(valueNode, env)
		if isError(value) {
			return value
		}

		hashed := hashKey.HashKey()
		pairs[hashed] = object.HashPair{
			Key:   key,
			Value: value,
		}
	}

	return &object.Hash{Pairs: pairs}
}

func evalHashIndexExpression(left, index object.Object) object.Object {
	key, ok := index.(object.Hashable)
	if !ok {
		return newError("unusable as hash key: %s", index.TokenType())
	}

	hashObj := left.(*object.Hash)
	if pair, exists := hashObj.Pairs[key.HashKey()]; exists {
		return pair.Value
	}
	return NilValue
}

/////////////////////////////////////////////////////
// mudscript

func evalTypedVarDecl(node *ast.TypedVarDecl, env object.Environment) object.Object {
	var val object.Object

	// 1. 如果有等號賦值 (例如: int x = 10;)
	if node.Value != nil {
		val = Eval(node.Value, env)
		if isError(val) {
			return val
		}

		// 執行型別檢查！
		expectedType := node.Token.Literal
		if !checkTypeMatch(expectedType, val) {
			return newError("type mismatch: cannot assign %s to %s variable '%s'",
				val.TokenType(), expectedType, node.Name.Value)
		}
	} else {
		// 2. 如果沒有賦值，給予預設值
		val = getDefaultLPCValue(node.Token.Literal)
	}

	// 3. 將變數存入環境中
	env.Set(node.Name.Value, val)
	return val
}

// 輔助函式：判斷指派的值是否符合宣告的型別
func checkTypeMatch(lpcType string, obj object.Object) bool {
	switch lpcType {
	case "int":
		return obj.TokenType() == object.IntegerType
	case "string":
		return obj.TokenType() == object.StringType
	case "float":
		return obj.TokenType() == object.FloatType
	case "mixed":
		return true
	case "object":
		return obj.TokenType() == object.LPC_OBJECT_OBJ || 
			   obj.TokenType() == object.NilType || 
			   obj.TokenType() == object.IntegerType
	case "mapping":
		return obj.TokenType() == object.MAPPING_OBJ || 
			   obj.TokenType() == object.NilType || 
			   obj.TokenType() == object.IntegerType
	case "array":
		return obj.TokenType() == object.ArrayType || 
			   obj.TokenType() == object.NilType || 
			   obj.TokenType() == object.IntegerType
	default:
		return false
	}
}

// 輔助函式：取得 LPC 的預設值
func getDefaultLPCValue(lpcType string) object.Object {
	switch lpcType {
	case "int":
		return &object.Integer{Value: 0}
	case "string":
		return &object.String{Value: ""}
	case "float":
		return &object.Float{Value: 0.0}
	
	case "mapping":
		// [修正] 使用全新的 HashKey 與 HashPair 結構來初始化空 Mapping
		return &object.Mapping{Pairs: make(map[object.HashKey]object.HashPair)}
		
	case "array":
		return &object.Array{Elements: []object.Object{}}
		
	default:
		return NilValue
	}
}

func evalFunctionDef(node *ast.FunctionDef, env object.Environment) object.Object {
	// 轉換 TypedParam → Ident 以相容原本的 Function
	var params []*ast.Ident
	for _, p := range node.Params {
		params = append(params, p.Name)
	}

	fn := &object.Function{
		Parameters: params,
		Env:		env,
		Body:	   node.Body,
	}

	env.Set(node.Name.Value, fn)
	return fn
}

// ==========================================
// 重新賦值與自增減
// ==========================================

func evalAssignExpression(node *ast.AssignExpression, env object.Environment) object.Object {
	val := Eval(node.Value, env)
	if isError(val) { return val }

	// ==========================================
	// 1. 處理陣列或 Mapping 的索引賦值 (例如 arr[0] = 5 或 m["hp"] += 10)
	// ==========================================
	if indexExpr, ok := node.Left.(*ast.IndexExpression); ok {
		leftObj := Eval(indexExpr.Left, env) // 取得 Array 或 Mapping 本身
		if isError(leftObj) { return leftObj }
		
		indexObj := Eval(indexExpr.Index, env) // 取得索引值 (例如 0 或 "hp")
		if isError(indexObj) { return indexObj }

		// 如果是單純的 =
		if node.Operator == "=" {
			return assignToIndex(leftObj, indexObj, val)
		}

		// 如果是 +=, -=, *=, /=
		currentVal := evalIndexExpression(leftObj, indexObj)
		if isError(currentVal) { return currentVal }
		
		op := node.Operator[:len(node.Operator)-1] // 把 "+=" 切成 "+"
		newVal := evalInfixExpression(op, currentVal, val)
		if isError(newVal) { return newVal }
		
		return assignToIndex(leftObj, indexObj, newVal)
	}

	// ==========================================
	// 2. 處理一般變數賦值 (例如 x = 5)
	// ==========================================
	leftIdent, ok := node.Left.(*ast.Ident)
	if !ok {
		return newError("賦值的左側必須是變數或索引 (例如 x 或 arr[0])")
	}

	if node.Operator == "=" {
		if !env.Assign(leftIdent.Value, val) {
			return newError("變數未宣告或不存在: %s", leftIdent.Value)
		}
		return val
	}

	currentVal, exists := env.Get(leftIdent.Value)
	if !exists {
		return newError("變數未宣告或不存在: %s", leftIdent.Value)
	}

	op := node.Operator[:len(node.Operator)-1]
	newVal := evalInfixExpression(op, currentVal, val)
	if isError(newVal) { return newVal }

	env.Assign(leftIdent.Value, newVal)
	return newVal
}

// 輔助函式：執行對底層資料結構的修改
func assignToIndex(left, index, val object.Object) object.Object {
	switch leftObj := left.(type) {
	
	// 處理陣列的修改
	case *object.Array:
		idx, ok := index.(*object.Integer)
		if !ok { return newError("陣列索引必須是整數") }
		i := idx.Value
		if i < 0 || i >= int64(len(leftObj.Elements)) {
			return newError("陣列索引超出範圍: %d", i)
		}
		leftObj.Elements[i] = val
		return val
		
	// 處理 Mapping 的修改
	case *object.Mapping:
		hashKey, ok := index.(object.Hashable)
		if !ok { return newError("無法作為 mapping 的 key: %s", index.TokenType()) }
		
		hashed := hashKey.HashKey()
		leftObj.Pairs[hashed] = object.HashPair{Key: index, Value: val}
		return val

	default:
		return newError("不支援對 %s 進行索引賦值", left.TokenType())
	}
}

func evalPostfixExpression(node *ast.PostfixExpression, env object.Environment) object.Object {
	leftIdent, ok := node.Left.(*ast.Ident)
	if !ok { return newError("目前僅支援對變數使用自增減") }
	
	currentVal, exists := env.Get(leftIdent.Value)
	if !exists { return newError("變數不存在: %s", leftIdent.Value) }
	
	if currentVal.TokenType() != object.IntegerType {
		return newError("自增減運算子只能用於整數")
	}

	oldInt := currentVal.(*object.Integer).Value
	var newInt int64
	if node.Operator == "++" {
		newInt = oldInt + 1
	} else {
		newInt = oldInt - 1
	}

	env.Assign(leftIdent.Value, &object.Integer{Value: newInt})
	// 後綴運算子 (x++) 會回傳「原本」的值
	return &object.Integer{Value: oldInt}
}

// ==========================================
// 迴圈與分支
// ==========================================

func evalForStatement(node *ast.ForStatement, env object.Environment) object.Object {
	loopEnv := object.NewEnclosedEnvironment(env) // 建立迴圈專屬作用域

	if node.Init != nil {
		Eval(node.Init, loopEnv)
	}

	var result object.Object
	for {
		if node.Condition != nil {
			cond := Eval(node.Condition, loopEnv)
			if isError(cond) { return cond }
			if !isTruthy(cond) { break }
		}

		result = Eval(node.Body, loopEnv)
		if isError(result) { return result }

		if result != nil {
			rt := result.TokenType()
			if rt == object.ReturnValueType { return result }
			if rt == object.BREAK_VALUE_OBJ { break }
			// 如果是 CONTINUE_VALUE_OBJ，就直接往下執行 Post，不要中斷迴圈
		}

		if node.Post != nil {
			Eval(node.Post, loopEnv)
		}
	}
	return NilValue
}

func evalWhileStatement(node *ast.WhileStatement, env object.Environment) object.Object {
	var result object.Object
	for {
		cond := Eval(node.Condition, env)
		if isError(cond) { return cond }
		if !isTruthy(cond) { break }

		result = Eval(node.Body, env)
		if isError(result) { return result }

		if result != nil {
			rt := result.TokenType()
			if rt == object.ReturnValueType { return result }
			if rt == object.BREAK_VALUE_OBJ { break }
		}
	}
	return NilValue
}

func evalDoWhileStatement(node *ast.DoWhileStatement, env object.Environment) object.Object {
	var result object.Object
	for {
		result = Eval(node.Body, env)
		if isError(result) { return result }

		if result != nil {
			rt := result.TokenType()
			if rt == object.ReturnValueType { return result }
			if rt == object.BREAK_VALUE_OBJ { break }
		}

		cond := Eval(node.Condition, env)
		if isError(cond) { return cond }
		if !isTruthy(cond) { break }
	}
	return NilValue
}

func evalSwitchStatement(node *ast.SwitchStatement, env object.Environment) object.Object {
	val := Eval(node.Value, env)
	if isError(val) { return val }

	isFallthrough := false
	var result object.Object

	for _, caseStmt := range node.Cases {
		match := false

		if caseStmt.Value == nil {
			match = true // 這是 default
		} else if !isFallthrough {
			caseVal := Eval(caseStmt.Value, env)
			if isError(caseVal) { return caseVal }
			
			// 使用現有的 Infix 比較邏輯
			cmp := evalInfixExpression("==", val, caseVal)
			if cmp == TrueValue { match = true }
		}

		if match || isFallthrough {
			isFallthrough = true // 除非遇到 break，否則 C/LPC 預設會 isFallthrough
			
			for _, stmt := range caseStmt.Body {
				result = Eval(stmt, env)
				if result != nil {
					rt := result.TokenType()
					if rt == object.ReturnValueType || rt == object.ErrorType { return result }
					if rt == object.BREAK_VALUE_OBJ { return NilValue } // break 跳出 switch
					if rt == object.CONTINUE_VALUE_OBJ { return result } // continue 給外層迴圈處理
				}
			}
		}
	}
	return NilValue
}

func evalMappingLiteral(node *ast.MappingLiteral, env object.Environment) object.Object {
	pairs := make(map[object.HashKey]object.HashPair)

	for keyNode, valueNode := range node.Pairs {
		key := Eval(keyNode, env)
		if isError(key) { return key }

		// [修正] 檢查這個物件是否可以作為 Hash Key
		hashKey, ok := key.(object.Hashable)
		if !ok {
			return newError("無法作為 mapping 的 key: %s", key.TokenType())
		}

		value := Eval(valueNode, env)
		if isError(value) { return value }

		hashed := hashKey.HashKey()
		pairs[hashed] = object.HashPair{Key: key, Value: value}
	}

	return &object.Mapping{Pairs: pairs}
}
func evalMappingIndexExpression(left, index object.Object) object.Object {
	mapping := left.(*object.Mapping)

	hashKey, ok := index.(object.Hashable)
	if !ok {
		return newError("無法作為 mapping 的 key: %s", index.TokenType())
	}

	if pair, exists := mapping.Pairs[hashKey.HashKey()]; exists {
		return pair.Value
	}
	
	// 找不到時回傳 0 (相容 LPC)
	return &object.Integer{Value: 0} 
}

func evalCallOtherExpression(node *ast.CallOtherExpression, env object.Environment) object.Object {
	// 1. 求出目標物件
	target := Eval(node.Object, env)
	if isError(target) { return target }

	targetObj, ok := target.(*object.LPCObject)
	if !ok {
		return newError("-> 運算子只能用於物件 (LPCObject), 得到的是 %s", target.TokenType())
	}

	// 2. 求出傳入的參數
	args := evalExpressions(node.Arguments, env)
	if len(args) == 1 && isError(args[0]) {
		return args[0]
	}

	// 3. 從目標物件的環境中尋找該函式
	fnObj, exists := targetObj.Vars.Get(node.Method.Value)
	if !exists {
		// 在 LPC 中，對物件呼叫不存在的函式不會崩潰，而是靜默回傳 0 (Nil)
		return &object.Integer{Value: 0}
	}

	fn, ok := fnObj.(*object.Function)
	if !ok {
		return newError("目標物件中的 '%s' 不是一個函式", node.Method.Value)
	}

	// 4. [關鍵] 建立新的執行環境！外層必須是目標物件的 Vars！
	extendedEnv := object.NewEnclosedEnvironment(targetObj.Vars)
	
	// 將參數綁定到目標函式上
	for i, param := range fn.Parameters {
		if i < len(args) {
			extendedEnv.Set(param.Value, args[i])
		} else {
			extendedEnv.Set(param.Value, &object.Integer{Value: 0})
		}
	}

	// 5. 執行目標函式，並解開 Return 包裝
	evaluated := Eval(fn.Body, extendedEnv)
	return unwrapReturnValue(evaluated)
}

// 輔助函式：自動將非字串物件轉為字串並串接
func evalStringConcatExpression(left, right object.Object) object.Object {
	leftStr := left.Inspect()
	if l, ok := left.(*object.String); ok {
		leftStr = l.Value
	}

	rightStr := right.Inspect()
	if r, ok := right.(*object.String); ok {
		rightStr = r.Value
	}

	return &object.String{Value: leftStr + rightStr}
}

func evalSscanf(node *ast.CallExpression, env object.Environment) object.Object {
	if len(node.Arguments) < 3 {
		return newError("sscanf 至少需要 3 個參數: sscanf(字串, 格式, 變數...)")
	}

	// 1. 正常評估前兩個參數 (輸入字串 與 格式)
	inputObj := Eval(node.Arguments[0], env)
	formatObj := Eval(node.Arguments[1], env)

	inputStr, ok1 := inputObj.(*object.String)
	formatStr, ok2 := formatObj.(*object.String)
	if !ok1 || !ok2 {
		return newError("sscanf 的前兩個參數必須是字串")
	}

	// 2. 將 LPC 的格式字串 (例如 "give %d %s to %s") 轉換為正規表達式
	// 使用 QuoteMeta 防止格式中的特殊符號干擾
	regexStr := regexp.QuoteMeta(formatStr.Value)
	
	regexStr = strings.ReplaceAll(regexStr, "%d", "(-?\\d+)")
	regexStr = strings.ReplaceAll(regexStr, "%s", "(.*?)")
	
	// LPC 特性：如果最後一個是 %s，它會把剩下的字串全吃掉 (貪婪模式)
	if strings.HasSuffix(formatStr.Value, "%s") {
		regexStr = strings.TrimSuffix(regexStr, "(.*?)") + "(.*)"
	}
	
	// 頭尾完全匹配
	re, err := regexp.Compile("^" + regexStr + "$")
	if err != nil {
		return newError("sscanf 格式編譯失敗: %v", err)
	}

	// 3. 進行字串配對
	matches := re.FindStringSubmatch(inputStr.Value)
	if matches == nil {
		return &object.Integer{Value: 0} // 配對失敗回傳 0
	}

	// matches[0] 是完整字串，matches[1:] 才是括號捕捉到的變數
	capturedGroups := matches[1:]
	matchedCount := 0

	// 4. 將捕捉到的值「強制覆寫」回傳入的變數中 (傳址的魔法)
	// 從 node.Arguments 的第 2 個開始，就是接收變數 (例如 amt, item)
	for i := 2; i < len(node.Arguments); i++ {
		if i-2 >= len(capturedGroups) {
			break // 捕捉群組用完了
		}

		ident, ok := node.Arguments[i].(*ast.Ident)
		if !ok {
			return newError("sscanf 的接收變數必須是識別字 (Identifier)")
		}

		valueStr := capturedGroups[i-2]

		// 判斷當初這個位置是 %d 還是 %s
		// (這裡用簡單的位置推算，真實 LPC 引擎會有更嚴謹的對應)
		if valInt, err := strconv.ParseInt(valueStr, 10, 64); err == nil {
			// 存入整數
			env.Assign(ident.Value, &object.Integer{Value: valInt})
		} else {
			// 存入字串
			env.Assign(ident.Value, &object.String{Value: valueStr})
		}
		
		matchedCount++
	}

	// 回傳成功匹配並賦值的變數數量
	return &object.Integer{Value: int64(matchedCount)}
}

func evalCatch(node *ast.CallExpression, env object.Environment) object.Object {
	if len(node.Arguments) != 1 {
		return newError("catch() 只需要 1 個表達式參數")
	}

	// 1. 嘗試評估括號內的表達式
	result := Eval(node.Arguments[0], env)

	// 2. 檢查結果是否為 Error 物件
	if err, ok := result.(*object.Error); ok {
		// 捕捉成功！將錯誤訊息轉化為普通的字串回傳，阻止它繼續往上崩潰
		return &object.String{Value: err.Message}
	}

	// 3. 如果沒有發生錯誤，LPC 的 catch 慣例是回傳 0
	return &object.Integer{Value: 0}
}
