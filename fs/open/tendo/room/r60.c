// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","小閣樓之第二層");
        set("long", @LONG
這棟小閣樓將天道的區域給總括了起來，想到地下室，想上二樓
，都是要從這棟小閣樓來走的。四處的火把十分不明顯，你要來這最
好自己帶著火把。
LONG);
set("exits", ([
	"down":__DIR__"r58",
        "north":__DIR__"r65",
]));
  set("no_light",1);
  setup();
}
