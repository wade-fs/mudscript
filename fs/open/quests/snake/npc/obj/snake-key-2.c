inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIC + "蛇型雕像" + NOR,({"snake statue","statue","snake-key-2"}));
	set_weight(300);
	set("long","這是一個小型的蛇型雕像，似乎是用來開啟某扇門。\n");
	set("unit","個");
	set("value",300);
	setup();
}
