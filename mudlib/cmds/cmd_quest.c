// /cmds/cmd_quest.c
// 任務查詢指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    mapping quests = me->query_quests();
    object quest_d = load_object("/secure/quest_d.c");

    if (!quests || sizeof(quests) == 0) {
        write("你目前沒有任何任務紀錄。\n");
        return 1;
    }

    write(HIW("\n=== 我的任務清單 ===\n"));
    mixed ks = keys(quests);
    foreach (string qid in ks) {
        mapping qdata = quests[qid];
        mapping info = quest_d->query_quest_info(qid);
        
        string status_str = (qdata["status"] == "active" ? HIG("[進行中]") : HIY("[已完成]"));
        write(status_str + " " + info["name"] + "\n");
        write("  描述：" + info["desc"] + "\n");
        
        if (qdata["status"] == "active" && info["goal"]) {
            mapping goal = info["goal"];
            int current = qdata["progress"]["count"];
            write(sprintf("  進度：%d / %d\n", current, goal["count"]));
        }
    }
    write(HIW("====================\n\n"));

    return 1;
}

string help() {
    return "【指令】\n" +
           "  quest    查看當前任務進度與完成紀錄\n";
}
