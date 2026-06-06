// Room: /open/capital/room/r34.c

inherit ROOM;

void create ()
{
  set ("short", "中央街口");
  set ("long", @LONG
這裡連接著兩條胡同, 東邊是永福胡同, 西邊則是較繁華的永安胡
同, 素有『南市』之稱, 而京城裡的衙門便設在那永安胡同裡。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/fighter" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r35",
  "west" : __DIR__"r33",
  "north" : __DIR__"r72",
  "east" : __DIR__"r36",
]));
  set("gopath", "west");

  setup();
}
