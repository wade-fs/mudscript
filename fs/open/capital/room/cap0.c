// Room: /open/capital/room/cap0.c
#include "/open/open.h"
inherit ROOM;

void create()
{
  set ("short", "草原");
	set( "build", 12 );
  set ("long", @LONG
這兒是一片平坦的草原, 是皇上出外打獵遊玩的所在, 因此嚴禁一
般民眾在此遊蕩。你可以看到南邊的城牆, 便是皇上居住的皇宮了, 唯
一的一道門也有人在看守著。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 1 */
	"west" : MAIN_ROOM"f16",
]));
  setup();
}
