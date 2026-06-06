// Room: /open/prayer/room/tanshu/20.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG

    這邊是天樞門的柴房，一堆一堆的木柴和枯樹枝，通常都是供給
炊事用的，不過門主也常利用這裡來關一些不守紀律的弟子。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"18.c",
]));
	set("no_clean_up", 0);

	setup();
	}
