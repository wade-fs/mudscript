// Room: /open/prayer/room/tanshu/6.c

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
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"5.c",
  "west" : __DIR__"3.c",
  "south" : __DIR__"9.c",
]));
	set("light_up", 1);
	set("no_clean_up", 0);
	set("short ", "偏廳");

	setup();
	}
