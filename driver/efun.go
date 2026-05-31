// driver/efun.go
package driver

import (
	"mudscript/object"
)

// ==========================================
// 輔助工具函式 (Internal Helpers)
// ==========================================

// isLPCTrue 判斷 LPC 中的真假值 (符合現代語言習慣：0, "", [], ([]) 皆為假)
func isLPCTrue(o object.Object) bool {
	if o == nil || o.TokenType() == object.NilType {
		return false
	}
	if i, ok := o.(*object.Integer); ok && i.Value == 0 {
		return false
	}
	if s, ok := o.(*object.String); ok && s.Value == "" {
		return false
	}
	if a, ok := o.(*object.Array); ok && len(a.Elements) == 0 {
		return false
	}
	if m, ok := o.(*object.Mapping); ok && len(m.Pairs) == 0 {
		return false
	}
	if b, ok := o.(*object.Boolean); ok && !b.Value {
		return false
	}
	if _, ok := o.(*object.Error); ok {
		return false
	}
	return true
}

// isEqual 比較兩個 LPC 物件是否相等 (給 member_array 等使用)
func isEqual(a, b object.Object) bool {
	if a.TokenType() != b.TokenType() {
		return false
	}
	if i1, ok := a.(*object.Integer); ok {
		return i1.Value == b.(*object.Integer).Value
	}
	if s1, ok := a.(*object.String); ok {
		return s1.Value == b.(*object.String).Value
	}
	if o1, ok := a.(*object.LPCObject); ok {
		return o1 == b.(*object.LPCObject)
	}
	return a.Inspect() == b.Inspect()
}

// getTarget 取得目標物件，若未提供則預設為呼叫者 this_object
func getTarget(args []object.Object, defaultObj *object.LPCObject) *object.LPCObject {
	if len(args) > 0 {
		if o, ok := args[0].(*object.LPCObject); ok {
			return o
		}
	}
	return defaultObj
}

// ==========================================
// efun 註冊進入點
// ==========================================

// SetupEfuns 為每個載入的 LPC 物件注入專屬的內建函式
func (d *Driver) SetupEfuns(obj *object.LPCObject) {
	d.registerTypePredicates(obj)
	d.registerTypeCasting(obj)
	d.registerMathEfuns(obj)
	d.registerCoreEfuns(obj)
    d.registerPrivilegeEfuns(obj)
    d.registerSecurityEfuns(obj)
    d.registerFindLivingEfun(obj)
    d.registerSetQueryEfuns(obj)
    d.registerErrorEfun(obj)
	d.registerCommEfuns(obj)
	d.registerEnvironmentEfuns(obj)
	d.registerTimeAndScheduling(obj)
    d.registerResetEfuns(obj)
	d.registerDataStructures(obj)
	d.registerFunctionalEfuns(obj)
    d.registerUniqueMappingEfun(obj)
    d.registerBindingEfuns(obj)
	d.registerStringEfuns(obj)
	d.registerAdvancedStringEfuns2(obj)
	d.registerSystemAndFiles(obj)
	d.registerPersistenceEfuns(obj)
    d.registerInheritanceEfuns(obj)
    d.registerMemoryEfuns(obj)
	d.registerFunctionExistsEfun(obj)
	d.registerLifecycleEfuns(obj)
	d.registerInteractiveEfuns(obj)
	d.registerP2PEfuns(obj)

	// 🚀 新增：註冊 SimulEfuns
	d.RegisterSimulEfuns(obj)
}

// RegisterSimulEfuns 掃描 SimulEfun 物件並將其函式注入目標物件
func (d *Driver) RegisterSimulEfuns(obj *object.LPCObject) {
	if d.SimulEfunObj == nil || obj == d.SimulEfunObj {
		return
	}

	// 遍歷 SimulEfun 物件的所有變數/函式
	for name, val := range d.SimulEfunObj.Vars.GetAll() {
		// 只注入函式 (Function)，不注入一般變數
		if _, ok := val.(*object.Function); ok {
			// 使用閉包包裝呼叫，確保執行時的 context 正確
			funcName := name // 捕獲變數
			obj.Vars.Set(funcName, &object.Builtin{
				Fn: func(args ...object.Object) object.Object {
					return d.CallFunction(d.SimulEfunObj, funcName, args)
				},
			})
		}
	}
}
