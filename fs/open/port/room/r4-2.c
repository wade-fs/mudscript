// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","西大街");
	set( "build", 4 );
  set ("long", @LONG
你正走在西大街上 . 俗話說 : 百日刀 , 千日劍 . 由於刀
是最容易上手的武器 , 而且普及度極高 , 因此 , 刀成為時下
最流行的武器 . 不過 , 要想將刀的霸氣完全發揮 , 還是得下
過一番苦心才行 . 北邊為本國規模最大的刀器專賣店 , 南邊是
防具店 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r4-3",
	"west" : "/open/port/room/r4-1",
	"north" : "/open/port/room/r4-4",
	"south" : "/open/port/room/r4-5",
]));
	set("objects",([
	]));

  setup();
}
