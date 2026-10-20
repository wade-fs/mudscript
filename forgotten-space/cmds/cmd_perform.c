// /cmds/cmd_perform.c
// 施展特殊招式指令

inherit "/std/object";

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write(select_lang(([ "en": "What skill do you want to perform? Usage: perform <skill_id> [target]\n", "zh-TW": "你要施展什麼招式？用法：perform <招式ID> [目標]\n", "zh-CN": "你要施展什么招式？用法：perform <招式ID> [目标]\n" ])));
        return 1;
    }

    string sid, target;
    int sp = strsrch(arg, " ");
    if (sp == -1) {
        sid = arg;
        target = "";
    } else {
        sid = substr(arg, 0, sp);
        target = substr(arg, sp + 1, strlen(arg) - sp - 1);
    }

    return load_object("/secure/combat_d.c")->do_perform(me, sid, target);
}

string help() {
    return select_lang(([
        "en": "【Combat Command】\n  perform <skill> [target]    Perform path-specific techniques of Force (li), Spirit (fa), or Matter (wu).\n  (e.g.: perform wu_fuhu, perform dao_jiefa, perform gong_qiaojin)\n",
        "zh-TW": "【戰鬥指令】\n  perform <招式> [目標]    施展【力】【法】【物】三道專屬招式、符印或機巧。\n  (例如：perform wu_fuhu, perform dao_jiefa, perform gong_qiaojin)\n",
        "zh-CN": "【战斗指令】\n  perform <招式> [目标]    施展【力】【法】【物】三道专属招式、符印或机巧。\n  (例如：perform wu_fuhu, perform dao_jiefa, perform gong_qiaojin)\n"
    ]));
}

string *query_verbs() {
    return ({ "perform" });
}

string query_category() {
    return select_lang(([ "en": "Combat", "zh-TW": "戰鬥", "zh-CN": "战斗" ]));
}
