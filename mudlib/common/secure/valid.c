// /secure/valid.c
// 共用權限管理物件 (World-Agnostic)

#include "/include/config.h"

inherit "/std/object.c";

void create() {
    ::create();
}

mixed valid_read(string path, object user, string func) {
    if (!user || user == 0) return 1;

    string creator = base_name(user);
    if (strsrch(creator, "/secure/") == 0 || strsrch(creator, "/std/") == 0 || strsrch(creator, "/daemon/") == 0) {
        return 1;
    }

    object tp = this_player();
    string role;
    if (tp && userp(tp)) {
        role = tp->query_role();
    } else {
        role = user->query_role();
    }

    if (role == "god") return 1;

    if (strsrch(path, "/secure/") == 0 || strsrch(path, "/data/user/") == 0) {
        if (role == "wizard") return 1;

        if (strsrch(path, "/data/user/") == 0) {
            string uid = user->get_id();
            if (uid && uid != "" && strsrch(path, "/" + uid + ".o") != -1) return 1;
        }
        return "拒絕讀取：該路徑包含敏感資訊。";
    }

    return 1;
}

mixed valid_write(string path, object user, string func) {
    string role;
    string *paths;
    string caller_file = "";
    if (user && user != 0) caller_file = base_name(user);

    // 深度沙盒與幻影模式
    if (user && user != 0) {
        if (strsrch(caller_file, FS_CACHE_DIR) == 0) {
            string rel = substr(caller_file, strlen(FS_CACHE_DIR) + 1, strlen(caller_file));
            int slash = strsrch(rel, "/");
            if (slash != -1) {
                string mid = substr(rel, 0, slash);
                string my_sandbox = FS_CACHE_DIR + "/" + mid + "/";
                if (strsrch(path, my_sandbox) == 0 || strsrch(path, "/log/") == 0) {
                    return 1;
                }
                return "遠端物件沙盒攔截：禁止跨目錄寫入。";
            }
        }

        if (userp(user) && function_exists("query_current_mudlib", user) && user->query_current_mudlib() != "") {
            return "幻影模式攔截：你目前處於虛幻狀態，無法對現實世界造成永久改變。";
        }
    }

    // 1. 系統背景呼叫（無使用者物件）
    if (!user || user == 0) {
        if (strsrch(path, "/data/") == 0 || strsrch(path, "/log/") == 0) return 1;
        return "拒絕：找不到使用者物件，無法驗證身分。";
    }

    // 2. /secure/, /daemon/, /master 白名單
    if (strsrch(caller_file, "/secure/") == 0 ||
        strsrch(caller_file, "/daemon/") == 0 ||
        caller_file == "/master" ||
        caller_file == "/master.c") {
        if (strsrch(path, "/data/") == 0 || strsrch(path, "/log/") == 0) return 1;
    }

    object tp = this_player();
    if (tp && userp(tp)) {
        role = tp->query_role();
    } else {
        role = user->query_role();
    }

    // 3. 天神權限
    if (role == "god") return 1;

    // 4. 巫師權限
    if (role == "wizard") {
        if (strsrch(path, "/rooms/") == 0 ||
            strsrch(path, "/npcs/") == 0 ||
            strsrch(path, "/items/") == 0 ||
            strsrch(path, "/quests/") == 0 ||
            strsrch(path, "/area/") == 0 ||
            strsrch(path, "/npc/") == 0 ||
            strsrch(path, "/item/") == 0 ||
            strsrch(path, "/cmds/") == 0 ||
            strsrch(path, "/log/") == 0 ||
            strsrch(path, "/open/") == 0 ||
            strsrch(path, "/tests/") == 0 ||
            strsrch(path, "/u/") == 0) {
            return 1;
        }
    }

    // 5. 個別授權路徑
    paths = user->query_write_paths();
    if (paths) {
        foreach (string p in paths) {
            if (strsrch(path, p) == 0) return 1;
        }
    }

    // 6. 測試與系統例外（僅放行 /open/ 及測試模式下的 /data/，絕不放行 /secure/）
    if (strsrch(caller_file, "/tests/") == 0) {
        if (strsrch(path, "/open/") == 0) return 1;
        if (getenv("MUD_TEST_MODE") && strsrch(path, "/data/") == 0) return 1;
    }

    if (caller_file == "/secure/system_d" || caller_file == "/daemon/system_d" || caller_file == "/std/login") {
        if (path == "/data/system.o") return 1;
    }

    if (caller_file == "/secure/fs_d") {
        if (strsrch(path, FS_CACHE_DIR) == 0) return 1;
    }

    if (strsrch(caller_file, "/area/lm/") == 0) {
        if (strsrch(path, "/data/lm") == 0) return 1;
    }

    // 7. 玩家自身存檔與備份
    if (strsrch(path, "/data/user/") == 0 || strsrch(path, "/data/backup/user/") == 0) {
        string uid = user->get_id();
        if (uid && uid != "" && strsrch(path, uid) != -1) {
            return 1;
        }
    }

    return "拒絕寫入：目標路徑 (" + path + ") 不在你的授權範圍內。";
}
