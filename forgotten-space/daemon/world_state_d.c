// daemon/world_state_d.c
// 《遺忘的世界》(THE FORGOTTEN SPACE) 世界狀態守護進程 (03 World State)
// 維護區域持續性、因果關係、水文生態、礦藏儲量與商道商隊

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

// ── 1. 水谷水文 (valley_stream) ──────────────────────────
int stream_water_level;     // 水位 0 ~ 100 (預設 40: 平緩適中)
int stream_moss_cleared;    // 是否已被洪水沖刷青苔露底 (0/1)
int was_flooded;            // 記錄前一刻是否處於山洪狀態

// ── 2. 南谷草藥生態 (valley_herbs) ───────────────────────
int herb_stock;             // 成熟草藥存量 (0 ~ 12，預設 8)
int herb_growth_progress;   // 生長進度 (0 ~ 100)

// ── 3. 北崖古礦坑 (blackstone_mine) ──────────────────────
int mine_ore_reserve;       // 粗鐵礦存量 (0 ~ 30，預設 15)
int mine_stability;         // 礦道岩壁穩定度 (0 ~ 100，預設 100)
int mine_is_collapsed;      // 是否塌方 (0/1)
int mine_clear_progress;    // 塌方清理進度 (0 ~ 100)

// ── 4. 大荒商隊 (trade_caravan) ──────────────────────────
string caravan_status;      // "traveling", "arrived", "blocked"
int caravan_timer;          // 倒數計時 (遊戲分鐘)
string caravan_delay_reason;// 延誤受阻原因
int caravan_visit_count;    // 商隊抵達累積次數

string query_save_file() { return "/data/world_state"; }

void create() {
    ::create();
    stream_water_level = 42;
    stream_moss_cleared = 0;
    was_flooded = 0;

    herb_stock = 8;
    herb_growth_progress = 0;

    mine_ore_reserve = 15;
    mine_stability = 100;
    mine_is_collapsed = 0;
    mine_clear_progress = 0;

    caravan_status = "traveling";
    caravan_timer = 90; // 90 遊戲分 (90秒) 後首度抵達
    caravan_delay_reason = "";
    caravan_visit_count = 0;

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
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

    // 3. 礦坑地質自癒
    if (!mine_is_collapsed) {
        if (mine_stability < 100) mine_stability += 1;
        // 地底深處慢速重壓再生礦石
        if (mine_ore_reserve < 20 && (g_time % 60 == 0)) {
            mine_ore_reserve += 1;
        }
    }

    // 4. 商隊進出生命週期
    if (stream_water_level >= 85 || weather == "storm") {
        if (caravan_status == "traveling") {
            caravan_status = "blocked";
            caravan_delay_reason = "大荒商道遭遇暴雨山洪沖毀，商隊暫時在山口驛站避險，無法前行";
            object sq2 = find_object("/d/village/square.c");
            if (sq2) tell_room(sq2, "\n" + YEL "【商道傳聞】一名渾身濕透的驛卒跑進街市：「大荒山口發生泥石流，金石商會的馱隊受阻在外！」\n" NOR);
        }
    } else {
        if (caravan_status == "blocked") {
            caravan_status = "traveling";
            caravan_delay_reason = "";
            object sq3 = find_object("/d/village/square.c");
            if (sq3) tell_room(sq3, "\n" + HIG "【商道暢通】驛道泥石已被清理開，受阻的金石商會馱隊已重新啟程朝黑石鋪進發！\n" NOR);
        }

        if (caravan_status == "traveling") {
            caravan_timer -= 5;
            if (caravan_timer <= 0) {
                // 商隊抵達
                caravan_status = "arrived";
                caravan_timer = 120; // 停留 120 遊戲分 (2分鐘)
                caravan_visit_count += 1;

                object sq_room = load_object("/d/village/square.c");
                if (sq_room) {
                    object merchant = clone_object("/clone/npc/caravan_merchant.c");
                    if (merchant) {
                        move_object(merchant, sq_room);
                    }
                    tell_room(sq_room, "\n" + HIY "【商隊抵達】伴隨著一陣清脆悠遠的駝鈴聲，一隊滿載大箱的金石商會馱隊緩緩駛入了青石街市！\n" +
                              "錢大掌櫃跳下駝獸，滿面紅光地朝四周街坊拱手：「金石商會開市收貨，高價收購粗礦良藥！」\n" NOR);
                }
            }
        } else if (caravan_status == "arrived") {
            caravan_timer -= 5;
            if (caravan_timer <= 0) {
                // 商隊離去
                caravan_status = "traveling";
                caravan_timer = 240; // 4分鐘後再次前來

                object sq_room2 = find_object("/d/village/square.c");
                if (sq_room2) {
                    object *inv2 = all_inventory(sq_room2);
                    foreach (object ob in inv2) {
                        if (ob && ob->query_name() == "錢富貴") {
                            destruct(ob);
                        }
                    }
                    tell_room(sq_room2, "\n" + YEL "【商隊啟程】駝鈴聲再次響起，金石商會收攏好收購的物資箱籠，在護衛的護送下拔營離去，返回金石城。\n" NOR);
                }
            }
        }
    }

    if (g_time % 30 == 0) {
        save_object(query_save_file());
    }
}

