// Room: /open/capital/room/r56.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋大街");
  set ("long", @LONG
這裡鄰近皇城，附近又多是達官貴人們的住所, 因此巡邏特別嚴密
不到一柱香的時間之內, 禁衛軍就來來回回巡了數趟, 也因為如此, 街
上也沒什麼人走動。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r55",
  "east" : __DIR__"r58",
]));
  set("outdoors", "/open/capital");

  setup();
}
