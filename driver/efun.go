// driver/efun.go
package driver

import (
	"encoding/json"
	"mudscript/object"
)

// ==========================================
// 輔助工具函式 (Internal Helpers)
// ==========================================

func (d *Driver) IsLPCTrue(o object.Object) bool {
	if o == nil || o.TokenType() == object.NilType || o.TokenType() == object.ErrorType {
		return false
	}
	if i, ok := o.(*object.Integer); ok && i.Value == 0 {
		return false
	}
	if b, ok := o.(*object.Boolean); ok && !b.Value {
		return false
	}
	if r, ok := o.(*object.ReturnValue); ok {
		return d.IsLPCTrue(r.Value)
	}
	return true
}

func isLPCTrue(o object.Object) bool {
	if o == nil || o.TokenType() == object.NilType || o.TokenType() == object.ErrorType {
		return false
	}
	if i, ok := o.(*object.Integer); ok && i.Value == 0 {
		return false
	}
	if b, ok := o.(*object.Boolean); ok && !b.Value {
		return false
	}
	if r, ok := o.(*object.ReturnValue); ok {
		return isLPCTrue(r.Value)
	}
	return true
}

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

func (d *Driver) SetupEfuns(obj *object.LPCObject) {
	obj.Efuns = object.NewEnvironment()

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
	d.registerSystemAndFiles(obj)
	d.registerMonitorEfuns(obj)
	d.registerPersistenceEfuns(obj)
	d.registerInheritanceEfuns(obj)
	d.registerMemoryEfuns(obj)
	d.registerFunctionExistsEfun(obj)
	d.registerLifecycleEfuns(obj)
	d.registerReloadObjectEfun(obj)
	d.registerInteractiveEfuns(obj)
	d.registerP2PEfuns(obj)
	d.registerBufferEfuns(obj)
	d.registerBitEfuns(obj)
	d.registerWizardEfuns(obj)
	d.registerNetworkEfuns(obj)
	d.registerParseEfuns(obj)
	d.registerDebugEfuns(obj)
	d.registerPerformanceEfuns(obj)

	for k, v := range obj.Vars.GetAll() {
		if _, ok := v.(*object.Builtin); ok {
			obj.Efuns.Set(k, v)
		}
	}

	d.RegisterSimulEfuns(obj)
	d.registerWebIDEEfuns(obj)
}

func (d *Driver) RegisterSimulEfuns(obj *object.LPCObject) {
	if d.SimulEfunObj == nil || obj == d.SimulEfunObj {
		return
	}
	for name, val := range d.SimulEfunObj.Vars.GetAll() {
		if _, ok := val.(*object.Function); ok {
			funcName := name
			obj.Vars.Set(funcName, &object.Builtin{
				Fn: func(args ...object.Object) object.Object {
					return d.CallFunction(d.SimulEfunObj, funcName, args)
				},
			})
		}
	}
}

func (d *Driver) registerWebIDEEfuns(obj *object.LPCObject) {
	isWeb := &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			if conn := d.GetConnectionFromObject(target); conn != nil {
				if conn.OutputCallback != nil { return &object.Integer{Value: 1} }
			}
			return &object.Integer{Value: 0}
		},
	}
	obj.Vars.Set("MUD_IS_WEB", isWeb)
	obj.Efuns.Set("MUD_IS_WEB", isWeb)

	webEdit := &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			path, ok := args[0].(*object.String)
			if !ok { return &object.Nil{} }
			p := d.GetCurrentPlayer()
			if p == nil && obj.IsInteractive { p = d.GetConnectionFromObject(obj) }
			if p == nil || !p.IsActive { return &object.Nil{} }
			content, _ := d.ReadFile(path.Value)
			payload := map[string]string{"path": path.Value, "content": string(content)}
			jsonData, _ := json.Marshal(payload)
			p.Send("__EDIT__" + string(jsonData))
			return &object.Nil{}
		},
	}
	obj.Vars.Set("MUD_REQUEST_EDIT", webEdit)
	obj.Efuns.Set("MUD_REQUEST_EDIT", webEdit)
}
