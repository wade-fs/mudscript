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
    start_test("Efun Control Flow (error)");
    // 測試 error() 應觸發執行期錯誤，這裡我們使用 catch 來測試
    mixed err = catch(error("test error"));
    assert_true(stringp(err), "error() should be catchable and return string");
    report_results();
}

void run_tests(object me) {
    test_lifecycle();
    test_type_predicates();
    test_control_flow();
}
