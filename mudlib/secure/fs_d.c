// /secure/fs_d.c
// Fantasy Space P2P 跨服守護進程
// 實作：Clone Room 懶加載策略
//   - fsjoin "other.mud"  → 登記遠端 mudlib，玩家進入遠端出口時才 fetch
//   - fsleave "other.mud" → 清空該遠端的緩存與出口
//   - fsflush "other.mud" → 重新拉取已緩存的遠端資料

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

// joined_muds: ([ "other.mud": ([ "hub_url": "wss://...", "joined_at": 12345 ]) ])
mapping joined_muds;

// room_cache: ([ "other.mud:/area/newbie/room_0_0": lpc_source_string ])
mapping room_cache;

// exit_map: 本地出口 -> 遠端 mudlib room
// ([ "/area/newbie/room_4_4.c:portal_east": ([ "mudlib": "other.mud", "room": "/area/newbie/room_0_0.c" ]) ])
mapping exit_map;

void create() {
    ::create();
    if (!joined_muds) joined_muds = ([]);
    if (!room_cache)  room_cache  = ([]);
    if (!exit_map)    exit_map    = ([]);
}

// ── 查詢 ──────────────────────────────────────────────
mapping query_joined_muds() { return joined_muds; }
mapping query_room_cache()  { return room_cache; }
mapping query_exit_map()    { return exit_map; }

int is_joined(string mudlib_id) {
    return (joined_muds && mapp(joined_muds[mudlib_id]));
}

// ── fsjoin：登記遠端 mudlib ───────────────────────────
// 向 hub 查詢 mudlib_id 是否存在，登記後廣播給本地玩家
string do_join(object me, string mudlib_id) {
    if (!mudlib_id || mudlib_id == "")
        return "用法：fsjoin <mudlib_id>  例如：fsjoin fantasy.space\n";

    if (mudlib_id == FS_MUDLIB_ID)
        return "無法加入自己的 mudlib。\n";

    if (joined_muds[mudlib_id])
        return "已經加入 " + mudlib_id + " 了。\n";

    // 透過 P2P 向 hub 查詢（非同步；這裡先登記並等待 receive_fs_info 回呼）
    joined_muds[mudlib_id] = ([
        "hub_url":   FS_HUB_URL,
        "joined_at": time(),
        "status":    "pending"
    ]);

    // 傳送 fs_query 訊息給信令中心
    p2p_send_fs_query(mudlib_id, "info", "");

    return HIW("[Fantasy Space] ") + "正在查詢 " + mudlib_id + " 的資訊...\n";
}

// ── fsleave：離開並清空緩存 ───────────────────────────
string do_leave(object me, string mudlib_id) {
    if (!mudlib_id || mudlib_id == "")
        return "用法：fsleave <mudlib_id>\n";

    if (!joined_muds[mudlib_id])
        return "你尚未加入 " + mudlib_id + "。\n";

    // 移除 joined 登記
    map_delete(joined_muds, mudlib_id);

    // 清空 room_cache 中屬於該 mudlib 的項目
    mixed keys_to_del = ({});
    foreach (string k in keys(room_cache)) {
        if (strsrch(k, mudlib_id + ":") == 0)
            keys_to_del += ({ k });
    }
    foreach (string k in keys_to_del) {
        map_delete(room_cache, k);
    }

    // 清空 exit_map 中屬於該 mudlib 的出口
    keys_to_del = ({});
    foreach (string k in keys(exit_map)) {
        if (exit_map[k] && exit_map[k]["mudlib"] == mudlib_id)
            keys_to_del += ({ k });
    }
    foreach (string k in keys_to_del) {
        map_delete(exit_map, k);
    }

    // 移除已 clone 的遠端 room 物件
    string cache_dir = FS_CACHE_DIR + "/" + mudlib_id;
    remove_cached_rooms(mudlib_id);

    return HIW("[Fantasy Space] ") + "已離開 " + mudlib_id + "，所有緩存已清空。\n";
}

// ── fsflush：重新拉取緩存 ─────────────────────────────
string do_flush(object me, string mudlib_id) {
    if (!mudlib_id || mudlib_id == "")
        return "用法：fsflush <mudlib_id>\n";

    if (!joined_muds[mudlib_id])
        return "你尚未加入 " + mudlib_id + "，請先執行 fsjoin。\n";

    // 清空 room cache（保留 joined 登記）
    mixed keys_to_del = ({});
    foreach (string k in keys(room_cache)) {
        if (strsrch(k, mudlib_id + ":") == 0)
            keys_to_del += ({ k });
    }
    foreach (string k in keys_to_del) {
        map_delete(room_cache, k);
    }

    remove_cached_rooms(mudlib_id);

    // 重新查詢 hub
    joined_muds[mudlib_id]["status"] = "pending";
    p2p_send_fs_query(mudlib_id, "info", "");

    return HIW("[Fantasy Space] ") + "已清空 " + mudlib_id + " 的緩存，重新拉取中...\n";
}

// ── 移除緩存 room 物件 ────────────────────────────────
void remove_cached_rooms(string mudlib_id) {
    string prefix = "/fs_remote/" + mudlib_id;
    // 找到所有已 load 的遠端 room 並摧毀
    object ob;
    mixed loaded = all_objects();
    if (!loaded) return;
    foreach (ob in loaded) {
        if (!ob) continue;
        string oname = object_name(ob);
        if (oname && strsrch(oname, prefix) == 0) {
            destruct(ob);
        }
    }
}

// ── 取得或建立遠端 room（懶加載） ─────────────────────
// 玩家走到帶有遠端出口的房間時，由 room.c 的 do_go 呼叫
object get_remote_room(string mudlib_id, string remote_room_path) {
    string cache_key = mudlib_id + ":" + remote_room_path;

