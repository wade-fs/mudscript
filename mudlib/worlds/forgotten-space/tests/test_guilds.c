// /tests/test_guilds.c
// 三元道途組織與晉升體系驗證
inherit "/std/test_case";

void run_tests(object me) {
    start_test("公會與勢力系統驗證");

    object tester = clone_object("/std/user.c");
    tester->set_id("tester");
    tester->set_lang("zh-TW");
    tester->set_name("測試志願者");
    tester->set_level(10);
    tester->set_stat("str", 25);
    tester->set_stat("int", 25);
    tester->set_stat("dex", 25);

    object guild_d = load_object("/secure/guild_d.c");

    // 1. 測試加入【力】道八方行省武館 (wu_initiate)
    int res = guild_d->join_guild(tester, "wu_initiate");
    assert_equal(1, res, "應該可以成功加入八方行省武館 (wu_initiate)");
    assert_equal("wu_initiate", tester->query_guild(), "公會屬性應正確設定為 wu_initiate");
    assert_equal("li", tester->query_path(), "加入 wu_initiate 後道途應自動對應為 li");
    string rank = tester->query_guild_rank();
    assert_true(rank == "外門武卒" || rank == "Outer Martial Recruit", "初始職位應正確: " + rank);

    // 2. 測試重複加入另一道途 (應該失敗)
    res = guild_d->join_guild(tester, "dao_initiate");
    assert_equal(0, res, "不應該能同時加入兩個道途公會");

    // 3. 測試職位晉升
    tester->add_guild_exp(1200);
    res = guild_d->promote_member(tester);
    assert_equal(1, res, "貢獻度足夠時應該可以晉升");
    rank = tester->query_guild_rank();
    assert_true(rank == "黑鐵銳士" || rank == "Iron-Belt Vanguard", "晉升後職位應變更: " + rank);

    report_results();
    destruct(tester);
}
