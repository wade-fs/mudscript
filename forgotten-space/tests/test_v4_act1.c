// /tests/test_v4_act1.c
// 第四卷第一幕（Ch.127 ~ Ch.134）人物、房間拓撲、道具、K×U 連動與 3 條任務整合驗證

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 3 第四卷第一幕（灰燼石堡、殘晶黑市、醫棚與鷹記）驗證");

    // ── 1. 任務引擎：Act 1 全部 3 條任務載入與步驟驗證 ────────────────
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(qe), "QUEST_ENGINE_D 必須存在");

    string *qids = ({
        "v4_act1_bastion_arrival",
        "v4_act1_salt_market_stove",
        "v4_act1_clinic_and_eagle_mark"
    });
    foreach (string qid in qids) {
        mapping qdef = qe->query_quest(qid);
        assert_true(mapp(qdef), sprintf("第四卷 Act 1 任務 %s 必須已載入", qid));
        if (qdef) {
            assert_equal(3, sizeof(qdef["steps"]), sprintf("任務 %s 應包含 3 個步驟", qid));
        }
    }

    // ── 2. /d/realm/edge/ 5 間新房載入、對稱出口與五感覆蓋驗證 ────────
    string *edge_rooms = ({
        "/d/realm/edge/basalt_ridge.c",
        "/d/realm/edge/ash_watch_post.c",
        "/d/realm/edge/stardust_salt_flats.c",
        "/d/realm/edge/edge_clinic.c",
        "/d/realm/edge/scorch_border.c"
    });
    foreach (string rpath in edge_rooms) {
        object rob = load_object(rpath);
        assert_true(objectp(rob), sprintf("房間 %s 必須成功載入", rpath));
        if (rob) {
            assert_true(mapp(rob->query_exits()) && sizeof(rob->query_exits()) >= 1,
                        sprintf("房間 %s 必須具備對稱出口", rpath));
            assert_true(stringp(rob->query_touch("default")) && stringp(rob->query_smell("default")) && stringp(rob->query_listen("default")),
                        sprintf("房間 %s 必須具備完整三維感官", rpath));
        }
    }

    // 驗證 peach_plateau -> basalt_ridge -> ash_watch_post 雙向連結
    object plateau = load_object("/d/realm/peach_plateau.c");
    object ridge   = load_object("/d/realm/edge/basalt_ridge.c");
    object post    = load_object("/d/realm/edge/ash_watch_post.c");
    object salt    = load_object("/d/realm/edge/stardust_salt_flats.c");
    object clinic  = load_object("/d/realm/edge/edge_clinic.c");
    object scorch  = load_object("/d/realm/edge/scorch_border.c");

    assert_equal("/d/realm/edge/basalt_ridge.c", plateau->query_exits()["north"], "碎石高原 north 應通往玄武岩風道");
    assert_equal("/d/realm/peach_plateau.c", ridge->query_exits()["south"], "玄武岩風道 south 應返回碎石高原");
    assert_equal("/d/realm/edge/ash_watch_post.c", ridge->query_exits()["north"], "玄武岩風道 north 應通往灰燼石堡");
    assert_equal("/d/realm/edge/basalt_ridge.c", post->query_exits()["south"], "灰燼石堡 south 應返回玄武岩風道");
    assert_equal("/d/realm/edge/stardust_salt_flats.c", post->query_exits()["east"], "灰燼石堡 east 應通往星塵鹽田");
    assert_equal("/d/realm/edge/ash_watch_post.c", salt->query_exits()["west"], "星塵鹽田 west 應返回灰燼石堡");
    assert_equal("/d/realm/edge/edge_clinic.c", post->query_exits()["west"], "灰燼石堡 west 應通往邊緣醫棚");
    assert_equal("/d/realm/edge/ash_watch_post.c", clinic->query_exits()["east"], "邊緣醫棚 east 應返回灰燼石堡");
    assert_equal("/d/realm/edge/scorch_border.c", ridge->query_exits()["southwest"], "玄武岩風道 southwest 應通往赤黑焦土邊坡");
    assert_equal("/d/realm/edge/basalt_ridge.c", scorch->query_exits()["northeast"], "赤黑焦土邊坡 northeast 應返玄武岩風道");

    // ── 3. Act 1 NPC 與道具實例化檢驗 ────────────────────────────────
    mapping npc_topics = ([
        "/clone/npc/ash_warden_qi.c"         : ({ "機隼", "先輩", "暖爐" }),
        "/clone/npc/stone_clinic_healer_su.c": ({ "排異", "病例" }),
        "/clone/npc/salt_market_broker.c"    : ({ "鹽晶", "鐵牌" }),
        "/clone/npc/bastion_young_hunter.c"  : ({ "異獸", "鷹記" })
    ]);
    foreach (string np, string *tps in npc_topics) {
        object nob = clone_object(np);
        assert_true(objectp(nob), sprintf("NPC %s 必須實例化", np));
        if (nob) {
            foreach (string tp in tps) {
                assert_true(stringp(nob->query_response(tp)), sprintf("NPC %s 必須回應 %s", np, tp));
            }
            destruct(nob);
        }
    }
    object lizard = clone_object("/clone/npc/gray_sand_lizard.c");
    assert_true(objectp(lizard) && lizard->id("gray_sand_lizard"), "灰甲砂蜥必須實例化");
    if (lizard) destruct(lizard);

    string *items = ({
        "/clone/item/edge_ration_wooden_tally.c",
        "/clone/item/spent_salt_crystal_core.c",
        "/clone/item/removable_stove_core.c",
        "/clone/item/bastion_salt_route_map.c",
        "/clone/item/yanshan_eagle_rubbing.c"
    });
    foreach (string ip in items) {
        object iob = clone_object(ip);
        assert_true(objectp(iob), sprintf("道具 %s 必須實例化", ip));
        if (iob) destruct(iob);
    }

    // ── 4. 實地房間互動觸發 K×U 能力解鎖與三條任務連動驗證 ───────────
    object tester = clone_object("/std/user.c");
    tester->set_id("v4_act1_tester");
    tester->enable_commands();
    tester->recalc_stats();
    tester->set_path("fa");
    object t3 = load_object(TIER3_D);

    // 4a. 在 basalt_ridge 執行 measure vector 應自動解鎖 law K+U
    move_object(tester, ridge);
    assert_equal(1, tester->command("measure vector"), "basalt_ridge 應支援 measure vector 指令");
    assert_equal(1, t3->has_k(tester, "law"), "measure vector 後應寫入經實驗驗證的 tier3_k/law");
    assert_equal(1, t3->has_u(tester, "law"), "measure vector 後應經野測風砂路徑解鎖 tier3_u/law");

    // 4b. 在 ash_watch_post 執行 forge stove 應自動解鎖 craft K+U
    move_object(tester, post);
    assert_equal(1, tester->command("douse lamps"), "ash_watch_post 應支援 douse lamps");
    assert_equal(1, tester->command("test damping"), "ash_watch_post 應支援 test damping");
    assert_equal(1, tester->command("forge stove"), "ash_watch_post 應支援 forge stove");
    assert_equal(1, t3->has_k(tester, "craft"), "forge stove 後應寫入 tier3_k/craft");
    assert_equal(1, t3->has_u(tester, "craft"), "forge stove 後應解鎖 tier3_u/craft");

    // 4c. 在 stardust_salt_flats 與 scorch_border 寫入 commerce / force K
    move_object(tester, salt);
    assert_equal(1, tester->command("audit market"), "stardust_salt_flats 應支援 audit market");
    assert_equal(1, t3->has_k(tester, "commerce"), "audit market 後應寫入 tier3_k/commerce");

    move_object(tester, clinic);
    assert_equal(1, tester->command("diagnose patient"), "edge_clinic 應支援 diagnose patient");

    move_object(tester, scorch);
    assert_equal(1, tester->command("rub mark"), "scorch_border 應支援 rub mark");
    assert_equal(1, t3->has_k(tester, "force"), "rub mark 後應寫入 tier3_k/force");

    destruct(tester);
}
