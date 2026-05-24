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

// 🚀 新增：等待傳送的玩家清單 ([ "mudlib_id": ({ player_objects }) ])
mapping pending_travel;

void create() {
    ::create();
    if (!joined_muds) joined_muds = ([]);
    if (!room_cache)  room_cache  = ([]);
    if (!pending_travel) pending_travel = ([]);
}

// ── 查詢 ──────────────────────────────────────────────
mapping query_joined_muds() { return joined_muds; }
mapping query_room_cache()  { return room_cache; }

int is_joined(string mudlib_id) {
    return (joined_muds && mapp(joined_muds[mudlib_id]) && joined_muds[mudlib_id]["status"] == "active");
}

// ── fsgoto：合併 join 與傳送功能 ──────────────────────
string init_fsgoto(object me, string mudlib_id) {
    if (!mudlib_id || mudlib_id == "")
        return "用法：fsgoto <mudlib_id>\n";

    if (mudlib_id == FS_MUDLIB_ID)
        return "你已經在本機伺服器了。\n";

    // 1. 若已經加入且 active，直接傳送
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

    // 2. 若尚未加入或 pending，則加入 pending_travel 並觸發 join
    if (!pending_travel[mudlib_id]) pending_travel[mudlib_id] = ({});
    pending_travel[mudlib_id] += ({ me });

    if (!joined_muds[mudlib_id]) {
        do_join(me, mudlib_id);
    }

    return HIW("[Fantasy Space] ") + "正在查詢 " + mudlib_id + " 的資訊並準備傳送...\n";
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
        if (!ob || ob == this_object()) continue; // 🚩 安全檢查
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
void list_muds(object me) {
    p2p_send_fs_query("*", "list", "");
    // 設定一個標記，告知之後接收到清單時要由哪位玩家觸發顯示
    // 這裡為了簡化，我們在接收到回應時廣播給所有人，但可以優化為只給發送者
}

// ── 改寫遠端 room 的 add_exit 路徑 ──────────────────────
// 把 add_exit("dir", "/area/...") 的路徑前面加上緩存目錄
// 這樣玩家在緩存 room 內移動時，load_object 會直接載入緩存版
// 若目標路徑以 /area/ 開頭才改寫（避免動到相對路徑或特殊出口）
string rewrite_exits(string src, string mudlib_id) {
    string prefix = FS_CACHE_DIR + "/" + mudlib_id;
    string result = "";
    string *lines = explode(src, "\n");
    int i;
    for (i = 0; i < sizeof(lines); i++) {
        string line = lines[i];
        // 找 add_exit(  行
        if (strsrch(line, "add_exit") != -1) {
            // 找第二個字串引數（路徑）
            // 格式：add_exit("dir", "/area/...");
            int q1 = strsrch(line, "\"");
            if (q1 >= 0) {
                int q2 = strsrch(line, "\"", q1 + 1);
                if (q2 > q1) {
                    int q3 = strsrch(line, "\"", q2 + 1);
                    if (q3 > q2) {
                        int q4 = strsrch(line, "\"", q3 + 1);
                        if (q4 > q3) {
                            string exit_path = substr(line, q3 + 1, q4 - q3 - 1);
                            // 只改寫以 /area/ 或 / 開頭的絕對路徑
                            if (strlen(exit_path) > 1 && exit_path[0] == '/') {
                                string new_path = prefix + exit_path;
                                // 把原始路徑換成緩存路徑
                                line = substr(line, 0, q3) + "\"" + new_path + "\"" + substr(line, q4 + 1, strlen(line) - q4 - 1);
                            }
                        }
                    }
                }
            }
        }
        if (i < sizeof(lines) - 1)
            result += line + "\n";
        else
            result += line;
    }
    return result;
}

// ── 接收遠端回應（由 interstellar_d 呼叫） ───────────
void receive_fs_response(string mudlib_id, string resp_type, string payload) {
    if (resp_type == "list") {
        // payload: name1|id1,name2|id2...
        // 為了避免重複顯示，我們這裡僅將收到的清單整理後顯示給所有玩家
        string *muds = explode(payload, ",");
        string output = HIW("\n【Fantasy Space 星際節點清單】\n");
        foreach (string mud in muds) {
            string *parts = explode(mud, "|");
            if (sizeof(parts) >= 2) {
                output += sprintf("  %-20s : %s\n", parts[0], parts[1]);
            }
        }
        output += "\n";
        
        object *us = users();
        foreach (object u in us) {
            if (u && userp(u)) tell_object(u, output);
        }
        return;
    }
    
    if (resp_type == "info") {
        // payload: mudlib_id|info|name|entrance_room
        string *parts = explode(payload, "|");
        if (sizeof(parts) >= 4) {
            if (joined_muds[mudlib_id]) {
                joined_muds[mudlib_id]["status"] = "active";
                joined_muds[mudlib_id]["name"] = parts[2];
                joined_muds[mudlib_id]["entrance"] = parts[3];

                // 🚀 關鍵：處理等待傳送的玩家
                if (pending_travel[mudlib_id]) {
                    foreach (object p in pending_travel[mudlib_id]) {
                        if (p && environment(p)) {
                            init_fsgoto(p, mudlib_id);
                        }
                    }
                    map_delete(pending_travel, mudlib_id);
                }
            }
        }
    } else if (resp_type == "room") {
        // payload: room path + "|" + LPC source
        int sep = strsrch(payload, "|");
        if (sep < 0) return;
        string room_path = substr(payload, 0, sep);
        string lpc_src   = substr(payload, sep + 1, strlen(payload) - sep - 1);
        if (!lpc_src || lpc_src == "") return;

        string cache_key = mudlib_id + ":" + room_path;

        // ── 改寫 add_exit 路徑：出口指向緩存版本而非本機 ──
        string rewritten_src = rewrite_exits(lpc_src, mudlib_id);

        room_cache[cache_key] = rewritten_src;

        // 寫入緩存檔案供 load_object 使用
        string file = FS_CACHE_DIR + "/" + mudlib_id + room_path;
        write_file(file, rewritten_src);

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
