//黃甲金龍的眼珠()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("黃甲金龍的眼珠", ({ "dragon eye","eye" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "顆");
          set("long","這是破邪洞窟中黃甲金龍的眼珠, 傳聞黃甲金龍全身上下均具有龍的魔力。\n");
          set("value", 800);
          set("material", "gem");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


