// Room: /u/r/ranko/room/sh4.c
#include <room.h>
#include "/open/open.h"

inherit HOCKSHOP;

void create ()
{
  set ("short", "當鋪");
  set ("long", @LONG
本村僅有的一間當鋪，店裡堆放了許多破破爛爛的東西，東一
堆，西一堆凌亂地放著。大多是一些沒有價值的物品，據說本店的
老闆是一個奇怪的人，專門喜歡收集一些別人不要的東西當成寶來
存放著，因此村民只要一有不要的東西大多會拿來此處賣，而老闆
也是來者不拒，甚麼物品都照單全收。
你可以在此典當物品(pawn)，請人鑑定物品價值(value)，或贖回
典當的物品(redeem)。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v2-5.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/pawn.c" : 1,
]));
  set("light_up", 1);

  setup();
}
