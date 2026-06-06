// Room: /u/f/fire/room/room1-24.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "強者之道");
  set ("long", @LONG
在歷史悠久雄偉厚重的大門上鑲著邊緣由黃金打造、中央雕刻著
李廣大人在戰場上殺敵的雄偉，流露出黃忠大人的英勇，抬頭往上一
看是一座潔白的建築物，在陽光的照射下更顯得它高雅無比。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1-23",
  "west" : __DIR__"room1-28.c",
  "north" : __DIR__"room1-31.c",
  "east" : __DIR__"room1-27.c",
]));

set("light_up",1);
  setup();
}
