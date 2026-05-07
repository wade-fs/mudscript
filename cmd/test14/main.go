package main

import (
	"fmt"
	"os"
	"path/filepath"

	"mudscript/driver"
)

func main() {
	files := map[string]string{
		"/test.c": `
			// 1. 測試 filter 用的判斷函式 (挑出大於等於指定門檻的數字)
			int is_high_level(int level, int threshold) {
				return level >= threshold; 
			}

			// 2. 測試 map 用的加工函式 (把數字乘上倍率)
			int multiply_level(int level, int multiplier) {
				return level * multiplier;
			}

			void run_test() {
				// --- 測試 keys() 與 values() ---
				mapping stats = ([ "str": 18, "dex": 15, "int": 10 ]);
				mixed k_arr = keys(stats);
				mixed v_arr = values(stats);
				
				write("Keys Array:   " + sprintf("%O", k_arr) + "\n");
				write("Values Array: " + sprintf("%O", v_arr) + "\n\n");

				// --- 測試 filter_array() 與 map_array() ---
				mixed monsters = [ 5, 12, 3, 20, 8 ];
				write("原始怪物等級: " + sprintf("%O", monsters) + "\n");

				// 過濾：找出大於等於 10 級的怪物
				// 這裡使用了額外參數：10 (會被當作 is_high_level 的第二個參數)
				mixed elites = filter_array(monsters, "is_high_level", this_object(), 10);
				write("篩選精英怪物: " + sprintf("%O", elites) + "\n");

				// 映射：將精英怪物的等級全部乘上 3 倍
				mixed bosses = map_array(elites, "multiply_level", this_object(), 3);
				write("強化變為 Boss: " + sprintf("%O", bosses) + "\n");
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
	testObj, err := d.CloneObject("/test.c")
	if err != nil {
		panic(err)
	}

	fmt.Println("=== 陣列與映射表高階操作測試 ===")
	d.CallFunction(testObj, "run_test", nil)
}
