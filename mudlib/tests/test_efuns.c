// mudlib/tests/test_efuns.c
inherit "/std/test_case";

void run_tests(object me) {
    start_test("Efun Lifecycle (new, file_name)");
    
    // 語法: object new(string file)
    // 說明: 根據腳本路徑，複製並產生一個新的物件實體。
    // 範例: object sword = new("/obj/weapon/sword");
    object obj = new("/std/object.c");
    assert_true(objectp(obj), "new() should return an object");
    
    // 語法: string file_name([object ob])
    // 說明: 取得物件的完整檔案名稱。
    // 範例: write(file_name(this_object()));
    string name = file_name(obj);
    assert_true(stringp(name), "file_name() should return a string");
    
    // 驗證是否包含路徑
    assert_true(strsrch(name, "/std/object.c") != -1, "file_name should contain path");
    
    destruct(obj);
    report_results();
}
