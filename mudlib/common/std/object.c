// std/object.c - 所有物件的共用基底類別 (World-Agnostic)
// 提供 id、名稱、描述、重量、通用 dbase/temp/responses 與垃圾回收

#include "/include/config.h"

string  name;          // 內部名稱
string  short_name;    // 短描述
string  long_name;     // 長描述
mixed   id_list;       // 識別字串陣列
int     weight;        // 重量（克）
int     no_get;        // 不可拿取
int     no_drop;       // 不可掉落
int     money_value;   // 錢袋金額

mapping dbase;            // 持久化動態屬性表
nosave mapping temp_vars; // 暫存屬性表（不存檔）
mapping responses;        // 關鍵字互動回應表

void create() {
    name        = "某個東西";
    short_name  = "某個東西";
    long_name   = "這是一個沒有描述的東西。";
    id_list     = ({});
    weight      = 0;
    no_get      = 0;
    no_drop     = 0;
    money_value = 0;
    dbase       = ([]);
    temp_vars   = ([]);
}

// ── 基本 hooks ──────────────────────────────────────────
int is_living() { return 0; }
void init() {}
void catch_tell(string msg) {}

// ── 設定函式 ────────────────────────────────────────────
varargs void set_name(mixed n, mixed ids) {
    name = n;
    if (ids) {
        if (arrayp(ids)) id_list = ids;
        else id_list = ({ ids });
    }
    if (is_living()) {
        set_living_name(to_string(select_lang(n)));
    }
}
void set_short(mixed s)      { short_name = s; }
void set_long(mixed s)       { long_name  = s; }
void set_id(mixed ids)       { if (arrayp(ids)) id_list = ids; else id_list = ({ ids }); }
void set_weight(int w)       { weight = w; }
void set_no_get(int v)       { no_get = v; }
void set_no_drop(int v)      { no_drop = v; }
void set_money_value(int v)  { money_value = v; }

// ── 方向輔助 ────────────────────────────────────────────
string query_reverse_dir(string dir) {
    switch (dir) {
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
string query_name()                      { return select_lang(name); }
string query_localized_name(string lang) { return select_lang(name, lang); }
string query_short()                     { return select_lang(short_name); }
string query_long()                      { return select_lang(long_name); }
mixed  query_id()                        { return id_list; }
int    query_weight()                    { return weight; }
int    query_no_get()                    { return no_get; }
int    query_no_drop()                   { return no_drop; }
int    query_money_value()               { return money_value; }

mixed query_coordinate() {
    object env = environment(this_object());
    if (env) return env->query_coordinate();
    return 0;
}

string query_key_id() {
    if (arrayp(id_list) && sizeof(id_list) > 0) {
        return id_list[0];
    }
    if (stringp(id_list) && id_list != "") {
        return id_list;
    }
    return get_name(this_object());
}

int id(string str) {
    if (!str || str == "") return 0;
    string lstr = lower_case(str);
    if (arrayp(id_list)) {
        for (int i = 0; i < sizeof(id_list); i++) {
            if (id_list[i] == str || lower_case(to_string(id_list[i])) == lstr) return 1;
        }
    } else if (stringp(id_list)) {
        if (id_list == str || lower_case(id_list) == lstr) return 1;
    }
    if (to_string(select_lang(name)) == str) return 1;
    return 0;
}

int move(mixed dest) {
    if (!dest) return 0;
    return move_object(this_object(), dest);
}

// ── 通用 dbase / temp 屬性容器 ──────────────────────────
void set(string prop, mixed val) {
    if (!mapp(dbase)) dbase = ([]);
    dbase[prop] = val;
}

mixed query(string prop) {
    if (!mapp(dbase)) return 0;
    return dbase[prop];
}

void add(string prop, mixed val) {
    if (!mapp(dbase)) dbase = ([]);
    if (!dbase[prop]) dbase[prop] = 0;
    dbase[prop] += val;
}

void delete(string prop) {
    if (mapp(dbase)) m_delete(dbase, prop);
}

mapping query_entire_dbase() {
    if (!mapp(dbase)) dbase = ([]);
    return dbase;
}

void set_temp(string key, mixed val) {
    if (!mapp(temp_vars)) temp_vars = ([]);
    temp_vars[key] = val;
}

mixed query_temp(string key) {
    if (!mapp(temp_vars)) return 0;
    return temp_vars[key];
}

void delete_temp(string key) {
    if (mapp(temp_vars)) m_delete(temp_vars, key);
}

// ── 關鍵字互動回應系統 ──────────────────────────────────
void add_response(mixed keyword, mixed response) {
    if (!responses) responses = ([]);

    if (arrayp(keyword)) {
        for (int i = 0; i < sizeof(keyword); i++) {
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

mixed query_response(string keyword) {
    if (!responses || !responses[keyword]) return 0;
    mixed res = responses[keyword];
    if (arrayp(res) && sizeof(res) > 0) return res[0];
    return res;
}

// ── 生命週期管理：垃圾回收 ─────────────────────────────
int clean_up(int inherited_count) {
    if (inherited_count > 0) return 1;

    string oname = object_name(this_object());
    if (strsrch(oname, "#") == -1 && strsrch(oname, FS_CACHE_DIR) != 0) return 1;

    object env = environment(this_object());
    if (env && living(env)) return 1;

    if (sizeof(all_inventory(this_object())) > 0) return 1;

    if (query_idle(this_object()) > 900) {
        destruct(this_object());
        return 0;
    }

    return 1;
}

int is_destructed() {
    return 0;
}
