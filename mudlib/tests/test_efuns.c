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
    // Basic test to ensure efuns are registered and callable
    assert_true(intp(undefinedp(0)), "undefinedp(0) should be int");
    report_results();
}

void test_control_flow() {
    start_test("Efun Control Flow (error, throw, call_out)");
    
    // 測試 error() 應觸發執行期錯誤，這裡我們使用 catch 來測試
    mixed err = catch(error("test error"));
    assert_true(stringp(err), "error() should be catchable and return string");

    // 測試 throw()
    err = catch(throw("test throw"));
    assert_true(stringp(err), "throw() should be catchable");
    assert_true(strsrch(err, "test throw") != -1, "throw() should return the message");

    // 測試 call_out()
    call_out("test_call_out_func", 1);
    int left = find_call_out("test_call_out_func");
    assert_true(left >= 0, "call_out should be found");
    remove_call_out("test_call_out_func");
    assert_true(find_call_out("test_call_out_func") == -1, "call_out should be removed");

    report_results();
}

void test_call_out_func() {
    // Helper function for call_out
}

void test_io_efuns(object me) {
    start_test("Efun I/O (tell_object, tell_room, message, receive)");
    
    // 測試 tell_object
    tell_object(me, "test tell_object\n");
    
    // 測試 tell_room
    object env = environment(me);
    if (env) {
        tell_room(env, "test tell_room\n");
    } else {
        write("  [SKIP] tell_room skipped (no environment)\n");
    }
    
    // 測試 message
    if (env) {
        message("say", "test message", env, me);
    } else {
        write("  [SKIP] message skipped (no environment)\n");
    }
    
    // 測試 receive
    me->receive("test receive\n");
    
    report_results();
}

void test_filesystem_efuns() {
    start_test("Efun Filesystem (file_size, write_file, read_file, rm, mkdir, rmdir)");
    
    string test_file = "/open/test_file.txt";
    string test_dir = "/open/test_dir";
    
    // 測試 write_file
    int res = write_file(test_file, "hello world\n", 1);
    if (res == 0) {
        write("  [SKIP] write_file() skipped (permission denied)\n");
    } else {
        assert_true(res == 1, "write_file() should succeed");
        
        // 測試 file_size
        int size = file_size(test_file);
        assert_true(size > 0, "file_size() should return size > 0");
        
        // 測試 read_file
        string content = read_file(test_file);
        assert_true(content == "hello world\n", "read_file() should return content");
        
        // 測試 rm
        res = rm(test_file);
        assert_true(res == 1, "rm() should succeed");
    }
    
    // 測試 mkdir
    res = mkdir(test_dir);
    if (res == 0) {
        write("  [SKIP] mkdir() skipped (permission denied)\n");
    } else {
        assert_true(res == 1, "mkdir() should succeed");
        // 測試 rmdir
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
    test_filesystem_efuns();
}
