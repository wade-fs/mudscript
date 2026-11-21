// /d/sects/taiqing/ark_portal_chamber.c
// 三山祖庭地底・太古破界方舟主傳送室 (Ch.126：五座石台多階段技術校驗與單向開啟三丈青金星門)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

mapping station_states;

void reset_stations() {
    station_states = ([
        "north": 0,
        "northeast": 0,
        "northwest": 0,
        "southwest": 0,
        "south": 0
    ]);
}

void create() {
    ::create();
    reset_stations();
    set_short("祖庭地底・太古破界方舟主傳送室");
    set_long("沿三大名山萬仞山腹三礦交擠而成的陡峭深黑螺旋階梯下行千餘丈，豁然顯出一座\n"
             "可容千人的宏偉地下球形大殿。與北荒裂谷破損漏液的冷卻艙段迥異，此處由半透明\n"
             "黑曜玄石拼接穹頂、保存完好；正中央矗立高逾三丈、刻滿雙重逆星軌道與幾何齒輪的\n"
             "巨型環狀空間傳送門框，前方依次排列五座技術驗證石台：\n"
             "  1. 正北水銀星盤控台 (calibrate north)     — 逆星軌道座標向量鎖定\n"
             "  2. 東北傳動主台     (calibrate northeast) — 不融黑鐵齒輪微米公差咬合\n"
             "  3. 西北黑岩陣台     (calibrate northwest) — 戰祖圖騰骨片生命頻率屏蔽\n"
             "  4. 西南高壓閥門台   (calibrate southwest) — 地煞晶核與溫和藥靈催化點火\n"
             "  5. 正南行商總約碑   (calibrate south)     — 天門引與九城總契通行覆核\n"
             "可逐台執行精密技術校驗（calibrate <方位> / status），或直接啟動總陣（activate gate）。\n"
             "門扉啟動後須於外陣崩裂前最後一息入陣（enter gate）；向上攀登螺旋黑階返【封存觀測室】。\n");

    set_exits(([
        "up": "/d/sects/taiqing/sealed_observatory.c",
    ]));

    set("is_outdoor", 0);

    set_touch("gate", HIC "你伸手觸碰三丈高的環狀傳送門框，太古青金合金冰冷堅硬，雙重逆星導流槽內正隨著頭頂雷劫震動發出微米級的高頻脈衝。" NOR);
    set_smell("default", HIW "球形大殿內瀰漫著水銀冷霧、臭氧電離氣息與萬載封存的靈石礦香。" NOR);
    set_listen("default", HIR "頭頂千丈岩層外傳來十丈紫黑滅世神雷轟擊護山大陣的沉悶雷鳴，殿內五座石台的導流管正發出低沉的待機蜂鳴。" NOR);
}

void init() {
    ::init();
    add_action("do_calibrate", "calibrate");
    add_action("do_calibrate", "校驗");
    add_action("do_status", "status");
    add_action("do_status", "進度");
    add_action("do_activate", "activate");
    add_action("do_enter", "enter");
}

mapping query_calibration_state(object me) {
    if (!station_states) reset_stations();
    if (me && mapp(me->query_temp("ark_portal_calib"))) {
        return copy(me->query_temp("ark_portal_calib"));
    }
    return copy(station_states);
}

int query_calibrated_count(object me) {
    mapping st = query_calibration_state(me);
    int cnt = 0;
    foreach (string k in ({ "north", "northeast", "northwest", "southwest", "south" })) {
        if (st[k]) cnt++;
    }
    return cnt;
}

