// /secure/simul_efun.c

// 讓物件名稱更漂亮
string get_name(object ob) {
    if (!ob) return "無名物";
    // 嘗試呼叫物件的 query("name")
    mixed name = ob->query("name");
    if (stringp(name)) return name;
    
    // 或是 query_id()
    mixed ids = ob->query_id();
    if (stringp(ids)) return ids;
    if (arrayp(ids) && sizeof(ids) > 0) return ids[0];
    
    return object_name(ob);
}

// 取得中文化的時間
string chinese_time() {
    // 這裡只是簡單範例，實務上可根據 ctime 解析
    return ctime(time());
}

// 簡單的訊息包裝
void message(string category, string msg, mixed target) {
    if (objectp(target)) {
        tell_object(target, msg);
    } else if (arrayp(target)) {
        foreach (object ob in target) {
            if (objectp(ob)) tell_object(ob, msg);
        }
    }
}
