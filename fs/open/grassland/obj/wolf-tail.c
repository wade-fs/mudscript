inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("狼尾",({"wolf-tail"}));
	set("long","這是從殺死的狼身上割下的尾巴。\n");
	set("unit","塊");
	set("value",1);
	set("no_get",1);
	set("no_auc",1);
	set("no_drop",1);
	set("no_sell",1);
	set("no_put",1);
	set("no_save",1);
	set("no_steal",1);
	set_weight(1);
        setup();
}
