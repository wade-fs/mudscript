// daemon/world_state_d.c
// 《遺忘的世界》(THE FORGOTTEN SPACE) 世界狀態守護進程 (03 World State)
// 維護區域持續性、因果關係、水文生態、礦藏儲量、地煞脈動、東林獸潮與商道關卡

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

// ── 1. 水谷水文 (valley_stream) ──────────────────────────
int stream_water_level;     // 水位 0 ~ 100 (預設 42: 平緩適中)
int stream_moss_cleared;    // 是否已被洪水或磨刀沖刷青苔露底 (0/1)
int was_flooded;            // 記錄前一刻是否處於山洪狀態

// ── 2. 南谷草藥生態 (valley_herbs) ───────────────────────
int herb_stock;             // 成熟草藥存量 (0 ~ 12，預設 8)
int herb_growth_progress;   // 生長進度 (0 ~ 100)

// ── 3. 北崖古礦坑與地煞 (blackstone_mine & disha) ────────
int mine_ore_reserve;       // 粗鐵礦存量 (0 ~ 30，預設 15)
int mine_stability;         // 礦道岩壁穩定度 (0 ~ 100，預設 65：昨夜北崖地煞微震落石後略有裂隙)
int mine_is_collapsed;      // 是否塌方 (0/1)
int mine_clear_progress;    // 塌方清理進度 (0 ~ 100)
int disha_activity;         // 地底地煞活躍度 (0 ~ 100，預設 60)

// ── 4. 東林獸群暴動警戒 (eastern_forest) ─────────────────
int forest_beast_alert;     // 東林異獸地煞暴動警戒度 (0 ~ 100，預設 65)

// ── 5. 大荒商隊與關卡權力 (trade_caravan) ────────────────
string caravan_status;      // "traveling", "arrived", "blocked"
int caravan_timer;          // 倒數計時 (遊戲分鐘)
string caravan_delay_reason;// 官面公告之延誤受阻原因
string caravan_truth_reason;// 幕後真實受阻原因 (供聽風/情報網讀取)
int caravan_visit_count;    // 商隊抵達累積次數

// ── 6. 奇遇世界窗口獨立排程與全服名額 (encounter_windows & world_slots) ────
mapping windows;             // 奇遇世界窗口 (window_id -> 剩餘時間分鐘數)
mapping encounter_slots;     // 全服奇遇名額消耗 (encounter_id -> 已獲取神物數量)

string query_save_file() { return "/data/world_state"; }

void create() {
    ::create();
    stream_water_level = 42;
    stream_moss_cleared = 0;
    was_flooded = 0;

    herb_stock = 8;
    herb_growth_progress = 0;

    mine_ore_reserve = 15;
    mine_stability = 65; // 第2章前提：昨夜北崖地煞微震落石，岩壁已有新鮮裂痕
    mine_is_collapsed = 0;
    mine_clear_progress = 0;
    disha_activity = 60;

    forest_beast_alert = 65; // 第3章前提：地煞外溢刺激東林獸群躁動

    caravan_status = "blocked";
    caravan_timer = 60;
    caravan_delay_reason = "北崖夜半落石引發黑石關外山體滑坡，金石商會馱隊暫滯關外";
    caravan_truth_reason = "黑石關城防軍藉昨夜北崖輕微落石之名封鎖官道，向金石商會勒索三成乾股，黑市【保書路引】已炒至八十兩雪花銀";
    caravan_visit_count = 0;

    windows = ([
        "stele_dawn": 0,
        "forge_white_heat": 0,
        "beast_blood_tide": 0,
        "altar_frost_gale": 0,
        "undercurrent_leak": 0,
        "dark_alley_conspiracy": 0
    ]);
    encounter_slots = ([]);

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    if (!windows || !mapp(windows)) {
        windows = ([
            "stele_dawn": 0,
            "forge_white_heat": 0,
            "beast_blood_tide": 0,
            "altar_frost_gale": 0,
            "undercurrent_leak": 0,
            "dark_alley_conspiracy": 0
        ]);
    }
    if (!encounter_slots || !mapp(encounter_slots)) {
        encounter_slots = ([]);
    }
    if (mine_stability <= 0 && !mine_is_collapsed) mine_stability = 65;
    if (disha_activity <= 0) disha_activity = 60;
    if (!caravan_truth_reason || caravan_truth_reason == "") {
        caravan_truth_reason = "黑石關城防軍藉北崖落石之名封鎖官道，向金石商會勒索三成乾股，黑市【保書路引】已炒至八十兩雪花銀";
    }
    if (!caravan_status || (caravan_status != "arrived" && caravan_status != "traveling" && caravan_status != "blocked")) {
        caravan_status = "blocked";
        caravan_timer = 60;
    }
}

