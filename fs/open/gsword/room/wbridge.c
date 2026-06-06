#include <room.h>

 inherit ROOM;

void create ()
{
  set ("short", "小拱橋");
  set ("long", @LONG
一做最簡單不過的小橋，窄的僅能容納數人通過，橋下一流清溪穿過，帶來
陣陣水氣，使你精神又為之一振，再往前面走就屬仙劍派的後山了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"walley4",
  "south" : __DIR__"walley3",
]));

  set("outdoors", "/open/gsword/room");
  set("objects",([
     "/open/gsword/mob/hunter.c" :1,
   ]));

  setup();
}
