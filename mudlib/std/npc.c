// std/npc.c - NPC / 怪物基底類別

#include "/include/config.h"

inherit "/std/living.c";

// ── NPC 專屬欄位 ────────────────────────────────────────────────
int     exp_reward;    // 擊殺後給予的經驗值
int     gold_reward;   // 掉落金幣數量
mixed   drop_list;     // 掉落物清單：({"/path/item.c", ...})
int     respawn_time;  // 重生時間（秒），0 = 不重生
string  aggro_msg;     // 主動攻擊時的訊息

// ── 棲息地與行為模式 ──────────────────────────────────────
string  habitat;       // HABITAT_LAND / WATER / UNDERGROUND / SKY / CAVE
int     behaviour;     // 位元旗標：BEHAV_AGGRESSIVE | BEHAV_GUARD | BEHAV_PATROL | BEHAV_WANDER
int     aggro_range;   // 主動攻擊偵測範圍（格數，0=不主動）
int     flee_hp_pct;   // 逃跑血量百分比 (預設 20)
int     flee_chance;   // 逃跑成功機率 (0~100, 預設 50)
mixed   patrol_rooms;  // 巡邏路線 ({"/area/newbie/room_x_y.c", ...})
int     patrol_idx;    // 目前巡邏位置索引
int     sight_flags;   // 位元旗標: 1=夜視, 2=水中視覺, 4=隱形偵測
string  special_atk;   // 特殊攻擊名稱（空=無）
int     special_atk_chance; // 特殊攻擊機率 (0~100)

// ── 自由移動屬性 ──────────────────────────────────────
string  home_room;     // 出生點 (房間路徑)
int     move_range;    // 可移動的最大距離 (Manhattan Distance, 0=固定)
int     wander_chance; // 每次心跳隨機移動的機率 (0~100)

void create() {
    ::create();
    enable_commands();

    set_name("怪物");
    set_short("一隻怪物");
    set_long("這是一隻普通的怪物，看起來不太友善。\n");
    set_id(({"monster", "怪物"}));

    level       = 1;
    stat_str    = 8;
    stat_dex    = 8;
    stat_con    = 8;
    recalc_stats();
    hp          = max_hp;
    mp          = max_mp;

    exp_reward  = 50;
    gold_reward = 10;
    drop_list   = ({});
    respawn_time= 0;
    aggro_msg   = "";

    // 預設值
    habitat          = HABITAT_LAND;
    behaviour        = BEHAV_PASSIVE;
    aggro_range      = 0;
    flee_hp_pct      = 20;
    flee_chance      = 50;
    patrol_rooms     = ({});
    patrol_idx       = 0;
    sight_flags      = 0;
    special_atk      = "";
    special_atk_chance = 0;

    home_room        = "";
    move_range       = 0;
    wander_chance    = 0;

    set_heart_beat(1);
}

// init() 在玩家進入 NPC 所在房間時由 driver 呼叫
void init() {
    // 第一次移動到某個房間時，若 home_room 未設定，則將該處設為家
    if (home_room == "") {
        object env = environment(this_object());
        if (env) {
            home_room = object_name(env);
            // 去除可能存在的 clone ID
            int pos = strsrch(home_room, "#");
            if (pos != -1) home_room = substr(home_room, 0, pos);
        }
    }
}

// ── 設定 / 查詢 ──────────────────────────────────────────────────
void set_exp_reward(int v)         { exp_reward        = v; }
void set_gold_reward(int v)        { gold_reward       = v; }
void set_drop_list(mixed l)        { drop_list         = l; }
void set_respawn(int v)            { respawn_time      = v; }
void set_aggro_msg(string s)       { aggro_msg         = s; }
void set_habitat(string h)         { habitat           = h; }
void set_behaviour(int b)          { behaviour         = b; }
void set_aggro_range(int v)        { aggro_range       = v; }
void set_flee_hp_pct(int v)        { flee_hp_pct       = v; }
void set_flee_chance(int v)        { flee_chance       = v; }
void set_patrol_rooms(mixed r)     { patrol_rooms      = r; }
void set_sight_flags(int v)        { sight_flags       = v; }
void set_special_atk(string s, int pct) {
    special_atk        = s;
    special_atk_chance = pct;
}
void set_home_room(string r)       { home_room         = r; }
void set_move_range(int v)         { move_range        = v; }
void set_wander_chance(int v)      { wander_chance     = v; }

