// /tests/test_event_manager.c
// Phase 0: 世界事件守護進程 (Event Manager Daemon) 嚴格架構單元測試
// 驗證項目：
// 1. 資料驅動載入 (JSON Schema) 與未註冊幽靈指標嚴格拒絕
// 2. 評估器純函式特性（只讀無副作用，看儀表板絕對不竄改軍事指標）
// 3. 顯式跨事件傳播 (propagate_beast_to_military)
// 4. 事務性與冪等結算 (Transactional & Idempotent Outcome)
// 5. 物證帳本多來源獨立驗證 (多物證加權，杜絕單證解鎖 Ending A)
// 6. 完備因果閉環：煞潮 6 大指標實質影響，軍事 5 大結局消除自相矛盾空間
// 7. T-Clock 單調推進防護與時間推進代價 (Time-Cost Decay)
// 8. 發布/訂閱事件匯流排 (Pub/Sub Event Bus) 回調驗證
// 9. 測試模式防護與乾淨重置 (Clean Reset)

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/world_event.h"

int pubsub_called = 0;
string pubsub_last_event = "";
string pubsub_last_type = "";

void on_event_bus_msg(string event_id, string event_type, mapping payload) {
    pubsub_called++;
    pubsub_last_event = event_id;
    pubsub_last_type = event_type;
}

