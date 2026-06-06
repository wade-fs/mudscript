// Room: /open/capital/room/r03.c

inherit ROOM;

void create ()
{
  set ("short", "環宮大道");
	set( "build", 12 );
  set ("long", @LONG
走到這兒, 越來越能感受到皇朝嚴肅的氣氛與豪華, 仔細一看路上
的石板, 竟然也雕了複雜的圖案, 兩旁建築高聳, 仰望之下不禁升起敬
畏的心情。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/r02",
  "east" : "/open/capital/room/r04",
]));

  set("gopath", "east");

  setup();
}
