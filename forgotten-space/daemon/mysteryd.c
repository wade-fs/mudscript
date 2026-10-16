// daemon/mysteryd.c
// 《遺忘的世界》史前奇遇、個人級事件與歷史拼圖守護進程 (MYSTERY_D)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

// 統一史前發現型遺物與奇遇註冊表 (Prehistoric Relic Registry)
mapping RELIC_REGISTRY;

void create() {
    ::create();
    RELIC_REGISTRY = ([
        "stream_stele" : ([
            "name" : "史前逆星斷碑",
            "required_fate" : 2,
            "exp_gain" : 30,
            "fate_gain" : 1,
            "legacy_key" : "study_ruin_stone",
            "title" : "洞悉太古逆星宿圖"
        ]),
        "forge_ancient_black_iron" : ([
            "name" : "太古不融黑鐵構件",
            "required_fate" : 0,
            "exp_gain" : 40,
            "fate_gain" : 1,
            "clone_item" : "/clone/relic/ancient_black_iron.c",
            "legacy_key" : "forged_ancient_iron",
            "title" : "震裂礦核觸及上古工聖黑鐵"
        ]),
        "commune_forest_totem" : ([
            "name" : "太古戰神獵獸圖騰玄柱",
            "required_fate" : 0,
            "exp_gain" : 40,
            "fate_gain" : 1,
            "legacy_key" : "communed_forest_totem",
            "title" : "喋血共鳴喚醒戰神圖騰"
        ]),
        "search_altar_pine" : ([
            "name" : "道化晶石殘片",
            "required_fate" : 0,
            "exp_gain" : 50,
            "fate_gain" : 1,
            "clone_item" : "/clone/item/dao_crystal.c",
            "legacy_key" : "searched_altar_pine",
            "title" : "發掘太古道化玉晶遺骸"
        ]),
        "stargaze_altar" : ([
            "name" : "蒼穹天羅偽籠真相",
            "required_fate" : 1,
            "exp_gain" : 100,
            "fate_gain" : 1,
            "legacy_key" : "stargazed",
            "title" : "神識穿透星空堪破活體牢籠"
        ]),
        "search_shed_wood" : ([
            "name" : "萬物行商・天門引",
            "required_fate" : 0,
            "exp_gain" : 50,
            "fate_gain" : 1,
            "clone_item" : "/clone/relic/tianmen_token.c",
            "legacy_key" : "searched_shed_wood",
            "title" : "掘出太古九天商盟通關殘令"
        ]),
        "eavesdrop_shed" : ([
            "name" : "黑石鋪市井暗流情報",
            "required_fate" : 0,
            "exp_gain" : 30,
            "fate_gain" : 0,
            "legacy_key" : "eavesdropped_shed",
            "title" : "聽風辨器洞悉官道真情"
        ])
    ]);
}

// ── 統一查詢：遺物是否已被該玩家發現過 ─────────────────────────
int is_relic_discovered(object who, string relic_key) {
    if (!who || !relic_key || relic_key == "") return 0;

    // 1. 標準個人事件旗標
    if (who->query("personal_event/" + relic_key)) return 1;

    // 2. 註冊表別名比對
    mapping cfg = RELIC_REGISTRY[relic_key];
    if (cfg && cfg["legacy_key"]) {
        if (who->query(cfg["legacy_key"])) return 1;
        if (who->query("personal_event/" + cfg["legacy_key"])) return 1;
    }

    // 3. 通用前綴相容
    if (relic_key == "stream_stele" && who->query("personal_event/study_ruin_stone")) return 1;
    if (relic_key == "study_ruin_stone" && who->query("personal_event/stream_stele")) return 1;

    return 0;
}

// 相容舊介面
int has_completed_personal_event(object who, string event_id) {
    return is_relic_discovered(who, event_id);
}

