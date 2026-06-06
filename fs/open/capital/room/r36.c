// Room: /open/capital/room/r36.c

inherit ROOM;

void create ()
{
  set ("short", "永福胡同");
  set ("long", @LONG
這兒是一段上坡路，走起來有點吃力。城的東南有座小丘陵，因為
地勢的緣故，從這往東走一直都是上坡。北面是一些普通的民宅。南面
是堅固的城牆。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r34",
  "east" : __DIR__"r38",
]));
  set("gopath", "west");

  setup();
}
