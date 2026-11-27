// /tests/test_v4_act2_4.c
// 第四卷 Act 2~4（Ch.135 ~ Ch.164）三極 11 新房、10 NPC、11 道具、19 條任務與五線校準整合測試

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 3 第四卷第二至四幕（太虛／戰祖／萬物、互助密約與五方校準）驗證");

    // ── 1. 任務引擎：Act 2~4 全部 19 條任務載入檢核 ────────────────────
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(qe), "QUEST_ENGINE_D 必須存在");

    string *qids = ({
        // Act 2 (6)
        "v4_act2_taixu_calibration_spy",
        "v4_act2_wanwu_ark_registry",
        "v4_act2_zhanzu_yanshan_trail",
        "v4_act2_law_rejection_clinic",
        "v4_act2_nine_city_offline_node",
        "v4_act2_countdown_convergence",
        // Act 3 (7)
        "v4_act3_labor_pact_stations",
        "v4_act3_three_pole_mutual_compact",
        "v4_act3_cross_realm_broker_intercept",
        "v4_act3_taixu_scan_deflection",
        "v4_act3_arena_rescue_yanshan",
        "v4_act3_human_seed_bridge_truce",
        "v4_act3_ten_day_war_prep",
        // Act 4 (6)
        "v4_act4_labor_strike_sanction",
        "v4_act4_taixu_star_deflection",
        "v4_act4_bone_gate_defense",
        "v4_act4_clinic_fog_and_conduit",
        "v4_act4_arbitration_equal_charter",
        "v4_act4_postwar_clinic_relief"
    });
    foreach (string qid in qids) {
        mapping qdef = qe->query_quest(qid);
        assert_true(mapp(qdef), sprintf("第四卷 Act 2~4 任務 %s 必須已載入", qid));
        if (qdef) {
            assert_true(arrayp(qdef["steps"]) && sizeof(qdef["steps"]) >= 1,
                        sprintf("任務 %s 至少應包含 1 個步驟", qid));
        }
    }

    // ── 2. 11 間三極新房載入、對稱出口與五感覆蓋驗證 ──────────────────
    string *pole_rooms = ({
        "/d/realm/taixu/white_jade_steps.c",
        "/d/realm/taixu/calibration_hall.c",
        "/d/realm/taixu/crystal_tower_core.c",
        "/d/realm/zhanzu/bone_gate.c",
        "/d/realm/zhanzu/hunting_camp.c",
        "/d/realm/zhanzu/arena_pit.c",
        "/d/realm/wanwu/scrap_ring.c",
        "/d/realm/wanwu/ark_registry_hall.c",
        "/d/realm/wanwu/nine_city_node.c",
        "/d/realm/wanwu/arbitration_bridge.c",
        "/d/realm/wanwu/conduit_well.c"
    });
    foreach (string rpath in pole_rooms) {
        object rob = load_object(rpath);
        assert_true(objectp(rob), sprintf("三極房間 %s 必須成功載入", rpath));
        if (rob) {
            assert_true(mapp(rob->query_exits()) && sizeof(rob->query_exits()) >= 1,
                        sprintf("三極房間 %s 必須具備對稱出口", rpath));
            assert_true(stringp(rob->query_touch("default")) && stringp(rob->query_smell("default")) && stringp(rob->query_listen("default")),
                        sprintf("三極房間 %s 必須具備完整三維感官", rpath));
        }
    }

    // 對稱接縫檢驗（/d/realm/edge/ -> taixu / wanwu / zhanzu）
    object post   = load_object("/d/realm/edge/ash_watch_post.c");
    object salt   = load_object("/d/realm/edge/stardust_salt_flats.c");
    object scorch = load_object("/d/realm/edge/scorch_border.c");
    object taixu1 = load_object("/d/realm/taixu/white_jade_steps.c");
    object taixu2 = load_object("/d/realm/taixu/calibration_hall.c");
    object taixu3 = load_object("/d/realm/taixu/crystal_tower_core.c");
    object zz1    = load_object("/d/realm/zhanzu/bone_gate.c");
    object zz2    = load_object("/d/realm/zhanzu/hunting_camp.c");
    object zz3    = load_object("/d/realm/zhanzu/arena_pit.c");
    object ww1    = load_object("/d/realm/wanwu/scrap_ring.c");
    object ww2    = load_object("/d/realm/wanwu/ark_registry_hall.c");
    object ww3    = load_object("/d/realm/wanwu/nine_city_node.c");
    object ww4    = load_object("/d/realm/wanwu/arbitration_bridge.c");
    object ww5    = load_object("/d/realm/wanwu/conduit_well.c");

    assert_equal("/d/realm/taixu/white_jade_steps.c", post->query_exits()["north"], "灰燼石堡 north 應接通太虛白玉階");
    assert_equal("/d/realm/edge/ash_watch_post.c", taixu1->query_exits()["south"], "白玉階 south 應返回灰燼石堡");
    assert_equal("/d/realm/taixu/calibration_hall.c", taixu1->query_exits()["northup"], "白玉階 northup 應接校準偏殿");
    assert_equal("/d/realm/taixu/white_jade_steps.c", taixu2->query_exits()["southdown"], "校準偏殿 southdown 應返白玉階");
    assert_equal("/d/realm/taixu/crystal_tower_core.c", taixu2->query_exits()["north"], "校準偏殿 north 應接晶塔核心");
    assert_equal("/d/realm/taixu/calibration_hall.c", taixu3->query_exits()["south"], "晶塔核心 south 應返校準偏殿");

    assert_equal("/d/realm/zhanzu/bone_gate.c", scorch->query_exits()["southwest"], "焦土邊坡 southwest 應接通戰祖巨骨哨卡");
    assert_equal("/d/realm/edge/scorch_border.c", zz1->query_exits()["northeast"], "巨骨哨卡 northeast 應返回焦土邊坡");
    assert_equal("/d/realm/zhanzu/hunting_camp.c", zz1->query_exits()["west"], "巨骨哨卡 west 應接戰祖外營");
    assert_equal("/d/realm/zhanzu/bone_gate.c", zz2->query_exits()["east"], "戰祖外營 east 應返巨骨哨卡");
    assert_equal("/d/realm/zhanzu/arena_pit.c", zz1->query_exits()["south"], "巨骨哨卡 south 應接鬥獸坑");
    assert_equal("/d/realm/zhanzu/bone_gate.c", zz3->query_exits()["north"], "鬥獸坑 north 應返巨骨哨卡");

    assert_equal("/d/realm/wanwu/scrap_ring.c", salt->query_exits()["east"], "星塵鹽田 east 應接通萬物外環");
    assert_equal("/d/realm/edge/stardust_salt_flats.c", ww1->query_exits()["west"], "萬物外環 west 應返回星塵鹽田");
    assert_equal("/d/realm/wanwu/ark_registry_hall.c", ww1->query_exits()["east"], "萬物外環 east 應接方舟登錄廊");
    assert_equal("/d/realm/wanwu/scrap_ring.c", ww2->query_exits()["west"], "登錄廊 west 應返外環");
    assert_equal("/d/realm/wanwu/nine_city_node.c", ww2->query_exits()["down"], "登錄廊 down 應下潛九城總庫");
    assert_equal("/d/realm/wanwu/ark_registry_hall.c", ww3->query_exits()["up"], "九城總庫 up 應返登錄廊");
    assert_equal("/d/realm/wanwu/arbitration_bridge.c", ww2->query_exits()["east"], "登錄廊 east 應通往秩序仲裁橋");
    assert_equal("/d/realm/wanwu/ark_registry_hall.c", ww4->query_exits()["west"], "仲裁橋 west 應返登錄廊");
    assert_equal("/d/realm/wanwu/conduit_well.c", ww1->query_exits()["south"], "萬物外環 south 應下通地底導流井");
    assert_equal("/d/realm/wanwu/scrap_ring.c", ww5->query_exits()["north"], "導流井 north 應返外環");

    // ── 3. Act 2~4 10 名 NPC 實例化與話題檢驗 ────────────────────────
    mapping npc_topics = ([
        "/clone/npc/taixu_observer_heng.c"   : ({ "日誌", "嚴平" }),
        "/clone/npc/taixu_clerk_yanping.c"   : ({ "鹽晶", "檢索" }),
        "/clone/npc/wanwu_auditor_qi.c"      : ({ "銅匣", "走私", "停工" }),
        "/clone/npc/wanwu_inspector_chen.c"  : ({ "達成率", "清零" }),
        "/clone/npc/wanwu_arbiter_core.c"    : ({ "火種", "沈雲妮" }),
        "/clone/npc/zhanzu_packmaster_tuo.c" : ({ "心核", "韓石", "藥膏" }),
        "/clone/npc/zhanzu_quartermaster_han.c": ({ "配額", "鬥獸坑" }),
        "/clone/npc/yan_shan.c"              : ({ "暗倉", "密牌" }),
        "/clone/npc/cross_realm_broker.c"    : ({ "赤火", "雲津" })
    ]);
    foreach (string np, string *tps in npc_topics) {
        object nob = clone_object(np);
        assert_true(objectp(nob), sprintf("三極 NPC %s 必須實例化", np));
        if (nob) {
            foreach (string tp in tps) {
                assert_true(stringp(nob->query_response(tp)), sprintf("NPC %s 必須回應 %s", np, tp));
            }
            destruct(nob);
        }
    }
    object beast = clone_object("/clone/npc/lava_bone_beast.c");
    assert_true(objectp(beast) && beast->id("lava_bone_beast"), "赤炎熔骨獸必須實例化");
    if (beast) destruct(beast);

    // ── 4. Act 2~4 11 件道具實例化檢驗 ───────────────────────────────
    string *items = ({
        "/clone/item/locked_data_casket.c",
        "/clone/item/steady_copper_core.c",
        "/clone/item/taixu_calibration_log_copy.c",
        "/clone/item/ark_pod_nine_manifest.c",
        "/clone/item/law_rejection_buffer_kit.c",
        "/clone/item/human_seed_quota_ledger.c",
        "/clone/item/three_pole_mutual_compact.c",
        "/clone/item/cross_realm_chihuo_crate.c",
        "/clone/item/yanshan_encrypted_tally.c",
        "/clone/item/sanyuan_shunt_valve.c",
        "/clone/item/shen_yunnini_charter_edict.c"
    });
    foreach (string ip in items) {
        object iob = clone_object(ip);
        assert_true(objectp(iob), sprintf("道具 %s 必須成功實例化", ip));
        if (iob) destruct(iob);
    }

    // ── 5. 角色實測房間指令、K×U 第二觀察路徑與事件評估連動 ──────────
    object p = clone_object("/std/user.c");
    assert_true(objectp(p), "測試玩家必須建立成功");
    object t3 = load_object(TIER3_D);
    object em = load_object(EVENT_MANAGER_D);
    assert_true(objectp(t3) && objectp(em), "TIER3_D 與 EVENT_MANAGER_D 必須可用");

    if (p && t3 && em) {
        p->set_id("act24_tester");
        p->enable_commands();
        p->recalc_stats();

        // Act 2 互動與 U 第二觀察路徑驗證
        move_object(p, taixu1);
        assert_equal(1, p->command("copy log"), "白玉階 copy log 應成功");
        assert_equal(1, t3->has_k(p, "law"), "copy log 後應寫入 tier3_k/law");
        assert_equal(1, t3->has_u(p, "law"), "copy log 後應解鎖 tier3_u/law 第二路徑");

        move_object(p, ww1);
        assert_equal(1, p->command("repair axle"), "萬物外環 repair axle 應成功");
        assert_equal(1, t3->has_k(p, "craft"), "repair axle 後應寫入 tier3_k/craft");
        assert_equal(1, t3->has_u(p, "craft"), "repair axle 後應解鎖 tier3_u/craft 第二路徑");

        move_object(p, ww2);
        assert_equal(1, p->command("check manifest"), "方舟登錄廊 check manifest 應成功");

        move_object(p, ww3);
        assert_equal(1, p->command("register ledger"), "九城總庫 register ledger 應成功");
        assert_equal(1, t3->has_k(p, "commerce"), "register ledger 後應寫入 tier3_k/commerce");
        assert_equal(1, t3->has_u(p, "commerce"), "register ledger 後應解鎖 tier3_u/commerce");

        move_object(p, zz2);
        assert_equal(1, p->command("hunt beast"), "戰祖外營 hunt beast 應成功");
        assert_equal(1, t3->has_k(p, "force"), "hunt beast 後應寫入 tier3_k/force");
        assert_equal(1, t3->has_u(p, "force"), "hunt beast 後應解鎖 tier3_u/force");

        object clinic = load_object("/d/realm/edge/edge_clinic.c");
        move_object(p, clinic);
        assert_equal(1, p->command("brew buffer"), "醫棚 brew buffer 應成功");
        assert_equal(1, t3->has_k(p, "medicine"), "brew buffer 後應寫入 tier3_k/medicine");
        assert_equal(1, t3->has_u(p, "medicine"), "brew buffer 後應解鎖 tier3_u/medicine");

        // Act 3/4 關鍵動作與 EVENT_TIER3_CALIBRATION 狀態機整合
        move_object(p, post);
        assert_equal(1, p->command("converge ledger"), "守夜寨 converge ledger 應成功");
        assert_equal(1, p->command("sign compact"), "守夜寨 sign compact 應成功");
        assert_equal(1, p->command("deflect scan"), "守夜寨 deflect scan 應成功");
        assert_equal(1, p->command("prepare war"), "守夜寨 prepare war 應成功");

        move_object(p, zz3);
        assert_equal(1, p->command("unlock cage"), "鬥獸坑 unlock cage 應成功");

        move_object(p, ww1);
        assert_equal(1, p->command("ambush broker"), "萬物外環 ambush broker 應成功");
        assert_equal(1, p->command("declare strike"), "萬物外環 declare strike 應成功");

        move_object(p, taixu2);
        assert_equal(1, p->command("insert needle"), "校準偏殿 insert needle 應成功");
        move_object(p, taixu3);
        assert_equal(1, p->command("inspect core"), "晶塔核心 inspect core 應成功");

        move_object(p, zz1);
        assert_equal(1, p->command("hold gate"), "巨骨哨卡 hold gate 應成功");

        move_object(p, clinic);
        assert_equal(1, p->command("light stoves"), "醫棚 light stoves 應成功");
        assert_equal(1, p->command("tend wounded"), "醫棚 tend wounded 應成功");

        move_object(p, ww5);
        assert_equal(1, p->command("swap valve"), "地底導流井 swap valve 應成功");

        move_object(p, ww4);
        assert_equal(1, p->command("invoke treaty"), "仲裁橋 invoke treaty 應成功");
        assert_equal(1, p->command("equalize charter"), "仲裁橋 equalize charter 應成功");

        // 驗證 EVENT_TIER3_CALIBRATION 純函式評估輸出結構
        mapping eval_t3 = em->evaluate_tier3_calibration();
        assert_true(mapp(eval_t3) && stringp(eval_t3["calibration_outcome"]) && stringp(eval_t3["stage"]),
                    "evaluate_tier3_calibration 必須回傳合法評估結果");

        // 清理測試角色與克隆物品
        foreach (object inv in all_inventory(p)) {
            if (inv) destruct(inv);
        }
        destruct(p);
    }
}
