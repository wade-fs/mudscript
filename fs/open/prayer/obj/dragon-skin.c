//黃甲金龍的鱗片()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("黃甲金龍的鱗片", ({ "dragon skin","skin" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "塊");
          set("long","這是破邪洞窟中黃甲金龍的鱗片, 傳聞黃甲金龍全身上下均具有龍的魔力。
          如果將鱗片拿去做成防具或衣服!? 那不就可以刀槍不入了嗎??..........\n");
          set("value", 800);
          set("material", "fur");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


