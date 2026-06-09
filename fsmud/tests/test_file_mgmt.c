// /tests/test_file_mgmt.c
inherit "/std/test_case";

// 讓測試物件具備管理員權限，以便建立測試目錄
string query_role() { return "god"; }

void run_tests(object me) {
    start_test("檔案管理與 CWD 權限驗證");

    // 建立一個測試用的巫師
    object wizard = clone_object("/std/user.c");
    wizard->set_id("test_wizard");
    wizard->set_role("wizard");
    wizard->enable_wizard(); // 🚀 重要：啟用巫師權限
    
    write("DEBUG: wizard created, role=" + wizard->query_role() + ", wizardp=" + wizardp(wizard) + "\n");
    
    // 初始化授權路徑: write_paths({ "/a/b", "/x/y" })
    wizard->set("write_paths", ({ "/a/b", "/x/y" }));
    wizard->set_cwd("/");

    // 載入 cd 指令物件
    object cd_cmd = load_object("/cmds/admin/cmd_cd.c");
    if (!cd_cmd) {
        assert_true(0, "無法載入 cd 指令物件");
        destruct(wizard);
        return;
    }
    
    // 設定 this_player() 讓 simul_efun 的 resolv_path 正確運作
    set_this_player(wizard);
    tell_object(me, "DEBUG: this_player is " + (this_player() ? object_name(this_player()) : "0") + "\n");

    // 建立測試目錄 (God 權限或系統內部呼叫 mkdir)
    tell_object(me, "DEBUG: Creating test directories...\n");
    int m1 = mkdir("/a");
    int m2 = mkdir("/a/b");
    int m3 = mkdir("/x");
    int m4 = mkdir("/x/y");
    tell_object(me, sprintf("DEBUG: mkdir results: /a:%d, /a/b:%d, /x:%d, /x/y:%d\n", m1, m2, m3, m4));

    // 1. 測試 cd /a/b (預期成功)
    tell_object(me, "測試: cd /a/b (授權路徑)\n");
    cd_cmd->main(wizard, "cd", "/a/b");
    assert_equal("/a/b", wizard->query_cwd(), "cd /a/b 應該成功切換");

    // 2. 測試 cd /a (預期失敗)
    tell_object(me, "測試: cd /a (未授權路徑)\n");
    cd_cmd->main(wizard, "cd", "/a");
    assert_equal("/a/b", wizard->query_cwd(), "cd /a 應該失敗 (保持在 /a/b)");

    // 3. 測試 cd /x/y (預期成功)
    tell_object(me, "測試: cd /x/y (另一個授權路徑)\n");
    cd_cmd->main(wizard, "cd", "/x/y");
    assert_equal("/x/y", wizard->query_cwd(), "cd /x/y 應該成功切換");

    // 4. 測試 cd .. (預期失敗)
    tell_object(me, "測試: cd .. (跳到未授權路徑)\n");
    cd_cmd->main(wizard, "cd", "..");
    assert_equal("/x/y", wizard->query_cwd(), "cd .. 應該失敗 (保持在 /x/y)");

    // 5. 測試 cd /area (預期成功)
    mkdir("/area");
    tell_object(me, "測試: cd /area (預設開放目錄)\n");
    cd_cmd->main(wizard, "cd", "/area");
    assert_equal("/area", wizard->query_cwd(), "cd /area 應該成功");


    // 清理測試目錄
    rmdir("/x/y");
    rmdir("/x");
    rmdir("/a/b");
    rmdir("/a");
    // 不清理 /area，因為它是系統預設目錄
    
    destruct(wizard);
    report_results();
}
