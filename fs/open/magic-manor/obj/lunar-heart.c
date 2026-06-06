#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC + "散玄冥陰心" + NOR, ({ "lunar heart","heart" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "塊");
		set("long","右靈晉所持有，傳說是通往天靈地界的導引物。\n");
		set("value", 0);
		set("no_sell",1);
		set("no_put",1);
		set("no_auc",1);
		set("no_sac",1);
		set("no_drop",1);
		set("no_steal",1);
		set("no_give",1);
		set("go-sky",1);

        }
}
