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
	add_action("do_test", "test");
}

int do_test(string arg) {
    if (arg == "string") {
        write("=== 測試字串 Efuns ===\n");
        write("lower_case('MUD'): " + lower_case("MUD") + "\n");
        write("upper_case('mud'): " + upper_case("mud") + "\n");
        
        // 測試中文長度，應該要印出 4，而不是 12 (bytes)
        write("strlen('測試字串'): " + sprintf("%d", strlen("測試字串")) + "\n");
        
        // 測試中英文混合截取
        write("substr('Hello世界', 5, 2): " + substr("Hello世界", 5, 2) + "\n");
        
        write("strsrch('Hello World', 'World'): " + sprintf("%d", strsrch("Hello World", "World")) + "\n");
        write("capitalize('hello'): " + capitalize("hello") + "\n");
        write("trim('  hello  '): '" + trim("  hello  ") + "'\n");
        
        return 1;

    } else if (arg == "foreach") {
        write("=== 測試 foreach (Array) ===\n");
        // 注意：依照你的 lexer，陣列可能是 [] 語法
        mixed arr = ["蘋果", "香蕉", "橘子"]; 
        
        foreach (item in arr) {
            write("陣列元素: " + item + "\n");
        }

        write("\n=== 測試 foreach (Mapping) ===\n");
        // 注意：依照你的 lexer，Mapping 是 ([ ]) 語法
        mixed map = ([ "HP": 100, "MP": 50 ]); 
        
        foreach (key, val in map) {
            write("屬性 " + key + ": " + sprintf("%d", val) + "\n");
        }
        
        return 1;
    }

    // 如果沒給參數，或者是打錯字
    write("請輸入: 'test string' 或 'test foreach'\n");
    return 1;
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
    } else if (arg == "info") {
        write("系統資訊：MudScript 引擎運作中。\n");
        return 1;
    } else if (arg == "quit") {
        write("下次見！\n");
        // 這裡未來可以呼叫斷線邏輯
        return 1;
    } else {
        return 0; // 回傳 0 讓底層接手處理「什麼？」
    }
}

void runtime_error(string msg, string file) {
    write("🔥 系統錯誤 [" + file + "]: " + msg + "\n");
}
