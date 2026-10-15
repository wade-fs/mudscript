// /secure/nature_d.c
// 氣候與時間守護進程 (Nature Daemon)
// 《遺忘的世界》(THE FORGOTTEN SPACE)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object";

// 遊戲時間與現實時間比例：1 真實秒 = 1 遊戲分鐘 (24 真實分 = 24 遊戲小時)
#define TIME_RATIO 60

int game_time;          // 遊戲總分鐘數
string current_weather; // 目前天氣 (clear, cloudy, rainy, storm, foggy, snowy)
int weather_duration;   // 當前天氣維持時間 (遊戲分鐘/秒數)
int last_update;

string query_save_file() { return "/data/nature"; }

void create() {
    ::create();
    game_time = 300; // 預設從清晨 05:00 卯時開始
    current_weather = "clear";
    weather_duration = 90; // 維持 90 分鐘 (90 秒真實時間)
    last_update = time();
    
    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    
    set_heart_beat(1);
}

// ── 時間處理 ─────────────────────────────────────────────

int query_game_time() { return game_time; }

// 當前小時 (0-23)
int query_hour() {
    return (game_time / 60) % 24;
}

// 當前分鐘 (0-59)
int query_minute() {
    return game_time % 60;
}

// 當前日期 (1-30)
int query_day() {
    return ((game_time / 1440) % 30) + 1;
}

// 當前月份 (1-12)
int query_month() {
    return ((game_time / 43200) % 12) + 1;
}

// 是否為白天 (06:00 - 18:00)
int is_day() {
    int h = query_hour();
    return (h >= 6 && h < 18);
}

// 當前季節 (春夏秋冬)
string query_season() {
    int m = query_month();
    if (m >= 3 && m <= 5) return "spring";
    if (m >= 6 && m <= 8) return "summer";
    if (m >= 9 && m <= 11) return "autumn";
    return "winter";
}

string query_season_name() {
    switch(query_season()) {
        case "spring": return "春季";
        case "summer": return "夏季";
        case "autumn": return "秋季";
        case "winter": return "冬季";
    }
    return "春季";
}

// 傳統十二時辰
string query_shichen_name() {
    int h = query_hour();
    switch(h) {
        case 23: case 0: return "子時";
        case 1:  case 2: return "丑時";
        case 3:  case 4: return "寅時";
        case 5:  case 6: return "卯時"; // 破曉清晨・晨露凝聚
        case 7:  case 8: return "辰時"; // 朝陽初升
        case 9:  case 10: return "巳時";
        case 11: case 12: return "午時"; // 正午純陽
        case 13: case 14: return "未時";
        case 15: case 16: return "申時";
        case 17: case 18: return "酉時"; // 日落黃昏
        case 19: case 20: return "戌時";
        case 21: case 22: return "亥時";
    }
    return "子時";
}

// 時辰刻數 (一刻 = 15分鐘)
string query_shichen_ke() {
    int m = query_minute();
    int ke = (m / 15) + 1;
    switch(ke) {
        case 1: return "初刻";
        case 2: return "二刻";
        case 3: return "三刻";
        case 4: return "四刻";
    }
    return "初刻";
}

string query_shichen_full() {
    return query_shichen_name() + query_shichen_ke();
}

// ── 天候處理 (具持續性與氣壓鋒面轉換) ──────────────────────

string query_weather() { return current_weather; }

string query_weather_name() {
    switch(current_weather) {
        case "clear":  return is_day() ? "萬里晴空" : "星斗璀璨";
        case "cloudy": return "層雲蔽日";
        case "rainy":  return "細雨霏霏";
        case "storm":  return "狂風驟雨";
        case "foggy":  return "幽霧迷濛";
        case "snowy":  return "碎雪紛飛";
    }
    return "晴朗";
}

void update_weather() {
    string season = query_season();
    string old_weather = current_weather;
    int rand = random(100);

    // 依據當前天氣進行馬可夫平滑轉移（自然鋒面，避免突變）
    if (old_weather == "clear") {
        if (rand < 50) current_weather = "clear";
        else if (rand < 85) current_weather = "cloudy";
        else current_weather = "foggy";
        weather_duration = 90 + random(90); // 維持 90~180 遊戲分
    } else if (old_weather == "cloudy") {
        if (rand < 35) current_weather = "clear";
        else if (rand < 75) {
            current_weather = (season == "winter") ? "snowy" : "rainy";
        } else {
            current_weather = "cloudy";
        }
        weather_duration = 80 + random(60);
    } else if (old_weather == "rainy") {
        if (rand < 25) current_weather = "storm"; // 轉暴雨
        else if (rand < 60) current_weather = "cloudy";
        else if (rand < 80) current_weather = "foggy";
        else current_weather = "rainy";
        weather_duration = 60 + random(60);
    } else if (old_weather == "storm") {
        if (rand < 70) current_weather = "rainy"; // 暴雨轉小雨
        else current_weather = "cloudy";
        weather_duration = 45 + random(45);
    } else if (old_weather == "foggy") {
        if (rand < 60) current_weather = "clear";
        else current_weather = "cloudy";
        weather_duration = 60 + random(60);
    } else { // snowy
        if (rand < 60) current_weather = "cloudy";
        else current_weather = "clear";
        weather_duration = 80 + random(60);
    }

    if (old_weather != current_weather) {
        object *all_users = users();
        if (all_users) {
            foreach (object u in all_users) {
                if (!u) continue;
                object env = environment(u);
                if (env && env->query_is_outdoor()) {
                    string change_msg = "";
                    switch(current_weather) {
                        case "clear":  change_msg = "$HIY$雲霧漸漸散去，金燦陽光再次灑落在大地上。$NOR$\n"; break;
                        case "cloudy": change_msg = "$WHT$大片陰雲自遠方山巒湧來，天色漸漸暗了下來。$NOR$\n"; break;
                        case "rainy":  change_msg = "$CYN$天空飄落綿綿細雨，水珠打在青石板上發出淅瀝聲響。$NOR$\n"; break;
                        case "storm":  change_msg = "$HIR$狂風呼嘯，黑雲翻滾！傾盆驟雨如注，電閃雷鳴！$NOR$\n"; break;
                        case "foggy":  change_msg = "$WHT$四周山澗漫起漫天濕冷白霧，數丈之外景物朦朧。$NOR$\n"; break;
                        case "snowy":  change_msg = "$HIW$寒風呼嘯，天空中灑落點點晶瑩的冰晶碎雪。$NOR$\n"; break;
                    }
                    tell_object(u, "\n" + change_msg);
                }
            }
        }
    }
}

// ── 心跳邏輯 ─────────────────────────────────────────────

void heart_beat() {
    game_time = game_time + 1;
    
    if (weather_duration > 0) {
        weather_duration = weather_duration - 1;
    } else {
        update_weather();
    }

    // 每 5 遊戲分鐘通知世界狀態守護進程進行因果推演
    if (game_time % 5 == 0) {
        object ws_d = find_object(WORLD_STATE_D);
        if (ws_d) {
            ws_d->world_tick(game_time, current_weather);
        }
    }

    // 每 30 遊戲分鐘存檔一次
    if (game_time % 30 == 0) {
        save_object(query_save_file());
    }
}

// 取得房間 Look 顯示的時辰氣候字串
string query_weather_string() {
    string time_desc = sprintf("%s (%02d:%02d)", query_shichen_full(), query_hour(), query_minute());
    string weather_desc = query_weather_name();
    return sprintf("【 %s / %s 】", time_desc, weather_desc);
}
