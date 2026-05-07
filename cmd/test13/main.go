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
		"/cmd/give.c": `
			// 模擬處理玩家輸入的指令
			void do_command(string arg) {
				int amount;
				string item;
				string target;

				// 1. 使用 sscanf 拆解玩家指令 (傳址參考的神奇之處！)
				// 輸入範例: "100 gold to guard"
				int match_count = sscanf(arg, "%d %s to %s", amount, item, target);

				if (match_count != 3) {
					write("語法錯誤！請輸入: give <數量> <物品> to <目標>\n");
					return;
				}

				// 2. 使用 sprintf 漂亮地排版輸出！
				string msg = sprintf("你拿出了 %5d 個 [%s] 交給了 %s。\n", amount, item, target);
				write(msg);
				
				// 再來點進階的格式化
				write(sprintf("  -> 剩餘金幣: %06d\n", 9999 - amount));
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
	cmdObj, err := d.CloneObject("/cmd/give.c")
	if err != nil {
		panic(fmt.Sprintf("載入腳本失敗: %v", err))
	}

	fmt.Println("=== 測試指令：give 100 gold to guard ===")
	d.CallFunction(cmdObj, "do_command", []object.Object{&object.String{Value: "100 gold to guard"}})

	fmt.Println("\n=== 測試指令：give apple ===")
	d.CallFunction(cmdObj, "do_command", []object.Object{&object.String{Value: "apple"}})
}
