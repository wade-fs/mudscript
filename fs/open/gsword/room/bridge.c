#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "小拱橋");
	set("long", "一做最簡單不過的小橋，窄的僅能容納數人通過，橋下一流清溪穿過，帶來
陣陣水氣，使你精神又為之一振，再往前面走就屬仙劍派的後山了。
");

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"alley3",
  "north" : __DIR__"alley4",
]) );

  set("outdoors", "/open/gsword/room" );


  setup();
}
