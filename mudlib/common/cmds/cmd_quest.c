// cmds/cmd_quest.c - 通用任務指令 (支援接取、查看、選擇分支)

#include "/include/ansi.h"

string *query_verbs()   { return ({ "quest", "quests" }); }
string query_category() { return "General"; }

int main(object me, string verb, string arg) {
    object qed = find_object("/daemon/quest_engine_d.c");
    if (!qed) qed = load_object("/daemon/quest_engine_d.c");

    string sub = "";
    string qid = "";
    string choice_id = "";
    if (arg && arg != "") {
        mixed *parts = explode(trim(arg), " ");
        if (sizeof(parts) > 0) sub = parts[0];
        if (sizeof(parts) > 1) qid = parts[1];
        if (sizeof(parts) > 2) choice_id = parts[2];
    }

    if (!sub || sub == "" || sub == "list") {
        mapping quests = me->query_quests();
        if (!mapp(quests) || sizeof(quests) == 0) {
            write("你目前沒有任何任務。\n");
            return 1;
        }
        write("{HIW}── 你的任務 ──{NOR}\n");
        string *qids = keys(quests);
        for (int i = 0; i < sizeof(qids); i++) {
            string q = qids[i];
            mixed pq = quests[q];
            if (!mapp(pq)) continue;
            string status = pq["status"] ? pq["status"] : "unknown";
            string qname = q;
            if (qed) {
                mapping qdef = qed->query_quest(q);
                if (qdef && qdef["name"]) qname = qdef["name"];
            }
            write("  [" + status + "] " + qname + " (" + q + ")\n");
        }
        return 1;
    }

    if (sub == "accept" && qid != "") {
        if (qed) qed->accept_quest(me, qid);
        return 1;
    }

    if (sub == "choose" && qid != "" && choice_id != "") {
        if (qed) qed->choose_branch(me, qid, choice_id);
        return 1;
    }

    if (sub == "info" && qid != "") {
        if (!qed) { write("任務系統不可用。\n"); return 1; }
        mapping qdef = qed->query_quest(qid);
        if (!qdef) { write("找不到任務：" + qid + "\n"); return 1; }
        write("{HIW}" + (qdef["name"] ? qdef["name"] : qid) + "{NOR}\n");
        if (qdef["desc"]) write(qdef["desc"] + "\n");
        mixed pq = me->query_quest(qid);
        if (mapp(pq)) {
            write("狀態：" + (pq["status"] ? pq["status"] : "unknown") + "\n");
            write("進度：階段 " + (pq["stage"] ? pq["stage"] : 0) + "\n");
        }
        return 1;
    }

    write("用法：quest [list|accept <id>|choose <id> <choice>|info <id>]\n");
    return 1;
}
