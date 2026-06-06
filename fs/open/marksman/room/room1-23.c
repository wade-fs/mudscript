#include <room.h>
inherit ROOM;
#include "marksman.h"
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "強者之道");
	set( "build", 4 );
  set ("long", @LONG
你現在正站在將軍府，此地氣態萬千，遠近高低望之，都有不同
的氣象，其設計可謂巧奪天工。所有雕刻的鳥獸草木，都是遠從遠處
請來的大師嘔心瀝血之作，站在此地，不免要讚嘆人類工蹟之偉大。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room1-26.c",
  "north" : __DIR__"room1-24.c",
  "out" : __DIR__"room1-22.c",
  "east" : __DIR__"room1-25.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "out" : (: look_door,     "out" :),
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/marker" : 1,
]));
  set("light_up", 1);

  setup();
}
