#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","宿舍地下密室");
  set ("long", @LONG
這裡是柴榮所指示的密室，看來你要的人就在這裡了。千萬不可以掉以輕心。
由房中傳來的陣陣殺氣看來，此人已經起了殺機，想要動手殺了你。
如果，你沒有把握的話，還是盡快的從南方的狗洞爬出去吧。 

LONG);

  set("exits", ([ /* sizeof() == 3 */
"south":__DIR__"outr0.c",
]));

  set("objects",([
        "/open/killer/npc/wanted.c":1,
        "/open/main/obj/torch" : 1,
        ]));
  setup();
}
