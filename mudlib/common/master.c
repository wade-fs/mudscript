// master.c
// 共用 Mudlib 核心總管物件 (World-Agnostic Master Object)

inherit "/secure/valid.c";

mapping world_manifest;

void load_world_manifest() {
    world_manifest = ([]);
    if (file_size("/manifest.json") > 0) {
        string raw = read_file("/manifest.json");
        if (raw && raw != "") {
            mixed parsed = json_decode(raw);
            if (mapp(parsed)) {
                world_manifest = parsed;
            }
        }
    }
}

mapping get_world_manifest() {
    if (!mapp(world_manifest)) load_world_manifest();
    return world_manifest;
}

void create() {
    ::create();
    load_world_manifest();

    string wname = world_manifest["name"] ? world_manifest["name"] : "MudScript World";
    write("=====================================================\n");
    write("  《" + wname + "》Master Object 啟動成功\n");
    write("=====================================================\n");

    // 載入共用核心守護進程
    load_object("/secure/system_d.c");
    load_object("/secure/language_d.c");
    load_object("/secure/social_d.c");
    load_object("/secure/command_d.c");
    load_object("/secure/nature_d.c");
    load_object("/secure/quest_d.c");
    load_object("/secure/channel_d.c");

    // Phase 2 MVVM daemon
    load_object("/daemon/schema_d.c");
    load_object("/daemon/world_state_d.c");
    load_object("/daemon/phase_d.c");
    load_object("/daemon/quest_engine_d.c");
    load_object("/daemon/room_factory_d.c");
    load_object("/daemon/npc_factory_d.c");
    load_object("/daemon/item_factory_d.c");
    load_object("/daemon/ui_bridge_d.c");

    // 若世界層提供專屬初始化守護進程，自動啟動
    if (file_size("/daemon/world_init_d.c") > 0) {
        load_object("/daemon/world_init_d.c");
    }

    if (getenv("MUD_TEST_MODE")) {
        call_out("run_test_mode", 1);
    }
}

void run_test_mode() {
    object test_cmd = load_object("/cmds/admin/cmd_tests.c");
    if (test_cmd) {
        object fake_me = clone_object("/std/user.c");
        fake_me->set_id("tester");
        fake_me->set_role("god");
        int failures = test_cmd->main(fake_me, "tests", "");
        destruct(fake_me);

        if (failures > 0) {
            shutdown(1);
        } else {
            shutdown(0);
        }
    } else {
        write("無法載入測試指令，測試失敗。\n");
        shutdown(1);
    }
}

// ==========================================
// 虛擬物件工廠掛勾 (Phase 2 compile_object)
// ==========================================
object compile_object(string path) {
    if (!path || path == "") return 0;

    if (file_size("/daemon/room_factory_d.c") > 0) {
        object rf = find_object("/daemon/room_factory_d.c");
        if (!rf) rf = load_object("/daemon/room_factory_d.c");
        if (rf) {
            object rob = rf->compile_virtual(path);
            if (rob) return rob;
        }
    }

    if (file_size("/daemon/npc_factory_d.c") > 0) {
        object nf = find_object("/daemon/npc_factory_d.c");
        if (!nf) nf = load_object("/daemon/npc_factory_d.c");
        if (nf) {
            object nob = nf->compile_virtual(path);
            if (nob) return nob;
        }
    }

    if (file_size("/daemon/item_factory_d.c") > 0) {
        object itf = find_object("/daemon/item_factory_d.c");
        if (!itf) itf = load_object("/daemon/item_factory_d.c");
        if (itf) {
            object iob = itf->compile_virtual(path);
            if (iob) return iob;
        }
    }

    return 0;
}

// ==========================================
// 玩家連線入口
// ==========================================
object connect(string lang) {
    object login_ob = clone_object("/std/login.c");
    if (login_ob) {
        login_ob->set_browser_lang(lang);
    } else {
        write_file("/log/runtime_error.log",
            sprintf("[%s] connect() 失敗：無法 clone /std/login.c\n", ctime(time())), 1);
    }
    return login_ob;
}

string get_root_uid() { return "Root"; }
string get_bb_uid()   { return "Backbone"; }
string get_simul_efun() { return "/secure/simul_efun.c"; }

int is_creator(string id) {
    if (file_size("/data/admin_set.o") > 0) {
        return 0;
    }
    mixed *files = get_dir("/data/user/*.o");
    if (sizeof(files) == 0) {
        write_file("/data/admin_set.o", id + "\n", 1);
        return 1;
    }
    return 0;
}

void runtime_error(string err_msg, string file) {
    string log_msg = sprintf("[%s] 檔案：%s\n訊息：%s\n---\n",
                             ctime(time()), file, err_msg);
    write_file("/log/runtime_error.log", log_msg, 1);
    write("【系統嚴重警告】執行期錯誤！\n" + log_msg);
}
