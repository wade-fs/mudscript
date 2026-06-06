// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","城牆上");
  set ("long", @LONG
你正站在楓林港北面的城牆上 . 往西邊看去 , 有幾個全副
武裝的守衛正在巡邏著 . 其實楓林真正的外患來自南方 , 由水
路而來的他國 . 北方方圓百里內皆為本國領土 , 並無敵國 .
東邊為瞭望台 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"southdown" : "/open/port/room/r6-3",
	"east" : "/open/port/room/r6-7",
]));
	set("objects",([
	]));

  setup();
}
