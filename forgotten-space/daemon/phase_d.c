// daemon/phase_d.c
// 《遺忘的世界》NPC 動態生態、時空作息與任務相位守護進程 (PHASE_D)
// 實作 NPC 十二時辰作息表 (Schedule Matrix)、事件相位切換 (Event Phasing) 與回歸記憶

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

mapping npc_registry;       // NPC 註冊表: npc_key -> schedule & phase def
mapping active_events;      // 全域事件相位: event_id -> phase_level
string current_period;      // 當前時辰劃分: dawn, morning, noon_afternoon, dusk, night, midnight
int last_update;

string query_save_file() { return "/data/phase_d"; }

void init_schedules();

void create() {
    ::create();
    current_period = "morning";
    active_events = ([
        "beast_surge": 0,
        "mine_collapse": 0,
        "canal_notarization": 0,
        "tribunal": 0
    ]);
    last_update = time();

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    init_schedules();
}

// ── 1. 時辰轉為作息時段 ──────────────────────────────────────
string query_period_by_shichen(string base_shichen) {
    if (!base_shichen) return "morning";
    if (base_shichen == "卯時") return "dawn";
    if (base_shichen == "辰時" || base_shichen == "巳時") return "morning";
    if (base_shichen == "午時" || base_shichen == "未時") return "noon_afternoon";
    if (base_shichen == "申時" || base_shichen == "酉時") return "dusk";
    if (base_shichen == "戌時" || base_shichen == "亥時") return "night";
    if (base_shichen == "子時" || base_shichen == "丑時" || base_shichen == "寅時") return "midnight";
    return "morning";
}

string query_current_period() {
    return current_period;
}

