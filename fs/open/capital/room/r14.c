// Room: /open/capital/room/r14.c

inherit ROOM;

void create ()
{
  set ("short", "環宮大道");
	set( "build", 12 );
  set ("long", @LONG
走到這兒, 越來越能感受到皇朝嚴肅的氣氛與豪華, 仔細一看路上
的石板, 竟然也雕了複雜的圖案, 兩旁建築高聳, 仰望之下不禁升起敬
畏的心情。由於這裡是交叉路口, 因此街道不時有巡邏的軍隊走過, 顯
的氣氛十分緊張。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/capital/room/r17",
  "west" : "/open/capital/room/r13",
  "east" : "/open/capital/room/r15",
]));

  set("gopath", "south");

  setup();
}
