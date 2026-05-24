// /cmds/cmd_fsgoto.c
// 透過傳送門前往遠端 mudlib

#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("用法：fsgoto <mudlib_id>\n");
        return 1;
    }

    // 🚀 特化處理：去除雙引號，並將空格轉換為點（ID 格式）
    arg = trim(arg);
    if (strlen(arg) > 2 && arg[0] == '"' && arg[strlen(arg)-1] == '"') {
        arg = substr(arg, 1, strlen(arg)-2);
    }
    arg = replace_string(arg, " ", ".");

    object fs_d = load_object("/secure/fs_d.c");
    if (!fs_d) {
        write("系統錯誤：無法載入跨服守護進程。\n");
        return 1;
    }

    mapping joined = fs_d->query_joined_muds();
    if (!joined || !joined[arg]) {
        write("你尚未加入 " + arg + "，請先使用 fsjoin 指令加入。\n");
        return 1;
    }

    if (joined[arg]["status"] != "active") {
        write("該伺服器尚未完全上線或正在同步中，請稍後再試。\n");
        return 1;
    }

    string entrance = joined[arg]["entrance"];
    if (!entrance || entrance == "") {
        write("無法取得該伺服器的入口點。\n");
        return 1;
    }

    write(HIM("【傳送門】你踏入了一陣扭曲的光芒中，前往了星際網路的彼端...\n"));
    
    // 呼叫 get_remote_room 進行懶加載或取得房間
    object dest = fs_d->get_remote_room(arg, entrance);
    if (dest) {
        me->move(dest, "portal");
        dest->look_room(me);
    } else {
        write(RED("傳送失敗：無法載入目標房間。\n"));
    }

    return 1;
}

string help() {
    return "【指令】\n  fsgoto <mudlib_id>   透過星際傳送門前往已加入的遠端伺服器。\n";
}