// ── 世界因果演進 (由 nature_d 每 5 遊戲分鐘觸發) ────────────

void world_tick(int g_time, string weather) {
    // 1. 水文因果推演
    if (weather == "storm") {
        stream_water_level += 6;
    } else if (weather == "rainy") {
        stream_water_level += 2;
    } else if (weather == "clear") {
        if (stream_water_level > 20) stream_water_level -= 1;
    }

    if (stream_water_level > 100) stream_water_level = 100;
    if (stream_water_level < 15)  stream_water_level = 15;

    // 山洪暴漲判定
    if (stream_water_level >= 85) {
        if (!was_flooded) {
            was_flooded = 1;
            stream_moss_cleared = 1; // 洪水沖刷掉陳年青苔
            object sq = find_object("/d/village/square.c");
            if (sq) tell_room(sq, "\n" + HIB "【水文警訊】南面山谷深處傳來沉悶怒吼般的轟鳴，連日暴雨引發了山洪狂暴注入碎石溪灘！\n" NOR);
            object st = find_object("/d/village/stream.c");
            if (st) tell_room(st, "\n" + HIR "【山洪暴發】深潭水位驟然暴漲數尺，渾濁洶湧的滔天巨浪瞬間將溪灘邊的巨石全部淹沒！\n" NOR);
        }
    } else if (stream_water_level < 70) {
        if (was_flooded) {
            was_flooded = 0;
            open_window("stele_dawn", 60);
            object st2 = find_object("/d/village/stream.c");
            if (st2) tell_room(st2, "\n" + HIG "【水退石出】咆哮的山洪漸漸退去，溪水重歸清冽。被急流洗刷乾淨的巨石斜臥在岸邊，露出深層的奇異刻痕！\n" NOR);
        }
    }

    // 2. 草藥生態推演
    if (herb_stock < 12) {
        int grow_speed = 5;
        if (weather == "rainy" || weather == "storm") grow_speed += 8;
        
        object nat = find_object("/secure/nature_d.c");
        if (nat) {
            int h = nat->query_hour();
            if (h >= 5 && h <= 8) grow_speed += 6; // 卯辰晨露加速
        }

        herb_growth_progress += grow_speed;
        if (herb_growth_progress >= 100) {
            herb_growth_progress = 0;
            herb_stock += 1;
        }
    }

    // 3. 地煞脈動、北崖礦坑與東林獸潮連動
    if (g_time % 20 == 0) {
        int delta = random(7) - 3;
        disha_activity += delta;
        if (disha_activity < 30) disha_activity = 30;
        if (disha_activity > 95) disha_activity = 95;

        if (disha_activity >= 70) {
            forest_beast_alert += 5;
            if (forest_beast_alert > 100) forest_beast_alert = 100;
            if (forest_beast_alert >= 75) open_window("beast_blood_tide", 60);
            open_window("forge_white_heat", 60);
            object fr = find_object("/d/village/forest.c");
            if (fr) tell_room(fr, "\n" + HIR "【地煞湧動】地底傳來一陣低沉悶響，泥沼間滲出刺鼻的地煞腥氣，林海深處響起狂暴的獸吼與急促狼哨！\n" NOR);
        } else if (forest_beast_alert > 40) {
            forest_beast_alert -= 2;
        }
    }

    if (!mine_is_collapsed) {
        if (mine_stability < 85 && disha_activity < 65) mine_stability += 1;
        // 地底深處慢速重壓再生礦石
        if (mine_ore_reserve < 20 && (g_time % 60 == 0)) {
            mine_ore_reserve += 1;
        }
    }

    // 4. 商隊進出生命週期 (兼顧天災與關卡人禍)
    if (stream_water_level >= 85 || weather == "storm") {
        if (caravan_status == "traveling") {
            caravan_status = "blocked";
            open_window("undercurrent_leak", 60);
            caravan_delay_reason = "大荒商道遭遇暴雨山洪沖毀，商隊暫時在山口驛站避險，無法前行";
            caravan_truth_reason = "暴雨沖垮山口棧道，且黑石關守軍趁災坐地起價勒索過路乾股，黑市【保書路引】炒至八十兩雪花銀";
            object sq2 = find_object("/d/village/square.c");
            if (sq2) tell_room(sq2, "\n" + YEL "【商道傳聞】一名渾身濕透的驛卒跑進街市：「大荒山口發生泥石流，金石商會的馱隊受阻在外！」\n" NOR);
        }
    } else {
        if (caravan_status == "blocked") {
            caravan_timer -= 5;
            if (caravan_timer <= 0) {
                caravan_status = "traveling";
                caravan_timer = 45;
                caravan_delay_reason = "";
                object sq3 = find_object("/d/village/square.c");
                if (sq3) tell_room(sq3, "\n" + HIG "【商道重開】金石商會打點妥當黑石關守軍並清開落石，受阻的馱隊已重新啟程朝黑石鋪進發！\n" NOR);
            }
        } else if (caravan_status == "traveling") {
            caravan_timer -= 5;
            if (caravan_timer <= 0) {
                trigger_caravan_arrival();
            }
        } else if (caravan_status == "arrived") {
            caravan_timer -= 5;
            if (caravan_timer <= 0) {
                trigger_caravan_departure();
            }
        } else {
            // 防禦未定義狀態：恢復為 blocked
            caravan_status = "blocked";
            caravan_timer = 60;
        }
    }

    // 5. 奇遇世界窗口倒數推演
    if (windows && sizeof(windows) > 0) {
        foreach (string wid, int rem in windows) {
            if (rem > 0) {
                windows[wid] = rem - 5;
                if (windows[wid] <= 0) {
                    windows[wid] = 0;
                }
            }
        }
    }

    if (g_time % 30 == 0) {
        save_object(query_save_file());
    }
}