// ── 查詢介面 ─────────────────────────────────────────────

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

int query_herb_stock() { return herb_stock; }
int query_mine_ore_reserve() { return mine_ore_reserve; }
int query_mine_stability() { return mine_stability; }
int is_mine_collapsed() { return mine_is_collapsed; }
int query_mine_clear_progress() { return mine_clear_progress; }
string query_caravan_status() { return caravan_status; }
int query_caravan_timer() { return caravan_timer; }
string query_caravan_delay_reason() { return caravan_delay_reason; }

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
    if (is_morning || cur_w == "rainy" || cur_w == "storm") {
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
    player->add(STAT_PER, 1);
    write(HIG "【在泥石與草木微芒的辨識中，你的眼力愈發銳利，感知微幅提升！】\n" NOR);
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

    if (player->query(VITAL_KEE) < 15) {
        write(HIR "你氣血衰竭，雙臂酸麻，連鐵鎬都掄不起來了！\n" NOR);
        return 1;
    }

    player->add(VITAL_KEE, -15);
    mine_ore_reserve -= 1;

    int stab_loss = random(4) + 2;
    int is_smith = (player->query("background") == "smith");
    if (is_smith) {
        stab_loss -= 2; // 打鐵學徒看準石眼，減少地煞震動
        if (stab_loss < 1) stab_loss = 1;
    }
    mine_stability -= stab_loss;

    write("你掄起鐵鎬，狠狠砸向堅硬的黑石礦脈，火星四濺！\n");
    player->add(STAT_STR, 1);
    write(HIG "【在沉重的揮鎬勞動中，你的雙臂肌肉緊繃，臂力微幅提升！】\n" NOR);

    // 產出粗鐵礦石
    int yield_chance = is_smith ? 60 : 40;
    if (random(100) < yield_chance) {
        object ore = clone_object("/std/item.c");
        if (ore) {
            ore->set_name("粗鐵礦石", ({ "iron ore", "ore", "礦石" }));
            ore->set_short("粗鐵礦石");
            ore->set_long("一塊剛從黑石斷崖開採出來的未精煉粗鐵礦，質地堅硬厚重。\n"
                         "可賣給金石商會掌櫃換取現銀，亦可用於鐵匠鋪鍛造。\n");
            ore->set_weight(2000);
            ore->set_value(30);
            ore->move(player);
            write(HIY "只聽『叮』的一聲脆響，你從碎石中撬出了一塊【粗鐵礦石】！\n" NOR);
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
    player->add(STAT_STR, 1);

    write("你咬緊牙關，雙手扣住一塊崩落的黑色稜角巨石，用盡全力將其撬滾到一旁...\n");
    write(sprintf(CYN "【清理進度：%d%%】\n" NOR, mine_clear_progress));

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
        write(HIY "老礦工滿面塵土，激動地拉住你的手：「多虧了小兄弟相助！這是一塊上好精礦，你拿去防身吧！」\n" NOR);
    }

    return 1;
}
