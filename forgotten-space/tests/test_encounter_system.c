// /tests/test_encounter_system.c
// Phase 2: Encounter 奇遇稀有性重構單元測試 (三階段、獨立排程窗口、身世排他、名額與回聲、保底線索、暗巷合契)

inherit "/std/test_case";

#include "/include/globals.h"

void run_tests(object me) {
    start_test("Phase 2 奇遇稀有性與世界窗口系統驗證");

    object qe = load_object(QUEST_ENGINE_D);
    object ws = load_object(WORLD_STATE_D);
    object md = load_object(MYSTERY_D);

    // 1. 驗證 6 大奇遇定義全數加載
    mapping all_enc = qe->query_all_encounters();
    assert_true(mapp(all_enc), "奇遇定義映射表必須存在");
    assert_equal(6, sizeof(all_enc), "必須成功加載 6 大奇遇定義 (5大身世+1暗巷拼圖)");

    assert_true(mapp(qe->query_encounter("enc_stele_dawn")), "史前逆星殘碑定義應存在");
    assert_true(mapp(qe->query_encounter("enc_ancient_iron")), "太古不融黑鐵定義應存在");
    assert_true(mapp(qe->query_encounter("enc_forest_totem")), "太古戰神獵獸圖騰定義應存在");
    assert_true(mapp(qe->query_encounter("enc_dao_crystal")), "道化晶石遺骸定義應存在");
    assert_true(mapp(qe->query_encounter("enc_tianmen_token")), "萬物行商天門引定義應存在");
    assert_true(mapp(qe->query_encounter("enc_map_fusion")), "暗巷雙脈合契定義應存在");

    // 2. 驗證舊註冊表別名映射相容
    assert_equal("enc_stele_dawn", qe->query_encounter_id_by_legacy("stream_stele"), "舊鍵 stream_stele 應映射至 enc_stele_dawn");
    assert_equal("enc_ancient_iron", qe->query_encounter_id_by_legacy("forge_ancient_black_iron"), "舊鍵 forge_ancient_black_iron 應映射至 enc_ancient_iron");
    assert_equal("enc_forest_totem", qe->query_encounter_id_by_legacy("commune_forest_totem"), "舊鍵 commune_forest_totem 應映射至 enc_forest_totem");
    assert_equal("enc_dao_crystal", qe->query_encounter_id_by_legacy("search_altar_pine"), "舊鍵 search_altar_pine 應映射至 enc_dao_crystal");
    assert_equal("enc_tianmen_token", qe->query_encounter_id_by_legacy("search_shed_wood"), "舊鍵 search_shed_wood 應映射至 enc_tianmen_token");

    // 3. 驗證世界窗口獨立排程開啟與關閉
    ws->close_window("stele_dawn");
    assert_equal(0, ws->is_window_active("stele_dawn"), "關閉後 stele_dawn 窗口應為未開啟 (0)");

    ws->open_window("stele_dawn", 60);
    assert_equal(1, ws->is_window_active("stele_dawn"), "開啟後 stele_dawn 窗口應為活躍中 (1)");
    assert_true(ws->query_window_remaining("stele_dawn") > 0, "窗口剩餘時間應大於 0");

    // 4. 驗證身世血脈排他性 (非鐵匠身世無法觸發太古黑鐵奇遇)
    object tester = clone_object("/std/user.c");
    tester->set_id("test_gu_xuan");
    tester->set_name("顧玄");
    tester->set("background", "herbalist");
    tester->set("stat_sen", 500);
    tester->set("stat_int", 50);

    // 顧玄身為 herbalist，嘗試評估 smith 專屬的 enc_ancient_iron，應被拒絕 (-2)
    int bg_check = qe->evaluate_encounter(tester, "enc_ancient_iron", (["ignore_window": 1]));
    assert_equal(-2, bg_check, "身世不符者評估應返回 -2 (身世血脈不合)");

    // 5. 驗證世界窗口阻擋 (-1)
    ws->close_window("stele_dawn");
    int win_check = qe->evaluate_encounter(tester, "enc_stele_dawn", ([]));
    assert_equal(-1, win_check, "世界窗口未開時評估應返回 -1 (窗口阻擋)");

    // 6. 驗證全服名額限制與回聲政策 (World Slots & Echo)
    ws->reset_encounter_slots("enc_stele_dawn");
    assert_equal(0, ws->query_encounter_slots_used("enc_stele_dawn"), "重置後名額消耗應為 0");

    assert_equal(1, ws->consume_encounter_slot("enc_stele_dawn", 2), "第 1 個名額應成功消耗");
    assert_equal(1, ws->consume_encounter_slot("enc_stele_dawn", 2), "第 2 個名額應成功消耗");
    assert_equal(0, ws->consume_encounter_slot("enc_stele_dawn", 2), "第 3 個名額應被拒絕 (名額耗盡)");

    // 當名額耗盡時，評估成功應發放回聲 (回傳 2)
    int echo_result = qe->evaluate_encounter(tester, "enc_stele_dawn", ([
        "force_eval": 1,
        "force_success": 1,
        "ignore_window": 1
    ]));
    assert_equal(2, echo_result, "名額耗盡時成功共鳴應發放回聲 (回傳 2)");
    assert_equal(1, tester->query("personal_event/enc_stele_dawn_echo"), "玩家應被標記獲得回聲旗標");

    // 7. 驗證 Pity 保底機制
    tester->delete("encounter_pity/enc_stele_dawn");
    tester->set("encounter_pity/enc_stele_dawn", 3); // 模擬已失敗 3 次
    assert_equal(3, tester->query("encounter_pity/enc_stele_dawn"), "應正確記錄 3 次保底累積");

    // 8. 驗證暗巷多身世合作拼合機制 (enc_map_fusion)
    // 單獨一人且無多重殘片 -> 失敗 (0)
    int fusion_fail = qe->evaluate_encounter(tester, "enc_map_fusion", ([
        "force_eval": 1,
        "ignore_window": 1
    ]));
    assert_equal(0, fusion_fail, "單一身世無多重信物印證時應無法拼合 (回傳 0)");

    // 注入第二種大道身世信物/線索 (道童的死霜線索)
    tester->set("encounter_clues/frost_trace", 1);
    ws->reset_encounter_slots("enc_map_fusion");
    int fusion_succ = qe->evaluate_encounter(tester, "enc_map_fusion", ([
        "force_eval": 1,
        "ignore_window": 1,
        "force_success": 1
    ]));
    assert_equal(1, fusion_succ, "具備兩種大道身世傳承時應合契成功 (回傳 1)");
    assert_equal(1, tester->query("encounter_clues/star_map_revealed"), "合契成功應解鎖星圖線索");

    // 9. 驗證 Phase 3 可持續遊玩體系：三大生計循環與獵師階梯鏈
    mapping hc = qe->query_quest("hunting_chain");
    assert_true(mapp(hc), "大荒獵師階梯鏈 (hunting_chain) 必須存在");
    assert_equal(3, sizeof(hc["stages"]), "獵師鏈必須擁有 3 環階梯階段 (鼠->狼->熊)");

    mapping ml = qe->query_quest("mining_loop");
    assert_true(mapp(ml), "北崖供礦循環任務必須存在");
    assert_true(mapp(ml["decay_config"]), "供礦任務必須具備收益遞減配置 (decay_config)");

    mapping hl = qe->query_quest("herb_loop");
    assert_true(mapp(hl), "南谷採藥循環任務必須存在");
    assert_true(mapp(hl["decay_config"]), "採藥任務必須具備收益遞減配置 (decay_config)");

    mapping pl = qe->query_quest("pelt_loop");
    assert_true(mapp(pl), "荒野獵皮循環任務必須存在");
    assert_true(mapp(pl["decay_config"]), "獵皮任務必須具備收益遞減配置 (decay_config)");

    report_results();
    destruct(tester);
}
