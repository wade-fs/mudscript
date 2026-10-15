// daemon/world_state_d.c
// 《遺忘的世界》世界狀態協調守護進程 (03 World State)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

mapping regional_events; // 區域可變動態狀態表
int last_tick_time;

void create() {
    ::create();
    regional_events = ([
        "blackstone_mine": ([
            "status": "normal",       // normal / collapsed / repairing
            "collapse_progress": 0,
            "repair_progress": 100,
            "desc": "北崖礦坑運作平穩，未見地煞異常。"
        ]),
        "trade_route": ([
            "status": "open",         // open / blocked / guarded
            "desc": "通往 Tier 1 府城之大荒官道暢通無阻。"
        ]),
        "valley_stream": ([
            "status": "calm",         // calm / surging / tainted
            "desc": "水谷溪流清冽，水氣迷濛。"
        ])
    ]);
    last_tick_time = time();
}

// 查詢某區域之當前動態狀態
mapping query_region_state(string region_id) {
    if (regional_events[region_id]) {
        return regional_events[region_id];
    }
    return ([]);
}

// 更新某區域之動態狀態
void set_region_state(string region_id, string key, mixed val) {
    if (!regional_events[region_id]) {
        regional_events[region_id] = ([]);
    }
    regional_events[region_id][key] = val;
}
