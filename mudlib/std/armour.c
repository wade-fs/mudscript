// std/armour.c - 防具基底類別

#include "/include/config.h"

inherit "/std/object.c";

int    defence_bonus;
string slot;

void create() {
    ::create();
    set_item_type(ITEM_ARMOUR);
    defence_bonus = 3;
    slot          = SLOT_BODY;
}

void set_defence(int v)    { defence_bonus = v; }
void set_slot(string s)    { slot = s; }
int    query_defence()     { return defence_bonus; }
string query_slot()        { return slot; }
