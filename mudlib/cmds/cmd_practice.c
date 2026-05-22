// /cmds/cmd_practice.c
// 練習指令：自行修練技能

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("你要練習什麼？用法：practice <技能ID>\n");
        return 1;
    }

    string sid = trim(arg);
    object skill_d = load_object("/secure/skill_d.c");

    if (!skill_d->query_all_skills()[sid]) {
        write("沒有這種技能。\n");
        return 1;
    }

    if (me->query_skill(sid) <= 0) {
        write("你連這門功夫的門檻都還沒摸到，先找人領悟（學習）一下吧。\n");
        return 1;
    }

    if (me->query_hp() < 20 || me->query_mp() < 20) {
        write("你太累了，先休息一下吧。\n");
        return 1;
    }

    // 消耗資源
    me->take_damage(10);
    me->use_mp(10);

    // 練習效率：隨機 + 受屬性影響
    int gain = 2 + random(5);
    gain += me->query_stat("con") / 5;

    me->improve_skill(sid, gain);
    write("你勤加練習『" + skill_d->query_skill_name(sid) + "』，感覺熟練了一些。\n");
    say(me->query_name() + " 正專心地在那裡獨自比劃修練。\n");
    
    me->save();
    return 1;
}

string help() {
    return "【指令】\n" +
           "  practice <技能>    消耗體力與法力自行練習已學會的技能。\n";
}
