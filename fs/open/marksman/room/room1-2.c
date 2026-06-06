// Room: /u/f/fire/room/room1-2.c
#include <ansi.h>
#include "marksman.h"
inherit ROOM;

void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
你正走在一條石道路上，黃塵滾滾的道路向南北方向延伸而去。
路旁的草地上長著一些不知名的野花及野草。你看到長沙城裏人來人
往十分熱烈。
LONG);

  set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"room1-3",
"south" : __DIR__"room1-1",
]));
set("outdoors","/open/marksman");

  setup();
}
