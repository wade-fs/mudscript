// /cmds/cmd_enable.c
// 心法設定指令：enable / jifa / 運功 / 心法

#include "/include/ansi.h"
#include "/include/globals.h"
inherit "/std/object";

int main(object me, string verb, string arg) {
    object skill_d = load_object("/secure/skill_d.c");
    mapping skills = me->query_skills();
    string cur_force = me->query("enabled_force");

    if (!arg || arg == "") {
        write(HIW "\n=== 當前運轉心法設定 (enable) ===\n" NOR);
        if (cur_force && me->query_skill(cur_force) > 0) {
            write(sprintf("  ● 當前激發心法：" HIG "%s" NOR " (等級 %d / %d)\n",
                skill_d->query_skill_name(cur_force),
                me->query_skill(cur_force),
                skill_d->query_max_level(cur_force)));
        } else {
            write("  ● 當前激發心法：" WHT "尚未設定（請先向出身師長請教心法，並以 enable <心法名稱> 設定）\n" NOR);
        }

        write(CYN "── 已習得之調息心法 ──\n" NOR);
        int found = 0;
        if (skills && sizeof(skills) > 0) {
            foreach (string sid in keys(skills)) {
                if (skill_d->query_skill_type(sid) == "force") {
                    found = 1;
                    int lv = me->query_skill(sid);
                    int exp = me->query_skill_exp(sid);
                    int req = skill_d->query_upgrade_exp(lv);
                    string mark = (sid == cur_force) ? HIG "[運轉中]" NOR : "        ";
                    write(sprintf("  %s %-18s (%s) : 等級 %2d  (熟練 %d/%d)\n",
                        mark, skill_d->query_skill_name(sid), sid, lv, exp, req));
                }
            }
        }
        if (!found) {
            write("  （尚未學會任何調息心法，可向自身出身場所的師長請教或探索領悟）\n");
        }
        write(HIW "=================================\n\n" NOR);
        return 1;
    }

    if (arg == "none" || arg == "off" || arg == "無") {
        me->set("enabled_force", 0);
        write(YEL "你散去了體內維持的心法運轉路線，恢復為尋常凡人吐納。\n" NOR);
        me->save();
        return 1;
    }

    string sid = skill_d->resolve_skill_id(arg);
    if (me->query_skill(sid) <= 0) {
        write(HIR "你尚未學會『" + arg + "』，無法將其設為運轉心法。\n" NOR);
        return 1;
    }

    if (skill_d->query_skill_type(sid) != "force") {
        write(HIR "『" + skill_d->query_skill_name(sid) + "』並非吐納調息類心法，無法用於日常調息運轉。\n" NOR);
        return 1;
    }

    me->set("enabled_force", sid);
    me->save();
    write(HIG "【心法設定】你將『" + skill_d->query_skill_name(sid) + "』設定為預設調息心法！\n" NOR);
    write(CYN "（日後使用 breathe / tuna / 吐納 / 凝神 / 調息 / 冥想 / 打坐 / 靜坐 時將自動運轉此心法）\n" NOR);
    return 1;
}

string *query_verbs() {
    return ({ "enable", "jifa", "心法", "運功" });
}

string query_category() {
    return select_lang(([ "en": "Action", "zh-TW": "行動", "zh-CN": "行动" ]));
}

string help() {
    return select_lang(([
        "en": "【Command】\n  enable [skill]    View or set your active inner cultivation/breathing skill.\n",
        "zh-TW": "【心法設定指令】\n  enable              查看目前激發的調息心法與已學心法列表。\n  enable <心法名稱>   設定預設運轉的心法（例如：enable 睡夢大法 或 enable dream_sleep）。\n",
        "zh-CN": "【心法设定指令】\n  enable              查看目前激发的调息心法与已学心法列表。\n  enable <心法名称>   设定预设运转的心法。\n"
    ]));
}
