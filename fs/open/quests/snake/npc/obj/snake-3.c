#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"蛇尾模組"NOR,({"snake tail","tail","c-snake-3"}));
	set_weight(100);
	set("long","
這是一個蛇的尾巴部分，還欠缺蛇頭與蛇身，才能組合(compose)
成一條完整的蛇。\n");
	set("unit","個");
	set("value",100);
setup();
}
