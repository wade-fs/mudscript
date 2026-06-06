// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","海岸");
	set( "build", 21 );
  set ("long", @LONG
這裡是楓林港的海岸 . 為免海水倒灌 , 或是有人遭到意外
 , 居名們在海岸旁加修了一道護堤 . 一條石子鋪成的小路向東
西方延伸 . 北邊即為單將軍廟 , 每到黃昏 , 廟旁的空地上便
聚集了捕魚歸來的漁民在此販賣 , 形成魚市 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r5-1",
	"west" : "/open/port/room/r5-3",
]));
	set("objects",([
	]));

  setup();
}
