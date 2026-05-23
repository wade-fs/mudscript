// /tests/test_currency_chat.c
inherit "/std/test_case";

void run_tests() {
    start_test("貨幣系統與頻道收費驗證");

    object me = clone_object("/std/user.c");
    me->set_name("測試富豪");
    
    // 1. 測試貨幣兌換
    // 1 酷金幣 = 1,000,000 銅幣
    me->add_money(1000000); 
    string m_str = me->query_money_string();
    assert_true(strsrch(m_str, "酷金幣") != -1, "1,000,000 銅幣應顯示包含酷金幣");
    
    // 2. 測試頻道收費
    object channel_d = load_object("/secure/channel_d.c");
    
    // 測試公會頻道收費 (1 銀幣 = 100 銅幣)
    me->set_guild("adventurer");
    int old_money = me->query_money();
    channel_d->broadcast("guild", me, "測試訊息", "");
    assert_equal(old_money - 100, me->query_money(), "公會發言應扣除 1 銀幣 (100 銅幣)");

    // 測試全域頻道收費 (10,000 銀幣 = 1,000,000 銅幣 = 1 酷金幣)
    me->add_money(1000000); // 補足錢
    old_money = me->query_money();
    channel_d->broadcast("chat", me, "大家豪", "");
    assert_equal(old_money - 1000000, me->query_money(), "全域發言應扣除 10,000 銀幣 (1,000,000 銅幣)");

    // 3. 測試餘額不足
    me->add_money(-me->query_money()); // 清空
    me->add_money(50); // 只有 50 銅幣
    channel_d->broadcast("guild", me, "窮人說話", "");
    assert_equal(50, me->query_money(), "餘額不足時不應扣費且不應發言");

    // 4. 測試好友頻道
    int res = channel_d->join_friend_channel(me, "秘密基地");
    assert_equal(1, res, "應可成功加入自建頻道");

    report_results();
    destruct(me);
}