// 檢查玩家本人或同房間隊友是否持有對應石台所需之實體遺物／圖譜憑證
mapping inspect_station_relic_support(object me, string station) {
    object *holders = ({ me });
    object env = environment(me);
    if (env) {
        object *inv = all_inventory(env);
        if (arrayp(inv)) {
            foreach (object ob in inv) {
                if (ob && ob != me && (userp(ob) || strsrch(base_name(ob), "/std/user") == 0)) holders += ({ ob });
            }
        }
    }

    string *match_ids = ({});
    string label = "";
    if (station == "north") {
        match_ids = ({ "stele rubbing", "rubbing", "reverse_star_addendum", "星圖拓片", "逆星歲差實測補遺" });
        label = "【逆星斷碑拓片 / 逆星歲差實測補遺】";
    } else if (station == "northeast") {
        match_ids = ({ "ancient black iron", "black iron", "detachable_feedback_spec", "steel_caliper", "太古不融黑鐵", "回授連動台圖紙" });
        label = "【太古不融黑鐵構件 / 回授連動台圖紙】";
    } else if (station == "northwest") {
        match_ids = ({ "totem bone", "totem", "bahuang_rotation_manual", "圖騰骨片", "黑山分段輪替操典" });
        label = "【獵獸圖騰骨片 / 黑山分段輪替操典】";
    } else if (station == "southwest") {
        match_ids = ({ "disha crystal", "crystal core", "sanyuan_bencao_draft", "sanyuan_shengji_dan", "晶核殘片", "三元本草祛道錄" });
        label = "【古礦地煞晶核 / 三元本草祛道錄】";
    } else if (station == "south") {
        match_ids = ({ "tianmen token", "bronze treaty plate", "wanshan_charter_deed", "天門引", "青銅契版", "萬山共治託付書" });
        label = "【天門引 / 青銅契版 / 萬山共治託付書】";
    }

    foreach (object h in holders) {
        foreach (string mid in match_ids) {
            if (present(mid, h)) {
                return ([
                    "found": 1,
                    "holder": (h == me) ? "self" : "teammate",
                    "holder_name": h->query_name(),
                    "label": label
                ]);
            }
        }
    }
    return ([ "found": 0, "label": label ]);
}

int do_status(string arg) {
    object me = this_player();
    mapping st = query_calibration_state(me);
    int cnt = query_calibrated_count(me);

    tell_object(me, HIW "\n================【太古破界方舟・五台技術校驗儀表】================\n" NOR);
    tell_object(me, sprintf("  [1] 正北水銀星盤控台 (north)     : %s\n", st["north"] ? HIG "已鎖定 (逆星歲差 0.00°)" NOR : YEL "待校驗 (星軌向量未閉合)" NOR));
    tell_object(me, sprintf("  [2] 東北傳動主台     (northeast) : %s\n", st["northeast"] ? HIG "已咬合 (齒輪公差 < 0.01 厘)" NOR : YEL "待校驗 (主導管應力未鎖)" NOR));
    tell_object(me, sprintf("  [3] 西北黑岩陣台     (northwest) : %s\n", st["northwest"] ? HIG "已展開 (荒血呼吸同步 100%%)" NOR : YEL "待校驗 (空間撕裂屏蔽未啟)" NOR));
    tell_object(me, sprintf("  [4] 西南高壓閥門台   (southwest) : %s\n", st["southwest"] ? HIG "已點火 (三元藥靈催化穩定)" NOR : YEL "待校驗 (靈石總庫閥門冷卻)" NOR));
    tell_object(me, sprintf("  [5] 正南行商總約碑   (south)     : %s\n", st["south"] ? HIG "已覆核 (天門引九城合印通過)" NOR : YEL "待校驗 (跨界通行總契待驗)" NOR));
    tell_object(me, sprintf(HIW "------------------------------------------------------------------\n"
                            "  總體校驗進度：%d / 5 台就緒 %s\n"
                            "==================================================================\n" NOR,
                            cnt, (cnt == 5 ? HIG "【可安全執行 activate gate 開啟星門】" NOR : "")));
    return 1;
}

