// /tests/test_v2_quests.c
// 卷二主線與五道資質認證、西水門危局、六物證缺口、六縣連環任務鏈單元測試
// 驗證項目：
// 1. QUEST_ENGINE_D 成功載入六大卷二任務定義
// 2. 卷二專屬物證與資質道具實例化及屬性檢驗
// 3. 核心 NPC 對話關鍵字與響應檢驗
// 4. 模擬玩家接取與推進任務狀態機檢驗

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 1 卷二主線、五道資質認證與六縣連環物證任務鏈驗證");

    object q_engine = load_object(QUEST_ENGINE_D);
    assert_true(objectp(q_engine), "QUEST_ENGINE_D 必須存在");

    // ── 1. 任務定義載入驗證 ──────────────────────────────────
    string *v2_qids = ({
        "v2_panmu_transport",
        "v2_residency_72h",
        "v2_career_tier1_qualifications",
        "v2_west_watergate_crisis",
        "v2_six_evidence_gaps",
        "v2_six_county_evidence"
    });

    foreach (string qid in v2_qids) {
        mapping qdef = q_engine->query_quest(qid);
        assert_true(mapp(qdef), sprintf("任務 %s 定義必須已載入", qid));
        if (qdef) {
            assert_true(strlen(qdef["name"]) > 0, sprintf("任務 %s 必須包含名稱", qid));
            assert_true(sizeof(qdef["steps"]) >= 2, sprintf("任務 %s 必須包含至少2個步驟", qid));
        }
    }

    // ── 2. 新增道具與信物實例化驗證 ──────────────────────────
    string *items_to_test = ({
        "/clone/item/custody_ledger.c",
        "/clone/item/residency_tally.c",
        "/clone/item/stress_wedge.c",
        "/clone/item/solvent_resin.c",
        "/clone/item/sluice_cable.c",
        "/clone/item/lic_artisan.c",
        "/clone/item/lic_apothecary.c",
        "/clone/item/lic_escort_guard.c",
        "/clone/item/lic_diviner.c",
        "/clone/item/lic_broker.c",
        "/clone/item/evidence_six_gaps.c",
        "/clone/item/liefan_clay_batch.c",
        "/clone/item/relay_poison_sample.c",
        "/clone/item/shan_token_half.c",
        "/clone/item/yunji_roster.c",
        "/clone/item/zhongshi_timber_order.c",
        "/clone/item/fengshi_quartz.c"
    });

    foreach (string item_path in items_to_test) {
        object ob = clone_object(item_path);
        assert_true(objectp(ob), sprintf("道具 %s 必須能成功複製實例", item_path));
        if (ob) {
            assert_true(strlen(ob->query_name()) > 0, sprintf("道具 %s 必須具備名稱", item_path));
            assert_true(strlen(ob->query_short()) > 0, sprintf("道具 %s 必須具備描述短名", item_path));
            destruct(ob);
        }
    }

    // ── 3. 核心 NPC 關鍵字回應檢驗 ──────────────────────────
    mapping npc_tests = ([
        "/clone/npc/gate_south_taxofficer.c": ({ "入城", "通牒" }),
        "/clone/npc/center_wenchengjing.c":   ({ "移交", "文卷" }),
        "/clone/npc/gate_south_inn_laoliu.c":  ({ "緩衝信物", "夜議", "四線", "凍結" }),
        "/clone/npc/gate_west_helmsman.c":    ({ "水閘", "合閘" }),
        "/clone/npc/gate_west_inspector.c":   ({ "濁膠" }),
        "/clone/npc/under_drain_gate_diver.c":({ "潛游", "鋼索" }),
        "/clone/npc/gong_mochui.c":           ({ "校準", "匠帖", "耐火泥" }),
        "/clone/npc/center_doctor_bai.c":     ({ "辨毒", "醫籍", "毒囊" }),
        "/clone/npc/wu_bashan.c":             ({ "盤石", "鏢師帖", "走山令" }),
        "/clone/npc/dao_xingyuan.c":          ({ "星軌", "觀象牒" }),
        "/clone/npc/center_pawn_jia.c":       ({ "死帳", "牙帖", "雲記" }),
        "/clone/npc/market_special_buyer.c":  ({ "六縣", "鐵木" }),
        "/clone/npc/su_ningshuang.c":         ({ "四線", "雲記", "停職" })
    ]);

    foreach (string npc_path, string *topics in npc_tests) {
        object npc = clone_object(npc_path);
        assert_true(objectp(npc), sprintf("NPC %s 必須能成功複製實例", npc_path));
        if (npc) {
            foreach (string top in topics) {
                string resp = npc->query_response(top);
                assert_true(stringp(resp) && strlen(resp) > 0, sprintf("NPC %s 必須對關鍵字 '%s' 具有響應", npc_path, top));
            }
            destruct(npc);
        }
    }

    // ── 4. 模擬任務接取與推進狀態機檢驗 ──────────────────────
    object tester = clone_object("/std/user.c");
    tester->set_id("v2_quest_tester");
    tester->set_level(15);

    // 測試 v2_panmu_transport 接取
    mapping data1 = ([
        "npc": "caravan_merchant",
        "topic": "押解"
    ]);
    q_engine->trigger_event(tester, "talk", data1);
    int step1 = q_engine->query_quest_step(tester, "v2_panmu_transport");
    assert_equal(2, step1, "在黑石鋪詢問押解後，v2_panmu_transport 應推進至 step 2");

    // 測試 v2_residency_72h 接取
    mapping data2 = ([
        "npc": "gate_south_taxofficer",
        "topic": "入城"
    ]);
    q_engine->trigger_event(tester, "talk", data2);
    int step2 = q_engine->query_quest_step(tester, "v2_residency_72h");
    assert_equal(2, step2, "在金石南關詢問入城後，v2_residency_72h 應推進至 step 2");

    // 測試 v2_six_county_evidence 接取
    mapping data3 = ([
        "npc": "gate_south_inn_laoliu",
        "topic": "四線"
    ]);
    q_engine->trigger_event(tester, "talk", data3);
    int step3 = q_engine->query_quest_step(tester, "v2_six_county_evidence");
    assert_equal(2, step3, "在南關小棧詢問四線後，v2_six_county_evidence 應推進至 step 2");

    destruct(tester);
}
