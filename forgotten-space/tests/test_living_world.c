// /tests/test_living_world.c
// 《遺忘的世界》自然運作機制單元測試 (Living World Simulation Tests)
// 驗證項目：
// 1. PHASE_D：NPC 十二時辰作息表 (Schedule Matrix)、時段轉換、環境動態描寫與事件相位 (Event Phasing)
// 2. RUMOR_D：六縣演進動態情報、大荒商隊物流情報、天候災異預警與 NPC 傳聞問答
// 3. CITY_D：72 小時三日通牒倒數、三條合法身分緩衝路徑 (青衿/藥囊/短褐) 檢核
// 4. 常平倉緊急平糶機制 (250% 閾值平抑、開倉七五折、平價荒糧購買與食用、平糶結束回穩)
// 5. 六縣專材長街即時行情牌價看板 (market_special_buyer list)
// 6. NATURE_D 時間推進心跳串接 (advance_time -> phase_d / world_state_d / rumor_d / city_d 閉環)

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 1: MUD 自然運作機制、NPC 作息相位、動態情報與常平倉平糶驗證");

    // ── 1. 守護進程載入檢驗 ──────────────────────────────────
    object phase_d = load_object(PHASE_D);
    assert_true(objectp(phase_d), "NPC 相位守護進程 (PHASE_D) 必須成功載入");

    object rumor_d = load_object(RUMOR_D);
    assert_true(objectp(rumor_d), "動態傳聞守護進程 (RUMOR_D) 必須成功載入");

    object city_d = load_object(CITY_D);
    assert_true(objectp(city_d), "金石都城守護進程 (CITY_D) 必須成功載入");

    object ws_d = load_object(WORLD_STATE_D);
    assert_true(objectp(ws_d), "世界狀態守護進程 (WORLD_STATE_D) 必須成功載入");

    object nat_d = load_object("/secure/nature_d.c");
    assert_true(objectp(nat_d), "天時氣候守護進程 (NATURE_D) 必須成功載入");

    // ── 2. PHASE_D 時辰轉時段與作息註冊表驗證 ──────────────────
    if (phase_d) {
        assert_equal("dawn", phase_d->query_period_by_shichen("卯時"), "卯時必須對應 dawn (破曉)");
        assert_equal("morning", phase_d->query_period_by_shichen("辰時"), "辰時必須對應 morning (早市)");
        assert_equal("morning", phase_d->query_period_by_shichen("巳時"), "巳時必須對應 morning (早市)");
        assert_equal("noon_afternoon", phase_d->query_period_by_shichen("午時"), "午時必須對應 noon_afternoon (正午)");
        assert_equal("noon_afternoon", phase_d->query_period_by_shichen("未時"), "未時必須對應 noon_afternoon (午後)");
        assert_equal("dusk", phase_d->query_period_by_shichen("申時"), "申時必須對應 dusk (薄暮)");
        assert_equal("dusk", phase_d->query_period_by_shichen("酉時"), "酉時必須對應 dusk (傍晚)");
        assert_equal("night", phase_d->query_period_by_shichen("戌時"), "戌時必須對應 night (入夜)");
        assert_equal("night", phase_d->query_period_by_shichen("亥時"), "亥時必須對應 night (深夜)");
        assert_equal("midnight", phase_d->query_period_by_shichen("子時"), "子時必須對應 midnight (子夜/鬼市)");

        // 驗證核心 NPC 作息註冊完整性
        string *key_npcs = ({
            "zhang_butcher", "lao_miner", "mo_beggar", "kumu_daoist",
            "center_doctor_bai", "center_teacher_lu", "center_wenchengjing",
            "gong_mochui", "wu_bashan", "dao_xingyuan", "square_watchman",
            "square_storyteller", "market_special_buyer"
        });
        foreach (string kn in key_npcs) {
            mapping sched = phase_d->query_npc_schedule(kn);
            assert_true(mapp(sched), sprintf("NPC %s 必須已於 PHASE_D 註冊作息", kn));
            if (sched) {
                assert_true(sched["schedules"] != 0, sprintf("NPC %s 必須包含日程表", kn));
            }
        }

        // 驗證張屠戶時段目標位置
        assert_equal("/d/village/stream.c", phase_d->query_npc_target_room("zhang_butcher", "dawn"), "張屠戶破曉應在溪灘磨刀");
        assert_equal("/d/village/square.c", phase_d->query_npc_target_room("zhang_butcher", "morning"), "張屠戶早市應在街市肉攤擺攤");
        assert_equal("/d/village/square.c", phase_d->query_npc_target_room("zhang_butcher", "dusk"), "張屠戶傍晚應在街市收攤");

        // 驗證白先生時段目標位置
        assert_equal("/d/city/center/clinic.c", phase_d->query_npc_target_room("center_doctor_bai", "morning"), "白先生早間應在醫館診病");
        assert_equal("/d/city/north/gong_alchemy.c", phase_d->query_npc_target_room("center_doctor_bai", "dusk"), "白先生傍晚應赴採百草堂會診");

        // 驗證星淵與李遊徼夜間作息
        assert_equal("/d/city/west/dao_roof.c", phase_d->query_npc_target_room("dao_xingyuan", "midnight"), "星淵子夜應登摘星台頂觀測逆星軌");
        assert_equal("/d/city/gate/gate_south.c", phase_d->query_npc_target_room("square_watchman", "midnight"), "李遊徼子夜應巡防南關城門");

        // 驗證重大事件相位 (Event Phasing)
        phase_d->set_event_phase("mine_collapse", 1);
        assert_equal("/d/village/mine_depths.c", phase_d->query_npc_target_room("lao_miner", "morning"), "礦難發生時魯大山應瞬移至地底避難坑道");
        phase_d->set_event_phase("mine_collapse", 0);
        assert_equal("/d/village/mine.c", phase_d->query_npc_target_room("lao_miner", "morning"), "危機解除後魯大山回歸常態礦道口");

        phase_d->set_event_phase("beast_surge", 1);
        assert_equal("/d/village/forest.c", phase_d->query_npc_target_room("zhang_butcher", "morning"), "獸潮爆發時張屠戶應持刀駐守林口哨防");
        phase_d->set_event_phase("beast_surge", 0);

        phase_d->set_event_phase("canal_notarization", 1);
        assert_equal("/d/city/under/canal_hub.c", phase_d->query_npc_target_room("center_wenchengjing", "morning"), "暗渠公證調查時文承敬應親赴地下樞紐");
        phase_d->set_event_phase("canal_notarization", 0);

        // 驗證環境動態描寫
        string z_desc = phase_d->query_npc_ambient_desc("zhang_butcher", "dawn");
        assert_true(strsrch(z_desc, "磨") != -1, "張屠戶破曉環境動態描寫應包含磨刀");
    }

    // ── 3. RUMOR_D 動態傳聞情報網驗證 ──────────────────────────
    if (rumor_d) {
        string pm_r = rumor_d->query_county_rumor("panmu");
        assert_true(strsrch(pm_r, "盤木") != -1, "RUMOR_D 必須能產出盤木縣動態情報");

        string zs_r = rumor_d->query_county_rumor("zhongshi");
        assert_true(strsrch(zs_r, "重石") != -1, "RUMOR_D 必須能產出重石縣動態情報");

        string qh_r = rumor_d->query_county_rumor("qinghe");
        assert_true(strsrch(qh_r, "青河") != -1, "RUMOR_D 必須能產出青河縣動態情報");

        string car_r = rumor_d->query_caravan_rumor();
        assert_true(strsrch(car_r, "商隊") != -1, "RUMOR_D 必須能產出大荒商隊即時物流情報");

        string w_r = rumor_d->query_weather_rumor();
        assert_true(strsrch(w_r, "天") != -1, "RUMOR_D 必須能產出天候氣象預警情報");

        string law_r = rumor_d->query_city_law_rumor();
        assert_true(strsrch(law_r, "七十二小時") != -1, "RUMOR_D 必須能產出城邦七十二小時居留法紀告示");

        string q_pm = rumor_d->query_random_rumor("盤木");
        assert_true(strsrch(q_pm, "盤木") != -1, "query_random_rumor 依關鍵字篩選必須精確匹配");

        string *all_rumors = rumor_d->query_all_rumors();
        assert_true(sizeof(all_rumors) >= 9, "RUMOR_D 全域情報庫必須涵蓋 7 縣 + 商隊 + 天候 + 法紀至少 9 項");
    }

    // ── 4. CITY_D 72 小時通牒與三條合法身分緩衝路徑驗證 ───────
    if (city_d) {
        // 使用無任何資格之新對象測試流民狀態
        object vagrant = clone_object("/std/living.c");
        assert_true(objectp(vagrant), "測試用無籍流民物件必須建立成功");

        if (vagrant) {
            // 初始未登記流民在 72h 內
            mapping res_init = city_d->check_residency_mandate(vagrant, 10);
            assert_equal("initial_72h_window", res_init["status"], "入城 10 小時且無資格者應為 initial_72h_window");
            assert_equal(62, res_init["hours_remaining"], "72h 視窗剩餘時數應為 72 - 10 = 62");

            // 逾期 72h 無擔保者 -> unregistered_vagrant
            mapping res_exp = city_d->check_residency_mandate(vagrant, 75);
            assert_equal("unregistered_vagrant", res_exp["status"], "逾期 72h 且無任何擔保者必須列為 unregistered_vagrant");

            // 測試路徑 A：學塾白鹿青衿 (+14 天 = +336h，共 408h 寬限)
            object qingjin = clone_object("/clone/item/academy_token.c");
            if (qingjin) {
                qingjin->move(vagrant);
                mapping res_acad = city_d->check_residency_mandate(vagrant, 80);
                assert_equal("buffered_temporary", res_acad["status"], "持有學塾青衿者應免除流民處分並列為 buffered_temporary");
                assert_equal(408, res_acad["grace_hours_total"], "學塾擔保總寬限期應為 72 + 336 = 408 小時");
                destruct(qingjin);
            }

            // 測試路徑 B：車馬行短褐腰牌 (+7 天 = +168h，共 240h 寬限)
            object duanhe = clone_object("/clone/item/caravan_token.c");
            if (duanhe) {
                duanhe->move(vagrant);
                mapping res_car = city_d->check_residency_mandate(vagrant, 80);
                assert_equal("buffered_temporary", res_car["status"], "持有車馬行短褐腰牌者應列為 buffered_temporary");
                assert_equal(240, res_car["grace_hours_total"], "車馬行擔保總寬限期應為 72 + 168 = 240 小時");
                destruct(duanhe);
            }

            // 測試路徑 C：杏林試藥藥囊 (+10 天 = +240h，共 312h 寬限)
            object yaonang = clone_object("/clone/item/clinic_token.c");
            if (yaonang) {
                yaonang->move(vagrant);
                mapping res_med = city_d->check_residency_mandate(vagrant, 80);
                assert_equal("buffered_temporary", res_med["status"], "持有杏林試藥藥囊者應列為 buffered_temporary");
                assert_equal(312, res_med["grace_hours_total"], "杏林擔保總寬限期應為 72 + 240 = 312 小時");
                destruct(yaonang);
            }

            destruct(vagrant);
        }

        // 測試 check_user_residency 即時換算
        mapping cur_res = city_d->check_user_residency(me);
        assert_true(mapp(cur_res), "check_user_residency 必須回傳合法狀態結構");
        assert_true(cur_res["status"] != "", "狀態字串不可為空");
    }

    // ── 5. 常平倉緊急平糶機制與平價荒糧購買食用驗證 ────────────
    if (city_d) {
        assert_equal(0, city_d->query_granary_open(), "常規狀態下常平倉預設應處於封閉狀態");
        assert_equal(100, city_d->query_granary_price_pct(), "常規狀態下市井牌價比例應為 100%");

        // 手動觸發平糶平抑
        city_d->trigger_granary_stabilization("六縣專材告急物價暴漲");
        assert_equal(1, city_d->query_granary_open(), "觸發平糶後常平倉必須為開啟狀態");
        assert_equal(75, city_d->query_granary_price_pct(), "開倉平糶後市井牌價比例應壓回七五折 (75%)");

        // 驗證常平倉大使劉秉忠買賣邏輯
        object liu = load_object("/clone/npc/granary_liubingzhong.c");
        assert_true(objectp(liu), "常平倉大使劉秉忠必須載入成功");
        if (liu) {
            string status_txt = liu->respond_granary_status();
            assert_true(strsrch(status_txt, "開倉平糶") != -1, "開倉狀態下劉秉忠應主動告知開倉平糶供應平價荒糧");

            // 給予測試玩家金錢並測試購買平糶荒糧
            me->add_money(50);
            int buy_res = liu->do_buy("grain", me);
            assert_equal(1, buy_res, "平糶期間玩家必須可成功購買平糶荒糧");
            object bought_grain = present("relief grain", me);
            assert_true(objectp(bought_grain), "玩家背包中必須獲得平糶荒糧袋");

            if (bought_grain) {
                int old_kee = me->query(VITAL_KEE);
                bought_grain->do_eat("grain");
                assert_true(me->query(VITAL_KEE) >= old_kee, "食用平價荒糧必須回復氣血");
            }
        }

        // 透過 city_tick 將平糶計時歸零，驗證平糶結束回穩
        for (int t = 0; t < 125; t++) {
            city_d->city_tick(t);
        }
        assert_equal(0, city_d->query_granary_open(), "計時歸零後常平倉必須自動關閉");
        assert_equal(100, city_d->query_granary_price_pct(), "平糶結束後牌價比例應回歸 100%");
    }

    // ── 6. 六縣專材長街即時行情看板驗證 ─────────────────────────
    object cheng = load_object("/clone/npc/market_special_buyer.c");
    assert_true(objectp(cheng), "六縣採辦總牙人程通四海必須載入成功");
    if (cheng) {
        string board = cheng->render_market_board();
        assert_true(strsrch(board, "六縣專材即時行情牌價") != -1, "看板標題必須包含六縣專材即時行情牌價");
        assert_true(strsrch(board, "青河洗靈草") != -1, "看板必須包含青河洗靈草");
        assert_true(strsrch(board, "烈礬特級耐火泥") != -1, "看板必須包含烈礬特級耐火泥");
        assert_true(strsrch(board, "盤木紅杉原木") != -1, "看板必須包含盤木紅杉原木");
        assert_true(strsrch(board, "鎮風風蝕石英") != -1, "看板必須包含鎮風風蝕石英");
        assert_true(strsrch(board, "濁水腐骨毒囊") != -1, "看板必須包含濁水腐骨毒囊");
        assert_true(strsrch(board, "重石重玄鐵錠") != -1, "看板必須包含重石重玄鐵錠");
    }

    // ── 7. NPC 通用傳聞問答與環境動作驗證 ───────────────────────
    object watchman = clone_object("/clone/npc/square_watchman.c");
    assert_true(objectp(watchman), "巡街遊徼李遊徼必須載入成功");
    if (watchman) {
        // 設定環境動作提示並驗證 query_long
        watchman->set_temp("ambient_action", "正手按鐵尺盯著往來流民。");
        string w_long = watchman->query_long();
        assert_true(strsrch(w_long, "當前動靜") != -1, "NPC query_long 必須包含當前動靜提示");
        assert_true(strsrch(w_long, "正手按鐵尺") != -1, "NPC query_long 必須呈現當前時段動態描寫");
        destruct(watchman);
    }

    // ── 8. 天時推進與自主循環 (advance_time) 閉環驗證 ───────────
    if (nat_d) {
        int old_gt = nat_d->query_game_time();
        nat_d->advance_time(120); // 推進 120 遊戲分鐘 (1 個時辰)
        assert_equal(old_gt + 120, nat_d->query_game_time(), "advance_time 必須精確累加遊戲總分鐘");
        // 驗證 phase_d 與 world_state_d 正常運作未崩潰
        assert_true(stringp(phase_d->query_current_period()), "時辰更迭後 phase_d 必須持有有效時段字串");
    }
}
