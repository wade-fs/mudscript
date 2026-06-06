// Room: /open/main/room/F3.c

inherit ROOM;

void create ()
{
  set ("short", "密林");
	set( "build", 48 );
  set ("long", @LONG
這裡一望無際的密林，四週伸手只見四指, 往東看過去, 只見獅鹿
依稀散落在大片草原上
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"F6",
  "west" : __DIR__"F2",
  "east" : __DIR__"s1",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/bloodbat" :1,
  "/open/main/obj/torch" : 1,
]));

  setup();
}
