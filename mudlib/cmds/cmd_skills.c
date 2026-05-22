// /cmds/cmd_skills.c
// 技能查看指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    mapping skills = me->query_skills();
    object skill_d = load_object("/secure/skill_d.c");

    write(HIW("\n=== 技能狀態 (潛能: " + me->query_potential() + ") ===\n"));

    if (!skills || sizeof(skills) == 0) {
        write("你目前尚未學會任何技能。\n");
    } else {
        mixed ks = keys(skills);
        foreach (string sid in ks) {
            mapping sdata = skills[sid];
            int lv = sdata["level"];
            int exp = sdata["exp"];
            int req = skill_d->query_upgrade_exp(lv);
            
            string progress = sprintf("%d/%d", exp, req);
            write(sprintf("  %-12s：等級 %3d  (進度 %s)\n", 
                skill_d->query_skill_name(sid), lv, progress));
        }
    }
    write(HIW("==================================\n\n"));

    return 1;
}

string help() {
    return "【指令】\n" +
           "  skills    查看你目前所具備的各項技能等級與潛能點數。\n";
}
