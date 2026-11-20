// /tests/test_v3_act2.c
// 第三卷第二幕（Ch.91 ~ Ch.101）人物、房間、道具、事件評估與任務整合驗證測試

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 2 第三卷第二幕（宗門深造、偏科之影與五方對帳）驗證");

    // ── 1. 世界事件系統：tier2_crisis 動態評估與 T-2 -> T-1 推進 ───
    object em = load_object(EVENT_MANAGER_D);
    assert_true(objectp(em), "EVENT_MANAGER_D 必須存在");
    mapping eval_t2 = em->evaluate_tier2_crisis();
    assert_true(mapp(eval_t2) && eval_t2["stage"] == STAGE_TIER2_T_MINUS_2,
                "tier2_crisis evaluate_tier2_crisis 初始態勢應為 T-2");
    assert_equal("fact_gathering", eval_t2["expedition_posture"],
                 "T-2 階段應處於線索蒐集態勢");

    string next_st = em->advance_event_stage(EVENT_TIER2_CRISIS);
    assert_equal(STAGE_TIER2_T_MINUS_1, next_st, "Ch.101 聯合勘探公文發出後應單調推進至 T-1");
    mapping eval_t1 = em->evaluate_tier2_crisis();
    assert_equal("expedition_mobilized", eval_t1["expedition_posture"],
                 "T-1 階段應切換為北荒勘探動員態勢");
    em->set_event_stage(EVENT_TIER2_CRISIS, STAGE_TIER2_T_MINUS_2, 1);

    // ── 2. 任務引擎：第二幕全部 8 條主支線任務載入檢驗 ──────────
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(qe), "QUEST_ENGINE_D 必須存在");

    mapping act2_qcounts = ([
        "v3_taiqing_star_archive"         : 4,
        "v3_act2_taiqing_ascension_secret": 3,
        "v3_bahuang_bloodline_watch"      : 3,
        "v3_act2_bahuang_ghost_gorge"     : 4,
        "v3_tiangong_ancient_mechanism"   : 4,
        "v3_danding_blood_pill_cases"     : 5,
        "v3_five_way_evidence_convergence": 4,
        "v3_act2_yunjin_ghost_and_sanyuan": 5
    ]);

    foreach (string qid, int expected_steps in act2_qcounts) {
        mapping qdef = qe->query_quest(qid);
        assert_true(mapp(qdef), sprintf("第二幕任務 %s 必須已載入", qid));
        if (qdef) {
            assert_equal(expected_steps, sizeof(qdef["steps"]),
                         sprintf("第二幕任務 %s 步驟數必須相符", qid));
        }
    }

    // ── 3. 第二幕 21 間新增房間載入與出口檢驗 ─────────────────────
    string *act2_rooms = ({
        "/d/sects/taiqing/hidden_archive.c",
        "/d/sects/taiqing/outer_observatory.c",
        "/d/sects/taiqing/quiet_peak.c",
        "/d/sects/taiqing/ascension_platform.c",
        "/d/sects/bahuang/restoration_hall.c",
        "/d/sects/bahuang/north_garrison_kitchen.c",
        "/d/sects/bahuang/great_wall_gate.c",
        "/d/sects/bahuang/north_watch.c",
        "/d/sects/bahuang/ghost_cry_gorge.c",
        "/d/sects/tiangong/forge_yard.c",
        "/d/sects/tiangong/array_drafting_room.c",
        "/d/sects/tiangong/machinery_depths.c",
        "/d/sects/tiangong/vault_four.c",
        "/d/sects/danding/medical_archive.c",
        "/d/sects/danding/earth_fire_pill_cave.c",
        "/d/sects/danding/discarded_pill_cliff.c",
        "/d/yunjin/mudway_store_cellar.c",
        "/d/yunjin/three_sect_market.c",
        "/d/yunjin/mountain_caravan_yard.c",
        "/d/yunjin/ghost_market.c",
        "/d/yunjin/wanbao_back_alley.c"
    });

    foreach (string rpath in act2_rooms) {
        object rob = load_object(rpath);
        assert_true(objectp(rob), sprintf("Act 2 房間 %s 必須成功載入", rpath));
        if (rob) {
            mapping exits = rob->query_exits();
            assert_true(mapp(exits) && sizeof(exits) >= 1,
                        sprintf("Act 2 房間 %s 必須具備有效出口", rpath));
        }
    }

    // ── 4. 第二幕核心 NPC 實例化與關鍵對話回應檢驗 ─────────────
    mapping npc_checks = ([
        "/clone/npc/yu_shouzhuo.c"               : ({ "原始星圖", "蟲蛀舊箱" }),
        "/clone/npc/jian_su.c"                   : ({ "坐化", "元青" }),
        "/clone/npc/xuan_ming.c"                 : ({ "坐化", "調核令" }),
        "/clone/npc/du_qinghe.c"                 : ({ "傷兵", "急鎮丸" }),
        "/clone/npc/qi_wushang.c"                : ({ "鬼哭冰澗", "夜震" }),
        "/clone/npc/a_man.c"                     : ({ "失蹤者", "韓素" }),
        "/clone/npc/ji_heng.c"                   : ({ "維護", "脆化麻點" }),
        "/clone/npc/wenjiu.c"                    : ({ "脈衝", "延長線" }),
        "/clone/npc/chi_lian.c"                  : ({ "晶柱", "特殊工單" }),
        "/clone/npc/sun_wenlu.c"                 : ({ "病案", "急鎮丸" }),
        "/clone/npc/tao_sheng.c"                 : ({ "封存", "白猿" }),
        "/clone/npc/gray_robed_scribe.c"         : ({ "黑鐵箱" }),
        "/clone/npc/a_si.c"                      : ({ "稽查" }),
        "/clone/npc/mo_beggar.c"                 : ({ "玄木", "敲山震虎" }),
        "/clone/npc/under_black_market_broker.c" : ({ "黑鐵箱", "延命私盟" })
    ]);

    foreach (string npath, string *topics in npc_checks) {
        object nob = clone_object(npath);
        assert_true(objectp(nob), sprintf("Act 2 NPC %s 必須成功實例化", npath));
        if (nob) {
            foreach (string tp in topics) {
                string resp = nob->query_response(tp);
                assert_true(stringp(resp) && strlen(resp) > 5,
                            sprintf("NPC %s 必須對 '%s' 具備回應", npath, tp));
            }
            destruct(nob);
        }
    }

    object yak = clone_object("/clone/npc/iron_yak.c");
    assert_true(objectp(yak) && yak->id("iron_yak"), "鐵甲寒犛必須成功實例化");
    if (yak) destruct(yak);

    object mo_alias = clone_object("/clone/npc/mo_beggar.c");
    assert_true(objectp(mo_alias) && mo_alias->id("mo_san"), "莫三必須包含 mo_san 別名");
    if (mo_alias) destruct(mo_alias);

    object broker_alias = clone_object("/clone/npc/under_black_market_broker.c");
    assert_true(objectp(broker_alias) && broker_alias->id("gui_jianchou"), "鬼見愁必須包含 gui_jianchou 別名");
    if (broker_alias) destruct(broker_alias);

    // ── 5. 第二幕 8 項新增證物與樣本實例化檢驗 ─────────────────
    string *act2_items = ({
        "/clone/item/tool_star_observation_plate.c",
        "/clone/item/yanshan_broken_arrow.c",
        "/clone/item/bahuang_logistics_copy.c",
        "/clone/item/sample_discarded_pill.c",
        "/clone/item/pill_reverse_dao_life.c",
        "/clone/item/ev3_private_purchase_ledger.c",
        "/clone/item/cyan_crystal_filament_vial.c",
        "/clone/item/tiangong_anchor_blueprint.c"
    });

    foreach (string ipath in act2_items) {
        object iob = clone_object(ipath);
        assert_true(objectp(iob), sprintf("Act 2 道具 %s 必須成功實例化", ipath));
        if (iob) {
            assert_true(strlen(iob->query_name()) > 0, sprintf("道具 %s 必須具備名稱", ipath));
            destruct(iob);
        }
    }

    // ── 6. 模擬玩家接取與推進第二幕核心任務鏈 ───────────────────
    object tester = clone_object("/std/user.c");
    tester->set_id("v3_act2_tester");
    tester->set_level(72);

    // (a) 太清藏星秘閣星曆校讀閉環
    tester->move(load_object("/d/sects/taiqing/star_law_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "song_zhiwei", "topic": "星圖校讀" ]));
    assert_equal(2, qe->query_quest_step(tester, "v3_taiqing_star_archive"),
                 "向宋知微申領星圖校讀後應推進至 step 2");

    tester->move(load_object("/d/sects/taiqing/hidden_archive.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "yu_shouzhuo", "topic": "原始星圖" ]));
    qe->trigger_event(tester, "action", ([ "verb": "collate", "target": "archive" ]));
    assert_equal(4, qe->query_quest_step(tester, "v3_taiqing_star_archive"),
                 "藏星秘閣完成 collate archive 後應推進至 step 4");
    assert_true(objectp(present("tool_star_observation_plate", tester)),
                "完成秘閣抄錄後應頒發星曆觀測校驗板");

    tester->move(load_object("/d/sects/taiqing/gate.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "lu_guanlan", "topic": "歲差" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_taiqing_star_archive"),
                 "向陸觀瀾回報歲差後應完成 v3_taiqing_star_archive");

    // (b) 雲津鬼市截帳與泥途地窖三元剝離晶絲閉環
    tester->move(load_object("/d/yunjin/exchange_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "gu_lanzhou", "topic": "匯兌" ]));
    tester->move(load_object("/d/yunjin/ghost_market.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "gui_jianchou", "topic": "黑鐵箱" ]));
    tester->move(load_object("/d/yunjin/wanbao_back_alley.c"));
    qe->trigger_event(tester, "action", ([ "verb": "rumor", "target": "audit" ]));
    assert_true(objectp(present("ev3_private_purchase_ledger", tester)),
                "暗巷散播稽核風聲後應截獲延命私盟密帳索引");

    tester->move(load_object("/d/yunjin/mudway_store_cellar.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "mo_san", "topic": "玄木" ]));
    qe->trigger_event(tester, "action", ([ "verb": "strip", "target": "filament" ]));
    assert_true(objectp(present("cyan_crystal_filament_vial", tester)),
                "地窖執行 strip filament 後應取得淡青晶絲樣本管");

    tester->move(load_object("/d/yunjin/public_office.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "luo_jiucheng", "topic": "聯合勘探" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_act2_yunjin_ghost_and_sanyuan"),
                 "確認聯合勘探輜重招標後應完成 v3_act2_yunjin_ghost_and_sanyuan");

    // (c) 鬼哭冰澗戰功與斷箭／軍需副本取得
    tester->move(load_object("/d/sects/bahuang/gate.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "tang_ying", "topic": "鬼哭冰澗" ]));
    tester->move(load_object("/d/sects/bahuang/great_wall_gate.c"));
    qe->trigger_event(tester, "kill", ([ "victim_id": "iron_yak" ]));
    tester->move(load_object("/d/sects/bahuang/ghost_cry_gorge.c"));
    qe->trigger_event(tester, "action", ([ "verb": "probe", "target": "ice" ]));
    assert_true(objectp(present("yanshan_broken_arrow", tester)),
                "鬼哭冰澗 probe ice 後應獲得燕山鷹記斷折骨箭");

    destruct(tester);
}
