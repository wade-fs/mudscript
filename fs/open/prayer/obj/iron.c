//生鐵()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("生鐵", ({ "iron" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "塊");
          set("long",@LONG
	這是一塊剛從坑中挖掘出來的鐵礦!!鐵礦是製作武器時所必須
	的材料之一, 因為它的密度夠, 硬度佳, 延展性也適中!!所以
	是武器最常見的主要材質!!
LONG);
          set("value", 800);
          set("material", "iron");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


