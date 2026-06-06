// Room: /open/prayer/room/tanshu/2.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG

    你走在天樞門的走廊上,每走五步就是一盞油燈,那油燈站立著足
足有四尺高,且雕刻的好不細緻,牆上一幅金龍的大壁畫直到大廳你所
站的這裡是龍身,原來門主葛輝的品味只是如此.

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"10.c",
  "north" : __DIR__"3.c",
  "south" : __DIR__"1.c",
  "east" : __DIR__"9.c",
]));
	set("light_up", 1);
	set("no_clean_up", 0);
	set("", "");

	setup();
	}
