inherit "/std/object";

string current_user_id;

void create() {
    ::create();
}

void logon() {
    write("請輸入您的帳號：");
    input_to("get_id"); // 攔截下次輸入
}

void get_id(string id) {
    current_user_id = id;
    
    // 檢查檔案是否存在
    if (file_size("/data/user/" + id + ".o") > 0) {
        write("請輸入密碼：");
        input_to("get_pass");
    } else {
        write("未註冊的帳號。請設定新密碼：");
        input_to("new_pass");
    }
}

// 驗證密碼後，進入遊戲
void enter_world() {
    object user;
    
    // 1. 產生實體
    user = clone_object("/cmds/user.c");
    
    // 2. 設定 ID 並讀取存檔
    user->set_id(current_user_id);
    user->restore(); 
    
    // 3. 轉移連線！(this_object() 是 login.c，user 是 user.c)
    if (exec(user, this_object())) {
        write("歡迎進入遊戲世界！\n");
        user->setup_player(); // 初始化玩家狀態
        destruct(this_object()); // 毀滅 login 物件
    } else {
        write("連線轉移失敗。\n");
        destruct(user);
    }
}
