// Room: /open/main/room/f15.c

inherit ROOM;

void create ()
{
  set ("short", "森林");
	set( "build", 90 );
  set ("long", @LONG
這裡是一片廣大的原始森林，參差的樹木雜亂的長著，陽
光透過枝葉灑下點點金黃，地上則凌亂的部滿落葉與雜草.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/squirt" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r15",
  "west" : __DIR__"f14",
  "east" : __DIR__"f16",
]));
   set("objects",([
     "/open/main/npc/sho-long.c": 1
     ]));

  setup();
}
