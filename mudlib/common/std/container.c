// std/container.c - 容器基底類別 (World-Agnostic)

#include "/include/config.h"

inherit "/std/object.c";

int max_weight;    // 最大承重（克）
int max_items;     // 最大容量（件數）
int is_closed;     // 是否處於關閉狀態
int can_open;      // 是否可以被開啟/關閉

void create() {
    ::create();
    max_weight = 50000; // 預設 50kg
    max_items  = 30;
    is_closed  = 0;
    can_open   = 0;
}

// ── 重量計算 ───────────────────────────────────────────
int query_contents_weight() {
    int total = 0;
    object *inv = all_inventory(this_object());
    for (int i = 0; i < sizeof(inv); i++) {
        total += inv[i]->query_weight();
    }
    return total;
}

// 檢查放入原因：0=可放入, 1=無效, 2=已關閉, 3=件數滿, 4=超重
int query_receive_error(object ob) {
    if (!ob) return 1;
    if (is_closed) return 2;
    object *inv = all_inventory(this_object());
    if (max_items > 0 && sizeof(inv) >= max_items) return 3;
    if (max_weight > 0 && (query_contents_weight() + ob->query_weight() > max_weight)) return 4;
    return 0;
}

int can_receive(object ob) {
    return (query_receive_error(ob) == 0);
}

int can_release(object ob) {
    if (is_closed) return 0;
    return 1;
}

// ── 設定與查詢 ──────────────────────────────────────────
void set_max_weight(int w) { max_weight = w; }
int  query_max_weight()    { return max_weight; }
void set_max_items(int n)  { max_items = n; }
int  query_max_items()     { return max_items; }
void set_closed(int v)     { is_closed = v; }
int  query_closed()        { return is_closed; }
void set_can_open(int v)   { can_open = v; }
int  query_can_open()      { return can_open; }
