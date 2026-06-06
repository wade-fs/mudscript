// Room: /open/prayer/room/tanshu/10.c

inherit ROOM;

void create()
{
	set("short", "偏廳");
	set("long", @LONG

    在廳上有許多高職位的門徒,個個面目嚴肅站在那裡,等候著向門
主報告份內的職責,以便門主能適時的處理掉棘手的問題,牆上是門主
所寫的書法,字字揮灑的淋漓盡致.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"8.c",
  "east" : __DIR__"2.c",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/vice-manager.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	}
