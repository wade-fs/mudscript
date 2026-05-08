// std/npc.c - NPC / 怪物基底類別

#include "/include/config.h"

inherit "/std/living.c";

// ── NPC 專屬欄位 ────────────────────────────────────────────
int     exp_reward;    // 擊殺後給予的經驗值
int     gold_reward;   // 掉落金幣數量
mixed   drop_list;     // 掉落物清單：({"path/to/item.c", ...})
int     respawn_time;  // 重生時間（秒），0 = 不重生
string  aggro_msg;     // 主動攻擊時的訊息

void create() {
    ::create();
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

    set_heart_beat(1);
}

// ── 設定 / 查詢 ─────────────────────────────────────────────
void set_exp_reward(int v)   { exp_reward   = v; }
void set_gold_reward(int v)  { gold_reward  = v; }
void set_drop_list(mixed l)  { drop_list    = l; }
void set_respawn(int v)      { respawn_time = v; }
void set_aggro_msg(string s) { aggro_msg    = s; }

// ── 心跳：AI 巡邏 ───────────────────────────────────────────
void heart_beat() {
    if (is_dead) { return; }

    // 如果正在戰鬥，呼叫戰鬥邏輯
    if (in_combat && combat_target) {
        if (combat_target->query_hp() <= 0) {
            in_combat     = 0;
            combat_target = 0;
            return;
        }
        do_attack();
        return;
    }

    // 掃描同一房間的活物，若是玩家就主動攻擊（預設不主動攻擊，子類別可覆寫）
}

// ── 戰鬥：NPC 攻擊 ──────────────────────────────────────────
void do_attack() {
    if (!combat_target || is_dead) { return; }

    // 命中判斷
    int hit_roll = random(100);
    int hit_chance = HIT_RATE_BASE + (stat_dex - combat_target->query_stat(STAT_DEX));
    if (hit_roll > hit_chance) {
        tell_object(combat_target,
            name + " 攻擊你，但沒打中！\n");
        return;
    }

    // 計算傷害
    int raw = attack - combat_target->query_defence();
    if (raw < 1) { raw = 1; }
    int variation = random(raw / 3 + 1);
    raw = raw - variation / 2 + random(variation);

    // 暴擊
    string crit_str = "";
    if (random(100) < CRIT_RATE_BASE) {
        raw = raw * CRIT_MULTIPLIER;
        crit_str = "【暴擊！】";
    }

    combat_target->take_damage(raw);
    tell_object(combat_target,
        crit_str + name + " 對你造成了 " + sprintf("%d", raw) + " 點傷害！" +
        "（你剩 " + sprintf("%d", combat_target->query_hp()) + "/" +
        sprintf("%d", combat_target->query_max_hp()) + " HP）\n");

    if (combat_target->query_hp() <= 0) {
        tell_object(combat_target, "你被 " + name + " 擊倒了！\n");
        combat_target->die();
        in_combat     = 0;
        combat_target = 0;
    }
}

// ── 被攻擊後，自動迎戰 ──────────────────────────────────────
void attacked_by(object attacker) {
    if (is_dead) { return; }
    if (!in_combat) {
        in_combat     = 1;
        combat_target = attacker;
        if (aggro_msg != "") {
            say(aggro_msg);
        } else {
            say(name + " 怒目而視，準備反擊！\n");
        }
    }
}

// ── 死亡 ────────────────────────────────────────────────────
void on_death() {
    say(name + " 倒下了！\n");

    // 發放獎勵給擊殺者
    if (combat_target && living(combat_target)) {
        combat_target->gain_exp(exp_reward);
        tell_object(combat_target,
            "你獲得了 " + sprintf("%d", gold_reward) + " 枚金幣。\n");
        combat_target->gain_gold(gold_reward);
    }

    // 掉落物品
    int i;
    for (i = 0; i < sizeof(drop_list); i++) {
        object item = clone_object(drop_list[i]);
        if (item) {
            move_object(item, environment(this_object()));
        }
    }

    // 計劃重生
    if (respawn_time > 0) {
        call_out("respawn", respawn_time);
    }

    destruct(this_object());
}

// ── 重生 ────────────────────────────────────────────────────
void respawn() {
    // 子類別實作重生邏輯
}
