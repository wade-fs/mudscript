// daemon/phase_d.c
// 《遺忘的世界》NPC 動態生態、時空作息與任務相位守護進程 (PHASE_D)
// 實作 NPC 十二時辰作息表 (Schedule Matrix)、事件相位切換 (Event Phasing) 與回歸記憶

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

mapping npc_registry;       // NPC 註冊表: npc_key -> schedule & phase def
mapping active_events;      // 全域事件相位: event_id -> phase_level
mapping hub_scenes;         // 關鍵樞紐 NPC-to-NPC 可觀察互動劇本
mapping hub_scene_beats;    // 關鍵樞紐當前互動節拍索引
string current_period;      // 當前時辰劃分: dawn, morning, noon_afternoon, dusk, night, midnight
int last_update;

string query_save_file() { return "/data/phase_d"; }

void init_schedules();
void init_hub_scenes();
void sync_all_npc_locations();

void create() {
    ::create();
    current_period = "morning";
    active_events = ([
        "beast_surge": 0,
        "mine_collapse": 0,
        "canal_notarization": 0,
        "tribunal": 0
    ]);
    hub_scene_beats = ([]);
    last_update = time();

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    if (!mapp(hub_scene_beats)) hub_scene_beats = ([]);
    init_schedules();
    init_hub_scenes();
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
        ]),
        // ── Phase 2B 新增：庶民與地方勞動群體自主作息矩陣 ─────────────────────
        "fishmonger_liu": ([
            "name": "魚販劉三娘",
            "file": "/clone/npc/folk/fishmonger_liu.c",
            "schedules": ([
                "dawn":           "/d/city/outer/fish_market.c",
                "morning":        "/d/city/outer/fish_market.c",
                "noon_afternoon": "/d/city/outer/fish_market.c",
                "dusk":           "/d/city/outer/tenement_alley.c",
                "night":          "/d/city/outer/tenement_alley.c",
                "midnight":       "/d/city/outer/fish_market.c"
            ]),
            "action_descs": ([
                "dawn":           "劉三娘踩著木屐接過頭批漁船卸下的竹編魚簍，利落開秤喊價。",
                "morning":        "劉三娘手起刀落刮去青魚鱗片，把大尾鱖魚留給城裡酒樓採買。",
                "dusk":           "劉三娘拎著兩竹籃賣剩的雜魚小蝦走進流民矮巷，半賣半送分給貧苦鄰舍煮湯。"
            ]),
            "relationships": ([ "peers": ({ "sun_old_carter", "charity_herbalist", "roaming_porter" }) ])
        ]),
        "sun_old_carter": ([
            "name": "孫老車夫",
            "file": "/clone/npc/folk/sun_old_carter.c",
            "schedules": ([
                "dawn":           "/d/city/outer/tenement_alley.c",
                "morning":        "/d/city/outer/tenement_alley.c",
                "noon_afternoon": "/d/city/outer/tenement_alley.c",
                "dusk":           "/d/city/outer/tenement_alley.c",
                "night":          "/d/city/outer/tenement_alley.c",
                "midnight":       "/d/city/outer/tenement_alley.c"
            ]),
            "action_descs": ([
                "dawn":           "孫老車夫天微亮便替小泥爐攏火煮上一鍋稀薄米湯，準備迎著涼風出棚找活。",
                "morning":        "孫老車夫倚在土坯牆根修補磨壞的木輪手推車軸，打聽哪處官道要人扛包。",
                "dusk":           "孫老車夫拖著微腫的右腿收工回來，蹲在矮巷門口看鄰舍添柴燉粥。",
                "night":          "孫老車夫將破棉絮蓋在膝上，側耳聽著城牆那頭遠處傳來的巡夜梆子聲。"
            ]),
            "relationships": ([ "peers": ({ "fishmonger_liu", "roaming_porter", "charity_herbalist" }) ])
        ]),
        "qinghe_boatman": ([
            "name": "老船工柳伯",
            "file": "/clone/npc/folk/qinghe_boatman.c",
            "schedules": ([
                "dawn":           "/d/counties/qinghe/ferry_dock.c",
                "morning":        "/d/counties/qinghe/ferry_dock.c",
                "noon_afternoon": "/d/counties/qinghe/ferry_dock.c",
                "dusk":           "/d/counties/qinghe/river_tea_shed.c",
                "night":          "/d/counties/qinghe/river_tea_shed.c",
                "midnight":       "/d/counties/qinghe/river_tea_shed.c"
            ]),
            "action_descs": ([
                "dawn":           "柳伯赤腳蹲在渡口平底駁船尾，仔細摸檢船底滲水縫與桐油麻絮。",
                "morning":        "柳伯撐著竹篙對著水尺刻度點頭，安排藥農與草藥筐上船。",
                "dusk":           "柳伯把船纜牢牢拴死在木樁上，上岸到蘆花渡粗茶棚喝兩文一碗的熱粗茶。"
            ]),
            "relationships": ([ "peers": ({ "qinghe_herb_woman" }) ])
        ]),
        "qinghe_herb_woman": ([
            "name": "採藥婦翠嬸",
            "file": "/clone/npc/folk/qinghe_herb_woman.c",
            "schedules": ([
                "dawn":           "/d/counties/qinghe/ferry_dock.c",
                "morning":        "/d/counties/qinghe/ferry_dock.c",
                "noon_afternoon": "/d/counties/qinghe/ferry_dock.c",
                "dusk":           "/d/counties/qinghe/ferry_dock.c",
                "night":          "/d/counties/qinghe/ferry_dock.c",
                "midnight":       "/d/counties/qinghe/ferry_dock.c"
            ]),
            "action_descs": ([
                "dawn":           "翠嬸趁著晨霧在青河渡口石階邊清點剛從百草坪剪來的帶露洗靈草。",
                "morning":        "翠嬸背著藥簍在青河碼頭排隊候船，跟鄰舍抱怨渡船又漲了兩文錢。",
                "dusk":           "翠嬸收工後把賣剩的草藥仔細綁回簍裡，望著渡口木樁盤算明日船期。"
            ]),
            "relationships": ([ "peers": ({ "qinghe_boatman" }) ])
        ]),
        "roaming_porter": ([
            "name": "挑夫阿福",
            "file": "/clone/npc/folk/roaming_porter.c",
            "schedules": ([
                "dawn":           "/d/city/outer/fish_market.c",
                "morning":        "/d/city/outer/river_wharf.c",
                "noon_afternoon": "/d/city/gate/gate_south_inn.c",
                "dusk":           "/d/city/outer/tenement_alley.c",
                "night":          "/d/city/outer/tenement_alley.c",
                "midnight":       "/d/city/outer/tenement_alley.c"
            ]),
            "action_descs": ([
                "dawn":           "阿福天沒亮就扛著扁擔蹲在魚市外頭等著搶頭批卸船挑魚活計。",
                "morning":        "阿福肩搭黃布汗巾在貨運碼頭把貨物竹籌攥在手裡，跟包頭核對趟數。",
                "noon_afternoon": "阿福坐在南關小棧門檻邊花兩文錢喝大麥茶歇肩，打聽誰家還缺短工。",
                "dusk":           "阿福收工走回流民矮巷，把掙來的銅錢仔細裹進貼身衣帶裡。"
            ]),
            "relationships": ([ "peers": ({ "sun_old_carter", "fishmonger_liu" }) ])
        ]),
        "liefan_old_miner": ([
            "name": "老礦工羅七",
            "file": "/clone/npc/folk/liefan_old_miner.c",
            "schedules": ([
                "dawn":           "/d/counties/liefan/tongtuo_ridge.c",
                "morning":        "/d/counties/liefan/tongtuo_ridge.c",
                "noon_afternoon": "/d/counties/liefan/miners_tea_shed.c",
                "dusk":           "/d/counties/liefan/miners_tea_shed.c",
                "night":          "/d/counties/liefan/miners_tea_shed.c",
                "midnight":       "/d/counties/liefan/miners_tea_shed.c"
            ]),
            "action_descs": ([
                "dawn":           "羅七在銅駝嶺井口替下井年輕礦工檢查礦燈油芯與防毒濕布巾。",
                "morning":        "羅七盯著礦車絞盤與岩壁排煙口，隨時留心井下地火色澤變化。",
                "dusk":           "羅七收工後蹲在礦工粗茶棚裡邊咳邊喝兩文一碗的甘草粗茶，跟工友算月底工錢。"
            ]),
            "event_phases": ([
                "mine_collapse": ([
                    "1": "/d/counties/liefan/miners_tea_shed.c"
                ])
            ])
        ]),
        "zhou_quarryman": ([
            "name": "老石匠周六",
            "file": "/clone/npc/folk/zhou_quarryman.c",
            "schedules": ([
                "dawn":           "/d/counties/zhongshi/shinian_slope.c",
                "morning":        "/d/counties/zhongshi/shinian_slope.c",
                "noon_afternoon": "/d/counties/zhongshi/chuanshan_camp.c",
                "dusk":           "/d/counties/zhongshi/post_inn.c",
                "night":          "/d/counties/zhongshi/post_inn.c",
                "midnight":       "/d/counties/zhongshi/post_inn.c"
            ]),
            "action_descs": ([
                "morning":        "周六扶著吊索木架指揮石工起吊重玄條石，滿臉白灰石粉。",
                "dusk":           "周六拍掉褲腳石粉在縣驛長凳上揉著肩膀，盤算今日切出幾方好料。"
            ]),
            "event_phases": ([
                "mine_collapse": ([
                    "1": "/d/counties/zhongshi/post_inn.c"
                ])
            ])
        ]),
        "panmu_raftsman": ([
            "name": "老放排把頭梁四",
            "file": "/clone/npc/folk/panmu_raftsman.c",
            "schedules": ([
                "dawn":           "/d/counties/panmu/fir_logging_line.c",
                "morning":        "/d/counties/panmu/fir_logging_line.c",
                "noon_afternoon": "/d/counties/panmu/timber_wharf.c",
                "dusk":           "/d/counties/panmu/timber_wharf.c",
                "night":          "/d/counties/panmu/post_inn.c",
                "midnight":       "/d/counties/panmu/post_inn.c"
            ]),
            "action_descs": ([
                "morning":        "梁四踩著沾滿松脂的杉木垛驗看木材年輪，指揮伐木工扎緊麻繩。",
                "dusk":           "梁四在木排碼頭收回濕淋淋的長篙，趁天黑前鎖好木排栓。"
            ])
        ]),
        "peddler_hu": ([
            "name": "貨郎胡二",
            "file": "/clone/npc/folk/peddler_hu.c",
            "schedules": ([
                "dawn":           "/d/village/peddler_corner.c",
                "morning":        "/d/village/peddler_corner.c",
                "noon_afternoon": "/d/village/peddler_corner.c",
                "dusk":           "/d/village/peddler_corner.c",
                "night":          "/d/village/peddler_corner.c",
                "midnight":       "/d/village/peddler_corner.c"
            ]),
            "action_descs": ([
                "dawn":           "貨郎胡二正將針頭線腦、草鞋與便宜墨錠分格擺進木擔準備開張。",
                "morning":        "貨郎胡二搖著銅撥浪鼓招呼村人賒買日常雜貨與乾麥餅。",
                "dusk":           "貨郎胡二就著燈花點算今日賣出的銅錢與各戶賒帳木牌。"
            ])
        ]),
        "charity_herbalist": ([
            "name": "義診老藥工周伯",
            "file": "/clone/npc/folk/charity_herbalist.c",
            "schedules": ([
                "dawn":           "/d/city/outer/charity_clinic_shed.c",
                "morning":        "/d/city/outer/charity_clinic_shed.c",
                "noon_afternoon": "/d/city/outer/charity_clinic_shed.c",
                "dusk":           "/d/city/outer/charity_clinic_shed.c",
                "night":          "/d/city/outer/charity_clinic_shed.c",
                "midnight":       "/d/city/outer/charity_clinic_shed.c"
            ]),
            "action_descs": ([
                "dawn":           "周伯生起炭火燉上一大砂鍋甘草金銀花清熱湯，準備免費分給棚外病患。",
                "morning":        "周伯正俯身為幾名摔傷腳踝的苦力包紮夾板，仔細叮囑別沾冷水。"
            ])
        ])
    ]);
}

