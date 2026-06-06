inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("五彩原石",({"color-stone","color","stone"}));
	set("long","長年吸收天地靈氣之後蛻變而成的狂想原石。\n");
	set("unit","顆");
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
