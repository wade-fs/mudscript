// std/combat.c - 戰鬥系統 mixin
// 繼承此檔後可獲得完整的玩家戰鬥指令

#include "/include/config.h"

// ── 攻擊動作（一回合） ──────────────────────────────────────
void do_combat_round() {
    object me = this_object();
    if (!in_combat || !combat_target) { return; }
    if (is_dead)                      { return; }

    object here = environment(me);
    if (here && here->query_no_combat()) {
        write("這裡禁止戰鬥！戰鬥中斷了。\n");
        stop_combat();
        return;
    }

    object target = combat_target;
    // 🚀 檢查目標是否還在同一個房間
    if (!target || environment(target) != here) {
        write("對象不在這裡，戰鬥結束了。\n");
        stop_combat();
        return;
    }

    if (target->query_hp() <= 0) {
        write("敵人已經死亡。\n");
        stop_combat();
        return;
    }

    // 命中判斷
    int hit_roll   = random(100);
    int hit_chance = HIT_RATE_BASE + stat_dex - target->query_stat(STAT_DEX);
    if (hit_roll > hit_chance) {
        write("你的攻擊沒有打中 " + target->query_name() + "！\n");
        say(query_name() + " 的攻擊打空了。\n");
        return;
    }

    // 傷害計算
    int raw = attack - target->query_defence();
    if (raw < 1) { raw = 1; }
    int variation = random(raw / 3 + 1);
    raw = raw - variation / 2 + random(variation + 1);

    // 暴擊判定
    string crit_str = "";
    if (random(100) < CRIT_RATE_BASE + stat_dex / 5) {
        raw = raw * CRIT_MULTIPLIER;
        crit_str = "【暴擊！】";
    }

    target->take_damage(raw);
    write(crit_str + "你對 " + target->query_name() +
          " 造成了 " + sprintf("%d", raw) + " 點傷害！" +
          "（對方剩 " + sprintf("%d", target->query_kee()) + "/" +
          sprintf("%d", target->query_max_kee()) + " 氣血）\n");
    say(crit_str + query_name() + " 攻擊了 " + target->query_name() + "！\n");

    target->attacked_by(this_object());

    if (target->query_hp() <= 0) {
        write("你擊敗了 " + target->query_name() + "！\n");
        say(query_name() + " 擊敗了 " + target->query_name() + "！\n");
        
        // 🚀 PK 判定
        load_object("/secure/pk_d.c")->check_kill_penalty(this_object(), target);

        stop_combat();
        target->die();
    }
}

// ── 心跳觸發戰鬥回合 ────────────────────────────────────────
void combat_heart_beat() {
    if (in_combat && combat_target) {
        do_combat_round();
    }
}

// ── 指令：kill / attack ──────────────────────────────────────
int do_kill(string arg) {
    // 🚀 幻影模式攔截
    if (this_object()->query_current_mudlib() != "") {
        write("你目前處於幻影狀態，無法干涉這個世界的因果。\n");
        return 1;
    }
    if (!arg) {
        write("你要攻擊誰？用法：kill <對象>\n");
        return 1;
    }
    if (is_dead) {
        write("你已經死了，無法戰鬥。\n");
        return 1;
    }

    object here = environment(this_object());
    if (!here) { write("你不在任何地方。\n"); return 1; }

    if (here->query_no_combat()) {
        write("這裡禁止戰鬥！\n");
        return 1;
    }

    // 在同一房間裡找到目標
    object target = present(arg, here);
    if (!target) {
        write("這裡沒有叫「" + arg + "」的東西。\n");
        return 1;
    }
    if (target == this_object()) {
        write("你無法攻擊自己。\n");
        return 1;
    }
    if (!living(target)) {
        write(target->query_name() + " 不是活物，你無法攻擊它。\n");
        return 1;
    }
    if (target->query_hp() <= 0) {
        write(target->query_name() + " 已經死了。\n");
        return 1;
    }

    in_combat     = 1;
    combat_target = target;

    write("你向 " + target->query_name() + " 發起攻擊！\n");
    say(query_name() + " 向 " + target->query_name() + " 發起攻擊！\n");

    do_combat_round();
    return 1;
}

// ── 指令：flee ───────────────────────────────────────────────
int do_flee(string arg) {
    if (!in_combat) {
        write("你並不在戰鬥中。\n");
        return 1;
    }

    // 50% 機率逃跑成功
    if (random(100) < 50) {
        stop_combat();
        write("你驚慌逃跑！\n");
        say(query_name() + " 落荒而逃！\n");
        return 1;
    }

    write("你試圖逃跑，但沒有成功！\n");
    return 1;
}

// ── 指令：skills ─────────────────────────────────────────────
int do_skills(string arg) {
    write("=== 三元基礎與內建招式 ===\n");
    write("  perform <招式ID> [目標] - 施展【力】【法】【物】三道專屬招式\n");
    write("  调息 / breathe          - 運轉心法恢復氣血(kee)、神識(sen)與精力(sp)\n");
    return 1;
}

// ── 基礎借法術式（消耗神識 sen） ────────────────────────────
int do_fireball(string arg) {
    // 🚀 幻影模式攔截
    if (this_object()->query_current_mudlib() != "") {
        write("你目前處於幻影狀態，無法施展破壞性的法術。\n");
        return 1;
    }
    int sen_cost = 20;
    if (!arg) { write("用法：perform dao_jiefa <目標>\n"); return 1; }
    
    object here = environment(this_object());
    if (here && here->query_no_combat()) {
        write("這裡禁止戰鬥，無法施放攻擊性法術！\n");
        return 1;
    }

    if (!use_sen(sen_cost)) {
        write("神識(sen)不足，無法引動借法印訣！（需要 " + sprintf("%d", sen_cost) + " 神識）\n");
        return 1;
    }

    object target = present(arg, here);
    if (!target || !living(target)) {
        write("找不到目標：" + arg + "\n");
        return 1;
    }

    int dmg = (stat_int + stat_spi) * 2 + random(20);
    target->take_damage(dmg);
    write("🔥 你掐動借法印訣向 " + target->query_name() + " 引動離火靈機，造成 " +
          sprintf("%d", dmg) + " 點法術傷害！\n");
    say(query_name() + " 掐動印訣引動了一道離火靈機！\n");
    tell_object(target, "🔥 " + query_name() +
        " 的離火印訣對你造成了 " + sprintf("%d", dmg) + " 點傷害！\n");

    target->attacked_by(this_object());

    if (target->query_kee() <= 0) {
        write("離火靈機將 " + target->query_name() + " 徹底擊潰！\n");
        target->die();
        stop_combat();
    } else if (!in_combat) {
        in_combat     = 1;
        combat_target = target;
    }
    return 1;
}

// ── 基礎回氣術式（消耗神識 sen） ────────────────────────────
int do_heal(string arg) {
    int sen_cost = 15;
    if (!use_sen(sen_cost)) {
        write("神識(sen)不足，無法凝神調理氣血！（需要 " + sprintf("%d", sen_cost) + " 神識）\n");
        return 1;
    }
    int heal_amount = stat_spi * 3 + random(15);
    heal_kee(heal_amount);
    write("✨ 你運轉靈機調理經脈，恢復了 " + sprintf("%d", heal_amount) + " 點氣血！" +
          "（氣血: " + sprintf("%d", hp) + "/" + sprintf("%d", max_hp) + "）\n");
    say(query_name() + " 凝神運氣，周身泛起微光。\n");
    return 1;
}