// ── 2b. 關鍵樞紐 NPC-to-NPC 可觀察互動劇本初始化 ──────────────
void init_hub_scenes() {
    hub_scenes = ([
        "/d/counties/qinghe/ferry_dock.c": ({
            "柳伯蹲在平底駁船尾檢查滲水船底，用指節敲著濕木縫朝岸邊學徒吆喝：「再遞兩把麻絮與熱桐油來！」",
            "兩名青河苦力站在跳板旁指著木籌爭得面紅耳赤：「昨兒那兩簍重靈草多繞了半里堤坡，憑啥還按原價給六文？！」",
            "背竹簍的採藥婦人對著水尺嘆氣抱怨：「上游道觀一落水閘就擱淺，連擺渡船資都又漲了兩文，真教人活不起……」",
            "伴隨一聲沉厚號子，滿載藥簍的駁船緩緩解纜撐離岸邊；碼頭一時間安靜下來，只剩青河水輕拍青石樁。"
        }),
        "/d/village/square.c": ({
            "貨郎胡二挑著銅撥浪鼓經過青石街角，跟案後的張屠戶扯起嗓門：「胡大哥，前山鹽價又浮了兩文，今日豬骨可要緊著點砍！」",
            "魯大山端著一碗粗熱水坐到條凳上低聲嘆道：「北崖岩縫昨夜又掉了碎石，這幾日怕是不好下深坑了，大夥得多防著些。」",
            "縮在牆角的乞兒莫三把破陶碗往懷裡攏了攏，渾濁卻銳利的眼神正順著過路貨夫的鞋底泥印掃過。"
        }),
        "/d/city/outer/tenement_alley.c": ({
            "魚販劉三娘提著半竹籃賣剩的小雜魚拐進矮巷，朝土坯棚門裡喊道：「孫伯，今兒有半盆小鯽魚雜骨，趁鮮扔鍋裡熬湯去！」",
            "孫老車夫替鄰家小孩添了兩塊煤核進小泥爐，沙啞叮囑挑夫阿福：「今晚風緊，別圖省事沒帶《暫住牌》往內城暗巷鑽！」",
            "巷口外突然傳來城防軍靴重踏青石板的節拍與遙遠梆聲，矮巷裡的說話聲瞬間壓低，只餘砂鍋咕嘟聲。"
        }),
        "/d/counties/liefan/miners_tea_shed.c": ({
            "老礦工羅七替兩名剛出井的灰頭土臉年輕礦工舀上甘草粗茶：「先漱口再灌下去，別讓肺裡的硫磺末黏死了！」",
            "幾名失業等工的礦工圍著矮桌搓著粗糙手掌嘆氣：「若那三號井還不準復工，這個月家裡的糙米錢真要斷頓了……」",
            "茶棚外一輛空礦車咯吱滑過，眾人齊齊抬頭望向山坡那頭，又低頭默默啜起兩文一碗的粗茶。"
        }),
        "/d/yunjin/river_wharf.c": ({
            "冰河船把頭拿著鐵鉤狠敲開棧板邊緣結成的冰碴，扯嗓喝道：「腳下踩緊防滑麻繩！碎冰封河前最後兩船紅杉今日務必上岸！」",
            "幾名羊皮襖苦力喊著整齊低沉的號子扛木過板，另一頭管事小廝正敲著木籌盤大聲報數點卯。",
            "當頭一批凍木推上貨架，眾人擠在岸邊火盆旁烤著凍紅的雙手，白霧混著木脂香氣升向雪空。"
        }),
        "/d/city/south/wine_tavern.c": ({
            "跑商陳大牙抓起一把五香毛豆拍在榆木桌上：「信我的！這波山路落石外加寒潮下來，鎮風皮襖跟盤木原材半月內準得再翻兩成！」",
            "對桌兩個拉貨老車夫哼笑一聲舉碗碰杯：「你們跑商嘴上翻兩成容易，咱們大冬天走虎跳峽，半條命都在懸崖棧道上懸著！」",
            "店小二從櫃後端出滾燙的粗茶老薑湯，屋裡的喧鬧裡多了幾分冬市煙火暖意。"
        })
    ]);
}

