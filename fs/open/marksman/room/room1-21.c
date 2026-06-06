// Room: /u/f/fire/room/room1-21.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", GRN + "長沙道" + NOR);
  set ("long", @LONG
映在道路上的樹影遙曳擺動著，路邊的衿取草和野生的小紫含笑
散發出淡淡的花香，令人感覺非常的清爽。你似乎可以看到長沙城的
民眾在這裏閒逛著。
LONG);

  set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"room1-22",
"south" : __DIR__"room1-14",
]));
set("outdoors","/open");

  setup();
}
