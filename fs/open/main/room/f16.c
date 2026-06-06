#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "森林");
	set( "build", 36 );
  set ("long", @LONG
這裡是一片廣大的原始森林，參差的樹木雜亂的長著，陽
光透過枝葉灑下點點金黃，地上則凌亂的部滿落葉與雜草.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"f15",
  "east" : CAPITAL_ROOM"cap0",
 "north" : __DIR__"p18",

]));

  setup();
}


