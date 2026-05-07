// mudlib/user.c

string name;

string query_name() {
    if (name) { return name; }
    return "無名旅者";
}

void set_name(string n) { name = n; }

void create() {
    name = "旅者#" + sprintf("%d", time());
    set_heart_beat(1);
}

void heart_beat() {
    write("💓 [" + query_name() + "] 心跳中... t=" + sprintf("%d", time()) + "\n");
}

void setup() {
    enable_commands();
    add_action("do_quit",  "quit");
    add_action("do_quit",  "exit");
    add_action("do_look",  "look");
    add_action("do_smile", "smile");
    add_action("do_say",   "say");
    add_action("do_name",  "name");
    add_action("do_who",   "who");
    add_action("do_test",  "test");

    object start_room = clone_object("/start.c");
    move_object(start_room);
    start_room->look_room();
}

void init() {}

// ── 基本指令 ────────────────────────────────────────

int do_quit(string arg) {
    write("你化為一道光芒，離開了這個世界。\n");
    say(query_name() + " 離開了遊戲。\n");
    destruct(this_object());
    return 1;
}

int do_look(string arg) {
    if (!arg) {
        object here = environment(this_object());
        if (here) {
            here->look_room();
        } else {
            write("你環顧四周，什麼都沒有。\n");
        }
    } else {
        write("你看了看 " + arg + "。\n");
    }
    return 1;
}

int do_smile(string arg) {
    if (!arg) {
        write("你開心地笑了。\n");
        say(query_name() + " 開心地笑了。\n");
    } else {
        write("你對著 " + arg + " 笑了笑。\n");
    }
    return 1;
}

int do_say(string arg) {
    if (!arg) {
        write("說什麼？\n");
        return 1;
    }
    write("你說：" + arg + "\n");
    say(query_name() + " 說：" + arg + "\n");
    return 1;
}

int do_name(string arg) {
    if (!arg) {
        write("你的名字是：" + query_name() + "\n");
        return 1;
    }
    set_name(arg);
    write("你的名字改為：" + arg + "\n");
    return 1;
}

// who 指令：列出所有在線玩家（透過 master 的 interactiveObjects）
int do_who(string arg) {
    write("=== 在線玩家 ===\n");
    write("（此功能需要 all_players efun，待實作）\n");
    return 1;
}

// ── 測試指令 ────────────────────────────────────────

int do_test(string arg) {
    if (arg == "hb") {
        write("當前心跳狀態：已啟用\n");
        write("你的名字：" + query_name() + "\n");
        write("物件檔名：" + object_name(this_object()) + "\n");
        return 1;
    }
    write("用法: test hb\n");
    return 1;
}

int process_input(string arg) {
    if (arg == "help") {
        write("指令：look, smile, say <msg>, name <name>, who, quit\n");
        return 1;
    }
    return 0;
}
