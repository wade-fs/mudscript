package main

import (
	"fmt"
	"os"
	"path/filepath"

	"mudscript/driver"
	"mudscript/object"
)

func main() {
	files := map[string]string{
		"/std/monster.c": `
			int hp;
			string name;
			
			// 父物件的初始化
			void create() {
				hp = 50;
				name = "未命名怪物";
				write("-> [monster] 基礎屬性初始化完畢\n");
			}
			
			void take_damage(int amount) {
				hp -= amount;
				write(name + " 受傷了！剩餘 hp: " + hp + "\n");
			}
		`,
		"/d/goblin.c": `
			inherit "/std/monster.c";
			
			// 子物件覆寫了 create()
			void create() {
				// 呼叫父物件的 create() 幫忙初始化基礎屬性！
				::create(); 
				
				// 然後再覆寫自己特有的屬性
				name = "狂暴哥布林";
				hp = 100;
				write("-> [goblin] 特化屬性設定完畢\n");
			}

			// 甚至可以攔截並加工傷害邏輯
			void take_damage(int amount) {
				write("哥布林尖叫：別打我！\n");
				// 呼叫指定父類別的方法扣血
				monster::take_damage(amount); 
			}
		`,
	}

	tmpDir, _ := os.MkdirTemp("", "mudlib_test")
	defer os.RemoveAll(tmpDir)

	for path, content := range files {
		fullPath := filepath.Join(tmpDir, path)
		os.MkdirAll(filepath.Dir(fullPath), 0755)
		os.WriteFile(fullPath, []byte(content), 0644)
	}

	d := driver.New(driver.DriverConfig{MudLibPath: tmpDir})

	fmt.Println("=== 載入哥布林 (觀察 create 執行順序) ===")
	goblin, _ := d.CloneObject("/d/goblin.c")

	fmt.Println("\n=== 模擬攻擊哥布林 ===")
	d.CallFunction(goblin, "take_damage", []object.Object{&object.Integer{Value: 30}})
}
