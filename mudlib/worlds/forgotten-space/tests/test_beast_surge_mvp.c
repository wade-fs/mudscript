// /tests/test_beast_surge_mvp.c
// Phase 1: 大荒煞潮第一階段 MVP（8 個標竿任務）自動化整合驗證
// 驗證項目：
// 1. 8 大標竿事件任務 JSON 載入與結構完整性
// 2. 非全能驗收情境 A（僅完成 A01+A02：掌握地煞逃亡與路線，但無工程準備 -> 主力衝擊聚落）
// 3. 非全能驗收情境 B（未勘測盲目施工 B02 + 忽略 C01 糧倉調度 -> B02 降級為 partial 且爆發糧荒危機）
// 4. 完整協同情境 C（先勘測 A01+A02 再築 B02 -> B02 達成 success 精準導流 + C01/D01/E01/G01/F03 跨事件傳播）
// 5. T-Clock 階段窗口逾期防護（逾越 deadline_stage 後拒絕啟動與結算）

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/world_event.h"

void reset_player_quests(object p) {
    if (!p) return;
    string *qids = ({
        "A01_dead_gazelle",
        "A02_reverse_tracks",
        "B02_rockfall_diversion",
        "C01_grain_inventory",
        "D01_last_painkiller",
        "E01_street_defense",
        "G01_palisade_breach",
        "F03_testimony_cross_check"
    });
    foreach (string qid in qids) {
        p->delete("quests/" + qid + "/step");
        p->delete("quests/" + qid + "/stage");
        p->delete("quests/" + qid + "/state");
        p->delete("quests/" + qid + "/outcome_grade");
        p->delete("quests/" + qid + "/progress/kill_count");
    }
}

