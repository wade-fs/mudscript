// Room: /open/japan/room/r2
inherit ROOM;

void create()
{
  set ("short", "東瀛島入口");
  set ("long", @LONG
這是一個神祕的島嶼,島上居民與中原武林有極大的差異
                         ....未完工^_^
LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"island.c",
  ]));
  setup();
}
