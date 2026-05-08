int valid_read(string path, object user, string func) { return 1; }

// 將回傳型別改為 mixed，支援回傳錯誤字串
mixed valid_write(string path, object user, string func)
{
    string role;
    string *paths;

    if (!user) { return "拒絕：找不到使用者物件，無法驗證身分。"; }

    role = user->query_role();

    // 天神擁有絕對權限
    if (role == "god") { return 1; }

    paths = user->query_write_paths();

    if (!paths || sizeof(paths) == 0) {
        return "拒絕：你沒有任何目錄的寫入授權。";
    }

    foreach (p in paths) {
        // 確認目標路徑是否以授權的目錄開頭
        if (strsrch(path, p) == 0) { return 1; }
    }

    // 若全數不匹配，回傳精確的拒絕原因
    return "拒絕：目標路徑 (" + path + ") 不在你的管轄範圍內。";
}
