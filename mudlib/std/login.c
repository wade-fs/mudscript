#include "/include/config.h"
#include "/include/ansi.h"
#include "/include/race.h"

inherit "/std/object";

string current_id;
string current_pass;
string current_nick;
string current_race;
string current_nature;
string browser_lang; // 🚀 新增

void create() {
    ::create();
}

void set_browser_lang(string lang) { browser_lang = lang; }

// 🚀 新增：覆寫 _t 以便在登入階段正確使用偵測到的語系
string _t(string key) {
    string l = browser_lang;
    if (!l) l = "en";
    return load_object("/secure/language_d.c")->translate(key, l);
}

void logon() {
    string lang = browser_lang;
    if (!lang || lang == "") lang = "en";
    if (strsrch(lang, "zh-") == 0) {
        if (lang == "zh-CN") lang = "zh-CN";
        else lang = "zh-TW";
    } else {
        lang = "en";
    }

    string issue = read_file(ISSUE_FILE + "." + lang);
    if (!issue) issue = read_file(ISSUE_FILE);

    if (issue) {
        write(issue);
    } else {
        write("\n" + CYAN(_t("welcome")) + "\n");
    }
    write("\n" + _t("prompt_id") + " ");
    input_to("get_id");
}

void get_id(string id) {
    if (!id || id == "") {
        write(RED(_t("prompt_id_empty")) + " ");
        input_to("get_id");
        return;
    }
    
    current_id = id;
    
    object temp_user = clone_object("/std/user.c");
    if (!temp_user) {
        write(RED("致命錯誤：無法載入 /std/user.c") + "\n");
        return;
    }
    
    if (errorp(temp_user)) {
        write(RED("載入 /std/user.c 發生錯誤：") + "\n" + sprintf("%v", temp_user) + "\n");
        return;
    }

    temp_user->set_id(id);
    
    if (temp_user->restore() == 1) {
        write(_t("prompt_pass") + " ");
        input_to("check_pass", 1);
    } else {
        string msg = _t("prompt_new_pass");
        msg = replace_string(msg, "$id", YELLOW(id));
        write(msg + " ");
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

    if (saved_pass == hashed_pass || saved_pass == pass) {
        if (saved_pass == pass) {
            user->set_password(hashed_pass);
            user->save();
        }

        if (exec(user, this_object())) {
            user->setup();
			if (!user->query_name()) {
                user->set_name(user->get_id());
            }
            
            // 🚀 新增：初始化語系
            if (!user->query_lang()) {
                user->set_lang(browser_lang);
            }

            string msg = _t("login_success");
            msg = replace_string(msg, "$name", user->query_name());
            write("\n" + GREEN(msg) + "\n");
            destruct(this_object());
        } else {
            write(RED("系統錯誤：無法轉移連線。") + "\n");
            destruct(user);
        }
    } else {
        write(RED(_t("prompt_pass_wrong")) + " ");
        destruct(user);
        input_to("check_pass", 1);
    }
}

void new_pass(string pass) {
    if (!pass || pass == "") {
        write(RED(_t("prompt_new_pass_empty")) + " ");
        input_to("new_pass", 1);
        return;
    }

    current_pass = crypt(pass);
    write("請輸入您在遊戲中的暱稱：");
    input_to("get_nickname");
}

void get_nickname(string nick) {
    if (!nick) {
        write(RED("暱稱不能為空") + "，請重新輸入您的暱稱：");
        input_to("get_nickname");
        return;
    }
    current_nick = nick;

    // 開始選擇種族
    write("\n" + BOLD_WHT("── 選擇您的種族 ──") + "\n");
    mapping races = RACE_DATA;
    string *ks = keys(races);
    for (int i = 0; i < sizeof(ks); i++) {
        write(sprintf("[%d] %-10s : %s\n", i + 1, races[ks[i]]["name"], races[ks[i]]["desc"]));
    }
    write("請輸入編號或名稱選擇種族：");
    input_to("get_race");
}

void get_race(string input) {
    mapping races = RACE_DATA;
    string *ks = keys(races);
    int idx = to_int(input);

    if (idx > 0 && idx <= sizeof(ks)) {
        current_race = ks[idx - 1];
    } else if (member_array(input, ks) != -1) {
        current_race = input;
    } else {
        write(RED("無效的選擇，請重新輸入："));
        input_to("get_race");
        return;
    }

    write("\n您選擇了 " + CYAN(races[current_race]["name"]) + "。\n");
    
    // 開始選擇天性
    write("\n" + BOLD_WHT("── 選擇您的天性 ──") + "\n");
    mapping natures = NATURE_DATA;
    string *n_ks = keys(natures);
    for (int i = 0; i < sizeof(n_ks); i++) {
        write(sprintf("[%d] %-10s : %s\n", i + 1, natures[n_ks[i]]["name"], natures[n_ks[i]]["desc"]));
    }
    write("請輸入編號或名稱選擇天性：");
    input_to("get_nature");
}

void get_nature(string input) {
    mapping natures = NATURE_DATA;
    string *ks = keys(natures);
    int idx = to_int(input);

    if (idx > 0 && idx <= sizeof(ks)) {
        current_nature = ks[idx - 1];
    } else if (member_array(input, ks) != -1) {
        current_nature = input;
    } else {
        write(RED("無效的選擇，請重新輸入："));
        input_to("get_nature");
        return;
    }

    write("\n您選擇了 " + CYAN(natures[current_nature]["name"]) + "。\n");
    
    create_character();
}

void create_character() {
    object user = clone_object("/std/user.c");
    user->set_id(current_id);
    user->set_password(current_pass);
    user->set_nickname(current_nick);
    user->set_race(current_race);
    user->set_nature(current_nature);
    user->set_lang(browser_lang); // 🚀 繼承瀏覽器語系

    // 套用種族與天性的屬性加成
    mapping r_data = RACE_DATA[current_race];
    mapping n_data = NATURE_DATA[current_nature];
    mapping r_stats = r_data["stats"];
    mapping n_stats = n_data["stats"];

    string *stats = ({ "str", "dex", "int", "con", "wis", "cha" });
    foreach (string s in stats) {
        int base = 10;
        if (r_stats[s]) base += r_stats[s];
        if (n_stats[s]) base += n_stats[s];
        user->set_stat(s, base);
    }

    // 給予初始技能
    string *skills = n_data["skills"];
    if (skills) {
        foreach (string sk in skills) {
            user->set_skill(sk, 1); // 初始等級 1
        }
    }
    
    user->set_level(1);
    user->set_hp(user->query_max_hp());
    user->set_mp(user->query_max_mp());

	string *files;
	files = get_dir("/data/user/*.o");
    if (!sizeof(files)) {
        user->set_role("god");
        user->add_write_path("/");
        write(MAGENTA("【創世神】您是本服第一位玩家，已自動獲得 god 權限！") + "\n");
    } else {
        user->set_role("user");
		user->add_write_path(user->query_save_file());
    }

    if (exec(user, this_object())) {
        write("\n" + GREEN("角色創建成功！歡迎來到這個世界，" + current_nick + "！") + "\n");
        user->save();
        user->setup();
        destruct(this_object());
    } else {
        write(RED("系統錯誤：無法轉移連線。") + "\n");
        destruct(user);
    }
}
