// /cmds/cmd_quest.c
// 任務查詢指令

inherit "/std/object";

#include "/include/globals.h"

int main(object me, string verb, string arg) {
    mapping quests = me->query_quests();
    object quest_d = load_object("/secure/quest_d.c");
    object career_d = load_object(CAREER_D);

    if (quests && sizeof(quests) > 0) {
        write("$HIW$" + select_lang(([ "en": "\n=== My Quest List ===\n", "zh-TW": "\n=== 我的任務清單 ===\n", "zh-CN": "\n=== 我的任务清单 ===\n" ])) + "$NOR$");
        mixed ks = keys(quests);
        foreach (string qid in ks) {
            mapping qdata = quests[qid];
            mapping info = quest_d ? quest_d->query_quest_info(qid) : 0;
            if (!info) continue;
            
            string status_str = (qdata["status"] == "active" ? "$HIG$" + select_lang(([ "en": "[Active]", "zh-TW": "[進行中]", "zh-CN": "[进行中]" ])) + "$NOR$" : "$HIY$" + select_lang(([ "en": "[Completed]", "zh-TW": "[已完成]", "zh-CN": "[已完成]" ])) + "$NOR$");
            write(status_str + " " + info["name"] + "\n");
            write(select_lang(([ "en": "  Desc: ", "zh-TW": "  描述：", "zh-CN": "  描述：" ])) + info["desc"] + "\n");
            
            if (qdata["status"] == "active" && info["goal"]) {
                mapping goal = info["goal"];
                int current = qdata["progress"]["count"];
                write(sprintf(select_lang(([ "en": "  Progress: %d / %d\n", "zh-TW": "  進度：%d / %d\n", "zh-CN": "  进度：%d / %d\n" ])), current, goal["count"]));
            }
        }
        write("$HIW$====================\n\n$NOR$");
    }

    object engine_d = load_object(QUEST_ENGINE_D);
    if (engine_d) {
        write(engine_d->query_all_status_report(me) + "\n");
    } else if (career_d) {
        write(career_d->query_all_chains_status(me) + "\n");
    }

    return 1;
}

string help() {
    return select_lang(([
        "en": "【Command】\n  quest    View current quest progress and completion records.\n",
        "zh-TW": "【指令】\n  quest    查看當前任務進度與完成紀錄\n",
        "zh-CN": "【指令】\n  quest    查看当前任务进度与完成纪录\n"
    ]));
}
