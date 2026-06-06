#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG + "蛇身模組" + NOR,({"snake body","body","c-snake-2"}));
	set_weight(100);
	set("long","
這是一個蛇的身體部分，還欠缺蛇頭與蛇尾，才能組合(compose)
成一條完整的蛇。\n");
	set("unit","個");
	set("value",100);
setup();
}
