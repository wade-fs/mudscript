// Room: /open/main/room/M16.c

inherit ROOM;

void create ()
{
  set ("short", "少室山");
	set( "build", 12 );
  set ("long", @LONG
	這裡是天山山脈的少室峰，也是這塊大陸上最大的
	佛教聖地＝少林寺之所在，從這兒石階轉向西北而
	上，在石階的盡頭有座山門。


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "westup" : "/open/main/room/M15",
  "south" : "/open/main/room/M20",
  "eastdown" : "/open/main/room/m18",
  "eastup" : "/open/ping/questsfan/rm1",
]));

  setup();
}
