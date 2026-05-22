// /tests/test_crafting.c
inherit "/std/test_case";

void run_tests() {
    start_test("合成、鍛造與鑲嵌驗證");

    object me = clone_object("/std/user.c");
    me->set_name("測試工匠");

    object crafting_d = load_object("/secure/crafting_d.c");

    // 1. 測試煉金 (Alchemy)
    object m1 = clone_object("/item/material/slime_jelly.c");
    object m2 = clone_object("/item/material/slime_jelly.c");
    object m3 = clone_object("/item/material/wood.c"); // 故意放錯一個
    m1->set_name("史萊姆黏液");
    m2->set_name("史萊姆黏液");
    m3->set_name("雜草"); // 模擬雜草

    move_object(m1, me); move_object(m2, me); move_object(m3, me);
    
    // 預期成功合成初級恢復藥水
    int res = crafting_d->do_craft(me, "alchemy", ({ m1, m2, m3 }));
    assert_equal(1, res, "應該可以成功合成初級恢復藥水");
    
    object *inv = all_inventory(me);
    assert_true(sizeof(inv) > 0, "玩家身上應該有合成產物");
    assert_equal("初級恢復藥水", inv[0]->query_name(), "產物名稱正確");

    // 2. 測試鑲嵌 (Socketing)
    object sword = clone_object("/item/weapon/short_sword.c");
    object gem = clone_object("/item/gem/fire_shard.c");
    sword->set_name("短劍");
    gem->set_name("火焰碎石");
    move_object(sword, me); move_object(gem, me);

    res = crafting_d->do_craft(me, "socket", ({ sword, gem }));
    assert_equal(1, res, "應該可以成功鑲嵌火焰碎石");
    assert_equal("火焰之短劍", sword->query_name(), "鑲嵌後名稱變更正確");
    assert_equal("fire", sword->query_element(), "鑲嵌後屬性正確");

    report_results();
    destruct(me);
}
