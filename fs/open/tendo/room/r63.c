// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","走廊");
        set("long", @LONG
這兒是第二層，在這十分的安靜幾乎聽不到任何聲音，因為這裡
是掌門人等的休憩處，因此沒人敢在這大聲喧嘩。東邊是謢法長老的
休息室。
LONG);
set("exits", ([
	"east":__DIR__"r71",
	"north":__DIR__"r62",
	"south":__DIR__"r64",
]));
  set("light_up",1);
  setup();
}
