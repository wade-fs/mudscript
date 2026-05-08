string current_id;

void create() {
    // 初始化
}

// Driver 會在連線成功後自動呼叫這裡
void logon() {
    write("\n請輸入您的帳號名稱 (若無帳號將自動註冊)：");
    input_to("get_id");
}

void get_id(string id) {
    if (id == "") {
        write("帳號不能為空，請重新輸入：");
        input_to("get_id");
        return;
    }
    
    current_id = id;
    
    // 建立一個暫時的 user 來試著讀取存檔
    object temp_user = clone_object("/std/user.c");
    temp_user->set_id(id);
    
    // 如果 restore_object 成功 (回傳 1)，代表是老玩家
    if (temp_user->restore() == 1) {
        write("歡迎回來，" + id + "！請輸入密碼：");
        input_to("check_pass", 1);
    } else {
        // 找不到存檔，代表是新玩家創角
        write("歡迎新玩家！為您的帳號設定密碼：");
        input_to("new_pass", 1);
    }
    
    destruct(temp_user); // 檢查完就摧毀暫時物件
}

void check_pass(string pass) {
    object user = clone_object("/cmds/user.c");
    user->set_id(current_id);
    user->restore();
    
    if (user->get_password() == pass) {
        // 密碼正確，轉移連線！
        if (exec(user, this_object())) {
            write("\n登入成功！\n");
            user->setup_player();
            destruct(this_object()); // 毀滅 login 物件
        } else {
            write("系統錯誤：無法轉移連線。\n");
            destruct(user);
        }
    } else {
        write("密碼錯誤，請重新輸入密碼：");
        destruct(user);
        input_to("check_pass", 1);
    }
}

void new_pass(string pass) {
    if (pass == "") {
        write("密碼不能為空，請重新設定密碼：");
        input_to("new_pass", 1);
        return;
    }

    object user = clone_object("/cmds/user.c");
    user->set_id(current_id);
    user->set_password(pass); // user.c 必須實作這個函式
    
    // 轉移連線並立刻存檔
    if (exec(user, this_object())) {
        write("\n角色創建成功！\n");
        user->save(); // 寫入硬碟
        user->setup_player();
        destruct(this_object());
    } else {
        write("系統錯誤：無法轉移連線。\n");
        destruct(user);
    }
}
void runtime_error(string err_msg, string file) {
    write("【系統嚴重警告】執行期錯誤！\n");
    write("檔案：" + file + "\n");
    write("訊息：" + err_msg + "\n");
}
