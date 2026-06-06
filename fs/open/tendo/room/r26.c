// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","隧道");
        set("long", @LONG
一進入這個隧道中你就感到無比的亢奮，好像有什麼有趣的事要
發生了一樣。你不斷的克制自己的心神，但此時心神卻十分不聽話一
再的在你心中發出原始的吼聲..ㄡ ㄨ~~~
LONG);
set("exits", ([
        "out":__DIR__"r27",
]));
  set("no_light",1);
  setup();
}
