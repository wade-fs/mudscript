// std/test_case.c - 通用測試案例基底類別 (World-Agnostic)
// 供 MUD_TEST_MODE 下的自動化測試使用

inherit "/std/object.c";

int pass_count;
int fail_count;
string test_name;

void create() {
    ::create();
    pass_count = 0;
    fail_count = 0;
    test_name  = "未命名測試";
}

void set_test_name(string n) { test_name = n; }

void assert_true(int cond, string desc) {
    if (cond) {
        pass_count++;
        write("  [PASS] " + desc + "\n");
    } else {
        fail_count++;
        write("  [FAIL] " + desc + "\n");
    }
}

void assert_false(int cond, string desc) {
    assert_true(!cond, desc);
}

void assert_equal(mixed a, mixed b, string desc) {
    assert_true(a == b, desc + " (期望: " + to_string(b) + ", 實際: " + to_string(a) + ")");
}

void assert_not_equal(mixed a, mixed b, string desc) {
    assert_true(a != b, desc);
}

void assert_string(mixed v, string desc) {
    assert_true(stringp(v), desc + " (期望字串, 實際: " + typeof(v) + ")");
}

void assert_mapping(mixed v, string desc) {
    assert_true(mapp(v), desc + " (期望 mapping, 實際: " + typeof(v) + ")");
}

// 子類別實作此函式來執行測試
int run_tests() {
    write("=== " + test_name + " ===\n");
    return fail_count;
}

int query_pass_count() { return pass_count; }
int query_fail_count() { return fail_count; }
