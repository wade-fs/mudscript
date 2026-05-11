#include "/include/config.h"

string current_id;
string current_pass;

void create() {
}

void logon() {
    string issue = read_file(ISSUE_FILE);
    if (issue) {
        write(issue);
    } else {
        write("\n連線成功！歡迎來到 MudScript 測試伺服器！\n");
    }
    write("\n請輸入您的帳號名稱 (若無帳號將自動註冊)：");
    input_to("get_id");
}

void get_id(string id) {
    if (!id) {
        write("帳號不能為空，請重新輸入：");
        input_to("get_id");
        return;
    }
    
    current_id = id;
    
    object temp_user = clone_object("/std/user.c");
    if (!temp_user) {
        write("致命錯誤：無法載入 /std/user.c\n");
        return;
    }
    
    // 如果是錯誤物件 (由 evaluator 產生的 Error)
    if (errorp(temp_user)) {
        write("載入 /std/user.c 發生錯誤：\n" + sprintf("%v", temp_user) + "\n");
        return;
    }

    temp_user->set_id(id);
    
    if (temp_user->restore() == 1) {
        write("歡迎回來，" + id + "！請輸入密碼：");
        input_to("check_pass", 1);
    } else {
        write("歡迎新玩家 " + id + "！為您的帳號設定密碼：");
        input_to("new_pass", 1);
    }
    
    destruct(temp_user);
}

void check_pass(string pass) {
    object user = clone_object("/std/user.c");
    user->set_id(current_id);
    user->restore();
    
    string saved_pass = user->get_password();
    string hashed_pass = crypt(pass);

    // 檢查密碼：符合加密後的密碼，或是符合舊版的明文密碼（向下相容）
    if (saved_pass == hashed_pass || saved_pass == pass) {
        
        // 【無縫升級】：如果是用舊版明文登入的，順手幫他升級成加密版
        if (saved_pass == pass) {
            user->set_password(hashed_pass);
            user->save();
        }

        if (exec(user, this_object())) {
            user->setup();
			if (!user->query_name()) {
                user->set_name(user->get_id());
            }
            write("\n登入成功！歡迎回來，" + user->query_name() + "。\n");
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
    if (!pass) {
        write("密碼不能為空，請重新設定密碼：");
        input_to("new_pass", 1);
        return;
    }

    current_pass = crypt(pass);
    
    write("請輸入您在遊戲中的暱稱：");
    input_to("get_nickname"); // 這裡不需要隱藏輸入，所以不加 1
}

void get_nickname(string nick) {
    if (!nick) {
        write("暱稱不能為空，請重新輸入您的暱稱：");
        input_to("get_nickname");
        return;
    }

    object user = clone_object("/std/user.c");
    user->set_id(current_id);
    user->set_password(current_pass);
    user->set_nickname(nick); // 呼叫 user.c 的新函式寫入暱稱
    
	string *files;
	files = get_dir("/data/user/*.o");
    if (!sizeof(files)) {
        user->set_role("god");
        user->add_write_path("/");        // god 擁有全部權限
        write("【創世神】您是本服第一位玩家，已自動獲得 god 權限！\n");
    } else {
        user->set_role("user");
		user->add_write_path(user->query_save_file());
    }

    if (exec(user, this_object())) {
        write("\n角色創建成功！歡迎來到這個世界，" + nick + "！\n");
        user->save();
        user->setup();
        destruct(this_object());
    } else {
        write("系統錯誤：無法轉移連線。\n");
        destruct(user);
    }
}
