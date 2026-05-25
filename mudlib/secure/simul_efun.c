// /secure/simul_efun.c
// 全域模擬內建函式 (SimulEfuns)

#include "/include/ansi.h"

// 讓物件名稱更漂亮
string get_name(object ob) {
    if (!ob) return "無名物";
    
    // 嘗試呼叫物件的 query_name() 或 query("name")
    mixed name = ob->query_name();
    if (!name) name = ob->query("name");
    
    if (stringp(name)) return name;
    
    // 或是 query_id()
    mixed ids = ob->query_id();
    if (stringp(ids)) return ids;
    if (arrayp(ids) && sizeof(ids) > 0) return ids[0];
    
    // 最後手段：使用檔名
    string fname = object_name(ob);
    int pos = strsrch(fname, "#");
    if (pos != -1) fname = substr(fname, 0, pos);
    string *parts = explode(fname, "/");
    return sizeof(parts) > 0 ? parts[sizeof(parts)-1] : fname;
}

// 根據指定語系選擇字串
varargs string select_lang(mixed data, string lang) {
    if (stringp(data)) return data;
    if (!mapp(data)) return to_string(data);

    if (!lang || lang == "0") {
        object ob = previous_object();
        // 優先從呼叫者取得語系 (適用於 ob->query_name() 這種呼叫)
        if (ob) lang = ob->query_lang();
        
        // 如果呼叫者沒語系，試試 this_player()
        if (!lang || lang == "0") {
            object tp = this_player();
            if (tp) lang = tp->query_lang();
        }
    }

    if (!lang || lang == "0") lang = "en";

    if (data[lang]) return data[lang];
    if (data["en"]) return data["en"];

    mixed ks = keys(data);
    if (sizeof(ks) > 0) return data[ks[0]];
    return "None";
}

// 翻譯輔助函式
string _t(string key) {
    string lang = "en";
    object ob = previous_object();

    if (ob) lang = ob->query_lang();
    
    if (!lang || lang == "0") {
        object tp = this_player();
        if (tp) lang = tp->query_lang();
    }
    
    if (!lang || lang == "0") lang = "en";

    return load_object("/secure/language_d.c")->translate(key, lang);
}

// 取得中文化的時間 (範例)
string chinese_time() {
    return ctime(time());
}

// 訊息發送封裝
varargs void message(string category, string msg, mixed target, mixed exclude) {
    if (objectp(target)) {
        tell_object(target, msg);
    } else if (arrayp(target)) {
        foreach (object ob in target) {
            if (objectp(ob)) tell_object(ob, msg);
        }
    } else if (!target) {
        // 預設發送給目前房間
        object env = environment(this_player());
        if (env) tell_room(env, msg, exclude);
    }
}
