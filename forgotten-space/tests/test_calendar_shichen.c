// /tests/test_calendar_shichen.c
inherit "/std/test_case";

void run_tests(object me) {
    start_test("遺忘曆法與元亨利貞周天四序驗證");

    object nd = load_object("/secure/nature_d.c");
    assert_true(nd != 0, "nature_d 守護進程應成功載入");

    int year = nd->query_calendar_year();
    int month = nd->query_calendar_month();
    int day = nd->query_calendar_day();
    string date_str = nd->query_calendar_date_string();
    string title = nd->query_year_season_title();
    string cycle = nd->query_cycle_name();
    string shichen = nd->query_shichen_name();
    string shichen_full = nd->query_shichen_full();
    string weather_str = nd->query_weather_string();

    write("  [資訊] 遺忘曆年份: " + year + "\n");
    write("  [資訊] 當前月份: " + month + "，日期: " + day + "\n");
    write("  [資訊] 歲象稱謂: " + title + "\n");
    write("  [資訊] 當前輪元: " + cycle + " (" + nd->query_cycle_desc() + ")\n");
    write("  [資訊] 當前時辰: " + shichen_full + "\n");
    write("  [資訊] 完整氣象字串: " + weather_str + "\n");

    // 驗證 2026 年 10 月對應 8104 年
    assert_true(year == 8104, "2026年10月之遺忘曆年份應為 8104 年");
    assert_true(month == 10, "當前月份應為 10 月");
    assert_true(title == "玄冥冬歲", "10月歲象稱謂應為 玄冥冬歲");
    assert_true(cycle == "元" || cycle == "亨" || cycle == "利" || cycle == "貞", "輪元應為 元亨利貞 之一");

    report_results();
}
