// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","神殿側室");
	set("long", @LONG
這裡是神殿的側室﹐在裡頭所存放的是一些祭祀用的用品﹐
掌管神殿的主教總是叫負責的弟子﹐每天作好悸祀的事宜﹐並且
將用品在此放置好來。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"west":COLD_ROOM"lin1",
]));
	set("objects",([
	]));
	setup();
	replace_program(ROOM);
}