string  query_habitat()       { return habitat; }
int     query_behaviour()     { return behaviour; }
int     query_aggro_range()   { return aggro_range; }
string  query_home_room()     { return home_room; }
int     query_move_range()    { return move_range; }

// ── 輔助：計算兩個房間之間的距離 ─────────────────────
int calculate_distance(object room1, object room2) {
    if (!room1 || !room2) return 999;
    mixed c1 = room1->query_coordinate();
    mixed c2 = room2->query_coordinate();
    if (!arrayp(c1) || !arrayp(c2) || sizeof(c1) < 3 || sizeof(c2) < 3) return 999;
    
    int dx = c1[0] - c2[0];
    int dy = c1[1] - c2[1];
    int dz = c1[2] - c2[2];
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    if (dz < 0) dz = -dz;
    return dx + dy + dz;
}

// ── 互動：對話 ───────────────────────────────────────────────────

// 收集所有來源的關鍵字回應（自己、房間、持有物）
mapping query_all_responses() {
    mapping all = ([]);
    mapping from;
    mixed ks;
    int i, j;

    // 1. 來自房間
    object env = environment(this_object());
    if (env) {
        from = env->query_responses();
        if (mapp(from)) {
            ks = keys(from);
            for (i = 0; i < sizeof(ks); i++) {
                if (!all[ks[i]]) all[ks[i]] = ({});
                all[ks[i]] += from[ks[i]];
            }
        }
    }
    
    // 2. 來自持有物
    object *inv = all_inventory(this_object());
    for (j = 0; j < sizeof(inv); j++) {
        from = inv[j]->query_responses();
        if (mapp(from)) {
            ks = keys(from);
            for (i = 0; i < sizeof(ks); i++) {
                if (!all[ks[i]]) all[ks[i]] = ({});
                all[ks[i]] += from[ks[i]];
            }
        }
    }
    
    // 3. 來自 NPC 自己
    from = query_responses();
    if (mapp(from)) {
        ks = keys(from);
        for (i = 0; i < sizeof(ks); i++) {
            if (!all[ks[i]]) all[ks[i]] = ({});
            all[ks[i]] += from[ks[i]];
        }
    }
    
    return all;
}

// 執行回應
void do_respond(string msg) {
    if (!msg || msg == "") return;
    say(query_name() + " 說：「" + msg + "」\n");
}

// 攔截聽到的訊息
void catch_tell(string msg) {
    // 只對玩家的說話內容反應，避免 NPC 之間產生無限迴圈
    object tp = this_player();
    if (!tp || !userp(tp)) return;

    // 判斷是否有人說話。格式通常為：Name 說：「Content」
    // 使用更寬鬆的匹配：只要包含 ：「 和 」
    int start = strsrch(msg, "：「");
    if (start == -1) return;
    
    int end = strsrch(msg, "」", 1);
    if (end == -1 || end <= start + 2) return;
    
    // "：「" 長度為 2 (：, 「)
    string content = substr(msg, start + 2, end - (start + 2));
    string lc_content = lower_case(trim(content));

    mapping all_resp = query_all_responses();
    if (!mapp(all_resp)) return;

    mixed ks = keys(all_resp);
    int i;

    for (i = 0; i < sizeof(ks); i++) {
        if (!stringp(ks[i])) continue;
        
        string keyword = lower_case(ks[i]);
        if (strsrch(lc_content, keyword) != -1) {
            mixed options = all_resp[ks[i]];
            string final_msg = "";
            if (arrayp(options)) {
                if (sizeof(options) > 0) {
                    final_msg = options[random(sizeof(options))];
                }
            } else if (stringp(options)) {
                final_msg = options;
            }
            
            if (final_msg && final_msg != "") {
                // 稍微延遲一下再回應，感覺比較真實
                call_out("do_respond", 1, final_msg);
                return; // 每次說話只針對一個關鍵字反應
            }
        }
    }
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    
    mapping all_resp = query_all_responses();
    string my_name = query_name();

    // 優先精確匹配
    if (all_resp[topic]) {
        mixed options = all_resp[topic];
        string final_msg = "";
        if (arrayp(options)) {
            if (sizeof(options) > 0) {
                final_msg = options[random(sizeof(options))];
            }
        } else {
            final_msg = options;
        }
        if (final_msg != "") {
            tell_object(me, my_name + " 告訴你：「" + final_msg + "」\n");
            return 1;
        }
    }

    // 模糊匹配與特殊話題
    string lc_topic = lower_case(topic);
    mixed ks = keys(all_resp);
    int i;
    for (i = 0; i < sizeof(ks); i++) {
        if (lower_case(ks[i]) == lc_topic) {
            mixed options = all_resp[ks[i]];
            string final_msg = "";
            if (arrayp(options)) {
                if (sizeof(options) > 0) {
                    final_msg = options[random(sizeof(options))];
                }
            } else {
                final_msg = options;
            }
            if (final_msg != "") {
                tell_object(me, my_name + " 告訴你：「" + final_msg + "」\n");
                return 1;
            }
        }
    }

    if (topic == "here" || topic == "這裡") {
        tell_object(me, my_name + " 說：「這裡是個好地方。」\n");
        return 1;
    }
    if (topic == "name" || topic == "名字") {
        tell_object(me, my_name + " 說：「我叫 " + my_name + "，請多指教。」\n");
        return 1;
    }
    if (lc_topic == "topics" || topic == "話題" || topic == "topic") {
        mixed t_keys = keys(all_resp);
        if (sizeof(t_keys) == 0) {
            tell_object(me, my_name + " 搖搖頭說：「我沒什麼好說的。」\n");
        } else {
            string list = implode(t_keys, "、");
            tell_object(me, my_name + " 說：「你可以問我關於：" + list + "。」\n");
        }
        return 1;
    }

    return 0;
}

