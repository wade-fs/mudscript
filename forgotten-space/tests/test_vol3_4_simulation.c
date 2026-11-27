// /tests/test_vol3_4_simulation.c
// 第三、四卷（名山問道、北荒、雲津與桃花源三極）世界模擬架構整合測試
// 驗證項目：
// 1. 10 個第三～四卷 Region JSON、17 個對應 Zone JSON 與 4 個關鍵 Site 載入與 schema_version/LOCAL_GAME_SPACE 檢核
// 2. 靜態定義與動態狀態分離：crisis_deck 抽卡觸發、勢力權重 adjust_faction_power 鉗制、不污染靜態 Region 定義
// 3. PHASE_D 第三、四卷事件相位（tier2_crisis / crystal_quarantine / tier3_calibration / wanwu_strike）與 NPC 動態排程移防
// 4. EVENT_MANAGER_D（EVENT_TIER2_CRISIS & EVENT_TIER3_CALIBRATION）推進顯式同步 REGION_D 危機牌組與 PHASE_D 相位，並支援週期重置清理
// 5. WORLD_STATE_D 寒潮與校準經濟聯動 + QUEST_ENGINE_D 卷幕/區域危機加成檢核

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/region.h"
#include "/include/world_event.h"

void run_tests(object me) {
    start_test("第三～四卷世界模擬引擎接軌驗證 (REGION_D / PHASE_D / EVENT_MANAGER_D / WORLD_STATE_D)");

    object rd = load_object(REGION_D);
    object pd = load_object(PHASE_D);
    object em = load_object(EVENT_MANAGER_D);
    object ws = load_object(WORLD_STATE_D);
    object qe = load_object(QUEST_ENGINE_D);

    assert_true(objectp(rd) && objectp(pd) && objectp(em) && objectp(ws) && objectp(qe),
                "五大世界模擬核心守護進程必須成功載入");

    rd->set_test_mode(1);
    pd->set_test_mode(1);
    em->set_test_mode(1);
    rd->reset_regions();
    em->reset_event("all");

    // ── 1. 10 個第三～四卷 Region 與 Zone / Site 載入驗證 ──────────────
    string *vol3_4_regions = ({
        "yunjin", "taiqing", "bahuang", "tiangong", "danding", "wastes",
        "realm_edge", "realm_taixu", "realm_wanwu", "realm_zhanzu"
    });
    mapping all_regs = rd->query_all_regions();
    assert_true(mapp(all_regs) && sizeof(all_regs) >= 19, "REGION_D 總計應至少載入 19 個區域定義 (Vol.1-4)");

    foreach (string rid in vol3_4_regions) {
        mapping rdef = rd->query_region_def(rid);
        assert_true(mapp(rdef), "區域定義必須存在: " + rid);
        if (rdef) {
            assert_equal("1.1", rdef["schema_version"], rid + " schema_version 應為 1.1");
            assert_true(mapp(rdef["geography"]) && rdef["geography"]["position"] == 0,
                        rid + " geography.position 應為 null (LOCAL_GAME_SPACE)");
            assert_equal("CONFIRMED", rdef["confidence"], rid + " confidence 應為 CONFIRMED");
            assert_true(mapp(rdef["factions"]) && sizeof(rdef["factions"]) >= 2,
                        rid + " 必須包含至少 2 個 factions");
            mixed *deck = rd->query_crisis_deck(rid);
            assert_true(pointerp(deck) && sizeof(deck) >= 3,
                        rid + " crisis_deck 必須包含 3~5 張危機牌組");
            string *zones = rd->query_zones_by_region(rid);
            assert_true(pointerp(zones) && sizeof(zones) >= 1,
                        rid + " 必須至少對應 1 個 Zone JSON");
        }
    }

    assert_true(mapp(rd->query_site("taiqing_ark_portal")), "太清祖庭星門 Site 必須載入");
    assert_true(mapp(rd->query_site("wastes_ark_core")), "北荒方舟核心室 Site 必須載入");
    assert_true(mapp(rd->query_site("realm_edge_beacon_relay")), "三息微光信標台 Site 必須載入");
    assert_true(mapp(rd->query_site("realm_wanwu_conduit_well")), "萬物總線匯流井 Site 必須載入");

    // ── 2. crisis_deck 觸發與勢力權重動態狀態分離檢核 ─────────────────
    int p_before = rd->query_faction_power("realm_wanwu", "wanwu_scrap_ring_artisans");
    assert_equal(35, p_before, "萬物外環匠師初始勢力應為 35");
    assert_equal(50, rd->adjust_faction_power("realm_wanwu", "wanwu_scrap_ring_artisans", 15),
                 "調整勢力後動態狀態應升為 50");
    // 靜態定義不可被動態修改污染
    mapping static_ww = rd->query_region_def("realm_wanwu");
    assert_equal(35, static_ww["factions"]["wanwu_scrap_ring_artisans"]["power"],
                 "靜態定義池 faction power 絕不得被動態狀態竄改");

    string drawn = rd->trigger_crisis_from_deck("yunjin", "herd_pressure", ([ "price_shock": 20 ]));
    assert_equal("crystal_poison_quarantine", drawn, "雲津依 herd_pressure 應抽出殘晶隔離危機");
    assert_true(mapp(rd->query_region_crisis("yunjin", "crystal_poison_quarantine")),
                "抽出的危機應登記於 active_crises");
    assert_equal(120, rd->query_region_price_index("yunjin"), "危機溢價後雲津物價指數應升至 120");

    // ── 3. PHASE_D 第三、四卷事件相位與 NPC 排程移防 ──────────────────
    string *v34_npcs = ({
        "qiu_he", "lei_lie", "han_su",
        "ash_warden_qi", "stone_clinic_healer_su", "wanwu_auditor_qi"
    });
    foreach (string nkey in v34_npcs) {
        assert_true(mapp(pd->query_npc_schedule(nkey)), "PHASE_D 必須已註冊 NPC 作息: " + nkey);
    }

    pd->set_event_phase("wanwu_strike", 1);
    assert_equal("/d/realm/wanwu/arbitration_bridge.c",
                 pd->query_npc_target_room("wanwu_auditor_qi", "morning"),
                 "wanwu_strike 相位啟動時齊叔應移往彩虹仲裁橋");
    pd->set_event_phase("wanwu_strike", 0);
    assert_equal("/d/realm/wanwu/scrap_ring.c",
                 pd->query_npc_target_room("wanwu_auditor_qi", "morning"),
                 "wanwu_strike 相位解除後齊叔應回歸萬物外環");

    object post_room = load_object("/d/realm/edge/ash_watch_post.c");
    assert_true(objectp(post_room) && strsrch(pd->query_room_rhythm_line(post_room), "洞天法則阻尼") != -1,
                "洞天房間時辰風物應輸出 12:1 時差與法則阻尼提示");

    // ── 4. EVENT_MANAGER_D -> REGION_D / PHASE_D 顯式聯動 ─────────────
    rd->reset_regions();
    em->set_event_stage(EVENT_TIER3_CALIBRATION, STAGE_TIER3_T_0, 0);
    assert_equal(1, pd->query_event_phase("tier3_calibration"), "T0 階段 PHASE_D tier3_calibration 應為 1");
    assert_equal(1, pd->query_event_phase("wanwu_strike"), "T0 階段 PHASE_D wanwu_strike 應為 1");
    assert_true(mapp(rd->query_region_crisis("realm_taixu", "sky_net_over_calibration")),
                "T-1/T0 推進應觸發太虛天羅過載危機");
    assert_true(mapp(rd->query_region_crisis("realm_wanwu", "scrap_ring_general_strike")),
                "T0 推進應觸發萬物外環停工危機");
    assert_true(mapp(rd->query_region_crisis("realm_zhanzu", "bone_gate_beast_stampede")),
                "T0 推進應觸發戰祖巨骨哨卡獸潮危機");

    // 達成五線校準結局並推進至 T+2，危機應獲解決且派系勢力重組
    em->apply_quest_outcome(EVENT_TIER3_CALIBRATION, "v4_sim_labor", ([
        "status": "success", "deltas": ([ METRIC_LABOR_SOLIDARITY: 4 ]), "facts": ([ "strike_executed": 1 ])
    ]), "sim_tester");
    em->apply_quest_outcome(EVENT_TIER3_CALIBRATION, "v4_sim_array", ([
        "status": "success", "deltas": ([ METRIC_ARRAY_DEFLECTION: 4 ]), "facts": ([ "array_shifted_1_5_deg": 1 ])
    ]), "sim_tester");
    em->apply_quest_outcome(EVENT_TIER3_CALIBRATION, "v4_sim_defense", ([
        "status": "success", "deltas": ([ METRIC_OUTPOST_DEFENSE: 4 ]), "facts": ([ "arena_yanshan_rescued": 1 ])
    ]), "sim_tester");
    em->apply_quest_outcome(EVENT_TIER3_CALIBRATION, "v4_sim_charter", ([
        "status": "success", "deltas": ([ METRIC_CHARTER_LEGITIMACY: 4, METRIC_BEACON_READINESS: 3 ]), "facts": ([ "charter_equalized": 1 ])
    ]), "sim_tester");

    em->set_event_stage(EVENT_TIER3_CALIBRATION, STAGE_TIER3_T_PLUS_2, 0);
    assert_true(!mapp(rd->query_region_crisis("realm_wanwu", "scrap_ring_general_strike")),
                "blocked_and_equalized 結算至 T+2 後外環停工危機應已解除");
    assert_equal(0, pd->query_event_phase("wanwu_strike"), "T+2 結算後 wanwu_strike 相位應清零");

    // 驗證 QUEST_ENGINE_D apply_region_effects 與卷幕獎勵倍率
    qe->apply_region_effects(([
        "region": "realm_edge",
        "faction_deltas": ([ "ash_bastion_council": 5 ]),
        "reserve_deltas": ([ "salt_crystal_jin": 100 ])
    ]), "realm_edge", "sim_test_quest");
    assert_true(rd->query_faction_power("realm_edge", "ash_bastion_council") >= 60,
                "QUEST_ENGINE_D apply_region_effects 應提升石堡自治議會勢力");

    mapping q_t3 = qe->query_quest("v4_act4_labor_strike_sanction");
    em->set_event_stage(EVENT_TIER3_CALIBRATION, STAGE_TIER3_T_0, 1);
    assert_equal(125, qe->query_act_reward_pct(q_t3), "Tier 3 校準 T0 高峰期應提供 125% 任務動態加成");

    // 驗證 WORLD_STATE_D 寒潮經濟聯動與快照輸出
    ws->sync_vol3_4_region_economy("winter", "snowy");
    assert_true(mapp(rd->query_region_crisis("wastes", "northern_cold_snap")),
                "寒潮同步應觸發北荒 REGION_D 寒潮危機");
    mapping snap = ws->query_vol3_4_simulation_snapshot();
    assert_true(mapp(snap) && mapp(snap["realm_wanwu"]) && mapp(snap["yunjin"]),
                "WORLD_STATE_D 應可產出第三、四卷十區模擬狀態快照");

    // 乾淨重置
    em->cycle_tier3_calibration();
    em->reset_event("all");
    pd->set_event_phase("tier2_crisis", 0);
    pd->set_event_phase("crystal_quarantine", 0);
    pd->set_event_phase("tier3_calibration", 0);
    pd->set_event_phase("wanwu_strike", 0);
    rd->reset_regions();
    rd->set_test_mode(0);
    pd->set_test_mode(0);
    em->set_test_mode(0);
}
