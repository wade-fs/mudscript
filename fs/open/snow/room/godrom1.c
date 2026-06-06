// Room: /open/snow/room/godrom1.c
// 天靈谷
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "天靈谷");
  set ("long", @LONG
這裏就是傳說中的天靈谷，谷中長滿了許多不知名的奇珍異草散發出
的香味讓人心曠神怡，消除了你身上的疲倦，在花草之中有一條小路
向前方而去。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"godrom2.c",
]));
  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
}
