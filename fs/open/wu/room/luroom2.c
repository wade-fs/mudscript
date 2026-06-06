// Room: /open/wu/room/luroom2.c
// 瀧山武館的練武場
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
這裏是瀧山武館的練武場,四周平坦,寬廣是武館教練用來教學的地方
，一眼望地便看到教練正在教導武館弟子修習瀧山武學的入門招式,在
一旁的你,看到雖是入門的招式,但也是精奧難學。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luroom3",
  "east" : __DIR__"luroom5.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/wu/npc/a_trainee" : 3,
  "/open/wu/npc/a_trainer" : 1,
]));

  setup();
}
