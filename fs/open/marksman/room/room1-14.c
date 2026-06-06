// Room: /u/f/fire/room/room1-14.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", GRN + "長沙道" + NOR);
  set ("long", @LONG
你正走在一條直直長長的長沙道上，長沙道兩旁長滿不知名的野
花雜草，清爽的微風正徐徐的吹來，溫柔的親吻你的臉頰，實令你心
曠神怡，久久無法忘懷。
LONG);

  set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"room1-21",
"south" : __DIR__"room1-13",
]));
set("outdoors","/open");

  setup();
}
