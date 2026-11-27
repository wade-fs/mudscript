// /tests/test_overlay_phase4.c
// Phase 4: mudlib/worlds/forgotten-space 與 mudlib/common Overlay 整合驗證

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/mvvm_protocol.h"

void run_tests(object me) {
    start_test("Phase 4: Overlay 共用核心 + Schema + UI Bridge + 章節正典對接");

    // 1. manifest.json 與 system_d 對接
    string raw_mf = read_file("/manifest.json");
    assert_true(stringp(raw_mf) && raw_mf != "", "manifest.json 應可讀取");
    mixed mf = raw_mf ? json_decode(raw_mf) : 0;
    assert_true(mapp(mf), "manifest.json 應解析為 mapping");
    assert_equal("forgotten-space", mf["world_id"], "manifest world_id 應為 forgotten-space");
    assert_equal("forgotten.space", mf["mudlib_id"], "manifest mudlib_id 應為 forgotten.space");

    object sysd = load_object(SYSTEM_D);
    assert_true(objectp(sysd), "共用 /secure/system_d.c 應成功載入");
    assert_equal("forgotten.space", sysd->query_mudlib_id(), "FS_MUDLIB_ID 應對齊 forgotten.space");

    // 2. 共用層檔案透過 Overlay 讀取
    assert_true(file_size("/master.c") > 0, "Overlay 應可讀取 common/master.c");
    assert_true(file_size("/include/mvvm_protocol.h") > 0, "Overlay 應可讀取 common/include/mvvm_protocol.h");
    assert_true(file_size("/chapters/01_volume1/ch0001.md") > 0, "chapters/ 第一章正典應存在");

    // 3. exclude_cmds 避免 common 指令衝突
    object cmdd = load_object(COMMAND_D);
    assert_true(objectp(cmdd), "共用 /secure/command_d.c 應成功載入");
    mapping cmap = cmdd->query_cmd_map();
    assert_equal("/cmds/cmd_info.c", cmap["score"], "score 應保留 forgotten-space 的 cmd_info.c");
    assert_equal("/cmds/cmd_ask.c", cmap["ask"], "ask 應保留 forgotten-space 的 cmd_ask.c");
    assert_equal("/cmds/cmd_inventory.c", cmap["get"], "get 應保留 forgotten-space 的 cmd_inventory.c");

    // 4. schema_d 載入三維道統、大荒通寶與屬性公式
    object sd = load_object(SCHEMA_D);
    assert_true(objectp(sd), "共用 /daemon/schema_d.c 應成功載入");
    if (sd) {
        assert_equal("凡胎", sd->query_realm_for_level("", 1), "Lv.1 應對應 凡胎");
        assert_equal("凝罡", sd->query_realm_for_level("", 20), "Lv.20 應對應 凝罡");
        assert_equal("1 金錠 2 銀兩 5 銅錢", sd->format_money(10205), "大荒通寶多面額格式化正確");
        mapping labels = sd->query_stat_labels("");
        assert_equal("臂力", labels["str"], "str 標籤應為 臂力");
        assert_equal("靈性", labels["spi"], "spi 標籤應為 靈性");
        assert_equal(150, sd->calc_stat("max_hp_bonus", ([ "con": 10 ])), "max_hp_bonus 公式計算正確");
    }

    // 5. world_init_d 已預熱本書專屬守護進程
    assert_true(objectp(find_object(CITY_D)), "world_init_d 應已載入 CITY_D");
    assert_true(objectp(find_object(REGION_D)), "world_init_d 應已載入 REGION_D");
    assert_true(objectp(find_object(ROUTE_D)), "world_init_d 應已載入 ROUTE_D");
    assert_true(objectp(find_object(TIER3_D)), "world_init_d 應已載入 TIER3_D");

    // 6. ui_bridge_d 對接 forgotten-space 角色與房間
    object uib = load_object(UI_BRIDGE_D);
    assert_true(objectp(uib), "共用 /daemon/ui_bridge_d.c 應成功載入");
    object p = clone_object("/std/user.c");
    object sq = load_object("/d/village/square.c");
    if (uib && p && sq) {
        p->set_id("phase4_viewer");
        p->set_name("黑石旅者", ({ "phase4_viewer" }));
        p->set_level(12);
        p->recalc_stats();
        mapping cv = uib->build_char_view(p);
        assert_equal("character", cv["type"], "char_view DTO type 正確");
        assert_equal("引氣", cv["realm"], "Lv.12 char_view realm 應對應 引氣");
        assert_true(intp(cv["str"]) && cv["str"] > 0, "char_view 應相容 query('str') 取得臂力");

        mapping rv = uib->build_room_view(sq, p);
        assert_equal("room", rv["type"], "room_view DTO type 正確");
        assert_equal("黑石鋪・青石街市", rv["short"], "room_view short 應對齊黑石鋪");
    }
    if (p) destruct(p);

    report_results();
}
