// std/item.c - 可攜帶物品基底類別

inherit "/std/object.c";

string  item_type;     // 物品種類
int     weight;        // 重量
int     value;         // 價值

void create() {
    ::create();
    item_type = "misc";
    weight    = 0;
    value     = 0;
}

// ── 設定函式 ────────────────────────────────────────────
void set_item_type(string t) { item_type  = t; }
void set_weight(int w)       { weight     = w; }
void set_value(int v)        { value      = v; }

// ── 查詢函式 ────────────────────────────────────────────
string query_item_type() { return item_type; }
int    query_weight()    { return weight; }
int    query_value()     { return value; }
