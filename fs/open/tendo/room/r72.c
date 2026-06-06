// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","監牢地道");
        set("long", @LONG
一進到這你就感到一陣陰風向你吹來，使你毛骨悚然，在這個地
道的左右就是一間間的牢房，你不禁在想--若一天你也被關來這那該
怎麼辦?
LONG);
set("exits", ([
        "south":__DIR__"r73",
	"east":__DIR__"r78",
	"west":__DIR__"r75",
	"north":__DIR__"r59",
]));
  setup();
}
