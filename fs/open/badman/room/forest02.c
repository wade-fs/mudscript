// Room: /open/badman/room/forest02.c
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

  set("objects",([ /* sizeof() == 1 */
  "/open/badman/npc/wart.c" : 1,
  ]));


  set("outdoors", "/open/badman");

  set("exits", ([ /* sizeof() == 4 */
  "west"  : __DIR__"forest02",
  "south" : __DIR__"forest02",
  "north" : __DIR__"forest02",
  "east"  : __DIR__"forest02",
]));

  setup();
}

int valid_leave(object who, string dir)
{
if( random(2)==1 ) {
                who->move(__DIR__"forest03");
		return notify_fail("");
	}
	return 1;
}

