// /secure/nature_d.c
// 氣候與時間守護進程 (Nature Daemon)
// 《遺忘的世界》(THE FORGOTTEN SPACE)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object";

// 遊戲時間與現實時間比例：4:1 (1 真實秒 = 4 遊戲秒；15 真實秒 = 1 遊戲分鐘；6 真實小時 = 24 遊戲小時/1 晝夜)
#define TIME_RATIO 4

int game_time;          // 遊戲總分鐘數
int tick_second;        // 累積真實秒數 (每 15 秒推進 1 遊戲分鐘)
int time_offset;        // 時間偏移分鐘數 (管理員推進或劇情調整)
string current_weather; // 目前天氣 (clear, cloudy, rainy, storm, foggy, snowy)
int weather_duration;   // 當前天氣維持時間 (遊戲分鐘數)
int last_update;

string query_save_file() { return "/data/nature"; }

void create() {
    ::create();
    game_time = 300; // 預設從清晨 05:00 卯時開始
    tick_second = 0;
    time_offset = 0;
    current_weather = "clear";
    weather_duration = 90; // 維持 90 分鐘 (90 秒真實時間)
    last_update = time();
    
    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    
    set_heart_beat(1);
}

// ── 輔助函數：取得現實時間與偏移對照 ─────────────────────
mapping get_time_info() {
    int now_ts = time() + (time_offset * 15);
    return localtime(now_ts);
}

// ── 遺忘曆法紀年 (方案 A 視角一：一季即一歲，太古異星公轉法則) ─────
// 2026年 10~12月 = 8104 年 (玄冥冬歲)
// 2027年 01~03月 = 8105 年 (一元春歲)
// 2027年 04~06月 = 8106 年 (品物夏歲)
// 2027年 07~09月 = 8107 年 (金石秋歲)
// 2027年 10~12月 = 8108 年 (玄冥冬歲)
int query_calendar_year() {
    mapping t = get_time_info();
    int real_year = t["year"];
    int real_mon = t["mon"] + 1; // 1~12
    int quarter = (real_mon - 1) / 3; // 0, 1, 2, 3
    return (real_year * 4) + quarter - 3;
}

int query_calendar_month() {
    mapping t = get_time_info();
    return t["mon"] + 1;
}

int query_calendar_day() {
    mapping t = get_time_info();
    return t["mday"];
}

// 當前大年歲象稱謂
string query_year_season_title() {
    int m = query_calendar_month();
    int q = (m - 1) / 3;
    switch(q) {
        case 0: return "一元春歲";
        case 1: return "品物夏歲";
        case 2: return "金石秋歲";
        case 3: return "玄冥冬歲";
    }
    return "玄冥冬歲";
}

string query_calendar_date_string() {
    return sprintf("遺忘曆 %d 年 %d 月 %d 日", query_calendar_year(), query_calendar_month(), query_calendar_day());
}

// ── 一日四序輪元 (元亨利貞) ──────────────────────────────────
// 現實 24 小時整齊劃分為 4 個 6 小時大日夜，每日歷經四十八時辰
int query_cycle_index() {
    mapping t = get_time_info();
    int sec_of_day = t["hour"] * 3600 + t["min"] * 60 + t["sec"];
    return (sec_of_day / 21600) % 4;
}

string query_cycle_name() {
    int c = query_cycle_index();
    switch(c) {
        case 0: return "元";
        case 1: return "亨";
        case 2: return "利";
        case 3: return "貞";
    }
    return "元";
}

string query_cycle_desc() {
    int c = query_cycle_index();
    switch(c) {
        case 0: return "一元復始，胚萌破曉";
        case 1: return "晨曦通暢，品物流形";
        case 2: return "日斜金風，各正性命";
        case 3: return "暮夜歸根，太和守正";
    }
    return "";
}

// ── 時間處理 (4:1 流速，每個日夜 24 遊戲小時) ─────────────

int query_game_time() { return game_time; }

// 當前日夜內的遊戲小時 (0-23)
int query_hour() {
    mapping t = get_time_info();
    int sec_of_day = t["hour"] * 3600 + t["min"] * 60 + t["sec"];
    int sec_in_cycle = sec_of_day % 21600;
    return sec_in_cycle / 900;
}

// 當前日夜內的遊戲分鐘 (0-59)
int query_minute() {
    mapping t = get_time_info();
    int sec_of_day = t["hour"] * 3600 + t["min"] * 60 + t["sec"];
    int sec_in_cycle = sec_of_day % 21600;
    return (sec_in_cycle % 900) / 15;
}

// 當前日期 (1-30，保留相容介面)
int query_day() {
    return query_calendar_day();
}

// 當前月份 (1-12，保留相容介面)
int query_month() {
    return query_calendar_month();
}

// 是否為白天 (06:00 - 18:00)
int is_day() {
    int h = query_hour();
    return (h >= 6 && h < 18);
}

// 當前季節 (春夏秋冬)
string query_season() {
    int m = query_calendar_month();
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

// 基礎十二時辰名稱
string query_base_shichen_name() {
    int h = query_hour();
    switch(h) {
        case 23: case 0: return "子時";
        case 1:  case 2: return "丑時";
        case 3:  case 4: return "寅時";
        case 5:  case 6: return "卯時"; // 破曉清晨・晨露凝聚
        case 7:  case 8: return "辰時"; // 朝陽初升・掠射側影
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

// 完整時辰名稱 (冠上元亨利貞，如：元子時、亨辰時、利午時、貞亥時)
string query_shichen_name() {
    return query_cycle_name() + query_base_shichen_name();
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
    tick_second++;
    if (tick_second >= 15) {
        tick_second = 0;
        game_time = game_time + 1;
        
        if (weather_duration > 0) {
            weather_duration = weather_duration - 1;
        } else {
            update_weather();
        }

        // 每 5 遊戲分鐘 (現實 75 秒) 通知世界狀態守護進程進行因果推演
        if (game_time % 5 == 0) {
            object ws_d = find_object(WORLD_STATE_D);
            if (ws_d) {
                ws_d->world_tick(game_time, current_weather);
            }
        }

        // 每 1440 遊戲分鐘 (1 遊戲日) 自動推進六縣與黑石鋪 30 天無主角介入演進時鐘
        if (game_time % 1440 == 0) {
            object ws_d = find_object(WORLD_STATE_D);
            if (!ws_d) ws_d = load_object(WORLD_STATE_D);
            if (ws_d) {
                ws_d->advance_county_day("all", 1);
            }
        }

        // 每 30 遊戲分鐘 (現實 7.5 分鐘) 存檔一次
        if (game_time % 30 == 0) {
            save_object(query_save_file());
        }
    }
}

// 取得當前時間比例 (4 代表 4:1)
int query_time_ratio() {
    return TIME_RATIO;
}

// 推進指定遊戲分鐘 (管理員或劇情事件專用)
void advance_time(int minutes) {
    if (minutes <= 0) return;
    time_offset += minutes;
    game_time += minutes;
    save_object(query_save_file());
    object ws_d = find_object(WORLD_STATE_D);
    if (ws_d) {
        ws_d->world_tick(game_time, current_weather);
    }
}

// 取得房間 Look 顯示的時辰氣候字串
string query_weather_string() {
    string date_desc = query_calendar_date_string();
    string time_desc = sprintf("%s (%02d:%02d)", query_shichen_full(), query_hour(), query_minute());
    string weather_desc = query_weather_name();
    return sprintf("【 %s %s / %s 】", date_desc, time_desc, weather_desc);
}
