// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","行宮內廳");
	set("long", @LONG
這邊是行宮的後廳﹐寒谷一派弟子平時沒事時﹐
偶爾會來此處聚集﹐談天閒聊的﹐好不熱鬧﹐此外
每當有重要聚會時﹐也都會在此處招開﹐這裡可以
算是寒谷的娛樂天地。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"south":COLD_ROOM"rin1",
	"north":COLD_ROOM"rin5",
]));
	set("objects",([
	]));
	setup();
	replace_program(ROOM);
}
