// copy from Room: /d/snow/hockshop.c
// made by chun,and copy by ccat

#include "/open/open.h"
#include <room.h>

inherit "/std/room/hockshop";

void create ()
{
  set ("short", "蜀中當鋪");
  set ("long", @LONG
  這是一家中等規模的當鋪﹐老舊的櫃臺上放著一張木牌(sign),屋
裡的光線不是很亮,一塊藍色布簾遮著出入口,上面寫著

             ____ 歡迎光臨 ____
             
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "	在這裡你可以典當(pawn)物品或者贖回(redeem)典當
	在這兒的物品，也可以鑑定(value)物品的價值。
",
]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/su2",
]));


  set("light_up", 2);

  setup();
}