string query_hub_scene_line(string room_path, int beat_idx) {
    if (!hub_scenes) init_hub_scenes();
    if (!room_path || room_path == "") return "";
    if (strsrch(room_path, ".c") == -1) room_path += ".c";
    string *beats = hub_scenes[room_path];
    if (!arrayp(beats) || sizeof(beats) == 0) return "";
    if (beat_idx < 0) beat_idx = 0;
    return beats[beat_idx % sizeof(beats)];
}

string query_current_hub_scene(string room_path) {
    if (!hub_scenes) init_hub_scenes();
    if (!room_path || room_path == "") return "";
    if (strsrch(room_path, ".c") == -1) room_path += ".c";
    string *beats = hub_scenes[room_path];
    if (!arrayp(beats) || sizeof(beats) == 0) return "";
    int b = (mapp(hub_scene_beats) && hub_scene_beats[room_path]) ? hub_scene_beats[room_path] : 0;
    return beats[b % sizeof(beats)];
}

string advance_hub_scene(object room) {
    if (!room) return "";
    string rpath = base_name(room);
    if (strsrch(rpath, ".c") == -1) rpath += ".c";
    if (!hub_scenes) init_hub_scenes();
    string *beats = hub_scenes[rpath];
    if (!arrayp(beats) || sizeof(beats) == 0) return "";
    if (!mapp(hub_scene_beats)) hub_scene_beats = ([]);
    int next_b = (hub_scene_beats[rpath] + 1) % sizeof(beats);
    hub_scene_beats[rpath] = next_b;
    return beats[next_b];
}

