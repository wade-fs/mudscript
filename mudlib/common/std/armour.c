// std/armour.c - 通用防具基底類別 (World-Agnostic)

#include "/include/config.h"

inherit "/std/item.c";

int def_bonus;   // 附加防禦力
string slot;     // "head", "body", "hands", "feet", "shield"

void create() {
    ::create();
    item_type = "armour";
    def_bonus = 3;
    slot      = "body";
}

void set_def_bonus(int v)  { def_bonus = v; }
int  query_def_bonus()     { return def_bonus; }
void set_slot(string s)    { slot = s; }
string query_slot()        { return slot; }
