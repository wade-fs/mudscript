#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "崎嶇的山路");
  set ("long", @LONG

	在你眼前的是一段更陡峭的山坡，兩旁是令人怵目驚心的峭壁。
	看來你得更小心的爬這一段山路，否則摔下去可不是開玩笑的。
	遠方似乎有水聲傳來？不會吧？在這種山中？

LONG);

  set("exits", ([ /* sizeof() == 3   */
     "north" : __DIR__"hr17.c",   
     "south" : __DIR__"hr15.c",   
]));

set("objects",([
  "/open/killer/npc/spy4.c":1,]));

  setup();
}