// ── 自由移動邏輯 ─────────────────────────────────────────────
void do_wander() {
    object env = environment(this_object());
    if (!env) return;

    mapping exits = env->query_exits();
    if (!mapp(exits) || sizeof(exits) == 0) return;

    string *dirs = keys(exits);
    string dir = dirs[random(sizeof(dirs))];
    string dest_path = exits[dir];
    
    object dest = load_object(dest_path);
    if (!dest) return;

    // 檢查目的地是否超出移動範圍
    if (home_room != "" && move_range > 0) {
        object home = load_object(home_room);
        if (home && calculate_distance(dest, home) > move_range) {
            return; // 太遠了，不去
        }
    }

    say(query_name() + " 往 " + dir + " 走了過去。\n");
    move_object(dest);
    say(query_name() + " 走了過來。\n");
}

// ── 巡邏邏輯 ─────────────────────────────────────────────────────
void do_patrol() {
    if (sizeof(patrol_rooms) == 0) return;
    patrol_idx = (patrol_idx + 1) % sizeof(patrol_rooms);
    object dest = find_object(patrol_rooms[patrol_idx]);
    if (!dest) dest = load_object(patrol_rooms[patrol_idx]);
    if (dest && dest != environment(this_object())) {
        move_object(this_object(), dest);
    }
}

// ── 逃跑邏輯 ─────────────────────────────────────────────────────
void do_flee() {
    say(query_name() + " 見勢不妙，拔腿逃跑！\n");
    stop_combat();
    // 嘗試隨機往相鄰房間移動
    object env = environment(this_object());
    if (env) {
        mixed exits = env->query_exits();
        if (exits && sizeof(exits) > 0) {
            mixed dirs = keys(exits);
            string dir = dirs[random(sizeof(dirs))];
            object dest = load_object(exits[dir]);
            if (dest) move_object(this_object(), dest);
        }
    }
}

// ── 戰鬥：NPC 攻擊 ───────────────────────────────────────────────
void do_attack() {
    if (!combat_target || is_dead) { return; }

    tell_object(combat_target, "【除錯】NPC 發起攻擊判定...\n");

    // 特殊攻擊判定
    if (special_atk != "" && random(100) < special_atk_chance) {
        do_special_attack();
        return;
    }

    int hit_roll   = random(100);
    int hit_chance = HIT_RATE_BASE + (stat_dex - combat_target->query_stat(STAT_DEX));
    if (hit_roll > hit_chance) {
        tell_object(combat_target,
            query_name() + " 攻擊你，但沒打中！\n");
        return;
    }

    int raw = attack - combat_target->query_defence();
    if (raw < 1) { raw = 1; }
    int variation = random(raw / 3 + 1);
    raw = raw - variation / 2 + random(variation);

    string crit_str = "";
    if (random(100) < CRIT_RATE_BASE) {
        raw = raw * CRIT_MULTIPLIER;
        crit_str = "【暴擊！】";
    }

    combat_target->take_damage(raw);
    tell_object(combat_target,
        crit_str + query_name() + " 對你造成了 " + sprintf("%d", raw) + " 點傷害！" +
        "（你剩 " + sprintf("%d", combat_target->query_hp()) + "/" +
        sprintf("%d", combat_target->query_max_hp()) + " HP）\n");
    
    // 🚀 觸發對方的被攻擊判定（讓玩家自動反擊）
    combat_target->attacked_by(this_object());

    if (combat_target->query_hp() <= 0) {
        tell_object(combat_target, "你被 " + query_name() + " 擊倒了！\n");
        combat_target->die();
        stop_combat();
    }
}

