// mudlib/master.c

string get_root_uid() { return "Root"; }
string get_bb_uid() { return "Backbone"; }

void create() {
    enable_commands();
}

object connect() {
    write("透過 Master 建立新連線...\n");
    return this_object(); 
}

void init() {
    add_action("do_look", "look");
    add_action("do_smile", "smile");
}

int do_look(string arg) {
    if (!arg) {
        write("你環顧四周，這裡空無一物。\n");
    } else {
        write("你看了看 " + arg + "。\n");
    }
    return 1;
}

int do_smile(string arg) {
    if (!arg) {
        write("你開心地笑了。\n");
        // 如果還沒有寫 query_name，這裡先用寫死的字串測試
        say("有人 開心地笑了。\n"); 
    } else {
        write("你對著 " + arg + " 笑了笑。\n");
    }
    return 1;
} // <--- 之前這裡漏了這個大括號！

// 將 void 改為 int，因為它需要回傳 1 或 0
int process_input(string arg) {
    if (arg == "help") {
        write("指令列表：look, smile, history\n");
        return 1;
    }
    return 0;
}

void runtime_error(string msg, string file) {
    write("🔥 系統錯誤 [" + file + "]: " + msg + "\n");
}
