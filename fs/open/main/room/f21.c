// Room: /open/main/room/f21.c

inherit ROOM;

void create ()
{
  set ("short", "森林");
	set( "build", 12 );
  set ("long", @LONG
這裡是一片廣大的原始森林，參差的樹木雜亂的長著，陽
光透過枝葉灑下點點金黃，地上則凌亂的部滿落葉與雜草.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 2,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s26",
  "north" : __DIR__"f18",
  "west" : __DIR__"f20",
  "east" : __DIR__"f22",
]));

  setup();
}
