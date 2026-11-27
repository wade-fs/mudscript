// /tests/test_quest_choices_and_regions.c
// 主線玩法多樣化、分支決策 choices、REGION_D 動態勢力／儲備／危機聯動回歸測試
// 驗證項目：
// 1. std/room.c quest_target_from_arg 與 sensory_msgs 宣告式多分支指令端到端派發
// 2. QUEST_ENGINE_D 任務分支 choices 記錄、checklist 決策選項渲染、單步 region_effects 同步
// 3. 六縣物證（張榜觸發黑市投機） -> 三方會審（常平倉賑濟抉擇 + 封印底單 + 抄沒結算平抑危機）因果閉環
// 4. 雲津（泥途立帳 + 履約分批賠償）與萬物外環（站點分倉稽查）及八荒（測冰長簽）實機指令與區域狀態變化

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"
#include "/include/world_event.h"

void run_tests(object me) {
    start_test("主線玩法多樣化、分支決策與 REGION_D 因果聯動驗證");

    object rd = load_object(REGION_D);
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(rd) && objectp(qe), "REGION_D 與 QUEST_ENGINE_D 必須成功載入");

    rd->set_test_mode(1);
    rd->reset_regions();

    object p = clone_object("/std/user.c");
    assert_true(objectp(p), "測試角色必須建立成功");
    if (!p) {
        report_results();
        return;
    }
    p->set_id("quest_choice_tester");
    p->set_name("試煉旅者");
    p->set_level(60);
    p->enable_commands();
    p->recalc_stats();

    // ── 1. v2_six_county_evidence：inspect clay + public_posting 觸發危機與物價震盪 ──
    object inn   = load_object("/d/city/gate/gate_south_inn.c");
    object forge = load_object("/d/city/north/gong_forge.c");
    assert_true(objectp(inn) && objectp(forge), "南關小棧與千錘地爐坊必須載入");

    int js_pref_0 = rd->query_faction_power("jinshi", "prefect_office");
    int js_chmb_0 = rd->query_faction_power("jinshi", "chamber_of_commerce");

    move_object(p, inn);
    qe->trigger_event(p, "talk", ([ "npc": "gate_south_inn_laoliu", "topic": "四線" ]));
    assert_equal(2, qe->query_quest_step(p, "v2_six_county_evidence"), "四線啟程後應位於 step 2");

    move_object(p, forge);
    assert_equal(1, p->command("inspect clay"), "千錘地爐坊應可實測 inspect clay");
    assert_true(objectp(present("liefan_clay_batch", p)) || objectp(present("clay", p)) ||
                qe->query_quest_step(p, "v2_six_county_evidence") == 3,
                "實測耐火白泥後應推進至 step 3");

    move_object(p, load_object("/d/city/center/clinic.c"));
    qe->trigger_event(p, "talk", ([ "npc": "clinic_baixiansheng", "topic": "毒囊" ]));
    move_object(p, load_object("/d/city/east/wu_hall.c"));
    qe->trigger_event(p, "talk", ([ "npc": "wu_hall_bashan", "topic": "走山令" ]));
    move_object(p, load_object("/d/city/south/market_special.c"));
    qe->trigger_event(p, "talk", ([ "npc": "market_special_buyer", "topic": "鐵木" ]));
    move_object(p, load_object("/d/city/center/pawnshop.c"));
    qe->trigger_event(p, "talk", ([ "npc": "pawnshop_jiachaofeng", "topic": "雲記" ]));
    assert_equal(7, qe->query_quest_step(p, "v2_six_county_evidence"), "推進四線後半步應達 step 7");

    string chk_ev = qe->query_quest_checklist(p, "v2_six_county_evidence");
    assert_true(strsrch(chk_ev, "決策選項 [publish_case public_posting]") != -1,
                "checklist 應渲染 step 7 的分支決策選項");

    move_object(p, inn);
    assert_equal(1, p->command("publish_case public_posting"), "南關小棧應可執行 publish_case public_posting");
    assert_equal("COMPLETED", qe->query_quest_state(p, "v2_six_county_evidence"),
                 "當街張榜後 v2_six_county_evidence 應完成");
    assert_equal("public_posting", p->query("quests/v2_six_county_evidence/choices/step_7"),
                 "玩家分支選擇應記錄於 quests/<qid>/choices/step_7");
    assert_true(mapp(rd->query_region_crisis("jinshi", "black_market_speculation")),
                "張榜逼迫攤牌應於 jinshi 觸發 black_market_speculation 危機");
    assert_equal(js_pref_0 + 6, rd->query_faction_power("jinshi", "prefect_office"),
                 "張榜應提升金石府衙勢力 6 點");
    assert_equal(js_chmb_0 - 8, rd->query_faction_power("jinshi", "chamber_of_commerce"),
                 "張榜應削弱商會私股勢力 8 點");

    // ── 2. v2_act4_tripartite_tribunal：常平倉賑濟抉擇 + 案牘庫火漆 + 三印抄沒平息危機 ──
    object granary = load_object("/d/city/center/granary.c");
    object archive = load_object("/d/city/center/yamen_archive.c");
    object yamen   = load_object("/d/city/center/yamen.c");
    assert_true(objectp(granary) && objectp(archive) && objectp(yamen), "常平倉、案牘庫與府衙正堂必須載入");

    int grain_before = rd->query_region_reserves("jinshi", "grain_granary");
    int price_before = rd->query_region_price_index("jinshi");

    move_object(p, load_object("/d/city/center/pawnshop.c"));
    qe->trigger_event(p, "talk", ([ "npc": "pawnshop_jiachaofeng", "topic": "成色" ]));
    move_object(p, granary);
    assert_equal(1, p->command("allocate work_relief"), "常平倉應可執行 allocate work_relief");
    assert_equal(3, qe->query_quest_step(p, "v2_act4_tripartite_tribunal"), "賑濟抉擇後應推進至 step 3");
    assert_equal(grain_before - 400, rd->query_region_reserves("jinshi", "grain_granary"),
                 "平糶放糧應使金石官倉糧儲減少 400");
    assert_equal(price_before - 6, rd->query_region_price_index("jinshi"),
                 "平糶放糧應立即壓低物價指數 6 點");

    move_object(p, load_object("/d/city/center/clinic.c"));
    qe->trigger_event(p, "talk", ([ "npc": "clinic_baixiansheng", "topic": "苦參" ]));
    move_object(p, forge);
    qe->trigger_event(p, "talk", ([ "npc": "gong_forge_mochui", "topic": "金剛砂" ]));
    move_object(p, load_object("/d/city/north/gong_fireworks.c"));
    qe->trigger_event(p, "talk", ([ "npc": "gong_fireworks_master", "topic": "存根" ]));

    move_object(p, archive);
    assert_equal(1, p->command("seal deed"), "案牘庫應可執行 seal deed 火漆封印正底單");
    assert_equal(7, qe->query_quest_step(p, "v2_act4_tripartite_tribunal"), "封印正底單後應達 step 7");

    move_object(p, yamen);
    assert_equal(1, p->command("adjudicate seize_assets"), "府衙正堂應可執行 adjudicate seize_assets");
    assert_equal("COMPLETED", qe->query_quest_state(p, "v2_act4_tripartite_tribunal"),
                 "三印裁決落槌後應完成 v2_act4_tripartite_tribunal");
    assert_equal(0, mapp(rd->query_region_crisis("jinshi", "black_market_speculation")),
                 "三印抄沒補倉應解除 jinshi 的 black_market_speculation 危機");

    // ── 3. v3_yuntu_market_charter：泥途立帳 + 雲海票號分批賠償抉擇 ──
    object office  = load_object("/d/yunjin/public_office.c");
    object mudway  = load_object("/d/yunjin/mudway_store.c");
    object exch    = load_object("/d/yunjin/exchange_hall.c");
    assert_true(objectp(office) && objectp(mudway) && objectp(exch), "雲津三間主商貿房間必須載入");

    int yj_mud_0    = rd->query_faction_power("yunjin", "yunjin_mudway_merchant");
    int yj_timber_0 = rd->query_region_reserves("yunjin", "timber");

    move_object(p, office);
    qe->trigger_event(p, "talk", ([ "npc": "luo_jiucheng", "topic": "商棧登記" ]));
    qe->trigger_event(p, "talk", ([ "npc": "luo_jiucheng", "topic": "租約" ]));

    move_object(p, mudway);
    assert_equal(1, p->command("establish ledger"), "泥途總號應可執行 establish ledger");
    assert_equal(3, qe->query_quest_step(p, "v3_yuntu_market_charter"), "立帳後應推進至 step 3");

    move_object(p, exch);
    assert_equal(1, p->command("settle split_indemnity"), "交割廳應可執行 settle split_indemnity");
    assert_equal("COMPLETED", qe->query_quest_state(p, "v3_yuntu_market_charter"),
                 "分批賠付後應完成 v3_yuntu_market_charter");
    assert_equal(yj_mud_0 + 10, rd->query_faction_power("yunjin", "yunjin_mudway_merchant"),
                 "傾囊履約應提升泥途商盟聲望 10 點");
    assert_equal(yj_timber_0 + 120, rd->query_region_reserves("yunjin", "timber"),
                 "穩住寒地貨源應增加雲津木材儲備 120");

    // ── 4. v4_act3_labor_pact_stations 與 v3_bahuang_bloodline_watch ──
    object em = load_object(EVENT_MANAGER_D);
    if (em) {
        em->set_test_mode(1);
        em->set_event_stage(EVENT_TIER3_CALIBRATION, STAGE_TIER3_T_MINUS_2, 1);
    }
    object scrap = load_object("/d/realm/wanwu/scrap_ring.c");
    object watch = load_object("/d/sects/bahuang/north_watch.c");
    assert_true(objectp(scrap) && objectp(watch), "萬物外環與北荒巡哨營必須載入");

    int ww_art_0 = rd->query_faction_power("realm_wanwu", "wanwu_scrap_ring_artisans");
    rd->set_region_crisis("realm_wanwu", "salt_levy_embezzlement", 1, ([ "source": "test" ]));

    move_object(p, scrap);
    qe->trigger_event(p, "talk", ([ "npc": "wanwu_auditor_qi", "topic": "停工" ]));
    assert_equal(1, p->command("audit_stations stockpile_bypass"), "萬物外環應可執行 audit_stations stockpile_bypass");
    assert_equal("COMPLETED", qe->query_quest_state(p, "v4_act3_labor_pact_stations"),
                 "分倉應對稽查後應完成 v4_act3_labor_pact_stations");
    assert_equal(ww_art_0 + 10, rd->query_faction_power("realm_wanwu", "wanwu_scrap_ring_artisans"),
                 "分倉保料應提升外環匠師團結度 10 點");
    assert_equal(0, mapp(rd->query_region_crisis("realm_wanwu", "salt_levy_embezzlement")),
                 "截留鹽稅回流應解除 salt_levy_embezzlement 危機");

    int bh_gar_0 = rd->query_faction_power("bahuang", "bahuang_wall_garrison");
    object camp = load_object("/d/sects/bahuang/black_mountain_camp.c");
    object rest_hall = load_object("/d/sects/bahuang/restoration_hall.c");
    move_object(p, camp);
    qe->trigger_event(p, "talk", ([ "npc": "lei_lie", "topic": "巡防" ]));
    move_object(p, rest_hall);
    qe->trigger_event(p, "talk", ([ "npc": "du_qinghe", "topic": "傷兵" ]));
    move_object(p, camp);
    qe->trigger_event(p, "talk", ([ "npc": "lei_lie", "topic": "藥丸" ]));
    move_object(p, watch);
    assert_equal(1, p->command("stake ice_rift"), "北荒巡哨營應可執行 stake ice_rift");
    assert_equal("COMPLETED", qe->query_quest_state(p, "v3_bahuang_bloodline_watch"),
                 "打設測冰鐵簽後應完成 v3_bahuang_bloodline_watch");
    assert_equal(bh_gar_0 + 6, rd->query_faction_power("bahuang", "bahuang_wall_garrison"),
                 "巡哨實測應提升八荒防線駐軍勢力 6 點");

    foreach (object inv in all_inventory(p)) {
        if (inv) destruct(inv);
    }
    destruct(p);
    rd->reset_regions();
}
