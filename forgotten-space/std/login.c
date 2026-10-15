#include "/include/config.h"
#include "/include/ansi.h"
#include "/include/globals.h"
#include "/include/background.h"
#include "/include/race.h"

inherit "/std/object";

string current_id;
string current_pass;
string current_nick;
string current_race;
string current_nature;
string current_background;
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
    // 🚀 新增：立即發送 UI 初始化資訊給前端，不需要等登入完成
    string l = browser_lang;
    if (!l) l = "en";
    object lang_d = load_object("/secure/language_d.c");

    mapping socials = load_object("/secure/social_d.c")->get_ui_list();
    write(sprintf("{\"ui\": \"socials\", \"title\": \"%s\", \"data\": %s}", 
        lang_d->translate("label_actions", l), json_encode(socials)));

    mapping cmds = load_object("/secure/command_d.c")->query_categorized_commands(l);
    write(sprintf("{\"ui\": \"commands\", \"title\": \"%s\", \"data\": %s}", 
        lang_d->translate("label_commands", l), json_encode(cmds)));

    write("\n" + "$HIW$Welcome to MudScript World!$NOR$" + "\n");
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

    // 🚀 關鍵修正：語系切換後立即更新 UI 標籤
    object lang_d = load_object("/secure/language_d.c");
    mapping socials = load_object("/secure/social_d.c")->get_ui_list();
    write(sprintf("{\"ui\": \"socials\", \"title\": \"%s\", \"data\": %s}", 
        lang_d->translate("label_actions", lang), json_encode(socials)));

    mapping cmds = load_object("/secure/command_d.c")->query_categorized_commands(lang);
    write(sprintf("{\"ui\": \"commands\", \"title\": \"%s\", \"data\": %s}", 
        lang_d->translate("label_commands", lang), json_encode(cmds)));

    string issue = read_file(ISSUE_FILE + "." + lang);
    if (!issue) issue = read_file(ISSUE_FILE);

    if (issue) {
        write_raw(issue);
    } else {
        write("\n" + "$CYN$" + _t("welcome") + "$NOR$" + "\n");
    }
    write("\n" + _t("prompt_id") + " ");
    input_to("get_id");
}

void get_id(string id) {
    if (!id || id == "") {
        write("$RED$" + _t("prompt_id_empty") + "$NOR$" + " ");
        input_to("get_id");
        return;
    }
    
    current_id = id;
    
    object temp_user = clone_object("/std/user.c");
    if (!temp_user) {
        write("$RED$致命錯誤：無法載入 /std/user.c$NOR$" + "\n");
        return;
    }
    
    if (errorp(temp_user)) {
        write("$RED$載入 /std/user.c 發生錯誤：$NOR$" + "\n" + sprintf("%v", temp_user) + "\n");
        return;
    }

    temp_user->set_id(id);
    
    if (temp_user->restore() == 1) {
        write(_t("prompt_pass") + " ");
        input_to("check_pass", 1);
    } else {
        string msg = _t("prompt_new_pass");
        msg = replace_string(msg, "$id", "$YEL$" + id + "$NOR$");
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

    if (crypt(pass, saved_pass) == saved_pass || saved_pass == pass) {
        if (saved_pass == pass) {
            user->set_password(crypt(pass));
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
            write("\n" + "$RED$" + msg_login + "$NOR$" + "\n");
            destruct(this_object());
        } else {
            write("$RED$系統錯誤：無法轉移連線。$NOR$" + "\n");
            destruct(user);
        }
    } else {
        write("$RED$" + _t("prompt_pass_wrong") + "$NOR$" + " ");
        destruct(user);
        input_to("check_pass", 1);
    }
}

void new_pass(string pass) {
    if (!pass || pass == "") {
        write("$RED$" + _t("prompt_new_pass_empty") + "$NOR$" + " ");
        input_to("new_pass", 1);
        return;
    }

    current_pass = crypt(pass);
    write("請輸入您在遊戲中的暱稱：");
    input_to("get_nickname");
}

void get_nickname(string nick) {
    if (!nick || nick == "") {
        write("$RED$暱稱不能為空$NOR$" + "，請重新輸入您的暱稱：");
        input_to("get_nickname");
        return;
    }
    current_nick = nick;

    // ── 身世背景選擇 ──
    write("\n" + "$HIW$── 選擇您的身世背景 ──$NOR$" + "\n");
    mapping bgs = BACKGROUND_DATA;
    menu_keys = BACKGROUND_LIST;
    
    for (int i = 0; i < sizeof(menu_keys); i++) {
        string k = menu_keys[i];
        write(sprintf("[%d] %-10s : %s\n", i + 1, bgs[k]["name"], bgs[k]["desc"]));
    }
    write("請輸入編號或代號選擇身世背景：");
    input_to("get_background");
}

void get_background(string input) {
    mapping bgs = BACKGROUND_DATA;
    int idx = to_int(input);

    if (idx > 0 && idx <= sizeof(menu_keys)) {
        current_background = menu_keys[idx - 1];
    } else if (member_array(input, menu_keys) != -1) {
        current_background = input;
    } else {
        write("$RED$無效的選擇，請重新輸入：$NOR$");
        input_to("get_background");
        return;
    }

    current_race = "human";
    write("\n您選擇的身世背景：" + "$CYN$" + bgs[current_background]["name"] + "$NOR$" + "。\n");
    write("$HIY$隨身舊物：" + bgs[current_background]["item_desc"] + "$NOR$\n\n");
    
    create_character();
}

void create_character() {
    object user = clone_object("/std/user.c");
    user->set_id(current_id);
    user->set_password(current_pass);
    user->set_nickname(current_nick);
    user->set_race("human");
    user->set_background(current_background);
    user->set_lang(browser_lang);

    // 六維先天屬性皆從 1 點起步（符合世界規則 Rules）
    user->set_stat("str", 1);
    user->set_stat("con", 1);
    user->set_stat("int", 1);
    user->set_stat("spi", 1);
    user->set_stat("dex", 1);
    user->set_stat("per", 1);

    // 終極隱藏屬性 (Meta Attributes)
    user->set("fate", 1);
    user->set("kar", 10);

    user->set_level(1);
    user->recalc_stats();
    user->set_hp(user->query_max_hp());
    user->set_mp(user->query_max_mp());

    // 身世專屬隨身舊物發放
    mapping bg = BACKGROUND_DATA[current_background];
    if (bg && bg["item"]) {
        object item_ob = clone_object(bg["item"]);
        if (item_ob) {
            move_object(item_ob, user);
        }
    }

    string *files = get_dir("/data/user/*.o");
    if (!sizeof(files)) {
        user->set_role("god");
        user->add_write_path("/");
        write("$MAG$【天命初臨】您是本世界第一位降臨者，已獲賜 god 管理權限！$NOR$\n");
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
        write("\n" + "$RED$" + msg_login + "$NOR$" + "\n");
        user->save();
        user->setup();
        destruct(this_object());
    } else {
        write("$RED$系統錯誤：無法轉移連線。$NOR$" + "\n");
        destruct(user);
    }
}
