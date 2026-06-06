// Room: /open/gblade/port/room/p4-1.c
inherit ROOM;

void create()
{
	set("short","五湖客棧");
  set ("long", @LONG
這裡是本港最大的客棧 , 取名為五湖客棧 , 正是因為客源
來自於五湖四海 , 這裡平常生意都非常之好 , 你幾乎很難找的
到空房 , 除非你能出的起更高的價錢 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"p3-2",
]));
  setup();
}
