// master.c
// 這是 MUD 引擎啟動後第一個載入的總管物件

inherit "/secure/valid.c";

void create() {
    ::create();
    // 伺服器啟動時，可以在這裡做一些全域的初始化
    write("=====================================================\n");
    write("  《遺忘的世界》(THE FORGOTTEN SPACE) Master Object 啟動成功 \n");
    write("=====================================================\n");

    // 啟動全域守護進程
    load_object("/secure/nature_d.c");
    load_object("/secure/quest_d.c");
    load_object("/secure/guild_d.c");
    load_object("/secure/channel_d.c");
    load_object("/daemon/world_state_d.c");
    load_object("/daemon/event_manager.c");
    load_object("/daemon/career_d.c");
    load_object("/daemon/mysteryd.c");
    load_object("/daemon/questd.c");
    load_object("/daemon/city_d.c");
    load_object("/daemon/tier3_d.c");

    // [FIX P1] 預熱任務引擎，避免首位玩家承受 117 份 JSON 掃描延遲
    // quest_engine_d 負責掃描 /quests/ 目錄下所有任務 JSON，原本採 lazy load；
    // 在啟動序列中主動載入，確保玩家觸發任務時已完成索引建立。
    load_object("/daemon/quest_engine_d.c");

    // [FIX P3] 預熱 NPC 作息與市井情報系統，避免首個心跳週期前的初始化空窗
    // phase_d 與 rumor_d 原本由 nature_d 在心跳中 lazy load，
    // 導致冷啟動後第一個心跳週期前 NPC 作息與流言系統未初始化。
    load_object("/daemon/phase_d.c");
    load_object("/daemon/rumor_d.c");

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

        // 如果失敗次數 > 0，則以結束代碼 1 關閉
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
// 1. 玩家連線入口 (非常重要)
// ==========================================
// 當玩家透過 TCP 連線時，Driver 的 AcceptConnection 會呼叫此函式
// [FIX P6] clone 失敗時記錄日誌，避免靜默失敗造成連線無聲無息中斷
object connect(string lang) {
    object login_ob;

    // 複製一個 login 物件來處理後續的登入流程
    login_ob = clone_object("/std/login.c");

    if (login_ob) {
        login_ob->set_browser_lang(lang);
    } else {
        // [FIX P6] clone 失敗時寫入錯誤日誌，方便排查 /std/login.c 編譯或載入問題
        write_file("/log/runtime_error.log",
            sprintf("[%s] connect() 失敗：無法 clone /std/login.c\n", ctime(time())), 1);
    }

    // 將這個 login 物件回傳給 Driver
    return login_ob;
}

// ==========================================
// 2. 系統權限標籤 (UIDs)
// ==========================================
// Driver 啟動時會呼叫這兩個函式來確立系統最高權限的 UID
// 傳統 MUD 依賴這兩個字串來判斷某個物件是否具有讀寫核心檔案的權限

string get_root_uid() {
    return "Root";
}

string get_bb_uid() {
    return "Backbone";
}

// 🚀 新增：告知 Driver SimulEfun 的存放路徑
string get_simul_efun() {
    return "/secure/simul_efun.c";
}

// [FIX P5] 防止競態條件：以旗標檔 /data/admin_set.o 確保首位 God 只被授權一次
// 原實作僅用 get_dir 掃描 user 存檔，多玩家同時連線時可能造成重複授權；
// 現改為先檢查旗標檔是否已寫入，確保首位登入者獲得 God 後即鎖定。
int is_creator(string id) {
    // 旗標檔已存在，表示 God 已授權完畢
    if (file_size("/data/admin_set.o") > 0) {
        return 0;
    }
    mixed *files = get_dir("/data/user/*.o");
    if (sizeof(files) == 0) {
        // 首位登入者自動成為管理員，寫入旗標防止重複授權
        write_file("/data/admin_set.o", id + "\n", 1);
        return 1;
    }
    return 0;
}

// ==========================================
// 3. 錯誤處理攔截 (Error Handling)
// ==========================================
// 當 Evaluator 執行期間發生崩潰 (Runtime Error) 時，Driver 會呼叫此函式
// 傳入的參數是錯誤訊息字串與發生錯誤的檔案名稱
// [FIX P4] 同時寫入 /log/runtime_error.log，確保背景執行的錯誤可追蹤，
//           而非僅靠 write() 輸出給當前玩家（玩家不在線時訊息即消失）
void runtime_error(string err_msg, string file) {
    string log_msg = sprintf("[%s] 檔案：%s\n訊息：%s\n---\n",
                             ctime(time()), file, err_msg);
    write_file("/log/runtime_error.log", log_msg, 1);
    write("【系統嚴重警告】執行期錯誤！\n" + log_msg);
}
