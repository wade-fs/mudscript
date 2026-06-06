// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","走廊");
        set("long", @LONG
這兒是第二層，在這十分的安靜幾乎聽不到任何聲音，因為這裡
是掌門人等的休憩處，因此沒人敢在這大聲喧嘩。西邊是天道歷史發
展室。
LONG);
set("exits", ([
        "south":__DIR__"r66",
	"north":__DIR__"r68",
]));
  set("light_up",1);
  setup();
}
