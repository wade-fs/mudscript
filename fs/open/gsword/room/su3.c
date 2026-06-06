// Room: /open/gsword/room/su3.c

inherit ROOM;

void create ()
{
  set ("short", "石板大道");
	set( "build", 1598 );
  set ("long", @LONG
這裡是蜀中的鬧區,嘻嘻嚷嚷,盡是來逛街的人潮,往西是一家
錢莊,東方則是一家商店,你也許可以在那裡買些東西.	
LONG);

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/mob/sells2" : 1,
  "/open/gsword/mob/woman" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/gsword/room/su4.c",
  "west" : "/open/gsword/room/subank",
  "south" : "/open/gsword/room/su2.c",
  "east" : "/open/gsword/room/sushop",
]));

  setup();
}
