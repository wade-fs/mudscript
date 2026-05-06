// driver/efun_test.go
package driver

import (
	"testing"
	"time"

	"mudscript/evaluator"
	"mudscript/lexer"
	"mudscript/object"
	"mudscript/parser"
)

func TestCallOutEfun(t *testing.T) {
	lpcScript := `
		int flag = 0;
		void create() {
			call_out("set_flag", 1);
		}
		void set_flag() {
			flag = 1;
		}
	`
	l := lexer.New(lpcScript)
	p := parser.New(l)
	program := p.ParseProgram()
	
	d := New(DriverConfig{HeartBeatTick: 100 * time.Millisecond})
	env := object.NewEnvironment()
	obj := &object.LPCObject{Filename: "/obj/test.c", Vars: env}
	
	d.SetupEfuns(obj)
	evaluator.Eval(program, env)
	
	d.Start()
	defer d.Stop()

	// 觸發 create()
	d.CallFunction(obj, "create", nil)

	// 檢查 flag 初始值
	if flag, _ := env.Get("flag"); flag.(*object.Integer).Value != 0 {
		t.Errorf("Expected flag to be 0, got %d", flag.(*object.Integer).Value)
	}

	// 等待 call_out 觸發 (因為我們設定 tick 是 100ms，延遲 1 秒，所以等 1.2 秒)
	time.Sleep(1200 * time.Millisecond)

	// 檢查 flag 是否被修改
	if flag, _ := env.Get("flag"); flag.(*object.Integer).Value != 1 {
		t.Errorf("Expected flag to be 1 after call_out, got %d", flag.(*object.Integer).Value)
	}
}
