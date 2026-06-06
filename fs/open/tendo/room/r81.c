// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","密道");
        set("long", @LONG
四處陰森森的，空氣中瀰漫著一股不尋常的氣息，就連你帶進來
的火把也顯得十分的暗淡。這樣的場面使你怯步，心中一股寒意不禁
油然升起，有種聲音一直在叫你回頭，不要繼續往前走了....
LONG);
set("exits", ([
	"out":__DIR__"r74",
	"southwest":__DIR__"r82",
]));
  setup();
}
