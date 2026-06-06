//白銀()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("白銀", ({ "silver" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "塊");
          set("long",@LONG
	這是一塊白銀!!純度頗高!!白銀是一貴重的金屬, 可是安
	定性卻不是很好, 硬度也是差強人意, 不過密度高, 可以
	有效地防止武器的攻擊以及減低傷害力!!
LONG);
          set("value", 800);
          set("material", "silver");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


