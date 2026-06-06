// Room: /open/prayer/room/tanshu/5.c

inherit ROOM;

void create()
{
	set("short", "偏廳");
	set("long", @LONG

    你所站的位置是天樞門的偏廳,通常一般門徒都在這習武,如果你
是習武之人,可以和他們切搓武藝,角落擺了一個兵器架,有刀,劍,槍,
鎚,戟...等各式兵器.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"4.c",
  "south" : __DIR__"6.c",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/general-manager" : 1,
]));
	set("no_clean_up", 0);

	setup();
	}
