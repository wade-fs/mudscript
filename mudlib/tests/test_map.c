// mudlib/tests/test_map.c
inherit "/std/test_case";

void run_tests(object me) {
    start_test("Map Drawing Utility");

    if (!me) {
        write("錯誤：找不到用戶物件。\n");
        return;
    }

    // Ensure player is in a room with coordinates
    if (!environment(me)) {
        me->move(load_object("/area/newbie/room_4_4.c"), "teleport");
    } else {
        // Force move to square for consistent testing
        me->move(load_object("/area/newbie/room_4_4.c"), "teleport");
    }

    // 1. Test basic drawing
    string map_str = load_object("/secure/map_d.c")->draw_map(me, 1);
    assert_true(strlen(map_str) > 0, "Map should not be empty");
    assert_true(strsrch(map_str, "[★]") != -1, "Map should contain player marker [★]");
    assert_true(strsrch(map_str, "|") != -1 || strsrch(map_str, "-") != -1, "Map should contain connection markers");

    // 2. Test JSON output
    mapping map_json = load_object("/secure/map_d.c")->get_map_json(me, 1);
    assert_true(mapp(map_json), "Map JSON should be a mapping");
    assert_equal("player", map_json["grid"][1][1], "Center of 3x3 grid should be player");
    assert_true(sizeof(map_json["connections"]) > 0, "Should have at least some connections in newbie square");

    report_results();
}
