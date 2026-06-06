// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","石板大道");
	set( "build", 33 );
  set ("long", @LONG
這是一條極為平坦的石板大道 . 南邊為海岸(沿岸) , 道路
隔著提防 , 順著海岸成東西走向 . 這條道路是近幾年新闢的 ,
用硬度極佳的花岡石所鋪成 , 以作為軍事用途 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r5-1",
	"east" : "/open/gblade/navy/room/d1-2.c",
]));
	set("objects",([
	]));

  setup();
}
