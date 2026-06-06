// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","空牢房");
        set("long", @LONG
在這有一張床、一張桌子和一個用來嗯嗯的茅坑，但到處都結滿
了蜘蛛絲，可見這兒已很久沒有關過人了。前方有一扇加裝了鐵條的
窗戶、後方則是一扇僅容一人通過的窄門。
LONG);
set("exits", ([
        "east":__DIR__"r73",
]));
  setup();
}
