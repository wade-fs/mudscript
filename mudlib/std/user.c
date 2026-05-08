inherit "/std/living";

string id;
string password; // 會被 save_object 自動存起來
int exp;         // 會被 save_object 自動存起來

// 暫時變數 (不存檔)
string _temp_status; 

void set_id(string i) { id = i; }
string get_id() { return id; }

// 封裝存取方法
void save() {
    save_object("/data/user/" + id);
}

void restore() {
    restore_object("/data/user/" + id);
}

void setup_player() {
    enable_commands(); // 讓玩家可以輸入指令
    move_object(load_object("/d/start_room")); // 把玩家丟到新手村
}

// 當玩家輸入 quit 時觸發
int quit() {
    save(); // 離開前存檔
    write("存檔完畢，下次見。\n");
    destruct(this_object());
    return 1;
}
