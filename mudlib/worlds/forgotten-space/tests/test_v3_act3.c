// /tests/test_v3_act3.c
// 第三卷第三幕（Ch.102 ~ Ch.111）北荒勘探、戰神遺塚、方舟五器、九城舊約與冰谷伏擊驗證測試

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 2 第三卷第三幕（絕嶺尋蹤、五器共鳴與母脈封證）驗證");

    // ── 1. 世界事件系統：tier2_crisis 推進至 T0 質證階段與評估檢驗 ───
    object em = load_object(EVENT_MANAGER_D);
    assert_true(objectp(em), "EVENT_MANAGER_D 必須存在");
    em->set_event_stage(EVENT_TIER2_CRISIS, STAGE_TIER2_T_MINUS_1, 1);
    em->set_metric(EVENT_TIER2_CRISIS, METRIC_EVIDENCE_STRENGTH, 3);
    em->set_metric(EVENT_TIER2_CRISIS, METRIC_EVIDENCE_VERIFIABILITY, 3);
    em->register_evidence("v3_field_evidence_chain", ([
        "name": "走山遺物與方舟樣本雙份保管鏈",
        "strength": 2,
        "source_type": "field_evidence_chain",
        "verified": 1
    ]));

    mapping eval_ready = em->evaluate_tier2_crisis();
    assert_equal("hearing_ready", eval_ready["readiness"], "齊備北荒與三宗證據後應達 hearing_ready");
    assert_true(eval_ready["v3_verified_sources"] >= 1, "已核驗 v3 物證來源數應至少為 1");

    string st_t0 = em->advance_event_stage(EVENT_TIER2_CRISIS);
    assert_equal(STAGE_TIER2_T_0, st_t0, "攜證歸山後應推進至 T0（雲頂質證與道化急變）");
    assert_equal("public_hearing_and_crisis", em->evaluate_tier2_crisis()["expedition_posture"],
                 "T0 階段態勢應為 public_hearing_and_crisis");
    assert_true(strsrch(em->dump_status(EVENT_TIER2_CRISIS), "v3_field_evidence_chain") != -1,
                "dump_status(EVENT_TIER2_CRISIS) 必須列出已登錄的第三卷現場物證");

    // 還原預設階段免影響其他測試隔離性
    em->set_metric(EVENT_TIER2_CRISIS, METRIC_EVIDENCE_STRENGTH, 0);
    em->set_metric(EVENT_TIER2_CRISIS, METRIC_EVIDENCE_VERIFIABILITY, 1);
    em->set_event_stage(EVENT_TIER2_CRISIS, STAGE_TIER2_T_MINUS_2, 1);

    // ── 2. 任務引擎：第三幕 5 條核心任務載入檢驗 ───────────────────
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(qe), "QUEST_ENGINE_D 必須存在");

    mapping act3_qcounts = ([
        "v3_north_wastes_expedition": 6,
        "v3_act3_war_god_tomb"      : 6,
        "v3_ark_excavation_evidence": 6,
        "v3_preserve_field_evidence": 3
    ]);
    foreach (string qid, int exp_steps in act3_qcounts) {
        mapping qd = qe->query_quest(qid);
        assert_true(mapp(qd), sprintf("第三幕任務 %s 必須存在", qid));
        if (qd) {
            assert_equal(exp_steps, sizeof(qd["steps"]),
                         sprintf("第三幕任務 %s 步驟數應為 %d", qid, exp_steps));
        }
    }
    mapping epic_res = qe->query_quest("v3_five_relic_resonance");
    assert_true(mapp(epic_res) && epic_res["total_stages"] == 3,
                "史詩任務 v3_five_relic_resonance 必須包含 3 個階段");

    // ── 3. 第三幕 16 間 /d/wastes 房間與接口聯通檢驗 ────────────────
    string *act3_rooms = ({
        "/d/wastes/black_mountain_pass.c",
        "/d/wastes/missing_families_hall.c",
        "/d/wastes/south_approach.c",
        "/d/wastes/snow_caravan_camp.c",
        "/d/wastes/north_outpost_infirmary.c",
        "/d/wastes/frozen_blood_plain.c",
        "/d/wastes/expedition_camp.c",
        "/d/wastes/rift_watch.c",
        "/d/wastes/black_ice_valley.c",
        "/d/wastes/old_expedition_camp.c",
        "/d/wastes/war_god_tomb.c",
        "/d/wastes/ark_foundation.c",
        "/d/wastes/ark_core_chamber.c",
        "/d/wastes/ark_logistics_hall.c",
        "/d/wastes/ark_cooling_breach.c",
        "/d/wastes/ice_valley_exit.c"
    });
    foreach (string rpath in act3_rooms) {
        object rob = load_object(rpath);
        assert_true(objectp(rob), sprintf("Act 3 房間 %s 必須成功載入", rpath));
        if (rob) {
            mapping exits = rob->query_exits();
            assert_true(mapp(exits) && sizeof(exits) >= 1,
                        sprintf("Act 3 房間 %s 必須有有效出口", rpath));
        }
    }
    object gw = load_object("/d/sects/bahuang/great_wall_gate.c");
    assert_equal("/d/wastes/black_mountain_pass.c", gw->query_exits()["north"],
                 "長城關口 north 必須連通至黑山長城北關雪道");

    // ── 4. 第三幕 8 位新增 NPC／荒獸與 9 項道具驗證 ─────────────────
    mapping npc_topics = ([
        "/clone/npc/qi_shiliu.c" : ({ "勘探隊", "主陣基" }),
        "/clone/npc/han_su.c"    : ({ "韓林", "遺址", "遺物編號" }),
        "/clone/npc/bai_yan.c"   : ({ "對照實驗", "樣本封存" }),
        "/clone/npc/yuan_qing.c" : ({ "晶絲", "三日後" })
    ]);
    foreach (string np, string *tps in npc_topics) {
        object nob = clone_object(np);
        assert_true(objectp(nob), sprintf("Act 3 NPC %s 必須成功實例化", np));
        if (nob) {
            foreach (string t in tps) {
                string ans = nob->query_response(t);
                assert_true(stringp(ans) && strlen(ans) > 5,
                            sprintf("%s 必須回應 '%s'", np, t));
            }
            destruct(nob);
        }
    }

    string *act3_mobs = ({
        "/clone/npc/shuangtou_dilong.c",
        "/clone/npc/ice_bear_king.c",
        "/clone/npc/private_league_envoy.c",
        "/clone/npc/tiger_mech_beast.c"
    });
    foreach (string mp in act3_mobs) {
        object mob = clone_object(mp);
        assert_true(objectp(mob), sprintf("Act 3 頭目/荒獸 %s 必須成功實例化", mp));
        if (mob) destruct(mob);
    }

    string *act3_items = ({
        "/clone/item/hanlin_copper_whistle.c",
        "/clone/item/ev3_yanshan_blood_note.c",
        "/clone/item/ev3_expedition_roster.c",
        "/clone/item/ev3_heart_guard_mirror.c",
        "/clone/item/ev3_drill_head.c",
        "/clone/item/ev3_mother_liquid_vial.c",
        "/clone/item/ev3_envoy_tally.c",
        "/clone/item/ninety_city_treaty_copy.c",
        "/clone/item/pill_herb_poultice.c"
    });
    foreach (string ip in act3_items) {
        object iob = clone_object(ip);
        assert_true(objectp(iob), sprintf("Act 3 道具 %s 必須成功實例化", ip));
        if (iob) destruct(iob);
    }

    // ── 5. 模擬玩家 Lv.85 推進 Act 3 主線、支線與史詩五器任務鏈 ────
    object tester = clone_object("/std/user.c");
    tester->set_id("v3_act3_tester");
    tester->set_level(85);

    // (a) 北荒勘探主線 (6 步)
    tester->move(load_object("/d/wastes/south_approach.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "qi_shiliu", "topic": "勘探隊" ]));
    tester->move(load_object("/d/wastes/snow_caravan_camp.c"));
    qe->trigger_event(tester, "action", ([ "verb": "inspect", "target": "sleighs" ]));
    tester->move(load_object("/d/wastes/frozen_blood_plain.c"));
    qe->trigger_event(tester, "kill", ([ "victim_id": "shuangtou_dilong" ]));
    assert_true(objectp(present("pill_herb_poultice", tester)), "擊敗雙頭霜甲地龍後應得雪線續脈膏實驗組");
    tester->move(load_object("/d/wastes/north_outpost_infirmary.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "bai_yan", "topic": "對照實驗" ]));
    tester->move(load_object("/d/wastes/black_ice_valley.c"));
    qe->trigger_event(tester, "action", ([ "verb": "excavate", "target": "remains" ]));
    assert_true(objectp(present("hanlin_copper_whistle", tester)), "勘驗黑冰斷谷應得韓林乙十七銅哨");
    tester->move(load_object("/d/wastes/ark_foundation.c"));
    qe->trigger_event(tester, "action", ([ "verb": "test", "target": "coolant" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_north_wastes_expedition"),
                 "化驗方舟冷卻母脈後應完成 v3_north_wastes_expedition");

    // (b) 戰神遺塚與血書護心鏡支線 (6 步)
    tester->move(load_object("/d/wastes/missing_families_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "han_su", "topic": "韓林" ]));
    tester->move(load_object("/d/wastes/rift_watch.c"));
    qe->trigger_event(tester, "action", ([ "verb": "rappel", "target": "cliff" ]));
    tester->move(load_object("/d/wastes/old_expedition_camp.c"));
    qe->trigger_event(tester, "action", ([ "verb": "search", "target": "alcove" ]));
    tester->move(load_object("/d/wastes/war_god_tomb.c"));
    qe->trigger_event(tester, "kill", ([ "victim_id": "ice_bear_king" ]));
    qe->trigger_event(tester, "action", ([ "verb": "resonate", "target": "totem" ]));
    assert_true(objectp(present("ev3_heart_guard_mirror", tester)), "戰神遺塚共鳴應得燕山凹損護心鏡");
    tester->move(load_object("/d/wastes/missing_families_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "han_su", "topic": "遺址" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_act3_war_god_tomb"),
                 "歸返互助所登錄遺址後應完成 v3_act3_war_god_tomb");

    // (c) 五器再鳴史詩任務 (Stage 1 -> Stage 2 -> Stage 3)
    tester->move(load_object("/d/wastes/ark_core_chamber.c"));
    qe->trigger_event(tester, "action", ([ "verb": "place", "target": "relics" ]));
    tester->move(load_object("/d/wastes/ark_logistics_hall.c"));
    qe->trigger_event(tester, "action", ([ "verb": "join", "target": "treaty" ]));
    assert_true(objectp(present("ninety_city_treaty_copy", tester)), "合璧總契後應得九城總契拓本");
    tester->move(load_object("/d/sects/taiqing/star_law_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "song_zhiwei", "topic": "五器訊號" ]));
    tester->move(load_object("/d/sects/tiangong/machinery_depths.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "ji_heng", "topic": "黑鐵結構" ]));
    assert_equal("DORMANT", qe->query_quest_state(tester, "v3_five_relic_resonance"),
                 "完成Stage 1後 v3_five_relic_resonance 應進入 DORMANT 等候Stage 2解鎖");
    tester->move(load_object("/d/yunjin/exchange_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "gu_lanzhou", "topic": "九城契版" ]));
    qe->trigger_event(tester, "talk", ([ "npc": "gu_lanzhou", "topic": "九城契版" ]));
    tester->move(load_object("/d/yunjin/ghost_market.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "gui_jianchou", "topic": "舊約" ]));
    tester->move(load_object("/d/wastes/south_approach.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "qi_shiliu", "topic": "主陣基" ]));
    qe->trigger_event(tester, "talk", ([ "npc": "qi_shiliu", "topic": "主陣基" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_five_relic_resonance"),
                 "完成 Stage 3 後應徹底結算 v3_five_relic_resonance");

    // (d) 母脈盜掘鎖閘與冰谷截殺封證 (6 步)
    tester->move(load_object("/d/sects/tiangong/array_drafting_room.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "wenjiu", "topic": "盜掘" ]));
    tester->move(load_object("/d/wastes/ark_cooling_breach.c"));
    qe->trigger_event(tester, "action", ([ "verb": "lock", "target": "valve" ]));
    assert_true(objectp(present("ev3_drill_head", tester)), "鎖死總閘應拾獲天工鑽頭殘件");
    tester->move(load_object("/d/wastes/ice_valley_exit.c"));
    qe->trigger_event(tester, "action", ([ "verb": "trigger", "target": "avalanche" ]));
    qe->trigger_event(tester, "kill", ([ "victim_id": "private_league_envoy" ]));
    assert_true(objectp(present("ev3_envoy_tally", tester)), "擊殺私盟大執事應得暗金令牌暨密令");
    tester->move(load_object("/d/sects/tiangong/array_drafting_room.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "wenjiu", "topic": "傀儡批次" ]));
    tester->move(load_object("/d/sects/tiangong/thousand_mechanisms_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "lu_zhanglao", "topic": "鑽頭殘件" ]));
    tester->move(load_object("/d/wastes/missing_families_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "han_su", "topic": "物證封存" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_ark_excavation_evidence"),
                 "互助所完成物證封存後應結束 v3_ark_excavation_evidence");

    destruct(tester);
}
