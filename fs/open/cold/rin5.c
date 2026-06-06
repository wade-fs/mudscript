// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","內側廂房");
	set("long", @LONG
這裡是行宮的內側廂房﹐通常﹐寒谷一派之中﹐
輩份較高者都住在這裡﹐在此處的人﹐個個法術高強
﹐決對不可輕視。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"south":COLD_ROOM"rin4",
]));
	set("objects",([
	COLD_NPC"ann":1,
	]));
	setup();
	replace_program(ROOM);
}