// ── 查詢與狀態修改介面 ─────────────────────────────────────

// ── 奇遇世界窗口 (World Windows) 獨立排程介面 ───────────────
int is_window_active(string wid) {
    if (!wid || wid == "") return 0;
    if (windows && windows[wid] > 0) return 1;
    return 0;
}

void open_window(string wid, int duration) {
    if (!wid || wid == "") return;
    if (!windows) windows = ([]);
    if (duration <= 0) duration = 60;
    windows[wid] = duration;
    save_object(query_save_file());
}

void close_window(string wid) {
    if (!wid || wid == "") return;
    if (!windows) windows = ([]);
    windows[wid] = 0;
    save_object(query_save_file());
}

int query_window_remaining(string wid) {
    if (!windows || !windows[wid]) return 0;
    return windows[wid];
}

mapping query_all_windows() {
    return windows;
}

// ── 奇遇名額與回聲政策 (World Slots & Echo) 介面 ────────────
int query_encounter_slots_used(string enc_id) {
    if (!encounter_slots || !encounter_slots[enc_id]) return 0;
    return encounter_slots[enc_id];
}

int consume_encounter_slot(string enc_id, int max_slots) {
    if (!enc_id || enc_id == "") return 0;
    if (!encounter_slots) encounter_slots = ([]);
    int used = encounter_slots[enc_id];
    if (max_slots > 0 && used >= max_slots) {
        return 0; // 名額耗盡，觸發回聲政策
    }
    encounter_slots[enc_id] = used + 1;
    save_object(query_save_file());
    return 1; // 成功取得正品名額
}

void reset_encounter_slots(string enc_id) {
    if (!encounter_slots) return;
    if (!enc_id || enc_id == "") encounter_slots = ([]);
    else map_delete(encounter_slots, enc_id);
    save_object(query_save_file());
}

