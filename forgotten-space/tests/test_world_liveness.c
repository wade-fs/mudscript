// /tests/test_world_liveness.c
// 世界擴展與生活化生態驗證：
// 1. 新增 Tier 0 / Tier 1 / Tier 2 非主線日常空間 (18 間) 載入、雙向出口對稱與五感設定
// 2. 六縣動態住民/飲食/行情系統 (std/county_room.c) 與官道過客系統 (std/route_room.c)
// 3. 兩條市井煙火支線任務 (side_village_grain_errand / side_county_liefan_mungbean) 完整通關

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("世界擴展、六縣動態生態與日常支線任務驗證");

    string *new_rooms = ({
        "/d/village/chen_grain_shop.c",
        "/d/village/old_granary_yard.c",
        "/d/village/wash_bank.c",
        "/d/village/south_quarry.c",
        "/d/village/earth_shrine.c",
        "/d/village/lumber_slope.c",
        "/d/village/village_school.c",
        "/d/village/peddler_corner.c",
        "/d/village/smokehouse_shed.c",
        "/d/city/outer/tenement_alley.c",
        "/d/city/center/tea_alley.c",
        "/d/city/outer/river_wharf.c",
        "/d/city/north/scrap_yard.c",
        "/d/sects/taiqing/scripture_copy_hall.c",
        "/d/sects/taiqing/outer_dormitory.c",
        "/d/sects/danding/outer_herb_terrace.c",
        "/d/sects/danding/sect_refectory.c",
        "/d/sects/tiangong/apprentice_shed.c",
        "/d/sects/tiangong/slag_pit.c",
        "/d/sects/bahuang/outer_barracks.c",
        "/d/yunjin/river_wharf.c",
        "/d/counties/zhenfeng/garrison_lane.c",
        "/d/counties/qinghe/river_tea_shed.c",
        "/d/counties/panmu/timber_wharf.c",
        "/d/counties/zhongshi/carter_yard.c",
        "/d/counties/zhuoshui/ginger_soup_stall.c",
        "/d/counties/liefan/miners_tea_shed.c",
        "/d/city/south/wine_tavern.c",
        "/d/city/south/dye_alley.c",
        "/d/city/outer/charity_clinic_shed.c",
        "/d/city/outer/fish_market.c",
        "/d/yunjin/temple_tea_fair.c",
        "/d/yunjin/dock_coolie_lane.c",
        "/d/wastes/frost_hunter_camp.c"
    });

    foreach (string rpath in new_rooms) {
        object rm = load_object(rpath);
        assert_true(objectp(rm), "生活擴展空間應能載入: " + rpath);
        mapping exs = rm->query_exits();
        assert_true(mapp(exs) && sizeof(exs) > 0, "擴展空間必須有出口: " + rpath);
        assert_true(stringp(rm->query_touch("default")) && strlen(rm->query_touch("default")) > 5,
                    "擴展空間應具備觸覺描寫: " + rpath);
        assert_true(stringp(rm->query_smell("default")) && strlen(rm->query_smell("default")) > 5,
                    "擴展空間應具備嗅覺描寫: " + rpath);
        assert_true(stringp(rm->query_listen("default")) && strlen(rm->query_listen("default")) > 5,
                    "擴展空間應具備聽覺描寫: " + rpath);

        // 驗證至少有一個相鄰房間雙向連回
        int has_recip = 0;
        foreach (string dir, string target in exs) {
            object nb = load_object(target);
            if (!objectp(nb)) continue;
            mapping nb_exs = nb->query_exits();
            if (!mapp(nb_exs)) continue;
            foreach (string ndir, string ntarget in nb_exs) {
                if (ntarget == rpath) has_recip = 1;
            }
        }
        assert_true(has_recip, "擴展空間必須與母房間建立雙向對稱出口: " + rpath);
    }

    object tester = clone_object("/std/user.c");
    tester->set_id("liveness_tester");
    tester->set_name("市井旅人");
    tester->enable_commands();
    tester->set_level(3);
    tester->recalc_stats();
    tester->set_kee(100);
    tester->set_sen(100);
    tester->set_sp(100);

    object q_engine = load_object(QUEST_ENGINE_D);
    assert_true(objectp(q_engine), "QUEST_ENGINE_D 應正常載入");

    // ── 2. 六縣動態住民、風土五感與飲食/行情指令驗證 ─────────────────────
    object inn = load_object("/d/counties/liefan/post_inn.c");
    object mkt = load_object("/d/counties/liefan/market.c");
    object ridge = load_object("/d/counties/liefan/tongtuo_ridge.c");
    assert_true(objectp(inn) && objectp(mkt) && objectp(ridge), "烈礬縣樣本房間應正常載入");

    assert_true(stringp(inn->query_smell("default")) && strsrch(inn->query_smell("default"), "明礬") != -1,
                "烈礬縣房間應具備自動縣城嗅覺風土描寫");
    assert_true(stringp(ridge->query_touch("default")) && strsrch(ridge->query_touch("default"), "礦粉") != -1,
                "銅駝嶺礦區應具備礦石觸覺描寫");

    move_object(tester, inn);
    tester->command("look");
    object innkeeper_ob = present("innkeeper", inn);
    assert_true(objectp(innkeeper_ob), "烈礬客舍進入/環顧後應自動生成地方客棧夥計");
    tester->command("rest");

    move_object(tester, mkt);
    tester->command("look");
    object broker_ob = present("broker", mkt);
    assert_true(objectp(broker_ob), "烈礬大集進入後應自動生成通寶牙行小販");
    tester->command("browse");

    move_object(tester, ridge);
    tester->command("look");
    object worker_ob = present("county_worker", ridge);
    assert_true(objectp(worker_ob), "銅駝嶺礦區進入後應自動生成地方老匠工");

    // ── 3. 官道動態過客、關卡巡檢與地貌五感驗證 ────────────────────────
    object route_rm = load_object("/d/routes/stone_highway_pavilion.c");
    assert_true(objectp(route_rm), "官道涼亭房間應正常載入");
    assert_true(stringp(route_rm->query_listen("default")) && strlen(route_rm->query_listen("default")) > 10,
                "官道房間應具備動態聽覺描寫");
    move_object(tester, route_rm);
    tester->command("look");
    object trav_ob = present("traveler", route_rm);
    assert_true(objectp(trav_ob), "官道涼亭節點應自動生成過路腳夫/旅人");
    tester->command("survey");

    object pass_rm = load_object("/d/routes/blackstone_pass.c");
    assert_true(objectp(pass_rm), "黑石關卡房間應正常載入");
    move_object(tester, pass_rm);
    tester->command("look");
    object rguard_ob = present("route_guard", pass_rm);
    assert_true(objectp(rguard_ob), "官道關卡節點應自動生成關卡巡檢卒");
    tester->command("check_pass");

    // ── 4. 日常支線任務完整流程驗證 ─────────────────────────────────────
    // 4.1 陳記雜糧・鄰里勻米
    object grain_shop = load_object("/d/village/chen_grain_shop.c");
    object wash_bank = load_object("/d/village/wash_bank.c");
    move_object(tester, grain_shop);
    tester->command("ask chen_grain_owner about 送糧");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_village_grain_errand"),
                 "向陳老漢打聽送糧應接取 side_village_grain_errand");
    tester->command("weigh grain");

    move_object(tester, wash_bank);
    tester->command("ask wang_washerwoman about 送糧");

    move_object(tester, grain_shop);
    tester->command("ask chen_grain_owner about 送糧");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_village_grain_errand"),
                 "完成秤米與鄰里交米後 side_village_grain_errand 應結算為 COMPLETED");

    // 4.2 赤岩客舍・井水綠豆湯 (跨縣城動態 NPC 任務)
    move_object(tester, inn);
    tester->command("ask innkeeper about 吃食");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_county_liefan_mungbean"),
                 "向烈礬客棧夥計打聽吃食應接取 side_county_liefan_mungbean");

    move_object(tester, ridge);
    tester->command("ask county_worker about 送湯");

    move_object(tester, inn);
    tester->command("ask innkeeper about 吃食");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_county_liefan_mungbean"),
                 "送湯上銅駝嶺並回報客舍後 side_county_liefan_mungbean 應結算為 COMPLETED");

    // 4.3 村尾蒙館・一錠松煙墨
    object school_rm = load_object("/d/village/village_school.c");
    object peddler_rm = load_object("/d/village/peddler_corner.c");
    move_object(tester, school_rm);
    tester->command("ask song_xiucai about 墨錠");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_village_school_ink"),
                 "向宋秀才打聽墨錠應接取 side_village_school_ink");
    move_object(tester, peddler_rm);
    tester->command("ask peddler_hu about 松煙墨");
    move_object(tester, school_rm);
    tester->command("ask song_xiucai about 墨錠");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_village_school_ink"),
                 "帶回松煙墨後 side_village_school_ink 應結算為 COMPLETED");

    // 4.4 官道驟雨・搶運貨棚
    move_object(tester, route_rm);
    tester->command("ask route_traveler about 官道");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_route_storm_cargo"),
                 "向接官亭趟子手打聽官道應接取 side_route_storm_cargo");
    tester->command("cover cargo");
    tester->command("ask route_traveler about 官道");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_route_storm_cargo"),
                 "蓋好貨棚並覆命後 side_route_storm_cargo 應結算為 COMPLETED");

    // 4.5 鎮風矮巷・邊卒冬襖 (跨縣城具名軍屬與動態巡檢卒任務)
    object zf_lane = load_object("/d/counties/zhenfeng/garrison_lane.c");
    object zf_beacon = load_object("/d/counties/zhenfeng/north_beacon.c");
    move_object(tester, zf_lane);
    tester->command("ask feng_seamstress about 冬襖");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_county_zhenfeng_coat"),
                 "向馮嫂打聽冬襖應接取 side_county_zhenfeng_coat");
    tester->command("stitch coat");
    move_object(tester, zf_beacon);
    tester->command("look");
    tester->command("ask county_bailiff about 冬襖");
    move_object(tester, zf_lane);
    tester->command("ask feng_seamstress about 冬襖");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_county_zhenfeng_coat"),
                 "送襖上烽燧並報平安後 side_county_zhenfeng_coat 應結算為 COMPLETED");

    // 4.6 老酒肆・跑商聽風 (金石物產差價生態)
    object tavern_rm = load_object("/d/city/south/wine_tavern.c");
    object g_mkt_rm = load_object("/d/city/south/grain_market.c");
    move_object(tester, tavern_rm);
    tester->command("ask tavern_merchant about 吹牛");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_city_trade_rumor"),
                 "向陳大牙打聽吹牛應接取 side_city_trade_rumor");
    move_object(tester, g_mkt_rm);
    tester->command("ask south_grain_guildhead about 糧價");
    move_object(tester, tavern_rm);
    tester->command("trade goods");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_city_trade_rumor"),
                 "核實糧價並於酒肆跑商後 side_city_trade_rumor 應結算為 COMPLETED");

    // 4.7 凍土尋羊・荒原迷蹤 (北荒非主線牧民日常)
    object camp_rm = load_object("/d/wastes/frost_hunter_camp.c");
    object bpass_rm = load_object("/d/wastes/black_mountain_pass.c");
    move_object(tester, camp_rm);
    tester->command("ask wastes_herder about 黃羊");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_wastes_lost_goat"),
                 "向牧戶烏蘭打聽黃羊應接取 side_wastes_lost_goat");
    move_object(tester, bpass_rm);
    tester->command("herd goat");
    move_object(tester, camp_rm);
    tester->command("ask wastes_herder about 黃羊");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_wastes_lost_goat"),
                 "尋回黃羊並交還烏蘭後 side_wastes_lost_goat 應結算為 COMPLETED");

    // 4.8 冰河碼頭・竹籌對帳 (雲津苦力算帳)
    object yj_wharf = load_object("/d/yunjin/river_wharf.c");
    object yj_tally = load_object("/d/yunjin/dock_coolie_lane.c");
    move_object(tester, yj_wharf);
    tester->command("ask yunjin_wharf_master about 工錢");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_yunjin_coolie_tally"),
                 "向雲津船把頭打聽工錢應接取 side_yunjin_coolie_tally");
    move_object(tester, yj_tally);
    tester->command("tally chips");
    move_object(tester, yj_wharf);
    tester->command("ask yunjin_wharf_master about 工錢");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_yunjin_coolie_tally"),
                 "核對竹籌並覆命後 side_yunjin_coolie_tally 應結算為 COMPLETED");

    // ── 5. 平民市井 RUMOR_D 與消除空房驗證 ─────────────────────────────
    object rum_d = load_object(RUMOR_D);
    assert_true(objectp(rum_d), "RUMOR_D 應正常載入");
    string folk_rum = rum_d->query_slice_of_life_rumor();
    assert_true(stringp(folk_rum) && strlen(folk_rum) > 10,
                "RUMOR_D 應能輸出民間市井平凡瑣事傳聞");

    string *former_empty_rooms = ({
        "/d/city/outer/south_road.c",
        "/d/city/west/dao_gate.c",
        "/d/city/wall/wall_path_s.c",
        "/d/sects/tiangong/vault_four.c",
        "/d/yunjin/wanshan_square.c",
        "/d/wastes/expedition_camp.c"
    });
    foreach (string erp in former_empty_rooms) {
        object erm = load_object(erp);
        assert_true(objectp(erm), "原空房修復後應正常載入: " + erp);
        assert_true(stringp(erm->query_touch("default")) && strlen(erm->query_touch("default")) > 5,
                    "原空房修復後應具備觸覺描寫: " + erp);
    }

    string *sensory_spot_rooms = ({
        "/d/city/center/yamen.c",
        "/d/city/east/wu_arena.c",
        "/d/city/north/gong_alchemy.c",
        "/d/city/gate/gate_south.c",
        "/d/sects/bahuang/gate.c",
        "/d/sects/taiqing/star_law_hall.c",
        "/d/sects/danding/herb_garden.c",
        "/d/sects/tiangong/machinery_depths.c"
    });
    foreach (string srp in sensory_spot_rooms) {
        object srm = load_object(srp);
        assert_true(objectp(srm), "補齊五感之舊房應正常載入: " + srp);
        assert_true(stringp(srm->query_touch("default")) && strlen(srm->query_touch("default")) > 5,
                    "舊房應具備觸覺描寫: " + srp);
        assert_true(stringp(srm->query_smell("default")) && strlen(srm->query_smell("default")) > 5,
                    "舊房應具備嗅覺描寫: " + srp);
        assert_true(stringp(srm->query_listen("default")) && strlen(srm->query_listen("default")) > 5,
                    "舊房應具備聽覺描寫: " + srp);
    }

    // ── 6. Phase 2B：日夜季節節律、庶民排程互動、因果經濟與階層四維度 ──
    object pd = load_object(PHASE_D);
    object ws = load_object(WORLD_STATE_D);
    object nd = load_object("/secure/nature_d.c");
    object cd = load_object(CITY_D);

    // (6a) 日夜時辰 × 季節節律描寫
    object f_mkt = load_object("/d/city/outer/fish_market.c");
    object q_ferry = load_object("/d/counties/qinghe/ferry_dock.c");
    object tf_pass = load_object("/d/routes/tianfeng_gorge_pass.c");
    assert_true(objectp(f_mkt) && objectp(q_ferry) && objectp(tf_pass), "Phase 2B 核心時節樞紐房間應正常載入");
    nd->set_season_override("winter");
    string rhythm_fm = pd->query_room_rhythm_line(f_mkt);
    assert_true(strsrch(rhythm_fm, "時辰風物") != -1, "PHASE_D 應生成區域時辰風物動態描寫");
    assert_true(strsrch(rhythm_fm, "玄冥冬歲") != -1, "冬季覆寫下應呈現玄冥冬歲禦寒行情");
    string tf_long = tf_pass->query_long();
    assert_true(strsrch(tf_long, "當季路況實警") != -1, "冬季天風峽官道應動態顯示當季積雪封道實警");

    // (6b) 庶民自主作息與 NPC-to-NPC 可觀察互動劇本
    string *folk_keys = ({
        "fishmonger_liu", "sun_old_carter", "qinghe_boatman", "qinghe_herb_woman",
        "roaming_porter", "liefan_old_miner", "zhou_quarryman", "panmu_raftsman",
        "peddler_hu", "charity_herbalist"
    });
    foreach (string fk in folk_keys) {
        assert_true(mapp(pd->query_npc_schedule(fk)), "PHASE_D 應已註冊庶民作息: " + fk);
    }
    assert_equal("/d/city/outer/fish_market.c", pd->query_npc_target_room("roaming_porter", "dawn"),
                 "挑夫阿福破曉應至魚市搶頭批貨擔");
    assert_equal("/d/city/outer/tenement_alley.c", pd->query_npc_target_room("roaming_porter", "dusk"),
                 "挑夫阿福黃昏應回流民矮巷歇腳");
    assert_equal("/d/counties/qinghe/ferry_dock.c", pd->query_npc_target_room("qinghe_boatman", "morning"),
                 "柳伯上午應在青河駁船碼頭撐船");
    assert_equal("/d/counties/qinghe/river_tea_shed.c", pd->query_npc_target_room("qinghe_boatman", "dusk"),
                 "柳伯黃昏收纜後應赴蘆花渡粗茶棚喝茶");

    // 驗證青河渡口四段式 NPC-to-NPC 互動序列
    string s_b0 = pd->query_hub_scene_line("/d/counties/qinghe/ferry_dock.c", 0);
    string s_b1 = pd->query_hub_scene_line("/d/counties/qinghe/ferry_dock.c", 1);
    string s_b2 = pd->query_hub_scene_line("/d/counties/qinghe/ferry_dock.c", 2);
    string s_b3 = pd->query_hub_scene_line("/d/counties/qinghe/ferry_dock.c", 3);
    assert_true(strsrch(s_b0, "船底") != -1 && strsrch(s_b1, "木籌") != -1 &&
                strsrch(s_b2, "漲了兩文") != -1 && strsrch(s_b3, "安靜") != -1,
                "青河渡口應完整涵蓋檢船、爭工錢、怨船資與船離後靜謐四拍互動");
    string adv_b = pd->advance_hub_scene(q_ferry);
    assert_true(strlen(adv_b) > 10, "advance_hub_scene 應能依序推進樞紐日常互動節拍");

    // (6c) 因果經濟鏈聯動（礦場停工／暴雨滑坡／河水暴漲／寒潮來襲）
    ws->trigger_causal_event("mine_shutdown", 60);
    ws->trigger_causal_event("northern_cold_snap", 60);
    ws->trigger_causal_event("landslide_rain", 60);
    assert_equal(1, ws->is_mine_economy_halted(), "觸發 mine_shutdown 後礦業經濟停擺標記應為 1");
    assert_equal("/d/counties/liefan/miners_tea_shed.c",
                 pd->query_npc_target_room("liefan_old_miner", "morning"),
                 "礦場停工期羅七上午應聚集粗茶棚而非下井");
    assert_true(ws->query_causal_bonus_pct("fur_cloak") >= 40, "寒潮期間鎮風皮襖因果漲幅應 >= 40%");
    assert_true(ws->query_causal_bonus_pct("charcoal") >= 35, "寒潮期間黑石鋪木炭因果漲幅應 >= 35%");
    assert_true(ws->query_causal_bonus_pct("panmu") >= 25, "山路暴雨滑坡應使盤木因果漲幅 >= 25%");
    mapping s_goods = ws->query_seasonal_goods_market();
    assert_true(mapp(s_goods) && mapp(s_goods["ginger_soup"]) && s_goods["ginger_soup"]["price_pct"] >= 130,
                "濁水老薑驅寒湯在寒潮期間行情應升至 >= 130%");
    object buyer = load_object("/clone/npc/market_special_buyer.c");
    string mb_txt = buyer ? buyer->render_market_board() : "";
    assert_true(strsrch(mb_txt, "民生／歲時急需貨物即時牌價") != -1 && strsrch(mb_txt, "寒潮") != -1,
                "採辦牌價看板應動態顯示冬寒民生急需價格與因果成因");
    string c_rum = rum_d->query_causal_economy_rumor();
    assert_true(stringp(c_rum) && strlen(c_rum) > 10, "RUMOR_D 應能輸出因果漲價見聞");
    ws->resolve_causal_event("mine_shutdown");
    ws->resolve_causal_event("northern_cold_snap");
    ws->resolve_causal_event("landslide_rain");
    nd->set_season_override("");

    // (6d) 社會階層四維度結構（身分 × 生計 × 資源 × 流動）
    tester->set("class", "");
    tester->set("guild", "");
    tester->set("city_entry_time", time() - 80 * 900); // 逾期 > 72h -> unregistered_vagrant
    mapping tier_v = cd->query_social_tier(tester);
    assert_equal("unregistered_vagrant", tier_v["tier_id"], "逾期無憑證者應歸為 unregistered_vagrant");
    assert_equal(0, tier_v["resources"]["inner_inn_allowed"], "無籍流民不可入住內城中心客棧雅間");

    object alley_rm = load_object("/d/city/outer/tenement_alley.c");
    object charity_rm = load_object("/d/city/outer/charity_clinic_shed.c");
    object clinic_rm = load_object("/d/city/center/clinic.c");
    object inn_rm = load_object("/d/city/center/inn_main.c");
    tester->add_money(200);

    move_object(tester, alley_rm);
    tester->command("porridge");
    tester->command("lodge");
    move_object(tester, charity_rm);
    int k_before = tester->query(VITAL_KEE);
    tester->command("heal");
    assert_true(tester->query(VITAL_KEE) >= k_before, "南關外施藥義棚應免費醫治無籍流民");

    // 內城醫館與中心客棧應拒絕無籍流民
    move_object(tester, clinic_rm);
    int m_before = tester->query("money");
    tester->command("treat");
    assert_equal(m_before, tester->query("money"), "杏林醫館應拒絕無籍流民而不扣診金");

    move_object(tester, inn_rm);
    tester->command("lodge");
    assert_equal(m_before, tester->query("money"), "金石大客棧應拒絕無籍流民投宿雅間");

    // 階層流動：先領《暫住牌》 -> 再獲學塾青衿保書 -> 即可入中心客棧與醫館 -> 再立籍
    move_object(tester, alley_rm);
    tester->command("register_pass");
    assert_true(objectp(present("temp residency pass", tester)), "register_pass 應成功領取《金石南關暫住牌》");
    mapping tier_tp = cd->query_social_tier(tester);
    assert_equal("outer_sojourner", tier_tp["tier_id"], "領取《暫住牌》後階層應升為外城短工 (outer_sojourner)");

    object acad_tok = clone_object("/clone/item/academy_token.c");
    acad_tok->move(tester);
    mapping tier_buf = cd->query_social_tier(tester);
    assert_equal("buffered_sojourner", tier_buf["tier_id"], "取得青衿保書後階層應升為持保書暫居客");
    assert_equal(1, tier_buf["resources"]["inner_inn_allowed"], "持保書暫居客應獲准入住中心客棧");
    move_object(tester, inn_rm);
    int m_inn_before = tester->query("money");
    tester->command("lodge");
    assert_equal(m_inn_before - 50, tester->query("money"), "持保書入宿金石大客棧應扣除 50 文雅間房資");

    // ── 7. Phase 3：因果跨區跑商、深化分層語氣與六縣官道宗門日常支線 ──
    ws->trigger_causal_event("northern_cold_snap", 60);
    mapping qt_char = ws->query_trade_quote("blackstone_charcoal", "yunjin");
    assert_true(mapp(qt_char) && qt_char["spread"] > 0 && qt_char["causal_active"] == 1,
                "寒潮期間黑石硬木炭運往雲津應顯示因果急漲正利潤差價");

    object peddler_rm2 = load_object("/d/village/peddler_corner.c");
    object yj_ex = load_object("/d/yunjin/exchange_hall.c");
    tester->add_money(200);
    move_object(tester, peddler_rm2);
    tester->command("cargo buy blackstone_charcoal");
    assert_true(objectp(present("trade_cargo", tester)), "應能於黑石鋪貨郎棚購入實體《黑石硬木炭》貨包");
    // 同產地原地賣出應遭阻擋
    int m_orig_try = tester->query("money");
    tester->command("cargo sell");
    assert_equal(m_orig_try, tester->query("money"), "同產地原地交割貨包應不給利潤且退回攔阻");
    // 跨區運至雲津三宗交割廳脫手獲利
    move_object(tester, yj_ex);
    int m_yj_before = tester->query("money");
    tester->command("cargo sell");
    assert_true(tester->query("money") > m_yj_before, "跨區運至雲津交割廳賣出貨包應實收並獲利");
    assert_true(!objectp(present("trade_cargo", tester)), "交割脫手後背包內對應貨包應清除");
    ws->resolve_causal_event("northern_cold_snap");

    // 深化 RUMOR_D 語氣分層驗證
    mapping r_peasant = rum_d->query_tiered_folk_rumor("peasant_boatman", "flood_sluice");
    mapping r_merch = rum_d->query_tiered_folk_rumor("merchant_artisan", "flood_sluice");
    assert_true(strsrch(r_peasant["msg"], "龍王") != -1, "普通農婦／船夫應呈現民俗誤解絮語");
    assert_true(strsrch(r_merch["msg"], "攔水閘") != -1, "專業跑商／老匠應能點破攔水閘與供需差價實務判斷");

    // 驗證 6 條 Phase 3 新增日常支線可完整通關結算
    tester->set_level(4);

    // Q1: 烈礬礦棚・停工賒糧（觸發礦場停工期讓羅七匯聚粗茶棚）
    ws->trigger_causal_event("mine_shutdown", 60);
    pd->sync_all_npc_locations();
    object lf_shed = load_object("/d/counties/liefan/miners_tea_shed.c");
    object lf_mkt = load_object("/d/counties/liefan/market.c");
    move_object(tester, lf_shed);
    tester->command("ask liefan_old_miner about 賒糧");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_county_liefan_credit_grain"),
                 "詢問羅七應接取 side_county_liefan_credit_grain");
    move_object(tester, lf_mkt);
    tester->command("credit grain");
    move_object(tester, lf_shed);
    tester->command("ask liefan_old_miner about 賒糧");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_county_liefan_credit_grain"),
                 "替礦工家屬賒糧覆命後應結算為 COMPLETED");
    ws->resolve_causal_event("mine_shutdown");

    // Q2: 青河碼頭・搶修纜樁
    move_object(tester, q_ferry);
    tester->command("ask qinghe_herb_woman about 纜樁");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_county_qinghe_mooring"),
                 "詢問翠嬸應接取 side_county_qinghe_mooring");
    tester->command("repair mooring");
    tester->command("ask qinghe_herb_woman about 纜樁");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_county_qinghe_mooring"),
                 "搶修渡口纜樁並覆命後應結算為 COMPLETED");

    // Q3: 盤木林道・冬寒送炭
    object pm_inn = load_object("/d/counties/panmu/post_inn.c");
    move_object(tester, peddler_rm2);
    tester->command("ask peddler_hu about 木炭");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_county_panmu_charcoal_sled"),
                 "詢問貨郎胡二應接取 side_county_panmu_charcoal_sled");
    move_object(tester, pm_inn);
    tester->command("deliver_warmth charcoal");
    move_object(tester, peddler_rm2);
    tester->command("ask peddler_hu about 木炭");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_county_panmu_charcoal_sled"),
                 "冬寒送炭至盤木並覆命後應結算為 COMPLETED");

    // Q4: 林海官道・寒夜借火
    object f_post = load_object("/d/routes/forest_sea_post.c");
    move_object(tester, f_post);
    tester->command("ask route_traveler about 借火");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_route_winter_hearth"),
                 "詢問林海驛趟子手應接取 side_route_winter_hearth");
    tester->command("kindle fire");
    tester->command("ask route_traveler about 借火");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_route_winter_hearth"),
                 "寒夜借火點燃篝火覆命後應結算為 COMPLETED");

    // Q5: 青河水驛・修補車輪
    object q_post = load_object("/d/routes/qinghe_post.c");
    move_object(tester, q_post);
    tester->command("ask route_traveler about 車輪");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_route_wheel_repair"),
                 "詢問半途水驛趟子手應接取 side_route_wheel_repair");
    tester->command("mend wheel");
    tester->command("ask route_traveler about 車輪");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_route_wheel_repair"),
                 "修補車輪覆命後應結算為 COMPLETED");

    // Q6: 八荒伙房・舊欠家書
    object bh_k = load_object("/d/sects/bahuang/north_garrison_kitchen.c");
    move_object(tester, bh_k);
    tester->command("ask a_man about 家書");
    assert_equal("ACTIVE", q_engine->query_quest_state(tester, "side_sect_bahuang_ration_tally"),
                 "詢問阿滿應接取 side_sect_bahuang_ration_tally");
    tester->command("sort letters");
    tester->command("ask a_man about 家書");
    assert_equal("COMPLETED", q_engine->query_quest_state(tester, "side_sect_bahuang_ration_tally"),
                 "整理軍寨家書交還阿滿後應結算為 COMPLETED");

    if (tester) destruct(tester);
    report_results();
}
