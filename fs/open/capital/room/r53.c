// Room: /open/capital/room/r53.c

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG
這兒是皇城祭壇旁的街道, 因此裝修的非常美觀, 看起來一塵不染
的。由這兒可以通向雲洋大街與環宮大道, 是到皇宮的必經之路。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r52",
  "south" : __DIR__"r57",
]));
  set("outdoors", "/open/capital");

  setup();
}
