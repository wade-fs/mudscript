// Room: /open/prayer/room/tanshu/12.c

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
  "west" : __DIR__"21.c",
	"south":__DIR__"2-door",
  "north" : __DIR__"11.c",
  "east" : __DIR__"22.c",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
#include <room.h>
#include "/open/open.h"
  "/open/prayer/npc/trainee4" : 2,
]));
	set("no_clean_up", 0);
        create_door("south","聖火刻紋精鋼大門", "north",DOOR_CLOSED);


	setup();
	}
