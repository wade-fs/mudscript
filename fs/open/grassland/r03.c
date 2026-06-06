// Room: /open/grassland/r01
#include "camp.h"
inherit ROOM;

void create ()
{
  set ("short", "黃土路");
  set ("long", @LONG
荒涼的路面，佈滿碎石依條蜿蜒而去的小路末端是一間大大個帳棚，
神秘詭異的環境，不經讓人提心吊膽，前方強大的氣息陣陣傳來，令你每
踏出一步都感到沉重的壓力，不短的路徑，走起來卻彷彿千年般的漫長。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"camp01.c",
  "west" : __DIR__"r02.c",
  "north" : __DIR__"r04.c",
]));
  set("outdoors", "/open/grassland");
  set("no_transmit", 1);
  set("no_scale",1);
  set("no_kill",1);
  set("no_fight",1);
  setup();
}
