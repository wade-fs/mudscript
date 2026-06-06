//open/prayer/room/westarea/suhock.c
#include "/open/open.h"
#include <room.h>

inherit "/std/room/hockshop";

void create ()
{
  set ("short", "當鋪");
  set ("long", @LONG
	這是一家規模不大的當鋪, 西域原木的櫃臺上放著一張木牌
	(sign), 屋裡的光線不是很亮, 一塊西域手工製的布簾遮著
	出入口, 上面寫著

             ____ 願者上鉤,不願者回頭 ____

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "    在這裡你可以典當(pawn)物品或者贖回(redeem)典當
        在這兒的物品，也可以鑑定(value)物品的價值。
",
]));

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road36",
]));


  set("light_up", 2);

  setup();
}

