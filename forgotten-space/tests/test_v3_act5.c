// /tests/test_v3_act5.c
// 第三卷第五幕（Ch.121 ~ Ch.126）百草格物突破、萬山共治託付、封存觀測室排斥劫雲與五器開門入 Tier 3 驗證

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"

void run_tests(object me) {
    start_test("Tier 2 第三卷第五幕（百草通玄、萬山託付與桃花源開門）驗證");

    // ── 1. 任務引擎：Act 5 雙任務載入與階段/步驟結構核驗 ─────────────
    object qe = load_object(QUEST_ENGINE_D);
    assert_true(objectp(qe), "QUEST_ENGINE_D 必須存在");

    mapping q_trials = qe->query_quest("v3_act5_lvl100_trials");
    assert_true(mapp(q_trials), "Act 5 v3_act5_lvl100_trials 必須已載入");
    if (q_trials) {
        assert_equal(6, sizeof(q_trials["steps"]), "v3_act5_lvl100_trials 應有 6 個步驟");
    }

    mapping q_dep = qe->query_quest("v3_tier2_departure");
    assert_true(mapp(q_dep), "Act 5 史詩收官任務 v3_tier2_departure 必須已載入");
    if (q_dep) {
        assert_equal(3, q_dep["total_stages"], "v3_tier2_departure 應為 3 階段史詩任務");
    }

    // ── 2. 第五幕 3 間新增房間載入、出口與 Tier 3 初窺空間檢驗 ─────────
    object peak = load_object("/d/sects/taiqing/quiet_peak.c");
    object seal = load_object("/d/sects/taiqing/sealed_observatory.c");
    object port = load_object("/d/sects/taiqing/ark_portal_chamber.c");
    object plateau = load_object("/d/realm/peach_plateau.c");

    assert_true(objectp(peak), "quiet_peak 必須載入");
    assert_true(objectp(seal), "sealed_observatory 必須載入");
    assert_true(objectp(port), "ark_portal_chamber 必須載入");
    assert_true(objectp(plateau), "Tier 3 peach_plateau 必須載入");

    assert_equal("/d/sects/taiqing/sealed_observatory.c",
                 peak->query_exits()["northeast"],
                 "清修偏峰 northeast 應通往封存觀測室");
    assert_equal("/d/sects/taiqing/quiet_peak.c",
                 seal->query_exits()["southwest"],
                 "封存觀測室 southwest 應返清修偏峰");
    assert_equal("/d/sects/taiqing/ark_portal_chamber.c",
                 seal->query_exits()["down"],
                 "封存觀測室 down 應沿深黑螺旋階梯通往祖庭方舟主傳送室");
    assert_equal("/d/sects/taiqing/sealed_observatory.c",
                 port->query_exits()["up"],
                 "祖庭主傳送室 up 應返封存觀測室");
    mapping p_exits = plateau->query_exits();
    assert_true(mapp(p_exits) && (!p_exits["south"] || strsrch(p_exits["south"], "/d/sects/") == -1) && !p_exits["down"],
                "單向古陣毀損後 Tier 3 桃花源高原不應有靜態返程出口回到 Tier 2");

    // ── 3. 第五幕新 NPC（周師叔）與 7 項新道具實例化檢驗 ──────────────
    object zhou = clone_object("/clone/npc/zhou_shishu.c");
    assert_true(objectp(zhou) && zhou->id("zhou_shishu"), "太清周執事 NPC 必須成功實例化");
    if (zhou) {
        assert_true(stringp(zhou->query_response("三元本草")) && strlen(zhou->query_response("三元本草")) > 10,
                    "周師叔必須回應三元本草禁忌單話題");
        destruct(zhou);
    }

    string *act5_items = ({
        "/clone/item/sanyuan_bencao_draft.c",
        "/clone/item/detachable_feedback_spec.c",
        "/clone/item/bahuang_rotation_manual.c",
        "/clone/item/reverse_star_addendum.c",
        "/clone/item/wanshan_charter_deed.c",
        "/clone/item/hometown_letters_bag.c",
        "/clone/item/ancestor_secret_record.c"
    });
    foreach (string ip in act5_items) {
        object iob = clone_object(ip);
        assert_true(objectp(iob), sprintf("Act 5 道具 %s 必須成功實例化", ip));
        if (iob) destruct(iob);
    }

    // ── 4. 模擬玩家先於 Lv.95 完成 Lv.100 破境試煉與故人託付 ──────────
    object tester = clone_object("/std/user.c");
    tester->set_id("v3_act5_tester");
    tester->set_level(95);

    tester->move(load_object("/d/sects/danding/medical_archive.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "zhou_shishu", "topic": "三元本草" ]));
    qe->trigger_event(tester, "action", ([ "verb": "publish", "target": "bencao" ]));

    tester->move(load_object("/d/sects/tiangong/machinery_depths.c"));
    qe->trigger_event(tester, "action", ([ "verb": "install", "target": "rig" ]));

    tester->move(load_object("/d/sects/bahuang/black_mountain_camp.c"));
    qe->trigger_event(tester, "action", ([ "verb": "compile", "target": "manual" ]));

    tester->move(load_object("/d/sects/taiqing/star_law_hall.c"));
    qe->trigger_event(tester, "action", ([ "verb": "publish", "target": "addendum" ]));

    tester->move(load_object("/d/yunjin/mudway_store.c"));
    qe->trigger_event(tester, "action", ([ "verb": "decentralize", "target": "ledger" ]));

    tester->move(load_object("/d/yunjin/mudway_store_cellar.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "mo_san", "topic": "三十年之約" ]));
    assert_true(objectp(present("hometown_letters_bag", tester)), "立三十年之約後應收到南方故人加急家書驛袋");
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_act5_lvl100_trials"),
                 "五人破境與託付應完成 v3_act5_lvl100_trials");

    // ── 5. 模擬推動《凡間排斥：五器驗證與桃花源古陣》3 階段史詩收官 ──
    tester->move(load_object("/d/sects/danding/medical_archive.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "sun_wenlu", "topic": "戰後修復" ]));
    qe->trigger_event(tester, "talk", ([ "npc": "sun_wenlu", "topic": "戰後修復" ]));
    tester->move(load_object("/d/sects/tiangong/machinery_depths.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "ji_heng", "topic": "機械回授" ]));
    tester->move(load_object("/d/sects/bahuang/black_mountain_camp.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "lei_lie", "topic": "破境紀錄" ]));
    tester->move(load_object("/d/yunjin/mudway_store.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "qiu_he", "topic": "商道託管" ]));
    assert_equal("DORMANT", qe->query_quest_state(tester, "v3_tier2_departure"),
                 "Stage 1 完成後應進入 DORMANT 等待觸及 Lv.100 排斥共鳴");

    // Stage 2: 晉入二階大圓滿 Lv.100，封存觀測室五器共鳴觸發排斥劫雲
    tester->set_level(100);
    tester->move(load_object("/d/sects/taiqing/star_law_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "song_zhiwei", "topic": "假天排斥" ]));
    tester->move(load_object("/d/sects/taiqing/sealed_observatory.c"));
    qe->trigger_event(tester, "action", ([ "verb": "resonate", "target": "relics" ]));
    tester->move(load_object("/d/sects/taiqing/star_law_hall.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "song_zhiwei", "topic": "假天排斥" ]));
    tester->move(load_object("/d/sects/tiangong/machinery_depths.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "ji_heng", "topic": "古陣風險" ]));
    assert_equal("DORMANT", qe->query_quest_state(tester, "v3_tier2_departure"),
                 "Stage 2 完成後應進入 DORMANT 等待祖庭主傳送室啟門");

    // Stage 3: 祖庭地底主傳送室五座石台校驗與開啟單向星門
    tester->move(load_object("/d/sects/taiqing/ark_portal_chamber.c"));
    qe->trigger_event(tester, "talk", ([ "npc": "qi_shiliu", "topic": "啟動古陣" ]));
    qe->trigger_event(tester, "talk", ([ "npc": "qi_shiliu", "topic": "同行確認" ]));
    qe->trigger_event(tester, "action", ([ "verb": "activate", "target": "gate" ]));
    qe->trigger_event(tester, "talk", ([ "npc": "song_zhiwei", "topic": "啟動古陣" ]));
    assert_equal("COMPLETED", qe->query_quest_state(tester, "v3_tier2_departure"),
                 "完成五座石台驗證並向宋知微確認啟動古陣後應全段通關 v3_tier2_departure");

    destruct(tester);
}
