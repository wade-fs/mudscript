// std/login.c - 通用登入物件 (World-Agnostic)
// 世界層可覆寫此檔案以自訂登入介面（歡迎畫面、語言選項等）

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object.c";

string current_id;
string current_pass;
string browser_lang;

void create() {
    ::create();
}

void set_browser_lang(string lang) { browser_lang = lang; }
string query_browser_lang()        { return browser_lang; }

string _t(string key) {
    string l = browser_lang ? browser_lang : "en";
    return load_object("/secure/language_d.c")->translate(key, l);
}

string resolve_start_room() {
    mapping mf = query_world_manifest();
    if (mapp(mf) && stringp(mf["start_room"]) && mf["start_room"] != "") {
        return mf["start_room"];
    }
    return START_ROOM;
}

void send_ui_init(string l) {
    object lang_d = load_object("/secure/language_d.c");
    object social_d = load_object("/secure/social_d.c");
    object cmd_d = load_object("/secure/command_d.c");

    if (social_d) {
        mapping socials = social_d->get_ui_list();
        write(sprintf("{\"ui\": \"socials\", \"title\": \"%s\", \"data\": %s}",
            lang_d ? lang_d->translate("label_actions", l) : "Socials", json_encode(socials)));
    }
    if (cmd_d) {
        mapping cmds = cmd_d->query_categorized_commands(l);
        write(sprintf("{\"ui\": \"cmd_list\", \"title\": \"%s\", \"data\": %s}",
            lang_d ? lang_d->translate("label_commands", l) : "Commands", json_encode(cmds)));
    }
}

void logon() {
    string l = browser_lang ? browser_lang : "en";
    send_ui_init(l);

    string issue_path = "/etc/issue." + l;
    string issue = "";
    if (file_size(issue_path) > 0) {
        issue = read_file(issue_path);
    } else if (file_size("/etc/issue") > 0) {
        issue = read_file("/etc/issue");
    }
    if (issue && issue != "") write(issue + "\n");

    write(_t("prompt_id") + " ");
    input_to("get_id");
}

void get_id(string input) {
    if (!input || input == "") {
        write(_t("prompt_id_empty") + " ");
        input_to("get_id");
        return;
    }
    current_id = lower_case(trim(input));
    write(_t("prompt_pass") + " ");
    input_to("get_pass", 1);
}

void get_pass(string input) {
    string hashed = crypt(input, 0);
    string save_path = "/data/user/" + current_id + ".o";

    if (file_size(save_path) > 0) {
        object user = clone_object("/std/user.c");
        user->set_id(current_id);
        if (!user->do_restore()) {
            destruct(user);
            write("載入角色資料失敗。\n");
            destruct(this_object());
            return;
        }
        if (user->query_password() != hashed) {
            destruct(user);
            write(_t("prompt_pass_wrong") + "\n");
            destruct(this_object());
            return;
        }
        write("歡迎回來，" + current_id + "！\n");
        exec(user, this_object());
        user->set_lang(browser_lang ? browser_lang : "zh-TW");
        string start = user->query_last_location() ? user->query_last_location() : resolve_start_room();
        object room = load_object(start);
        if (!room) room = load_object(resolve_start_room());
        if (room) move_object(user, room);
        user->do_look();

        object ui = find_object("/daemon/ui_bridge_d.c");
        if (!ui) ui = load_object("/daemon/ui_bridge_d.c");
        if (ui) {
            ui->push_room_view(user);
            ui->push_char_view(user);
            ui->push_quest_list(user);
        }
        destruct(this_object());
    } else {
        current_pass = hashed;
        write("建立新帳號：" + current_id + "\n請再次輸入密碼確認：");
        input_to("confirm_pass", 1);
    }
}

void confirm_pass(string input) {
    string hashed = crypt(input, 0);
    if (hashed != current_pass) {
        write("兩次輸入的密碼不一致。\n");
        destruct(this_object());
        return;
    }
    object user = clone_object("/std/user.c");
    user->set_id(current_id);
    user->set_password(current_pass);
    user->set_lang(browser_lang ? browser_lang : "zh-TW");
    if (master() && master()->is_creator(current_id)) {
        user->set_role("god");
    } else {
        user->set_role("player");
    }
    write("帳號建立完成！\n");
    exec(user, this_object());
    object room = load_object(resolve_start_room());
    if (room) move_object(user, room);
    user->do_look();
    user->do_save();

    object ui = find_object("/daemon/ui_bridge_d.c");
    if (!ui) ui = load_object("/daemon/ui_bridge_d.c");
    if (ui) {
        ui->push_room_view(user);
        ui->push_char_view(user);
        ui->push_quest_list(user);
    }
    destruct(this_object());
}
