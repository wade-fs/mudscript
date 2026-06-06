// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","阜財巷");
  set ("long", @LONG
這裡是阜財巷 , 兩旁住的不是高官 , 就是巨富 . 劉廉訪 ,
 王太宰 , 鄭尚書 , 鄧樞密等人都住在這裡 . 其中房舍最多 ,
 規模最大的首推史懷恩的史宅 . 東邊就是史宅 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/port/room/r3-4",
	"south" : "/open/port/room/r3-7",
]));
	set("objects",([
	]));

  setup();
}
