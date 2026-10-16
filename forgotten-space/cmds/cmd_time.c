// /cmds/cmd_time.c
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    object nature_d = load_object("/secure/nature_d.c");
    if (!nature_d) {
        write("無法載入時間守護進程。\n");
        return 1;
    }

    int year = nature_d->query_calendar_year();
    int month = nature_d->query_calendar_month();
    int day = nature_d->query_calendar_day();
    string title = nature_d->query_year_season_title();
    string cycle = nature_d->query_cycle_name();
    string shichen = nature_d->query_shichen_full();
    int hour = nature_d->query_hour();
    int min = nature_d->query_minute();
    string weather = nature_d->query_weather_name();
    int ratio = nature_d->query_time_ratio();

    string res = "";
    res += WHT "============================================================\n" NOR;
    res += HIY "              📜 《遺忘的世界》周天四序時曆               \n" NOR;
    res += WHT "============================================================\n" NOR;
    res += sprintf(CYN "  太古紀年：" NOR + HIW "遺忘曆 %d 年 %02d 月 %02d 日 " NOR + YEL "【%s】\n" NOR,
                   year, month, day, title);
    res += sprintf(CYN "  當前時辰：" NOR + HIG "%s " NOR + WHT "(%02d:%02d)\n" NOR, shichen, hour, min);
    res += sprintf(CYN "  天地氣象：" NOR + HIW "%s\n" NOR, weather);
    res += WHT "------------------------------------------------------------\n" NOR;
    res += YEL "  周天四序輪元（太古乾坤律度・每日歷經四十八時辰）：\n" NOR;
    
    string c0_mark = (cycle == "元") ? HIG " 👉 " NOR : "    ";
    string c1_mark = (cycle == "亨") ? HIG " 👉 " NOR : "    ";
    string c2_mark = (cycle == "利") ? HIG " 👉 " NOR : "    ";
    string c3_mark = (cycle == "貞") ? HIG " 👉 " NOR : "    ";

    res += sprintf("%s" CYN "【元】00:00 - 05:59" NOR "：一元復始，胚萌破曉 (元子時 ~ 元亥時)\n", c0_mark);
    res += sprintf("%s" CYN "【亨】06:00 - 11:59" NOR "：晨曦通暢，品物流形 (亨子時 ~ 亨亥時)\n", c1_mark);
    res += sprintf("%s" CYN "【利】12:00 - 17:59" NOR "：日斜金風，各正性命 (利子時 ~ 利亥時)\n", c2_mark);
    res += sprintf("%s" CYN "【貞】18:00 - 23:59" NOR "：暮夜歸根，太和守正 (貞子時 ~ 貞亥時)\n", c3_mark);
    res += WHT "------------------------------------------------------------\n" NOR;
    res += sprintf(MAG "  流速法則：%d : 1 (15 秒現實 = 1 遊戲分；三月即一歲，一歲專一季)\n" NOR, ratio);
    res += WHT "============================================================\n" NOR;

    write(res);
    return 1;
}

string help() {
    return "查看目前的遊戲時間、氣候與流速比例。\n";
}
