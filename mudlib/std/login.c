#include "/include/config.h"
#include "/include/ansi.h"
#include "/include/race.h"

inherit "/std/object";

string current_id;
string current_pass;
string current_nick;
string current_race;
string current_nature;
string browser_lang;
string *menu_keys; // 🚀 新增：追蹤當前選單的 Key 順序

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
    write("\n" + HIW("Welcome to MudScript World!") + "\n");
    write("Please select your language / 請選擇您的語系：\n");
    write("[1] English\n");
    write("[2] 繁體中文 (Traditional Chinese)\n");
    write("[3] 简体中文 (Simplified Chinese)\n");
    write("Selection: ");
    input_to("get_language");
}

void get_language(string input) {
    switch(input) {
        case "1": browser_lang = "en"; break;
        case "2": browser_lang = "zh-TW"; break;
        case "3": browser_lang = "zh-CN"; break;
        default:  browser_lang = "en"; break;
    }

    string lang = browser_lang;
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
            // 🚀 關鍵修正：不論舊檔語系為何，一律強制同步為本次登入所選語系
            user->set_lang(browser_lang);
            
            user->setup();
			if (!user->query_name()) {
                user->set_name(user->get_id());
            }

            string msg_login = load_object("/secure/language_d.c")->translate("login_success", user->query_lang());
            msg_login = replace_string(msg_login, "$name", user->query_name());
            write("\n" + GREEN(msg_login) + "\n");
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
    if (!nick || nick == "") {
        write(RED("暱稱不能為空") + "，請重新輸入您的暱稱：");
        input_to("get_nickname");
        return;
    }
    current_nick = nick;

    // 開始選擇種族
    write("\n" + BOLD_WHT("── 選擇您的種族 ──") + "\n");
    mapping races = RACE_DATA;
    // 🚀 關鍵修正：使用穩定的排序，並將結果存入變數
    menu_keys = sort_array(keys(races), (: $1 > $2 ? 1 : -1 :));
    
    for (int i = 0; i < sizeof(menu_keys); i++) {
        string k = menu_keys[i];
        write(sprintf("[%d] %-10s : %s\n", i + 1, races[k]["name"], races[k]["desc"]));
    }
    write("請輸入編號或名稱選擇種族：");
    input_to("get_race");
}

void get_race(string input) {
    mapping races = RACE_DATA;
    int idx = to_int(input);

    if (idx > 0 && idx <= sizeof(menu_keys)) {
        current_race = menu_keys[idx - 1];
    } else if (member_array(input, menu_keys) != -1) {
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
    // 🚀 關鍵修正：更新為天性的排序 Key
    menu_keys = sort_array(keys(natures), (: $1 > $2 ? 1 : -1 :));
    
    for (int i = 0; i < sizeof(menu_keys); i++) {
        string k = menu_keys[i];
        write(sprintf("[%d] %-10s : %s\n", i + 1, natures[k]["name"], natures[k]["desc"]));
    }
    write("請輸入編號或名稱選擇天性：");
    input_to("get_nature");
}

void get_nature(string input) {
    mapping natures = NATURE_DATA;
    int idx = to_int(input);

    if (idx > 0 && idx <= sizeof(menu_keys)) {
        current_nature = menu_keys[idx - 1];
    } else if (member_array(input, menu_keys) != -1) {
        current_nature = input;
    } else {
        write(RED("無效的選擇，請重新輸入："));
        input_to("get_nature");
        return;
    }

    write("\n您選擇了 " + CYAN(natures[current_nature]["name"]) + "。\n");
    
    string *files = get_dir("/data/user/*.o");
    if (!sizeof(files)) {
        write("\n" + HIW("【系統初始化】") + "\n");
        write("偵測到您是本伺服器第一位玩家，請為您的 MUD 伺服器命名。\n");
        write("命名規則：最多四個英文單字，總長最多 64 個字母。\n");
        write("例如：fantasy space\n");
        write("請輸入伺服器名稱：");
        input_to("get_mudlib_name");
        return;
    }
    
    create_character();
}

void get_mudlib_name(string input) {
    if (!input || input == "") {
        write(RED("名稱不能為空，請重新輸入："));
        input_to("get_mudlib_name");
        return;
    }
    if (strlen(input) > 64) {
        write(RED("名稱太長（最多 64 字母），請重新輸入："));
        input_to("get_mudlib_name");
        return;
    }

    string id = lower_case(input);
    id = replace_string(id, " ", ".");

    // 🛑 核心驗證：保留字元與官方伺服器防撞名
    if (id == "fantasy.space") {
        write(RED("⚠️ 註冊失敗：『fantasy.space』為官方星際中心保留名稱，請使用其他名稱！\n"));
        write("請重新輸入伺服器名稱：");
        input_to("get_mudlib_name");
        return;
    }

    object system_d = load_object("/secure/system_d.c");
    if (system_d) {
        system_d->set_mudlib_name(input, id);
    }

    write(HIW("[Fantasy Space] ") + "伺服器已命名為：" + HIY(input) + "，識別字為：" + HIY(id) + "\n");
    
    create_character();
}

void create_character() {
    object user = clone_object("/std/user.c");
    user->set_id(current_id);
    user->set_password(current_pass);
    user->set_nickname(current_nick);
    user->set_race(current_race);
    user->set_nature(current_nature);
    user->set_lang(browser_lang); // 🚀 繼承選擇語系

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

    string *files = get_dir("/data/user/*.o");
    if (!sizeof(files)) {
        user->set_role("god");
        user->add_write_path("/");
        write(MAGENTA("【創世神】您是本服第一位玩家，已自動獲得 god 權限！") + "\n");
        string id = load_object("/secure/system_d.c")->query_mudlib_id();
        write(HIW("[Fantasy Space] ") + "本 mudlib 識別字為：" + HIY(id) + "\n");
        write(HIW("[Fantasy Space] ") + "你的跨服身份為：" + HIY(user->get_id() + "@" + id) + "\n");
        write(HIW("[Fantasy Space] ") + "使用 fsjoin <mudlib_id> 連接其他伺服器。\n");
    } else {
        user->set_role("user");
        user->add_write_path(user->query_save_file());
    }

    finish_create_character(user);
}

void finish_create_character(object user) {
    if (exec(user, this_object())) {
        string lang = user->query_lang() ? user->query_lang() : browser_lang;
        string msg_login = load_object("/secure/language_d.c")->translate("login_success", lang);
        msg_login = replace_string(msg_login, "$name", user->query_name());
        write("\n" + GREEN(msg_login) + "\n");
        user->save();
        user->setup();
        destruct(this_object());
    } else {
        write(RED("系統錯誤：無法轉移連線。") + "\n");
        destruct(user);
    }
}
