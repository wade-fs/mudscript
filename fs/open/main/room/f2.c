// Room: /open/main/room/F2.c

inherit ROOM;

void create ()
{
  set ("short", "密林");
	set( "build", 12 );
  set ("long", @LONG
這裡一望無際的密林，四週伸手只見四指, 可見其黑的程度
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"F5",
  "west" : __DIR__"F1",
  "east" : __DIR__"F3",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/p_item" :1,
  "/open/main/npc/lion" : 1,
]));

  setup();
}
