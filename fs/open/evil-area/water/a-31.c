inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",YEL + "沙 屋" + NOR);
	set("long",@LONG
一個混身長毛的大蟲子正站立在你的眼前，它手持著一個金黃色
大湯匙，不斷的攪拌著它眼前的那個大湯鍋，湯鍋由於受熱，不斷的
發出一股令人難以忍受的氣味，當你一走進屋內，那隻大毛蟲停下了
手上的工作，望向了你。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"out":__DIR__"a-27",
]));
	set("objects",([
__DIR__"npc/sell":1,
]));
	setup();
}

 
