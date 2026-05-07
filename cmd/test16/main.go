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
			// 一個簡單的加法函式
			int add_numbers(int a, int b, int c) {
				write(sprintf("  執行 add_numbers(%d, %d, %d)\n", a, b, c));
				return a + b + c;
			}

			void run_test() {
				// 1. 建立一個預先綁定了 10 和 20 的閉包
				mixed my_closure = (: "add_numbers", 10, 20 :);
				write("建立閉包: " + sprintf("%O", my_closure) + "\n");

				// 2. 稍後執行它，只須補上最後一個參數 5
				write("準備執行 evaluate...\n");
				int result = evaluate(my_closure, 5);
				
				write(sprintf("結果: %d\n", result));
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

	fmt.Println("=== LPC 函數指標 (Closures) 測試 ===")
	d.CallFunction(testObj, "run_test", nil)
}
