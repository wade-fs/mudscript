// /tests/test_security.c
inherit "/std/test_case";

void run_tests() {
    start_test("安全性與權限審核");

    object me = this_player();
    if (!me) {
        // 模擬一個 wizard 物件來測試
        me = clone_object("/std/user.c");
        // 直接設定變數，而不只是呼叫函式，確保 Driver 能偵測到 Role
        me->set_role("wizard");
    }

    string role = me->query_role();
    write("當前測試角色: " + role + "\n");

    // 1. 測試 Wizard 寫入權限
    if (role == "wizard") {
        // 巫師應該可以寫入 /area/
        int res = write_file("/area/test_touch.txt", "wizard test", 1);
        assert_equal(1, res, "Wizard 應該具有 /area/ 寫入權限");
        rm("/area/test_touch.txt");

        // 巫師應該可以寫入 /npc/
        res = write_file("/npc/test_touch.txt", "wizard test", 1);
        assert_equal(1, res, "Wizard 應該具有 /npc/ 寫入權限");
        rm("/npc/test_touch.txt");

        // 巫師不應該可以寫入 /secure/
        res = write_file("/secure/hack.c", "hack", 1);
        assert_equal(0, res, "Wizard 不應該具有 /secure/ 寫入權限");
    }

    // 2. 測試讀取權限
    // 讀取公共檔案
    string content = read_file("/README.md");
    assert_true(strlen(content) > 0, "應該可以讀取公共檔案 README.md");

    // 巫師應該可以讀取 /secure/ (以便除錯)，但玩家不行
    content = read_file("/secure/valid.c");
    if (role == "wizard" || role == "god") {
        assert_true(strlen(content) > 0, "管理員/巫師 應該可以讀取 /secure/ 檔案");
    } else {
        assert_true(!content, "一般玩家 不應該可以讀取 /secure/ 檔案");
    }

    report_results();
    
    if (me->query_role() == "wizard" && !this_player()) {
        destruct(me);
    }
}
