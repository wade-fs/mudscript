// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","中央廣場");
        set("long", @LONG
這兒是天道派用來給初入門的弟子練防身武術的地方，你放眼四
望，看見了許許多多的天道弟子在練習紫龍鞭法，他們舞出的氣流把
你逼得一直往後退。
LONG);
  set("outdoors",1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/tendo/npc/boy":1,
]));
set("exits", ([
        "south":__DIR__"r43",
	"north":__DIR__"r49",
	"east":__DIR__"r47",
	"west":__DIR__"r39",
]));
  setup();
}
