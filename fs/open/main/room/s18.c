// Room: /open/main/room/s18.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 12 );
  set ("long", @LONG
這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/blackhorse" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r16",
"east":"/open/area/pagoda/p00",
  "south" : __DIR__"s22",
  "west" : __DIR__"s17",
]));

  setup();
}
