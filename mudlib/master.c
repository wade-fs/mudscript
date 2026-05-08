// master.c
// 這是 MUD 引擎啟動後第一個載入的總管物件

void create() {
    // 伺服器啟動時，可以在這裡做一些全域的初始化
    write("===================================\n");
    write("  MudScript Master Object 啟動成功 \n");
    write("===================================\n");
}

// ==========================================
// 1. 玩家連線入口 (非常重要)
// ==========================================
// 當玩家透過 TCP 連線時，Driver 的 AcceptConnection 會呼叫此函式
object connect() {
    object login_ob;
    
    // 這裡印出的訊息，因為在 driver.go 裡有綁定上下文，會直接送到玩家的終端機
    write("\n連線成功！歡迎來到 MudScript 測試伺服器！\n");
    
    // 複製一個 login 物件來處理後續的登入流程
    // (對應我們剛剛寫的 /cmds/login.c)
    login_ob = clone_object("/cmds/login.c");
    
    // 將這個 login 物件回傳給 Driver
    // Driver 收到後，會正式把玩家的網路連線掛載到這個 login_ob 身上
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

// ==========================================
// 3. 錯誤處理攔截 (Error Handling)
// ==========================================
// 當 Evaluator 執行期間發生崩潰 (Runtime Error) 時，Driver 會呼叫此函式
// 傳入的參數是錯誤訊息字串與發生錯誤的檔案名稱
void runtime_error(string err_msg, string file) {
    write("【系統嚴重警告】執行期錯誤！\n");
    write("檔案：" + file + "\n");
    write("訊息：" + err_msg + "\n");
}
