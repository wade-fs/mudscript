// Room: /open/main/room/s4.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 24 );
  set ("long", @LONG
這裡是大草原的西邊, 往西邊看過去, 是黑壓壓的密林, 也許裡面有不可
思議的怪物, 還是少進去為妙! 南邊高高聳立著
一座高山, 山頂不知是雲還是雪, 一片白茫茫, 那裡難道是蜀山?
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/main/room/F6",
  "north" : "/open/main/room/s1",
  "east" : "/open/main/room/s5",
]));

  set("outdoors", "/open/main");

  setup();
}
