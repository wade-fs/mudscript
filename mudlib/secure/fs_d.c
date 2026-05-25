// /secure/fs_d.c
// Fantasy Space P2P 跨服守護進程 - Driver 聯動版
// 核心邏輯：依賴 Driver 的 ResolvePath 進行自動沙盒映射

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

mapping joined_muds;
mapping room_cache;
mapping pending_travel;

void create() {
    ::create();
    if (!joined_muds) joined_muds = ([]);
    if (!room_cache)  room_cache  = ([]);
    if (!pending_travel) pending_travel = ([]);
}

mapping query_joined_muds() { return joined_muds; }

int is_joined(string mudlib_id) {
    if (!joined_muds || !mapp(joined_muds[mudlib_id])) return 0;
    return (joined_muds[mudlib_id]["status"] == "active");
}

string init_fsgoto(object me, string mudlib_id) {
    if (!mudlib_id || mudlib_id == "") return "用法：fsgoto <mudlib_id>\n";
    if (mudlib_id == FS_MUDLIB_ID) return "你已經在本機伺服器了。\n";

    if (is_joined(mudlib_id)) {
        string entrance = joined_muds[mudlib_id]["entrance"];
        if (!entrance || entrance == "") return "無法取得該伺服器的入口點。\n";

        write(HIM("【傳送門】你踏入了一陣扭曲的光芒中，前往了星際網路的彼端...\n"));
        object dest = get_remote_room(mudlib_id, entrance);
        if (dest) {
            me->move(dest, "portal");
            dest->look_room(me);
            return "";
        }
        return RED("傳送失敗：無法載入目標房間。\n");
    }

    if (!pending_travel[mudlib_id]) pending_travel[mudlib_id] = ({});
    pending_travel[mudlib_id] += ({ me });

    if (!joined_muds[mudlib_id]) {
        do_join(me, mudlib_id);
    }

    return HIW("[Fantasy Space] ") + "正在查詢 " + mudlib_id + " 的資訊並準備傳送...\n";
}

string do_join(object me, string mudlib_id) {
    if (joined_muds[mudlib_id]) return "";

    joined_muds[mudlib_id] = ([
        "hub_url":   FS_HUB_URL,
        "joined_at": time(),
        "status":    "pending"
    ]);

    p2p_send_fs_query(mudlib_id, "info", "");
    return "";
}

void remove_cached_rooms(string mudlib_id) {
    string prefix = "/fs_remote/" + mudlib_id;
    object ob;
    foreach (ob in objects()) {
        if (!ob || ob == this_object()) continue; 
        if (strsrch(object_name(ob), prefix) == 0) destruct(ob);
    }
}

object get_remote_room(string mudlib_id, string remote_room_path) {
    string cache_key = mudlib_id + ":" + remote_room_path;
    if (room_cache[cache_key]) {
        string virt_path = FS_CACHE_DIR + "/" + mudlib_id + remote_room_path;
        return load_object(virt_path);
    }
    p2p_send_fs_query(mudlib_id, "room", remote_room_path);
    return get_loading_placeholder(mudlib_id, remote_room_path);
}

void list_muds(object me) {
    p2p_send_fs_query("*", "list", "");
}

