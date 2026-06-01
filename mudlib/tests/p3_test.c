// mudlib/tests/p3_test.c
inherit "/std/test_case";

void test_buffer() {
    start_test("Efun Buffer (allocate_buffer, bufferp, read_buffer, write_buffer)");
    
    buffer b = allocate_buffer(10);
    assert_true(bufferp(b), "allocate_buffer should return a buffer");
    assert_equal(10, sizeof(b), "buffer size should be 10");

    write_buffer(b, 0, "Hello");
    assert_equal("Hello", read_buffer(b, 0, 5), "read_buffer should return 'Hello'");

    write_buffer(b, 5, 65); // 'A'
    assert_equal(65, read_buffer(b, 5, 1), "read_buffer with len 1 should return integer 65");

    report_results();
}

void test_bits() {
    start_test("Efun Bits (set_bit, clear_bit, test_bit)");
    
    string s = "";
    s = set_bit(s, 0);
    s = set_bit(s, 6);
    assert_equal(1, test_bit(s, 0), "bit 0 should be set");
    assert_equal(1, test_bit(s, 6), "bit 6 should be set");
    assert_equal(0, test_bit(s, 1), "bit 1 should not be set");

    s = clear_bit(s, 0);
    assert_equal(0, test_bit(s, 0), "bit 0 should be cleared");
    assert_equal(1, test_bit(s, 6), "bit 6 should still be set");

    report_results();
}

void test_wizard(object me) {
    start_test("Efun Wizard (enable_wizard, disable_wizard, wizardp)");
    
    enable_wizard();
    assert_true(wizardp(this_object()), "enable_wizard should make object a wizard");
    disable_wizard();
    assert_true(!wizardp(this_object()), "disable_wizard should remove wizard status");
    
    report_results();
}

void test_crc32() {
    start_test("Efun CRC32");
    
    int c1 = crc32("hello");
    int c2 = crc32("hello");
    assert_equal(c1, c2, "crc32 should be consistent for same input");
    assert_true(c1 != 0, "crc32 should not be 0 for 'hello'");
    
    report_results();
}

void test_match_path() {
    start_test("Efun Match Path");
    
    mapping m = ([
        "/": "root",
        "/secure/": "secure",
        "/std/": "std",
        "/std/object.c": "object",
    ]);

    assert_equal("secure", match_path(m, "/secure/test.c"), "match_path should match directory with trailing slash");
    assert_equal("object", match_path(m, "/std/object.c"), "match_path should match exact file path");
    assert_equal("root", match_path(m, "/area/room.c"), "match_path should fallback to root '/'");
    
    report_results();
}

void run_tests(object me) {
    test_buffer();
    test_bits();
    test_wizard(me);
    test_crc32();
    test_match_path();
}
