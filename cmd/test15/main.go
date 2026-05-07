package main

import (
	"os"
	"path/filepath"

	"mudscript/driver"
)

func main() {
	files := map[string]string{
		"/master.c": `
			// 如果 catch 失敗，錯誤就會漏到這裡來
			void runtime_error(string msg, string file) {
				write("\n🔥 [系統崩潰警告] 檔案: " + file + " -> 錯誤: " + msg + "\n");
			}
		`,
		"/test.c": `
			// 測試 1：系統錯誤
			void dangerous_system_call() {
				write("  -> 試著存取不存在的變數...\n");
				int x = unknown_variable_will_crash + 10;
			}

			// 測試 2：自定義業務邏輯錯誤
			void dangerous_business_logic(int amount) {
				write("  -> 試著提款 " + amount + " 元...\n");
				if (amount > 100) {
					throw("餘額不足！");
				}
				write("  -> 提款成功！\n");
			}

			void run_test() {
				mixed err;

				write("=== 測試一：捕捉系統錯誤 ===\n");
				err = catch( dangerous_system_call() );
				if (err != 0) {
					write("✅ 成功攔截系統錯誤: " + err + "\n\n");
				}

				write("=== 測試二：捕捉自定義 throw ===\n");
				err = catch( dangerous_business_logic(500) );
				if (err != 0) {
					write("✅ 成功攔截業務錯誤: " + err + "\n\n");
				}

				write("=== 測試三：正常執行無錯誤 ===\n");
				err = catch( dangerous_business_logic(150) );
				if (err == 0) {
					write("✅ 執行順利，catch 回傳 0\n\n");
				}
				
				write("=== 測試四：故意不使用 catch (觀察 master.c 反應) ===\n");
				dangerous_system_call();
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

	// 綁定 master.c 啟動引擎
	d := driver.New(driver.DriverConfig{
		MudLibPath: tmpDir,
		MasterFile: "/master.c",
	})
	d.Start()

	testObj, err := d.CloneObject("/test.c")
	if err != nil {
		panic(err)
	}

	d.CallFunction(testObj, "run_test", nil)
}
