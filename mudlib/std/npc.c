// std/npc.c - NPC / 怪物基底類別

#include "/include/config.h"

inherit "/std/living.c";

// ── NPC 專屬欄位 ────────────────────────────────────────────────
int     exp_reward;    // 擊殺後給予的經驗值
int     gold_reward;   // 掉落金幣數量
mixed   drop_list;     // 掉落物清單：({"/path/item.c", ...})
int     respawn_time;  // 重生時間（秒），0 = 不重生
string  aggro_msg;     // 主動攻擊時的訊息
mapping chat_topics;   // 詢問話題表：([ "topic": "response" ])

// ── 新增：棲息地與行為模式 ──────────────────────────────────────
string  habitat;       // HABITAT_LAND / WATER / UNDERGROUND / SKY / CAVE
string  behaviour;     // BEHAV_PASSIVE / AGGRESSIVE / GUARD / PATROL / FLEE
int     aggro_range;   // 主動攻擊偵測範圍（格數，0=不主動）
int     flee_hp_pct;   // 逃跑血量百分比（BEHAV_FLEE 用，預設30）
mixed   patrol_rooms;  // 巡邏路線 ({"/area/newbie/room_x_y.c", ...})
int     patrol_idx;    // 目前巡邏位置索引
int     sight_flags;   // 位元旗標: 1=夜視, 2=水中視覺, 4=隱形偵測
string  special_atk;   // 特殊攻擊名稱（空=無）
int     special_atk_chance; // 特殊攻擊機率 (0~100)

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
    chat_topics = ([]);

    // 預設值
    habitat          = HABITAT_LAND;
    behaviour        = BEHAV_PASSIVE;
    aggro_range      = 0;
    flee_hp_pct      = 30;
    patrol_rooms     = ({});
    patrol_idx       = 0;
    sight_flags      = 0;
    special_atk      = "";
    special_atk_chance = 0;

    set_heart_beat(1);
}

// init() 在玩家進入 NPC 所在房間時由 driver 呼叫
// ⚠️  不在這裡掛 add_action("ask")：
//     "ask" 已由 command_d → cmd_ask.c 統一處理。
//     若再 add_action，driver action 與 command_d 都觸發，造成重複輸出。
void init() {
}

// ── 設定 / 查詢 ──────────────────────────────────────────────────
void set_exp_reward(int v)         { exp_reward        = v; }
void set_gold_reward(int v)        { gold_reward       = v; }
void set_drop_list(mixed l)        { drop_list         = l; }
void set_respawn(int v)            { respawn_time      = v; }
void set_aggro_msg(string s)       { aggro_msg         = s; }
void set_habitat(string h)         { habitat           = h; }
void set_behaviour(string b)       { behaviour         = b; }
void set_aggro_range(int v)        { aggro_range       = v; }
void set_flee_hp_pct(int v)        { flee_hp_pct       = v; }
void set_patrol_rooms(mixed r)     { patrol_rooms      = r; }
void set_sight_flags(int v)        { sight_flags       = v; }
void set_special_atk(string s, int pct) {
    special_atk        = s;
    special_atk_chance = pct;
}
void set_chat_topic(string topic, string response) {
    if (!chat_topics) chat_topics = ([]);
    chat_topics[topic] = response;
}

string  query_habitat()       { return habitat; }
string  query_behaviour()     { return behaviour; }
int     query_aggro_range()   { return aggro_range; }
mapping query_chat_topics()   { return chat_topics; }

// ── 互動：對話 ───────────────────────────────────────────────────
int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    if (!chat_topics) chat_topics = ([]);

    string my_name = query_name();

    if (chat_topics[topic]) {
        tell_object(me, my_name + " 告訴你：「" + chat_topics[topic] + "」\n");
        return 1;
    }

    string lc_topic = lower_case(topic);
    mixed ks = keys(chat_topics);
    int i;
    for (i = 0; i < sizeof(ks); i++) {
        if (lower_case(ks[i]) == lc_topic) {
            tell_object(me, my_name + " 告訴你：「" + chat_topics[ks[i]] + "」\n");
            return 1;
        }
    }

    if (topic == "here" || topic == "這裡") {
        tell_object(me, my_name + " 說：「這裡是新手村，是個好地方。」\n");
        return 1;
    }
    if (topic == "name" || topic == "名字") {
        tell_object(me, my_name + " 說：「我叫 " + my_name + "，請多指教。」\n");
        return 1;
    }
    if (lc_topic == "topics" || topic == "話題" || topic == "topic") {
        mixed t_keys = keys(chat_topics);
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

// ── 心跳：AI 巡邏 + 逃跑 ─────────────────────────────────────────
void heart_beat() {
    if (is_dead) { return; }

    if (in_combat && combat_target) {
        if (combat_target->query_hp() <= 0) {
            in_combat     = 0;
            combat_target = 0;
            return;
        }
        // BEHAV_FLEE：血量不足時逃跑
        if (behaviour == BEHAV_FLEE &&
            hp * 100 / max_hp <= flee_hp_pct) {
            do_flee();
            return;
        }
        do_attack();
        return;
    }

    // BEHAV_PATROL：沒在戰鬥時巡邏
    if (behaviour == BEHAV_PATROL &&
        sizeof(patrol_rooms) > 0) {
        do_patrol();
    }
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
    in_combat     = 0;
    combat_target = 0;
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
        crit_str + query_name() + " 對你造成了 " + raw + " 點傷害！" +
        "（你剩 " + combat_target->query_hp() + "/" +
        combat_target->query_max_hp() + " HP）\n");

    if (combat_target->query_hp() <= 0) {
        tell_object(combat_target, "你被 " + query_name() + " 擊倒了！\n");
        combat_target->die();
        in_combat     = 0;
        combat_target = 0;
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
        query_name() + " 對你造成了 " + raw + " 點傷害！\n");
    if (combat_target->query_hp() <= 0) {
        combat_target->die();
        in_combat = 0;
        combat_target = 0;
    }
}

// ── 被攻擊後，自動迎戰 ───────────────────────────────────────────
void attacked_by(object attacker) {
    if (is_dead) { return; }
    if (!in_combat) {
        in_combat     = 1;
        combat_target = attacker;
        if (aggro_msg && aggro_msg != "") {
            say(aggro_msg);
        } else {
            say(query_name() + " 怒目而視，準備反擊！\n");
        }
    }
}

// ── 死亡 ─────────────────────────────────────────────────────────
void on_death() {
    say(query_name() + " 倒下了！\n");

    if (combat_target && living(combat_target)) {
        combat_target->gain_exp(exp_reward);
        tell_object(combat_target,
            "你獲得了 " + gold_reward + " 枚金幣。\n");
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
