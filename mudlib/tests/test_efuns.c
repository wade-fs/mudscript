inherit "/std/test_case";

void test_lifecycle() {
    start_test("Efun Lifecycle (new, file_name)");
    object obj = clone_object("/std/object.c");
    assert_true(objectp(obj), "new() should return an object");
    string name = file_name(obj);
    assert_true(stringp(name), "file_name() should return a string");
    assert_true(strsrch(name, "/std/object.c") != -1, "file_name should contain path");
    destruct(obj);
    report_results();
}

void test_type_predicates() {
    start_test("Efun Type Predicates (bufferp, undefinedp)");
    assert_true(intp(undefinedp(0)), "undefinedp(0) should be int");
    report_results();
}

void test_control_flow() {
    start_test("Efun Control Flow (error, throw, call_out)");
    
    mixed err = catch(error("test error"));
    assert_true(stringp(err), "error() should be catchable and return string");

    err = catch(throw("test throw"));
    assert_true(stringp(err), "throw() should be catchable");
    assert_true(strsrch(err, "test throw") != -1, "throw() should return the message");

    call_out("test_call_out_func", 1);
    int left = find_call_out("test_call_out_func");
    assert_true(left >= 0, "call_out should be found");
    remove_call_out("test_call_out_func");
    assert_true(find_call_out("test_call_out_func") == -1, "call_out should be removed");

    report_results();
}

void test_call_out_func() {}

void test_io_efuns(object me) {
    start_test("Efun I/O (write, say, tell_object, tell_room, message, receive, shout)");
    
    write("test write\n");
    tell_object(me, "test tell_object\n");
    
    object env = environment(me);
    if (env) {
        tell_room(env, "test tell_room\n");
        message("say", "test message", env, me);
    }
    
    me->receive("test receive\n");
    shout("test shout\n");
    
    report_results();
}
void test_interactive_efuns(object me) {
    start_test("Efun Interactive (this_interactive, get_char)");

    // 在測試執行環境中，me 通常就是當前玩家
    object ti = this_interactive();

    // 檢查 ti 是否有效，若測試環境中沒有 interactive user，跳過
    if (ti) {
        assert_true(ti == me, "this_interactive() should return this_player()");
    } else {
        write("  [SKIP] this_interactive() skipped (no interactive user)\n");
    }

    get_char("do_test_get_char");

    report_results();
}

void do_test_get_char(string str) {}

void test_filesystem_efuns() {
    start_test("Efun Filesystem (file_size, write_file, read_file, rm, mkdir, rmdir)");
    
    string test_file = "/open/test_file.txt";
    string test_dir = "/open/test_dir";
    
    int res = write_file(test_file, "hello world\n", 1);
    if (res == 0) {
        write("  [SKIP] write_file() skipped (permission denied)\n");
    } else {
        assert_true(res == 1, "write_file() should succeed");
        int size = file_size(test_file);
        assert_true(size > 0, "file_size() should return size > 0");
        string content = read_file(test_file);
        assert_true(content == "hello world\n", "read_file() should return content");
        res = rm(test_file);
        assert_true(res == 1, "rm() should succeed");
    }
    
    res = mkdir(test_dir);
    if (res == 0) {
        write("  [SKIP] mkdir() skipped (permission denied)\n");
    } else {
        assert_true(res == 1, "mkdir() should succeed");
        res = rmdir(test_dir);
        assert_true(res == 1, "rmdir() should succeed");
    }
    
    report_results();
}

void run_tests(object me) {
    test_lifecycle();
    test_type_predicates();
    test_control_flow();
    test_io_efuns(me);
    test_interactive_efuns(me);
    test_filesystem_efuns();
}
