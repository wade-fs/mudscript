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

// ── 輔助：解析絕對路徑 (考慮相對路徑轉換) ────────────────
string resolve_absolute_path(string base_path, string target_path) {
    if (strsrch(target_path, "/") == 0) return target_path;
    // 如果是相對路徑，則根據 base_path 進行轉換
    return resolve_path(target_path, base_path);
}

// ── 改寫遠端物件的所有依賴路徑 (Deep Sandboxing) ─────────
// 掃描 LPC 原始碼，將所有指向 /area/, /npc/, /item/ 等目錄的絕對路徑
// 改寫為指向本機緩存目錄 /data/fs_cache/<mudlib_id>/...
// 同時保留對 /std/, /include/ 等全域系統目錄的引用
string rewrite_assets(string src, string mudlib_id, string current_file_path) {
    string prefix = FS_CACHE_DIR + "/" + mudlib_id;
    string result = "";
    string *lines = explode(src, "\n");
    int i;

    for (i = 0; i < sizeof(lines); i++) {
        string line = lines[i];

        // 我們要搜尋的關鍵字清單
        string *keywords = ({ "add_exit", "inherit", "load_object", "clone_object", "move_object", "read_file", "write_file", "include" });

        int found = 0;
        foreach (string kw in keywords) {
            if (strsrch(line, kw) != -1) {
                found = 1;
                break;
            }
        }

        if (found) {
            // 由於 LPC 解析複雜，這裡使用簡化的引號搜尋策略
            // 邏輯：找到所有 "..." 字串，如果內容以 /area/, /npc/, /item/ 開頭，則改寫
            int q1 = -1;
            while ((q1 = strsrch(line, "\"", q1 + 1)) != -1) {
                int q2 = strsrch(line, "\"", q1 + 1);
                if (q2 == -1) break;

                string path = substr(line, q1 + 1, q2 - q1 - 1);

                // 只處理絕對路徑 (以 / 開頭)
                if (strlen(path) > 1 && path[0] == '/') {
                    // 白名單：不改寫系統路徑
                    if (strsrch(path, "/std/") == 0 || 
                        strsrch(path, "/include/") == 0 || 
                        strsrch(path, "/secure/") == 0 ||
                        strsrch(path, "/fs_remote/") == 0 || // 避免重複改寫
                        strsrch(path, FS_CACHE_DIR) == 0) {
                        q1 = q2;
                        continue;
                    }

                    // 改寫目標目錄
                    string new_path = prefix + path;

                    // 檢查目標是否已在緩存中，若不在，則排程下載 (非同步)
                    // 這裡先簡單改寫，下載由 ensure_room_loaded 或其他處觸發

                    line = substr(line, 0, q1 + 1) + new_path + substr(line, q2, strlen(line) - q2);
                    // 更新 q2 因為行長度變了
                    q2 = q1 + strlen(new_path) + 1;
                }
                q1 = q2;
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
        // ... (原有 list 邏輯不變)
        return;
    }

    if (resp_type == "info") {
        // ... (原有 info 邏輯不變)
        // ... (原有 pending_travel 邏輯不變)
    } else if (resp_type == "room") {
        // payload: room path + "|" + LPC source
        int sep = strsrch(payload, "|");
        if (sep < 0) return;
        string room_path = substr(payload, 0, sep);
        string lpc_src   = substr(payload, sep + 1, strlen(payload) - sep - 1);
        if (!lpc_src || lpc_src == "") return;

        string cache_key = mudlib_id + ":" + room_path;

        // ── 🚀 核心升級：深度資產改寫 ──
        string rewritten_src = rewrite_assets(lpc_src, mudlib_id, room_path);

        room_cache[cache_key] = rewritten_src;

        // 寫入緩存檔案供 load_object 使用
        string file = FS_CACHE_DIR + "/" + mudlib_id + room_path;
        write_file(file, rewritten_src);

        // 通知等在傳送門的玩家房間已就緒
        notify_waiting_players(mudlib_id, room_path);

        // 🚀 掃描並自動請求缺漏的依賴 (如 inherit 或 add_exit 指向的文件)
        scan_and_fetch_dependencies(mudlib_id, rewritten_src);
    }
}

// ── 掃描原始碼並自動請求依賴 ──────────────────────────
void scan_and_fetch_dependencies(string mudlib_id, string src) {
    string prefix = FS_CACHE_DIR + "/" + mudlib_id;
    int q1 = -1;
    while ((q1 = strsrch(src, prefix, q1 + 1)) != -1) {
        int q2 = strsrch(src, "\"", q1);
        if (q2 == -1) break;

        string full_path = substr(src, q1, q2 - q1);
        // 提取原始路徑 (去掉緩存前綴)
        string orig_path = substr(full_path, strlen(prefix), strlen(full_path));

        // 如果緩存檔案不存在，則請求它
        if (file_size(full_path) == -1) {
            p2p_send_fs_query(mudlib_id, "room", orig_path);
        }
        q1 = q2;
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
