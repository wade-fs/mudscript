// std/item.c - 通用道具基底類別 (World-Agnostic)

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object.c";

string  item_type;    // "weapon", "armour", "consumable", "quest", "misc"
int     value;        // 市價（貨幣最小單位）
int     is_stackable; // 是否可疊加
int     stack_count;  // 當前堆疊數量

void create() {
    ::create();
    item_type   = "misc";
    value       = 0;
    is_stackable = 0;
    stack_count  = 1;
}

void set_item_type(string t)  { item_type = t; }
string query_item_type()      { return item_type; }
void set_value(int v)         { value = v; }
int  query_value()            { return value; }
void set_stackable(int v)     { is_stackable = v; }
int  query_stackable()        { return is_stackable; }
void set_stack_count(int n)   { stack_count = n; }
int  query_stack_count()      { return stack_count; }
