// /secure/channel_d.c
// 共用頻道守護進程

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/object.c";

mapping friend_channels;

void create() {
    ::create();
    friend_channels = ([]);
}

string get_channel_prefix(string type, string cid) {
    switch (type) {
        case "chat":   return "$HIW$【全域】$NOR$";
        case "area":   return "$HIC$【區域】$NOR$";
        case "guild":  return "$HIG$【組織】$NOR$";
        case "team":   return "$HIY$【團隊】$NOR$";
        case "friend": return "$HIM$【" + cid + "】$NOR$";
        case "sys":    return "$HIR$【系統】$NOR$";
        default:       return "【頻道】";
    }
}

void broadcast(string type, object sender, string msg, string cid) {
    if (!msg || msg == "") return;

    string prefix = get_channel_prefix(type, cid);
    string sender_name = sender ? get_name(sender) : "系統";
    string full_msg = prefix + sender_name + "：" + msg + "\n";

    object *all_users = users();
    if (!all_users) return;
    foreach (object u in all_users) {
        if (!u) continue;
        tell_object(u, full_msg);
    }
}
