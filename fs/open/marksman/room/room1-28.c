// Room: /u/f/fire/room/room1-28.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "強者之道");
  set ("long", @LONG
從這裡可以更加的清楚的音樂，不只高亢的琴聲，還有釵h旋律
簡單而柔和的鋼琴聲。更令人注意的是在這宮殿的貴族似乎是跟著這
個音樂的節拍在走動，各各臉上露出一副快樂的表情。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room1-26.c",
  "north" : __DIR__"room1-30.c",
  "east" : __DIR__"room1-24",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/bowman1.c" : 2,
]));

  setup();
}