// ── 統一判定：玩家是否具備勘破認知盲區與發現門檻 ─────────────
int can_discover_relic(object who, string relic_key) {
    if (!who) return 0;
    if (!relic_key || relic_key == "") return 1;

    mapping cfg = RELIC_REGISTRY[relic_key];
    int req_fate = cfg ? cfg["required_fate"] : 1;

    // 溪灘斷碑：若玩家個人曾以磨刀 (sharpen) 或清洗 (wash) 去除石面青苔石垢，天命門檻降低 1 點
    if (relic_key == "stream_stele" && who->query_temp("cleared_stele_moss")) {
        req_fate -= 1;
        if (req_fate < 1) req_fate = 1;
    }

    int player_fate = who->query(STAT_FATE);

    // 判定天命是否達到該遺物之門檻
    if (player_fate >= req_fate) return 1;

    return 0;
}

// 相容舊介面
int check_amnesia_breakthrough(object who, int required_fate) {
    return can_discover_relic(who, "stream_stele");
}

// ── 統一觸發：發放遺物、給予經驗、覺醒天命、標記旗標 ─────────
mixed trigger_relic_discovery(object who, string relic_key, object dest) {
    if (!who || !relic_key) return 0;
    if (is_relic_discovered(who, relic_key)) return 0;

    mapping cfg = RELIC_REGISTRY[relic_key];
    if (!cfg) return 0;

    // 1. 設置核心事件旗標與舊有相容旗標
    who->set("personal_event/" + relic_key, 1);
    if (cfg["legacy_key"]) {
        who->set(cfg["legacy_key"], 1);
        who->set("personal_event/" + cfg["legacy_key"], 1);
    }
    if (relic_key == "stream_stele") who->set("personal_event/study_ruin_stone", 1);
    if (relic_key == "study_ruin_stone") who->set("personal_event/stream_stele", 1);

    // 2. 發放經驗與潛能
    int exp_gain = cfg["exp_gain"];
    if (exp_gain > 0) {
        who->gain_exp(exp_gain);
    }

    // 3. 覺醒天命 (Fate Awakening)
    int fate_gain = cfg["fate_gain"];
    if (fate_gain > 0) {
        int cur_fate = who->query(STAT_FATE);
        who->set(STAT_FATE, cur_fate + fate_gain);
        tell_object(who, HIY "【宿命共鳴】你觸及了一角被大清洗抹除的史前真相，體內沉睡的天命微幅覺醒（天命 +" +
                         sprintf("%d", fate_gain) + "，當前天命：" + sprintf("%d", cur_fate + fate_gain) + "）！\n" NOR);
    }

    // 4. 複製發放遺物實體
    object relic_ob = 0;
    if (cfg["clone_item"]) {
        relic_ob = clone_object(cfg["clone_item"]);
        if (relic_ob) {
            if (!dest) dest = who;
            if (!relic_ob->move(dest)) {
                if (environment(who)) relic_ob->move(environment(who));
            }
        }
    }

    return relic_ob ? relic_ob : 1;
}

// 相容舊介面
int complete_personal_event(object who, string event_id, int exp_gain, int fate_gain) {
    if (!who || !event_id) return 0;
    if (is_relic_discovered(who, event_id)) return 0;

    if (RELIC_REGISTRY && RELIC_REGISTRY[event_id]) {
        return trigger_relic_discovery(who, event_id, who) ? 1 : 0;
    }

    who->set("personal_event/" + event_id, 1);
    if (exp_gain > 0) who->gain_exp(exp_gain);
    if (fate_gain > 0) {
        int cur_fate = who->query(STAT_FATE);
        who->set(STAT_FATE, cur_fate + fate_gain);
        tell_object(who, HIY "【宿命共鳴】你觸及了一角被大清洗抹除的史前真相，體內沉睡的天命微幅覺醒（天命 +" +
                         sprintf("%d", fate_gain) + "，當前天命：" + sprintf("%d", cur_fate + fate_gain) + "）！\n" NOR);
    }
    return 1;
}
