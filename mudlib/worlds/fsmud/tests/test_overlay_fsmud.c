// /tests/test_overlay_fsmud.c
// Phase 5A: mudlib/worlds/fsmud 與 mudlib/common Overlay 整合驗證

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/mvvm_protocol.h"

void run_tests(object me) {
    start_test("Overlay: Fantasy Space 共用核心 + Schema + UI Bridge 對接");

    // 1. manifest.json 與共用 system_d 對接
    string raw_mf = read_file("/manifest.json");
    assert_true(stringp(raw_mf) && raw_mf != "", "manifest.json 應可讀取");
    mixed mf = raw_mf ? json_decode(raw_mf) : 0;
    assert_true(mapp(mf), "manifest.json 應解析為 mapping");
    assert_equal("fsmud", mf["world_id"], "manifest world_id 應為 fsmud");
    assert_equal("fantasy.space", mf["mudlib_id"], "manifest mudlib_id 應為 fantasy.space");

    object sysd = load_object(SYSTEM_D);
    assert_true(objectp(sysd), "共用 /secure/system_d.c 應成功載入");
    assert_equal("fantasy.space", sysd->query_mudlib_id(), "FS_MUDLIB_ID 應對齊 fantasy.space");

    // 2. 共用層檔案透過 Overlay 讀取（master.c、command_d、simul_efun、mvvm_protocol.h）
    assert_true(file_size("/master.c") > 0, "Overlay 應可讀取 common/master.c");
    assert_true(file_size("/include/mvvm_protocol.h") > 0, "Overlay 應可讀取 common/include/mvvm_protocol.h");
    assert_true(mapp(query_world_manifest()), "common/secure/simul_efun.c 的 query_world_manifest() 應可用");

    // 3. exclude_cmds 避免與 common 指令衝突
    object cmdd = load_object(COMMAND_D);
    assert_true(objectp(cmdd), "共用 /secure/command_d.c 應成功載入");
    mapping cmap = cmdd->query_cmd_map();
    assert_equal("/cmds/cmd_info.c", cmap["score"], "score 應保留 fsmud 的 cmd_info.c");
    assert_equal("/cmds/cmd_ask.c", cmap["ask"], "ask 應保留 fsmud 的 cmd_ask.c");
    assert_equal("/cmds/cmd_inventory.c", cmap["get"], "get 應保留 fsmud 的 cmd_inventory.c");
    assert_equal("/cmds/cmd_inventory.c", cmap["drop"], "drop 應保留 fsmud 的 cmd_inventory.c");

    // 4. schema_d 載入 Fantasy Space 幣制、等級與屬性公式
    object sd = load_object(SCHEMA_D);
    assert_true(objectp(sd), "共用 /daemon/schema_d.c 應成功載入");
    if (sd) {
        assert_equal("見習冒險者", sd->query_realm_for_level("", 1), "Lv.1 應對應 見習冒險者");
        assert_equal("英勇戰士", sd->query_realm_for_level("", 12), "Lv.12 應對應 英勇戰士");
        assert_equal("1 金幣 2 銀幣 5 銅幣", sd->format_money(10205), "多面額幣制格式化正確");
        mapping labels = sd->query_stat_labels("");
        assert_equal("力量", labels["str"], "str 標籤應為 力量");
        assert_equal("智慧", labels["wis"], "wis 標籤應為 智慧");
        assert_equal(100, sd->calc_stat("max_hp_bonus", ([ "con": 10 ])), "max_hp_bonus 公式計算正確");
    }

    // 5. world_init_d 已預熱 fsmud 專屬守護進程
    assert_true(objectp(find_object("/secure/event_d.c")), "world_init_d 應已載入 event_d");
    assert_true(objectp(find_object("/daemon/settlement_d.c")), "world_init_d 應已載入 settlement_d");
    assert_true(objectp(find_object("/daemon/timeline_d.c")), "world_init_d 應已載入 timeline_d");
    assert_true(objectp(find_object("/secure/guild_d.c")), "world_init_d 應已載入 guild_d");
    assert_true(objectp(find_object("/secure/crafting_d.c")), "world_init_d 應已載入 crafting_d");

    // 6. ui_bridge_d 對接 fsmud 角色與新手村房間
    object uib = load_object(UI_BRIDGE_D);
    assert_true(objectp(uib), "共用 /daemon/ui_bridge_d.c 應成功載入");
    object p = clone_object("/std/user.c");
    object start_rm = load_object("/area/newbie/room_0_0.c");
    if (uib && p && start_rm) {
        p->set_id("fsmud_viewer");
        p->set_name("星際旅者");
        p->set_lang("zh-TW");
        p->set_level(12);
        p->recalc_stats();
        mapping cv = uib->build_char_view(p);
        assert_equal("character", cv["type"], "char_view DTO type 正確");
        assert_equal("英勇戰士", cv["realm"], "Lv.12 char_view realm 應對應 英勇戰士");
        assert_true(intp(cv["str"]) && cv["str"] > 0, "char_view 應相容 query_stat('str') 取得力量");
        assert_true(intp(cv["wis"]) && cv["wis"] > 0, "char_view 應相容 query_stat('wis') 取得智慧");

        mapping rv = uib->build_room_view(start_rm, p);
        assert_equal("room", rv["type"], "room_view DTO type 正確");
        assert_equal("/area/newbie/room_0_0.c", rv["path"], "room_view path 應對齊新手村大門");
        assert_true(rv["short"] == "新手村大門" || rv["short"] == "Newbie Village Gate", "room_view short 應對齊新手村大門");
    }
    if (p) destruct(p);

    report_results();
}