mapping query_all_encounter_slots() {
    return encounter_slots;
}

int query_stream_water_level() { return stream_water_level; }

string query_water_level_desc() {
    if (stream_water_level < 35) return "枯水清淺";
    if (stream_water_level < 70) return "平緩適中";
    if (stream_water_level < 85) return "豐水洶湧";
    return "山洪暴漲";
}

int is_stele_submerged() {
    return (stream_water_level >= 85);
}

int is_moss_cleared() {
    return stream_moss_cleared;
}

void clear_stream_moss() {
    stream_moss_cleared = 1;
}

int query_herb_stock() { return herb_stock; }
int query_mine_ore_reserve() { return mine_ore_reserve; }
int query_mine_stability() { return mine_stability; }
int is_mine_collapsed() { return mine_is_collapsed; }
int query_mine_clear_progress() { return mine_clear_progress; }
int query_disha_activity() { return disha_activity; }
int query_forest_beast_alert() { return forest_beast_alert; }

string query_forest_status_desc() {
    if (forest_beast_alert >= 75) return "獸潮狂暴（狼哨三響・極度危險）";
    if (forest_beast_alert >= 50) return "地煞躁動（紫黑濁血外溢・哨亭戒備）";
    return "林莽平靜（偶有野獸出沒）";
}

string query_forest_beast_desc() {
    return query_forest_status_desc();
}

void calm_forest_beasts(int v) {
    forest_beast_alert -= v;
    if (forest_beast_alert < 20) forest_beast_alert = 20;
}

string query_caravan_status() { return caravan_status ? caravan_status : "blocked"; }
int query_caravan_timer() { return caravan_timer; }
string query_caravan_delay_reason() { return caravan_delay_reason; }
string query_caravan_truth_reason() { return caravan_truth_reason; }

int is_caravan_arrived() { return (caravan_status == "arrived"); }
int is_caravan_blocked() { return (caravan_status == "blocked"); }
int is_caravan_traveling() { return (caravan_status == "traveling"); }

// ── 商隊到達生命週期函式 ─────────────────────────────────
void trigger_caravan_arrival() {
    caravan_status = "arrived";
    caravan_timer = 120; // 停留 120 遊戲分 (2分鐘)
    caravan_visit_count += 1;
    caravan_truth_reason = "金石商會雖已進村設鋪，但二掌櫃錢富貴在客棧天字號房大發雷霆——黑石關守軍藉落石封路硬吃三成乾股，將一張官方【保書路引】在黑市炒至八十兩雪花銀";

    object sq_room = load_object("/d/village/square.c");
    if (sq_room) {
        object old_m = present("caravan merchant", sq_room);
        if (!old_m) {
            object merchant = clone_object("/clone/npc/caravan_merchant.c");
            if (merchant) {
                move_object(merchant, sq_room);
            }
        }
        tell_room(sq_room, "\n" + HIY "【商隊抵達】伴隨著一陣清脆悠遠的駝鈴聲，一隊滿載大箱的金石商會馱隊緩緩駛入了青石街市！\n" +
                  "錢大掌櫃跳下駝獸，滿面紅光地朝四周街坊拱手：「金石商會開市收貨，高價收購粗礦、柴刀與良藥！」\n" NOR);
    }
}

// ── 商隊離去生命週期函式 ─────────────────────────────────
void trigger_caravan_departure() {
    caravan_status = "blocked";
    caravan_timer = 90;
    caravan_delay_reason = "北崖地煞落石與黑石關守軍例行封關盤查，商隊暫滯關外";
    caravan_truth_reason = "黑石關封路並非單純山體滑坡，乃是城防軍勒索金石商會三成乾股！如今一張官方【保書路引】在黑市已被炒至整整八十兩雪花銀";

    object sq_room2 = find_object("/d/village/square.c");
    if (sq_room2) {
        object *inv2 = all_inventory(sq_room2);
        foreach (object ob in inv2) {
            if (ob && (ob->query_name() == "錢富貴" || ob->id("caravan merchant") || ob->id("merchant"))) {
                destruct(ob);
            }
        }
        tell_room(sq_room2, "\n" + YEL "【商隊啟程】駝鈴聲再次響起，金石商會收攏好收購的物資箱籠，在護衛的護送下拔營離去，返回金石城。\n" NOR);
    }
}

