// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","謢法長老休息室");
        set("long", @LONG
這裡是天道謢法長老 龍清和 的休息室，因為龍清和是謢法長老
，且又是掌門人的師兄，所以特別為他準備了一間休息室。你大概看
了一下，在這裡有一張床、一張小几子和一張辦公桌，看來這辦公桌
就是龍清和平日用來處理公文的地方了。
LONG);
  set("light_up",1);
set("exits", ([
	"west":__DIR__"r63",
]));
  setup();
}
