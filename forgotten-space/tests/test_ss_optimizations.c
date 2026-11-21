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
    tester->enable_commands();
    tester->recalc_stats();
    tester->set_kee(100);
    tester->set_sen(100);
    tester->set_sp(100);
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
    move_object(tester, port);
    tester->command("calibrate reset");
    assert_equal(0, port->query_calibrated_count(tester), "重置後五台校驗進度應為 0/5");

    // 跳步校驗應被攔截並給出工程診斷
    tester->command("calibrate northeast");
    assert_equal(0, port->query_calibrated_count(tester), "未鎖定正北座標前強行校驗東北傳動台應失敗");

    // 粗暴操作 (rough) 應給出公差/歲差警告
    tester->command("calibrate north rough");
    assert_equal(0, port->query_calibrated_count(tester), "未補償歲差強按星盤應校驗失敗");

    // 依序完成五台精密技術校驗
    tester->command("calibrate north");
    tester->command("calibrate northeast");
    tester->command("calibrate northwest");
    tester->command("calibrate southwest");
    tester->command("calibrate south");
    assert_equal(5, port->query_calibrated_count(tester), "依序完成五台技術校驗後進度應達 5/5");

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

    // ── 5. 進階接線與宣告式架構驗證 ───────────────────────────────────
    // 5.1 cmd_set 與 brief_numeric 偏好切換
    object cmd_set = load_object("/cmds/cmd_set.c");
    assert_true(objectp(cmd_set), "cmd_set 指令應正常載入");
    cmd_set->main(tester, "set", "brief_numeric 1");
    assert_equal(1, tester->query("brief_numeric"), "應能開啟 brief_numeric 純感官模式");
    cmd_set->main(tester, "set", "brief_numeric 0");
    assert_equal(0, tester->query("brief_numeric"), "應能關閉 brief_numeric 恢復數值提示");

    // 5.2 cmd_chronicle 歷史回放指令
    object cmd_chr = load_object("/cmds/cmd_chronicle.c");
    assert_true(objectp(cmd_chr), "cmd_chronicle 指令應正常載入");
    int chr_ret = cmd_chr->main(tester, "chronicle", "");
    assert_equal(1, chr_ret, "chronicle 總覽應成功執行");

    // 5.3 暗渠樞紐移動自動污染未封存物證 + 偽造反噬 + 三卷互證
    object ev_unsealed = clone_object("/clone/item/liefan_clay_batch.c");
    ev_unsealed->move(tester);
    object canal = load_object("/d/city/under/canal_hub.c");
    assert_true(objectp(canal), "canal_hub 必須載入");
    move_object(tester, canal);
    assert_equal(1, ev_unsealed->query("contaminated"), "攜帶未封存物證進入暗渠污水應自動觸發污染");

    object ev_fake = clone_object("/clone/item/detonator_serial_ledger.c");
    ev_fake->set("is_forged", 1);
    mapping fake_res = city_d->present_evidence_to_npc(tester, ev_fake, qin);
    assert_equal("rejected_forged", fake_res["status"], "出示偽造物證應遭識破並觸發反噬");
    assert_true(tester->query("reputation_penalty") >= 10, "偽造被識破應扣除聲望");

    tester->set_temp("presented_evidence_list", ({}));
    object ev_v3_drill = clone_object("/clone/item/ev3_drill_head.c");
    object ev_v3_priv  = clone_object("/clone/item/ev3_private_purchase_ledger.c");
    city_d->present_evidence_to_npc(tester, ev_v3_drill, qin);
    mapping v3_syn = city_d->present_evidence_to_npc(tester, ev_v3_priv, qin);
    assert_true(member_array("v3_tiangong_sabotage_chain", v3_syn["corroboration"]["synergies"]) != -1,
                "三卷北荒鑽頭與秘密採辦帳冊應觸發 v3_tiangong_sabotage_chain 互鎖");

    // 5.4 宣告式動作規則與府城「會做 vs 有資格做」現場攔截 (clinic)
    object clinic = load_object("/d/city/center/clinic.c");
    assert_true(objectp(clinic) && sizeof(clinic->query_action_rules()) >= 1,
                "杏林醫館應使用 std/room 宣告式動作規則");
    move_object(tester, clinic);
    int pre_exp = tester->query_exp();
    tester->revoke_qualification("lic_apothecary");
    tester->command("diagnose");
    assert_equal(pre_exp, tester->query_exp(), "無行醫資格證時於醫館公開坐診應遭攔截");
    tester->grant_qualification_by("lic_apothecary", 1, "杏林醫館");
    tester->command("diagnose");
    assert_true(tester->query_exp() > pre_exp, "持有行醫資格證後於醫館坐診應成功獲得歷練");

    // 5.5 五器校驗 strict 實體信物＋隊友協同 + ark_core_chamber 5 階凹龕
    object teammate = clone_object("/std/user.c");
    teammate->set_id("ss_teammate");
    teammate->enable_commands();
    teammate->set("background", "daoist");
    object rubbing = clone_object("/clone/item/stele_rubbing.c");
    rubbing->move(teammate);
    move_object(tester, port);
    move_object(teammate, port);
    tester->command("calibrate reset");
    tester->command("calibrate north strict");
    assert_equal(1, port->query_calibrated_count(tester), "同殿隊友持有逆星拓片應能協助通過 strict 模式正北校驗");

    object core = load_object("/d/wastes/ark_core_chamber.c");
    move_object(tester, core);
    tester->command("place reset");
    tester->command("place northeast");
    assert_equal(0, core->query_core_placed_count(tester), "核心圓台未嵌入正北星軌龕前嵌入東北龕應失敗");
    tester->command("place north");
    tester->command("place northeast");
    assert_equal(2, core->query_core_placed_count(tester), "依序嵌入核心圓台凹龕應正確推進進度");

    // 5.6 QUEST_ENGINE_D 幕次倍率 + 五道組隊協同 + NPC 身世態度 + EVENT_MANAGER 貢獻階梯結算
    object qe = load_object(QUEST_ENGINE_D);
    move_object(teammate, core);
    teammate->set_leader(tester);
    int syn_pct = qe->query_party_background_synergy_pct(tester);
    assert_true(syn_pct >= 10, "不同身世隊友同場應觸發五道協同互補獎勵加成");

    object mochui = clone_object("/clone/npc/gong_mochui.c");
    mochui->set("faction", "baigong");
    tester->set("background", "smith");
    string att = mochui->query_bg_attitude_prefix(tester);
    assert_true(stringp(att) && strsrch(att, "厚繭") != -1, "百工 NPC 對打鐵學徒身世應展現專屬態度差異");

    int old_tm = em->query_test_mode();
    em->set_test_mode(1);
    em->reset_event(EVENT_TIER2_CRISIS);
    em->record_player_contribution(EVENT_TIER2_CRISIS, "ss_opt_tester", "calib", 15);
    mapping settled = em->distribute_contribution_rewards(EVENT_TIER2_CRISIS);
    em->set_test_mode(old_tm);
    assert_true(mapp(settled) && mapp(settled["ss_opt_tester"]) && settled["ss_opt_tester"]["tier"] == "pillar",
                "事件貢獻結算應依貢獻度頒發對應榮譽階梯");

    if (ev_unsealed) destruct(ev_unsealed);
    if (ev_fake) destruct(ev_fake);
    if (ev_v3_drill) destruct(ev_v3_drill);
    if (ev_v3_priv) destruct(ev_v3_priv);
    if (mochui) destruct(mochui);
    if (teammate) destruct(teammate);
    if (ev_det) destruct(ev_det);
    if (ev_clay) destruct(ev_clay);
    if (ev_miners) destruct(ev_miners);
    if (qin) destruct(qin);
    if (wen) destruct(wen);
    if (tester) destruct(tester);
    report_results();
}
