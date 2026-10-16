// /cmds/cmd_time.c
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    object nature_d = load_object("/secure/nature_d.c");
    write(_t("current_game_time") + "：" + nature_d->query_weather_string() + "\n");
    write(_t("total_game_minutes") + "：" + nature_d->query_game_time() + "\n");
    int ratio = nature_d ? nature_d->query_time_ratio() : 4;
    write(sprintf(CYN "時間流速比例：%d : 1（15 秒真實時間 = 1 遊戲分鐘，6 小時 = 1 完整晝夜）\n" NOR, ratio));
    return 1;
}

string help() {
    return "查看目前的遊戲時間、氣候與流速比例。\n";
}
