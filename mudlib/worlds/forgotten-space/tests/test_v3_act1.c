// /tests/test_v3_act1.c
// 第三卷第一幕（Ch.83 ~ Ch.90）人物、房間、事件與任務整合驗證測試

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 2 第三卷第一幕（北境寒原、雲津商埠與三山入門）驗證");

    // ── 1. 世界事件系統：tier2_crisis 載入與階段檢驗 ───────────
    object em = load_object(EVENT_MANAGER_D);
    assert_true(objectp(em), "EVENT_MANAGER_D 必須存在");
    mapping t2_def = em->query_event_def(EVENT_TIER2_CRISIS);
    assert_true(mapp(t2_def) && t2_def["id"] == EVENT_TIER2_CRISIS, "tier2_crisis 事件定義必須已註冊載入");
    assert_true(em->query_event_stage(EVENT_TIER2_CRISIS) == STAGE_TIER2_T_MINUS_2, "tier2_crisis 初始階段應為 T-2");

    // ── 2. 任務引擎：第一幕全部 7 條主支線任務載入檢驗 ──────────
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(qe), "QUEST_ENGINE_D 必須存在");

    string *act1_qids = ({
        "v3_act1_cold_plain_rescue",
        "v3_northbound_and_yunjin_arrival",
        "v3_yuntu_market_charter",
        "v3_act1_taiqing_ladder",
        "v3_act1_bahuang_gorge",
        "v3_act1_tiangong_forge",
        "v3_act1_danding_valley"
    });

    foreach (string qid in act1_qids) {
        mapping qdef = qe->query_quest(qid);
        assert_true(mapp(qdef), sprintf("第一幕任務 %s 必須已載入", qid));
        if (qdef) {
            assert_true(sizeof(qdef["steps"]) == 3, sprintf("第一幕任務 %s 應包含 3 個步驟", qid));
        }
    }

    // ── 3. 第一幕 20 間房間載入與出口連通性驗證 ─────────────────
    string *act1_rooms = ({
        "/d/wastes/north_road/cold_plain_entry.c",
        "/d/wastes/north_road/post_station.c",
        "/d/wastes/north_road/qing_pass.c",
        "/d/yunjin/north_road_gate.c",
        "/d/yunjin/wanshan_square.c",
        "/d/yunjin/public_office.c",
        "/d/yunjin/exchange_hall.c",
        "/d/yunjin/wanbao_pavilion.c",
        "/d/yunjin/western_warehouse_street.c",
        "/d/yunjin/mudway_store.c",
        "/d/sects/taiqing/gate.c",
        "/d/sects/taiqing/outer_court.c",
        "/d/sects/taiqing/star_law_hall.c",
        "/d/sects/bahuang/gate.c",
        "/d/sects/bahuang/black_stone_gorge.c",
        "/d/sects/bahuang/black_mountain_camp.c",
        "/d/sects/tiangong/gate.c",
        "/d/sects/tiangong/thousand_mechanisms_hall.c",
        "/d/sects/danding/gate.c",
        "/d/sects/danding/herb_garden.c"
    });

    foreach (string rpath in act1_rooms) {
        object rob = load_object(rpath);
        assert_true(objectp(rob), sprintf("房間 %s 必須成功載入", rpath));
        if (rob) {
            mapping exits = rob->query_exits();
            assert_true(mapp(exits) && sizeof(exits) >= 1, sprintf("房間 %s 必須具備有效出口", rpath));
        }
    }

    // 驗證鎮風北塞已向北接通北境寒原
    object beacon = load_object("/d/counties/zhenfeng/north_beacon.c");
    assert_true(objectp(beacon) && mapp(beacon->query_exits()) &&
                beacon->query_exits()["north"] == "/d/wastes/north_road/cold_plain_entry.c",
                "鎮風望荒烽燧向北必須接通北境寒原");

    // ── 4. 第一幕核心 NPC 實例化與對話回應驗證 ───────────────────
    mapping npc_checks = ([
        "/clone/npc/mu_xue.c"         : ({ "北境行旅", "退門者" }),
        "/clone/npc/zhou_tieshan.c"   : ({ "退門者", "泥途" }),
        "/clone/npc/chen_qing.c"      : ({ "潰爛", "水脈" }),
        "/clone/npc/luo_jiucheng.c"   : ({ "登記", "租約" }),
        "/clone/npc/he_wanjin.c"      : ({ "試單", "冷風坡" }),
        "/clone/npc/gu_lanzhou.c"     : ({ "保書", "履約" }),
        "/clone/npc/qiu_he.c"         : ({ "短契", "帳簿" }),
        "/clone/npc/lu_guanlan.c"     : ({ "登天梯", "歲差" }),
        "/clone/npc/song_zhiwei.c"    : ({ "誤差", "星圖校讀" }),
        "/clone/npc/shen_zhaochen.c"  : ({ "登天梯" }),
        "/clone/npc/yue_tingshan.c"   : ({ "問心谷", "鐵背荒狼" }),
        "/clone/npc/tang_ying.c"      : ({ "箭矢", "傷亡" }),
        "/clone/npc/lei_lie.c"        : ({ "入營", "燕山" }),
        "/clone/npc/lu_zhanglao.c"    : ({ "工單", "脆化" }),
        "/clone/npc/zhang_bailian.c"  : ({ "搬山傀儡", "卡尺" }),
        "/clone/npc/bai_henian.c"     : ({ "試藥", "冷萃" }),
        "/clone/npc/ye_qingzhi.c"     : ({ "藥田", "雪線苔" }),
        "/clone/npc/he_shou.c"        : ({ "雪線苔", "延命丹" })
    ]);

    foreach (string npath, string *topics in npc_checks) {
        object nob = clone_object(npath);
        assert_true(objectp(nob), sprintf("NPC %s 必須成功實例化", npath));
        if (nob) {
            foreach (string tp in topics) {
                string resp = nob->query_response(tp);
                assert_true(stringp(resp) && strlen(resp) > 5,
                            sprintf("NPC %s 必須對關鍵字 '%s' 具備對話回應", npath, tp));
            }
            destruct(nob);
        }
    }

    object wolf = clone_object("/clone/npc/ironback_wolf.c");
    assert_true(objectp(wolf) && wolf->id("ironback_wolf"), "黑石峽缺耳鐵背狼王必須成功實例化");
    if (wolf) destruct(wolf);

    // ── 5. 第一幕 8 項新道具與信物實例化檢驗 ───────────────────
    string *act1_items = ({
        "/clone/item/cold_herbal_decoction.c",
        "/clone/item/snowline_moss_sample.c",
        "/clone/item/puppet_tolerance_record.c",
        "/clone/item/yunjin_trade_ledger.c",
        "/clone/item/cred_taiqing_outer_token.c",
        "/clone/item/cred_bahuang_camp_plate.c",
        "/clone/item/cred_tiangong_artisan_tag.c",
        "/clone/item/cred_danding_medical_tag.c"
    });

    foreach (string ipath in act1_items) {
        object iob = clone_object(ipath);
        assert_true(objectp(iob), sprintf("道具 %s 必須成功實例化", ipath));
        if (iob) {
            assert_true(strlen(iob->query_name()) > 0, sprintf("道具 %s 必須具備名稱", ipath));
            destruct(iob);
        }
    }

    // ── 6. 模擬玩家接取並推進第一幕主線與支線任務 ──────────────
    object tester = clone_object("/std/user.c");
    tester->set_id("v3_act1_tester");
    tester->set_level(52);

    // 模擬：斷崖石棚驛站開啟寒原與雲津任務
    object post = load_object("/d/wastes/north_road/post_station.c");
    tester->move(post);
    qe->trigger_event(tester, "talk", ([ "npc": "mu_xue", "topic": "北境行旅" ]));
    assert_equal(1, qe->query_quest_step(tester, "v3_northbound_and_yunjin_arrival"),
                 "詢問穆雪北境行旅應啟動或推進 v3_northbound_and_yunjin_arrival");

    // 模擬：登天雲梯實測問心陣公差
    object tq_gate = load_object("/d/sects/taiqing/gate.c");
    tester->move(tq_gate);
    qe->trigger_event(tester, "talk", ([ "npc": "lu_guanlan", "topic": "登天梯" ]));
    qe->trigger_event(tester, "talk", ([ "npc": "lu_guanlan", "topic": "問心陣" ]));
    assert_equal(2, qe->query_quest_step(tester, "v3_act1_taiqing_ladder"),
                 "請教陸觀瀾問心陣後應推進至 step 2");

    qe->trigger_event(tester, "action", ([ "verb": "measure", "target": "ladder" ]));
    assert_equal(3, qe->query_quest_step(tester, "v3_act1_taiqing_ladder"),
                 "完成 measure ladder 實測公差後應推進至 step 3");

    destruct(tester);
}
