// Room: /open/grassland/r01
#include "camp.h"
inherit ROOM;

void create ()
{
  set ("short", "黃土路");
  set ("long", @LONG
四周長滿成人般高的芒草，隱約中一條小路蜿蜒而去，彷彿在廣大的草
原中闢出一條獨特的路徑，不知道前方盡頭等待著的是什麼樣的地方，這提
起你莫大的好奇心，讓你不經想往前方一探究竟，此時間遠方的盡頭傳來一
聲巨響，令你突然停下腳步。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r01",
  "east" : __DIR__"r03",
]));
  set("objects",([
    __DIR__"npc/patrol.c":2
	]));
  set("path",({ "e","s","n","n","s","w" }));
  set("outdoors", "/open/grassland");
  set("no_transmit", 1);
  set("no_scale",1);
  set("no_kill",1);
  set("no_fight",1);
  setup();
}
