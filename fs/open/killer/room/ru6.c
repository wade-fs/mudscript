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
目前的通道，極為狹長，兩旁似乎隱藏了不少機關。
要是有人想進攻此處，必定會在此遭到夾擊。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west":__DIR__"ru4",
  "north":__DIR__"ru8",
]));

/*  set("objects",([
        "/open/killer/npc/hu_fa1.c" : 1,
        ]));  */
  setup();
}
