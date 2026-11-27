// /tests/test_combat_classes.c
// 三元力量（【力】li / 【法】fa / 【物】wu）、三柱資源（kee/sen/sp）、三角生剋與內城絕靈法網戰鬥驗證
inherit "/std/test_case";

#include "/include/globals.h"

void run_tests(object me) {
    start_test("三元戰鬥體系、三柱消耗與生剋驗證");

    object fighter_li = clone_object("/std/user.c");
    fighter_li->set_id("tester_li");
    fighter_li->set_name("測試力士");
    fighter_li->set_path("li");
    fighter_li->set_level(15);
    fighter_li->set_stat("str", 22);
    fighter_li->set_stat("con", 20);
    fighter_li->set_skill("wu_fuhu", 35);
    fighter_li->set_skill("wu_qixue", 35);
    fighter_li->set_kee(200);
    fighter_li->set_sen(100);
    fighter_li->set_sp(100);

    object target = clone_object("/npc/slime.c");
    target->set_level(50);
    target->set_stat("con", 50);
    target->recalc_stats();
    target->set_kee(target->query_max_kee());

    object room = load_object("/d/village/square.c");
    move_object(fighter_li, room);
    move_object(target, room);

    object combat_d = load_object(COMBAT_D);

    // 1. 測試【力】道招式施展 (wu_fuhu) 與氣血 (kee) 扣除
    int res = combat_d->do_perform(fighter_li, "wu_fuhu", target->query_key_id());
    assert_equal(1, res, "【力】道行者應能成功施展『伏虎重拳』(wu_fuhu)");
    assert_true(target->query_kee() < target->query_max_kee(), "目標氣血(kee)應該受到傷害");
    assert_equal(185, fighter_li->query_kee(), "【力】道招式應正確扣除 15 點氣血 (200 - 15)");

    // 2. 測試道途跨界限制（【法】道不得強行施展【力】道招式）
    fighter_li->set_path("fa");
    res = combat_d->do_perform(fighter_li, "wu_fuhu", target->query_key_id());
    assert_equal(0, res, "【法】道行者不應能施展【力】道專屬招式");

    // 3. 測試【法】道招式 (dao_jiefa) 與神識 (sen) 扣除
    fighter_li->set_sen(100);
    fighter_li->set_stat("int", 22);
    fighter_li->set_stat("spi", 22);
    fighter_li->set_skill("dao_jiefa", 35);
    target->set_kee(target->query_max_kee());
    res = combat_d->do_perform(fighter_li, "dao_jiefa", target->query_key_id());
    assert_equal(1, res, "【法】道行者應能成功施展『借法印訣』(dao_jiefa)");
    assert_equal(80, fighter_li->query_sen(), "【法】道招式應正確扣除 20 點神識 (100 - 20)");

    // 4. 測試【物】道招式 (gong_qiaojin) 與精力 (sp) 扣除
    fighter_li->set_path("wu");
    fighter_li->set_sp(100);
    fighter_li->set_stat("dex", 22);
    fighter_li->set_stat("per", 22);
    fighter_li->set_skill("gong_qiaojin", 35);
    target->set_kee(target->query_max_kee());
    res = combat_d->do_perform(fighter_li, "gong_qiaojin", target->query_key_id());
    assert_equal(1, res, "【物】道行者應能成功施展『百工巧勁』(gong_qiaojin)");
    assert_equal(85, fighter_li->query_sp(), "【物】道招式應正確扣除 15 點精力 (100 - 15)");

    // 5. 測試三角生剋公式（力剋法 125%、法剋物 125%、物剋力 125%、被克 85%）
    assert_equal(125, combat_d->calc_triangular_modifier("li", "fa"), "【力】剋【法】應有 125% 倍率加成");
    assert_equal(125, combat_d->calc_triangular_modifier("fa", "wu"), "【法】剋【物】應有 125% 倍率加成");
    assert_equal(125, combat_d->calc_triangular_modifier("wu", "li"), "【物】剋【力】應有 125% 倍率加成");
    assert_equal(85, combat_d->calc_triangular_modifier("fa", "li"), "【法】攻【力】被克應為 85% 倍率");

    // 6. 測試內城絕靈法網對無照【法】道施法的反噬與持度牒豁免
    object city_square = load_object("/d/city/center/square.c");
    move_object(fighter_li, city_square);
    move_object(target, city_square);
    fighter_li->set_path("fa");
    fighter_li->revoke_qualification("lic_diviner");
    fighter_li->set_sen(100);
    target->set_kee(target->query_max_kee());
    combat_d->do_perform(fighter_li, "dao_jiefa", target->query_key_id());
    assert_equal(70, fighter_li->query_sen(), "內城無照施展法術除消耗 20 神識外，應額外承受 10 點絕靈法網神識反噬 (100 - 20 - 10 = 70)");

    fighter_li->grant_qualification("lic_diviner", 1);
    fighter_li->set_sen(100);
    target->set_kee(target->query_max_kee());
    combat_d->do_perform(fighter_li, "dao_jiefa", target->query_key_id());
    assert_equal(80, fighter_li->query_sen(), "持有受牒度牒 (lic_diviner) 於內城施法應獲法網豁免，不承受神識反噬 (100 - 20 = 80)");

    report_results();
    destruct(fighter_li);
    if (target) destruct(target);
}
