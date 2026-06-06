// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","走廊");
        set("long", @LONG
這兒是第二層，在這十分的安靜幾乎聽不到任何聲音，因為這裡
是掌門人等的休憩處，因此沒人敢在這大聲喧嘩。往北是掌門人的休
息室，往南則是天道派的新膜拜堂。
LONG);
set("exits", ([
	"north":__DIR__"r70",
	"south":__DIR__"r86",
	"east":__DIR__"r62",
	"west":__DIR__"r68",
]));
  set("light_up",1);
  setup();
}