// ── 2. NPC 作息矩陣初始化 ─────────────────────────────────────
void init_schedules() {
    npc_registry = ([
        "zhang_butcher": ([
            "name": "張屠戶",
            "file": "/clone/npc/zhang_butcher.c",
            "schedules": ([
                "dawn":           "/d/village/stream.c",
                "morning":        "/d/village/square.c",
                "noon_afternoon": "/d/village/square.c",
                "dusk":           "/d/village/square.c",
                "night":          "/d/village/square.c",
                "midnight":       "/d/village/square.c"
            ]),
            "action_descs": ([
                "dawn":           "張屠戶正就著冰涼溪水霍霍磨著砍肉尖刀，鐵屑夾著白沫沖入碎石灘。",
                "morning":        "張屠戶一刀剁在案板厚木上，高聲叫賣著今日剛宰殺的新鮮山豬肉。",
                "noon_afternoon": "張屠戶擦了一把額頭熱汗，將剔骨尖刀插在案頭大口喝著涼水。",
                "dusk":           "張屠戶在青石街市收拾案板，扯著嗓子抱怨山道難行。",
                "night":          "張屠戶收拾著案板上的碎肉渣滓，將防獸砍刀收進油布套中。"
            ]),
            "event_phases": ([
                "beast_surge": ([
                    "1": "/d/village/forest.c"
                ])
            ])
        ]),
        "lao_miner": ([
            "name": "魯大山",
            "file": "/clone/npc/lao_miner.c",
            "schedules": ([
                "dawn":           "/d/village/mine.c",
                "morning":        "/d/village/mine.c",
                "noon_afternoon": "/d/village/mine.c",
                "dusk":           "/d/village/square.c",
                "night":          "/d/village/square.c",
                "midnight":       "/d/village/square.c"
            ]),
            "action_descs": ([
                "dawn":           "魯大山檢查著礦道口的老舊絞盤，滿面塵灰。",
                "morning":        "魯大山揮著鐵鎬敲擊粗黑鐵礦，指導新來的礦工如何分辨裂脈。",
                "dusk":           "魯大山在客棧外長凳上揉著發酸的肩膀，咳著黑灰痰濁。",
                "night":          "魯大山望著北崖黑沉沉的山影，眉頭深鎖。"
            ]),
            "event_phases": ([
                "mine_collapse": ([
                    "1": "/d/village/mine_depths.c"
                ])
            ])
        ]),
        "mo_beggar": ([
            "name": "莫三",
            "file": "/clone/npc/mo_beggar.c",
            "schedules": ([
                "dawn":           "/d/village/shed.c",
                "morning":        "/d/village/square.c",
                "noon_afternoon": "/d/village/square.c",
                "dusk":           "/d/village/square.c",
                "night":          "/d/village/shed.c",
                "midnight":       "/d/village/shed.c"
            ]),
            "action_descs": ([
                "morning":        "莫三縮在牆角抱著破陶碗曬太陽，渾濁的眼睛掃視著過往客商。",
                "night":          "莫三縮在後巷破柴房爛木堆邊，藉著殘月微光摸索著一枚生鏽黑鐵牌。"
            ])
        ]),
        "kumu_daoist": ([
            "name": "枯木老道",
            "file": "/clone/npc/kumu_daoist.c",
            "schedules": ([
                "dawn":           "/d/village/altar.c",
                "morning":        "/d/village/daoist_temple.c",
                "noon_afternoon": "/d/village/daoist_temple.c",
                "dusk":           "/d/village/daoist_temple.c",
                "night":          "/d/village/altar.c",
                "midnight":       "/d/village/altar.c"
            ]),
            "action_descs": ([
                "dawn":           "枯木老道迎著晨曦在白石殘壇盤膝閉目，吞吐天地微茫紫氣。",
                "morning":        "枯木老道在破敗道觀手撥古算籌，口中喃喃誦讀殘缺經文。",
                "midnight":       "枯木老道仰望周天星軌，眼底浮現出一絲難以言喻的悲戚與恐懼。"
            ])
        ]),
        "center_doctor_bai": ([
            "name": "白先生",
            "file": "/clone/npc/center_doctor_bai.c",
            "schedules": ([
                "dawn":           "/d/city/center/clinic.c",
                "morning":        "/d/city/center/clinic.c",
                "noon_afternoon": "/d/city/center/clinic.c",
                "dusk":           "/d/city/north/gong_alchemy.c",
                "night":          "/d/city/center/clinic.c",
                "midnight":       "/d/city/center/clinic.c"
            ]),
            "action_descs": ([
                "morning":        "白先生手持銀針為病榻上的傷患切脈，神情專注嚴肅。",
                "dusk":           "白先生正在百草堂藥爐前與孫先生研討濁水毒囊樣本，神色凝重。"
            ])
        ]),
        "center_teacher_lu": ([
            "name": "陸夫子",
            "file": "/clone/npc/center_teacher_lu.c",
            "schedules": ([
                "dawn":           "/d/city/center/academy.c",
                "morning":        "/d/city/center/academy.c",
                "noon_afternoon": "/d/city/center/yamen_archive.c",
                "dusk":           "/d/city/center/academy.c",
                "night":          "/d/city/center/academy.c",
                "midnight":       "/d/city/center/academy.c"
            ]),
            "action_descs": ([
                "morning":        "陸夫子手持戒尺來回踱步，正領著幾名蒙童朗誦大乾開國律例。",
                "noon_afternoon": "陸夫子戴著花鏡在案牘庫翻查三十年前商盟舊檔，不時輕輕嘆息。"
            ])
        ]),
        "center_wenchengjing": ([
            "name": "文承敬",
            "file": "/clone/npc/center_wenchengjing.c",
            "schedules": ([
                "dawn":           "/d/city/center/yamen_archive.c",
                "morning":        "/d/city/center/yamen_archive.c",
                "noon_afternoon": "/d/city/center/yamen_archive.c",
                "dusk":           "/d/city/center/yamen_archive.c",
                "night":          "/d/city/center/yamen.c",
                "midnight":       "/d/city/center/yamen.c"
            ]),
            "action_descs": ([
                "morning":        "文承敬蘸著濃墨在稅冊底單上核驗火印，頭也不抬地翻閱卷宗。"
            ]),
            "event_phases": ([
                "canal_notarization": ([
                    "1": "/d/city/under/canal_hub.c"
                ])
            ])
        ]),
        "gong_mochui": ([
            "name": "莫錘",
            "file": "/clone/npc/gong_mochui.c",
            "schedules": ([
                "dawn":           "/d/city/north/gong_forge.c",
                "morning":        "/d/city/north/gong_forge.c",
                "noon_afternoon": "/d/city/north/gong_forge.c",
                "dusk":           "/d/city/south/yard_material.c",
                "night":          "/d/city/north/gong_forge.c",
                "midnight":       "/d/city/north/gong_forge.c"
            ]),
            "action_descs": ([
                "morning":        "莫錘正赤著精壯上身揮舞重錘，叮噹鍛打一塊來自重石縣的粗鐵胚。",
                "dusk":           "莫錘蹲在大石堆棧仔細檢視新運抵的耐火泥批號，神情警惕。"
            ])
        ]),
        "wu_bashan": ([
            "name": "霸山",
            "file": "/clone/npc/wu_bashan.c",
            "schedules": ([
                "dawn":           "/d/city/east/wu_arena.c",
                "morning":        "/d/city/east/wu_arena.c",
                "noon_afternoon": "/d/city/east/wu_arena.c",
                "dusk":           "/d/city/east/wu_barracks.c",
                "night":          "/d/city/east/wu_barracks.c",
                "midnight":       "/d/city/east/wu_barracks.c"
            ]),
            "action_descs": ([
                "morning":        "霸山雙臂抱胸立於擂台正中，如洪鐘般的吼聲震得台下武徒氣血翻騰。",
                "night":          "霸山在巡防營房親自檢查披甲武卒的重弓扳指與鐵鏃。"
            ])
        ]),
        "dao_xingyuan": ([
            "name": "星淵",
            "file": "/clone/npc/dao_xingyuan.c",
            "schedules": ([
                "dawn":           "/d/city/west/dao_observatory.c",
                "morning":        "/d/city/west/dao_observatory.c",
                "noon_afternoon": "/d/city/west/dao_observatory.c",
                "dusk":           "/d/city/west/dao_roof.c",
                "night":          "/d/city/west/dao_roof.c",
                "midnight":       "/d/city/west/dao_roof.c"
            ]),
            "action_descs": ([
                "morning":        "星淵調校著渾天儀的青銅齒輪，記錄著晨間地煞微弱的經緯波動。",
                "midnight":       "星淵獨立摘星台頂端，冷風吹拂道袍，正凝視著夜幕中逆行的晦暗星軌。"
            ])
        ]),
        "square_watchman": ([
            "name": "李遊徼",
            "file": "/clone/npc/square_watchman.c",
            "schedules": ([
                "dawn":           "/d/city/gate/gate_south.c",
                "morning":        "/d/city/center/square.c",
                "noon_afternoon": "/d/city/center/square.c",
                "dusk":           "/d/city/gate/gate_south.c",
                "night":          "/d/city/center/square.c",
                "midnight":       "/d/city/gate/gate_south.c"
            ]),
            "action_descs": ([
                "morning":        "李遊徼手扶腰間鐵尺在中央廣場巡視，目光如隼般打量著外縣流民。",
                "midnight":       "李遊徼提著燈籠在南關城門下敲梆巡夜，喝斥試圖翻越柵欄的無籍野民。"
            ])
        ]),
        "square_storyteller": ([
            "name": "瞎子陳",
            "file": "/clone/npc/square_storyteller.c",
            "schedules": ([
                "dawn":           "/d/city/center/square.c",
                "morning":        "/d/city/center/square.c",
                "noon_afternoon": "/d/city/center/square.c",
                "dusk":           "/d/city/center/inn_main.c",
                "night":          "/d/city/center/inn_main.c",
                "midnight":       "/d/city/center/inn_main.c"
            ]),
            "action_descs": ([
                "morning":        "瞎子陳一拍梨花醒木，在古槐樹下引得圍觀行商嘖嘖稱奇。",
                "night":          "瞎子陳在客棧暖閣自斟自飲，向過路客商低聲訴說著六縣江湖舊聞。"
            ])
        ]),
        "market_special_buyer": ([
            "name": "程通四海",
            "file": "/clone/npc/market_special_buyer.c",
            "schedules": ([
                "dawn":           "/d/city/south/market_special.c",
                "morning":        "/d/city/south/market_special.c",
                "noon_afternoon": "/d/city/south/market_special.c",
                "dusk":           "/d/city/south/shanghui_hq.c",
                "night":          "/d/city/south/shanghui_hq.c",
                "midnight":       "/d/city/south/market_special.c"
            ]),
            "action_descs": ([
                "morning":        "程通四海正核算著新送達的盤木符紙與重石生鐵牌價，算盤打得劈啪作響。",
                "dusk":           "程通四海在商會總堂大廳向長老呈交今日六縣專材行情摺子。"
            ])
        ])
    ]);
}

