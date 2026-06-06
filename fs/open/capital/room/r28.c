// Room: /open/capital/room/r28.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
城南的小巷。和市中心的熱鬧相比，這兒顯得冷清多了，南邊就是
高聳堅固的城牆，可以看到士兵在城牆上來回巡邏著。往西北去即是日
落馳道。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"r30",
  "northwest" : __DIR__"r27",
]));
  set("gopath", "northwest");
  set("gopath2", "east");

  setup();
}
