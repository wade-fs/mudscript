// std/npc.c - NPC / 怪物基底類別

#include "/include/config.h"

inherit "/std/living.c";

// ── NPC 專屬欄位 ────────────────────────────────────────────────
int     exp_reward;    // 擊殺後給予的經驗值
int     gold_reward;   // 掉落金幣數量
mixed   drop_list;     // 掉落物清單：({"path/to/item.c", ...})
int     respawn_time;  // 重生時間（秒），0 = 不重生
string  aggro_msg;     // 主動攻擊時的訊息
mapping chat_topics;   // 詢問話題表：([ "topic": "response" ])

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

    set_heart_beat(1);
}

// init() 在玩家進入 NPC 所在房間時由 driver 呼叫
// 此處的 add_action 作為備援路徑；主路徑是 command_d -> cmd_ask.c -> do_chat()
void init() {
    add_action("do_ask_action", "ask");
}

// do_ask_action：備援詢問路徑（當 command_d 未攔截時觸發）
// 注意：若 command_d 已把 "ask" 路由到 cmd_ask.c，此 action 不會被呼叫
int do_ask_action(string arg) {
    object me = this_player();
    if (!arg || arg == "") return 0;

    string target_id, topic;
    if (sscanf(arg, "%s about %s", target_id, topic) != 2 ||
        target_id == "" || topic == "") {
        if (sscanf(arg, "%s %s", target_id, topic) != 2 ||
            target_id == "" || topic == "") {
            return 0;
        }
    }

    if (!id(target_id)) return 0;  // 問的不是我，讓其他 NPC 的 action 處理

    string my_name = query_name();
    tell_object(me, "你向 " + my_name + " 詢問關於「" + topic + "」的事。\n");
    say(me->query_name() + " 向 " + my_name + " 詢問了一些事。\n");

    if (!do_chat(me, topic)) {
        tell_object(me, my_name + " 只是看了看你，什麼也沒說。\n");
    }
    return 1;
}

// ── 設定 / 查詢 ──────────────────────────────────────────────────
void set_exp_reward(int v)   { exp_reward   = v; }
void set_gold_reward(int v)  { gold_reward  = v; }
void set_drop_list(mixed l)  { drop_list    = l; }
void set_respawn(int v)      { respawn_time = v; }
void set_aggro_msg(string s) { aggro_msg    = s; }
void set_chat_topic(string topic, string response) {
    if (!chat_topics) chat_topics = ([]);
    chat_topics[topic] = response;
}

mapping query_chat_topics() { return chat_topics; }

// ── 互動：對話 ───────────────────────────────────────────────────
// me：詢問者物件；topic：話題字串
// 回傳 1 表示有回應，0 表示無話可說
int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    if (!chat_topics) chat_topics = ([]);

    string my_name = query_name();

    // 查表：完全比對（支援中英文 topic）
    if (chat_topics[topic]) {
        tell_object(me, my_name + " 告訴你：「" + chat_topics[topic] + "」\n");
        return 1;
    }

    // 大小寫不敏感備援（英文 topic）
    string lc_topic = lower_case(topic);
    mixed ks = keys(chat_topics);
    int i;
    for (i = 0; i < sizeof(ks); i++) {
        if (lower_case(ks[i]) == lc_topic) {
            tell_object(me, my_name + " 告訴你：「" + chat_topics[ks[i]] + "」\n");
            return 1;
        }
    }

    // 預設回應
    if (topic == "here" || topic == "這裡") {
        tell_object(me, my_name + " 說：「這裡是新手村，是個好地方。」\n");
        return 1;
    }
    
    if (topic == "name" || topic == "名字") {
        tell_object(me, my_name + " 說：「我叫 " + my_name + "，請多指教。」\n");
        return 1;
    }

    // 內建 fallback：查詢可問的話題
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

// ── 心跳：AI 巡邏 ────────────────────────────────────────────────
void heart_beat() {
    if (is_dead) { return; }

    if (in_combat && combat_target) {
        if (combat_target->query_hp() <= 0) {
            in_combat     = 0;
            combat_target = 0;
            return;
        }
        do_attack();
        return;
    }
}

// ── 戰鬥：NPC 攻擊 ───────────────────────────────────────────────
void do_attack() {
    if (!combat_target || is_dead) { return; }

    int hit_roll = random(100);
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

    if (combat_target->query_hp() <= 0) {
        tell_object(combat_target, "你被 " + query_name() + " 擊倒了！\n");
        combat_target->die();
        in_combat     = 0;
        combat_target = 0;
    }
}

// ── 被攻擊後，自動迎戰 ───────────────────────────────────────────
void attacked_by(object attacker) {
    if (is_dead) { return; }
    if (!in_combat) {
        in_combat     = 1;
        combat_target = attacker;
        if (aggro_msg) {
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
