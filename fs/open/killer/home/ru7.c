#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","總壇大廳左翼");
  set ("long", @LONG
這裡是黑牙聯總壇大廳左翼，為通往黑牙聯最狡詐的銀狼暗殺組的通道。
如此設計是為了保護大廳的安全，然而沒有葉秀殺命令，他們也不敢主動保護。
然而，必須小心的是不知道何時會有人從你背後冒出來，然後給你一刀。
狹長的通道，隱藏的機關，正代表了你將要去的地方。
傳說當年金刀門進攻此處，死傷無數。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east":__DIR__"ru5",
  "north":__DIR__"ru9",
]));

/*  set("objects",([
        "/open/killer/npc/hu_fa2.c" : 1,
        ])); */
  setup();
}