void receive_fs_response(string mudlib_id, string resp_type, string payload) {
    if (resp_type == "list") {
        string *muds = explode(payload, ",");
        string output = HIW("\n【Fantasy Space 星際節點清單】\n");
        foreach (string mud in muds) {
            string *parts = explode(mud, "|");
            if (sizeof(parts) >= 2) {
                output += sprintf("  %-20s : %s\n", parts[0], parts[1]);
            }
        }
        foreach (object u in users()) { 
            if (u && userp(u)) tell_object(u, output + "\n"); 
        }
        return;
    }

    if (resp_type == "info") {
        string *parts = explode(payload, "|");
        if (sizeof(parts) >= 4) {
            if (!joined_muds[mudlib_id]) {
                joined_muds[mudlib_id] = ([ "hub_url": FS_HUB_URL, "joined_at": time() ]);
            }
            joined_muds[mudlib_id]["status"] = "active";
            joined_muds[mudlib_id]["name"] = parts[2];
            joined_muds[mudlib_id]["entrance"] = parts[3];

            if (pending_travel[mudlib_id]) {
                foreach (object p in pending_travel[mudlib_id]) { 
                    if (p && environment(p)) init_fsgoto(p, mudlib_id); 
                }
                m_delete(pending_travel, mudlib_id);
            }
        }
    } else if (resp_type == "room") {
        int sep = strsrch(payload, "|");
        if (sep < 0) return;
        
        string room_path = substr(payload, 0, sep);
        string lpc_src   = substr(payload, sep + 1, strlen(payload) - sep - 1);
        if (!lpc_src || lpc_src == "") return;

        string file = FS_CACHE_DIR + "/" + mudlib_id + room_path;
        
        if (write_file(file, lpc_src, 1)) {
            room_cache[mudlib_id + ":" + room_path] = 1;
            notify_waiting_players(mudlib_id, room_path);
            scan_and_fetch_dependencies(mudlib_id, lpc_src);
        }
    }
}

void scan_and_fetch_dependencies(string mudlib_id, string src) {
    string *lines = explode(src, "\n");
    foreach (string line in lines) {
        int q1 = -1;
        while ((q1 = strsrch(line, "\"", q1 + 1)) != -1) {
            int q2 = strsrch(line, "\"", q1 + 1);
            if (q2 == -1) break;
            string path = substr(line, q1 + 1, q2 - q1 - 1);
            if (strlen(path) > 1 && path[0] == '/' && 
                strsrch(path, "/std/") != 0 && 
                strsrch(path, "/include/") != 0 && 
                strsrch(path, "/secure/") != 0 &&
                strsrch(path, FS_CACHE_DIR) != 0) {
                
                string local_file = FS_CACHE_DIR + "/" + mudlib_id + path;
                if (file_size(local_file) == -1) {
                    p2p_send_fs_query(mudlib_id, "room", path);
                }
            }
            q1 = q2;
        }
    }
}

object get_loading_placeholder(string mudlib_id, string room_path) {
    object ob = clone_object("/std/fs_loading_room");
    if (ob) {
        ob->set_target_mudlib(mudlib_id);
        ob->set_target_room(room_path);
    }
    return ob;
}

void notify_waiting_players(string mudlib_id, string room_path) {
    foreach (object u in users()) {
        if (!u || !userp(u)) continue;
        object env = environment(u);
        if (env && env->query_is_loading_room() && 
            env->query_target_mudlib() == mudlib_id && 
            env->query_target_room() == room_path) {
            string file = FS_CACHE_DIR + "/" + mudlib_id + room_path;
            if (file_size(file) > 0) {
                object dest = load_object(file);
                if (dest) {
                    u->move(dest, "portal");
                    dest->look_room(u);
                }
            }
        }
    }
}

void p2p_send_fs_query(string mudlib_id, string type, string payload) {
    p2p_broadcast("fs_query|" + FS_MUDLIB_ID + "|" + mudlib_id + "|" + type + "|" + payload);
}

void handle_fs_query(string from_mudlib, string type, string payload) {
    if (type == "info") {
        string resp = FS_MUDLIB_ID + "|info|" + FS_MUDLIB_NAME + "|" + START_ROOM;
        p2p_broadcast("fs_resp|" + FS_MUDLIB_ID + "|" + from_mudlib + "|info|" + resp);
    } else if (type == "list") {
        string resp = FS_MUDLIB_NAME + "|" + FS_MUDLIB_ID;
        mixed ks = keys(joined_muds);
        foreach (string mid in ks) {
            resp += "," + joined_muds[mid]["name"] + "|" + mid;
        }
        p2p_broadcast("fs_resp|" + FS_MUDLIB_ID + "|" + from_mudlib + "|list|" + resp);
    } else if (type == "room") {
        string src = read_file("/mudlib" + payload);
        if (!src) src = read_file(payload);
        if (!src) src = "";
        p2p_broadcast("fs_resp|" + FS_MUDLIB_ID + "|" + from_mudlib + "|room|" + payload + "|" + src);
    }
}