// ── 3. 查詢指定 NPC 當前目標位置 ─────────────────────────────
string query_npc_target_room(string npc_key, string period) {
    if (!npc_registry || !npc_registry[npc_key]) return 0;
    mapping info = npc_registry[npc_key];

    // 優先檢查重大事件相位
    if (info["event_phases"]) {
        mapping ev_phases = info["event_phases"];
        foreach (string ev_id in keys(ev_phases)) {
            int cur_phase = active_events[ev_id];
            if (cur_phase > 0) {
                string p_str = sprintf("%d", cur_phase);
                if (ev_phases[ev_id][p_str]) {
                    return ev_phases[ev_id][p_str];
                }
            }
        }
    }

    if (!period || period == "") period = current_period;
    if (info["schedules"] && info["schedules"][period]) {
        return info["schedules"][period];
    }
    return 0;
}

// ── 4. 取得當前 NPC 環境描寫動態片段 ─────────────────────────
string query_npc_ambient_desc(string npc_key, string period) {
    if (!npc_registry || !npc_registry[npc_key]) return "";
    mapping info = npc_registry[npc_key];
    if (!period || period == "") period = current_period;
    if (info["action_descs"] && info["action_descs"][period]) {
        return info["action_descs"][period];
    }
    return "";
}

// ── 5. 事件相位設定與查詢 ────────────────────────────────────
void set_event_phase(string event_id, int phase) {
    if (!event_id || event_id == "") return;
    active_events[event_id] = phase;
    save_object(query_save_file());
    sync_all_npc_locations();
}

