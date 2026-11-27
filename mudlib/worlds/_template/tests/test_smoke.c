// tests/test_smoke.c - _template 世界 Phase 2 完整冒煙與整合測試
// 驗證：Overlay 讀取、compile_object() 零 .c stub、JSON 房間/NPC/道具具現、
//       clone_object 虛擬物件、NPC 狀態機、分支選擇任務後果、schema_d 力量體系/幣制、
//       ui_bridge_d DTO 打包、以及 save_object/restore_object 隔離寫入

inherit "/std/test_case.c";

void create() {
    ::create();
    set_test_name("_template Phase 2 MVVM 與 JSON 工廠整合測試");
}

int run_tests() {
    write("=== " + "test_smoke: _template Phase 2 整合測試" + " ===\n");

    // 1. Manifest 與 Schema 驗證
    string raw = read_file("/manifest.json");
    assert_true(raw && raw != "", "manifest.json 可讀");
    mixed mf = raw ? json_decode(raw) : 0;
    assert_true(mapp(mf), "manifest.json 解析為 mapping");
    assert_true(stringp(mf["world_id"]) && mf["world_id"] != "", "manifest.json 包含有效 world_id");

    object sd = load_object("/daemon/schema_d.c");
    assert_true(objectp(sd), "schema_d 可載入");
    if (sd) {
        assert_equal(sd->query_realm_for_level("", 1), "初境", "Lv.1 對應初境");
        assert_equal(sd->query_realm_for_level("", 12), "通脈", "Lv.12 對應通脈");
        assert_equal(sd->format_money(10205), "1 金幣 2 銀幣 5 銅錢", "多面額幣制格式化正確");
        mapping labels = sd->query_stat_labels("");
        assert_equal(labels["str"], "氣力", "力量體系自訂屬性標籤");
        assert_equal(sd->calc_stat("max_hp_bonus", ([ "con": 10 ])), 100, "stat_formula 公式計算正確");
    }

    // 2. compile_object() 零 .c stub 具現 JSON 房間
    object start_room = load_object("/rooms/start");
    assert_true(objectp(start_room), "load_object(/rooms/start) 透過 compile_object 具現成功");
    if (start_room) {
        assert_equal(to_string(start_room->query_short()), "新世界的起點", "JSON 房間標題正確");
        mapping exits = start_room->query_exits();
        assert_equal(exits["north"], "/rooms/courtyard", "JSON 房間出口正確");
    }

    object courtyard = load_object("/rooms/courtyard");
    assert_true(objectp(courtyard), "load_object(/rooms/courtyard) 透過 compile_object 具現成功");

    // 3. compile_object() 具現 JSON NPC + clone_object 保留資料 + 狀態機切換
    object guide = clone_object("/npcs/guide");
    assert_true(objectp(guide), "clone_object(/npcs/guide) 透過 compile_object 成功");
    if (guide) {
        assert_equal(to_string(guide->query_name()), "嚮導", "JSON NPC 名稱保留於 clone");
        assert_true(guide->id("guide"), "JSON NPC id('guide') 匹配");
        assert_true(guide->id("嚮導"), "JSON NPC id('嚮導') 匹配");
        assert_equal(guide->query_npc_state(), "waiting", "NPC 初始狀態機為 waiting");
    }

    // 4. compile_object() 具現 JSON 道具
    object badge = clone_object("/items/badge");
    assert_true(objectp(badge), "clone_object(/items/badge) 透過 compile_object 成功");
    if (badge) {
        assert_equal(to_string(badge->query_name()), "新手徽章", "JSON 道具名稱保留於 clone");
        assert_equal(badge->query_item_type(), "quest", "JSON 道具類型為 quest");
    }

    // 5. 模擬玩家移動、NPC 對話觸發任務 + 狀態切換 + 分支選擇後果
    object player = clone_object("/std/user.c");
    player->set_id("smoke_tester");
    player->set_name("冒煙測試員", ({ "smoke_tester" }));
    player->set_role("player");
    move_object(player, courtyard);
    if (guide) move_object(guide, courtyard);

    if (guide) {
        string reply = guide->talk_to(player, "quest");
        assert_true(strsrch(reply, "入門委託") != -1, "NPC 對話回傳正確");
        assert_equal(guide->query_npc_state(), "guiding", "NPC 對話觸發狀態機轉移至 guiding");
    }

    object qed = load_object("/daemon/quest_engine_d.c");
    assert_true(objectp(qed), "quest_engine_d 可載入");
    if (qed) {
        assert_true(qed->file_exists_any("/rooms/start"), "quest_engine_d 支援 .json 存在性檢查 (/rooms/start)");
        assert_true(qed->file_exists_any("/items/badge"), "quest_engine_d 支援 .json 存在性檢查 (/items/badge)");

        mixed pq = player->query_quest("intro");
        assert_true(mapp(pq) && pq["status"] == "active", "NPC 對話成功接取 intro 任務");

        // 推進 stage 0 -> stage 1
        int adv = qed->advance_stage(player, "intro", ([ "visited_courtyard": 1 ]));
        assert_equal(adv, 1, "任務推進至 stage 1");

        // 驗證 active 階段的 ui_bridge_d quest_list DTO 包含 stage_desc 與 choices
        object ui_pre = load_object("/daemon/ui_bridge_d.c");
        if (ui_pre) {
            mapping qv_active = ui_pre->build_quest_list(player);
            assert_true(arrayp(qv_active["quests"]) && sizeof(qv_active["quests"]) >= 1, "active 任務出現在 quest_list");
            mapping q0 = qv_active["quests"][0];
            assert_true(stringp(q0["stage_desc"]) && q0["stage_desc"] != "", "active 任務 DTO 包含 stage_desc");
            assert_true(arrayp(q0["choices"]) && sizeof(q0["choices"]) == 2, "active 任務 DTO 包含 2 個分支 choices");
        }

        // 選擇 explore 分支
        int chosen = qed->choose_branch(player, "intro", "explore");
        assert_equal(chosen, 1, "任務分支選擇 explore 成功");

        mixed pq_done = player->query_quest("intro");
        assert_equal(pq_done["status"], "completed", "選擇分支後任務正確結算為 completed");
        assert_equal(player->query_quest_flag("style_explorer"), 1, "分支選擇寫入玩家 quest_flag");
        assert_true(player->query_money() >= 100, "分支獎勵金幣入帳");

        object wsd = load_object("/daemon/world_state_d.c");
        assert_equal(wsd->query_var("exploration_index"), 1, "分支選擇連動 world_state_d 世界變數");

        // 確認獎勵物品 /items/badge 透過 .json 具現並放入玩家背包
        object got_badge = present("badge", player);
        assert_true(objectp(got_badge), "分支獎勵 JSON 道具成功發放至玩家背包");
    }

    // 5.5 感官互動、宣告式房間動作與基礎共用指令 (lang/help/alias/act)
    int prev_sp = player->query_sp();
    assert_true(courtyard->execute_action_rule(player, "wish", "well") == 1, "JSON 房間宣告式動作 wish well 執行成功");
    assert_equal(player->query_quest_flag("wished_at_well"), 1, "wish well 寫入玩家 quest_flag");
    assert_equal(player->query_sp(), prev_sp - 5, "wish well 正確消耗 5 點精力");

    object cmd_act = load_object("/cmds/cmd_act.c");
    assert_true(objectp(cmd_act), "cmd_act 可載入");
    if (cmd_act) {
        assert_equal(cmd_act->main(player, "touch", "well"), 1, "touch well 感官指令執行成功");
        assert_equal(cmd_act->main(player, "search", "tree"), 1, "search tree 感官指令執行成功");
    }
    object cmd_alias = load_object("/cmds/cmd_alias.c");
    if (cmd_alias) {
        cmd_alias->main(player, "alias", "ww wish well");
        assert_equal(player->expand_alias("ww"), "wish well", "alias 指令設定生效");
        cmd_alias->main(player, "unalias", "ww");
        assert_equal(player->expand_alias("ww"), "ww", "unalias 指令移除生效");
    }
    object cmd_lang = load_object("/cmds/cmd_lang.c");
    if (cmd_lang) {
        cmd_lang->main(player, "lang", "en");
        assert_equal(player->query_lang(), "en", "lang 指令切換語系為 en");
        cmd_lang->main(player, "lang", "zh-TW");
        assert_equal(player->query_lang(), "zh-TW", "lang 指令切換回 zh-TW");
    }

    // 6. UI Bridge DTO 驗證
    object ui = load_object("/daemon/ui_bridge_d.c");
    assert_true(objectp(ui), "ui_bridge_d 可載入");
    if (ui) {
        mapping rview = ui->build_room_view(courtyard, player);
        assert_equal(rview["type"], "room", "room_view DTO type 正確");
        assert_equal(rview["short"], "廣場庭院", "room_view DTO short 正確");
        assert_true(arrayp(rview["npcs"]) && sizeof(rview["npcs"]) >= 1, "room_view DTO 包含 NPC");
        assert_true(arrayp(rview["actions"]) && sizeof(rview["actions"]) >= 1, "room_view DTO 包含宣告式 actions");
        assert_true(arrayp(rview["inspectables"]) && sizeof(rview["inspectables"]) >= 1, "room_view DTO 包含可觀察項目");

        mapping cview = ui->build_char_view(player);
        assert_equal(cview["type"], "character", "char_view DTO type 正確");
        assert_equal(cview["realm"], "初境", "char_view DTO 包含 schema 境界");

        mapping qview = ui->build_quest_list(player);
        assert_equal(qview["type"], "quest_list", "quest_list DTO type 正確");
        assert_true(arrayp(qview["quests"]) && sizeof(qview["quests"]) >= 1, "quest_list DTO 包含已完成任務");
    }

    // 7. 寫入隔離存檔驗證（save_object -> /data/user/smoke_tester.o）
    player->do_save();
    assert_true(file_size("/data/user/smoke_tester.o") > 0, "玩家存檔寫入世界層 /data/user/");
    rm("/data/user/smoke_tester.o");

    if (guide) destruct(guide);
    if (badge) destruct(badge);
    destruct(player);

    write("=== 測試完成：通過 " + pass_count + "，失敗 " + fail_count + " ===\n");
    return fail_count;
}
