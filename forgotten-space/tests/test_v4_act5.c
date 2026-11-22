// /tests/test_v4_act5.c
// 第四卷 Act 5（Ch.165 ~ Ch.170）微光信標、自治議會、三元雛流試驗與 Tier 4 門檻隔離驗證

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 3 第四卷第五幕（微光信標、自治議會、三元雛流與歸墟門縫）驗證");

    // ── 1. 任務引擎：Act 5 全部 4 條任務載入檢核 ──────────────────────
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(qe), "QUEST_ENGINE_D 必須存在");

    string *qids = ({
        "v4_act5_beacon_crystal_gathering",
        "v4_act5_two_way_beacon_and_guixu",
        "v4_act5_bastion_autonomy_council",
        "v4_act5_three_yuan_prototype_trial"
    });
    foreach (string qid in qids) {
        mapping qdef = qe->query_quest(qid);
        assert_true(mapp(qdef), sprintf("第四卷 Act 5 任務 %s 必須已載入", qid));
    }

    // ── 2. beacon_relay 與對稱出口／三維感官檢驗 ──────────────────────
    object post    = load_object("/d/realm/edge/ash_watch_post.c");
    object beacon  = load_object("/d/realm/edge/beacon_relay.c");
    object ridge   = load_object("/d/realm/edge/basalt_ridge.c");
    object plateau = load_object("/d/realm/peach_plateau.c");

    assert_true(objectp(beacon), "跨界微光共鳴信標台必須成功載入");
    assert_true(stringp(beacon->query_touch("default")) && stringp(beacon->query_smell("default")) && stringp(beacon->query_listen("default")),
                "beacon_relay 必須具備完整三維感官");
    assert_equal("/d/realm/edge/beacon_relay.c", post->query_exits()["southwest"], "守夜寨 southwest 應通往微光信標台");
    assert_equal("/d/realm/edge/ash_watch_post.c", beacon->query_exits()["northeast"], "微光信標台 northeast 應返回守夜寨");

    // ── 3. Act 5 雙道具實例化檢核 ─────────────────────────────────────
    foreach (string ip in ({ "/clone/item/two_way_beacon_token.c", "/clone/item/guixu_threshold_record.c" })) {
        object iob = clone_object(ip);
        assert_true(objectp(iob), sprintf("Act 5 道具 %s 必須成功實例化", ip));
        if (iob) destruct(iob);
    }

    // ── 4. 完整互動流程、高代價信標限制與 Tier 4 不自動解鎖檢驗 ───────
    object p = clone_object("/std/user.c");
    assert_true(objectp(p), "Act 5 測試角色必須建立成功");
    object t3 = load_object(TIER3_D);
    assert_true(objectp(t3), "TIER3_D 必須可用");

    if (p && t3) {
        p->set_id("v4_act5_tester");
        p->enable_commands();
        p->recalc_stats();

        // 4a. 微光信標台：300 斤鹽晶籌集 + 嚴禁活人 + 限重 5 兩發送
        move_object(p, beacon);
        assert_equal(1, p->command("gather crystal"), "beacon_relay 應支援 gather crystal");
        assert_equal(300, p->query_temp("tier3/beacon_salt_ready"), "gather crystal 後應備齊 300 斤高純鹽晶");
        assert_equal(1, p->command("send beacon"), "beacon_relay 應支援 send beacon");
        assert_true(p->query("tier3_beacon_sent") >= 1, "send beacon 後應記錄發信次數");
        assert_true(objectp(present("two_way_beacon_token", p)), "send beacon 後應獲得《兩界微光家書囊》");

        // 4b. 守夜寨：自治去留議會
        move_object(p, post);
        assert_equal(1, p->command("hold council"), "守夜寨應支援 hold council");
        assert_equal(1, p->query_temp("tier3/autonomy_council_done"), "hold council 後應寫入自治議會完成標記");

        // 4c. 玄武岩風道：五人三元雛流試驗（不自動授予 Tier 4 資格）
        move_object(p, ridge);
        assert_equal(1, p->command("test resonance"), "basalt_ridge 應支援 test resonance");
        assert_equal(1, p->query_temp("tier3/three_yuan_prototype_tested"), "test resonance 後應記錄原型試驗標記");

        // 4d. 碎石高原：窺見歸墟門縫並確認 Tier 4 獨立三要件門檻未被旁路
        move_object(p, plateau);
        assert_equal(1, p->command("peer fissure"), "peach_plateau 應支援 peer fissure");
        assert_true(objectp(present("guixu_threshold_record", p)), "peer fissure 後應取得《歸墟古淵門縫拓銘》");

        mapping gate = t3->evaluate_tier4_unlock_eligibility(p);
        assert_equal(0, gate["eligible"], "完成 Act 5 與窺見歸墟門縫後，未集齊 §4.2 三要件絕不自動解鎖 Tier 4");

        foreach (object inv in all_inventory(p)) {
            if (inv) destruct(inv);
        }
        destruct(p);
    }
}