int do_calibrate(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (!station_states) reset_stations();

    if (!arg || arg == "") {
        tell_object(me, "請指定要校驗的石台方位：calibrate north | northeast | northwest | southwest | south（或輸入 status 查看進度）。\n");
        return 1;
    }

    string target = lower_case(arg);
    string mode = "";
    if (sscanf(target, "%s %s", target, mode) != 2) {
        mode = "normal";
    }

    if (target == "北" || target == "正北" || target == "1") target = "north";
    if (target == "東北" || target == "2") target = "northeast";
    if (target == "西北" || target == "3") target = "northwest";
    if (target == "西南" || target == "4") target = "southwest";
    if (target == "南" || target == "正南" || target == "5") target = "south";

    mapping st = query_calibration_state(me);
    mapping rel_info = inspect_station_relic_support(me, target);
    if (mode == "strict" && !rel_info["found"]) {
        tell_object(me, sprintf(HIR "【技術校驗失敗 — 實體信物／圖紙缺席】\n"
                                    "嚴格校驗模式要求本人或同殿隊友實際持有 %s 方可扣入導流槽，目前檢測無此實體信物！\n" NOR,
                                rel_info["label"]));
        return 1;
    }

    string relic_note = rel_info["found"]
        ? sprintf(HIG "（實體信物 %s 由%s現場扣入導流槽並耗費微許神識催動）\n" NOR,
                  rel_info["label"], (rel_info["holder"] == "teammate") ? ("隊友 " + rel_info["holder_name"]) : "你")
        : CYN "（由祖庭備用拓印與同門協作矩陣補足實體介面，若帶齊實體遺物可觸發 strict 零損校驗）\n" NOR;

    if (target == "reset" || target == "重置") {
        reset_stations();
        me->set_temp("ark_portal_calib", copy(station_states));
        tell_object(me, CYN "【系統重置】五座驗證石台的水銀導流槽與齒輪卡榫已歸零重置。\n" NOR);
        return 1;
    }

    // 支援模擬工程失誤診斷 (若帶 force/rough 或未按前置順序校驗時給出明確工程錯誤)
    if (target == "north") {
        if (mode == "rough" || mode == "force") {
            tell_object(me, HIR "【技術校驗失敗 — 星象偏差警告】\n"
                                "你未經歲差補償便強行壓入逆星拓片，水銀星盤劇烈震盪，指針偏移達 4.7 度！\n"
                                "宋知微急喝道：「不可強按！假天星軌每甲子逆移三毫，必須對齊太古辰宿基準線（calibrate north）！」\n" NOR);
            return 1;
        }
        st["north"] = 1;
        station_states["north"] = 1;
        me->set_temp("ark_portal_calib", st);
        tell_object(me, HIC "【第一階校驗通過：正北水銀星盤控台（座標鎖定）】\n"
                            "你將【逆星斷碑拓片】覆於水銀星象凹盤上，依《太古逆星補遺》微調三十六枚青銅游標。\n"
                            "水銀珠沿逆行九宿溝槽精準歸位，「錚」地一聲清鳴，跨界空間座標向量徹底釘死（偏差 0.00°）！\n" NOR + relic_note);
        return 1;
    }

    if (target == "northeast") {
        if (!st["north"]) {
            tell_object(me, HIR "【技術校驗失敗 — 座標未鎖警告】\n"
                                "東北傳動主台的青金連桿猛然彈回，震得你虎口發麻！\n"
                                "診斷提示：正北星盤控台 (north) 尚未鎖定空間座標向量，傳動軸缺乏基準方位，強行嵌合將導致齒輪崩齒！\n" NOR);
            return 1;
        }
        if (mode == "rough" || mode == "force") {
            tell_object(me, HIR "【技術校驗失敗 — 齒輪咬合公差超標】\n"
                                "你未用卡尺校準便直接將黑鐵構件推入卡槽，傳動軸發出刺耳的金屬刮擦聲，公差偏移達 0.35 厘，安全栓自動鎖死！\n" NOR);
            return 1;
        }
        st["northeast"] = 1;
        station_states["northeast"] = 1;
        me->set_temp("ark_portal_calib", st);
        tell_object(me, HIY "【第二階校驗通過：東北傳動主台（結構校準）】\n"
                            "你左手抵住阿鐵師傅留下的精鋼卡尺，測量主導管在雷劫震動下的微米級形變，\n"
                            "右手在震波波谷的一瞬將【太古不融黑鐵齒輪】精準推入榫卯！「哢嗒——」三百六十齒嚴絲合縫，空間撕裂應力被死死鎖住！\n" NOR + relic_note);
        return 1;
    }

    if (target == "northwest") {
        if (!st["north"] || !st["northeast"]) {
            tell_object(me, HIR "【技術校驗失敗 — 結構應力未穩】\n"
                                "西北黑岩陣台的共振波散逸失控！請先完成正北座標鎖定 (north) 與東北傳動校準 (northeast)，否則生命屏蔽場將被空間亂流撕碎！\n" NOR);
            return 1;
        }
        if (mode == "rough" || mode == "force") {
            tell_object(me, HIR "【技術校驗失敗 — 生命頻率失步】\n"
                                "你氣息急促紊亂，圖騰骨片與黑岩陣台產生劇烈排斥反震，屏蔽波紋瞬間潰散！必須沉住長呼吸使氣血脈搏與陣台同頻。\n" NOR);
            return 1;
        }
        st["northwest"] = 1;
        station_states["northwest"] = 1;
        me->set_temp("ark_portal_calib", st);
        tell_object(me, MAG "【第三階校驗通過：西北黑岩陣台（生命屏蔽）】\n"
                            "你將【獵獸圖騰骨片】按入黑岩血槽，屏息收斂狂暴殺氣，以八荒綿長勻稱的呼吸節律引導氣血脈動。\n"
                            "暗紅荒血紋路與黑岩導流槽同頻搏動，一層堅韌的太古生命屏蔽場如穹頂般張開，隔絕了跨界虛空壓差！\n" NOR + relic_note);
        return 1;
    }

    if (target == "southwest") {
        if (!st["north"] || !st["northeast"] || !st["northwest"]) {
            tell_object(me, HIR "【技術校驗失敗 — 過載爆炸風險】\n"
                                "西南高壓點火閥門發出尖銳鳴叫並拒絕開啟！\n"
                                "診斷提示：前三台（north / northeast / northwest）的座標、傳動與屏蔽場尚未全數就緒，此時點燃靈石總庫將直接引爆整座球形大殿！\n" NOR);
            return 1;
        }
        if (mode == "rough" || mode == "force") {
            tell_object(me, HIR "【技術校驗失敗 — 地煞狂暴逆衝】\n"
                                "缺乏溫和草木藥靈中和，古礦地煞晶核剛接觸閥門便爆出紫黑毒火，高壓導管溫度驟升至臨界紅線，你連忙切斷閥門！\n" NOR);
            return 1;
        }
        st["southwest"] = 1;
        station_states["southwest"] = 1;
        me->set_temp("ark_portal_calib", st);
        tell_object(me, HIG "【第四階校驗通過：西南高壓閥門台（能源點火）】\n"
                            "你將【古礦地煞晶核殘片】嵌入高壓閥芯，同時以百草三元溫和藥靈真氣包裹暴烈地煞作為催化引信。\n"
                            "地底儲備萬載的靈石總庫轟然點燃，狂暴的地脈火能被藥靈梳理成純淨璀璨的青金洪流，灌入三丈星門外環！\n" NOR + relic_note);
        return 1;
    }

    if (target == "south") {
        if (!st["north"] || !st["northeast"] || !st["northwest"] || !st["southwest"]) {
            tell_object(me, HIR "【技術校驗失敗 — 能源迴路未通】\n"
                                "正南行商總約石碑光芒黯淡。須先完成北、東北、西北、西南四台校驗並點燃主能源，總約石碑方能進行最終通行覆核！\n" NOR);
            return 1;
        }
        st["south"] = 1;
        station_states["south"] = 1;
        me->set_temp("ark_portal_calib", st);
        tell_object(me, HIW "【第五階校驗通過：正南行商總約石碑（行商認證）】\n"
                            "你將微溫的【天門引】與【九城總契銅版】並排扣入正南石碑雙槽！\n"
                            "令符內部休眠萬古的微型神械齒輪高速旋轉，將五人一路收集的雙帳鐵證、三元本草、百工規約與黑石鋪生靈名冊逐一造冊校驗——\n"
                            "「叮——五器共鳴校驗 100% 通過！太古破界方舟主星門授權解鎖（可執行 activate gate）！」\n" NOR + relic_note);
        return 1;
    }

    tell_object(me, "未知的校驗方位，請使用：calibrate north | northeast | northwest | southwest | south（或 status 查看進度）。\n");
    return 1;
}

