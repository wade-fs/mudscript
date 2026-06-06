// Room: /open/capital/room/h15.c

inherit ROOM;

void create ()
{
  set ("short", "蘿蔔胡同");
	set( "build", 12 );
  set ("long", @LONG
這兒開始有行人走動了, 相對的, 也就熱鬧多了, 只是每個人都形
色匆匆的, 不知要趕著去哪? 不過這也不干你事, 還是逛逛四周, 欣賞
一下京城的景色要緊。南邊是頂頂大名的悅來客棧, 同樣的, 它也是乾
通天的產業之一。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"inn",
  "west" : __DIR__"h14",
  "east" : __DIR__"h16",
]));
  set("outdoors", "/open/capital");

  setup();
}
