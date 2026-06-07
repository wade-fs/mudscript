// /secure/simul_efun.c
// 全域模擬內建函式 (SimulEfuns)

#include "/include/ansi.h"

// 讓物件名稱更漂亮
string get_name(object ob) {
    if (!ob) return "無名物";
    mixed name = ob->query_name();
    if (!name) name = ob->query("name");
    if (stringp(name)) return name;
    mixed ids = ob->query_id();
    if (stringp(ids)) return ids;
    if (arrayp(ids) && sizeof(ids) > 0) return ids[0];
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
        if (ob) lang = ob->query_lang();
        if (!lang || lang == "0") {
            object tp = this_player();
            if (tp) lang = tp->query_lang();
        }
    }
    if (!lang || lang == "0") lang = "en";
    if (data[lang]) return data[lang];
    if (data["en"]) return data["en"];
    if (sizeof(data) > 0) return values(data)[0];
    return "";
}

// 語系翻譯
string _t(string key) {
    object tp = this_player();
    string lang = tp ? tp->query_lang() : "en";
    return load_object("/secure/language_d.c")->translate(key, lang);
}

// 判斷玩家是否使用 Web 客戶端
int is_web_client(object ob) {
    if (!ob) ob = this_player();
    if (!ob) return 0;
    return efun::is_web_client(ob);
}

// 請求前端開啟 Web 編輯器
void request_web_edit(string path) {
    efun::request_web_edit(path);
}
