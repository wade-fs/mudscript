#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","總壇大廳右翼");
  set ("long", @LONG
這裡是黑牙聯總壇大廳右翼，也是通往黑牙聯最強的紅葉暗殺組的通道。
這樣的設計是為了保護大廳的安全，然而沒有葉秀殺命令，他們也不敢主動保護。
然而，必須小心的是不知道何時會有人從你背後冒出來，然後給你一刀。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west":__DIR__"masterm",
  "east":__DIR__"ru6",
]));

/*  set("objects",([
        "/open/killer/npc/hu_fa1.c" : 1,
        ]));  */
  setup();
}
