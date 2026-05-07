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
		"/std/player.c": `
			int hp = 100;
			string name = "冒險者";
			
			// 遭受攻擊的方法
			void receive_damage(int amount) {
				hp -= amount;
				write(name + " 被砍中了！剩下 HP: " + hp + "\n");
			}
			
			int query_hp() {
				return hp;
			}
		`,
		"/obj/sword.c": `
			void do_attack(object target) {
				write("長劍揮舞！\n");
				// 使用 -> 運算子呼叫目標的函式！
				target->receive_damage(25);
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

	// 載入玩家和劍
	player, _ := d.CloneObject("/std/player.c")
	sword, _ := d.CloneObject("/obj/sword.c")

	fmt.Println("=== 戰鬥開始 ===")
	// 讓劍攻擊玩家
	d.CallFunction(sword, "do_attack", []object.Object{player})
}
