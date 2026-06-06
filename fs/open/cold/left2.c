// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","西側神殿門口");
	set("long", @LONG
這裡就是寒谷西側神殿的入口﹐在殿門口﹐散出一陣陣的寒氣﹐
讓人感到此處的莊嚴﹐此處乃是祭拜著玄冰寒谷的開山祖師﹐相
傳她乃是天上的「冰谷女仙」轉世﹐法術好不驚人﹐移山倒海﹐
千變萬化﹐無所不能。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"enter":COLD_ROOM"lin1",
	"east":COLD_ROOM"left1",
	"west":COLD_ROOM"left3",
	"southwest":COLD_ROOM"left4",
]));
	set("objects",([
	COLD_NPC"trainee8":1,
	]));
	setup();
	replace_program(ROOM);
}