void run_tests(object me) {
    start_test("Phase 0: 底層狀態機嚴格架構與純函式因果引擎驗證");

    object em = load_object(EVENT_MANAGER_D);
    assert_true(objectp(em), "事件守護進程 (EVENT_MANAGER_D) 必須成功載入");

    // 開啟測試模式 (不寫磁碟存檔，保護資料完整)
    em->set_test_mode(1);
    em->reset_event("all");

    // ── 1. 資料驅動驗證與幽靈指標嚴格拒絕 ──────────────────────
    assert_equal(1, em->is_valid_metric(EVENT_BEAST_SURGE, METRIC_HERD_PRESSURE), "已註冊指標 herd_pressure 應合法");
    assert_equal(1, em->is_valid_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "已註冊指標 intel_confidence 應合法");
    assert_equal(0, em->is_valid_metric(EVENT_BEAST_SURGE, "ghost_metric_foo"), "未註冊指標 ghost_metric_foo 應非法");

    // 1.1 資料一致性斷言：C 程式 Fallback 與磁碟 JSON Schema 的指標與事實鍵必須 100% 雙向對齊
    foreach (string eid in ({ EVENT_BEAST_SURGE, EVENT_MILITARY_CRISIS })) {
        mapping fdef = em->get_fallback_def(eid);
        mapping jdef = em->query_event_def(eid);
        foreach (string mk in keys(fdef["metrics"])) {
            assert_true(member_array(mk, keys(jdef["metrics"])) != -1, sprintf("Fallback 指標必須存在於 JSON: %s.%s", eid, mk));
        }
        foreach (string fk in keys(fdef["facts"])) {
            assert_true(member_array(fk, keys(jdef["facts"])) != -1, sprintf("Fallback 事實必須存在於 JSON: %s.%s", eid, fk));
        }
    }

    // 嚴格拒絕幽靈指標
    int ghost_res = em->set_metric(EVENT_BEAST_SURGE, "ghost_metric_foo", 5);
    assert_equal(-999, ghost_res, "設定未註冊指標必須被拒絕並回傳 -999");
    assert_equal(-999, em->query_metric(EVENT_BEAST_SURGE, "ghost_metric_foo"), "查詢未註冊指標應回傳 -999，絕不產生幽靈變數");

    // ── 2. 評估器純函式特性驗證（看儀表板無副作用） ────────────
    // 設定軍事危機 ASSAULT_COST 原本為 3 (例如其他任務累積)
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST, 3);
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST), "ASSAULT_COST 初始設定為 3");

    // 設定煞潮導流完成度為 1 (預期破壞為 1)
    em->set_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT, 1);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE, 1);

    // 呼叫 evaluate_beast_surge() 純評估
    mapping eval_read_only = em->evaluate_beast_surge();
    assert_equal(1, eval_read_only["canyon_road_destruction"], "純評估計算預期官道損毀等級為 1");

    // 檢視狀態儀表板 (內部會呼叫 evaluate_beast_surge)
    string dashboard = em->dump_status(EVENT_BEAST_SURGE);
    assert_true(strlen(dashboard) > 50, "儀表板字串輸出應正常");

    // 關鍵斷言：查看儀表板與純評估後，軍事危機 ASSAULT_COST 絕對不能被覆寫為 2！
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST), "評估器與儀表板必須為純函式，絕不可產生覆寫軍事指標的副作用");

    // 顯式傳播 (Explicit Propagation)：只有在顯式呼叫時才同步
    em->propagate_beast_to_military();
    // 關鍵修復斷言：若原本成本為 3，官道損毀 1 (1 + 1 = 2) 絕不允許覆寫下修，保留 max(3, 2) = 3！
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST), "顯式傳播絕不可覆寫下修既有更高強攻成本 (max 保護)");

    // 2.2 驗證 route_confidence 實質早期預警因果減損
    em->reset_event(EVENT_BEAST_SURGE);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE, 0);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT, 0);
    mapping eval_no_survey = em->evaluate_beast_surge();
    em->set_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE, 3);
    mapping eval_with_survey = em->evaluate_beast_surge();
    assert_true(eval_with_survey["surviving_capacity"] > eval_no_survey["surviving_capacity"], "掌握逃逸路徑預警應實質減少殘獸衝擊並保護聚落物資存量");

    // 驗證原本成本為預設 1 時，官道損毀 1 會正確提高成本至 2
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST, 1);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT, 1);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE, 1);
    em->propagate_beast_to_military();
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST), "成本初始為 1 時，官道損毀 1 應提高至 2");

    // 2.5 生態物證下游因果連動 (EVIDENCE_STRENGTH -> EVIDENCE_VERIFIABILITY / INTEL_CONFIDENCE)
    em->reset_event("all");
    em->set_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH, 2);
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "軍事危機初始 INTEL_CONFIDENCE 應為 3");
    assert_equal(0, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "軍事危機初始 EVIDENCE_VERIFIABILITY 應為 0");

    // 呼叫顯式傳播
    em->propagate_beast_to_military();
    mapping ev_reg = em->query_evidence("ev_beast_ecology");
    assert_true(sizeof(ev_reg) > 0, "生態物證 ev_beast_ecology 應成功登錄至軍事危機物證帳本");
    assert_equal(2, ev_reg["strength"], "生態物證強度應為 2");
    assert_equal(1, ev_reg["verified"], "生態物證應自動標記為已核驗");
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "下游 EVIDENCE_VERIFIABILITY 應增加 2");
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "下游 INTEL_CONFIDENCE 應因強度 >= 2 動搖扣減 1");

    // 再次呼叫顯式傳播，驗證冪等性 (不得重複累加)
    em->propagate_beast_to_military();
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "重複顯式傳播不得重複累加 EVIDENCE_VERIFIABILITY");
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "重複顯式傳播不得重複扣減 INTEL_CONFIDENCE");

    // 2.6 重置煞潮時自動還原傳播至軍事側之污染 (Clean Propagation Reversal)
    em->reset_event(EVENT_BEAST_SURGE);
    assert_equal(0, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "重置煞潮後軍事危機核驗度應清零還原");
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "重置煞潮後軍事危機情報信任度應還原為 3");
    assert_equal(0, sizeof(em->query_evidence("ev_beast_ecology")), "重置煞潮後生態物證應自帳本移除");

    // ── 3. T-Clock 單調推進防護、時間代價與兩軸耦合 ─────────────
    em->reset_event(EVENT_BEAST_SURGE);
    assert_equal(STAGE_BEAST_T_MINUS_3, em->query_event_stage(EVENT_BEAST_SURGE), "初始階段為 T-3");
    em->start_event(EVENT_BEAST_SURGE);
    assert_true(em->query_stage_entered_at(EVENT_BEAST_SURGE) > 0, "start_event 應成功排程並記錄 stage_entered_at");

    // 單調性：非 force 模式禁止時間倒流
    assert_equal(0, em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_MINUS_3, 0), "禁止在非強制模式下重複或倒退設定階段");

    // 推進至 T-2，驗證時間推進代價：settlement_capacity 受到衝擊扣減 1
    int cap_before = em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY);
    string next_st = em->advance_event_stage(EVENT_BEAST_SURGE);
    assert_equal(STAGE_BEAST_T_MINUS_2, next_st, "時間軸應順利推進至 T-2");
    assert_equal(cap_before - 1, em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY), "進入 T-2 時間代價應自動扣減 1 點 settlement_capacity");

    // 推進至 T-1，civilian_trust 代價扣減 1
    int trust_before = em->query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST);
    em->advance_event_stage(EVENT_BEAST_SURGE);
    assert_equal(trust_before - 1, em->query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST), "進入 T-1 時間代價應自動扣減 1 點 civilian_trust");

    // 3.1 跳階逐階補算驗證：從 T-3 一口氣推進至 T+1，中間階段時間代價全部補算
    em->reset_event("all");
    int cap_init = em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY);
    int trust_init = em->query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST);
    em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_PLUS_1, 0);
    assert_equal(STAGE_BEAST_T_PLUS_1, em->query_event_stage(EVENT_BEAST_SURGE), "跳階推進應順利抵達 T+1");
    assert_equal(cap_init - 1, em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY), "中間 T-2 時間代價必須被逐階補算扣減");
    assert_equal(trust_init - 1, em->query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST), "中間 T-1 時間代價必須被逐階補算扣減");

    // 3.5 煞潮 T+2 與軍事危機 standby -> arrival 階段耦合驗證
    em->reset_event("all");
    assert_equal(STAGE_MILITARY_STANDBY, em->query_event_stage(EVENT_MILITARY_CRISIS), "軍事危機初始應為 standby (待命蟄伏)");

    // 煞潮強制推進至 T+1
    em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_PLUS_1, 1);
    assert_equal(STAGE_MILITARY_STANDBY, em->query_event_stage(EVENT_MILITARY_CRISIS), "煞潮在 T+1 時，軍事危機仍應維持 standby");

    // 煞潮推進至 T+2 (第 31~32 章，局勢反噬・官道衝斷)
    em->advance_event_stage(EVENT_BEAST_SURGE);
    assert_equal(STAGE_BEAST_T_PLUS_2, em->query_event_stage(EVENT_BEAST_SURGE), "煞潮應推進至 T+2");
    assert_equal(STAGE_MILITARY_ARRIVAL, em->query_event_stage(EVENT_MILITARY_CRISIS), "煞潮抵達 T+2 時應自動觸發軍事時間軸前進至 arrival (先鋒扣關)");

    // ── 4. 事務性與冪等結算 (Transactional & Idempotent) ───────
    em->reset_event(EVENT_BEAST_SURGE);

    // 4.1 事務失敗 (包含非法幽靈指標，全筆 rollback)
    mapping bad_outcome = ([
        "status": "success",
        "deltas": ([
            METRIC_ROUTE_CONFIDENCE: 1,
            "non_existent_metric": 5 // 惡意或拼寫錯誤的未註冊指標
        ])
    ]);
    mapping bad_tx = em->apply_quest_outcome(EVENT_BEAST_SURGE, "bad_quest", bad_outcome, "player1");
    assert_equal(0, sizeof(bad_tx), "包含未註冊指標時整筆事務必須中止");
    assert_equal(0, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "事務中止後原本的指標絕不應被部分套用");

    // 4.1.2 事務失敗 (包含未註冊幽靈事實，全筆 rollback)
    mapping bad_fact_outcome = ([
        "status": "success",
        "facts": ([ "ghost_fact_xyz": 1 ])
    ]);
    mapping bad_fact_tx = em->apply_quest_outcome(EVENT_BEAST_SURGE, "bad_fact_quest", bad_fact_outcome, "player1");
    assert_equal(0, sizeof(bad_fact_tx), "包含未註冊事實時整筆事務必須中止");

    // 4.2 正常事務結算
    mapping good_outcome = ([
        "status": "success",
        "deltas": ([
            METRIC_EVIDENCE_STRENGTH: 1,
            METRIC_ROUTE_CONFIDENCE: 1
        ]),
        "facts": ([
            "autopsy_performed": 1
        ]),
        "message": "顧玄驗屍剖檢完成"
    ]);
    mapping rec_ok = em->apply_quest_outcome(EVENT_BEAST_SURGE, "A01_sheep", good_outcome, "player1");
    assert_equal("A01_sheep", rec_ok["quest_id"], "合法事務結算成功");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH), "指標正確增量為 1");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "指標正確增量為 1");
    assert_equal(0, rec_ok["duplicate"], "初次結算 duplicate 旗標應為 0");
    assert_equal(1, rec_ok["is_new"], "初次結算 is_new 旗標應為 1");
    assert_equal(EVENT_RESULT_SUCCESS, rec_ok["result"], "初次結算 result 應為 EVENT_RESULT_SUCCESS");

    // 4.2.1 查詢已結算成果 (支援 actor_id 專用與全域 fallback)
    mapping queried_global = em->query_applied_outcome(EVENT_BEAST_SURGE, "A01_sheep", "");
    assert_equal("A01_sheep", queried_global["quest_id"], "透過全域 quest_id 查詢結算紀錄成功");
    mapping queried_actor = em->query_applied_outcome(EVENT_BEAST_SURGE, "A01_sheep", "player1");
    assert_equal("A01_sheep", queried_actor["quest_id"], "透過 actor_id 查詢全域結算紀錄成功 fallback");

    // 4.3 冪等性防護：同一位玩家再次提交同一非重複任務
    mapping dup_rec = em->apply_quest_outcome(EVENT_BEAST_SURGE, "A01_sheep", good_outcome, "player1");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH), "重複提交時指標不得再次疊加");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "重複提交時指標不得再次疊加");
    assert_equal(1, dup_rec["duplicate"], "重複提交 duplicate 旗標應為 1");
    assert_equal(0, dup_rec["is_new"], "重複提交 is_new 旗標應為 0");
    assert_equal(EVENT_RESULT_DUPLICATE, dup_rec["result"], "重複提交 result 應為 EVENT_RESULT_DUPLICATE");

    // 4.4 任務階段限定 (Stage Gating)：逾期任務拒絕套用
    em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_0, 1);
    mapping expired_outcome = ([
        "status": "success",
        "deadline_stage": STAGE_BEAST_T_MINUS_1,
        "deltas": ([ METRIC_ROUTE_CONFIDENCE: 1 ])
    ]);
    mapping expired_tx = em->apply_quest_outcome(EVENT_BEAST_SURGE, "late_survey", expired_outcome, "player1");
    assert_equal("expired", expired_tx["status"], "逾期任務必須被拒絕套用 (拖延產生代價)");

    // ── 5. 物證帳本多來源獨立驗證與防重置 ─────────────────────
    em->reset_event(EVENT_MILITARY_CRISIS);
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "初始 intel_confidence 為 3");
    assert_equal(0, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "初始 evidence_verifiability 為 0");

    // 登錄物證 1 (來源：autopsy，強度：2)
    em->register_evidence("ev_autopsy", ([
        "name": "黃羊氣管焦黑粉塵樣本",
        "strength": 2,
        "source_type": "autopsy"
    ]));

    // 先鋒主帥初次檢驗物證 1：verifiability += 2, intel -= 1
    assert_equal(1, em->mark_evidence_seen("ev_autopsy", "commander"), "主帥初次檢驗物證 1 應成功");
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "強度 2 物證檢驗後 verifiability 應為 2");
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "intel 應降為 2");

    // 重複登錄同一物證：絕不重置 verified 與 seen_by 狀態！
    em->register_evidence("ev_autopsy", ([
        "name": "黃羊氣管焦黑粉塵樣本(二次加固)",
        "strength": 3,
        "source_type": "autopsy"
    ]));
    mapping ev_re_check = em->query_evidence("ev_autopsy");
    assert_equal(1, ev_re_check["verified"], "重複登錄物證不得重置 verified 狀態為 0");
    assert_equal(1, member_array("commander", ev_re_check["seen_by"]) != -1, "重複登錄物證不得清空既有 seen_by 名冊");

    // 防刷分：主帥再次查看同一物證 1，數值絕不重複計算
    assert_equal(0, em->mark_evidence_seen("ev_autopsy", "commander"), "同一官員重複查看同一物證應回傳 0");
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "重複查看數值不得增加");

    // 監軍 inspector 查看同一物證 1：物證 1 已被 verified，不得再次累加指標
    em->mark_evidence_seen("ev_autopsy", "inspector");
    assert_equal(2, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "同一物證被其他官員查看不得重複累加 verifiability 指標");

    // 此時只有 1 個獨立來源物證，即使證人完好，評估絕對不能解鎖 Ending A
    em->set_fact(EVENT_MILITARY_CRISIS, "witnesses_intact", 1);
    mapping eval_single_ev = em->evaluate_military_crisis();
    assert_true(eval_single_ev["ending_code"] != ENDING_A_FORMAL_INVESTIGATION, "單一孤證絕對不能解鎖結局 A (正式調查)");

    // 登錄物證 2 (來源：smuggling_wreckage，強度：1)
    em->register_evidence("ev_crucible", ([
        "name": "富商覆車起獲之走私坩堝",
        "strength": 1,
        "source_type": "smuggling_wreckage"
    ]));

    // 監軍檢驗物證 2：來自第 2 個獨立來源，verifiability += 1 (達到 3)，intel -= 1 (達到 1)
    em->mark_evidence_seen("ev_crucible", "inspector");
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "第二來源物證檢驗後 verifiability 達到 3");
    assert_equal(1, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE), "intel 降至 1");

    // 具備 2 個獨立來源 + verifiability >= 2 + intel <= 1 + 未流血 + 證人生還 + resilience >= 1 -> 正式解鎖 Ending A
    mapping eval_double_ev = em->evaluate_military_crisis();
    assert_equal(ENDING_A_FORMAL_INVESTIGATION, eval_double_ev["ending_code"], "多方獨立鐵證核驗後方可合法收斂至結局 A (正式調查)");

    // ── 6. 結局空間無矛盾性與聚落韌性決定性驗證 ─────────────────
    // 6.1 只要 blood_drawn == 1，必須收斂為 Ending D (局部衝突)
    em->set_fact(EVENT_MILITARY_CRISIS, "blood_drawn", 1);
    mapping eval_blood = em->evaluate_military_crisis();
    assert_equal(ENDING_D_LOCAL_SKIRMISH, eval_blood["ending_code"], "已流血事件必須嚴格判定為結局 D (局部衝突)");

    // 6.2 聚落韌性徹底崩潰 (resilience <= 0) 即使未流血也判定為局部騷亂死傷 (Ending D)
    em->set_fact(EVENT_MILITARY_CRISIS, "blood_drawn", 0);
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE, 0);
    mapping eval_collapse = em->evaluate_military_crisis();
    assert_equal(ENDING_D_LOCAL_SKIRMISH, eval_collapse["ending_code"], "聚落韌性崩潰 (resilience <= 0) 判定為局部衝突與接管死傷");

    // 6.3 韌性恢復後，強攻成本高 -> Ending B (有限封鎖)
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE, 2);
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST, 3);
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE, 3);
    mapping eval_blockade = em->evaluate_military_crisis();
    assert_equal(ENDING_B_LIMITED_BLOCKADE, eval_blockade["ending_code"], "未流血且強攻成本過高且韌性足夠時收斂至結局 B");

    // 強攻成本低 + 暗渠暢通 -> Ending E (疏散撤離)
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST, 1);
    em->set_fact(EVENT_MILITARY_CRISIS, "evacuation_tunnels_open", 1);
    mapping eval_evac = em->evaluate_military_crisis();
    assert_equal(ENDING_E_EVACUATION_REBUILD, eval_evac["ending_code"], "未流血且暗渠完備時收斂至結局 E (疏散撤離)");

    // 保底對峙 -> Ending C (延遲進攻)
    em->set_fact(EVENT_MILITARY_CRISIS, "evacuation_tunnels_open", 0);
    mapping eval_ultimatum = em->evaluate_military_crisis();
    assert_equal(ENDING_C_DELAYED_ULTIMATUM, eval_ultimatum["ending_code"], "未流血且各方均未壓倒時收斂至結局 C (延遲進攻)");

    // 6.4 終局結算凍結 (Resolution Freeze) 驗證
    em->set_event_stage(EVENT_MILITARY_CRISIS, STAGE_MILITARY_RESOLUTION, 1);
    mapping frozen_eval = em->evaluate_military_crisis();
    string frozen_code = frozen_eval["ending_code"];
    assert_equal(ENDING_C_DELAYED_ULTIMATUM, frozen_code, "進入 resolution 時結算被快照凍結");

    // 試圖在凍結後竄改指標
    em->set_fact(EVENT_MILITARY_CRISIS, "blood_drawn", 1);
    mapping post_frozen_eval = em->evaluate_military_crisis();
    assert_equal(frozen_code, post_frozen_eval["ending_code"], "終局凍結後結局快照不可被後續指標竄改");

    // 試圖在凍結後提交任務
    mapping late_outcome = ([ "status": "success", "deltas": ([ METRIC_INTEL_CONFIDENCE: -1 ]) ]);
    mapping late_tx = em->apply_quest_outcome(EVENT_MILITARY_CRISIS, "late_quest", late_outcome, "player1");
    assert_equal("rejected", late_tx["status"], "終局凍結後拒絕後續任務結算");

    // 6.5 標準遊玩因果閉環驗證 (消除 Ending D 85%~92% 鎖死)
    em->reset_event("all");
    em->set_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT, 1);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE, 1);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY, 4);
    em->set_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST, 2);

    // 煞潮自然推進至 T+2 (自動觸發傳播與軍事危機 arrival)
    em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_PLUS_2, 0);
    assert_equal(STAGE_MILITARY_ARRIVAL, em->query_event_stage(EVENT_MILITARY_CRISIS), "煞潮 T+2 自動促成軍事危機抵達 arrival");
    int res_arrival = em->query_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE);
    assert_true(res_arrival >= 2, "正常防禦煞潮後，傳播至軍事危機之聚落韌性至少為 2");

    // 軍事時間軸推進至 confrontation (對峙摩擦：扣減 1 點聚落韌性)
    em->advance_event_stage(EVENT_MILITARY_CRISIS);
    assert_equal(STAGE_MILITARY_CONFRONTATION, em->query_event_stage(EVENT_MILITARY_CRISIS), "軍事時間軸前進至 confrontation");
    int res_confront = em->query_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE);
    assert_true(res_confront >= 1, "經歷陣前對峙消耗後，聚落韌性依然保底 >= 1，絕不崩潰");

    // 軍事時間軸推進至 ultimatum (修正後不再重複雙扣韌性)
    em->advance_event_stage(EVENT_MILITARY_CRISIS);
    assert_equal(STAGE_MILITARY_ULTIMATUM, em->query_event_stage(EVENT_MILITARY_CRISIS), "軍事時間軸前進至 ultimatum");
    int res_ultimatum = em->query_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE);
    assert_equal(res_confront, res_ultimatum, "最後通牒階段不再重複扣減韌性");
    assert_true(res_ultimatum >= 1, "結算前夕聚落韌性 >= 1，徹底打破結局 D 鎖死");

    // 驗證在正常遊玩下，評估不會被鎖死在結局 D
    mapping eval_std_play = em->evaluate_military_crisis();
    assert_true(eval_std_play["ending_code"] != ENDING_D_LOCAL_SKIRMISH, "標準遊玩未流血且韌性保底時，絕不落入結局 D");
    assert_equal(ENDING_B_LIMITED_BLOCKADE, eval_std_play["ending_code"], "因官道受損強攻成本提高，標準遊玩順利收斂至結局 B (有限封鎖)");

    // 若強攻成本為 1 且未呈遞鐵證，則收斂至保底結局 C (延遲進攻)
    em->set_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST, 1);
    mapping eval_c = em->evaluate_military_crisis();
    assert_equal(ENDING_C_DELAYED_ULTIMATUM, eval_c["ending_code"], "強攻成本一般時順利收斂至保底結局 C (延遲進攻)");

    // ── 7. 發布/訂閱事件匯流排 (Pub/Sub Event Bus) 驗證 ───────
    pubsub_called = 0;
    em->reset_event("all");
    em->subscribe(EVENT_BEAST_SURGE, this_object(), "on_event_bus_msg");

    mapping pubsub_outcome = ([
        "status": "success",
        "deltas": ([ METRIC_CIVILIAN_TRUST: 1 ]),
        "message": "鐵匠鋪修整兵刃安撫人心"
    ]);
    em->apply_quest_outcome(EVENT_BEAST_SURGE, "smith_morale", pubsub_outcome, "player2");

    assert_true(pubsub_called > 0, "事件匯流排訂閱者應收到回調通知");
    assert_equal(EVENT_BEAST_SURGE, pubsub_last_event, "訂閱回調事件 ID 應正確");
    assert_equal("quest_outcome", pubsub_last_type, "訂閱回調事件類型應為 quest_outcome");

    // 取消訂閱
    em->unsubscribe(EVENT_BEAST_SURGE, this_object());
    int prev_calls = pubsub_called;
    em->apply_quest_outcome(EVENT_BEAST_SURGE, "smith_morale_2", pubsub_outcome, "player3");
    assert_equal(prev_calls, pubsub_called, "取消訂閱後不再接收回調");

    // ── 8. 乾淨重置 (Clean Reset) 驗證 ────────────────────────
    em->reset_event("all");
    assert_equal(STAGE_BEAST_T_MINUS_3, em->query_event_stage(EVENT_BEAST_SURGE), "重置後煞潮階段應恢復為 T-3");
    assert_equal(0, sizeof(em->query_all_evidence()), "重置後物證帳本應徹底清空");
    assert_equal(0, sizeof(em->query_event_logs("", 0)), "重置後歷史日誌應徹底清空");
    assert_equal(0, sizeof(em->query_all_applied_outcomes(EVENT_BEAST_SURGE)), "重置後已結算任務名冊應徹底清空");

    report_results();
}
