// /cmds/cmd_quest.c
// 任務查詢指令

inherit "/std/object";

#include "/include/globals.h"

mixed query_verbs() {
    return ({ "quest", "quests", "task", "tasks" });
}

int main(object me, string verb, string arg) {
    mapping quests = me->query_quests();
    object quest_d = load_object("/secure/quest_d.c");
    object career_d = load_object(CAREER_D);

    object engine_d = load_object(QUEST_ENGINE_D);
    if (engine_d) {
        write(engine_d->query_all_status_report(me) + "\n");
    } else if (career_d) {
        write(career_d->query_all_chains_status(me) + "\n");
    }

    // 舊系統相容：僅顯示未由 QUEST_ENGINE_D 接管的遺留舊任務 (如 newbie_badge 等)
    if (quests && sizeof(quests) > 0) {
        mixed ks = keys(quests);
        int has_legacy = 0;
        string legacy_out = "";
        foreach (string qid in ks) {
            // 若新任務引擎已有該定義，不重複列出
            if (engine_d && engine_d->query_quest(qid)) continue;
            if (qid == "pass_village_ceremony" && engine_d && engine_d->query_quest("village_pass")) continue;

            mapping qdata = quests[qid];
            mapping info = quest_d ? quest_d->query_quest_info(qid) : 0;
            if (!info) continue;
            
            if (!has_legacy) {
                legacy_out += "$HIW$" + select_lang(([ "en": "\n=== Other Quests ===\n", "zh-TW": "\n=== 其他附屬歷練 ===\n", "zh-CN": "\n=== 其他附属历练 ===\n" ])) + "$NOR$";
                has_legacy = 1;
            }
            string status_str = (qdata["status"] == "active" ? "$HIG$" + select_lang(([ "en": "[Active]", "zh-TW": "[進行中]", "zh-CN": "[进行中]" ])) + "$NOR$" : "$HIY$" + select_lang(([ "en": "[Completed]", "zh-TW": "[已完成]", "zh-CN": "[已完成]" ])) + "$NOR$");
            legacy_out += status_str + " " + info["name"] + "\n";
            legacy_out += select_lang(([ "en": "  Desc: ", "zh-TW": "  描述：", "zh-CN": "  描述：" ])) + info["desc"] + "\n";
            
            if (qdata["status"] == "active" && info["goal"]) {
                mapping goal = info["goal"];
                int current = qdata["progress"]["count"];
                legacy_out += sprintf(select_lang(([ "en": "  Progress: %d / %d\n", "zh-TW": "  進度：%d / %d\n", "zh-CN": "  进度：%d / %d\n" ])), current, goal["count"]);
            }
        }
        if (has_legacy) {
            legacy_out += "$HIW$====================\n\n$NOR$";
            write(legacy_out);
        }
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