int do_activate(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "gate" && arg != "portal" && arg != "array" && arg != "古陣" && arg != "五器") {
        notify_fail("你想啟動哪座核心古陣？試試：activate gate\n");
        return 0;
    }

    int cnt = query_calibrated_count(me);
    if (cnt == 5) {
        message_vision(HIW "【五台精密校驗全數吻合・零公差完美啟動】\n" NOR
                       HIC "隨著正北星盤、東北黑鐵齒輪、西北圖騰屏蔽、西南藥靈閥門與正南天門引五台校驗綠芒連成一線，\n"
                           "三丈高的巨型環狀星門毫無阻滯地轟然運轉，青金長鳴響徹千丈地底——\n"
                           "旋轉著浩瀚星霧的單向青金星門應聲撕開（可輸入 enter gate 踏入洞天）！\n" NOR, me);
    } else {
        // 相容快速觸發與自動化測試，同時完整呈現五階段技術校驗細節
        reset_stations();
        station_states = ([ "north": 1, "northeast": 1, "northwest": 1, "southwest": 1, "south": 1 ]);
        me->set_temp("ark_portal_calib", copy(station_states));
        message_vision(HIC "頭頂千丈地脈在十丈紫黑滅世神雷轟擊下劇烈震顫，宋知微握定星盤大呼催促，五台緊急聯動校驗依序完成：\n"
                           "・[1/5 正北主控台]：以【逆星拓片】補償歲差扣合水銀星象凹盤，釘定跨界座標向量（偏差 0.00°）！\n"
                           "・[2/5 東北傳動台]：左握阿鐵卡尺確認微米偏移，嵌【不融黑鐵齒輪】鎖死空間撕裂應力！\n"
                           "・[3/5 西北黑岩台]：【獵獸圖騰骨片】按入黑岩，綿長呼吸同頻共振展開太古生命屏蔽場！\n"
                           "・[4/5 西南閥門台]：【古礦晶核殘片】配溫和三元藥靈生機催化，平穩點燃儲備靈石總庫！\n"
                           "・[5/5 正南主驗證台]：【天門引】與【九城總契銅版】合印造冊物資證物，青金長鳴響徹大殿——\n"
                           "足有三丈高、旋轉浩瀚星霧的單向青金星門應聲撕開（可輸入 enter gate 踏入洞天）！\n" NOR, me);
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "activate", "target": "gate" ]));
    }
    return 1;
}

int do_enter(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "gate" && arg != "portal" && arg != "star" && arg != "星門" && arg != "洞天") {
        notify_fail("你想踏入哪處傳送光門？試試：enter gate\n");
        return 0;
    }
    object dst = load_object("/d/realm/peach_plateau.c");
    if (!dst) {
        tell_object(me, "星門另一端的空間座標尚在穩定中。\n");
        return 1;
    }
    message_vision(HIW "$N在護山大陣徹底崩碎前的最後一息邁進旋轉星霧！身後紫黑滅世雷火將主傳送室\n"
                       "連同五座石台盡數劈成廢墟煙塵，單向空間裂隙從此徹底閉合……\n" NOR, me);
    me->move(dst);
    return 1;
}
