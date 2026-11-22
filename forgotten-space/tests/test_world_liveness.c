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

    if (tester) destruct(tester);
    report_results();
}
