// Room: /u/f/fire/room/room1-17.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "天龍客棧");
  set ("long", @LONG
你正站在天龍客棧之中，雖說這裏是城內最大的客棧，這裏似乎
是武林人士所休息的地方。裏面只擺飾著一些簡單的傢俱，看到客棧
裏面的小二正在忙的不可開交。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room1-16",
  "up" : __DIR__"room1-18.c",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/cheng-chong" : 1,
]));

  setup();
}
