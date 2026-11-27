// std/object.c - 所有物件的共用基底類別 (World-Agnostic)
// 提供 id、名稱、描述、重量與通用 dbase 屬性容器

#include "/include/config.h"

string  name;          // 內部名稱
string  short_name;    // 短描述
string  long_name;     // 長描述
mixed   id_list;       // 識別字串陣列
int     weight;        // 重量（克）
int     no_get;        // 不可拿取
int     no_drop;       // 不可掉落
int     money_value;   // 金幣面額（如果是貨幣物件）
mapping dbase;         // 動態持久化屬性表
nosave mapping temp_vars; // 暫存屬性表（不存檔）

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
        if (arrayp(ids)) id_list = ids; else id_list = ({ ids });
    }
    if (is_living()) set_living_name(to_string(select_lang(n)));
}
void set_short(mixed s)      { short_name = s; }
void set_long(mixed s)       { long_name  = s; }
void set_id(mixed ids)       { if (arrayp(ids)) id_list = ids; else id_list = ({ ids }); }
void set_weight(int w)       { weight = w; }
void set_no_get(int v)       { no_get = v; }
void set_no_drop(int v)      { no_drop = v; }
void set_money_value(int v)  { money_value = v; }

// ── 查詢函式 ────────────────────────────────────────────
mixed query_name()         { return select_lang(name); }
mixed query_short()        { return select_lang(short_name); }
mixed query_long()         { return select_lang(long_name); }
mixed query_id()           { return id_list; }
int   query_weight()       { return weight; }
int   query_no_get()       { return no_get; }
int   query_no_drop()      { return no_drop; }
int   query_money_value()  { return money_value; }

// ── 通用動態屬性 (dbase / temp_vars) ─────────────────────
void set(string prop, mixed val) {
    if (!dbase) dbase = ([]);
    dbase[prop] = val;
}

mixed query(string prop) {
    if (!dbase) return 0;
    return dbase[prop];
}

void delete(string prop) {
    if (dbase) map_delete(dbase, prop);
}

mixed add(string prop, int val) {
    if (!dbase) dbase = ([]);
    int cur = intp(dbase[prop]) ? dbase[prop] : 0;
    dbase[prop] = cur + val;
    return dbase[prop];
}

void set_temp(string prop, mixed val) {
    if (!temp_vars) temp_vars = ([]);
    temp_vars[prop] = val;
}

mixed query_temp(string prop) {
    if (!temp_vars) return 0;
    return temp_vars[prop];
}

void delete_temp(string prop) {
    if (temp_vars) map_delete(temp_vars, prop);
}

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

// ── ID 匹配 ─────────────────────────────────────────────
int id(string str) {
    if (!str || str == "") return 0;
    if (arrayp(id_list)) {
        return (member_array(str, id_list) != -1);
    }
    return (id_list == str);
}
