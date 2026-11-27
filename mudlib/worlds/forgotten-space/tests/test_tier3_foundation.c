// /tests/test_tier3_foundation.c
// Phase 6 Step 3: Tier 3 Mudlib 底層機制與防歪樓測試
// 驗證項目：
// 1. K × U 能力檢定：禁止以整數/字串計數冒充 K，必須經「可驗證環境實驗」寫入 K 后方能解鎖 U
// 2. 舊招式三倍消耗、半威力（由 TIER3_D 單一可調表驅動），且僅在 /d/realm/ 生效
// 3. 同一種 U（law / force / craft）可由「兩種不同觀察路徑」各自取得並解除阻尼罰則
// 4. 單一可調表動態調參生效驗證
// 5. 高代價雙向信標嚴禁活人強渡、嚴限半斤載重、強制消耗三百斤鹽晶儲柱與特鍛黑鐵導波環
// 6. EVENT_TIER3_CALIBRATION 週期性世界事件（T-2 -> T+2）、五條平行指標與 CROSS-05 嚴格區隔 Tier 4

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/world_event.h"

void run_tests(object me) {
    start_test("Phase 6 Step 3: Tier 3 底層 (K×U、三倍高耗、雙向信標與校準事件)");

    object t3 = load_object(TIER3_D);
    object combat_d = load_object(COMBAT_D);
    object em = load_object(EVENT_MANAGER_D);
    assert_true(objectp(t3) && objectp(combat_d) && objectp(em), "TIER3_D / COMBAT_D / EVENT_MANAGER_D 必須成功載入");

    object village_room = load_object("/d/village/square.c");
    object realm_room = load_object("/d/realm/peach_plateau.c");
    assert_true(objectp(village_room) && objectp(realm_room), "凡間基準房與 /d/realm/peach_plateau.c 必須存在");

    // ── 1. 驗證舊招在凡間正常消耗/威力 vs 進入 /d/realm/ 三倍消耗、半威力 ──
    object fa_a = clone_object("/std/user.c");
    fa_a->set_id("t3_fa_a");
    fa_a->set_name("清虛甲");
    fa_a->set_path("fa");
    fa_a->set_level(100);
    fa_a->set_stat("int", 30);
    fa_a->set_stat("spi", 30);
    fa_a->set_skill("dao_jiefa", 60);
    fa_a->set_skill("dao_fudun", 60);

    object dummy = clone_object("/npc/slime.c");
    dummy->set_level(60);
    dummy->set_stat("con", 80);
    dummy->recalc_stats();

    // 1a. 凡間基準 (dao_jiefa 原耗 sen = 20)
    move_object(fa_a, village_room);
    move_object(dummy, village_room);
    fa_a->set_sen(200);
    assert_equal(20, combat_d->query_effective_perform_cost(fa_a, "dao_jiefa"), "凡間施展 dao_jiefa 應維持原耗 20");
    assert_equal(100, combat_d->query_effective_power_pct(fa_a, "fa"), "凡間威力倍率應為 100%");
    int dmg_mortal = combat_d->apply_combat_modifiers(fa_a, dummy, "fa", 100);

    // 1b. 進入 /d/realm/ 無 U 時：三倍消耗 (20 * 3 = 60)、半威力 (50%)
    move_object(fa_a, realm_room);
    move_object(dummy, realm_room);
    assert_equal(60, combat_d->query_effective_perform_cost(fa_a, "dao_jiefa"), "進入洞天未具 U 時消耗應增至三倍 (60)");
    assert_equal(50, combat_d->query_effective_power_pct(fa_a, "fa"), "進入洞天未具 U 時威力倍率應折半為 50%");

    int dmg_realm_no_u = combat_d->apply_combat_modifiers(fa_a, dummy, "fa", 100);
    assert_equal(dmg_mortal / 2, dmg_realm_no_u, "洞天未具 U 時舊招傷害應為凡間基準半威力");

    // 實際 do_perform 扣減驗證
    fa_a->set_sen(200);
    dummy->set_kee(dummy->query_max_kee());
    int perf_ok = combat_d->do_perform(fa_a, "dao_jiefa", dummy->query_key_id());
    assert_equal(1, perf_ok, "sen 足夠三倍消耗時應可施展舊招");
    assert_equal(140, fa_a->query_sen(), "實際扣除神識應為 60 (200 - 60 = 140)");

    // sen 只有 40（凡間夠用，洞天三倍 60 不足）應遭拒
    fa_a->set_sen(40);
    int perf_fail = combat_d->do_perform(fa_a, "dao_jiefa", dummy->query_key_id());
    assert_equal(0, perf_fail, "神識僅 40 不足洞天三倍消耗 60 時應無法施展");

    // ── 2. 防作弊與 K × U 雙觀察路徑解鎖驗證 ──────────────────────────
    // 2a. 禁止以計數整數或裸字串寫入 tier3_k/*
    fa_a->set("tier3_k/law", 99);
    assert_equal(0, t3->has_k(fa_a, "law"), "禁止以整數計數旗標冒充 K");
    fa_a->set("tier3_k/law", "done");
    assert_equal(0, t3->has_k(fa_a, "law"), "禁止以裸字串冒充 K");

    // 2b. 未具合法 K 前不可直接解鎖 U
    mapping u_early = t3->unlock_u_via_path(fa_a, "law", "wind_sand_copper_ruler", ([
        "tangent_sketch": 1, "low_cost_barrier_test": 1
    ]));
    assert_equal(0, u_early["ok"], "尚未完成可驗證環境實驗 K 前，不得直接解鎖 U");

    // 2c. 實驗缺少必要現場證據欄位亦應失敗
    mapping k_bad = t3->grant_k_from_experiment(fa_a, "law", "measure_basalt_wind", ([ "copper_ruler_drift": 1 ]));
    assert_equal(0, k_bad["ok"], "環境實驗證據不完整時不得寫入 K");

    // 2d. 角色 A 經【路徑一：野測風砂銅尺】取得 law U
    mapping k_ok_a = t3->grant_k_from_experiment(fa_a, "law", "measure_basalt_wind", ([
        "copper_ruler_drift": 5, "dust_vector_trace": "tangent_ne"
    ]));
    assert_equal(1, k_ok_a["ok"], "完成可驗證環境實驗應寫入 K");
    assert_equal(1, t3->has_k(fa_a, "law"), "has_k 應驗證通過");

    mapping u_ok_a = t3->unlock_u_via_path(fa_a, "law", "wind_sand_copper_ruler", ([
        "tangent_sketch": 1, "low_cost_barrier_test": 1
    ]));
    assert_equal(1, u_ok_a["ok"], "經觀察路徑一應成功解鎖 tier3_u/law");
    assert_equal(1, t3->has_u(fa_a, "law"), "角色 A 應具備 tier3_u/law");
    assert_equal(100, combat_d->query_effective_power_pct(fa_a, "fa"), "解鎖 U 後威力應恢復 100%");
    assert_true(combat_d->query_effective_perform_cost(fa_a, "dao_jiefa") < 60, "解鎖 U 後應擺脫三倍高耗罰則");

    // 2e. 角色 B 經完全不同的【路徑二：校星院日誌交叉實證】取得同一種 tier3_u/law
    object fa_b = clone_object("/std/user.c");
    fa_b->set_id("t3_fa_b");
    fa_b->set_path("fa");
    move_object(fa_b, realm_room);
    mapping k_ok_b = t3->grant_k_from_experiment(fa_b, "law", "inspect_taixu_steps", ([
        "step_incline_angle": 15, "salt_resonance_delta": 3
    ]));
    assert_equal(1, k_ok_b["ok"], "角色 B 經太虛階座實驗應寫入 K");
    mapping u_ok_b = t3->unlock_u_via_path(fa_b, "law", "taixu_calibration_log", ([
        "heng_log_diff": 1, "reverse_star_alignment": 1
    ]));
    assert_equal(1, u_ok_b["ok"], "角色 B 經觀察路徑二應可取得同一種 tier3_u/law");
    assert_equal(1, t3->has_u(fa_b, "law"), "兩種不同觀察路徑應皆可取得同一種 U");
    assert_equal(100, combat_d->query_effective_power_pct(fa_b, "fa"), "路徑二解鎖 U 同樣解除半威力罰則");

    // 2f. 驗證力道 (force) 雙觀察路徑與支援招式半威力
    object li_a = clone_object("/std/user.c");
    li_a->set_id("t3_li_a");
    li_a->set_path("li");
    li_a->set_stat("con", 40);
    move_object(li_a, realm_room);
    assert_equal(50, combat_d->query_effective_power_pct(li_a, "li"), "力道未具 U 在洞天應折半威力");
    t3->grant_k_from_experiment(li_a, "force", "time_gravity_pulse", ([ "pulse_interval_beats": 10, "totem_resonance": 1 ]));
    t3->unlock_u_via_path(li_a, "force", "veteran_hunter_marks", ([ "eagle_mark_rubbing": 1, "pack_breath_cadence": 1 ]));
    assert_equal(1, t3->has_u(li_a, "force"), "力道應可透過獵人暗記路徑解鎖 U");

    // ── 3. 驗證單一可調表集中控制生效 ─────────────────────────────────
    mapping orig_tuning = t3->query_tuning();
    assert_equal(3, orig_tuning["old_skill_cost_mult"], "預設舊招倍率應為 3");
    assert_equal(50, orig_tuning["old_skill_power_pct"], "預設舊招威力應為 50%");
    t3->set_tuning_value("old_skill_cost_mult", 4);
    t3->set_tuning_value("old_skill_power_pct", 40);
    assert_equal(80, combat_d->query_effective_perform_cost(li_a, "dao_jiefa"), "調整單一可調表後應即時改變未解鎖領域消耗");
    assert_equal(40, combat_d->query_effective_power_pct(li_a, "fa"), "調整單一可調表後應即時改變未解鎖領域威力");
    t3->set_tuning_value("old_skill_cost_mult", 3);
    t3->set_tuning_value("old_skill_power_pct", 50);

    // ── 4. 高代價雙向信標邊界驗證 ────────────────────────────────────
    mapping b_living = t3->transmit_beacon_parcel(fa_a, ([
        "is_living": 1, "weight_liang": 5, "salt_crystal_jin": 300, "conduit_rings": 1
    ]));
    assert_equal(0, b_living["ok"], "雙向信標必須嚴禁活人強渡");
    assert_equal("living_transit_forbidden", b_living["reason"], "應回傳活人禁渡原因");

    mapping b_heavy = t3->transmit_beacon_parcel(fa_a, ([
        "is_living": 0, "weight_liang": 6, "salt_crystal_jin": 300, "conduit_rings": 1
    ]));
    assert_equal(0, b_heavy["ok"], "超過半斤（5 兩）應遭拒");

    mapping b_low_salt = t3->transmit_beacon_parcel(fa_a, ([
        "is_living": 0, "weight_liang": 4, "salt_crystal_jin": 200, "conduit_rings": 1
    ]));
    assert_equal(0, b_low_salt["ok"], "鹽晶儲柱不足 300 斤應遭拒");

    mapping b_ok = t3->transmit_beacon_parcel(fa_a, ([
        "title": "雲津家報與茶牌拓印",
        "is_living": 0, "weight_liang": 5, "salt_crystal_jin": 300, "conduit_rings": 1
    ]));
    assert_equal(1, b_ok["ok"], "符合成本與半斤上限時雙向信標應成功寄出");
    assert_equal(300, b_ok["salt_consumed"], "應記錄消耗 300 斤鹽晶");
    assert_equal(3, b_ok["window_breaths"], "視窗應維持 3 息");

    // ── 5. EVENT_TIER3_CALIBRATION 骨架、平行指標、週期輪轉與 Tier 4 區隔 ──
    em->set_test_mode(1);
    em->reset_event(EVENT_TIER3_CALIBRATION);
    assert_equal(STAGE_TIER3_T_MINUS_2, em->query_event_stage(EVENT_TIER3_CALIBRATION), "Tier 3 校準事件初始階段應為 T-2");
    assert_equal(1, em->is_valid_metric(EVENT_TIER3_CALIBRATION, METRIC_LABOR_SOLIDARITY), "指標 labor_solidarity 應註冊成功");

    // 模擬多條平行戰線貢獻（不綁特定身世）
    em->apply_quest_outcome(EVENT_TIER3_CALIBRATION, "v4_act4_labor_strike_sanction", ([
        "status": "success", "deltas": ([ METRIC_LABOR_SOLIDARITY: 4 ]), "facts": ([ "strike_executed": 1 ]), "message": "大停工執行"
    ]), "t3_fa_a");
    em->apply_quest_outcome(EVENT_TIER3_CALIBRATION, "v4_act4_taixu_star_deflection", ([
        "status": "success", "deltas": ([ METRIC_ARRAY_DEFLECTION: 4 ]), "facts": ([ "array_shifted_1_5_deg": 1 ]), "message": "偏星一度半"
    ]), "t3_fa_b");
    em->apply_quest_outcome(EVENT_TIER3_CALIBRATION, "v4_act4_bone_gate_defense", ([
        "status": "success", "deltas": ([ METRIC_OUTPOST_DEFENSE: 3 ]), "facts": ([ "arena_yanshan_rescued": 1 ]), "message": "哨卡阻獸"
    ]), "t3_li_a");
    em->apply_quest_outcome(EVENT_TIER3_CALIBRATION, "v4_act4_arbitration_equal_charter", ([
        "status": "success", "deltas": ([ METRIC_CHARTER_LEGITIMACY: 4, METRIC_BEACON_READINESS: 3 ]), "facts": ([ "charter_equalized": 1, "beacon_tested": 1 ]), "message": "平權定約"
    ]), "t3_fa_a");

    em->set_event_stage(EVENT_TIER3_CALIBRATION, STAGE_TIER3_T_PLUS_2, 1);
    mapping ev3 = em->evaluate_tier3_calibration();
    assert_equal("blocked_and_equalized", ev3["calibration_outcome"], "五線並行達標應收斂為阻停並立約結局");
    assert_equal(1, ev3["beacon_available"], "T+2 且信標籌備達標時應可啟用微光信標");
    assert_equal(0, ev3["tier4_auto_unlocked"], "CROSS-05：校準通關絕不自動解鎖 Tier 4");

    // 驗證僅完成 Tier 3 校準與信標，仍不得進入 Tier 4 (/d/secret/)
    fa_a->set("event_honors/" + EVENT_TIER3_CALIBRATION, "破局先驅功臣");
    mapping t4_deny = t3->evaluate_tier4_unlock_eligibility(fa_a);
    assert_equal(0, t4_deny["eligible"], "完成 Tier 3 校準與信標後未達 §4.2 三要件仍不得進 Tier 4");
    assert_equal(3, sizeof(t4_deny["missing_requirements"]), "應明確列出缺少 §4.2 三要件");

    // 補齊 §4.2 三要件後始得解鎖 Tier 4
    fa_a->set("enc_map_fusion", 1);
    fa_a->set("three_yuan_resonance", 1);
    fa_a->set("personal_event/pierced_false_heaven", 1);
    mapping t4_allow = t3->evaluate_tier4_unlock_eligibility(fa_a);
    assert_equal(1, t4_allow["eligible"], "滿足 §4.2 三要件後方可解鎖 Tier 4");

    // 驗證 CROSS-05 週期輪轉（可重置回 T-2 供新玩家再參與）
    assert_equal(1, em->cycle_tier3_calibration(), "cycle_tier3_calibration 應可重置輪轉事件");
    assert_equal(STAGE_TIER3_T_MINUS_2, em->query_event_stage(EVENT_TIER3_CALIBRATION), "週期輪轉後應回到 T-2");

    // ── 6. C-07 洞天跨界時差倍率、換算與消費者機制驗證 (Ch.144~167: 12:1) ──────
    assert_equal(12, t3->query_realm_time_ratio(), "洞天跨界時差倍率應為 12:1");
    mapping conv = t3->query_realm_time_conversion(90);
    assert_equal(90, conv["realm_days"], "洞天 90 日大校準倒數");
    assert_equal(1080, conv["mortal_days"], "對應人間約 1080 日（整整三年）");
    assert_equal(12, conv["ratio"], "換算倍率應為 12");

    mapping cycle_info = t3->query_calibration_cycle_info();
    assert_equal(25, cycle_info["calibration_cycle_realm_years"], "人間三百年大校準對應洞天每 25 年一輪元");
    assert_equal(300, cycle_info["calibration_cycle_mortal_years"], "人間大校準週期為 300 年");

    object nature_d = load_object(NATURE_D);
    assert_true(objectp(nature_d), "NATURE_D 必須成功載入");
    assert_equal(4, nature_d->query_effective_time_ratio(village_room), "凡間時間比例應為 4");
    assert_equal(48, nature_d->query_effective_time_ratio(realm_room), "洞天有效流速應為 4 * 12 = 48");

    int gtime_before = nature_d->query_game_time();
    t3->advance_realm_time(10); // 推進洞天 10 分鐘
    int gtime_after = nature_d->query_game_time();
    assert_equal(gtime_before + 120, gtime_after, "推進洞天 10 分鐘應依 12:1 倍率推進人間 120 分鐘");

    // 驗證 cmd_time 指令在洞天環境下可正常呼叫並輸出跨界時差
    object cmd_time_ob = load_object("/cmds/cmd_time.c");
    assert_true(objectp(cmd_time_ob), "cmd_time 必須成功載入");
    move_object(me, realm_room);
    int time_res = cmd_time_ob->main(me, "time", "");
    assert_equal(1, time_res, "在洞天執行 cmd_time 應成功回傳 1");

    // 清理測試物件並還原事件狀態
    em->reset_event("all");
    destruct(fa_a);
    destruct(fa_b);
    destruct(li_a);
    destruct(dummy);
}
