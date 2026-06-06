// Room: /open/capital/room/r57.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋大街");
  set ("long", @LONG
這裡是三叉路口, 北方是通往連接皇城入口及東西二城門的街道, 
是京城的重要道路, 東西方連接著雲洋大街, 寬闊的大街別有一番雄偉
的氣象。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/capital/room/r53",
  "west" : "/open/capital/room/r56",
  "east" : "/open/capital/room/r58",
]));

  set("outdoors", "/open/capital");

  setup();
}
