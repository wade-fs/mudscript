// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","東側行宮門口");
	set("long", @LONG
這裡是寒谷的東側行宮入口﹐由此處即可進入東側行宮﹐往西通往
寒谷奇景「霜雨道」﹐往東則是「晚風亭」﹐往南通到「勸修園」即門
弟子平時練功之處。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"west":COLD_ROOM"right2",
	"south":COLD_ROOM"right4",
	"east":COLD_ROOM"right5",
	"enter":COLD_ROOM"rin1",
]));
	set("objects",([
	]));
	setup();
	replace_program(ROOM);
}
