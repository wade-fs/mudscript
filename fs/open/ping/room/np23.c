#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "後堂");
	set( "build", 21 );
  set ("long", @LONG
    走進這裡, 是一間偏廳, 往北是段雲的房間, 兩旁各有一條走道,
長廊上鋪著上好的大紅地毯, 襯托出一股莊嚴的氣氛。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"p1.c",
  "west" : __DIR__"np24",
  "north" : __DIR__"np25",
  "east" : __DIR__"np22",
]));
  set("light_up", 1);
create_door("north","雕花紫壇木門","south",DOOR_CLOSED);
  setup();
}
