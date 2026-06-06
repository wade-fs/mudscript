inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", GRN + "長沙道" + NOR);
  set ("long", @LONG
輕風輕輕的往我的臉頰吹過，白藍藍的天空似乎多了一飛獸在空
飛舞著。從長沙道上可以清楚的聽見鳥兒的歌聲，在空中自由的飄揚
著。
LONG);

  set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"room1-3",
"north" : __DIR__"room1-9",
]));
set("outdoors","/open/marksman");

  setup();
}
