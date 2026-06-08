// /tests/test_i18n.c
inherit "/std/test_case";

void run_tests(object me) {
    start_test("多語系系統驗證");

    object test_user = clone_object("/std/user.c");
    test_user->set_id("tester");
    test_user->set_name("多語系測試員");
    
    // 1. 測試預設語系 (en)
    test_user->set_lang("en");
    set_this_player(test_user);
    assert_equal("What?", _t("what"), "英文模式下的 'what' 翻譯應正確");

    // 2. 測試繁體中文
    test_user->set_lang("zh-TW");
    set_this_player(test_user);
    assert_equal("什麼？", _t("what"), "繁體中文模式下的 'what' 翻譯應正確");

    // 3. 測試簡體中文
    test_user->set_lang("zh-CN");
    set_this_player(test_user);
    assert_equal("什么？", _t("what"), "简体中文模式下的 'what' 翻譯應正確");

    // 恢復 context
    set_this_player(me);

    // 4. 測試語言切換指令
    object cmd_lang = load_object("/cmds/cmd_lang.c");
    cmd_lang->main(test_user, "lang", "en");
    assert_equal("en", test_user->query_lang(), "執行 lang en 指令後語系應變更");

    // 5. 測試帶有佔位符的翻譯
    object lang_d = load_object("/secure/language_d.c");
    string res = lang_d->translate("login_success", "en");
    res = replace_string(res, "$name", "Wade");
    assert_equal("Login successful! Welcome, Wade.", res, "英文登入訊息佔位符替換");

    res = lang_d->translate("login_success", "zh-TW");
    res = replace_string(res, "$name", "小明");
    assert_equal("登入成功！歡迎來到這個世界，小明。", res, "繁中登入訊息佔位符替換");

    report_results();
    destruct(test_user);
}
