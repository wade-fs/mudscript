// Room: /open/capital/room/r72.c

inherit ROOM;

void create ()
{
  set ("short", "中央大街");
	set( "build", 12 );
  set ("long", @LONG
走在京城的中央大街, 街上不時有快馬奔過, 顯示出這條街交通的
繁忙。路的西邊是軍機處, 歸兵部尚書管理。路的東邊是京城直設的民
政司, 專門負責平民的結婚事宜, 若你想與你的另一半共結連理的話,
請到民政司登記結婚吧。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r34",
  "north" : __DIR__"r71",
  "west" : __DIR__"soldier_room",
  "east" : __DIR__"merry",
]));
  set("outdoors", "/open/capital");

  setup();
}
