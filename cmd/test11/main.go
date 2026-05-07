package main

import (
	"os"
	"path/filepath"
	"time"

	"mudscript/driver"
)

func main() {
	files := map[string]string{
		"/master.c": `
			string get_root_uid() { return "Root"; }
			string get_bb_uid() { return "Backbone"; }
			
			// 處理連線
			object connect() {
				write("-> [Master] 接收到新連線，指派登入物件...\n");
				// 正常情況下這裡會 return clone_object("/clone/login.c");
				// 為了測試，我們讓他回傳自己當作佔位符
				return this_object(); 
			}

			// 攔截系統錯誤
			void runtime_error(string msg, string file) {
				write("\n🔥 [系統全域警報] 執行期錯誤！\n");
				write("   檔案: " + file + "\n");
				write("   錯誤: " + msg + "\n");
			}
		`,
		"/obj/buggy.c": `
			void do_something_dangerous() {
				write("準備做一些危險操作...\n");
				// 呼叫一個根本不存在的變數引發 Evaluator Error
				int x = unknown_variable + 10; 
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

	// 1. 初始化引擎
	d := driver.New(driver.DriverConfig{
		MudLibPath: tmpDir,
		MasterFile: "/master.c",
	})

	// 2. 啟動 Driver (會自動載入 master.c 並觸發 UID 掛勾)
	if err := d.Start(); err != nil {
		panic(err)
	}

	// 3. 模擬一個玩家連線
	d.AcceptConnection()

	// 4. 載入並引爆有 Bug 的物件
	buggy, _ := d.CloneObject("/obj/buggy.c")
	d.CallFunction(buggy, "do_something_dangerous", nil)

	// 給背景執行續一點時間印出訊息
	time.Sleep(100 * time.Millisecond)
}
