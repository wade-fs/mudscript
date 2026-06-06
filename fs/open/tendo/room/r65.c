// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","走廊");
        set("long", @LONG
這兒是第二層，在這十分的安靜幾乎聽不到任何聲音，因為這裡
是掌門人等的休憩處，因此沒人敢在這大聲喧嘩。往南走可到小閣樓
，往東可到謢法長老休息室，往西則是到天道歷史發展室。
LONG);
set("exits", ([
	"south":__DIR__"r60",
	"east":__DIR__"r64",
	"west":__DIR__"r66",
]));
  set("light_up",1);
  setup();
}
