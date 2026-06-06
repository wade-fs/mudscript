// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","中央大街");
	set( "build", 102 );
  set ("long", @LONG
你正走在中央大街上 , 南邊就是港口了 . 這裡已經瀕臨著
海岸 , 幾個碼頭往難延伸出去 , 商用的 , 客運的 , 分的井然
有序 , 港口繁忙卻不紊亂 . 西邊是個小漁村 , 東邊則是水軍
軍營 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 4 */
	"east" : "/open/gblade/navy/room/d1-1",
	"west" : "/open/port/room/r5-2.c",
	"north" : "/open/port/room/r2-2",
        "south" : "/open/dancer/room/fonport", 
]));
	set("objects",([
	]));

  setup();
}
