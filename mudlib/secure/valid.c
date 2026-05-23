// /secure/valid.c
// 權限管理物件

// valid_read: 控制檔案讀取權限
mixed valid_read(string path, object user, string func) {
    if (!user) return 1; // 系統內部讀取允許
    
    string role = user->query_role();
    if (role == "god") return 1;

    // 保護敏感目錄
    if (strsrch(path, "/secure/") == 0 || strsrch(path, "/data/user/") == 0) {
        if (role == "wizard") return 1; // 巫師可以讀取，但不能隨意寫入
        
        // 玩家只能讀取自己的資料
        if (strsrch(path, "/data/user/") == 0) {
            string uid = user->get_id();
            if (uid && strsrch(path, uid) != -1) return 1;
        }
        return "拒絕讀取：該路徑包含敏感資訊。";
    }

    return 1; // 預設允許讀取
}

// valid_write: 控制檔案寫入與刪除權限
mixed valid_write(string path, object user, string func)
{
    string role;
    string *paths;

    if (!user) { return "拒絕：找不到使用者物件，無法驗證身分。"; }

    role = user->query_role();

    // 1. 天神擁有絕對權限
    if (role == "god") { return 1; }

    // 2. 巫師 (Wizard) 權限：允許開發遊戲內容
    if (role == "wizard") {
        // 允許寫入區域、NPC、物品、指令等非核心目錄
        if (strsrch(path, "/area/") == 0 || 
            strsrch(path, "/npc/") == 0 || 
            strsrch(path, "/item/") == 0 ||
            strsrch(path, "/cmds/") == 0 ||
            strsrch(path, "/log/") == 0) {
            return 1;
        }
    }

    // 3. 檢查個別授權的路徑 (透過 add_write_path 給予的)
    paths = user->query_write_paths();
    if (paths) {
        foreach (p in paths) {
            if (strsrch(path, p) == 0) { return 1; }
        }
    }

    // 4. 特殊例外
    // 允許使用者儲存自己的資料 (/data/user/) 或 備份 (/data/backup/user/)
    if (strsrch(path, "/data/user/") == 0 || strsrch(path, "/data/backup/user/") == 0) {
        string uid = user->get_id();
        if (uid && uid != "" && strsrch(path, uid) != -1) {
            return 1;
        }
    }

    // 若全數不匹配
    return "拒絕寫入：目標路徑 (" + path + ") 不在你的授權範圍內。";
}
