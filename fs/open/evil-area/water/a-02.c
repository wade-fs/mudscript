inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 揚 湖"NOR);
	set("long",@LONG
繞著琰揚湖邊走著，讓你似乎遺忘了你正身處於危險的邪靈界之
事，一樣有著動人的鳥啼聲、美艷的花、芳香的水氣，以及秀麗的景
色，你不禁懷疑，這裡是曾經造成整個大地恐慌的五邪靈使之一的水
邪將--水柔纏　所居住的地方？
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/mob01":2,
__DIR__"npc/mob02":1,
]));
	set("exits",([
"south":__DIR__"a-01",
"north":__DIR__"a-03",
]));
	setup();
}

 
