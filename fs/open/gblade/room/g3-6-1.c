#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "臥房");
  set ("long", @LONG

這間凡間華麗異常，牆上掛的是唐伯虎的『海棠春睡圖』，案上設的是武
則天當日鏡室中設的寶鏡；一邊擺著趙飛燕立著舞的金盤；盤內盛著安祿
山擲過傷了太真乳的木瓜；榻上是西施挽過的紗衾，紅娘抱過的鴛枕。看
看這裡又想想王大小姐的房間，沒想到即使是姊妹彼此間的差別也是很大
的。


LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"g3-6",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/shoue.c" : 1,
]));
  set("light_up", 1);
	create_door("north","雕花紫檀木門", "south",DOOR_CLOSED);

  setup();
}
