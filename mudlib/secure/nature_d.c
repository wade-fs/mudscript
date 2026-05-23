// /secure/nature_d.c
// 氣候與時間守護進程 (Nature Daemon)

#include "/include/ansi.h"

inherit "/std/object";

// 遊戲時間與現實時間的比例
// 預設 1 真實秒 = 1 遊戲分鐘 (1440 遊戲分 = 24 遊戲小時 = 24 真實分)
#define TIME_RATIO 60

// 變數定義
int game_time;          // 遊戲總分鐘數
string current_weather; // 目前天氣
int last_update;        // 上次更新天氣的時間

// 天氣清單
string *weather_types = ({ "clear", "cloudy", "rainy", "foggy", "snowy" });

void create() {
    ::create();
    game_time = 0;
    current_weather = "clear";
    last_update = time();
    set_heart_beat(1);
}

// ── 時間處理 ─────────────────────────────────────────────

int query_game_time() { return game_time; }

// 取得當前小時 (0-23)
int query_hour() {
    return (game_time / 60) % 24;
}

// 取得當前日期 (1-30)
int query_day() {
    return ((game_time / 1440) % 30) + 1;
}

// 取得當前月份 (1-12)
int query_month() {
    return ((game_time / 43200) % 12) + 1;
}

// 判斷是否為白天 (06:00 - 18:00)
int is_day() {
    int h = query_hour();
    return (h >= 6 && h < 18);
}

// 取得當前季節
string query_season() {
    int m = query_month();
    if (m >= 3 && m <= 5) return "spring";
    if (m >= 6 && m <= 8) return "summer";
    if (m >= 9 && m <= 11) return "autumn";
    return "winter";
}

// ── 天氣處理 ─────────────────────────────────────────────

string query_weather() { return current_weather; }

void update_weather() {
    string season = query_season();
    string old_weather = current_weather;
    int rand = random(100);

    // 根據季節決定天氣機率
    switch(season) {
        case "spring":
            if (rand < 50) current_weather = "clear";
            else if (rand < 80) current_weather = "cloudy";
            else current_weather = "rainy";
            break;
        case "summer":
            if (rand < 60) current_weather = "clear";
            else if (rand < 70) current_weather = "cloudy";
            else current_weather = "rainy"; // 雷陣雨
            break;
        case "autumn":
            if (rand < 70) current_weather = "clear";
            else if (rand < 90) current_weather = "cloudy";
            else current_weather = "foggy";
            break;
        case "winter":
            if (rand < 40) current_weather = "clear";
            else if (rand < 70) current_weather = "cloudy";
            else current_weather = "snowy";
            break;
    }

    if (old_weather != current_weather) {
        // 發送天氣變化訊息給所有人 (戶外)
        string msg = "";
        switch(current_weather) {
            case "clear": msg = HIY("天空逐漸放晴，陽光灑滿了大地的每一個角落。"); break;
            case "cloudy": msg = WHT("幾朵烏雲飄過，天空變得陰沉了下來。"); break;
            case "rainy": msg = HIB("天空下起了綿綿細雨，洗滌著塵世。"); break;
            case "foggy": msg = CYN("四周漸漸騰起一陣濃霧，遠方的景物變得模糊不清。"); break;
            case "snowy": msg = HIW("晶瑩的雪花從天空紛紛揚揚地落下。"); break;
        }
        
        object *users = users();
        foreach (object user in users) {
            object env = environment(user);
            if (env && env->query_is_outdoor()) {
                tell_object(user, "\n" + msg + "\n");
            }
        }
    }
}

// ── 心跳邏輯 ─────────────────────────────────────────────

void heart_beat() {
    game_time += 1; // 每一真實秒推進一遊戲分鐘

    // 每 10 遊戲分鐘 (真實 10 秒) 更新一次天氣判定
    if (game_time % 10 == 0) {
        update_weather();
    }
}

// 取得給予 Look 顯示的字串
string query_weather_string() {
    string time_desc = sprintf("%02d:%02d", query_hour(), game_time % 60);
    string weather_desc = "";
    
    switch(current_weather) {
        case "clear":  weather_desc = is_day() ? "晴朗" : "星光燦爛"; break;
        case "cloudy": weather_desc = "多雲"; break;
        case "rainy":  weather_desc = "下雨"; break;
        case "foggy":  weather_desc = "濃霧"; break;
        case "snowy":  weather_desc = "下雪"; break;
    }

    return sprintf("【%s / %s】", time_desc, weather_desc);
}