// ── 官軍封關與商道敘事驅動 ─────────────────────────────────
string query_garrison_status() {
    if (caravan_status == "arrived") return "bribed";
    if (caravan_status == "blocked") return "blockade";
    return "eased";
}

string query_garrison_narrative(int is_truth) {
    if (caravan_status == "arrived") {
        if (is_truth) {
            return "金石商會車隊雖已順利入駐前街廣場開市，但大掌櫃是在黑市硬吞下炒至整整八十兩雪花銀的官方【保書路引】，打點了黑石關守軍，才得以通關！";
        } else {
            return "金石商會車隊已順利通關入駐青石街市！大掌櫃錢富貴設鋪開市，高價收購粗礦、良藥與大荒柴刀。";
        }
    } else if (caravan_status == "blocked") {
        if (is_truth) {
            return "黑石關封路並非單純山體滑坡，乃是城防軍勒索金石商會三成乾股！如今一張官方【保書路引】在黑市已被炒至整整八十兩雪花銀！";
        } else {
            return caravan_delay_reason != "" ? caravan_delay_reason : "北崖夜半落石引發黑石關外山體滑坡，金石商會馱隊暫滯關外！";
        }
    } else {
        if (is_truth) {
            return "金石商會馱隊正行經大荒官道。行商私下嘀咕：黑石關守軍胃口愈來愈大，若無重金打點官方【保書路引】，商隊過關必遭刁難！";
        } else {
            return "商會馱隊正在前往黑石鋪途中，大荒官道暫行通暢。";
        }
    }
}

// ── 東林獸群異動與地煞敘事驅動 ─────────────────────────────
string query_beast_movement_status() {
    if (forest_beast_alert >= 75) return "frenzied";
    if (forest_beast_alert >= 50) return "alert";
    return "calm";
}

string query_beast_movement_narrative(int is_detailed) {
    if (forest_beast_alert >= 60) {
        if (is_detailed) {
            return "東林鹿角柵欄外傳來三聲急促狼哨，趙老獵正佈設破甲機弩，張屠戶天不亮提刀磨礪準備隨隊進山；林間發現暗紫色的焦灼濁血，地煞濁氣翻湧，狂暴黑熊發狂撞裂古木！";
        } else {
            return sprintf("東林獸潮警戒（狼哨頻發・地煞濃度 %d%%・獸群躁動度 %d%%），急需巡視加固陷阱 (trap)！", disha_activity, forest_beast_alert);
        }
    } else if (forest_beast_alert >= 40) {
        if (is_detailed) {
            return sprintf("東林獵場地煞濁氣濃度達 %d%%（獸群警戒度 %d%%），獵戶正加緊巡視陷阱與暗紫濁血獸跡。", disha_activity, forest_beast_alert);
        } else {
            return sprintf("東林外圍野獸偶有躁動咆哮（地煞濃度 %d%%，獸群警戒度 %d%%）。", disha_activity, forest_beast_alert);
        }
    } else {
        if (is_detailed) {
            return "東林荒莽晨煙靜謐，野獸潛伏深山，防獸陷阱完好無損。";
        } else {
            return sprintf("獵場動態：林莽平靜（地煞濃度 %d%%，獸群警戒度 %d%%）。", disha_activity, forest_beast_alert);
        }
    }
}

// ── 採藥業務 (gather_herb) ────────────────────────────────

