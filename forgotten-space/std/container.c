// std/container.c - 容器基底類別

#include "/include/config.h"

inherit "/std/object.c";

// 容器屬性
int max_weight;    // 最大承重
int max_items;     // 最大容量（件數）

// 🚀 新增：開啟/關閉狀態
int is_closed;     // 是否處於關閉狀態
int can_open;      // 是否可以被開啟/關閉 (例如: 寶箱可開, 但麻袋可能永遠開著)

void create() {
    ::create();
    max_weight = 50000; // 預設 50kg (50000g)
    max_items  = 30;    // 預設 30 件
    is_closed  = 0;
    can_open   = 0;
}

// ── 權限檢查 ───────────────────────────────────────────

// 取得內容物總重量
int query_contents_weight() {
    int total = 0;
    object *inv = all_inventory(this_object());
    for (int i = 0; i < sizeof(inv); i++) {
        total += inv[i]->query_weight();
    }
    return total;
}

// 檢查放入原因：0=可放入, 1=無效物件, 2=已關閉, 3=件數滿, 4=超重
int query_receive_error(object ob) {
    if (!ob) return 1;
    if (is_closed) return 2;
    object *inv = all_inventory(this_object());
    if (max_items > 0 && sizeof(inv) >= max_items) return 3;
    if (max_weight > 0 && (query_contents_weight() + ob->query_weight() > max_weight)) return 4;
    return 0;
}

// 判斷物件是否可以進入此容器
int can_receive(object ob) {
    return (query_receive_error(ob) == 0);
}

// 判斷物件是否可以離開此容器
int can_release(object ob) {
    // 🚀 若容器已關閉，無法取出東西
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

// ── 互動：開啟/關閉 ───────────────────────────────────
int do_open() {
    if (!can_open) return 0;
    if (!is_closed) {
        write(query_name() + " 已經是開著的了。\n");
        return 1;
    }
    is_closed = 0;
    write("你打開了 " + query_name() + "。\n");
    say(this_player()->query_name() + " 打開了 " + query_name() + "。\n");
    return 1;
}

int do_close() {
    if (!can_open) return 0;
    if (is_closed) {
        write(query_name() + " 已經是關著的了。\n");
        return 1;
    }
    is_closed = 1;
    write("你關上了 " + query_name() + "。\n");
    say(this_player()->query_name() + " 關上了 " + query_name() + "。\n");
    return 1;
}

void init() {
    if (can_open) {
        add_action("do_open", "open");
        add_action("do_open", "開啟");
        add_action("do_close", "close");
        add_action("do_close", "關閉");
    }
}


// 取得當前總重量 (預設為內容物重量)
int query_weight() {
    return query_contents_weight();
}
