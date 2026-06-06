// Room: /open/gsword/room/su2.c

inherit ROOM;

void create ()
{
  set ("short", "石板大道");
	set( "build", 133 );
  set ("long", @LONG
 走到這裡,人群開始多了起來,嘻嘻嚷嚷,盡是來逛街的居民,
往西是一家鐵鋪,你可以在那買些武器,東方則是蜀中驛站,你可以
由驛站騎馬通往別處
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/sword_boy" : 1,
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/gsword/room/su3.c",
  "west" : "/open/gsword/room/susteal",
  "south" : "/open/gsword/room/su1.c",
  "east" : "/open/trans/room/room2",
]));

  setup();
}
