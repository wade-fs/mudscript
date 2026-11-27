// std/test_case.c - 通用測試案例基底類別 (World-Agnostic)
// 同時相容 _template (pass_count/fail_count) 與 fsmud/forgotten-space (total_tests/passed_tests)

#include "/include/ansi.h"

inherit "/std/object.c";

int pass_count = 0;
int fail_count = 0;
int total_tests = 0;
int passed_tests = 0;
string test_name = "未命名測試";
string current_test_name = "";

void create() {
    ::create();
    pass_count        = 0;
    fail_count        = 0;
    total_tests       = 0;
    passed_tests      = 0;
    test_name         = "未命名測試";
    current_test_name = "";
}

void set_test_name(string n) {
    test_name = n;
    current_test_name = n;
}

void start_test(string name) {
    current_test_name = name;
    test_name = name;
    write("$HIY$\n👉 正在執行測試組: $NOR$" + name + "\n");
}

void assert_true(int cond, string desc) {
    total_tests++;
    if (cond) {
        pass_count++;
        passed_tests++;
        if (current_test_name == "") {
            write("  [PASS] " + desc + "\n");
        }
    } else {
        fail_count++;
        write("$HIR$  [FAIL] $NOR$" + desc + " (預期為真)\n");
    }
}

void assert_false(int cond, string desc) {
    assert_true(!cond, desc);
}

void assert_equal(mixed expected, mixed actual, string desc) {
    total_tests++;
    if (expected == actual) {
        pass_count++;
        passed_tests++;
        if (current_test_name == "") {
            write("  [PASS] " + desc + " (期望: " + to_string(actual) + ", 實際: " + to_string(expected) + ")\n");
        }
    } else {
        fail_count++;
        write("$HIR$  [FAIL] $NOR$" + desc + "\n");
        write("         預期: " + sprintf("%O", expected) + "\n");
        write("         實際: " + sprintf("%O", actual) + "\n");
    }
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

void report_results() {
    write("\n" + "$HIW$測試總結: $NOR$" + current_test_name + "\n");
    if (passed_tests == total_tests) {
        write("$HIG$✅ 全部通過 (" + passed_tests + "/" + total_tests + ")$NOR$" + "\n");
    } else {
        write("$HIR$❌ 部分失敗 (" + (total_tests - passed_tests) + "/" + total_tests + ")$NOR$" + "\n");
    }
}

int query_total()      { return total_tests; }
int query_passed()     { return passed_tests; }
int query_pass_count() { return pass_count; }
int query_fail_count() { return fail_count; }
