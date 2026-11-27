// /secure/channel_d.c
// 共用頻道守護進程 (Channel Daemon)

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/object.c";

mapping friend_channels; // 自建/好友頻道 ([ "cid": ({ member_ids }) ])

void create() {
    ::create();
    friend_channels = ([]);
}

string get_channel_prefix(string type, string cid) {
    switch (type) {
        case "chat":   return "$HIW$【全域】$NOR$";
        case "area":   return "$HIC$【區域】$NOR$";
        case "guild":  return "$HIG$【公會】$NOR$";
        case "team":   return "$HIY$【團隊】$NOR$";
        case "friend": return "$HIM$【" + cid + "】$NOR$";
        case "sys":    return "$HIR$【系統】$NOR$";
        default:       return "【頻道】";
    }
}

int get_chat_cost(string type) {
    switch (type) {
        case "guild": return 1 * COIN_SILVER;     // 1 銀幣
        case "area":  return 100 * COIN_SILVER;   // 100 銀幣 = 1 金幣
        case "chat":  return 10000 * COIN_SILVER; // 10,000 銀幣
        default:      return 0;
    }
}

int join_friend_channel(object me, string cid) {
    if (!friend_channels[cid]) friend_channels[cid] = ({});
    if (member_array(me->get_id(), friend_channels[cid]) == -1) {
        friend_channels[cid] += ({ me->get_id() });
        write("$HIG$你加入了好友頻道：$NOR$" + cid + "\n");
        return 1;
    }
    return 0;
}

int leave_friend_channel(object me, string cid) {
    if (!friend_channels[cid]) return 0;
    friend_channels[cid] -= ({ me->get_id() });
    write("$HIR$你離開了好友頻道：$NOR$" + cid + "\n");
    return 1;
}

varargs void broadcast(string type, object sender, string msg, string cid) {
    if (!msg || msg == "") return;

    if (sender && userp(sender)) {
        int cost = get_chat_cost(type);
        if (cost > 0) {
            if (sender->query_money() < cost) {
                tell_object(sender, "$HIR$你的錢不夠支付發言費用！(需要 " + (cost / COIN_SILVER) + " 銀幣)\n$NOR$");
                return;
            }
            sender->add_money(-cost);
            tell_object(sender, "你支付了 " + (cost / COIN_SILVER) + " 銀幣的發言費。\n");
        }
    }

    string prefix = get_channel_prefix(type, cid);
    string sender_name = sender ? get_name(sender) : "系統";
    string full_msg = prefix + sender_name + "：" + msg + "\n";

    object *all_u = users();
    foreach (object u in all_u) {
        if (!u) continue;
        if (type != "friend" && function_exists("is_channel_open", u) && !u->is_channel_open(type)) {
            continue;
        }

        switch (type) {
            case "area":
                if (environment(u) && environment(sender) &&
                    base_name(environment(u)) == base_name(environment(sender))) {
                } else continue;
                break;

            case "guild":
                if (function_exists("query_guild", u) && function_exists("query_guild", sender) &&
                    u->query_guild() && sender->query_guild() &&
                    u->query_guild() == sender->query_guild()) {
                } else continue;
                break;

            case "team":
                if (function_exists("query_leader", sender) && function_exists("query_leader", u)) {
                    object s_leader = sender->query_leader();
                    object u_leader = u->query_leader();
                    if (s_leader && u_leader && s_leader == u_leader) {
                    } else continue;
                } else continue;
                break;

            case "friend":
                if (!friend_channels[cid] || member_array(u->get_id(), friend_channels[cid]) == -1) {
                    continue;
                }
                break;
        }

        tell_object(u, full_msg);
    }
}
