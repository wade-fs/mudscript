// Room: /open/capital/r31.c

#include "/open/capital/capital.h"
	
inherit ROOM;
									
void create ()
{
  set ("short", "紫藤蘆");
  set ("long", @LONG
茶館。老板修養很好，取了個很雅的名子，四周也都種了一些藤蔓
，延著牆壁長著，一片綠意，煞是好看。店裡茶香四溢，感覺暖烘烘的
。茶館就是茶館，小道消息最多的地方，武林大事，芝麻小事，這兒都
有，由其這兒的小二，人稱天耳通，大小事都知曉，要問甚麼事，找他
就對了。

LONG);

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/waiter1" : 1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/capital/room/r31",
]));

  set("gopath", "west");

  setup();
}