int gather_herb(object player) {
    if (!player) return 0;

    if (player->query(VITAL_SP) < 10) {
        write(HIR "你雙手脫力、氣喘吁吁，精力耗竭，無法在濕滑碎石間精細尋藥。\n" NOR);
        return 1;
    }

    if (herb_stock <= 0) {
        write(WHT "你在碎石灌木叢中仔細搜尋了一番，但成熟草藥已被採擷一空，只見幾株初生嫩苗，尚不堪入藥。\n" +
              "（需等待天地雨露滋養，方能再生成熟）\n" NOR);
        return 1;
    }

    player->add(VITAL_SP, -10);
    herb_stock -= 1;

    // 判斷時辰與天候
    object nat = find_object("/secure/nature_d.c");
    int is_morning = 0;
    string cur_w = "clear";
    if (nat) {
        int h = nat->query_hour();
        if (h >= 5 && h <= 8) is_morning = 1;
        cur_w = nat->query_weather();
    }

    int is_herbalist = (player->query("background") == "herbalist");
    if (is_herbalist) {
        herb_growth_progress += 20; // 採藥孤兒手法高超，採草留根加速再生
    }

    // 產出草藥
    object career = load_object(CAREER_D);
    int is_wu_quest = (career && career->query_chain_stage(player, "wu") == 2);
    if (!is_wu_quest) {
        object qe = find_object(QUEST_ENGINE_D);
        if (qe && qe->query_quest_step(player, "wu_chain") == 2) is_wu_quest = 1;
    }

    if (is_morning || cur_w == "rainy" || cur_w == "storm" || is_wu_quest) {
        object h_dew = clone_object("/clone/item/herb_dew.c");
        if (h_dew) {
            h_dew->move(player);
            write(HIG "你在薄霧籠罩的灌木深處，小心翼翼地剪下一株掛著晶瑩露珠的【帶露晨露草】！\n" NOR);
            write("清晨採摘的草藥靈氣最為凝聚，藥性遠超尋常草藥。\n");
        }
    } else {
        object h_com = clone_object("/clone/item/herb_common.c");
        if (h_com) {
            h_com->move(player);
            write("你撥開碎石泥土，小心掘出了一株【新鮮草藥】。\n");
        }
    }

    // 採藥孤兒機率採得稀有古藥
    if (is_herbalist && random(100) < 30) {
        object h_rare = clone_object("/clone/item/herb_rare.c");
        if (h_rare) {
            h_rare->move(player);
            write(HIY "【天命奇遇】你身手靈活如猿猴，在旁人無法企及的峭壁絕隙中，赫然發現並採下了一株珍罕的【百年鐵角七】！\n" NOR);
        }
    }

    // 鍛鍊感知 per 與靈巧 dex
    write(HIG "【在泥石與草木微芒的辨識中，你的眼力愈發銳利，感知微幅提升！】\n" NOR);
    player->train_stat(STAT_PER, 20);
    player->train_stat(STAT_DEX, 10);
    player->gain_exp(10);
    return 1;
}

// ── 採礦業務 (mine_ore) ──────────────────────────────────

