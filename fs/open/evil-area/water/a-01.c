inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
在你的身旁走動著不少奇形怪狀的生物，不是頭上長個角就是身
上多了幾條觸鬚，不過每一個生物似乎都已經習慣了生活週遭活動著
不一樣的生物，你也漸漸的習慣了這種感覺...
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/mob01":1,
__DIR__"npc/mob02":1,
]));
	set("exits",([
"west":__DIR__"enter",
"east":__DIR__"a-23",
"south":__DIR__"a-22",
"north":__DIR__"a-02",
]));
	setup();
}

 
