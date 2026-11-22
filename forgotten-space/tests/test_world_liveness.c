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
        "/d/yunjin/river_wharf.c"
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

    // ── 3. 官道動態過客與地貌五感驗證 ──────────────────────────────────
    object route_rm = load_object("/d/routes/stone_highway_pavilion.c");
    assert_true(objectp(route_rm), "官道涼亭房間應正常載入");
    assert_true(stringp(route_rm->query_listen("default")) && strlen(route_rm->query_listen("default")) > 10,
                "官道房間應具備動態聽覺描寫");
    move_object(tester, route_rm);
    tester->command("look");
    object trav_ob = present("traveler", route_rm);
    assert_true(objectp(trav_ob), "官道涼亭節點應自動生成過路腳夫/旅人");

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

    if (tester) destruct(tester);
    report_results();
}
