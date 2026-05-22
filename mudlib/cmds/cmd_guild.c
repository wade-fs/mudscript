// /cmds/cmd_guild.c
// 公會資訊指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    string gid = me->query_guild();
    object guild_d = load_object("/secure/guild_d.c");

    if (!gid) {
        write("你目前尚未加入任何公會或組織。\n");
        write("可用的公會：\n");
        mapping all = guild_d->query_all_guilds();
        mixed ks = keys(all);
        foreach (string k in ks) {
            write(sprintf("  %-12s : %s\n", k, all[k]["name"]));
        }
        return 1;
    }

    mapping info = guild_d->query_guild_info(gid);
    write(HIW("\n=== 所屬公會資訊 ===\n"));
    write("名稱：" + info["name"] + "\n");
    write("職位：" + me->query_guild_rank() + "\n");
    write("貢獻：" + me->query_guild_exp() + "\n");
    write("描述：" + info["desc"] + "\n");
    write(HIW("====================\n\n"));

    if (arg == "promote") {
        guild_d->promote_member(me);
    }

    return 1;
}

string help() {
    return "【指令】\n" +
           "  guild            查看目前所屬公會的資訊與職位。\n" +
           "  guild promote    嘗試向公會申請晉升職位。\n";
}
