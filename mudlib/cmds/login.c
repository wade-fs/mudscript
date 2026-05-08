string current_id;
string current_pass;

void create() {
}

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
    
    object temp_user = clone_object("/std/user.c");
    temp_user->set_id(id);
    
    if (temp_user->restore() == 1) {
        write("歡迎回來，" + id + "！請輸入密碼：");
        input_to("check_pass", 1);
    } else {
        write("歡迎新玩家！為您的帳號設定密碼：");
        input_to("new_pass", 1);
    }
    
    destruct(temp_user);
}

void check_pass(string pass) {
    object user = clone_object("/std/user.c");
    user->set_id(current_id);
    user->restore();
    
    if (user->get_password() == pass) {
        if (exec(user, this_object())) {
            write("\n登入成功！歡迎回來，" + user->query_name() + "。\n");
            user->setup_player();
            destruct(this_object());
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

    current_pass = pass;
    write("請輸入您在遊戲中的暱稱：");
    input_to("get_nickname"); // 這裡不需要隱藏輸入，所以不加 1
}

void get_nickname(string nick) {
    if (nick == "") {
        write("暱稱不能為空，請重新輸入您的暱稱：");
        input_to("get_nickname");
        return;
    }

    object user = clone_object("/std/user.c");
    user->set_id(current_id);
    user->set_password(current_pass);
    user->set_nickname(nick); // 呼叫 user.c 的新函式寫入暱稱
    
    if (exec(user, this_object())) {
        write("\n角色創建成功！歡迎來到這個世界，" + nick + "！\n");
        user->save(); // 立刻存檔，把帳號、密碼、暱稱全寫入 JSON
        user->setup_player();
        destruct(this_object());
    } else {
        write("系統錯誤：無法轉移連線。\n");
        destruct(user);
    }
}
