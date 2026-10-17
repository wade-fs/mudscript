// /tests/test_event_manager.c
// Phase 0: 世界事件守護進程 (Event Manager Daemon) 單元測試
// 驗證項目：
// 1. 守護進程載入與預設狀態矩陣 (6+4 變數)
// 2. 雙階段 T-Clock 時間軸推進與邊界保護
// 3. 指標讀寫、增量加算與邊界限制 (Metrics Clamping)
// 4. 單向數據流：任務成果提交 -> 更新指標 -> 更新客觀事實
// 5. 物證帳本 (Evidence Ledger)：登錄、過目標記、關鍵官員核驗連動
// 6. 動態因果評估器：大荒煞潮偏折率與金石官道衝毀連動
// 7. 動態因果評估器：黑石關軍事危機 5 大非二元結局組合運算
// 8. 重置 (reset_event) 與狀態重現

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/world_event.h"

void run_tests(object me) {
    start_test("Phase 0: 底層狀態機與全域事件引擎骨架驗證");

    object em = load_object(EVENT_MANAGER_D);
    assert_true(objectp(em), "事件守護進程 (EVENT_MANAGER_D) 必須成功載入");

    // 重置為乾淨的初始狀態
    em->reset_event("all");

    // ── 1. 驗證大荒煞潮初始狀態矩陣 ───────────────────────────
    assert_equal(STAGE_BEAST_T_MINUS_3, em->query_event_stage(EVENT_BEAST_SURGE), "煞潮初始階段應為 T-3");
    assert_equal(3, em->query_metric(EVENT_BEAST_SURGE, METRIC_HERD_PRESSURE), "初始 herd_pressure 應為 3");
    assert_equal(0, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "初始 route_confidence 應為 0");
    assert_equal(0, em->query_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT), "初始 diversion_effect 應為 0");
    assert_equal(4, em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY), "初始 settlement_capacity 應為 4");
    assert_equal(0, em->query_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH), "初始 evidence_strength 應為 0");
    assert_equal(2, em->query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST), "初始 civilian_trust 應為 2");

    // ── 2. 驗證軍事危機初始狀態矩陣 ───────────────────────────
    assert_equal(STAGE_MILITARY_STANDBY, em->query_event_stage(EVENT_MILITARY_CRISIS), "軍事危機初始階段應為 standby");
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "初始 intel_confidence 應為 3");
    assert_equal(0, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "初始 evidence_verifiability 應為 0");
    assert_equal(1, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST), "初始 assault_cost 應為 1");
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE), "初始 settlement_resilience 應為 2");

    // ── 3. 驗證 T-Clock 時間軸推進 ────────────────────────────
    assert_equal("T-2", em->advance_event_stage(EVENT_BEAST_SURGE), "煞潮推進應至 T-2");
    assert_equal("T-1", em->advance_event_stage(EVENT_BEAST_SURGE), "煞潮推進應至 T-1");
    assert_equal("T0",  em->advance_event_stage(EVENT_BEAST_SURGE), "煞潮推進應至 T0");
    assert_equal("T+1", em->advance_event_stage(EVENT_BEAST_SURGE), "煞潮推進應至 T+1");
    assert_equal("T+2", em->advance_event_stage(EVENT_BEAST_SURGE), "煞潮推進應至 T+2");
    assert_equal("T+2", em->advance_event_stage(EVENT_BEAST_SURGE), "煞潮至終點後不應越界超出 T+2");

    // 不合法階段設定應被拒絕
    assert_equal(0, em->set_event_stage(EVENT_BEAST_SURGE, "INVALID_STAGE"), "設定不合法階段應回傳 0");
    assert_equal(1, em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_MINUS_3), "回調至 T-3 應成功");

    // ── 4. 驗證數值指標上下限鉗位 (Clamping) ───────────────────
    // route_confidence 上限為 3
    em->set_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE, 100);
    assert_equal(3, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "route_confidence 超出上限應被鉗位在 3");

    // civilian_trust 下限為 0
    em->set_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST, -50);
    assert_equal(0, em->query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST), "civilian_trust 低於下限應被鉗位在 0");

    // add_metric 邊界增量
    em->set_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST, 2);
    em->add_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST, 5);
    assert_equal(3, em->query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST), "add_metric 超額增加應正確鉗位在 3");

    // ── 5. 驗證單向數據流：任務成果結算 (apply_quest_outcome) ─
    em->reset_event(EVENT_BEAST_SURGE);
    mapping outcome_a01 = ([
        "status": "success",
        "deltas": ([
            METRIC_EVIDENCE_STRENGTH: 1,
            METRIC_ROUTE_CONFIDENCE: 1
        ]),
        "facts": ([
            "autopsy_performed": 1,
            "sulfur_poisoning_found": 1
        ]),
        "message": "顧玄完成了黃羊解剖，確認死因非外傷撕咬，乃地煞硫磺急毒窒息！"
    ]);

    mapping rec1 = em->apply_quest_outcome(EVENT_BEAST_SURGE, "A01_dead_yellow_sheep", outcome_a01);
    assert_equal("success", rec1["status"], "任務結算狀態應記錄為 success");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH), "A01 完成後 evidence_strength 應增加為 1");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "A01 完成後 route_confidence 應增加為 1");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "autopsy_performed"), "事實 autopsy_performed 應被標記為 1");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "sulfur_poisoning_found"), "事實 sulfur_poisoning_found 應被標記為 1");

    // 驗證任務查詢
    mapping q_rec = em->query_quest_outcome(EVENT_BEAST_SURGE, "A01_dead_yellow_sheep");
    assert_equal("A01_dead_yellow_sheep", q_rec["quest_id"], "任務記錄應能準確查出");

    // ── 6. 驗證物證帳本 (Evidence Ledger) 與官員檢驗 ──────────
    em->reset_event(EVENT_MILITARY_CRISIS);
    mapping ev_crucible = ([
        "name": "刻有商會暗記之精煉坩堝",
        "desc": "在私逃富商覆車殘骸中起獲的走私坩堝，殘留地煞血精微塵",
        "strength": 2,
        "source": "商隊車隊殘骸"
    ]);

    em->register_evidence("ev_crucible", ev_crucible);
    mapping q_ev = em->query_evidence("ev_crucible");
    assert_equal("ev_crucible", q_ev["id"], "物證應成功登錄於帳本中");
    assert_equal(0, em->is_evidence_seen_by("ev_crucible", "commander"), "初始先鋒主帥不應看過此證物");

    // 當先鋒主帥檢驗物證
    int seen_res = em->mark_evidence_seen("ev_crucible", "commander");
    assert_equal(1, seen_res, "標記主帥檢驗物證應成功");
    assert_equal(1, em->is_evidence_seen_by("ev_crucible", "commander"), "此時主帥應在看過名單中");

    // 主帥過目後，軍方情報自信心動搖 (-1)，證據核驗度上升 (+1)
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "主帥驗證後 intel_confidence 應降為 2");
    assert_equal(1, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "主帥驗證後 evidence_verifiability 應升為 1");

    // ── 7. 驗證大荒煞潮因果評估與官道破壞連動 ────────────────
    em->reset_event("all");
    // 預設無工程：主力直衝黑石鋪
    mapping eval_no_eng = em->evaluate_beast_surge();
    assert_equal("village_impact", eval_no_eng["main_herd_route"], "無工程時主力路線應為 village_impact");
    assert_equal(0, eval_no_eng["canyon_road_destruction"], "無改道時落龍澗下泄官道未受損");

    // 模擬成功完成導流工程 (diversion=2, confidence=2)
    em->set_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT, 2);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE, 2);
    mapping eval_diverted = em->evaluate_beast_surge();
    assert_equal("canyon", eval_diverted["main_herd_route"], "高工程與精確勘測時主力路線應偏折入落龍澗 (canyon)");
    assert_equal(2, eval_diverted["canyon_road_destruction"], "下泄萬獸狂潮應徹底衝斷金石官道 (destruction=2)");

    // 驗證煞潮因果自動回饋至軍事危機：官道被衝毀，大軍強攻成本自動上升
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST), "山道被獸潮衝斷後，軍事危機 assault_cost 應自動激增至 3");

    // ── 8. 驗證軍事危機 5 大非二元結局推演 ────────────────────
    // 測試結局 B：強攻成本過高且未流血 -> 有限封鎖，局部妥協
    mapping ending_b = em->evaluate_military_crisis();
    assert_equal(ENDING_B_LIMITED_BLOCKADE, ending_b["ending_code"], "強攻成本過高時應收斂至結局 B (有限封鎖)");

    // 測試結局 A：情報動搖 (<=1) + 物證核驗度高 (>=2) + 證人存活 -> 正式調查
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE, 1);
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY, 2);
    em->set_fact(EVENT_MILITARY_CRISIS, "witnesses_intact", 1);
    mapping ending_a = em->evaluate_military_crisis();
    assert_equal(ENDING_A_FORMAL_INVESTIGATION, ending_a["ending_code"], "證據確鑿且情報動搖時應收斂至最佳結局 A (暫停進攻，正式調查)");

    // 測試結局 D：發生不可逆流血事件 -> 局部衝突
    em->set_fact(EVENT_MILITARY_CRISIS, "blood_drawn", 1);
    mapping ending_d = em->evaluate_military_crisis();
    assert_equal(ENDING_D_LOCAL_SKIRMISH, ending_d["ending_code"], "發生流血事件時應收斂至結局 D (局部衝突)");

    // ── 9. 驗證儀表板 Dump 輸出 ───────────────────────────────
    string dump_str = em->dump_status(EVENT_BEAST_SURGE);
    assert_true(strlen(dump_str) > 100, "狀態儀表板輸出長度應大於 100 字元");

    report_results();
}
