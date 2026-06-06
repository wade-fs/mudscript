// Room: /open/prayer/room/tanshu/11.c

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG

    這裡是天樞門的練武場,最基層的門生都聚集在這習武,或許你可
以和他們切搓武藝,往北走就是天樞門的門門口. 

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"13.c",
  "south" : __DIR__"12.c",
  "north" : __DIR__"1.c",
  "east" : __DIR__"14.c",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/general" : 1,
]));
	set("no_clean_up", 0);

	setup();
	}
