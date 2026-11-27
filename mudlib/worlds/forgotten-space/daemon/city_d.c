// daemon/city_d.c
// 《遺忘的世界》金石府城環境守護進程 (CITY_D)
// 維護紅塵濁氣梯度、絕靈法網防衛、城防四關稅則與三日通牒身分緩衝

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

int granary_open;           // 常平倉是否開倉平糶中 (0/1)
int granary_open_timer;     // 開倉剩餘時間 (遊戲分鐘)
int last_tick;

string query_save_file() { return "/data/city_d"; }

void create() {
    ::create();
    granary_open = 0;
    granary_open_timer = 0;
    last_tick = time();

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
}

// ── 1. 紅塵濁氣梯度指數 ──────────────────────────────────────
// center / south: 100% (打坐效率 20%，滯留易積濁氣)
// west / north:   45%  (道統淨化陣法與純陽爐火)
// outer:          15%  (近郊自然清新)
// under:          5%   (紅塵濁氣低，但陰煞地煞極重)
int query_turbidity_index(string room_path) {
    if (!room_path) return 0;
    if (strsrch(room_path, "/d/city/center/") != -1 || strsrch(room_path, "/d/city/south/") != -1) {
        return 100;
    }
    if (strsrch(room_path, "/d/city/west/") != -1 || strsrch(room_path, "/d/city/north/") != -1) {
        return 45;
    }
    if (strsrch(room_path, "/d/city/outer/") != -1) {
        return 15;
    }
    if (strsrch(room_path, "/d/city/under/") != -1) {
        return 5;
    }
    if (strsrch(room_path, "/d/city/gate/") != -1 || strsrch(room_path, "/d/city/wall/") != -1) {
        return 50;
    }
    return 0;
}

// ── 2. 城防絕靈法網防衛機制 ──────────────────────────────────
// 覆蓋: center/, gate/, west/, north/
int is_spirit_sealed_grid(string room_path) {
    if (!room_path) return 0;
    if (strsrch(room_path, "/d/city/center/") != -1 ||
        strsrch(room_path, "/d/city/gate/") != -1 ||
        strsrch(room_path, "/d/city/west/") != -1 ||
        strsrch(room_path, "/d/city/north/") != -1) {
        return 1;
    }
    return 0;
}

// ── 3. 濁氣淨化與累積 ───────────────────────────────────────
int cleanse_turbidity(object who, int amount) {
    if (!who || amount <= 0) return 0;
    int cur = who->query("turbidity");
    if (cur <= 0) return 0;
    cur -= amount;
    if (cur < 0) cur = 0;
    who->set("turbidity", cur);
    return cur;
}

void apply_turbidity_tick(object who) {
    if (!who || !userp(who)) return;
    object env = environment(who);
    if (!env) return;
    string path = base_name(env);
    int idx = query_turbidity_index(path);
    if (idx >= 80) {
        int cur = who->query("turbidity");
        if (cur < 100) {
            cur += 1;
            who->set("turbidity", cur);
            if (cur == 20) {
                tell_object(who, YEL "【心神浮躁】紅塵喧囂紛擾，你感到心神濁氣隱隱上湧 (20/100)。\n" NOR);
            } else if (cur == 50) {
                tell_object(who, HIR "【濁障迷心】市井濁氣沉積靈台，若不儘快淨化，將難以凝神觀象 (50/100)！\n" NOR);
            } else if (cur >= 80 && cur < 100) {
                tell_object(who, HIR "【走火邊緣】心神濁氣已達 " + sprintf("%d", cur) + "/100，氣血翻騰逆行！\n" NOR);
                int hp_drain = who->query("max_kee") * 5 / 100;
                if (hp_drain > 0) who->receive_damage(hp_drain);
            }
        }
    }
}

// ── 4. 四關入城與稅則檢查 ───────────────────────────────────
mapping check_gate_access(object who, string gate_type) {
    if (!who) return ([ "allow": 0, "msg": "無效目標" ]);

    // 檢查是否擁有合法身分憑證
    int has_pass = (present("road pass", who) || present("baoshu", who) || present("保書路引", who)) ? 1 : 0;
    int has_buffer = (present("academy token", who) || present("caravan token", who) || present("clinic token", who)) ? 1 : 0;
    string my_class = who->query("class");
    int has_class = (my_class && my_class != "") ? 1 : 0;

    if (gate_type == "south") {
        // 南關：盤木大木、重石石料大車、流民入口
        // 黑石鋪鄉民憑舊戶籍或路引可免稅，無憑證者需 10 文工本費
        if (has_pass || has_buffer || has_class || who->query("level") >= 10) {
            return ([ "allow": 1, "fee": 0, "msg": "城防武卒審核憑證無誤，放行入城！" ]);
        }
        int money = who->query("money");
        if (money >= 10) {
            who->add_money(-10);
            return ([ "allow": 1, "fee": 10, "msg": "南關稅吏收取了十文流民查驗費，揮手放行入關。" ]);
        }
        return ([ "allow": 0, "fee": 10, "msg": "南關稅吏喝道：「無路引又無盤纏的流民，休想擅闖金石南關！」" ]);
    }

    if (gate_type == "north") {
        // 北關：官道客商、邊防物證
        if (has_pass || has_buffer || has_class || who->query("level") >= 10) {
            return ([ "allow": 1, "fee": 0, "msg": "北關典吏韓清點頭查驗完畢，放行入城！" ]);
        }
        int money = who->query("money");
        if (money >= 10) {
            who->add_money(-10);
            return ([ "allow": 1, "fee": 10, "msg": "北關城防兵收取十文客商登記費，放行入城。" ]);
        }
        return ([ "allow": 0, "fee": 10, "msg": "城門典吏按刀喝道：「北關重地，未經登記流民不得擅入！」" ]);
    }

    // 東關與西水門
    return ([ "allow": 1, "fee": 0, "msg": "盤查通過，放行入關。" ]);
}

