// Room: /open/capital/room/r69.c

inherit ROOM;

void create ()
{
  set ("short", "中央大街");
	set( "build", 48 );
  set ("long", @LONG
走在京城的中央大街, 看到的是一幅繁華熱鬧的景象, 街上不時有
快馬奔過, 顯示出這條街交通的繁忙, 過路的人潮也不少, 讓你感受到
王朝活潑的朝氣與生命力, 右邊則是舞者公會, 左邊則是驛站。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r67",
  "south" : __DIR__"r70",
  "east" : __DIR__"dancer",
  "west" : "/open/trans/room/room1.c",
]));
  set("outdoors", "/open/capital");

  setup();
}
