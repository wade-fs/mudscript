// std/object.c - 所有物件的基底類別
// 提供 id、名稱、描述、重量等最基本的屬性

string  short_name;    // 短描述（用於 look inventory 時顯示）
string  long_name;     // 長描述（用於 look <item> 時顯示）
mixed   id_list;       // 識別字串陣列，例如 ({"sword","long sword"})
string  item_type;     // 物品種類（weapon/armour/consumable/misc）
int     weight;        // 重量（克）
int     value;         // 金幣價值

void create() {
    short_name = "某個東西";
    long_name  = "這是一個沒有描述的東西。";
    id_list    = ({});
    item_type  = "misc";
    weight     = 0;
    value      = 0;
}

// ── 設定函式 ────────────────────────────────────────────
void set_short(string s)     { short_name = s; }
void set_long(string s)      { long_name  = s; }
void set_id(mixed ids)       { if (arrayp(ids)) id_list = ids; else id_list = ({ ids }); }
void set_item_type(string t) { item_type  = t; }
void set_weight(int w)       { weight     = w; }
void set_value(int v)        { value      = v; }

// ── 查詢函式 ────────────────────────────────────────────
string query_short()     { return short_name; }
string query_long()      { return long_name; }
mixed  query_id()        { return id_list; }
string query_item_type() { return item_type; }
int    query_weight()    { return weight; }
int    query_value()     { return value; }

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

// catch_tell(string msg) - 收到訊息（預設不處理）
void catch_tell(string msg) {}