    // 1. 檢查是否已有緩存的 LPC 原始碼
    if (room_cache[cache_key]) {
        return ensure_room_loaded(mudlib_id, remote_room_path, room_cache[cache_key]);
    }

    // 2. 尚無緩存，向遠端請求
    p2p_send_fs_query(mudlib_id, "room", remote_room_path);

    // 3. 回傳一個「載入中」的臨時房間
    return get_loading_placeholder(mudlib_id, remote_room_path);
}

// ── fslist：查詢全域節點 ──────────────────────────────
void list_muds() {
    p2p_send_fs_query("*", "list", "");
}

// ── 接收遠端回應（由 interstellar_d 呼叫） ───────────
void receive_fs_response(string mudlib_id, string resp_type, string payload) {
    if (resp_type == "list") {
        // payload: name1|id1,name2|id2...
        write(HIW("\n【Fantasy Space 星際節點清單】\n"));
        string *muds = explode(payload, ",");
        foreach (string mud in muds) {
            string *parts = explode(mud, "|");
            if (sizeof(parts) >= 2) {
                write(sprintf("  %-20s : %s\n", parts[0], parts[1]));
            }
        }
        write("\n");
        return;
    }
    
    if (resp_type == "info") {
    } else if (resp_type == "room") {
        // payload: room path + "|" + LPC source
        int sep = strsrch(payload, "|");
        if (sep < 0) return;
        string room_path = substr(payload, 0, sep);
        string lpc_src   = substr(payload, sep + 1, strlen(payload) - sep - 1);
        if (!lpc_src || lpc_src == "") return;

        string cache_key = mudlib_id + ":" + room_path;
        room_cache[cache_key] = lpc_src;

        // 寫入緩存檔案供 load_object 使用
        string dir  = FS_CACHE_DIR + "/" + mudlib_id;
        string file = dir + room_path;
        // 確保目錄存在（MudScript 的 write_file 會自動建立）
        write_file(file, lpc_src);

        // 通知等在傳送門的玩家房間已就緒
        notify_waiting_players(mudlib_id, room_path);
    }
}

// ── 建立或回傳已緩存的 room 物件 ─────────────────────
object ensure_room_loaded(string mudlib_id, string room_path, string lpc_src) {
    string virt_path = FS_CACHE_DIR + "/" + mudlib_id + room_path;
    object ob = find_object(virt_path);
    if (ob) return ob;

    // 寫入並載入
    write_file(virt_path, lpc_src);
    ob = load_object(virt_path);
    return ob;
}

// ── 臨時「載入中」房間 ────────────────────────────────
object get_loading_placeholder(string mudlib_id, string room_path) {
    string virt_path = "/std/fs_loading_room.c";
    object ob = clone_object(virt_path);
    if (ob) {
        ob->set_target_mudlib(mudlib_id);
        ob->set_target_room(room_path);
    }
    return ob;
}

// ── 通知等待的玩家 ────────────────────────────────────
void notify_waiting_players(string mudlib_id, string room_path) {
    object *us = users();
    foreach (object u in us) {
        if (!u || !userp(u)) continue;
        object env = environment(u);
        if (!env) continue;
        // 如果玩家在 loading placeholder 且目標相符，則傳送過去
        if (env->query_is_loading_room() &&
            env->query_target_mudlib() == mudlib_id &&
            env->query_target_room()   == room_path) {
            string virt_path = FS_CACHE_DIR + "/" + mudlib_id + room_path;
            object dest = load_object(virt_path);
            if (dest) {
                u->move(dest, "portal");
                dest->look_room(u);
            }
        }
    }
}

// ── 向 hub 傳送 fs query ──────────────────────────────
void p2p_send_fs_query(string mudlib_id, string query_type, string query_payload) {
    // 組合 fs 查詢訊息格式：fs_query|from_mudlib|to_mudlib|type|payload
    string msg = "fs_query|" + FS_MUDLIB_ID + "|" + mudlib_id + "|" + query_type + "|" + query_payload;
    p2p_broadcast(msg);
}

// ── 處理收到的 fs_query（由 interstellar_d 轉來） ─────
void handle_fs_query(string from_mudlib, string query_type, string query_payload) {
    if (query_type == "info") {
        // 回傳本 mudlib 的基本資訊
        string resp = FS_MUDLIB_ID + "|info|" + FS_MUDLIB_NAME + "|" + START_ROOM;
        string msg = "fs_resp|" + FS_MUDLIB_ID + "|" + from_mudlib + "|info|" + resp;
        p2p_broadcast(msg);

    } else if (query_type == "list") {
        // 回傳所有節點資訊
        string resp = "";
        mixed keys = keys(joined_muds);
        // 加入自己
        resp = FS_MUDLIB_NAME + "|" + FS_MUDLIB_ID;
        foreach (string mid in keys) {
            resp += "," + joined_muds[mid]["name"] + "|" + mid;
        }
        string msg = "fs_resp|" + FS_MUDLIB_ID + "|" + from_mudlib + "|list|" + resp;
        p2p_broadcast(msg);
    } else if (query_type == "room") {
        // query_payload 應該是類似 "/area/newbie/room_0_0.c"
        // 為了確保安全與正確，我們加上 "/mudlib" 前綴
        string real_path = "/mudlib" + query_payload;
        string src = read_file(real_path);
        if (!src) {
             // 嘗試直接讀取
             src = read_file(query_payload);
        }
        if (!src) src = "";
        // 把回應傳回去
        string msg = "fs_resp|" + FS_MUDLIB_ID + "|" + from_mudlib + "|room|" + query_payload + "|" + src;
        p2p_broadcast(msg);
    }
}