// ── 5. 唯一交通路網模型 (ROUTE_SEGMENTS) ─────────────────────
// 嚴格區分：概念方位圖 vs 商貿交通路網 vs MUD 房間拓撲
// 標準欄位：from, to, distance_li, travel_mode, normal_duration, seasonal_block, risk, one_way, canon_status
mapping ROUTE_SEGMENTS = ([
    "seg_city_qinghe_land": ([
        "from": "city", "to": "qinghe", "name": "青河沿河官道",
        "distance_li": 280, "terrain": "land_road",
        "travel_mode": "快馬/步卒/重車", "normal_duration": "快馬36時辰/步3日/重車5日",
        "fast_horse_shichen": 36, "foot_days": 3, "heavy_wagon_days": 5,
        "seasonal_block": "秋雨泥濘，重車行進延緩 20%",
        "seasonal_limits": ([ "autumn": "秋雨泥濘，重車行進延緩 20%" ]),
        "risk": "低窪積水、水匪游哨", "risks": ({ "低窪積水", "水匪游哨" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_city_qinghe_water": ([
        "from": "city", "to": "qinghe", "name": "青河漕運水路",
        "distance_li": 300, "terrain": "waterway",
        "travel_mode": "漕運駁船", "normal_duration": "順流3日/逆流5日(禁快馬)",
        "fast_horse_shichen": 0, "foot_days": 3, "heavy_wagon_days": 3, "upstream_days": 5,
        "seasonal_block": "玄冥冬歲枯水限載五成；品物夏歲洪峰禁航",
        "seasonal_limits": ([ "winter": "玄冥冬歲枯水淺灘，重載駁船限載五成", "summer": "品物夏歲洪峰期間禁航" ]),
        "risk": "水關緝私盤查、淺灘暗礁擱淺", "risks": ({ "水關緝私盤查", "淺灘暗礁擱淺" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_city_liefan": ([
        "from": "city", "to": "liefan", "name": "紅石斷脈山道",
        "distance_li": 320, "terrain": "mountain_road",
        "travel_mode": "快馬/步卒/重車", "normal_duration": "快馬44時辰/步4日/重車8日",
        "fast_horse_shichen": 44, "foot_days": 4, "heavy_wagon_days": 8,
        "seasonal_block": "品物夏歲地火暑熱，行路精力消耗加倍",
        "seasonal_limits": ([ "summer": "品物夏歲地火暑熱，行路精力消耗加倍" ]),
        "risk": "地火毒瘴外溢、礦匪劫掠", "risks": ({ "地火毒瘴外溢", "礦匪劫掠" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_city_panmu": ([
        "from": "city", "to": "panmu", "name": "南嶺林海官道",
        "distance_li": 260, "terrain": "forest_road",
        "travel_mode": "快馬/步卒/重車", "normal_duration": "快馬36時辰/步3日/重車6日",
        "fast_horse_shichen": 36, "foot_days": 3, "heavy_wagon_days": 6,
        "seasonal_block": "金石秋歲連陰雨林道濕滑",
        "seasonal_limits": ([ "autumn": "金石秋歲連陰雨林道濕滑" ]),
        "risk": "大荒走獸流竄、林道滑坡", "risks": ({ "大荒走獸流竄", "林道滑坡" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_city_zhenfeng": ([
        "from": "city", "to": "zhenfeng", "name": "北塞天風馳道",
        "distance_li": 300, "terrain": "gorge_highway",
        "travel_mode": "快馬/步卒/重車", "normal_duration": "快馬40時辰/步4日/重車6日",
        "fast_horse_shichen": 40, "foot_days": 4, "heavy_wagon_days": 6,
        "seasonal_block": "玄冥冬歲天風谷暴雪封關，重車禁行",
        "seasonal_limits": ([ "winter": "玄冥冬歲天風谷暴雪封關，重車禁行" ]),
        "risk": "罡風迷眼、外荒兇獸南侵", "risks": ({ "罡風迷眼", "外荒兇獸南侵" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_city_zhuoshui_land": ([
        "from": "city", "to": "zhuoshui", "name": "東南沼澤浮橋道",
        "distance_li": 350, "terrain": "swamp_pontoon",
        "travel_mode": "快馬/步卒/重車", "normal_duration": "快馬48時辰/步5日/重車8日",
        "fast_horse_shichen": 48, "foot_days": 5, "heavy_wagon_days": 8,
        "seasonal_block": "品物夏歲水澤瘴氣爆發，山洪易沖毀浮橋",
        "seasonal_limits": ([ "summer": "品物夏歲水澤瘴氣爆發，山洪易沖毀浮橋" ]),
        "risk": "腐骨泥沼、淘金幫黑吃黑", "risks": ({ "腐骨泥沼", "淘金幫黑吃黑" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_city_zhuoshui_under": ([
        "from": "city_under", "to": "zhuoshui", "name": "地下溶洞暗河",
        "distance_li": 310, "terrain": "underground_canal",
        "travel_mode": "暗河輕舟/步涉(禁車馬)", "normal_duration": "步涉4日/暗舟5日",
        "fast_horse_shichen": 0, "foot_days": 4, "heavy_wagon_days": 5,
        "seasonal_block": "品物夏歲暴雨暗河倒灌完全封閉",
        "seasonal_limits": ([ "summer": "品物夏歲暴雨暗河倒灌封閉" ]),
        "risk": "法網盲區、陰煞地蟲、水鬼截殺", "risks": ({ "法網盲區", "陰煞地蟲", "水鬼截殺" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_city_zhongshi": ([
        "from": "city", "to": "zhongshi", "name": "西南條石馳道",
        "distance_li": 240, "terrain": "paved_highway",
        "travel_mode": "快馬/步卒/重車", "normal_duration": "快馬32時辰/步3日/重車5日",
        "fast_horse_shichen": 32, "foot_days": 3, "heavy_wagon_days": 5,
        "seasonal_block": "全年暢通",
        "seasonal_limits": ([]),
        "risk": "重載車隊擁堵、石匪路霸", "risks": ({ "重載車隊擁堵", "石匪路霸" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_blackstone_panmu": ([
        "from": "blackstone", "to": "panmu", "name": "虎跳峽林道（東線）",
        "distance_li": 190, "terrain": "canyon_forest_road",
        "travel_mode": "快馬/步卒/重車", "normal_duration": "快馬28時辰/步3日/重車4日",
        "fast_horse_shichen": 28, "foot_days": 3, "heavy_wagon_days": 4,
        "seasonal_block": "玄冥冬歲初冬凍融落石；一元春歲春融泥石流",
        "seasonal_limits": ([ "winter": "玄冥冬歲初冬凍融易發落石滑坡", "spring": "一元春歲春融泥石流" ]),
        "risk": "虎跳峽落石、黑石關盤剝、煞化野獸", "risks": ({ "虎跳峽落石", "黑石關盤剝", "煞化野獸" }),
        "one_way": 0, "canon_status": "CANON"
    ]),
    "seg_blackstone_zhongshi": ([
        "from": "blackstone", "to": "zhongshi", "name": "落龍西谷棧道（西線）",
        "distance_li": 180, "terrain": "cliff_plank_road",
        "travel_mode": "快馬/輕裝步卒(禁重車)", "normal_duration": "快馬24時辰/步2日/重車禁行",
        "fast_horse_shichen": 24, "foot_days": 2, "heavy_wagon_days": 0, // 0 表示禁行重車
        "seasonal_block": "品物夏歲山洪淹沒棧道；玄冥冬歲懸崖棧道結冰封閉",
        "seasonal_limits": ([ "summer": "品物夏歲溪谷山洪淹沒棧道", "winter": "玄冥冬歲懸崖棧道結冰封閉" ]),
        "risk": "懸崖斷棧、地煞裂隙毒氣", "risks": ({ "懸崖斷棧", "地煞裂隙毒氣" }),
        "one_way": 0, "canon_status": "RULE"
    ]),
    "seg_qinghe_zhongshi": ([
        "from": "qinghe", "to": "zhongshi", "name": "西嶺支脈山道",
        "distance_li": 160, "terrain": "hill_trail",
        "travel_mode": "快馬/步卒/重車", "normal_duration": "快馬24時辰/步2日/重車4日",
        "fast_horse_shichen": 24, "foot_days": 2, "heavy_wagon_days": 4,
        "seasonal_block": "金石秋歲山霧迷途",
        "seasonal_limits": ([ "autumn": "金石秋歲山霧迷途" ]),
        "risk": "山嶺野獸、私鹽販子", "risks": ({ "山嶺野獸", "私鹽販子" }),
        "one_way": 0, "canon_status": "PROPOSAL"
    ]),
    "seg_liefan_zhuoshui": ([
        "from": "liefan", "to": "zhuoshui", "name": "東麓峽谷私梟道",
        "distance_li": 210, "terrain": "smuggler_ravine",
        "travel_mode": "快馬/步卒/走私車", "normal_duration": "快馬30時辰/步3日/重車6日",
        "fast_horse_shichen": 30, "foot_days": 3, "heavy_wagon_days": 6,
        "seasonal_block": "品物夏歲硫磺瘴水交匯劇毒",
        "seasonal_limits": ([ "summer": "品物夏歲硫磺瘴水交匯劇毒" ]),
        "risk": "無印生銅與私硝走私火併", "risks": ({ "無印生銅與私硝走私火併" }),
        "one_way": 0, "canon_status": "PROPOSAL"
    ])
]);

mapping query_route_segment(string seg_id) {
    if (!seg_id || !ROUTE_SEGMENTS[seg_id]) return 0;
    return ROUTE_SEGMENTS[seg_id];
}

mapping query_all_route_segments() {
    return ROUTE_SEGMENTS;
}

// 查詢兩地之間的複合路線（如黑石鋪至金石府城：東線盤木 450 里 vs 西線重石 420 里）
mapping query_composite_routes(string from_node, string to_node) {
    if ((from_node == "blackstone" && to_node == "city") || (from_node == "city" && to_node == "blackstone")) {
        mapping seg_bp = ROUTE_SEGMENTS["seg_blackstone_panmu"];
        mapping seg_cp = ROUTE_SEGMENTS["seg_city_panmu"];
        mapping seg_bz = ROUTE_SEGMENTS["seg_blackstone_zhongshi"];
        mapping seg_cz = ROUTE_SEGMENTS["seg_city_zhongshi"];
        return ([
            "east_panmu_route": ([
                "name": "東線・盤木林道官道線",
                "via": "panmu",
                "segments": ({ "seg_blackstone_panmu", "seg_city_panmu" }),
                "total_distance_li": seg_bp["distance_li"] + seg_cp["distance_li"], // 190 + 260 = 450 里
                "fast_horse_shichen": seg_bp["fast_horse_shichen"] + seg_cp["fast_horse_shichen"],
                "foot_days": seg_bp["foot_days"] + seg_cp["foot_days"],
                "heavy_wagon_allowed": 1,
                "heavy_wagon_days": seg_bp["heavy_wagon_days"] + seg_cp["heavy_wagon_days"],
                "desc": "經虎跳峽與盤木縣入南關（450 里），路寬坡緩可通重載大車，為金石商會主力商道。"
            ]),
            "west_zhongshi_route": ([
                "name": "西線・重石河谷棧道線",
                "via": "zhongshi",
                "segments": ({ "seg_blackstone_zhongshi", "seg_city_zhongshi" }),
                "total_distance_li": seg_bz["distance_li"] + seg_cz["distance_li"], // 180 + 240 = 420 里
                "fast_horse_shichen": seg_bz["fast_horse_shichen"] + seg_cz["fast_horse_shichen"],
                "foot_days": seg_bz["foot_days"] + seg_cz["foot_days"],
                "heavy_wagon_allowed": 0,
                "heavy_wagon_days": 0,
                "desc": "經落龍西谷棧道與重石縣入南關（420 里），捷徑省時但懸崖棧道禁行重車，且易受山洪凍融阻斷。"
            ])
        ]);
    }
    return ([]);
}

// ── 6. 歷史法統、權力運作邊界與三方會審機制 ─────────────────
mapping POWER_AUTHORITIES = ([
    "yamen": ([
        "name": "金石府衙（大乾遺制法統）",
        "leader": "秦正明（金石府尹）",
        "jurisdiction": ({ "內城治安拘捕", "戶籍田契底單", "凡胎刑民詞訟", "四關基礎門稅", "常平倉平糶權" }),
        "hard_limits": "無直屬野戰大軍（僅轄兩百衙役捕快），無權單獨調兵出城或單方面抄沒商會總堂資產；亦無權單獨審判現役邊防軍官。",
        "cert_nature": "administrative_judicial_ruling"
    ]),
    "wen_chengjing": ([
        "name": "府衙案牘庫（六房主簿）",
        "leader": "文承敬（案牘主簿）",
        "jurisdiction": ({ "核驗地契路引與匠籍底冊真偽", "封存與調閱歷年稅冊舊案", "三方會審文書比對公證" }),
        "hard_limits": "僅具文書核驗與呈堂公證權，無獨立執法或拘捕權；調閱三十年前大清洗密檔須府尹手令或三司合簽。",
        "cert_nature": "archival_document_notarization"
    ]),
    "junzhen": ([
        "name": "鎮武軍鎮與城防司（八方武館）",
        "leader": "陳鎮山（北塞鎮武統帥）／雷震（北關巡防副將）／霸山（武館總教頭）",
        "jurisdiction": ({ "關外邊防衛所", "城防四關駐軍", "生死擂台私鬥仲裁", "外門黑鐵腰牌核發" }),
        "hard_limits": "關外防務由軍鎮虎符單獨授權；但調兵入內城或跨縣查抄，必須府衙官印＋軍鎮虎符＋後勤餉票三方合符。",
        "cert_nature": "military_command_and_ordnance_audit"
    ]),
    "chen_zhenshan": ([
        "name": "北塞鎮武軍鎮帥府",
        "leader": "陳鎮山（鎮武將軍）",
        "jurisdiction": ({ "北塞天風谷防線調兵", "關外邊防軍令單獨授權", "現役邊防軍官軍法會審權" }),
        "hard_limits": "非經三印合符不得率邊軍入內城干政；糧餉與火器補給受制於府衙常平倉、商會車隊與百工軍器局。",
        "cert_nature": "border_military_authority"
    ]),
    "shanghui": ([
        "name": "金石商會與通寶體系",
        "leader": "錢百川（副會長）／蘇忠（蘇氏舊部）／賈富春（通寶當鋪）",
        "jurisdiction": ({ "六縣大宗車馬漕運調度", "通寶銀票跨縣匯兌", "六縣專材長街鋪席配額", "邊軍糧餉代辦" }),
        "hard_limits": "嚴禁私蓄披甲重步卒與官禁火器；內部帳目雖受行規保護，但若物價突破 250% 紅線或證實惡意凍結準備金，府尹可依荒政律強制開常平倉平糶並會審查封暗庫。",
        "cert_nature": "commercial_credit_and_waybill_verification"
    ]),
    "xuandaosi": ([
        "name": "金石府宣道司",
        "leader": "玄機真人（道官）／星淵（觀星師）",
        "jurisdiction": ({ "內城絕靈法網陣樞維運", "曆法節氣與煞潮預警", "法道大乾度牒核發", "涉煞物證靈煞溯源勘驗" }),
        "hard_limits": "不直接干預凡俗賦稅詞訟，依賴府衙與商會供奉維持摘星台與法網靈石消耗；其勘驗結論屬『專業技術鑑定意見』，須交由府衙或三方會審採信方具司法強制力。",
        "cert_nature": "technical_forensic_opinion"
    ]),
    "baigong": ([
        "name": "府城百工總會與軍器局",
        "leader": "歐陽大師（匠首）／莫錘（鍛造大師）",
        "jurisdiction": ({ "城防重械水閘床弩維運", "官禁硝火作雷管督造核銷", "正式匠籍與六縣原料調撥核銷", "器物暗銘與工藝鑑定" }),
        "hard_limits": "官禁雷管與重械嚴禁私流民間（須軍鎮簽領＋百工核銷雙聯存根）；原料命脈受制於烈礬、重石、盤木各縣產能與商會物流。",
        "cert_nature": "craft_and_ordnance_origin_authentication"
    ]),
    "junqiju": ([
        "name": "百工軍器局（官禁硝火作）",
        "leader": "歐陽大師兼管／莫錘協查",
        "jurisdiction": ({ "官禁開山雷管批號督造", "城防破甲重弩配給", "火器出庫雙聯火印核銷" }),
        "hard_limits": "無權私自對外販售火器，亦無獨立抓捕權；發現批號外流須移交軍鎮執法隊與府衙合查。",
        "cert_nature": "ordnance_batch_authentication"
    ])
]);

mapping FACTION_BRANCHES = ([
    "shanghui_qian":    ([ "parent": "shanghui",  "name": "錢氏實利派", "rep": "錢百川、錢不換", "stance": "壟斷六縣礦木、暗中轉運高利地煞晶錠以養私衛" ]),
    "shanghui_su":      ([ "parent": "shanghui",  "name": "蘇氏規約派", "rep": "蘇凝霜、蘇忠",   "stance": "堅守跨縣公平契約與鄉鎮共生，反對竭澤而漁" ]),
    "shanghui_tongbao": ([ "parent": "shanghui",  "name": "通寶中立暗線", "rep": "賈朝奉（賽半仙）", "stance": "認印不認人，暗中保存三十年前舊商盟清洗底帳" ]),
    "junzhen_wuguan":   ([ "parent": "junzhen",   "name": "武館血氣派", "rep": "霸山、趙猛、厲無咎", "stance": "崇尚純陽氣血與擂台明規，鄙視官商黑幕" ]),
    "junzhen_bianfang": ([ "parent": "junzhen",   "name": "邊防軍功派", "rep": "雷震（部分基層如胡百戶腐化）", "stance": "因北塞傷亡重且軍餉屢拖欠，部分基層軍官淪為走私保護傘自籌餉銀" ]),
    "yamen_fumin":      ([ "parent": "yamen",     "name": "守成撫民派", "rep": "秦正明、文承敬、劉秉忠", "stance": "死守常平倉糧儲底線與舊案卷宗真相，力求城邦不崩" ]),
    "dao_shuntian":     ([ "parent": "xuandaosi", "name": "清虛順天派", "rep": "玄機真人",       "stance": "維持絕靈法網與假天道化秩序，視凡間政爭為紅塵微濁" ]),
    "dao_qiuzhen":      ([ "parent": "xuandaosi", "name": "觀象求真派", "rep": "星淵",           "stance": "由逆星軌與地煞異動察覺大清洗法則殘缺，暗中尋求破局者" ]),
    "baigong_shouzheng":([ "parent": "baigong",   "name": "匠道守正派", "rep": "歐陽大師、莫錘", "stance": "痛恨百工造物淪為地煞邪器，嚴查丙字柒號坩堝外流真相" ]),
    "baigong_gongli":   ([ "parent": "baigong",   "name": "官造功利派", "rep": "部分分坊管事",   "stance": "為換取烈礬耐火料與經費，對商會私單睜一隻眼閉一隻眼" ])
]);

mapping query_power_authority(string org_id) {
    return POWER_AUTHORITIES[org_id];
}

mapping query_faction_branch(string branch_id) {
    return FACTION_BRANCHES[branch_id];
}

// 軍令授權檢驗：邊防關卡僅需軍鎮虎符；入城調兵或跨縣查抄需三印合符
mapping check_military_order_auth(string order_scope, string *seals) {
    if (!seals) seals = ({});
    int has_tiger = (member_array("junzhen_tiger_tally", seals) != -1);
    int has_yamen = (member_array("yamen_seal", seals) != -1);
    int has_supply = (member_array("supply_warrant", seals) != -1);

    if (order_scope == "border_patrol" || order_scope == "gate_lockdown") {
        if (has_tiger) {
            return ([ "authorized": 1, "mode": "single_tally", "msg": "持鎮武軍鎮虎符，邊防衛所與關卡駐軍依令執行戒嚴盤查。" ]);
        }
        return ([ "authorized": 0, "mode": "single_tally", "msg": "缺乏軍鎮虎符，邊關駐軍不受單獨文官調遣。" ]);
    }

    // 調兵入城、跨縣剿匪、查抄大宗庫房：必須三方合符
    if (has_tiger && has_yamen && has_supply) {
        return ([
            "authorized": 1,
            "mode": "tri_seal_joint",
            "msg": "府衙官印、軍鎮虎符與後勤餉票三印合符，披甲武卒與府衙捕快聯合開拔執法！"
        ]);
    }
    return ([
        "authorized": 0,
        "mode": "tri_seal_joint",
        "msg": "《金石共治盟約》規定：凡調兵入城或查抄大宗資產，須集齊府衙官印、軍鎮虎符與後勤餉票，缺一不可！"
    ]);
}

// ── 7. 證據狀態與證明力邊界模型 (P0-4 五欄結構) ──────────────────
mapping EVIDENCE_REGISTRY = ([
    "relay_poison_sample": ([
        "name": "驛站毒案殘留樣本（對比濁水毒囊）",
        "supported_claims": "證明驛站毒物與濁水澤腐骨毒囊具備相同材料來源與提煉製程",
        "unsupported_claims": "不能單獨證明誰是下毒真兇，亦不能直接證明商會高層指使投毒",
        "source_independence": "physical_trace",
        "chain_of_custody": "須以百草封靈玉瓶封存且未受暗渠污水二次污染",
        "certifier_authority": "xuandaosi_and_xinglin",
        "tribunal_domain": "law"
    ]),
    "liefan_clay_batch": ([
        "name": "烈礬耐火泥批次與商會內堂採辦簽名",
        "supported_claims": "證明該批特級耐火泥由金石商會內堂出資採辦並運入府城",
        "unsupported_claims": "不能直接證明採辦簽名者知悉耐火泥最終被用於私鑄地煞禁器",
        "source_independence": "single_internal",
        "chain_of_custody": "須保留烈礬窯場火印與南關入城稅單存根互證",
        "certifier_authority": "wen_chengjing_and_su_auditor",
        "tribunal_domain": "guild"
    ]),
    "detonator_serial_ledger": ([
        "name": "官禁雷管連號批號與軍需簽領簿",
        "supported_claims": "證明流入黑石鋪之雷管在帳面上由城防司特定軍需官簽領流出，構成正式調查理由",
        "unsupported_claims": "若僅有內部簽領簿而無百工出庫火印存根，不能排除盜印造假，無法單獨定罪頂層將領",
        "source_independence": "single_internal",
        "chain_of_custody": "須同時取得城防軍需簽領簿與百工硝火作雙聯出庫存根",
        "certifier_authority": "junqiju_and_junzhen",
        "tribunal_domain": "military"
    ]),
    "under_canal_deed": ([
        "name": "地下暗渠密室取得之舊商盟底單",
        "supported_claims": "證明三十年前礦脈產權轉移存在未公開之私下雙重契約",
        "unsupported_claims": "若取得程序有瑕疵，公證人僅能證明尋獲過程，不能自動補正底單上死人印鑑真偽",
        "source_independence": "cross_verified",
        "chain_of_custody": "尋獲時須由案牘主簿文承敬或宣道司經生現場火漆封存並比對通寶暗帳",
        "certifier_authority": "wen_chengjing_and_tongbao",
        "tribunal_domain": "law"
    ]),
    "crucible_bing_7": ([
        "name": "丙字柒號百工特規坩堝殘骸",
        "supported_claims": "證明私煉地煞晶錠現場使用了百工總會特批高階坩堝且殘留非法地煞結晶",
        "unsupported_claims": "不能單獨證明原鍛造匠師知情參與私煉（可能係報廢品遭分坊管事私調）",
        "source_independence": "physical_trace",
        "chain_of_custody": "現場起獲後須保持內壁地煞結晶與百工暗銘完整",
        "certifier_authority": "baigong_and_xuandaosi",
        "tribunal_domain": "guild"
    ]),
    "miner_thumbprints": ([
        "name": "黑石鋪生還礦工聯名血手印供狀",
        "supported_claims": "證明礦難發生時礦坑被從外部反鎖且有人蓄意引爆雷管之現場目擊事實",
        "unsupported_claims": "礦工未見幕後主使真容，不能單獨指證府城商會會長或軍鎮高層",
        "source_independence": "cross_verified",
        "chain_of_custody": "須於府衙公堂具結畫押並保護證人免遭滅口",
        "certifier_authority": "yamen",
        "tribunal_domain": "law"
    ])
]);

mapping query_evidence_def(string ev_id) {
    return EVIDENCE_REGISTRY[ev_id];
}

// 評估單一證據在當前保管鏈與認證狀態下的證明力階級：lead_only / corroborating / conclusive
mapping evaluate_evidence_probative_value(string ev_id, int custody_intact, int certified) {
    if (!ev_id || !EVIDENCE_REGISTRY[ev_id]) {
        return ([ "tier": "invalid", "weight": 0, "msg": "未知證據編號" ]);
    }
    mapping def = EVIDENCE_REGISTRY[ev_id];
    if (!custody_intact) {
        return ([
            "tier": "lead_only",
            "weight": 0,
            "supported_claims": def["supported_claims"],
            "unsupported_claims": def["unsupported_claims"],
            "msg": "【保管鏈瑕疵】『" + def["name"] + "』欠缺完整封存程序，公證人僅能證明尋獲過程，無法排除污染或偽造，僅能作為調查線索（會審權重 0）。"
        ]);
    }
    if (!certified) {
        return ([
            "tier": "lead_only",
            "weight": 0,
            "supported_claims": def["supported_claims"],
            "unsupported_claims": def["unsupported_claims"],
            "msg": "【未經權威認證】『" + def["name"] + "』尚未經法定機構（" + def["certifier_authority"] + "）核驗用印，僅構成調查理由，不可直接呈堂定罪。"
        ]);
    }
    if (def["source_independence"] == "single_internal") {
        return ([
            "tier": "corroborating",
            "weight": 1,
            "supported_claims": def["supported_claims"],
            "unsupported_claims": def["unsupported_claims"],
            "msg": "【間接佐證】『" + def["name"] + "』雖經認證，但屬單一內部帳冊來源，僅能證明（" + def["supported_claims"] + "），尚不能單獨證明（" + def["unsupported_claims"] + "），須與跨機構實物互鎖。"
        ]);
    }
    return ([
        "tier": "conclusive",
        "weight": 2,
        "supported_claims": def["supported_claims"],
        "unsupported_claims": def["unsupported_claims"],
        "msg": "【核心實證】『" + def["name"] + "』具備獨立來源、完整保管鏈與權威認證，可有效鎖定（" + def["supported_claims"] + "）！"
    ]);
}

// 三方會審裁決與執行機制 (Tripartite Tribunal)
mapping conduct_tripartite_tribunal(string case_id, string *evidence_list) {
    if (!evidence_list) evidence_list = ({});
    int law_vote = 0;      // 法度方（府衙＋宣道司）
    int military_vote = 0; // 軍武方（鎮武軍鎮）
    int guild_vote = 0;    // 工商方（百工總會＋金石商會）

    foreach (string ev in evidence_list) {
        if (ev == "miner_thumbprints" || ev == "old_archive_deed" || ev == "disha_taint_sample" ||
            ev == "relay_poison_sample" || ev == "under_canal_deed") law_vote = 1;
        if (ev == "garrison_bribe_ledger" || ev == "smuggled_armor_batch" ||
            ev == "detonator_serial_ledger") military_vote = 1;
        if (ev == "crucible_bing_7" || ev == "secret_vault_manifest" ||
            ev == "liefan_clay_batch") guild_vote = 1;
    }

    int total_votes = law_vote + military_vote + guild_vote;
    if (total_votes < 2) {
        return ([
            "verdict": "deadlocked",
            "votes": total_votes,
            "msg": "三方會審證據不足兩席共識，涉案高層推諉塞責，案件暫予擱置候查。"
        ]);
    }

    return ([
        "verdict": "convicted",
        "votes": total_votes,
        "prison_target": "/d/city/center/yamen_prison.c",
        "seized_vault": "/d/city/south/warehouse_shang.c",
        "asset_split": ([ "granary": 30, "military_pay": 40, "baigong_melt": 30 ]),
        "msg": "三方會審達成共識：涉案主犯由府衙獄頭與軍鎮執法隊共同畫押鎖入死牢；查抄暗庫資產三成充入常平倉、四成折抵邊軍欠餉、三成移交百工回爐銷毀！"
    ]);
}

// ── 8. 第二卷壓力測試節點 1：72 小時三日通牒與三條緩衝路徑法律機制 (Ch.39–46) ──
mapping check_residency_mandate(object who, int hours_in_city) {
    if (!who) return ([ "status": "invalid" ]);

    // 若已取得正式道途或專業資格，視為已正式立籍
    string my_class = who->query("class");
    mapping quals = who->query_qualifications();
    if ((my_class && my_class != "") || (mapp(quals) && sizeof(keys(quals)) > 0)) {
        return ([
            "status": "formal_resident",
            "obligation": "none",
            "grace_hours_total": 999999,
            "hours_remaining": 999999,
            "msg": "你已取得金石府正式行會／道統資格立籍，享有完整內城居留與執業權。"
        ]);
    }

    // 檢查三條臨時擔保緩衝路徑（延長的是「免除無籍流民拘役並完成正式資格考核」的寬限期）
    if (present("academy token", who) || who->query_temp("residency_buffer") == "academy") {
        int limit = 72 + 14 * 24; // 72h + 14天(336h) = 408h
        return ([
            "status": (hours_in_city <= limit) ? "buffered_temporary" : "buffer_expired",
            "buffer_type": "academy",
            "extension_days": 14,
            "obligation": "complete_formal_qualification",
            "grace_hours_total": limit,
            "hours_remaining": (limit > hours_in_city) ? (limit - hours_in_city) : 0,
            "msg": "憑城西蒙學塾保書完成臨時居留擔保，免除無籍流民拘役，並獲延長 14 日（共 408 小時）正式立籍考核寬限期。"
        ]);
    }
    if (present("clinic token", who) || who->query_temp("residency_buffer") == "clinic") {
        int limit = 72 + 10 * 24; // 72h + 10天(240h) = 312h
        return ([
            "status": (hours_in_city <= limit) ? "buffered_temporary" : "buffer_expired",
            "buffer_type": "clinic",
            "extension_days": 10,
            "obligation": "complete_formal_qualification",
            "grace_hours_total": limit,
            "hours_remaining": (limit > hours_in_city) ? (limit - hours_in_city) : 0,
            "msg": "憑杏林醫館試藥保條完成臨時居留擔保，免除無籍流民拘役，並獲延長 10 日（共 312 小時）正式立籍考核寬限期。"
        ]);
    }
    if (present("caravan token", who) || who->query_temp("residency_buffer") == "caravan") {
        int limit = 72 + 7 * 24; // 72h + 7天(168h) = 240h
        return ([
            "status": (hours_in_city <= limit) ? "buffered_temporary" : "buffer_expired",
            "buffer_type": "caravan",
            "extension_days": 7,
            "obligation": "complete_formal_qualification",
            "grace_hours_total": limit,
            "hours_remaining": (limit > hours_in_city) ? (limit - hours_in_city) : 0,
            "msg": "憑車馬大院趟子手腰牌完成臨時居留擔保，免除無籍流民拘役，並獲延長 7 日（共 240 小時）正式立籍考核寬限期。"
        ]);
    }
    if (present("temp residency pass", who) || who->query_temp("residency_buffer") == "temp_pass") {
        int limit = 72 + 5 * 24; // 72h + 5天(120h) = 192h
        return ([
            "status": (hours_in_city <= limit) ? "outer_temp_pass" : "buffer_expired",
            "buffer_type": "temp_pass",
            "extension_days": 5,
            "obligation": "complete_formal_qualification",
            "grace_hours_total": limit,
            "hours_remaining": (limit > hours_in_city) ? (limit - hours_in_city) : 0,
            "msg": "持《金石南關暫住牌》完成外城去向登記，免遭夜間當街拘役，可於外城碼頭做散工，但仍須設法取得正式保書或考牒方能立籍內城。"
        ]);
    }

    // 未持緩衝擔保者：受 72 小時（三日通牒）臨時居留擔保登錄限制
    if (hours_in_city <= 72) {
        return ([
            "status": "initial_72h_window",
            "obligation": "register_temporary_sponsor",
            "grace_hours_total": 72,
            "hours_remaining": 72 - hours_in_city,
            "msg": "入城未滿 72 小時：須於三日通牒屆滿前覓得學塾、醫館或車馬院完成『臨時居留擔保登錄』，否則將列為無籍流民。"
        ]);
    }

    return ([
        "status": "unregistered_vagrant",
        "obligation": "subject_to_curfew_corvee",
        "grace_hours_total": 72,
        "hours_remaining": 0,
        "msg": "【三日通牒逾期】入城已逾 72 小時且無任何機構擔保，你已被府衙列為『無籍流民』，夜間受宵禁巡防隊拘役並禁止租屋立約！"
    ]);
}

// ── 9. 第二卷壓力測試節點 3：通寶分號信用凍結邊界機制 (Ch.68–76) ──────
mapping evaluate_credit_freeze_impact(string transaction_type) {
    // 通寶信印僅保證跨分號異地匯兌與行會大宗遠期帳期，不等於全府唯一法定現銀貨幣
    if (transaction_type == "inter_county_bill" || transaction_type == "guild_credit_settlement") {
        return ([
            "frozen": 1,
            "scope": "tongbao_clearing_network",
            "msg": "【跨縣清算凍結】通寶分號暫停跨縣飛錢異地兌付與行會遠期帳期貼現，大宗礦木交割與邊軍異地匯餉受阻！"
        ]);
    }
    if (transaction_type == "cash_copper_silver" || transaction_type == "official_granary_relief") {
        return ([
            "frozen": 0,
            "scope": "sovereign_spot_currency",
            "msg": "【現銀銅錢照常流通】通寶信印並非全府唯一法定貨幣，民間市井現銅現銀買賣與府衙常平倉平糶糧食不受票據凍結影響。"
        ]);
    }
    return ([ "frozen": 0, "scope": "unknown", "msg": "一般交易" ]);
}

// 核驗通寶信用凍結是否為人為惡意操控：須比對「通寶總號準備金底冊」與「四關押銀重車入城稅單」
mapping verify_credit_freeze_manipulation(int has_vault_reserve_ledger, int has_gate_silver_tax_receipt) {
    if (has_vault_reserve_ledger && has_gate_silver_tax_receipt) {
        return ([
            "proven_manipulation": 1,
            "emergency_authority_triggered": "yamen_famine_relief_seizure",
            "msg": "經比對【通寶總號準備金底冊】與【南關押銀重車入城稅單】，證實六縣現銀早已入城鎖入商會南倉暗庫而非在途遭劫，定性為『人為惡意操縱信用』，府尹依法啟動荒政律強制查封暗庫！"
        ]);
    }
    return ([
        "proven_manipulation": 0,
        "emergency_authority_triggered": "none",
        "msg": "僅憑單方傳聞或單一帳冊，尚無法戳破商會『押銀在途遭劫、準備金暫時短缺』之抗辯藉口。"
    ]);
}

// ── 10. 玩家居留即時檢查介面 ─────────────────────────────────
mapping check_user_residency(object who) {
    if (!who || !userp(who)) return ([ "status": "invalid" ]);

    int entry_time = who->query("city_entry_time");
    if (!entry_time) {
        entry_time = time();
        who->set("city_entry_time", entry_time);
    }

    // 15 秒 = 1 遊戲分鐘，900 秒 = 60 遊戲分鐘 = 1 遊戲小時
    int hours_in_city = (time() - entry_time) / 900;
    if (hours_in_city < 0) hours_in_city = 0;

    return check_residency_mandate(who, hours_in_city);
}

// ── 11. 常平倉緊急開倉平糶平抑機制 ────────────────────────────
int query_granary_open() {
    return granary_open;
}

int query_granary_price_pct() {
    return granary_open ? 75 : 100;
}

int trigger_granary_stabilization(string cause) {
    granary_open = 1;
    granary_open_timer = 120; // 平糶維持 120 遊戲分鐘 (約 30 分鐘真實時間)
    save_object(query_save_file());

    string notice = sprintf(
        "\n" HIY "【金石府常平倉平糶告示】府尹秦正明手諭：\n"
        "鑒於外縣災異與大荒商道受阻（%s），物資價格飆越兩成半（250%%）法統警戒！\n"
        "金石府衙即刻開常平倉平糶，按平價七五折供應城鄉米糧與急需草料！" NOR "\n",
        (cause && cause != "") ? cause : "六縣專材告急"
    );

    object *all_users = users();
    if (all_users) {
        foreach (object u in all_users) {
            if (u) tell_object(u, notice);
        }
    }
    return 1;
}

void city_tick(int game_time) {
    if (granary_open) {
        granary_open_timer--;
        if (granary_open_timer <= 0) {
            granary_open = 0;
            save_object(query_save_file());
            object *all_users = users();
            if (all_users) {
                foreach (object u in all_users) {
                    if (u) tell_object(u, WHT "\n【常平倉告示】緊急平糶完畢，常平倉大門重新合閉封存，常規市井物價回穩。\n" NOR);
                }
            }
        }
    } else {
        // 自主檢核六縣物價是否突破 250%
        object ws_d = find_object(WORLD_STATE_D);
        if (!ws_d) ws_d = load_object(WORLD_STATE_D);
        if (ws_d) {
            mapping clocks = ws_d->query_all_county_clocks();
            if (mapp(clocks)) {
                foreach (string cid in keys(clocks)) {
                    if (clocks[cid] && clocks[cid]["price_pct"] >= 250) {
                        trigger_granary_stabilization(sprintf("%s專材價格突破 250%%", cid));
                        break;
                    }
                }
            }
        }
    }
}

// ── 12. 物證污染 / 修復與主動出示、互相印證系統 (Evidence Presentation & Corroboration) ──
string normalize_evidence_id(object ev_ob, string raw_id) {
    string id = raw_id ? lower_case(raw_id) : "";
    if (ev_ob) {
        string bn = base_name(ev_ob);
        if (strsrch(bn, "detonator_serial_ledger") != -1) return "detonator_serial_ledger";
        if (strsrch(bn, "liefan_clay_batch") != -1) return "liefan_clay_batch";
        if (strsrch(bn, "relay_poison_sample") != -1) return "relay_poison_sample";
        if (strsrch(bn, "miner_thumbprints") != -1) return "miner_thumbprints";
        if (strsrch(bn, "under_canal_deed") != -1) return "under_canal_deed";
        if (strsrch(bn, "custody_ledger") != -1) return "custody_ledger";
        if (strsrch(bn, "crucible_bing_7") != -1) return "crucible_bing_7";
        if (strsrch(bn, "yunji_roster") != -1) return "yunji_roster";
        if (strsrch(bn, "bronze_treaty_plate") != -1) return "bronze_treaty_plate";
        if (strsrch(bn, "tianmen_token") != -1) return "tianmen_token";
        if (strsrch(bn, "ev3_drill_head") != -1) return "ev3_drill_head";
        if (strsrch(bn, "ev3_mother_liquid_vial") != -1) return "ev3_mother_liquid_vial";
        if (strsrch(bn, "ev3_private_purchase_ledger") != -1) return "ev3_private_purchase_ledger";
        if (strsrch(bn, "ev3_expedition_roster") != -1) return "ev3_expedition_roster";
        if (strsrch(bn, "ev3_yanshan_blood_note") != -1) return "ev3_yanshan_blood_note";
        if (strsrch(bn, "ev3_heart_guard_mirror") != -1) return "ev3_heart_guard_mirror";
        if (ev_ob->query("evidence_id")) return ev_ob->query("evidence_id");
    }
    if (id == "detonator" || id == "雷管批號" || id == "簽領簿") return "detonator_serial_ledger";
    if (id == "clay" || id == "耐火泥") return "liefan_clay_batch";
    if (id == "poison" || id == "毒囊" || id == "毒樣") return "relay_poison_sample";
    if (id == "thumbprints" || id == "血手印" || id == "供狀") return "miner_thumbprints";
    if (id == "deed" || id == "底單" || id == "舊商盟底單") return "under_canal_deed";
    if (id == "crucible" || id == "坩堝") return "crucible_bing_7";
    return id;
}

// 觸發物證污染（例如攜帶未封存紙本底單或毒樣涉過暗渠污水或遭暴雨浸泡）
mapping contaminate_evidence(object ev_ob, string reason) {
    if (!ev_ob) return ([ "contaminated": 0, "msg": "無效物證" ]);
    if (ev_ob->query("sealed_custody")) {
        return ([
            "contaminated": 0,
            "msg": sprintf("【封存完好】%s 已由火漆或封靈玉瓶嚴密封存，未受「%s」污染。", ev_ob->query_short(), reason ? reason : "外在環境")
        ]);
    }
    ev_ob->set("contaminated", 1);
    ev_ob->set("contamination_reason", reason ? reason : "保管不當受潮污損");
    return ([
        "contaminated": 1,
        "reason": ev_ob->query("contamination_reason"),
        "msg": sprintf(HIR "【物證污染警告】%s 因「%s」導致墨跡暈染或樣本受污，保管鏈出現瑕疵！須找案牘主簿文承敬或醫館白先生重新鑑定封存。" NOR,
                       ev_ob->query_short(), ev_ob->query("contamination_reason"))
    ]);
}

// 由權威公證人（文承敬 / 白先生 / 歐陽大師）修復或封存認證物證
mapping certify_or_cleanse_evidence(object me, object ev_ob, object certifier) {
    if (!ev_ob) return ([ "certified": 0, "msg": "無效物證" ]);
    string cname = certifier ? certifier->query_name() : "公證官";
    int was_contaminated = ev_ob->query("contaminated");
    ev_ob->set("contaminated", 0);
    ev_ob->set("sealed_custody", 1);
    ev_ob->set("certified", 1);
    ev_ob->set("certified_by", cname);

    string ev_id = normalize_evidence_id(ev_ob, "");
    object em = load_object(EVENT_MANAGER_D);
    if (em && ev_id != "") {
        em->register_evidence(ev_id, ([
            "name": ev_ob->query_short(),
            "strength": 2,
            "source_type": "certified_physical",
            "verified": 1
        ]));
    }

    return ([
        "certified": 1,
        "cleansed": was_contaminated ? 1 : 0,
        "msg": sprintf(HIG "【公證封存完畢】%s 仔細比對底檔印鑑與殘留理化特徵，為 %s 重新加蓋火漆封條與核驗印記（保管鏈完整，已具呈堂效力）！" NOR,
                       cname, ev_ob->query_short())
    ]);
}

// 評估玩家已出示物證集合的「互相印證（Mutual Corroboration）」協同效應
mapping evaluate_corroboration_synergy(string *presented_ids) {
    if (!presented_ids) presented_ids = ({});
    int has_detonator = (member_array("detonator_serial_ledger", presented_ids) != -1);
    int has_clay      = (member_array("liefan_clay_batch", presented_ids) != -1);
    int has_crucible  = (member_array("crucible_bing_7", presented_ids) != -1);
    int has_miners    = (member_array("miner_thumbprints", presented_ids) != -1);
    int has_deed      = (member_array("under_canal_deed", presented_ids) != -1);
    int has_poison    = (member_array("relay_poison_sample", presented_ids) != -1);
    int has_custody   = (member_array("custody_ledger", presented_ids) != -1);
    int has_v3_tech   = (member_array("ev3_drill_head", presented_ids) != -1 || member_array("ev3_mother_liquid_vial", presented_ids) != -1);
    int has_v3_priv   = (member_array("ev3_private_purchase_ledger", presented_ids) != -1);
    int has_v3_roster = (member_array("ev3_expedition_roster", presented_ids) != -1);
    int has_v3_blood  = (member_array("ev3_yanshan_blood_note", presented_ids) != -1 || member_array("ev3_heart_guard_mirror", presented_ids) != -1);

    string *synergies = ({});
    int bonus_weight = 0;

    // 1. 礦難蓄意爆破與私煉鐵證鏈（雷管批號 + 坩堝/耐火泥 + 倖存礦工血手印）
    if (has_detonator && (has_clay || has_crucible) && has_miners) {
        synergies += ({ "mine_sabotage_triad" });
        bonus_weight += 3;
    }
    // 2. 雙帳咬合與三十年前產權黑幕（暗渠舊商盟底單 + 保管鏈/耐火泥稅單）
    if (has_deed && (has_custody || has_clay)) {
        synergies += ({ "double_ledger_match" });
        bonus_weight += 2;
    }
    // 3. 物流投毒滅口鏈（驛站毒樣 + 暗渠底單/礦工供狀）
    if (has_poison && (has_deed || has_miners)) {
        synergies += ({ "poison_silencing_chain" });
        bonus_weight += 2;
    }
    // 4. 第三卷北荒母脈盜掘與秘密採辦互證鏈（鑽頭/母液 + 私下採辦帳冊）
    if (has_v3_tech && has_v3_priv) {
        synergies += ({ "v3_tiangong_sabotage_chain" });
        bonus_weight += 3;
    }
    // 5. 第三卷戰祖古墓血書與失蹤名冊互證鏈（名冊 + 燕山血書/護心鏡）
    if (has_v3_roster && has_v3_blood) {
        synergies += ({ "v3_expedition_truth" });
        bonus_weight += 3;
    }

    string tier = "isolated_lead";
    string summary = "【孤證難鳴】目前僅出示單一面向物證，涉案勢力極易推脫為「下屬盜印」或「意外巧合」，尚不足以令三方會審拍板定案。";
    if (sizeof(synergies) >= 2 || bonus_weight >= 4) {
        tier = "ironclad_chain";
        summary = HIY "【雙帳咬合・鐵證如山】多源獨立物證互相印證閉合！軍需出庫、百工坩堝、暗渠底單與活人血手印環環相扣，徹底封死錢百川一切卸責退路！" NOR;
    } else if (sizeof(synergies) == 1 || sizeof(presented_ids) >= 2) {
        tier = "corroborated";
        summary = HIG "【交叉印證・信任質變】物證之間已形成跨部門互鎖（軍需／百工／人證互相咬合），主審官員的態度由謹慎觀望轉為正式採信！" NOR;
    }

    return ([
        "tier": tier,
        "synergies": synergies,
        "bonus_weight": bonus_weight,
        "count": sizeof(presented_ids),
        "summary": summary
    ]);
}

// 玩家主動向 NPC 出示物證 (present <item> to <npc>)，根據 NPC 立場與印證狀態返回差異化反應
mapping present_evidence_to_npc(object me, object ev_ob, object npc) {
    if (!me || !ev_ob || !npc) return ([ "handled": 0, "msg": "出示對象無效。" ]);

    string ev_id = normalize_evidence_id(ev_ob, ev_ob->query_key_id());
    string npc_path = base_name(npc);
    string npc_name = npc->query_name();

    // 0. 檢查是否為蓄意偽造之物證（偽造風險與反噬）
    if (ev_ob->query("is_forged")) {
        me->add("reputation_penalty", 10);
        me->set_temp("last_forgery_caught", ev_id);
        return ([
            "handled": 1,
            "status": "rejected_forged",
            "ev_id": ev_id,
            "msg": sprintf(HIR "【偽證反噬！】%s 只看了一眼 %s 的火印與筆跡，便冷笑拍案：「騎縫章墨色浮躁、紙質年份對不上——這是偽造的假證！你想誣告還是蓄意攪局？！」（聲望受損，已紀錄在案）" NOR,
                           npc_name, ev_ob->query_short())
        ]);
    }

    // 1. 檢查物證是否受污染
    if (ev_ob->query("contaminated")) {
        // 若出示給文承敬或白先生，直接觸發公證修復與重新封存！
        if (strsrch(npc_path, "wenchengjing") != -1 || strsrch(npc_path, "doctor_bai") != -1 ||
            strsrch(npc_name, "文承敬") != -1 || strsrch(npc_name, "白先生") != -1) {
            mapping clean_res = certify_or_cleanse_evidence(me, ev_ob, npc);
            return ([
                "handled": 1,
                "status": "cleansed_and_certified",
                "ev_id": ev_id,
                "msg": sprintf(CYN "%s 接過受污的 %s，眉頭微蹙：「保管鏈怎可如此疏忽！幸好底紋火印與殘留藥理尚存，老夫這便為你重新比對封存。」\n" NOR "%s",
                               npc_name, ev_ob->query_short(), clean_res["msg"])
            ]);
        }
        return ([
            "handled": 1,
            "status": "rejected_contaminated",
            "ev_id": ev_id,
            "msg": sprintf(HIR "%s 瞥了一眼 %s，搖頭沉聲道：「此物墨跡暈染、封條破損（%s），在公堂上必被錢百川反咬為偽造！快去請案牘庫文主簿或杏林白先生重新核驗封存！」" NOR,
                           npc_name, ev_ob->query_short(), ev_ob->query("contamination_reason") ? ev_ob->query("contamination_reason") : "保管鏈瑕疵")
        ]);
    }

    // 2. 記錄已向該 NPC / 全域出示的物證清單
    string *presented = me->query_temp("presented_evidence_list");
    if (!arrayp(presented)) presented = ({});
    if (ev_id != "" && member_array(ev_id, presented) == -1) {
        presented += ({ ev_id });
        me->set_temp("presented_evidence_list", presented);
    }

    mapping syn = evaluate_corroboration_synergy(presented);

    // 同步登錄至 EVENT_MANAGER_D
    object em = load_object(EVENT_MANAGER_D);
    string actor_role = "observer";
    if (strsrch(npc_path, "yamen_magistrate") != -1 || strsrch(npc_name, "秦正明") != -1) actor_role = "judge";
    else if (strsrch(npc_path, "wenchengjing") != -1 || strsrch(npc_name, "文承敬") != -1) actor_role = "inspector";
    else if (strsrch(npc_path, "chen_zhenshan") != -1 || strsrch(npc_path, "wu_bashan") != -1 || strsrch(npc_name, "陳鎮山") != -1 || strsrch(npc_name, "霸山") != -1) actor_role = "commander";

    if (em && ev_id != "") {
        mapping reg_def = EVIDENCE_REGISTRY[ev_id];
        em->register_evidence(ev_id, ([
            "name": reg_def ? reg_def["name"] : ev_ob->query_short(),
            "strength": (syn["tier"] == "ironclad_chain" ? 3 : 2),
            "source_type": reg_def ? reg_def["tribunal_domain"] : "general"
        ]));
        em->mark_evidence_seen(ev_id, actor_role);
    }

    // 3. 依據 NPC 立場與單證/互證狀態生成小說化反應
    string reaction = "";
    if (strsrch(npc_name, "秦正明") != -1 || strsrch(npc_path, "yamen_magistrate") != -1) {
        if (syn["tier"] == "isolated_lead") {
            reaction = sprintf(CYN "府尹秦正明凝視著 %s，手指輕敲驚堂木，沉吟道：「此物確有疑點，但單憑這一件孤證，商會隨時能推給下面管事頂罪。你若能再找來百工坩堝暗帳與活人血手印互相印證，本府才能動用荒政律拿人！」" NOR, ev_ob->query_short());
        } else {
            reaction = sprintf(HIY "府尹秦正明猛然拍案而起，目光如電掃過 %s 與前番呈堂諸證：「好！軍需雷管、百工耐火泥、暗渠雙帳與礦工血手印環環咬死！來人，備府衙大印，即刻召開三方會審！」" NOR, ev_ob->query_short());
        }
    } else if (strsrch(npc_name, "文承敬") != -1 || strsrch(npc_path, "wenchengjing") != -1) {
        ev_ob->set("certified", 1);
        ev_ob->set("sealed_custody", 1);
        reaction = sprintf(HIG "案牘主簿文承敬推了推花鏡，取出三十年前底冊與 %s 逐字比對，指尖微微發顫：「字跡、火印、騎縫章分毫不差！老夫這便加蓋案牘庫公證火漆，為你鎖死這條保管鏈！」" NOR, ev_ob->query_short());
    } else if (strsrch(npc_name, "莫錘") != -1 || strsrch(npc_name, "歐陽") != -1 || strsrch(npc_path, "gong_") != -1) {
        reaction = sprintf(HIR "%s 接過 %s，粗大的指節捏得咯咯作響，怒喝道：「丙字柒號特規坩堝與烈礬耐火泥竟被拿去私煉地煞血精！這群敗類辱沒百工祖師，百工總會這一票，投定了！」" NOR, npc_name, ev_ob->query_short());
    } else if (strsrch(npc_name, "陳鎮山") != -1 || strsrch(npc_name, "霸山") != -1 || strsrch(npc_name, "雷震") != -1) {
        if (syn["tier"] == "isolated_lead") {
            reaction = sprintf(YEL "%s 盯著 %s 冷哼一聲：「軍鎮虎符豈能因一紙孤證輕動？把百工出庫火印或生還礦工供狀一併拿來，本將絕不護短！」" NOR, npc_name, ev_ob->query_short());
        } else {
            reaction = sprintf(HIR "%s 虎目圓睜，一掌按在刀柄上：「竟敢盜用邊軍雷管炸塌民礦、截留軍餉！多證互鎖之下鐵證如山，鎮武軍鎮願出虎符與府衙合符拿人！」" NOR, npc_name);
        }
    } else if (strsrch(npc_name, "錢百川") != -1 || strsrch(npc_name, "錢不換") != -1) {
        if (syn["tier"] == "isolated_lead") {
            reaction = sprintf(WHT "%s 眼皮都沒抬，冷笑道：「就憑這點捕風捉影的破紙片也想攀咬金石商會？不過是底下帳房手腳不乾淨罷了，你能奈我何？」" NOR, npc_name);
        } else {
            reaction = sprintf(HIR "%s 看見 %s 與雙帳鐵證並陳，臉色瞬間煞白，額角青筋暴跳，退後半步厲聲道：「你們……你們竟從暗渠死水裡把三十年前的底單翻出來了？！」" NOR, npc_name, ev_ob->query_short());
        }
    } else {
        reaction = sprintf(CYN "%s 仔細端詳著你出示的 %s，神色微變：「原來坊間傳聞竟是真的……這件物證可要收好，千萬別落入商會暗探手裡！」" NOR, npc_name, ev_ob->query_short());
    }

    return ([
        "handled": 1,
        "status": syn["tier"],
        "ev_id": ev_id,
        "corroboration": syn,
        "msg": reaction + "\n" + syn["summary"]
    ]);
}

// ── 13. 嚴格區分「會做（Skill）」與「有資格做（Social Qualification / Residency）」 ──
mapping check_qualification_vs_skill(object me, string domain, string action_name) {
    if (!me) return ([ "allowed": 0, "reason": "invalid_user" ]);
    if (!action_name || action_name == "") action_name = "公開執業";

    // 1. 先檢查三日通牒居留狀態
    mapping res = check_user_residency(me);
    if (res["status"] == "unregistered_vagrant" || res["status"] == "buffer_expired") {
        return ([
            "allowed": 0,
            "reason": "unregistered_residency",
            "msg": sprintf(HIR "【會做 ≠ 有資格做：無籍流民禁令】你雖具備相關技藝，但目前在金石府屬「無籍流民」（三日通牒逾期未立籍），府衙巡防隊嚴禁無籍者在城內公開進行「%s」！" NOR, action_name)
        ]);
    }

    mapping quals = me->query_qualifications();
    if (!mapp(quals)) quals = ([]);

    string req_lic = "";
    string req_title = "";
    string guild_authority = "";

    if (domain == "medical" || domain == "clinic" || domain == "醫道") {
        req_lic = "lic_apothecary";
        req_title = "杏林坐堂醫士資格";
        guild_authority = "杏林醫館與百草堂";
    } else if (domain == "forge" || domain == "craft" || domain == "百工") {
        req_lic = "lic_artisan";
        req_title = "百工正式匠籍";
        guild_authority = "府城百工總會";
    } else if (domain == "escort" || domain == "martial" || domain == "武館") {
        req_lic = "lic_escort_guard";
        req_title = "外門黑鐵腰牌／護院武籍";
        guild_authority = "八方武館與城防司";
    } else if (domain == "diviner" || domain == "dao" || domain == "法道") {
        req_lic = "lic_diviner";
        req_title = "宣道司大乾度牒";
        guild_authority = "金石府宣道司";
    } else if (domain == "commerce" || domain == "broker" || domain == "行商") {
        req_lic = "lic_broker";
        req_title = "通寶牙行經紀印牌";
        guild_authority = "金石商會與通寶牙行";
    }

    int has_qual = 0;
    if (req_lic != "") {
        if (quals[req_lic] || present(req_lic, me) || me->query("qualification/" + req_lic)) {
            has_qual = 1;
        }
    } else {
        has_qual = 1;
    }

    if (!has_qual) {
        return ([
            "allowed": 0,
            "reason": "missing_qualification",
            "required_license": req_lic,
            "msg": sprintf(YEL "【手藝與法統之別】你的技藝造詣或許足以勝任「%s」，但在金石府城，「會做」不等於「有資格做」！\n"
                               "未持【%s (%s)】而私自公開執業，將遭 %s 與府衙巡檢聯手取締。請先完成立籍與行會考核。" NOR,
                           action_name, req_title, req_lic, guild_authority)
        ]);
    }

    return ([
        "allowed": 1,
        "reason": "qualified",
        "required_license": req_lic,
        "msg": sprintf(HIG "【行會資格核驗通過】你出示【%s】，合法在金石府執行「%s」。" NOR, req_title, action_name)
    ]);
}

// ── 14. Phase 2B：社會階層四維度結構模型（身分 × 生計 × 資源 × 流動） ──
mapping query_social_tier(object who) {
    if (!who) {
        return ([ "tier_id": "invalid", "tier_name": "未知身分" ]);
    }

    mapping res = check_residency_mandate(who, 0);
    if (userp(who)) {
        res = check_user_residency(who);
    }

    string status = mapp(res) ? res["status"] : "initial_72h_window";
    string my_class = who->query("class");
    string guild = who->query("guild");
    mapping quals = who->query_qualifications();
    int has_qual = (mapp(quals) && sizeof(keys(quals)) > 0) ? 1 : 0;
    int has_temp_pass = (present("temp residency pass", who) || status == "outer_temp_pass") ? 1 : 0;
    int has_buffer = (status == "buffered_temporary") ? 1 : 0;

    string tier_id = "unregistered_vagrant";
    string tier_name = "無籍流民／底層散工";
    string identity_desc = "未持路引、保書與行會籍冊，夜間受宵禁盤查，僅能滯留南關外土坯棚區。";
    string livelihood_desc = "僅能於關外碼頭、流民矮巷與冰河棧道接黑工或按件領取竹籌，嚴禁進入內城大坊正式受僱。";
    string housing_desc = "僅能宿於【南關外・流民賃居矮巷】土坯通鋪（2文），內城中心客棧拒絕無憑據散客立約投宿。";
    string medical_desc = "限於【南關外・施藥義棚】領取免費甘草粗湯，難負擔內城杏林醫館高昂診金與靈材方劑。";
    string mobility_desc = "先於南關外申請《暫住牌》，或赴學塾（青衿）、醫館（試藥藥囊）、車馬大院（短褐腰牌）取得保書；再透過考牒、工會作保或跨縣等價認證取得正式匠／醫／武／道籍。";

    int inner_work = 0;
    int inner_inn = 0;
    int inn_cost = 50;
    int clinic_discount = 0;

    if (has_qual || (my_class && my_class != "" && my_class != "mortal")) {
        tier_id = "formal_guild";
        tier_name = "在籍門人／行會正職";
        identity_desc = "已取得金石府正式匠籍、醫士資格、軍武腰牌或宗門／宣道度牒。";
        livelihood_desc = "可合法於內城百工工坊、杏林醫館或四大宗門執業掛單，支領正規俸祿與行會份例。";
        housing_desc = "可自由投宿【金石大客棧】雅間（50文），無懼夜間宵禁巡防。";
        medical_desc = "享有杏林醫館正式掛號優先權與丹鼎藥爐合方資格。";
        mobility_desc = "可跨城出使雲津、北荒或以公證人／保人身分引薦新進子弟立籍。";
        inner_work = 1;
        inner_inn = 1;
        clinic_discount = 1;
    } else if (guild && guild != "") {
        tier_id = "sect_outer";
        tier_name = "宗門／組織外門名籍";
        identity_desc = sprintf("已錄入【%s】外門名籍，具備基本組織庇護與出入識別。", guild);
        livelihood_desc = "可在宗門或分舵接領外門差事、採藥護隊與軍鎮操練，亦可兼接城南商隊護衛。";
        housing_desc = "可借住宗門外院通鋪或城內外合規客棧。";
        medical_desc = "內外城醫館皆可看診，然高階丹藥仍須另行核算貢獻。";
        mobility_desc = "累積門內貢獻升任內門，或兼考百工／杏林／武館執業資格。";
        inner_work = 1;
        inner_inn = 1;
        inn_cost = 35;
    } else if (has_buffer) {
        tier_id = "buffered_sojourner";
        tier_name = "持保書暫居客（青衿／試藥／趟子手）";
        identity_desc = "憑學塾青衿、醫館試藥藥囊或車馬院腰牌取得臨時居留寬限，暫免流民驅逐。";
        livelihood_desc = "可在擔保機構轄下打雜學藝並承接行商短活，尚待正式考牒方能獨立掛牌。";
        housing_desc = "可投宿城內外客棧（50文），亦可至南關外省錢落腳。";
        medical_desc = "可憑保條進入杏林醫館候診（50文），重病急症時亦不至被拒諸門外。";
        mobility_desc = "把握寬限期完成學塾考牒、百工入行、杏林坐堂或武館腰牌正式評定。";
        inner_work = 0;
        inner_inn = 1;
    } else if (status == "initial_72h_window" || has_temp_pass) {
        tier_id = "outer_sojourner";
        tier_name = has_temp_pass ? "持《暫住牌》外城短工" : "新入關待籍行旅（72時辰內）";
        identity_desc = has_temp_pass
            ? "持有《金石南關暫住牌》，外城去向有案可查，可免夜間當街抓捕。"
            : "甫抵金石界尚未滿三日通牒，須儘快覓得保人或領取暫住牌。";
        livelihood_desc = "限於南關車馬、外城碼頭與魚市扛貨記竹籌掙取銅錢，無法簽訂內城大坊正契。";
        housing_desc = "建議先歇於南關外矮巷通鋪或南關車馬小棧（2～5文）節省盤纏。";
        medical_desc = "多赴【南關外・施藥義棚】免費取粗湯調養，內城中心醫館診費高昂。";
        mobility_desc = "先向南關小棧／流民巷探詢保人，取得學塾、醫館或車馬院三條緩衝保書之一。";
        inner_work = 0;
        inner_inn = 0;
    }

    return ([
        "tier_id": tier_id,
        "tier_name": tier_name,
        "residency_status": status,
        "identity": identity_desc,
        "livelihood": livelihood_desc,
        "resources": ([
            "housing": housing_desc,
            "medical": medical_desc,
            "inner_inn_allowed": inner_inn,
            "inner_inn_cost": inn_cost,
            "clinic_discount": clinic_discount
        ]),
        "mobility": mobility_desc,
        "can_work_inner_guild": inner_work
    ]);
}
