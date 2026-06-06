// Room: /open/capital/room/r51.c

inherit ROOM;

void create ()
{
  set ("short", "街道");
	set( "build", 12 );
  set ("long", @LONG
撼東門在你的北邊。左邊的牆較低矮，可以看見裡面的花園，百花
爭豔，花園裡有幾個婢女模樣的人和幾名男子相互戲耍著，你不禁感嘆
世風日下，但是又覺得有點羨慕。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/capital/room/r50",
  "north" : "/open/capital/room/r17",
]));

  set("gopath", "south");

  setup();
}
