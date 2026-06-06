// Room: /open/main/room/f14.c

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
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"f13",
  "south" : __DIR__"r14",
  "east" : __DIR__"f15",
"north" : __DIR__"p15",

]));

  setup();
}


