#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","紅葉組");
  set ("long", @LONG
這裡是黑牙聯總壇大廳右翼，也是黑牙聯最強的紅葉暗殺組的所在地。
江振武在此處，隨時待命出擊，並且培養自己的專屬殺手。
一身野心並不在葉秀殺之下，但是葉秀殺並不以為意。
因為江振武身上所散發出的霸氣，正是葉秀殺所需要的。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "westup":__DIR__"ru8.c",
  "east":__DIR__"redr2",
  "south":__DIR__"redr4",
]));

  set("objects",([
        "/open/killer/npc/rednpc1.c" : 2,
        ]));  
  setup();
}
