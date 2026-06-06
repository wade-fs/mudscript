//黃甲金龍的骨骼()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("黃甲金龍的骨骼", ({ "dragon bone","bone" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "根");
          set("long","這是破邪洞窟中黃甲金龍的骨骼, 傳聞黃甲金龍全身上下均具有龍的魔力。
          如果將骨骼拿去做成武器, 防具或衣服!? 真不知道會變成什麼樣子耶??..........\n");
          set("value", 800);
          set("material", "bone");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


