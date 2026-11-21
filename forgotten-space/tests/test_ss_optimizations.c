// /tests/test_ss_optimizations.c
// 《從小說看 Mudlib：優化建議》(narrative/ss.md) 全方位功能驗證測試：
// 1. 感官與物質反饋 (touch / smell / listen) + 身世視角濾鏡 (Background Sensory Lens)
// 2. 物證主動出示 (present)、互相印證 (Mutual Corroboration) 與污染/公證修復 (Contamination & Cleanse)
// 3. 五器共鳴多階段技術校驗 (5-Station Technical Calibration & Diagnostics)
// 4. 傳聞衰減與扭曲 (Rumor Distortion vs Truth)、小說卷幕映射與歷史回放、會做 vs 有資格做

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/ansi.h"
#include "/include/world_event.h"

void run_tests(object me) {
    start_test("《從小說看 Mudlib：優化建議》(ss.md) 核心體驗與機制驗證");

    // ── 1. 感官與物質反饋 + 身世視角濾鏡驗證 ──────────────────────────
    object stream = load_object("/d/village/stream.c");
    object forge  = load_object("/d/village/forge.c");
    object altar  = load_object("/d/village/altar.c");
    object shed   = load_object("/d/village/shed.c");
    object plateau = load_object("/d/realm/peach_plateau.c");

    assert_true(objectp(stream) && objectp(forge) && objectp(altar) && objectp(shed) && objectp(plateau),
                "核心感官房間應能正常載入");

    assert_true(stringp(stream->query_touch("stone")) && strlen(stream->query_touch("stone")) > 10,
                "碎石溪灘應提供 touch stone 動態觸覺描寫");
    assert_true(stringp(forge->query_touch("dark stone")) && strsrch(forge->query_touch("dark stone"), "微米齒槽") != -1,
                "打鐵爐房 touch dark stone 應反饋太古冷硬與微米齒槽質感");
    assert_true(stringp(plateau->query_smell("default")) && strsrch(plateau->query_smell("default"), "苦杏仁") != -1,
                "桃花源高原 smell 應反饋第四卷苦杏仁鹽霜與太古源質氣味");

    object tester = clone_object("/std/user.c");
    tester->set_id("ss_opt_tester");
    tester->set("background", "herbalist");
    string bg_line = stream->query_bg_sensory_line(tester);
    assert_true(stringp(bg_line) && strsrch(bg_line, "晨露草") != -1,
                "採藥學徒在溪灘應觸發專屬感官濾鏡");

    tester->set("background", "smith");
    string smith_line = forge->query_bg_sensory_line(tester);
    assert_true(stringp(smith_line) && strsrch(smith_line, "打鐵學徒") != -1,
                "打鐵學徒在爐房應觸發專屬感官濾鏡");

    // ── 2. 物證出示、互相印證與污染修復驗證 ───────────────────────────
    object city_d = load_object(CITY_D);
    assert_true(objectp(city_d), "CITY_D 必須存在");

    object ev_det = clone_object("/clone/item/detonator_serial_ledger.c");
    object ev_clay = clone_object("/clone/item/liefan_clay_batch.c");
    object ev_miners = clone_object("/clone/item/miner_thumbprints.c");
    object qin = clone_object("/clone/npc/yamen_magistrate.c");
    object wen = clone_object("/clone/npc/center_wenchengjing.c");

    assert_true(objectp(ev_det) && objectp(ev_clay) && objectp(ev_miners) && objectp(qin) && objectp(wen),
                "物證與府衙 NPC 應可正常實例化");

    // 2.1 測試物證污染與拒收 -> 文承敬公證修復
    mapping contam = city_d->contaminate_evidence(ev_det, "暗渠死水浸泡");
    assert_equal(1, contam["contaminated"], "未封存物證涉水應標記為受污染");

    mapping rej = city_d->present_evidence_to_npc(tester, ev_det, qin);
    assert_equal("rejected_contaminated", rej["status"], "向府尹出示受污染物證應遭拒並提示重新公證");

    mapping clean = city_d->present_evidence_to_npc(tester, ev_det, wen);
    assert_equal("cleansed_and_certified", clean["status"], "向文承敬出示受污染物證應完成公證修復與火漆封存");
    assert_equal(0, ev_det->query("contaminated"), "修復後物證污染狀態應歸零");
    assert_equal(1, ev_det->query("sealed_custody"), "火漆封存後應具抗污染保護");

    // 2.2 測試單一孤證 vs 三證互鎖（互相印證質變）
    tester->set_temp("presented_evidence_list", ({}));
    mapping res1 = city_d->present_evidence_to_npc(tester, ev_det, qin);
    assert_equal("isolated_lead", res1["status"], "單獨出示雷管批號應判定為孤證難鳴");

    mapping res2 = city_d->present_evidence_to_npc(tester, ev_clay, qin);
    assert_equal("corroborated", res2["status"], "搭配耐火泥批次後應升級為交叉印證");

    mapping res3 = city_d->present_evidence_to_npc(tester, ev_miners, qin);
    assert_true(member_array("mine_sabotage_triad", res3["corroboration"]["synergies"]) != -1,
                "湊齊雷管批號+耐火泥+礦工血手印應觸發 mine_sabotage_triad 三證互鎖");

    // ── 3. 五器共鳴多階段技術校驗與錯誤診斷驗證 ────────────────────────
    object port = load_object("/d/sects/taiqing/ark_portal_chamber.c");
    tester->move(port);
    set_this_player(tester);
    port->do_calibrate("reset");
    assert_equal(0, port->query_calibrated_count(tester), "重置後五台校驗進度應為 0/5");

    // 跳步校驗應被攔截並給出工程診斷
    port->do_calibrate("northeast");
    assert_equal(0, port->query_calibrated_count(tester), "未鎖定正北座標前強行校驗東北傳動台應失敗");

    // 粗暴操作 (rough) 應給出公差/歲差警告
    port->do_calibrate("north rough");
    assert_equal(0, port->query_calibrated_count(tester), "未補償歲差強按星盤應校驗失敗");

    // 依序完成五台精密技術校驗
    port->do_calibrate("north");
    port->do_calibrate("northeast");
    port->do_calibrate("northwest");
    port->do_calibrate("southwest");
    port->do_calibrate("south");
    assert_equal(5, port->query_calibrated_count(tester), "依序完成五台技術校驗後進度應達 5/5");
    set_this_player(me);

    // ── 4. 傳聞扭曲 vs 聽風破妄、會做 vs 有資格做、卷幕映射與歷史回放 ──
    object rumor_d = load_object(RUMOR_D);
    tester->set("background", "herbalist");
    tester->set_temp("presented_evidence_list", ({}));
    mapping r_normal = rumor_d->query_distorted_rumor("caravan", tester);
    assert_equal(0, r_normal["can_discern_truth"], "一般背景未持物證時聽到的是失真三手傳聞");

    tester->set("background", "beggar");
    mapping r_beggar = rumor_d->query_distorted_rumor("caravan", tester);
    assert_equal(1, r_beggar["can_discern_truth"], "乞兒身世應能從失真傳聞中聽風破妄洞悉真相");

    // 會做 vs 有資格做
    tester->set("city_entry_time", time());
    mapping qual_chk = city_d->check_qualification_vs_skill(tester, "medical", "公開坐堂行醫");
    assert_equal(0, qual_chk["allowed"], "無杏林資格證時即使會醫術也不可在府城公開坐診");
    assert_equal("missing_qualification", qual_chk["reason"], "應明確指出缺少行會資格");

    // 小說卷幕映射與貢獻度歷史回放
    object em = load_object(EVENT_MANAGER_D);
    mapping act_info = em->query_novel_act_info(EVENT_BEAST_SURGE);
    assert_equal(1, act_info["volume"], "大荒煞潮應映射至第一卷");
    assert_equal(4, act_info["act"], "大荒煞潮應映射至第四幕");

    int c_score = em->record_player_contribution(EVENT_BEAST_SURGE, "ss_opt_tester", "rig_barrier", 15);
    assert_true(c_score >= 15, "玩家世界事件貢獻度應成功記錄");
    string replay = em->query_event_replay_summary(EVENT_BEAST_SURGE);
    assert_true(stringp(replay) && strsrch(replay, "ss_opt_tester") != -1,
                "歷史回放摘要應包含先行者貢獻紀錄");

    if (ev_det) destruct(ev_det);
    if (ev_clay) destruct(ev_clay);
    if (ev_miners) destruct(ev_miners);
    if (qin) destruct(qin);
    if (wen) destruct(wen);
    if (tester) destruct(tester);
}
