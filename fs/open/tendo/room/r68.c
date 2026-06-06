// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","走廊");
        set("long", @LONG
這兒是第二層，在這十分的安靜幾乎聽不到任何聲音，因為這裡
是掌門人等的休憩處，因此沒人敢在這大聲喧嘩。
LONG);
set("exits", ([
	"south":__DIR__"r67",
	"east":__DIR__"r61",
]));
  set("light_up",1);
  setup();
}
