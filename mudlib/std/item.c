// std/item.c - 可攜帶物品基底類別

inherit "/std/object.c";

string  item_type;     // 物品種類
int     weight;        // 重量
int     value;         // 價值

// 🚀 新增：進階物品屬性
int     durability;    // 當前耐久度 (0 = 無限)
int     max_durability;// 最大耐久度
int     level_req;     // 等級需求
int     identified;    // 是否已鑑定

void create() {
    ::create();
    item_type = "misc";
    weight    = 0;
    value     = 0;

    durability     = 100;
    max_durability  = 100;
    level_req      = 1;
    identified     = 1; // 預設普通物品自動鑑定，稀有物品可設為 0
}

// ── 設定函式 ────────────────────────────────────────────
void set_item_type(string t) { item_type  = t; }
void set_weight(int w)       { weight     = w; }
void set_value(int v)        { value      = v; }

void set_durability(int v)     { durability = v; }
void set_max_durability(int v) { max_durability = v; durability = v; }
void set_level_req(int v)      { level_req = v; }
void set_identified(int v)     { identified = v; }

// ── 查詢函式 ────────────────────────────────────────────
string query_item_type() { return item_type; }
int    query_weight()    { return weight; }
int    query_value()     { return value; }

int    query_durability()     { return durability; }
int    query_max_durability() { return max_durability; }
int    query_level_req()      { return level_req; }
int    query_identified()     { return identified; }

// ── 功能函式 ────────────────────────────────────────────
// 損耗耐久度
void damage_durability(int v) {
    if (max_durability <= 0) return;
    durability -= v;
    if (durability < 0) durability = 0;
}

// 修復耐久度
void repair_item(int v) {
    durability += v;
    if (durability > max_durability) durability = max_durability;
}

