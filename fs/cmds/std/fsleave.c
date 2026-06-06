// /cmds/std/fsleave.c
// 結束跨服 session

#include <globals.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg) {
    if (!me->query_temp("ssh_session_id") && !me->query_temp("ssh_pending")) {
        write("你目前不在遠端連線狀態中。\n");
        return 1;
    }

    object ssh_d = load_object("/secure/ssh_d");
    if (ssh_d) {
        ssh_d->client_send_disconnect(me);
    }
    return 1;
}

string help() {
    return "【fsleave】斷開跨服連線，返回本機。\n";
}