int query_event_phase(string event_id) {
    if (!active_events || !active_events[event_id]) return 0;
    return active_events[event_id];
}

mapping query_all_event_phases() {
    return active_events;
}

// ── 6. 尋找 NPC 實體物件 ─────────────────────────────────────
object find_npc_instance(string npc_file) {
    if (!npc_file) return 0;
    // 遍歷所有已知可能房間中的物件
    object ob = find_object(npc_file);
    if (ob && environment(ob)) return ob;

    // 若未載入，檢查使用者環境或常見房間
    return 0;
}

// ── 7. 時辰跳轉回呼（由 nature_d 定時心跳驅動）────────────────
void on_shichen_change(string base_shichen) {
    string new_period = query_period_by_shichen(base_shichen);
    if (new_period != current_period) {
        current_period = new_period;
        sync_all_npc_locations();
    }
}

// ── 8. 全域 NPC 位置同步與動態轉場 ───────────────────────────
void sync_all_npc_locations() {
    if (!npc_registry) init_schedules();

    foreach (string npc_key in keys(npc_registry)) {
        mapping def = npc_registry[npc_key];
        string target_room_path = query_npc_target_room(npc_key, current_period);
        if (!target_room_path) continue;

        string npc_file = def["file"];
        object target_room = find_object(target_room_path);
        if (!target_room) target_room = load_object(target_room_path);
        if (!target_room) continue;

        // 檢查目標房間是否已存在該 NPC
        int already_here = 0;
        object *here_inv = all_inventory(target_room);
        object found_npc = 0;
        foreach (object ob in here_inv) {
            if (base_name(ob) == npc_file) {
                already_here = 1;
                found_npc = ob;
                break;
            }
        }

        // 若已在目標房間，更新其當前環境動作提示
        if (already_here && found_npc) {
            string amb = query_npc_ambient_desc(npc_key, current_period);
            if (amb != "") found_npc->set_temp("ambient_action", amb);
            continue;
        }

        // 若不在目標房間，搜尋舊房間並進行遷徙
        // 檢查其所有可能行程房間
        mapping sched = def["schedules"];
        object old_npc = 0;
        foreach (string p in keys(sched)) {
            string r_path = sched[p];
            if (r_path == target_room_path) continue;
            object r_ob = find_object(r_path);
            if (r_ob) {
                object *r_inv = all_inventory(r_ob);
                foreach (object ob in r_inv) {
                    if (base_name(ob) == npc_file) {
                        old_npc = ob;
                        break;
                    }
                }
            }
            if (old_npc) break;
        }

        if (old_npc) {
            // 如果舊 NPC 正在戰鬥中，不強制瞬移，避免中斷玩家戰鬥
            if (old_npc->query_combat_target()) continue;

            object old_room = environment(old_npc);
            if (old_room) {
                tell_room(old_room, sprintf(WHT "【作息更替】%s 收拾手邊物事，邁步往他處走去。\n" NOR, old_npc->query_name()));
            }
            move_object(old_npc, target_room);
            tell_room(target_room, sprintf(WHT "【作息更替】%s 邁步走了過來，開始當前時段的作息。\n" NOR, old_npc->query_name()));
            string amb = query_npc_ambient_desc(npc_key, current_period);
            if (amb != "") old_npc->set_temp("ambient_action", amb);
        }
    }
}

mapping query_npc_schedule(string npc_key) {
    if (!npc_registry) init_schedules();
    return npc_registry[npc_key];
}

mapping query_all_schedules() {
    if (!npc_registry) init_schedules();
    return npc_registry;
}
