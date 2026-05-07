// mudlib/master.c

string get_root_uid() { return "Root"; }
string get_bb_uid() { return "Backbone"; }

// 當有新連線進入時，Driver 會呼叫此函式
object connect() {
    write("透過 Master 建立新連線...\n");
    // 這裡通常會 clone 一個 login 物件，現在我們先回傳 master 自己作為測試
    return this_object(); 
}

// 處理 process_input (當玩家在 telnet 輸入文字時)
void process_input(string arg) {
    if (arg == "help") {
        write("指令列表：help, quit, info\n");
    } else {
        write("你說了：" + arg + "\n");
    }
}

void runtime_error(string msg, string file) {
    write("🔥 系統錯誤 [" + file + "]: " + msg + "\n");
}
