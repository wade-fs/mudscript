// Room: /u/f/fire/room/room1-36.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"

void create ()
{
  set ("short", "民房");
  set ("long", @LONG
這一間民房和其他的房子並沒有什麼不同的地方。你似乎可以感
覺到房間裏都充滿著食物的香味，使你不禁流下一滴滴的口水，感覺
好噁心。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room1-35",
]));
  set("objects", ([ /* sizeof() == 2 */
C_NPC"/woman" : 1,
C_NPC"/oldwoman" : 1,
]));

  setup();
}
