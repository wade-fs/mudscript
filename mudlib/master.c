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

// ==========================================
// 陣列測試用的輔助函式 (字串呼叫法)
// ==========================================
int is_even(int x) {
    return x % 2 == 0;
}

int multi_ten(int x) {
    return x * 10;
}

int sort_desc(int a, int b) {
    // 降冪排序：回傳 < 0 代表 a 要排在 b 前面
    return b - a; 
}

string get_first_char(string word) {
    return substr(word, 0, 1);
}

int double_value(string k, int v) {
    // 把所有的 value 乘以 2
    return v * 2;
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
	} else if (arg == "array") {
        mixed arr = [1, 2, 3, 4, 5];
        write("=== 測試陣列 Efuns ===\n");
        write("原始陣列: " + sprintf("%O", arr) + "\n\n");

        // 1. filter 與 map (字串回呼法)
        write("[字串寫法] filter (找偶數): " + sprintf("%O", filter(arr, "is_even")) + "\n");
        write("[字串寫法] map (全部乘 10): " + sprintf("%O", map(arr, "multi_ten")) + "\n\n");

        // 2. filter 與 map (閉包寫法) 
        // 註: 若你的 Parser 已經支援 $1 語法，這裡可以解開註解測試
        // write("[閉包寫法] filter (大於2): " + sprintf("%O", filter(arr, (: $1 > 2 :))) + "\n");
        // write("[閉包寫法] map (加 100): " + sprintf("%O", map(arr, (: $1 + 100 :))) + "\n\n");

        // 3. sort_array 排序
        mixed unsorted = [8, 3, 7, 1, 4];
        write("未排序陣列: " + sprintf("%O", unsorted) + "\n");
        write("sort_array (由大到小): " + sprintf("%O", sort_array(unsorted, "sort_desc")) + "\n\n");

        // 4. member_array 尋找
        write("member_array (找數字 7): " + sprintf("%d", member_array(7, unsorted)) + "\n");
        write("member_array (找數字 99): " + sprintf("%d", member_array(99, unsorted)) + "\n\n");

        // 5. unique_array 分組
        mixed words = ["apple", "ant", "banana", "bear", "cat"];
        write("原始單字: " + sprintf("%O", words) + "\n");
        write("unique_array (依字首分組):\n" + sprintf("%O", unique_array(words, "get_first_char")) + "\n");

        return 1;
	} else if (arg == "mapping") {
        write("=== 測試 Mapping Efuns ===\n");
        
        mixed stats = ([ "STR": 15, "DEX": 18, "INT": 12 ]);
        write("原始狀態: " + sprintf("%O", stats) + "\n\n");

        // 1. keys 和 values
        write("所有的 Keys: " + sprintf("%O", keys(stats)) + "\n");
        write("所有的 Values: " + sprintf("%O", values(stats)) + "\n\n");

        // 2. m_delete (刪除 INT)
        m_delete(stats, "INT");
        write("刪除 INT 後: " + sprintf("%O", stats) + "\n");

        // 3. m_add (新增 CON)
        m_add(stats, "CON", 16);
        // 也修改一下 DEX
        stats["DEX"] = 20; 
        write("新增 CON 並修改 DEX 後: " + sprintf("%O", stats) + "\n\n");

        // 4. map_mapping (全部乘以 2)
        mixed buffed_stats = map_mapping(stats, "double_value");
        write("Map_Mapping (狀態數值加倍): " + sprintf("%O", buffed_stats) + "\n");
        // 證明 map_mapping 不會改到原本的資料
        write("原狀態依舊是: " + sprintf("%O", stats) + "\n");

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
