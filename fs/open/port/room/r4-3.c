// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","西大街");
  set ("long", @LONG
由於四海刀聯和金刀門齊聚在此的緣故 , 這一帶成了刀客的   
大本營 . 走在路上的大多是強調以武力解決一切的刀客 . 如果
你沒有太大的把握 , 還是別想在此撒野的好 . 南邊的大宅是四
海刀聯 , 你看到許多刀客進進出出的 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r3-1",
	"west" : "/open/port/room/r4-2",
	"south" : "/open/port/room/r4-6",
]));
	set("objects",([
	"/open/port/npc/blademan2":1,
	]));

  setup();
}
