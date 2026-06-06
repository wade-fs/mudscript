// Room: /open/capital/room/r50.c

inherit ROOM;

void create ()
{
  set ("short", "三叉路口");
	set( "build", 12 );
  set ("long", @LONG
北方的道路就是通往三大城門之一的撼東門，西方的街道便是所謂
的雲洋大街, 唯有一些權大勢大的人物才住的起這條街。由於這裡鄰近
皇城，附近又多是達官貴人們的住所，所以禁衛軍的巡邏也特別嚴密，
別想在這兒鬧事，那對你絕對沒好處。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/capital/room/r51",
  "south" : "/open/capital/room/r49",
  "west" : "/open/capital/room/r64",
]));

  set("gopath", "south");

  setup();
}
