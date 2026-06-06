// Room: /open/wu/room/luroom5.c
// 瀧山武館的練武場
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
這裏是瀧山武館的練武場,四周平坦,寬廣是武館教練用來教學的地方
，一眼望地便看到教練正在教導武館弟子修習瀧山武學的中級招式,在
一旁的你,看到瀧山的武學果然是精密異常,不愧是武林中的絕學。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"luroom2.c",
  "south" : __DIR__"luroom6",
  "east" : __DIR__"luroom8.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/wu/npc/d_trainee" : 3,
  "/open/wu/npc/d_trainer" : 1,
]));

  setup();
}
