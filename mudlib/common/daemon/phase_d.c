// daemon/phase_d.c - 通用時辰節律與 NPC 排程守護進程 (World-Agnostic)
// 移除特定小說事件硬編碼，支援 JSON 注入的 NPC 排程

#include "/include/config.h"

inherit "/std/object.c";

mapping npc_schedules;   // npc_key -> schedule def
string  current_period;  // "dawn", "morning", "noon", "dusk", "night", "midnight"
int     last_update;

string query_save_file() { return "/data/phase_d"; }

// 時辰定義（以遊戲內時間）
mixed period_names;

void create() {
    ::create();
    npc_schedules = ([]);
    current_period = "morning";
    last_update    = time();

    period_names = ({ "dawn", "morning", "noon", "dusk", "night", "midnight" });

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    if (!npc_schedules) npc_schedules = ([]);

    // 從 JSON 載入 NPC 排程
    load_schedules();
}

void load_schedules() {
    if (file_size("/schema/phase_schedule.json") <= 0) return;
    string raw = read_file("/schema/phase_schedule.json");
    if (!raw || raw == "") return;
    mixed data = json_decode(raw);
    if (!mapp(data)) return;

    if (mapp(data["schedules"])) {
        npc_schedules = data["schedules"];
    }
}

// ── 時辰計算 ─────────────────────────────────────────────
string calc_period(int game_hour) {
    if (game_hour >= 5  && game_hour < 7)  return "dawn";
    if (game_hour >= 7  && game_hour < 12) return "morning";
    if (game_hour >= 12 && game_hour < 17) return "noon";
    if (game_hour >= 17 && game_hour < 19) return "dusk";
    if (game_hour >= 19 && game_hour < 23) return "night";
    return "midnight";
}

string query_period()           { return current_period; }
void   set_period(string p)     { current_period = p; }

// ── NPC 排程 ─────────────────────────────────────────────
void register_npc_schedule(string npc_key, mapping schedule) {
    if (!npc_schedules) npc_schedules = ([]);
    npc_schedules[npc_key] = schedule;
}

mapping query_npc_schedule(string npc_key) {
    return npc_schedules ? npc_schedules[npc_key] : 0;
}

// 取得 NPC 在指定時辰應在的位置
string query_npc_location(string npc_key, string period) {
    mapping sched = query_npc_schedule(npc_key);
    if (!sched) return 0;
    if (!period) period = current_period;
    return sched[period] ? sched[period] : sched["default"];
}

// ── 心跳：同步所有排程 NPC 位置 ─────────────────────────
void sync_npc_locations() {
    if (!npc_schedules) return;
    string *npc_keys = keys(npc_schedules);
    for (int i = 0; i < sizeof(npc_keys); i++) {
        string npc_key = npc_keys[i];
        string target_room = query_npc_location(npc_key, current_period);
        if (!target_room) continue;

        object npc = find_object(npc_key);
        if (!npc) continue;
        object cur_room = environment(npc);
        if (cur_room && base_name(cur_room) == target_room) continue;

        object room = load_object(target_room);
        if (room) move_object(npc, room);
    }
}

// ── 時辰推進（供 heartbeat 或 call_out 呼叫） ───────────
void tick(int game_hour) {
    string new_period = calc_period(game_hour);
    if (new_period != current_period) {
        current_period = new_period;
        sync_npc_locations();
        // 廣播時辰變更事件
        object wsd = find_object("/daemon/world_state_d.c");
        if (wsd) wsd->fire_event("period_changed", ([ "period": current_period ]));
    }
    last_update = time();
    save_object(query_save_file());
}
