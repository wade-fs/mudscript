// /tests/test_guilds.c
inherit "/std/test_case";

void run_tests(object me) {
    start_test("公會與勢力系統驗證");

    object me = clone_object("/std/user.c");
    me->set_name("測試志願者");
    me->set_level(10);
    me->set_stat("str", 25);
    me->set_stat("int", 25);
    
    object guild_d = load_object("/secure/guild_d.c");

    // 1. 測試加入公會
    int res = guild_d->join_guild(me, "fighter");
    assert_equal(1, res, "應該可以成功加入戰士盟約");
    assert_equal("fighter", me->query_guild(), "公會屬性應正確設定");
    assert_equal("見習鬥士", me->query_guild_rank(), "初始職位應正確");

    // 2. 測試重複加入 (應該失敗)
    res = guild_d->join_guild(me, "mage");
    assert_equal(0, res, "不應該能同時加入兩個公會");

    // 3. 測試職位晉升
    me->add_guild_exp(1200);
    res = guild_d->promote_member(me);
    assert_equal(1, res, "貢獻度足夠時應該可以晉升");
    assert_equal("勇猛戰士", me->query_guild_rank(), "晉升後職位應變更");

    report_results();
    destruct(me);
}
