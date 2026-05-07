package main

import (
	"fmt"
	"os"
	"path/filepath"

	"mudscript/driver"
	"mudscript/object"
)

func main() {
	// 1. 定義要測試的 LPC 腳本內容
	files := map[string]string{
		"/std/monster.c": `
			int hp;
			string name;
			
			// 基底怪物的受傷邏輯
			void take_damage(int amount) {
				hp -= amount;
				write(name + " 受到了傷害！剩餘血量: " + hp + "\n");
			}
		`,
		"/d/goblin.c": `
			// 宣告繼承！
			inherit "/std/monster.c";
			
			// 覆寫初始化邏輯
			void create() {
				name = "狂暴哥布林";
				hp = 100;
				write(name + " 誕生了！\n");
			}
		`,
	}

	// 2. 建立作業系統的暫存資料夾 (模擬 MudLibPath)
	tmpDir, err := os.MkdirTemp("", "mudlib_test")
	if err != nil {
		panic("無法建立暫存目錄: " + err.Error())
	}
	// 確保程式結束時會自動清理這些垃圾檔案
	defer os.RemoveAll(tmpDir)

	// 3. 把虛擬腳本寫入暫存硬碟
	for path, content := range files {
		fullPath := filepath.Join(tmpDir, path)
		// 因為路徑包含 /std 和 /d，需要先建立子目錄
		os.MkdirAll(filepath.Dir(fullPath), 0755)
		os.WriteFile(fullPath, []byte(content), 0644)
	}

	fmt.Println("📁 成功建立暫存 MudLib 於:", tmpDir)

	// ==========================================
	// 開始進行 Driver 引擎測試
	// ==========================================
	
	// 4. 初始化 Driver 並指定剛剛建立的暫存目錄
	d := driver.New(driver.DriverConfig{
		MudLibPath: tmpDir,
	})

	fmt.Println("\n=== 開始載入並複製哥布林 ===")
	goblin, err := d.CloneObject("/d/goblin.c")
	if err != nil {
		fmt.Println("❌ 載入失敗:", err)
		return
	}

	fmt.Println("\n=== 測試戰鬥 (呼叫從 /std/monster 繼承來的方法) ===")
	// 模擬玩家對哥布林造成 25 點傷害
	args := []object.Object{&object.Integer{Value: 25}}
	d.CallFunction(goblin, "take_damage", args)

	// 5. 系統底層驗證
	fmt.Println("\n=== 系統底層記憶體驗證 ===")
	if hp, ok := goblin.Vars.Get("hp"); ok {
		fmt.Printf("哥布林目前的 HP 變數值: %s\n", hp.Inspect()) // 預期 75
	}
}
