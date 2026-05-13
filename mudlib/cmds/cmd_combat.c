// mudlib/cmds/cmd_combat.c
// 戰鬥指令守護進程：kill / attack / flee / skills / fireball / heal

#include "/include/config.h"

int main(object me, string verb, string arg) {
    switch (verb) {
        case "kill":
        case "attack":
            return do_kill_cmd(me, arg);
        case "flee":
            return do_flee_cmd(me, arg);
        case "skills":
            return do_skills_cmd(me, arg);
        case "fireball":
            return do_fireball_cmd(me, arg);
        case "heal":
            return do_heal_cmd(me, arg);
    }
    return 0;
}

int do_kill_cmd(object me, string arg) {
    return me->do_kill(arg);
}

int do_flee_cmd(object me, string arg) {
    return me->do_flee(arg);
}

int do_skills_cmd(object me, string arg) {
    return me->do_skills(arg);
}

int do_fireball_cmd(object me, string arg) {
    return me->do_fireball(arg);
}

int do_heal_cmd(object me, string arg) {
    return me->do_heal(arg);
}

string help() {
    return "【戰鬥指令】\n" +
           "  kill <對象>     向目標發起攻擊\n" +
           "  flee            嘗試從戰鬥中逃跑\n" +
           "  skills          列出可用技能\n" +
           "  fireball <目標> 施放火球術\n" +
           "  heal            施放治療術\n";
}
