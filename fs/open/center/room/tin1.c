// Room: /u/l/lotus/girl/tin1.c
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "穿堂");
  set ("long", @LONG
掛了兩盞明晃晃的花燈, 煞是好看, 姑娘唱小曲兒的歌聲一陣一
陣飄來 ~~
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"guest2.c",
  "north" : __DIR__"tin2.c",
  "east" : __DIR__"guest3.c",
]));
  set("light_up", 1);

  setup();
}
