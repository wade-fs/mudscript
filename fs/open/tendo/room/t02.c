// Room: /open/tendo/room/t01.c

inherit ROOM;

void create()
{
        set("short", "道觀的外圍步道");
	set("long", @LONG
你正走在道觀的外圍步道上，上面鋪著堅硬的水磨青
磚，四周種滿了翠綠的數木，令人心神舒暢。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west"  : __DIR__"t01",
  "east"  : __DIR__"t03",
]));
	set("light_up",1);
	setup();
}
