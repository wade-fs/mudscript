// /secure/nature_d.c
// 共用氣候與時辰守護進程 (World-Agnostic Nature Daemon)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

int game_time;
int time_offset;
string current_weather;
string season_override;
string calendar_name;

string query_save_file() { return "/data/nature"; }

void create() {
    ::create();
    game_time = 300;
    time_offset = 0;
    current_weather = "clear";
    season_override = "";

    mapping mf = query_world_manifest();
    calendar_name = mf["calendar_name"] ? mf["calendar_name"] : "紀元曆";

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    if (!season_override) season_override = "";
    set_heart_beat(1);
}

mapping get_time_info() {
    int now_ts = time() + (time_offset * 15);
    return localtime(now_ts);
}

int query_hour() {
    mapping t = get_time_info();
    return t["hour"];
}

int is_day() {
    int h = query_hour();
    return (h >= 6 && h < 18);
}

string query_weather() {
    return current_weather;
}

string query_season() {
    if (season_override && season_override != "") return season_override;
    mapping t = get_time_info();
    int mon = t["mon"] + 1;
    if (mon >= 3 && mon <= 5) return "spring";
    if (mon >= 6 && mon <= 8) return "summer";
    if (mon >= 9 && mon <= 11) return "autumn";
    return "winter";
}

string query_shichen() {
    int h = query_hour();
    if (h >= 23 || h < 1)  return "子時";
    if (h >= 1  && h < 3)  return "丑時";
    if (h >= 3  && h < 5)  return "寅時";
    if (h >= 5  && h < 7)  return "卯時";
    if (h >= 7  && h < 9)  return "辰時";
    if (h >= 9  && h < 11) return "巳時";
    if (h >= 11 && h < 13) return "午時";
    if (h >= 13 && h < 15) return "未時";
    if (h >= 15 && h < 17) return "申時";
    if (h >= 17 && h < 19) return "酉時";
    if (h >= 19 && h < 21) return "戌時";
    return "亥時";
}

string query_weather_string() {
    string w = "晴朗";
    if (current_weather == "cloudy") w = "多雲";
    else if (current_weather == "rainy") w = "微雨";
    else if (current_weather == "storm") w = "風雨交加";
    else if (current_weather == "foggy") w = "薄霧瀰漫";
    else if (current_weather == "snowy") w = "飛雪紛飛";

    return sprintf("[%s %s | %s]", calendar_name, query_shichen(), w);
}

void heart_beat() {
    game_time++;
}
