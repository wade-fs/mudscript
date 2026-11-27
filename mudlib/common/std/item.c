// std/item.c - 通用道具基底類別 (World-Agnostic)

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object.c";

string  item_type;     // "weapon", "armour", "consumable", "quest", "misc"
int     weight;        // 重量（克）
int     value;         // 市價（貨幣最小單位）
int     is_stackable;  // 是否可疊加
int     stack_count;   // 當前堆疊數量

// 進階物品屬性
int     durability;    // 當前耐久度 (0 = 無限)
int     max_durability;// 最大耐久度
int     level_req;     // 等級需求
int     identified;    // 是否已鑑定
int     indestructible;// 是否不可破壞 (如徽章、裝飾品)

void create() {
    ::create();
    item_type      = "misc";
    weight         = 0;
    value          = 0;
    is_stackable   = 0;
    stack_count    = 1;

    durability     = 100;
    max_durability = 100;
    level_req      = 1;
    identified     = 1;
    indestructible = 0;
}

// ── 設定函式 ────────────────────────────────────────────
void set_item_type(string t)   { item_type      = t; }
void set_weight(int w)         { weight         = w; }
void set_value(int v)          { value          = v; }
void set_stackable(int v)      { is_stackable   = v; }
void set_stack_count(int n)    { stack_count    = n; }
void set_durability(int v)     { durability     = v; }
void set_max_durability(int v) { max_durability = v; durability = v; }
void set_level_req(int v)      { level_req      = v; }
void set_identified(int v)     { identified     = v; }
void set_indestructible(int v) { indestructible = v; }
void set_block_type(mixed t)   { set("block_type", t); }

// ── 查詢函式 ────────────────────────────────────────────
string query_item_type()      { return item_type; }
int    query_weight()         { return weight; }
int    query_value()          { return value; }
int    query_stackable()      { return is_stackable; }
int    query_stack_count()    { return stack_count; }
int    query_durability()     { return durability; }
int    query_max_durability() { return max_durability; }
int    query_level_req()      { return level_req; }
int    query_identified()     { return identified; }
int    query_indestructible() { return indestructible; }
string query_slot()           { return query("slot"); }
string query_slot_name()      { return query("slot_name"); }
int    query_attack()         { return query("attack"); }
int    query_defence()        { return query("defence"); }
string query_element()        { return query("element"); }

// ── 功能函式 ────────────────────────────────────────────
void damage_durability(int v) {
    if (indestructible || max_durability <= 0) return;
    durability -= v;
    if (durability < 0) durability = 0;
}

void repair_item(int v) {
    durability += v;
    if (durability > max_durability) durability = max_durability;
}

// ── 物品專用垃圾回收 (掉地消失機制) ─────────────────────
int clean_up(int inherited_count) {
    if (inherited_count > 0) return 1;

    object env = environment(this_object());
    if (env && living(env)) return 1;

    if (query_idle(this_object()) > 600) {
        if (strsrch(object_name(this_object()), "#") == -1) return 1;
        destruct(this_object());
        return 0;
    }

    return 1;
}
