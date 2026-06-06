// Room: /open/prayer/room/tanshu/21.c

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG

    天樞門的練武場，弟子們汗流浹背的頂著大太陽，辛勤的練武只
為早日練成聖火的絕世武學，更希望有朝一日能在教中提升自己的地
位，可見要學成聖火教的武學，並非想像中的容易。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"13.c",
  "east" : __DIR__"12.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	}
