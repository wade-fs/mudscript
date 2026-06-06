// Room: /open/main/room/f23.c

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
  "/open/gsword/mob/squirt" : 1,
  "/open/ping/questsfan/npc/chin" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"r36",
  "west" : __DIR__"f22",
  "south" : __DIR__"s28",
  "east" : __DIR__"f24",
]));

  setup();
}
