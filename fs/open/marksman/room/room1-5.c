// Room: /u/f/fire/room/room1-5.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "張家鐵鋪");
  set ("long", @LONG
你走進一間充滿熱氣的房子中，這裡是長沙城最大的打鐵鋪，在
房間的中央有一口高有四尺的大火爐，紅紅的火焰從爐中不斷的冒出
。在火爐中則有許多已經燒紅的鐵塊。在火爐的旁邊則是一缸好大的
清水。房內的鐵匠正在趕製一流的武器，你可以在這選出一流的武器
來使用。
想知道這裡有那些武器可以選用的話請用(view)來查看!!!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room1-4",
]));

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/chang-sen" : 1,
]));
  setup();
}
