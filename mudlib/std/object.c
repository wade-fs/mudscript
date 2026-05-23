// std/object.c - 所有物件的基底類別
// 提供 id、名稱、描述等最基本的屬性

string  name;          // 內部名稱/名稱
string  short_name;    // 短描述
string  long_name;     // 長描述
mixed   id_list;       // 識別字串陣列

// 🚀 新增：基本旗標
int     no_get;        // 不可拿取 (例如: 巨大的石頭)
int     no_drop;       // 不可掉落 (例如: 詛咒物品、重要任務道具)
int     money_value;   // 🚀 新增：如果是錢袋，紀錄金額

void create() {
    name       = "某個東西";
    short_name = "某個東西";
    long_name  = "這是一個沒有描述的東西。";
    id_list    = ({});
    no_get     = 0;
    no_drop    = 0;
}

// ── 設定函式 ────────────────────────────────────────────
void set_name(mixed n)       { name = n; }
void set_short(mixed s)      { short_name = s; }
void set_long(mixed s)       { long_name  = s; }
void set_id(mixed ids)       { if (arrayp(ids)) id_list = ids; else id_list = ({ ids }); }
void set_no_get(int v)       { no_get = v; }
void set_no_drop(int v)      { no_drop = v; }
void set_money_value(int v)  { money_value = v; }

// ── 輔助函式：根據玩家語系選擇字串 ─────────────────────
string select_lang(mixed data) {
    if (stringp(data)) return data;
    if (!mapp(data)) return to_string(data);

    string lang = "en";
    object tp = this_player();
    
    // 優先順序：1. 目前執行此函式的物件如果是玩家 2. this_player() 3. 預設 en
    if (userp(this_object())) {
        lang = this_object()->query_lang();
    } else if (tp && userp(tp)) {
        lang = tp->query_lang();
    }
    
    // write("DEBUG: select_lang for " + object_name(this_object()) + " lang=" + lang + "\n");
    
    if (!lang || lang == "0") lang = "en";
    
    if (data[lang]) return data[lang];
    if (data["en"]) return data["en"];
    
    // 沒找到則回傳第一項
    mixed ks = keys(data);
    if (sizeof(ks) > 0) return data[ks[0]];
    return "None";
}

// ── 方向輔助 ────────────────────────────────────────────
string query_reverse_dir(string dir) {
    switch(dir) {
        case "north": return "south";
        case "south": return "north";
        case "east":  return "west";
        case "west":  return "east";
        case "up":    return "down";
        case "down":  return "up";
    }
    return "here";
}

// ── 查詢函式 ────────────────────────────────────────────
string query_name()      { return select_lang(name); }
string query_short()     { return select_lang(short_name); }
string query_long()      { return select_lang(long_name); }
mixed  query_id()        { return id_list; }
int    query_no_get()    { return no_get; }
int    query_no_drop()   { return no_drop; }
int    query_money_value(){ return money_value; }

// 🚀 新增：取得坐標 (若自身無坐標則向環境查詢)
mixed query_coordinate() {
    object env = environment(this_object());
    if (env) return env->query_coordinate();
    return 0;
}

// 🚀 新增：翻譯輔助函式
string _t(string key) {
    object tp = this_player();
    string lang = "en";
    
    if (tp && userp(tp)) {
        lang = tp->query_lang();
    } else if (userp(this_object())) {
        lang = this_object()->query_lang();
    }
    
    return load_object("/secure/language_d.c")->translate(key, lang);
}

// ── 取得用於指令互動的主要識別字 ─────────────────────
string query_key_id() {
	if (arrayp(id_list) && sizeof(id_list) > 0) {
        return id_list[0];
    }
    if (stringp(id_list) && id_list != "") {
        return id_list;
    }

    // 最後防線：只取檔名，不帶路徑和 .c
    string fname = object_name(this_object());
    int pos = strsrch(fname, "#");
    if (pos != -1) {
        fname = substr(fname, 0, pos);
    }
    
    // 如果結尾是 .c，去掉它
    if (strlen(fname) > 2) {
        string tail = substr(fname, strlen(fname)-2, 2);
        if (tail == ".c") {
            fname = substr(fname, 0, strlen(fname)-2);
        }
    }

    // 取得最後一個 / 之後的內容 (模仿 basename)
    // 由於沒有 strrchr，我們用簡單的方式處理
    string *parts = explode(fname, "/");
    if (sizeof(parts) > 0) {
        return parts[sizeof(parts)-1];
    }

    return fname;
}

// id(string str) - 判斷這個物件是否符合指定識別詞
int id(string str) {
    if (!str) { return 0; }
    int i;
    for (i = 0; i < sizeof(id_list); i++) {
        if (id_list[i] == str) { return 1; }
    }
    return 0;
}

// 判斷是否為生物
int is_living() { return 0; }

// catch_tell(string msg) - 收到訊息（預設不處理）
void catch_tell(string msg) {}

// ── 關鍵字互動系統 ──────────────────────────────────────
mapping responses;

void add_response(mixed keyword, mixed response) {
    if (!responses) responses = ([]);
    
    if (arrayp(keyword)) {
        int i;
        for (i = 0; i < sizeof(keyword); i++) {
            add_response(keyword[i], response);
        }
        return;
    }

    if (!responses[keyword]) responses[keyword] = ({});
    if (stringp(response) || mapp(response)) {
        responses[keyword] += ({ response });
    } else if (arrayp(response)) {
        responses[keyword] += response;
    }
}

mapping query_responses() {
    if (!responses) return ([]);
    return responses;
}
