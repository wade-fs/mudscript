// Room: /open/main/room/F1.c

inherit ROOM;

void create ()
{
  set ("short", "密林");
	set( "build", 373 );
  set ("long", @LONG
這裡一望無際的密林，四週伸手只見四指, 往西似乎稍微透出點亮光
那邊的樹應該比較少一些吧?
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 3,
]));

  set("light_up", "-1");

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"F4",
  "west" : __DIR__"f2",
  "east" : __DIR__"F2",
]));

  setup();
}
