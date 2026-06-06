// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","走廊");
        set("long", @LONG
這兒是廣場四周的走廊，這個走廊做的十分考究，地上是用實心
的沈香木所鋪，而四周的欄干則是用熟鐵打造的，使得這個四方形的
走廊在白天太陽的照射下顯得十分耀眼。
LONG);
set("exits", ([
	"south":__DIR__"r32",
	"west":__DIR__"r34",
	"east":__DIR__"r55",
]));
  set("light_up",1);
  setup();
}
