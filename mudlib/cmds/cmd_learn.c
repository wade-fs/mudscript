// /cmds/cmd_learn.c
// 學習指令：向 NPC 學習技能

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("用法：learn <技能ID> from <NPC ID> [amount]\n");
        return 1;
    }

    string sid, target_id;
    int amount = 10; // 預設消耗 10 點潛能

    // 解析參數: learn sword from thoracic 20
    if (strsrch(arg, " from ") == -1) {
        write("你要向誰學習？用法：learn <技能ID> from <NPC ID>\n");
        return 1;
    }

    string *parts = explode(arg, " from ");
    sid = trim(parts[0]);
    string rest = trim(parts[1]);

    int sp = strsrch(rest, " ");
    if (sp == -1) {
        target_id = rest;
    } else {
        target_id = substr(rest, 0, sp);
        amount = to_int(substr(rest, sp + 1, strlen(rest) - sp - 1));
    }

    if (amount <= 0) amount = 10;

    object here = environment(me);
    object teacher = present(target_id, here);

    if (!teacher) {
        write("這裡沒有「" + target_id + "」。\n");
        return 1;
    }

    if (!living(teacher) || userp(teacher)) {
        write(teacher->query_name() + " 無法教導你任何東西。\n");
        return 1;
    }

    mapping teachable = teacher->query_skills_to_teach();
    if (!teachable || !teachable[sid]) {
        write(teacher->query_name() + " 搖搖頭說：我不會這門功夫，你找別人吧。\n");
        return 1;
    }

    int my_lv = me->query_skill(sid);
    int max_lv = teachable[sid];

    if (my_lv >= max_lv) {
        write(teacher->query_name() + " 說：你的『" + load_object("/secure/skill_d.c")->query_skill_name(sid) + "』造詣已經不在我之下了。\n");
        return 1;
    }

    // 執行學習
    if (load_object("/secure/skill_d.c")->learn_skill(me, sid, amount)) {
        say(me->query_name() + " 向 " + teacher->query_name() + " 請教了一些關於『" + sid + "』的竅門。\n");
        me->save();
    }

    return 1;
}

string help() {
    return "【指令】\n" +
           "  learn <技能> from <NPC> [數量]    消耗潛能向 NPC 學習技能。\n";
}
