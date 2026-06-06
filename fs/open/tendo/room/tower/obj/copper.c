//黃銅
#include <command.h>
inherit ITEM;

void create()
{
        set_name("黃銅", ({ "copper" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "塊");
          set("long",@LONG
        這是一塊黃銅!!黃銅的物理性質較生鐵穩定, 是最早被使用
        的金屬!!你可以將這塊黃銅拿去打造成武器或是防具!!不過
        黃銅的硬度較鐵小, 所以做成的武器可能會很容易就斷掉了
        !!
LONG);
          set("value", 800);
          set("material", "copper");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}



