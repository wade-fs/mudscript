// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","監牢地道");
        set("long", @LONG
這兒左右都是一間間的牢房，但都是空的。真不知這些牢房是要
用來幹什麼的?
LONG);
set("exits", ([
        "south":__DIR__"r74",
	"north":__DIR__"r72",
	"east":__DIR__"r79",
	"west":__DIR__"r76",
]));
  setup();
}
