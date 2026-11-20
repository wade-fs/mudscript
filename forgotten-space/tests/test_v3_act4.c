// /tests/test_v3_act4.c
// 第三卷第四幕（Ch.112 ~ Ch.120）問道天台會武、萬寶商戰、公開質證、結晶毒域、冰獄骨龍與雲津新約驗證

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 2 第三卷第四幕（三宗會武、道化驚變與雲津新約）驗證");

    // ── 1. 世界事件系統：tier2_crisis T0 -> T+1 -> T+2 推進與防災結果 ──
    object em = load_object(EVENT_MANAGER_D);
    assert_true(objectp(em), "EVENT_MANAGER_D 必須存在");
    em->set_event_stage(EVENT_TIER2_CRISIS, STAGE_TIER2_T_0, 1);
    em->set_metric(EVENT_TIER2_CRISIS, METRIC_SETTLEMENT_RESILIENCE, 3);
    em->set_fact(EVENT_TIER2_CRISIS, "signal_arrows_ready", 1);

    string st_p1 = em->advance_event_stage(EVENT_TIER2_CRISIS);
    assert_equal(STAGE_TIER2_T_PLUS_1, st_p1, "骨龍叩關爆發時應單調推進至 T+1（北荒獸潮與三元鎮脈）");
    mapping eval_p1 = em->evaluate_tier2_crisis();
    assert_equal("stabilization_and_reform", eval_p1["expedition_posture"], "T+1 態勢應為 stabilization_and_reform");
    assert_equal("contained_with_scars", eval_p1["defense_outcome"], "備齊輪替與韌性達標時應呈現 contained_with_scars");

    string st_p2 = em->advance_event_stage(EVENT_TIER2_CRISIS);
    assert_equal(STAGE_TIER2_T_PLUS_2, st_p2, "雲津新約成立應推進至 T+2（戰後改革與洞天準備）");

    // 還原預設狀態免影響其他測試隔離性
    em->set_fact(EVENT_TIER2_CRISIS, "signal_arrows_ready", 0);
    em->set_metric(EVENT_TIER2_CRISIS, METRIC_SETTLEMENT_RESILIENCE, 2);
    em->set_event_stage(EVENT_TIER2_CRISIS, STAGE_TIER2_T_MINUS_2, 1);

    // ── 2. 任務引擎：第四幕全 7 條主/支/事件任務載入與步驟核驗 ────
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(qe), "QUEST_ENGINE_D 必須存在");
    mapping act4_qcounts = ([
        "v3_act4_cloud_top_tournament"       : 7,
        "v3_evidence_chain_hearing"          : 5,
        "v3_act4_sanyuan_defense"            : 5,
        "v3_postwar_reform_and_restitution"  : 4,
        "v3_cross_sect_evidence_audit"       : 3,
        "v3_crystal_quarantine_response"     : 3,
        "v3_north_wall_beast_surge"          : 3
    ]);
    foreach (string qid, int expected_steps in act4_qcounts) {
        mapping qd = qe->query_quest(qid);
        assert_true(mapp(qd), sprintf("第四幕任務 %s 必須已載入", qid));
        if (qd) {
            assert_equal(expected_steps, sizeof(qd["steps"]),
                         sprintf("第四幕任務 %s 步驟數應為 %d", qid, expected_steps));
        }
    }

    // ── 3. 第四幕 7 間新增房間載入與雙向出口聯通檢驗 ─────────────
    string *act4_rooms = ({
        "/d/yunjin/stone_arch_quarantine.c",
        "/d/yunjin/hearing_hall.c",
        "/d/yunjin/tournament_craft_arena.c",
        "/d/yunjin/tournament_combat_arena.c",
        "/d/yunjin/crystal_poison_edge.c",
        "/d/yunjin/west_street_recycling.c",
        "/d/sects/bahuang/west_wall_breach.c"
    });
    foreach (string rp in act4_rooms) {
        object rob = load_object(rp);
        assert_true(objectp(rob), sprintf("Act 4 房間 %s 必須成功載入", rp));
        if (rob) {
            mapping exits = rob->query_exits();
            assert_true(mapp(exits) && sizeof(exits) >= 1,
                        sprintf("Act 4 房間 %s 必須有有效出口", rp));
        }
    }
    assert_equal("/d/yunjin/stone_arch_quarantine.c",
                 load_object("/d/yunjin/wanshan_square.c")->query_exits()["northup"],
                 "萬山廣場 northup 應直登石牌坊暨問道天台");
    assert_equal("/d/sects/bahuang/west_wall_breach.c",
                 load_object("/d/sects/tiangong/machinery_depths.c")->query_exits()["north"],
                 "萬機地窟 north 玄鐵暗門應直通長城西段缺口");

    // ── 4. 第四幕 8 位 NPC／骨龍與 6 項新道具實例化檢驗 ──────────
    mapping act4_npcs = ([
        "/clone/npc/zixiao_zhenren.c" : ({ "聯席掌門令", "毒域" }),
        "/clone/npc/tiebei_shanzhu.c" : ({ "長城缺口", "忠烈歸籍" }),
        "/clone/npc/xuanshu_menzhu.c" : ({ "丙字柒號", "赤煉" }),
        "/clone/npc/zhao_lie.c"       : ({ "煞火魔偶" }),
        "/clone/npc/li_qingyun.c"     : ({ "九轉增元丹" }),
        "/clone/npc/wang_tieniu.c"    : ({ "急鎮丸" }),
        "/clone/npc/han_cang.c"       : ({ "青玉佩" })
    ]);
    foreach (string np, string *tps in act4_npcs) {
        object nob = clone_object(np);
        assert_true(objectp(nob), sprintf("Act 4 NPC %s 必須成功實例化", np));
        if (nob) {
            foreach (string t in tps) {
                assert_true(stringp(nob->query_response(t)) && strlen(nob->query_response(t)) > 5,
                            sprintf("%s 必須回應 '%s'", np, t));
            }
            destruct(nob);
        }
    }
    object dragon = clone_object("/clone/npc/ice_bone_dragon.c");
    assert_true(objectp(dragon) && dragon->id("ice_bone_dragon"), "Lv.95 冰獄骨龍必須實例化");
    if (dragon) destruct(dragon);

    string *act4_items = ({
        "/clone/item/sanyuan_shengji_dan.c",
        "/clone/item/brittle_shahuomou_shard.c",
        "/clone/item/wang_red_pill_vial.c",
        "/clone/item/wanbao_black_iron_box.c",
        "/clone/item/sanyuan_isolation_mist.c",
        "/clone/item/yunjin_relief_treaty.c"
    });
    foreach (string ip in act4_items) {
        object iob = clone_object(ip);
        assert_true(objectp(iob), sprintf("Act 4 道具 %s 必須成功實例化", ip));
        if (iob) destruct(iob);
    }

    // ── 5. 模擬玩家 Lv.92 完整推進第四幕四大主支線任務鏈 ──────────
    object tester = clone_object("/std/user.c");
    tester->set_id("v3_act4_tester");
    tester->set_level(92);

    // (a) 雲頂會武暨偏峰試治元青與萬寶擠兌稽核 (7 步)
    tester->move(load_object("/d/sects/taiqing/quiet_peak.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "jian_su", "topic": "三日後" ]));
    qe->trigger_event(tester, "action", ([ "verb": "cure", "target": "yuanqing" ]));
    tester->move(load_object("/d/yunjin/tournament_craft_arena.c"));
    qe->trigger_event(tester, "action", ([ "verb": "smash", "target": "puppet" ]));
    assert_true(objectp(present("brittle_shahuomou_shard", tester)), "破煞火魔偶後應得脆化主軸樣本");
    qe->trigger_event(tester, "action", ([ "verb": "test", "target": "needle" ]));
    assert_true(objectp(present("sanyuan_shengji_dan", tester)), "西台試毒後應得三元生機丹雙盲封樣");
    tester->move(load_object("/d/yunjin/tournament_combat_arena.c"));
    qe->trigger_event(tester, "kill", ([ "victim_id": "wang_tieniu" ]));
    assert_true(objectp(present("wang_red_pill_vial", tester)), "震破王鐵牛護心甲應封存暗紅丸藥瓶");
    qe->trigger_event(tester, "action", ([ "verb": "step", "target": "deadzone" ]));
    qe->trigger_event(tester, "kill", ([ "victim_id": "han_cang" ]));
    tester->move(load_object("/d/yunjin/exchange_hall.c"));
    qe->trigger_event(tester, "action", ([ "verb": "audit", "target": "wanbao" ]));
    assert_true(objectp(present("wanbao_black_iron_box", tester)), "萬寶稽核查封後應取後庫暗標帳箱摘要");
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_act4_cloud_top_tournament"),
                 "萬寶閣稽核落幕應完成 v3_act4_cloud_top_tournament");

    // (b) 公開質證五方查核席 (5 步)
    tester->move(load_object("/d/yunjin/hearing_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "luo_jiucheng", "topic": "公開質證" ]));
    qe->trigger_event(tester, "talk", ([ "npc": "luo_jiucheng", "topic": "商帳" ]));
    tester->move(load_object("/d/sects/bahuang/black_mountain_camp.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "lei_lie", "topic": "走山物證" ]));
    tester->move(load_object("/d/sects/danding/medical_archive.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "sun_wenlu", "topic": "病理證據" ]));
    tester->move(load_object("/d/sects/tiangong/machinery_depths.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "ji_heng", "topic": "盜掘物證" ]));
    tester->move(load_object("/d/yunjin/hearing_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "zixiao_zhenren", "topic": "聯席掌門令" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_evidence_chain_hearing"),
                 "聽宣聯席掌門令後應完成 v3_evidence_chain_hearing");

    // (c) 毒域救援與骨龍破關三元鎮脈陣防禦 (5 步)
    tester->move(load_object("/d/sects/taiqing/gate.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "lu_guanlan", "topic": "壓陣" ]));
    tester->move(load_object("/d/yunjin/crystal_poison_edge.c"));
    qe->trigger_event(tester, "action", ([ "verb": "brace", "target": "pillar" ]));
    tester->move(load_object("/d/yunjin/stone_arch_quarantine.c"));
    qe->trigger_event(tester, "action", ([ "verb": "spread", "target": "lime" ]));
    assert_true(objectp(present("sanyuan_isolation_mist", tester)), "生石灰防線與二十鍋藥霧應產出百草中和組");
    tester->move(load_object("/d/sects/bahuang/west_wall_breach.c"));
    qe->trigger_event(tester, "action", ([ "verb": "stabilize", "target": "array" ]));
    qe->trigger_event(tester, "kill", ([ "victim_id": "ice_bone_dragon" ]));
    tester->move(load_object("/d/yunjin/hearing_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "tiebei_shanzhu", "topic": "長城缺口" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_act4_sanyuan_defense"),
                 "向鐵背山主確認戰損與平反後應完成 v3_act4_sanyuan_defense");

    // (d) 雲津新約與西街無毒炭料回收廠 (4 步)
    tester->move(load_object("/d/yunjin/hearing_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "luo_jiucheng", "topic": "新約" ]));
    qe->trigger_event(tester, "talk", ([ "npc": "luo_jiucheng", "topic": "停採" ]));
    tester->move(load_object("/d/wastes/missing_families_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "han_su", "topic": "補償名冊" ]));
    tester->move(load_object("/d/yunjin/mudway_store.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "qiu_he", "topic": "共同治理" ]));
    tester->move(load_object("/d/yunjin/west_street_recycling.c"));
    qe->trigger_event(tester, "action", ([ "verb": "sign", "target": "treaty" ]));
    assert_true(objectp(present("yunjin_relief_treaty", tester)), "西街落簽協約應領取《雲津萬山臨時互市與救濟協約》");
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_postwar_reform_and_restitution"),
                 "簽署雲津新約與回收廠試辦條約後應完成 v3_postwar_reform_and_restitution");

    destruct(tester);
}
