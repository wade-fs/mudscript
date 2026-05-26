// /cmds/cmd_fsgoto.c
// 跨服傳送指令：fsgoto <mudlib_id>
// 讓玩家真正「出現」在遠方世界中，而非只能透過 fs 頻道說話。

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    arg = trim(arg);

    if (!arg || arg == "") {
        write(HIW("【Fantasy Space 跨服傳送】\n") +
              "用法：fsgoto <mudlib_id>\n\n" +
              "效果：你將被傳送到指定 mudlib 的入口，並真正出現在那個世界中。\n" +
              "      對方的玩家將能看見你、和你說話、看到你的行動。\n\n" +
              "使用 " + CYAN("fs list") + " 查詢可抵達的星際節點。\n");
        return 1;
    }

    // 特殊指令：fsgoto home — 返回本機
    if (arg == "home" || arg == "back") {
        _do_return_home(me);
        return 1;
    }

    // 使用新的 Distributed Object Model
    object dist_d = load_object("/secure/dist_d.c");
    if (!dist_d) {
        write(RED("系統錯誤：無法載入 dist_d。\n"));
        return 1;
    }

    dist_d->start_fsgoto(me, arg);
    return 1;
}

// 返回本機
void _do_return_home(object me) {
    object env = environment(me);
    if (env && env->is_proxy_room()) {
        write(HIM("【傳送門】你切斷了分散式連結，返回了本地伺服器...\n"));
        object home = load_object(START_ROOM);
        if (home) {
            me->move(home, "portal");
            home->look_room(me);
        }
        // 銷毀 Proxy Room
        destruct(env);
        return;
    }

    // 備援：原有的 fs_d 邏輯
    object fs_d = find_object("/secure/fs_d.c");

string *query_verbs() { return ({ "fsgoto" }); }
string query_category() { return "Travel"; }

string help() {
    return "【Fantasy Space 跨服傳送】\n" +
           "  fsgoto <mudlib_id>   傳送到指定的遠端伺服器，真正出現在那個世界中。\n" +
           "  fsgoto home          返回本機伺服器。\n\n" +
           "進入遠端世界後：\n" +
           "  - 你會在對方房間的 inventory 中顯示為「星際旅人」\n" +
           "  - 你說的話會出現在對方的房間裡\n" +
           "  - 你可以看到對方房間已有的本地玩家和遠端旅人\n";
}