int mine_ore(object player) {
    if (!player) return 0;

    if (mine_is_collapsed) {
        write(HIR "古礦洞已被崩落的萬斤巨石死死堵塞，煙塵瀰漫，內部不時有碎石滾落！\n" +
              "（請使用 clear 指令協助老礦工清理通道碎石）\n" NOR);
        return 1;
    }

    if (mine_ore_reserve <= 0) {
        write(WHT "你敲落了幾片黑石，眼前的富礦脈已被挖空，盡是劣質廢渣。\n" +
              "（需等待地底暗震擠壓出新礦層，方能繼續開採）\n" NOR);
        return 1;
    }

    if (player->query(VITAL_KEE) < 15 || player->query(VITAL_SP) < 10) {
        write(HIR "你氣血衰竭、雙臂酸麻，連鐵鎬都掄不起來了！\n" NOR);
        return 1;
    }

    player->add(VITAL_KEE, -10);
    player->add(VITAL_SP, -10);
    mine_ore_reserve -= 1;

    int stab_loss = random(4) + 2;
    int is_smith = (player->query("background") == "smith");
    if (is_smith) {
        stab_loss -= 2; // 打鐵學徒看準石眼，減少地煞震動
        if (stab_loss < 1) stab_loss = 1;
    }
    mine_stability -= stab_loss;
    if (disha_activity < 95) disha_activity += 1;

    write("你掄起鐵鎬，狠狠砸向堅硬的黑石礦脈，火星四濺！\n");
    write(HIG "【在沉重的揮鎬勞動中，你的雙臂肌肉緊繃，臂力微幅提升！】\n" NOR);
    player->train_stat(STAT_STR, 20);
    player->train_stat(STAT_CON, 10);
    player->gain_exp(10);

    // 產出北崖粗鐵礦核 (/clone/item/ore_chunk.c，具備 is_ore = 1，可直接用於 forge.c 鍛造或賣給商隊)
    int yield_chance = is_smith ? 65 : 45;
    if (random(100) < yield_chance) {
        object ore = clone_object("/clone/item/ore_chunk.c");
        if (ore) {
            ore->move(player);
            write(HIY "只聽『叮』的一聲脆響，你從碎石中撬出了一塊沉甸甸的【北崖粗鐵礦核】（可攜至鐵匠鋪 strike 鍛造或 sell 售予商會）！\n" NOR);
        }
    } else {
        write("碎石崩落一地，只可惜這處岩層盡是雜質廢土。\n");
    }

    // 塌方危險判定
    if (mine_stability <= 25 && mine_stability > 0) {
        write(HIR "⚠️【地質預警】洞頂傳來一陣令人牙酸的石裂聲，幾塊拳頭大的碎石帶著塵土稀里嘩啦砸落！\n" NOR);
    } else if (mine_stability <= 0) {
        mine_is_collapsed = 1;
        mine_clear_progress = 0;
        object room_m = find_object("/d/village/mine.c");
        if (room_m) {
            tell_room(room_m, "\n" + HIR "【地動山搖】伴隨著一聲轟天巨響，整個礦道上方劇烈崩塌！萬斤巨石轟然砸下，將洞口徹底堵死！\n" NOR);
        }
        object sq_r = find_object("/d/village/square.c");
        if (sq_r) {
            tell_room(sq_r, "\n" + HIR "【突發劇變】北面黑石斷崖傳來震耳欲聾的轟鳴，古礦洞發生了大面積塌方！\n" NOR);
        }
    }

    return 1;
}

// ── 加固與維修礦洞 (repair_mine) ──────────────────────────
int repair_mine(int amount) {
    if (amount <= 0) amount = 10;
    mine_stability += amount;
    if (mine_stability > 100) mine_stability = 100;
    return mine_stability;
}

// ── 清理塌方 (clear_rubble) ──────────────────────────────

int clear_mine_rubble(object player) {
    if (!player) return 0;

    if (!mine_is_collapsed) {
        write("礦道目前暢通無阻，未有巨石塌方，無需清理。\n");
        return 1;
    }

    if (player->query(VITAL_KEE) < 15) {
        write(HIR "你氣血虛弱，搬不動如此沉重的崩落巨石。\n" NOR);
        return 1;
    }

    player->add(VITAL_KEE, -10);
    mine_clear_progress += 25;

    write("你咬緊牙關，雙手扣住一塊崩落的黑色稜角巨石，用盡全力將其撬滾到一旁...\n");
    write(sprintf(CYN "【清理進度：%d%%】\n" NOR, mine_clear_progress));
    player->train_stat(STAT_STR, 25);
    player->gain_exp(15);

    if (mine_clear_progress >= 100) {
        mine_is_collapsed = 0;
        mine_stability = 70;
        mine_ore_reserve = 15;
        mine_clear_progress = 0;

        object room_m = find_object("/d/village/mine.c");
        if (room_m) {
            tell_room(room_m, "\n" + HIG "【道路搶通】在眾人的奮力搬運下，最後一塊堵塞洞口的巨石被徹底移開，古礦洞重新恢復通行！\n" NOR);
        }
        object sq_r = find_object("/d/village/square.c");
        if (sq_r) {
            tell_room(sq_r, "\n" + HIG "【捷報】北面黑石斷崖的塌方巨石已被清理完畢，老礦工得以脫困，礦道重開！\n" NOR);
        }
        write(HIY "老礦工滿面塵土，激動地拉住你的手：「多虧了小兄弟相助！這是一塊上好精礦，你拿去防身鍛造吧！」\n" NOR);
        object reward_ore = clone_object("/clone/item/ore_chunk.c");
        if (reward_ore) {
            reward_ore->move(player);
        }
    }

    return 1;
}