// ── 2c. 區域時間維度（日夜時辰 × 季節節律）動態景致生成器 ───────
string query_room_rhythm_line(object room) {
    if (!room) return "";
    string rpath = base_name(room);
    object nat = find_object("/secure/nature_d.c");
    if (!nat) nat = load_object("/secure/nature_d.c");
    string period = current_period ? current_period : "morning";
    string season = nat ? nat->query_season() : "autumn";
    string weather = nat ? nat->query_weather() : "clear";

    string time_note = "";
    if (period == "dawn") {
        if (strsrch(rpath, "fish_market") != -1 || strsrch(rpath, "wharf") != -1 || strsrch(rpath, "dock") != -1) {
            time_note = "天光初亮，頭批靠岸漁船剛卸下竹簍開秤，碼頭苦力與商販正忙著搶早市第一波貨擔。";
        } else if (strsrch(rpath, "peddler") != -1 || strsrch(rpath, "square") != -1) {
            time_note = "晨霧尚未散盡，貨郎與早市攤販正支起油布攤篷、整理貨擔準備開張。";
        } else if (strsrch(rpath, "mine") != -1 || strsrch(rpath, "slope") != -1 || strsrch(rpath, "logging") != -1) {
            time_note = "清晨山風微寒，頭班礦工、石匠與伐木工拎著工器與油燈上工開線。";
        } else {
            time_note = "東方天際剛泛魚肚白，街坊簷下冒出清晨炊煙，行商苦力陸續啟程上工。";
        }
    } else if (period == "morning") {
        if (strsrch(rpath, "market") != -1 || strsrch(rpath, "square") != -1 || strsrch(rpath, "exchange") != -1) {
            time_note = "上午大集正值最喧鬧之際，攤位連成一片，喊價、過秤與車夫招呼聲此起彼落。";
        } else if (strsrch(rpath, "ferry") != -1 || strsrch(rpath, "dock") != -1 || strsrch(rpath, "wharf") != -1) {
            time_note = "早午渡船擺渡往來最密，平底駁船與竹筏挨個靠岸裝卸糧藥木材。";
        } else if (strsrch(rpath, "mine") != -1 || strsrch(rpath, "tongtuo") != -1 || strsrch(rpath, "shinian") != -1 || strsrch(rpath, "fir_logging") != -1) {
            time_note = "上午正是採料作業最旺的時候，鐵鎬敲石、絞盤拉繩與大鋸伐木聲震響山野。";
        } else {
            time_note = "晨陽正盛，坊市營生與官道車馬井然有序地忙碌運轉。";
        }
    } else if (period == "noon_afternoon") {
        if (strsrch(rpath, "gong_") != -1 || strsrch(rpath, "forge") != -1 || strsrch(rpath, "tiangong") != -1) {
            time_note = "午後工坊爐火正旺，鐵匠與器師赤膊鍛打鋼胚，叮噹錘聲震耳欲聾。";
        } else if (strsrch(rpath, "academy") != -1 || strsrch(rpath, "school") != -1) {
            time_note = "午後課堂窗畔傳來整齊的蒙童誦讀聲與夫子講解律曆經義的低沉嗓音。";
        } else if (strsrch(rpath, "wu_") != -1 || strsrch(rpath, "/d/sects/") != -1) {
            time_note = "午後太陽西斜，外門弟子與武徒正在校場演練拳腳樁功，汗氣蒸騰。";
        } else {
            time_note = "午後日頭漸斜，茶攤歇腳的挑夫與奔波商旅在簷蔭下喘氣喝水。";
        }
    } else if (period == "dusk") {
        if (strsrch(rpath, "tea_shed") != -1 || strsrch(rpath, "inn") != -1 || strsrch(rpath, "tavern") != -1) {
            time_note = "黃昏收工時分，滿身灰汗的礦工、苦力與船工陸續擠進茶棚客棧，端碗粗茶邊喝邊嘆生計。";
        } else if (strsrch(rpath, "ferry") != -1 || strsrch(rpath, "dock") != -1 || strsrch(rpath, "wharf") != -1) {
            time_note = "夕陽沉入河面，渡口船隻陸續收帆拉纜鎖上木樁，只餘岸邊數盞防風漁燈搖晃。";
        } else if (strsrch(rpath, "market") != -1 || strsrch(rpath, "square") != -1) {
            time_note = "薄暮時分市集開始收攤，攤販忙著將餘貨裝筐，街市喧鬧漸轉平緩。";
        } else {
            time_note = "殘陽如血將街牆染成暗金，趕路行人加快腳步趕在城門關閉前落腳。";
        }
    } else { // night or midnight
        if (strsrch(rpath, "wine_tavern") != -1 || strsrch(rpath, "inn") != -1) {
            time_note = "夜幕低垂，棚外冷風呼嘯，酒肆客棧裡點起黃燈，醉漢與跑商圍坐喝酒吹牛避寒。";
        } else if (strsrch(rpath, "black_alley") != -1 || strsrch(rpath, "ghost_market") != -1 || strsrch(rpath, "/d/city/under/") != -1) {
            time_note = "深夜正市早已閉門，幽暗巷陌與暗渠鬼市卻在此時點起壓低遮罩的綠燈，私下交易暗湧。";
        } else if (strsrch(rpath, "gate_") != -1 || strsrch(rpath, "wall") != -1 || strsrch(rpath, "tenement_alley") != -1) {
            time_note = "夜深實行街坊宵禁，城防巡夜軍卒提著氣死風燈敲梆盤查，無籍流民多縮門躲避盤問。";
        } else {
            time_note = "四野入夜萬籟俱寂，偶有更夫遠處傳來三更梆聲與寒風刮過屋瓦的輕響。";
        }
    }

    string season_note = "";
    if (season == "winter") {
        if (strsrch(rpath, "/d/wastes/") != -1 || strsrch(rpath, "/d/yunjin/") != -1 || strsrch(rpath, "zhenfeng") != -1 || strsrch(rpath, "/d/routes/") != -1) {
            season_note = HIW "【玄冥冬歲・風雪警戒】寒風如刀，高寒山道與北荒積雪隨時可能封斷車路，皮襖與木炭奇缺！" NOR;
        } else {
            season_note = CYN "【玄冥冬歲・禦寒行情】入冬氣溫驟降，街巷裡羊皮襖、硬木炭與熱老薑湯價碼與需求齊升。" NOR;
        }
    } else if (season == "summer") {
        season_note = HIG "【品物夏歲・暑汛提醒】盛夏濕熱驟雨頻發，河澤瘴氣加重且山溪易暴漲阻道。" NOR;
    }

    if (weather == "storm" && season_note == "") {
        season_note = HIR "【暴雨警示】狂風驟雨沖刷道路，山區泥石滑坡與河道暴漲風險急升！" NOR;
    } else if (weather == "snowy" && season != "winter") {
        season_note = HIW "【突降寒雪】天際飄下罕見冷雪，炭火與驅寒熱湯價格隨之看漲！" NOR;
    }

    string res = CYN "【時辰風物】" NOR + time_note;
    if (season_note != "") res += "\n" + season_note;
    return res;
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

    // 因果經濟聯動：當礦場停工／塌方時，烈礬／重石礦工聚集茶棚或客舍嘆氣
    if (npc_key == "liefan_old_miner" || npc_key == "zhou_quarryman") {
        object ws_d = find_object(WORLD_STATE_D);
        if (ws_d && ws_d->is_mine_economy_halted()) {
            if (npc_key == "liefan_old_miner") return "/d/counties/liefan/miners_tea_shed.c";
            return "/d/counties/zhongshi/post_inn.c";
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

// ── 9. 全域關鍵樞紐互動場景脈動（由 nature_d 定期觸發）─────────
void pulse_hub_scenes() {
    if (!hub_scenes) init_hub_scenes();
    foreach (string r_path, string *beats in hub_scenes) {
        object r = find_object(r_path);
        if (!r) continue;
        // 僅在房內有在線玩家時推進並廣播，避免空耗
        int has_user = 0;
        foreach (object ob in all_inventory(r)) {
            if (userp(ob)) { has_user = 1; break; }
        }
        if (has_user) {
            string line = advance_hub_scene(r);
            if (line != "") {
                tell_room(r, "\n" HIC "【市井日常】" NOR + line + "\n");
            }
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
