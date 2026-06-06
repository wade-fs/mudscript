// Room: /open/badman/room/forest04.c
// written by powell 96.4.26@FS

#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "惡人森林");
  set ("long", @LONG
你走進了一大片森林之中，走著走著你才發現四周的景物似乎
一直都沒變過，讓你完全失去了方向。原來這裡就是著名的惡人森
林，據說只有惡人谷的人知道如何順利通過這片森林。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  BAD_NPC"gibbon" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 4 */
  "west"  : __DIR__"forest05",
  "south" : __DIR__"forest07.c",
  "north" : __DIR__"forest08.c",
  "east"  : __DIR__"forest03",
]));

  setup();
}
