// /cmds/cmd_party.c
// 組隊指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    string cmd, target_id;
    if (!arg || arg == "") cmd = "status";
    else {
        int sp = strsrch(arg, " ");
        if (sp == -1) {
            cmd = arg;
            target_id = "";
        } else {
            cmd = substr(arg, 0, sp);
            target_id = substr(arg, sp + 1, strlen(arg) - sp - 1);
        }
    }

    object party_d = load_object("/secure/party_d.c");

    switch (cmd) {
        case "create":
            return party_d->create_party(me);
        
        case "invite":
            if (target_id == "") { write("用法：party invite <玩家ID>\n"); return 1; }
            object invitee = find_player(target_id);
            if (!invitee) { write("找不到玩家 " + target_id + "。\n"); return 1; }
            return party_d->invite_player(me, invitee);
        
        case "join":
            if (target_id == "") { write("用法：party join <隊長ID>\n"); return 1; }
            object leader = find_player(target_id);
            if (!leader) { write("找不到玩家 " + target_id + "。\n"); return 1; }
            return party_d->join_party(me, leader);
        
        case "leave":
        case "disband":
            return party_d->leave_party(me);
        
        case "status":
        default:
            object my_leader = me->query_leader();
            if (!my_leader) {
                write("你目前不在任何隊伍中。\n");
            } else {
                write(HIW("\n=== 隊伍狀態 ===\n"));
                write("隊長：" + my_leader->query_name() + "\n");
                object *members = my_leader->query_followers();
                write("隊員：\n");
                foreach (object m in members) {
                    string role = (m == my_leader ? "[隊長]" : "[隊員]");
                    write("  " + role + " " + m->query_name() + "\n");
                }
                write(HIW("================\n\n"));
            }
            return 1;
    }
}

string help() {
    return "【組隊指令】\n" +
           "  party create           建立新隊伍\n" +
           "  party invite <ID>      邀請玩家加入隊伍\n" +
           "  party join <ID>        接受邀請加入隊伍\n" +
           "  party leave            離開當前隊伍\n" +
           "  party disband          解散隊伍 (僅限隊長)\n" +
           "  party status           查看隊伍成員與狀態\n";
}
