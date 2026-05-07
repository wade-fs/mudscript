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
		"/include/combat.h": `
			// 這是放在共用資料夾的標頭檔
			#define MAX_HP 200
			#define DAMAGE_MODIFIER 15
		`,
		"/obj/weapon.c": `
			// 引入標頭檔
			#include "/include/combat.h"

			// 定義自己的開關
			#define ENABLE_CRIT 1

			int calculate_damage(int base) {
				int total = base + DAMAGE_MODIFIER;
				
				// 條件編譯：只有開啟 ENABLE_CRIT 時，這段程式碼才會被編譯進去
				#if ENABLE_CRIT == 1
					total += 50; 
				#else
					total += 1; // 這行不會被編譯
				#endif

				return total;
			}
			
			int get_max() {
				return MAX_HP;
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
	weapon, err := d.CloneObject("/obj/weapon.c")
	if err != nil {
		panic(err)
	}

	// 測試 1: 驗證巨集展開和條件編譯 (預期: 10 + 15 + 50 = 75)
	res1 := d.CallFunction(weapon, "calculate_damage", []object.Object{&object.Integer{Value: 10}})
	fmt.Printf("計算傷害結果: %s\n", res1.Inspect())

	// 測試 2: 驗證引入檔案的巨集 (預期: 200)
	res2 := d.CallFunction(weapon, "get_max", nil)
	fmt.Printf("MAX_HP 常數結果: %s\n", res2.Inspect())
}
