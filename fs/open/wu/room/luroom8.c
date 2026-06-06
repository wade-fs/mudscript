// Room: /open/wu/room/luroom8.c
// 瀧山武館的練武場
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
這裏是瀧山武館的西北角的練武場,四周平坦,寬廣主要是用來教學的地
方，一眼望地便看到教練正在教導武館弟子修習瀧山武學的高級招式,
在一旁的你,看到瀧山的武學果然是威力異常,不愧和雪蒼武學並列第一
東邊的道路通往瀧山派的花園。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"luroom9",
  "west" : __DIR__"luroom5",
  "east" : __DIR__"luroom11",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/wu/npc/d_trainer" : 1,
  "/open/wu/npc/e_trainee" : 3,
]));

  setup();
}
