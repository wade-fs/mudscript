// Room: /open/badman/room/forest13.c
// written by powell 96.4.26@FS

inherit ROOM;

void create ()
{
  set ("short", "惡人森林");
  set ("long", @LONG
你走進了一大片森林之中，走著走著你才發現四周的景物似乎
一直都沒變過，讓你完全失去了方向。原來這裡就是著名的惡人森
林，據說只有惡人谷的人知道如何順利通過這片森林。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest14",
  "north" : __DIR__"forest10",
]));
  set("outdoors", "/open/badman");

  setup();
}
