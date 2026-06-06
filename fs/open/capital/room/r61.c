// Room: /open/capital/room/r61.c

inherit ROOM;

void create ()
{
  set ("short", "三叉路口");
  set ("long", @LONG
北方是通往連接皇城入口及東西二城門的街道, 是京城的重要道路
。西北邊的廣場是乾通天所開設的競技場。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r60",
  "north" : __DIR__"r74",
  "east" : __DIR__"r62",
]));

  set("outdoors", "/open/capital");

  setup();
}
