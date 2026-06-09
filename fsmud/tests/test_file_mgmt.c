// /tests/test_file_mgmt.c
inherit "/std/test_case";

// 讓測試物件具備管理員權限，以便建立測試目錄
string query_role() { return "god"; }

void run_tests(object me) {
    start_test("檔案管理與 CWD 權限驗證");

    write("DEBUG: 1. 建立測試目錄 (由具備 god 權限的測試物件執行)\n");
    mkdir("/a");
    mkdir("/a/b");
    mkdir("/x");
    mkdir("/x/y");
    mkdir("/area");

    write("DEBUG: 2. 建立一個測試用的巫師\n");
    object wizard = clone_object("/std/user.c");
    wizard->set_id("test_wizard");
    wizard->set_role("wizard");
    wizard->enable_wizard(); 

    write("DEBUG: 3. 初始化授權路徑 (使用正確的函式)\n");
    wizard->add_write_path("/a/b");
    wizard->add_write_path("/x/y");
    wizard->set_cwd("/");

    write("DEBUG: 4. 載入指令\n");
    object cd_cmd = load_object("/cmds/admin/cmd_cd.c");
    
    write("DEBUG: 測試 A: cd /a/b (授權路徑) -> 預期成功\n");
    set_this_player(wizard);
    write("DEBUG: 測試 A.1 cd /a/b\n");
    cd_cmd->main(wizard, "cd", "/a/b");
    write("DEBUG: 測試 A.2 set_this_player(me)\n");
    set_this_player(me);
    assert_equal("/a/b", wizard->query_cwd(), "cd /a/b (授權路徑) 應該成功");

    write("DEBUG: 測試 B: cd /a (未授權父目錄) -> 預期失敗\n");
    wizard->set_cwd("/a/b"); 
    set_this_player(wizard);
    cd_cmd->main(wizard, "cd", "/a");
    set_this_player(me);
    assert_equal("/a/b", wizard->query_cwd(), "cd /a (未授權) 應該失敗並保持原位");

    write("DEBUG: 測試 C: cd /x/y (另一個授權路徑) -> 預期成功\n");
    set_this_player(wizard);
    cd_cmd->main(wizard, "cd", "/x/y");
    set_this_player(me);
    assert_equal("/x/y", wizard->query_cwd(), "cd /x/y (授權路徑) 應該成功");

    write("DEBUG: 測試 D: cd .. (跳到未授權的 /x) -> 預期失敗\n");
    set_this_player(wizard);
    cd_cmd->main(wizard, "cd", "..");
    set_this_player(me);
    assert_equal("/x/y", wizard->query_cwd(), "cd .. (跳向未授權) 應該失敗");

    write("DEBUG: 測試 E: cd /area (預設開放目錄) -> 預期成功\n");
    set_this_player(wizard);
    cd_cmd->main(wizard, "cd", "/area");
    set_this_player(me);
    assert_equal("/area", wizard->query_cwd(), "cd /area (預設開放) 應該成功");

    write("DEBUG: 清理\n");
    set_this_player(me);
    rmdir("/x/y");
    rmdir("/x");
    rmdir("/a/b");
    rmdir("/a");

    destruct(wizard);
    write("DEBUG: Finalizing file management tests...\n");
    report_results();
}

