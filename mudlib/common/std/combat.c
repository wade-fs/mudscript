// std/combat.c - 通用戰鬥系統基底 (World-Agnostic)
// 世界層可繼承並覆寫具體戰鬥公式

#include "/include/config.h"
#include "/include/ansi.h"

int do_attack(object target) {
    if (!target || !living(target)) return 0;
    if (target->query_dead()) return 0;

    int dmg = this_object()->query_attack() - target->query_defence();
    if (dmg < 1) dmg = 1;

    int cur_hp = target->query_hp();
    cur_hp -= dmg;

    write("{RED}你攻擊了 " + to_string(target->query_short()) + " 造成 " + dmg + " 點傷害。{NOR}\n");
    tell_object(target, "{RED}" + to_string(this_object()->query_short()) + " 攻擊了你，造成 " + dmg + " 點傷害。{NOR}\n");

    if (cur_hp <= 0) {
        tell_object(target, "{RED}你死了！{NOR}\n");
        write("{YEL}" + to_string(target->query_short()) + " 被你擊敗了！{NOR}\n");
        if (function_exists("query_exp_reward", target)) {
            int exp_gain = (int)target->query_exp_reward();
            if (exp_gain > 0) this_object()->gain_exp(exp_gain);
        }
        if (function_exists("destruct_on_death", target)) {
            destruct(target);
        }
        return 1;
    } else {
        target->set_hp(cur_hp);
    }
    return 0;
}

void heart_beat_combat() {
    object target = this_object()->query_combat_target();
    if (!target || !living(target) || target->query_dead()) {
        this_object()->set_in_combat(0);
        this_object()->set_combat_target(0);
        return;
    }
    do_attack(target);
}
