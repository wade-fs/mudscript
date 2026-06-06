// copy from Room: /d/snow/hockshop.c
// made by chun,and copy by ccat

#include "/open/open.h"
#include <room.h>

inherit HOCKSHOP;

void create ()
{
	set("short","高記當鋪");
  set ("long", @LONG
這裡是本地唯一的一家當鋪 . 由於楓林港居民大多生活富裕 
 , 物資充足 . 一天難得有幾個人來光顧 . 你看見整間店冷冷清
清的 , 與中央大街的喧囂繁鬧簡直是兩個世界 . 一張木牌(sign)
告訴你這裡的服務 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
	"east" : "/open/port/room/r1-3",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "	在這裡你可以典當(pawn)物品或者贖回(redeem)典當
	在這兒的物品，也可以鑑定(value)物品的價值。
",
]));
  set("light_up", 1);

  setup();
}
