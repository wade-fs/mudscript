inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 揚 湖"NOR);
	set("long",@LONG
合適的溫度，陣陣暖風吹拂著你的臉龐，你忍不住的打起了哈欠
，寧靜的湖邊，你可以看到幾隻魔獸正在舔舐著自己的肢體，彷彿柔
順的貓一般，只是感覺上滿不搭嘎的，你斜眼偷偷注視著它，它也正
呆望著你，或許在彼此的眼中，對方都是一個奇怪的生物吧...
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/mob01":1,
]));
	set("exits",([
"south":__DIR__"a-02",
"north":__DIR__"a-04",
]));
	setup();
}

 
