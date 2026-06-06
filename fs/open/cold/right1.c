// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","東側小路");
	set("long", @LONG
這裡是寶珍神宮東側的一條筆直小路﹐路上鋪著一粒粒細細的小石子
﹐往東直行便是東側行宮﹐據說﹐在行宮裡住的全都是寒谷一派的弟子
﹐而在東側行宮前是一座大型的校場﹐是平常寒谷弟子們修練之處。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"west":COLD_ROOM"home1",
	"east":COLD_ROOM"right2",
]));
	set("objects",([
	]));
	setup();
	replace_program(ROOM);
}
