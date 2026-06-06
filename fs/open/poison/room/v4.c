// Room: /open/poison/room/v6.v
inherit ROOM;

void create ()
{
  set ("short", "農舍");
  set ("long", @LONG
一間普普通通以磚瓦蓋成的屋子，這是供給村民所住的農舍，
裡面陳設十分簡單，沒有甚麼能引起你興趣的東西。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v2-2.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/open/poison/npc/child.c" : 1,
  "/open/poison/npc/vler2.c" : 1,
]));

  setup();
}
