//黃甲金龍的皮革()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("黃甲金龍的皮革", ({ "dragon fur","fur" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "件");
          set("long","這是破邪洞窟中黃甲金龍的皮革, 傳聞黃甲金龍全身上下均具有龍的魔力。
          只要將這塊皮革拿去做成武器或防具!? 那不就..........\n");
          set("value", 800);
          set("material", "fur");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


