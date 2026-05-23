// mudlib/tests/test_path.c
inherit "/std/test_case";

void run_tests(object me) {
    start_test("Path and Object Name Consistency");

    object room = load_object("/area/newbie/room_4_4.c");
    string name = object_name(room);
    
    write("Room object_name: '" + name + "'\n");
    
    if (substr(name, 0, 1) == "/") {
        write("Result: Starts with /\n");
    } else {
        write("Result: Does NOT start with /\n");
    }

    report_results();
}
