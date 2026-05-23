// /tests/test_i18n.c
inherit "/std/test_case";

void run_tests(object me) {
    start_test("多語系系統驗證");

    object me = clone_object("/std/user.c");
    me->set_name("多語系測試員");
    
    // 1. 測試預設語系 (en)
    me->set_lang("en");
    assert_equal("What?", me->_t("what"), "英文模式下的 'what' 翻譯應正確");

    // 2. 測試繁體中文
    me->set_lang("zh-TW");
    assert_equal("什麼？", me->_t("what"), "繁體中文模式下的 'what' 翻譯應正確");

    // 3. 測試簡體中文
    me->set_lang("zh-CN");
    assert_equal("什么？", me->_t("what"), "简体中文模式下的 'what' 翻譯應正確");

    // 4. 測試語言切換指令
    object cmd_lang = load_object("/cmds/cmd_lang.c");
    cmd_lang->main(me, "lang", "en");
    assert_equal("en", me->query_lang(), "執行 lang en 指令後語系應變更");

    report_results();
    destruct(me);
}