// ── 特殊攻擊（子類別可 override）────────────────────────────────
void do_special_attack() {
    if (!combat_target || is_dead) return;
    int raw = (attack - combat_target->query_defence()) * 2;
    if (raw < 1) raw = 1;
    combat_target->take_damage(raw);
    tell_object(combat_target,
        "【特殊技：" + special_atk + "】" +
        query_name() + " 對你造成了 " + sprintf("%d", raw) + " 點傷害！\n");
    
    // 🚀 觸發對方的被攻擊判定
    combat_target->attacked_by(this_object());

    if (combat_target->query_hp() <= 0) {
        combat_target->die();
        stop_combat();
    }
}

// ── 心跳：AI 邏輯 ──────────────────────────────────────
void heart_beat() {
    if (is_dead) { return; }

    object me = this_object();
    object env = environment(me);
    if (env) {
       tell_room(env, "【除錯】NPC " + query_name() + " 心跳中，in_combat=" + sprintf("%d", in_combat) + "\n");
    }

    if (in_combat && combat_target) {
        tell_object(combat_target, "【除錯】NPC 戰鬥心跳執行中，目標：" + combat_target->query_name() + "\n");
        
        if (combat_target->query_hp() <= 0) {
            stop_combat();
            return;
        }
        
        // 🚀 檢查目標是否還在同一個房間
        if (environment(combat_target) != environment(this_object())) {
            stop_combat();
            return;
        }

        // 🚀 逃跑判定：血量低於門檻 且 機率命中
        if (hp * 100 / max_hp <= flee_hp_pct) {
            if (random(100) < flee_chance) {
                do_flee();
                return;
            }
        }
        
        do_attack();
        return;
    }

    // 🚀 使用 bitwise & 檢查行為旗標，可疊加多種行為
    
    // 1. 巡邏行為
    if ((behaviour & BEHAV_PATROL) && sizeof(patrol_rooms) > 0) {
        do_patrol();
        return;
    }

    // 2. 隨機移動行為
    if (move_range > 0 && wander_chance > 0) {
        if (random(100) < wander_chance) {
            do_wander();
        }
    }
}

// ── 被攻擊後，自動迎戰 ───────────────────────────────────────────
void attacked_by(object attacker) {
    if (is_dead) { return; }
    
    object env = environment(this_object());
    if (env && env->query_no_combat()) return;

    if (attacker) tell_object(attacker, "【除錯】NPC " + query_name() + " 收到來自你的攻擊。\n");

    // 🚀 強制開啟心跳，確保 AI 會執行攻擊
    set_heart_beat(1);

    if (!in_combat) {
        ::attacked_by(attacker);
        if (in_combat) { // 確保父類別沒有攔截
            if (aggro_msg && aggro_msg != "") {
                say(aggro_msg);
            } else {
                say(query_name() + " 怒目而視，準備反擊！\n");
            }
        }
    }
}

// ── 死亡 ─────────────────────────────────────────────────────────
void on_death() {
    say(query_name() + " 倒下了！\n");

    if (combat_target && living(combat_target)) {
        combat_target->gain_exp(exp_reward);
        tell_object(combat_target,
            "你獲得了 " + sprintf("%d", gold_reward) + " 枚金幣。\n");
        combat_target->gain_gold(gold_reward);
    }

    int i;
    for (i = 0; i < sizeof(drop_list); i++) {
        object item = clone_object(drop_list[i]);
        if (item) {
            move_object(item, environment(this_object()));
        }
    }

    if (respawn_time > 0) {
        call_out("respawn", respawn_time);
    }

    destruct(this_object());
}

// ── 重生 ─────────────────────────────────────────────────────────
void respawn() {
    // 子類別實作重生邏輯
}
