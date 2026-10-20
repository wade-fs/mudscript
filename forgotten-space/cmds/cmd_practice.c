// /cmds/cmd_practice.c
// 練習指令：自行修練技能

inherit "/std/object";

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write(select_lang(([ "en": "What do you want to practice? Usage: practice <skill_id>\n", "zh-TW": "你要練習什麼？用法：practice <技能ID>\n", "zh-CN": "你要练习什么？用法：practice <技能ID>\n" ])));
        return 1;
    }

    string sid = trim(arg);
    object skill_d = load_object("/secure/skill_d.c");
    sid = skill_d->resolve_skill_id(sid);

    mapping s_def = skill_d->query_all_skills()[sid];
    if (!s_def) {
        write(select_lang(([ "en": "No such skill.\n", "zh-TW": "沒有這種技能。\n", "zh-CN": "没有这种技能。\n" ])));
        return 1;
    }

    if (me->query_skill(sid) <= 0) {
        write(select_lang(([ "en": "You haven't even grasped the basics of this skill. Find someone to learn from first.\n", "zh-TW": "你連這門功夫的門檻都還沒摸到，先找人領悟（學習）一下吧。\n", "zh-CN": "你连这门功夫的门槛都还没摸到，先找人领悟（学习）一下吧。\n" ])));
        return 1;
    }

    string pool = s_def["cost_pool"];
    int gain = 2 + random(5);

    if (pool == "sen") {
        if (me->query_sen() < 20 || me->query_sp() < 10) {
            write(select_lang(([ "en": "Your spirit (sen) or stamina (sp) is too low, rest for a while.\n", "zh-TW": "你的神識(sen)或精力(sp)不足，先調息片刻吧。\n", "zh-CN": "你的神识(sen)或精力(sp)不足，先调息片刻吧。\n" ])));
            return 1;
        }
        me->use_sen(10);
        me->use_sp(5);
        gain += (me->query_stat("int") + me->query_stat("spi")) / 8;
    } else if (pool == "sp") {
        if (me->query_sp() < 20 || me->query_kee() < 15) {
            write(select_lang(([ "en": "Your stamina (sp) or vitality (kee) is too low, rest for a while.\n", "zh-TW": "你的精力(sp)或氣血(kee)不足，先歇息片刻吧。\n", "zh-CN": "你的精力(sp)或气血(kee)不足，先歇息片刻吧。\n" ])));
            return 1;
        }
        me->use_sp(10);
        me->use_kee(5);
        gain += (me->query_stat("dex") + me->query_stat("per")) / 8;
    } else {
        if (me->query_kee() < 20 || me->query_sp() < 10) {
            write(select_lang(([ "en": "Your vitality (kee) or stamina (sp) is too low, rest for a while.\n", "zh-TW": "你的氣血(kee)或精力(sp)不足，先調息一下吧。\n", "zh-CN": "你的气血(kee)或精力(sp)不足，先调息一下吧。\n" ])));
            return 1;
        }
        me->use_kee(10);
        me->use_sp(5);
        gain += (me->query_stat("str") + me->query_stat("con")) / 8;
    }

    me->improve_skill(sid, gain);
    write(select_lang(([ "en": "You practice '", "zh-TW": "你勤加練習『", "zh-CN": "你勤加练习『" ])) + skill_d->query_skill_name(sid) + select_lang(([ "en": "' diligently and feel more proficient.\n", "zh-TW": "』，感覺熟練了一些。\n", "zh-CN": "』，感觉熟练了一些。\n" ])));
    say(me->query_name() + select_lang(([ "en": " is practicing alone here.\n", "zh-TW": " 正專心地在那裡獨自比劃修練。\n", "zh-CN": " 正专心地在那里独自比划修练。\n" ])));
    
    me->save();
    return 1;
}

string help() {
    return select_lang(([
        "en": "【Command】\n  practice <skill>    Consume KEE, SEN or SP to practice a learned skill.\n",
        "zh-TW": "【指令】\n  practice <技能>    依技能道途消耗氣血(kee)、神識(sen)或精力(sp)自行修練已領悟的技藝。\n",
        "zh-CN": "【指令】\n  practice <技能>    依技能道途消耗气血(kee)、神识(sen)或精力(sp)自行修练已领悟的技艺。\n"
    ]));
}

string *query_verbs() {
    return ({ "practice" });
}

string query_category() {
    return select_lang(([ "en": "Combat", "zh-TW": "戰鬥", "zh-CN": "战斗" ]));
}
