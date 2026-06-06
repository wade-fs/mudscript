// copy from Room: /d/snow/hockshop.c
// made by chun,and copy by ccat

#include "/open/open.h"
#include <room.h>

inherit HOCKSHOP;

void create ()
{
  seteuid(ROOT_UID);
  set ("short", "平南當鋪");
  set ("long", @LONG
這是一家普通的當鋪,一塊藍布在門口垂下,上面寫著白色大
大的__當__字,一張木牌(sign)告訴你這兒的服務,並不而外多收
你錢.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "	在這裡你可以典當(pawn)物品或者贖回(redeem)典當
	在這兒的物品，也可以鑑定(value)物品的價值。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road3",
]));
  set("light_up", 1);

  setup();
}
