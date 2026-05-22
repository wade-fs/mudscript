// /secure/channel_d.c
// 頻道守護進程 (Channel Daemon)

#include "/include/ansi.h"

void create() {}

// 取得顏色前綴
string get_channel_prefix(string type) {
    switch (type) {
        case "chat":  return HIW("【全域】");
        case "area":  return HIC("【區域】");
        case "guild": return HIG("【公會】");
        case "team":  return HIY("【團隊】");
        case "sys":   return HIR("【系統】");
        default:      return "【頻道】";
    }
}

void broadcast(string type, object sender, string msg) {
    if (!msg || msg == "") return;

    string prefix = get_channel_prefix(type);
    string sender_name = (sender ? sender->query_name() : "系統");
    string full_msg = prefix + sender_name + "：" + msg + "\n";

    object *users = users();
    foreach (object u in users) {
        if (!u || !u->is_channel_open(type)) continue;

        // 條件過濾
        switch (type) {
            case "area":
                if (environment(u) && environment(sender) && 
                    base_name(environment(u)) == base_name(environment(sender))) {
                    // 同一個區域 (這裡簡化為同一個房間或鄰近目錄，我們先用同房)
                    // TODO: 真正的區域頻道應該判定目錄
                } else continue;
                break;
            
            case "guild":
                if (u->query_guild() && sender->query_guild() && 
                    u->query_guild() == sender->query_guild()) {
                } else continue;
                break;
            
            case "team":
                object s_leader = sender->query_leader();
                object u_leader = u->query_leader();
                if (s_leader && u_leader && s_leader == u_leader) {
                } else continue;
                break;
        }

        tell_object(u, full_msg);
    }
}