void run_tests(object me) {
    start_test("Phase 1: 大荒煞潮第一階段 MVP（8 個標竿任務）與非線性世界演化驗證");

    object qe = load_object(QUEST_ENGINE_D);
    object em = load_object(EVENT_MANAGER_D);
    object ws = load_object(WORLD_STATE_D);
    assert_true(objectp(qe), "任務引擎 (QUEST_ENGINE_D) 必須成功載入");
    assert_true(objectp(em), "事件守護進程 (EVENT_MANAGER_D) 必須成功載入");

    em->set_test_mode(1);
    em->reset_event("all");

    // ── 1. 驗證 8 大標竿任務均已載入任務池 ──────────────────────
    string *mvp_quests = ({
        "A01_dead_gazelle",
        "A02_reverse_tracks",
        "B02_rockfall_diversion",
        "C01_grain_inventory",
        "D01_last_painkiller",
        "E01_street_defense",
        "G01_palisade_breach",
        "F03_testimony_cross_check"
    });
    foreach (string qid in mvp_quests) {
        mapping qdef = qe->query_quest(qid);
        assert_true(mapp(qdef), "標竿事件任務必須存在於任務池: " + qid);
        assert_equal("beast_surge", qdef["world_event"], "任務必須綁定 beast_surge 事件: " + qid);
    }

    // 載入測試所需房間與 NPC
    object r_forest = load_object("/d/village/forest.c");
    object r_herb   = load_object("/d/village/herb_hut.c");
    object r_mine   = load_object("/d/village/mine.c");
    object r_cabin  = load_object("/d/village/hunter_cabin.c");
    object r_forge  = load_object("/d/village/forge.c");
    object r_square = load_object("/d/village/square.c");
    object r_shed   = load_object("/d/village/shed.c");
    object r_stream = load_object("/d/village/stream.c");
    object r_alley  = load_object("/d/village/dark_alley.c");

    object p = clone_object("/std/user.c");
    p->set_id("mvp_tester");
    p->set_name("測試少俠");
    p->set("level", 10);

    // ── 2. 非全能驗收情境 A：僅完成 A01 + A02（知曉成因與路線，但無工程干預）──
    em->reset_event("all");
    reset_player_quests(p);

    // 執行 A01 暴斃黃羊：forest (inspect gazelle) -> herb_hut (talk ge) -> mine (talk lu)
    p->move(r_forest);
    qe->trigger_event(p, "action", ([ "verb": "inspect", "target": "gazelle" ]));
    assert_equal(2, qe->query_quest_step(p, "A01_dead_gazelle"), "A01 Step 1 完成後應推進至 Step 2");

    p->move(r_herb);
    qe->trigger_event(p, "talk", ([ "npc": "ge", "topic": "黃羊" ]));
    assert_equal(3, qe->query_quest_step(p, "A01_dead_gazelle"), "A01 Step 2 完成後應推進至 Step 3");

    p->move(r_mine);
    qe->trigger_event(p, "talk", ([ "npc": "lu", "topic": "石髓渣" ]));
    assert_equal("COMPLETED", qe->query_quest_state(p, "A01_dead_gazelle"), "A01 應順利完成");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH), "A01 完成後 evidence_strength 應為 1");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "A01 完成後 route_confidence 應為 1");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "autopsy_performed"), "A01 完成後 autopsy_performed 應為 1");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "sulfur_poisoning_found"), "A01 完成後 sulfur_poisoning_found 應為 1");

    // 執行 A02 逆行獸跡：hunter_cabin (talk zhao) -> forest (survey tracks) -> hunter_cabin (talk zhao)
    p->move(r_cabin);
    qe->trigger_event(p, "talk", ([ "npc": "zhao", "topic": "獸跡" ]));
    assert_equal(2, qe->query_quest_step(p, "A02_reverse_tracks"), "A02 接取並完成 Step 1 後應推進至 Step 2");

    p->move(r_forest);
    qe->trigger_event(p, "action", ([ "verb": "survey", "target": "tracks" ]));
    assert_equal(3, qe->query_quest_step(p, "A02_reverse_tracks"), "A02 Step 2 完成後應推進至 Step 3");

    p->move(r_cabin);
    qe->trigger_event(p, "talk", ([ "npc": "zhao", "topic": "遷徙路線" ]));
    assert_equal("COMPLETED", qe->query_quest_state(p, "A02_reverse_tracks"), "A02 應順利完成");
    assert_equal(3, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "A01+A02 完成後 route_confidence 應達 3");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "flight_direction_mapped"), "flight_direction_mapped 應為 1");

    // 驗證「知情但無工程準備」的衍生評估：diversion_effect 為 0，僅能做到預警局部偏折 (partial_deflected)，無法將主力導入落龍澗 (canyon)
    mapping eval_a = em->evaluate_beast_surge();
    assert_equal(0, em->query_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT), "未做工程時 diversion_effect 為 0");
    assert_equal("partial_deflected", eval_a["main_herd_route"], "無工程石陣時僅能局部偏折，無法導入落龍澗");

    // ── 3. 非全能驗收情境 B：未做勘測盲目施工 B02 + 忽略糧倉調度 ──────────────
    em->reset_event("all");
    reset_player_quests(p);

    // 此時 route_confidence == 0 (< 2)，直接執行 B02 萬斤落石
    p->move(r_forge);
    qe->trigger_event(p, "talk", ([ "npc": "tie", "topic": "落龍工程" ]));
    assert_equal(2, qe->query_quest_step(p, "B02_rockfall_diversion"), "B02 接取並完成 Step 1");

    p->move(r_mine);
    qe->trigger_event(p, "talk", ([ "npc": "lu", "topic": "斜向卸力" ]));
    assert_equal(3, qe->query_quest_step(p, "B02_rockfall_diversion"), "B02 Step 2 完成");

    qe->trigger_event(p, "action", ([ "verb": "rig", "target": "barrier" ]));
    assert_equal("COMPLETED", qe->query_quest_state(p, "B02_rockfall_diversion"), "B02 應完成");
    assert_equal("partial", p->query("quests/B02_rockfall_diversion/outcome_grade"), "未勘測下施工 B02 應判定為 partial 分支");
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT), "B02 partial 僅提升 diversion_effect +1");
    assert_equal(2, em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY), "B02 partial 消耗雙倍物資，settlement_capacity 降至 2");

    // 推進時間軸至 T-1（經過 T-2 時間代價 settlement_capacity -1，剩餘 1；T-1 時間代價 civilian_trust -1，剩餘 1）
    em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_MINUS_1, 0);
    assert_equal(1, em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY), "未盤點糧倉且經 T-2 消耗後，物資承載力僅剩 1");
    mapping eval_b = em->evaluate_beast_surge();
    assert_equal("devastated", eval_b["settlement_state"], "盲目施工耗盡物資且無預警時，殘獸衝擊將導致聚落物資崩潰");
    assert_equal(0, eval_b["derived_resilience"], "物資耗盡下衍生韌性跌至 0");

    // ── 4. 完整協同情境 C：8 大標竿任務全線連動與跨事件傳播 ──────────────────
    em->reset_event("all");
    reset_player_quests(p);

    // 4.1 先完成 A01 + A02 取得 route_confidence == 3
    p->move(r_forest);
    qe->trigger_event(p, "action", ([ "verb": "inspect", "target": "gazelle" ]));
    p->move(r_herb);
    qe->trigger_event(p, "talk", ([ "npc": "ge", "topic": "黃羊" ]));
    p->move(r_mine);
    qe->trigger_event(p, "talk", ([ "npc": "lu", "topic": "石髓渣" ]));

    p->move(r_cabin);
    qe->trigger_event(p, "talk", ([ "npc": "zhao", "topic": "獸跡" ]));
    p->move(r_forest);
    qe->trigger_event(p, "action", ([ "verb": "survey", "target": "tracks" ]));
    p->move(r_cabin);
    qe->trigger_event(p, "talk", ([ "npc": "zhao", "topic": "遷徙路線" ]));
    assert_equal(3, em->query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE), "A01+A02 達成滿額勘測信心 3");

    // 4.2 在高勘測信心下完成 B02 萬斤落石 -> 應觸發 success 分支 (+2 diversion, -1 capacity)
    p->move(r_forge);
    qe->trigger_event(p, "talk", ([ "npc": "tie", "topic": "落龍工程" ]));
    p->move(r_mine);
    qe->trigger_event(p, "talk", ([ "npc": "lu", "topic": "斜向卸力" ]));
    qe->trigger_event(p, "action", ([ "verb": "rig", "target": "barrier" ]));
    assert_equal("success", p->query("quests/B02_rockfall_diversion/outcome_grade"), "具備勘測基礎時 B02 應達成 success 精準導流");
    assert_equal(2, em->query_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT), "B02 success 應提升 diversion_effect 至 2");
    assert_equal(3, em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY), "B02 success 僅消耗 1 點物資 (4->3)");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "diversion_ditch_dug"), "diversion_ditch_dug 事實應為 1");

    // 4.3 完成 C01 糧倉盤點：square (audit grain) -> shed (talk su) -> forge (talk tie)
    p->move(r_square);
    qe->trigger_event(p, "action", ([ "verb": "audit", "target": "grain" ]));
    p->move(r_shed);
    qe->trigger_event(p, "talk", ([ "npc": "su", "topic": "盤點存糧" ]));
    p->move(r_forge);
    qe->trigger_event(p, "talk", ([ "npc": "tie", "topic": "三方封條" ]));
    assert_equal("COMPLETED", qe->query_quest_state(p, "C01_grain_inventory"), "C01 糧倉盤點應完成");
    assert_equal(4, em->query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY), "C01 完成後物資承載力回滿至 4");
    assert_equal(3, em->query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST), "C01 完成後居民信任度提升至 3");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "merchant_supplies_looted"), "merchant_supplies_looted 應為 1");

    // 4.4 推進至 T-1（扣除時間代價後，以 D01 與 E01 補回！）
    em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_MINUS_1, 0);

    // 完成 D01 最後一包止痛散：herb_hut (talk ge -> triage miner) -> stream (gather herb)
    p->move(r_herb);
    qe->trigger_event(p, "talk", ([ "npc": "ge", "topic": "止痛散" ]));
    qe->trigger_event(p, "action", ([ "verb": "triage", "target": "miner" ]));
    p->move(r_stream);
    qe->trigger_event(p, "action", ([ "verb": "gather", "target": "herb" ]));
    assert_equal("COMPLETED", qe->query_quest_state(p, "D01_last_painkiller"), "D01 最後一包止痛散應完成");

    // 完成 E01 誰來守街口：hunter_cabin (talk zhao) -> forge (talk tie) -> square (fortify street)
    p->move(r_cabin);
    qe->trigger_event(p, "talk", ([ "npc": "zhao", "topic": "守街口" ]));
    p->move(r_forge);
    qe->trigger_event(p, "talk", ([ "npc": "tie", "topic": "街口車陣" ]));
    p->move(r_square);
    qe->trigger_event(p, "action", ([ "verb": "fortify", "target": "street" ]));
    assert_equal("COMPLETED", qe->query_quest_state(p, "E01_street_defense"), "E01 誰來守街口應完成");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "signal_arrows_ready"), "E01 完成後 signal_arrows_ready 應為 1");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "cold_smoke_stock"), "E01 完成後 cold_smoke_stock 應為 1");

    // 4.5 推進至 T+1（殘獸清剿），執行 G01 木柵缺口 與 F03 證詞互證
    em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_PLUS_1, 0);

    p->move(r_cabin);
    qe->trigger_event(p, "talk", ([ "npc": "zhao", "topic": "木柵缺口" ]));
    p->move(r_forest);
    object w1 = clone_object("/npc/wolf.c");
    object w2 = clone_object("/npc/wolf.c");
    qe->trigger_event(p, "kill", ([ "victim": w1, "victim_id": "wolf", "victim_name": "灰狼", "victim_file": "/npc/wolf" ]));
    qe->trigger_event(p, "kill", ([ "victim": w2, "victim_id": "wolf", "victim_name": "灰狼", "victim_file": "/npc/wolf" ]));
    if (w1) destruct(w1);
    if (w2) destruct(w2);
    p->move(r_square);
    qe->trigger_event(p, "action", ([ "verb": "brace", "target": "breach" ]));
    assert_equal("COMPLETED", qe->query_quest_state(p, "G01_palisade_breach"), "G01 木柵缺口應完成");
    assert_equal(2, em->query_metric(EVENT_BEAST_SURGE, METRIC_HERD_PRESSURE), "G01 完成後 herd_pressure 應由 3 降至 2");
    assert_equal(1, em->query_fact(EVENT_BEAST_SURGE, "residual_breach_occurred"), "residual_breach_occurred 應為 1");

    // 完成 F03 證詞互證：mine (talk lu) -> dark_alley (inspect crucible) -> shed (talk su)
    p->move(r_mine);
    qe->trigger_event(p, "talk", ([ "npc": "lu", "topic": "雷管引信" ]));
    p->move(r_alley);
    qe->trigger_event(p, "action", ([ "verb": "inspect", "target": "crucible" ]));
    p->move(r_shed);
    qe->trigger_event(p, "talk", ([ "npc": "su", "topic": "證詞互證" ]));
    assert_equal("COMPLETED", qe->query_quest_state(p, "F03_testimony_cross_check"), "F03 證詞互證應完成");
    assert_equal(3, em->query_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH), "A01+F03 完成後 evidence_strength 應達滿值 3");

    // 4.6 推進至 T+2（局勢反噬・官道衝斷），驗證向第二階段軍事危機的自動耦合傳播
    em->set_event_stage(EVENT_BEAST_SURGE, STAGE_BEAST_T_PLUS_2, 0);
    assert_equal(STAGE_MILITARY_ARRIVAL, em->query_event_stage(EVENT_MILITARY_CRISIS), "T+2 應自動觸發軍事危機進入 arrival 先鋒扣關階段");
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE), "黑石鋪完整防禦後傳播至軍事危機的韌性應為 3");
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST), "獸潮主力偏折落龍澗沖毀官道，強攻成本應升至 3");
    assert_equal(3, em->query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY), "生態與走私鐵證傳播後，核驗度應達 3");

    // 檢查狀態總覽面板輸出包含大荒煞潮事件網
    string report = qe->query_all_status_report(p);
    assert_true(strsrch(report, "大荒煞潮・生存事件網") != -1, "任務面板應顯示大荒煞潮生存事件網專區");

    // ── 5. 驗證 T-Clock 階段窗口逾期保護 (Deadline Gating) ──────────────────
    reset_player_quests(p);
    // 當前處於 T+2，嘗試重新觸發截止於 T-1 的 A01 暴斃黃羊
    p->move(r_forest);
    int late_start = qe->trigger_event(p, "action", ([ "verb": "inspect", "target": "gazelle" ]));
    assert_equal(0, late_start, "逾越 deadline_stage (T-1) 後，在 T+2 不可再啟動 A01");
    assert_equal("NOT_STARTED", qe->query_quest_state(p, "A01_dead_gazelle"), "逾期任務狀態應保持 NOT_STARTED");

    // ── 6. 驗證日常交付與三大道統鏈雙軌對齊 (deliver / stargaze / trap / strike ore) ──
    object r_temple = load_object("/d/village/daoist_temple.c");
    object r_altar  = load_object("/d/village/altar.c");

    // 6.1 驗證 herb 與 wolf_fur 的 has_required_item 及 deliver 閉環
    object herb_ob = clone_object("/clone/item/herb_common.c");
    herb_ob->move(p);
    assert_equal(1, qe->has_required_item(p, "herb"), "has_required_item 應支援 herb");
    p->move(r_herb);
    qe->trigger_event(p, "talk", ([ "npc": "ge", "topic": "採藥" ]));
    assert_equal(1, qe->query_quest_step(p, "herb_loop"), "herb_loop 應成功接取");
    qe->trigger_event(p, "deliver", ([ "npc": "ge", "item": herb_ob ]));
    assert_equal(1, qe->query_quest_rounds(p, "herb_loop"), "herb_loop 交付草藥後應完成 1 輪");
    if (herb_ob) destruct(herb_ob);

    object fur_ob = clone_object("/item/material/wolf_fur.c");
    fur_ob->move(p);
    assert_equal(1, qe->has_required_item(p, "wolf_fur"), "has_required_item 應支援 wolf_fur");
    p->move(r_cabin);
    qe->trigger_event(p, "talk", ([ "npc": "zhao", "topic": "毛皮" ]));
    assert_equal(1, qe->query_quest_step(p, "pelt_loop"), "pelt_loop 應成功接取");
    qe->trigger_event(p, "deliver", ([ "npc": "zhao", "item": fur_ob ]));
    assert_equal(1, qe->query_quest_rounds(p, "pelt_loop"), "pelt_loop 交付狼皮後應完成 1 輪");
    if (fur_ob) destruct(fur_ob);

    // 6.2 驗證 fa_chain (wash -> stargaze -> talk kumu)
    p->move(r_temple);
    qe->trigger_event(p, "talk", ([ "npc": "kumu", "topic": "任務" ]));
    assert_equal(2, qe->query_quest_step(p, "fa_chain"), "fa_chain 接取後推進至 Step 2");
    p->move(r_stream);
    qe->trigger_event(p, "action", ([ "verb": "wash", "target": "face" ]));
    assert_equal(3, qe->query_quest_step(p, "fa_chain"), "fa_chain wash 後推進至 Step 3");
    p->move(r_altar);
    qe->trigger_event(p, "action", ([ "verb": "stargaze" ]));
    assert_equal(4, qe->query_quest_step(p, "fa_chain"), "fa_chain stargaze 後推進至 Step 4");
    p->move(r_temple);
    qe->trigger_event(p, "talk", ([ "npc": "kumu", "topic": "任務" ]));
    assert_equal(1, qe->query_quest_rounds(p, "fa_chain"), "fa_chain 完成一整輪閉環");

    // 6.3 驗證 li_chain (trap 發放 tainted_pelt -> sharpen blade -> deliver tainted_pelt)
    p->move(r_cabin);
    qe->trigger_event(p, "talk", ([ "npc": "zhao", "topic": "任務" ]));
    assert_equal(2, qe->query_quest_step(p, "li_chain"), "li_chain 接取後推進至 Step 2");
    p->move(r_forest);
    qe->trigger_event(p, "action", ([ "verb": "trap" ]));
    assert_equal(3, qe->query_quest_step(p, "li_chain"), "li_chain trap 後推進至 Step 3");
    assert_equal(1, qe->has_required_item(p, "tainted_pelt"), "li_chain Step 2 完成後應自動發放 tainted_pelt");
    object blade_ob = clone_object("/clone/weapon/rusty_blade.c");
    blade_ob->move(p);
    p->move(r_stream);
    qe->trigger_event(p, "action", ([ "verb": "sharpen", "target": "blade" ]));
    assert_equal(4, qe->query_quest_step(p, "li_chain"), "li_chain sharpen blade 後推進至 Step 4");
    object pelt_ob = present("tainted pelt", p);
    p->move(r_cabin);
    qe->trigger_event(p, "deliver", ([ "npc": "zhao", "item": pelt_ob ]));
    assert_equal(1, qe->query_quest_rounds(p, "li_chain"), "li_chain 完成一整輪閉環");
    if (blade_ob) destruct(blade_ob);
    if (pelt_ob) destruct(pelt_ob);

    // 6.4 驗證 wu_chain (talk lu -> deliver herb_dew -> deliver huoluo_dan -> strike ore)
    p->move(r_forge);
    qe->trigger_event(p, "talk", ([ "npc": "tie", "topic": "任務" ]));
    p->move(r_mine);
    qe->trigger_event(p, "talk", ([ "npc": "lu", "topic": "任務" ]));
    assert_equal(2, qe->query_quest_step(p, "wu_chain"), "wu_chain Step 1 完成後推進至 Step 2");
    object dew_ob = clone_object("/clone/item/herb_dew.c");
    dew_ob->move(p);
    p->move(r_herb);
    qe->trigger_event(p, "deliver", ([ "npc": "ge", "item": dew_ob ]));
    assert_equal(3, qe->query_quest_step(p, "wu_chain"), "wu_chain Step 2 完成後推進至 Step 3");
    object san_ob = present("huoluo san", p);
    p->move(r_mine);
    qe->trigger_event(p, "deliver", ([ "npc": "lu", "item": san_ob ]));
    assert_equal(4, qe->query_quest_step(p, "wu_chain"), "wu_chain Step 3 完成後推進至 Step 4");
    object hammer_ob = clone_object("/clone/weapon/smith_hammer.c");
    hammer_ob->move(p);
    p->move(r_forge);
    qe->trigger_event(p, "action", ([ "verb": "strike", "target": "ore" ]));
    assert_equal(1, qe->query_quest_rounds(p, "wu_chain"), "wu_chain strike ore 後完成一整輪閉環");
    if (dew_ob) destruct(dew_ob);
    if (san_ob) destruct(san_ob);
    if (hammer_ob) destruct(hammer_ob);

    destruct(p);
    em->reset_event("all");
    em->set_test_mode(0);
    report_results();
}

