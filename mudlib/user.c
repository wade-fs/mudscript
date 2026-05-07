// mudlib/user.c

string query_name() { return "你"; }

void create() {
	set_heart_beat(1);
}

void heart_beat() {
	write("💓 心跳跳動中... 現在時間: " + sprintf("%d", time()) + "\n");
}

// 登入後的第一個動作
void setup() {
    enable_commands();
    add_action("do_quit", "quit");
    add_action("do_quit", "exit");
    add_action("do_look", "look");
    add_action("do_smile", "smile");
    add_action("do_test", "test");

    object start_room = clone_object("/start.c");
    move_object(start_room);
    start_room->look_room();
}

void init() {
}

// 處理退出的邏輯
int do_quit(string arg) {
    object me = this_object();
    write("你化為一道光芒，離開了這個世界。\n");
    say(query_name() + " 離開了遊戲。\n");
    
    write("DEBUG: this_object() = " + object_name(me) + "\n");
    
    destruct(me);   // 明確傳入自己
    
    return 1;
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
	} else if (arg == "inherit") {
        // 動態複製出一個 start 房間
        object start_room = clone_object("/start.c");
        
        write("成功複製房間！嘗試呼叫父類別繼承來的 look_room()：\n");
        // 呼叫這間房間的 look_room (這是從 room.c 繼承來的)
        start_room->look_room();
        
        // 為了測試，把玩家「移動」進去，看看 init() 有沒有觸發
        write("\n把你丟進這個房間！\n");
        move_object(start_room); // 觸發 init，獲得 jump 指令
        
        return 1;
	} else if (arg == "object") {
        write("=== 測試物件查詢 Efuns ===\n");
        
        // 自己(master)的檔名
        write("1. 我的名字 (object_name): " + object_name(this_object()) + "\n");
        
        // 尋找 master 是否存在
        object m = find_object("/master.c");
        if (m) {
			write("2. 成功用 find_object 找到 master！\n");
		}
        
        // 狀態判斷
        write("3. 玩家 (this_player) 是活物嗎 (living)? " + sprintf("%d", living(this_player())) + "\n");
        write("4. 玩家是連線狀態嗎 (interactive)? " + sprintf("%d", interactive(this_player())) + "\n");
        
        // 測試 Inventory
        write("5. 我的背包目前裝了幾個東西 (sizeof all_inventory)? " + 
              sprintf("%d", sizeof(all_inventory(this_object()))) + "\n");

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
