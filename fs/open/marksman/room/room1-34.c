// Room: /u/f/fire/room/room1-34.c
#include <ansi.h>
#include "marksman.h"
inherit ROOM;

void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
溫暖的風兒向著我的臉頰吹起，長沙城裏的人們似乎在努力忙碌
著工作。你看到一群武林人士在長沙城內四處走動，和平的長沙城似
乎沒有任何暴力的行動出現。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-35.c",
  "east" : __DIR__"room1-3",
]));
set("outdoors","/open/marksman");

  setup();
}
