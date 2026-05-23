// mudlib/tests/test_save.c
inherit "/std/test_case";

void run_tests(object me) {
    start_test("System Save Verification");

    object nature_d = load_object("/secure/nature_d.c");
    nature_d->save_object("/data/test_save");
    
    mixed *files = get_dir("/data/test_save.o");
    assert_true(sizeof(files) > 0, "test_save.o should be created");
    
    if (sizeof(files) > 0) {
        rm("/data/test_save.o");
    }

    report_results();
}
