// Room: /open/prayer/room/tanshu/22.c

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG

    「喝～喝～！」天樞的弟子正練習對打，如果你自認功夫到家，
    可以考慮看看下去插一腳，不過要記得打死人可不償命哦！

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"12.c",
  "north" : __DIR__"14.c",
]));
	set("objects", ([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1.c" : 2,
]));
	set("no_clean_up", 0);

	setup();
	}
