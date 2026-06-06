// copy from Room: /d/snow/hockshop.c
// made by chun,and copy by ccat

#include "/open/open.h"
#include <room.h>

inherit HOCKSHOP;

void create ()
{
	set("short","楓林當鋪");
  set ("long", @LONG
這是楓林港唯一的一家當鋪 , 由於楓林港居民大都生活富裕 ,
加上黑市發達 , 交易熱絡 , 平常並不常有人走進當鋪 , 位於此精
華地帶 , 地價高昂 , 這間當鋪看來也撐不久啦 , 一張木牌(sign)
告訴你這裡的服務 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p2-2.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "	在這裡你可以典當(pawn)物品或者贖回(redeem)典當
	在這兒的物品，也可以鑑定(value)物品的價值。
",
]));
  set("light_up", 1);

  setup();
}
