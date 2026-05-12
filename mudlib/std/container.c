// std/container.c - 容器基底類別

#include "/include/config.h"

inherit "/std/object.c";

// 容器屬性
int max_weight;    // 最大承重
int max_items;     // 最大容量（件數）

void create() {
    ::create();
    max_weight = 10000; // 預設 10kg
    max_items  = 20;    // 預設 20 件
}

// ── 權限檢查 ───────────────────────────────────────────

// 判斷物件是否可以進入此容器
// ob: 要進入的物件
// 回傳: 1 代表允許, 0 代表拒絕 (可進一步擴充回傳字串作為錯誤訊息)
int can_receive(object ob) {
    if (!ob) return 0;
    
    // 檢查件數上限
    object *inv = all_inventory(this_object());
    if (sizeof(inv) >= max_items) {
        return 0;
    }
    
    // 這裡可以增加重量檢查
    
    return 1;
}

// 判斷物件是否可以離開此容器
int can_release(object ob) {
    return 1; 
}

// ── 設定與查詢 ──────────────────────────────────────────
void set_max_weight(int w) { max_weight = w; }
int  query_max_weight()    { return max_weight; }
void set_max_items(int n)  { max_items = n; }
int  query_max_items()     { return max_items; }

// 取得當前總重量 (自身重量 + 內容物重量)
int query_weight() {
    int total = 0;
    // 如果物件本身有重量屬性，應該加上去
    // 但因為 container.c 不一定繼承 item.c，所以這裡先只算內容物
    object *inv = all_inventory(this_object());
    for (int i = 0; i < sizeof(inv); i++) {
        total += inv[i]->query_weight();
    }
    return total;
}
