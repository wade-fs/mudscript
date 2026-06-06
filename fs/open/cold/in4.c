// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","寶珍神宮後廳");
	set("long", @LONG
這裡是寶珍神宮的後廳﹐真在寶珍神宮裡有分大廳、內廳﹐側廳﹐
及後廳﹐而這個後廳是宮主平時養神、修心之處﹐每當宮主處理完一些
內務之後﹐常常會在此休息﹐而在廳內則有舞群獻舞﹐歌者奏樂﹐基本
上﹐寒谷一派的門人都十分清雅﹐連掌門也不例外。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"south":COLD_ROOM"in1",
	"north":COLD_ROOM"in5",
]));
	set("objects",([
	]));
	setup();
	replace_program(ROOM);
}
