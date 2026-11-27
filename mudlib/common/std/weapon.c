// std/weapon.c - 通用武器基底類別 (World-Agnostic)

#include "/include/config.h"

inherit "/std/item.c";

int atk_bonus;   // 附加攻擊力
string wield_msg;

void create() {
    ::create();
    item_type = "weapon";
    atk_bonus = 5;
    wield_msg = "你揮舞了武器。\n";
}

void set_atk_bonus(int v)   { atk_bonus = v; }
int  query_atk_bonus()      { return atk_bonus; }
void set_wield_msg(string s){ wield_msg = s; }
