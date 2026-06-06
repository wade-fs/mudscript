// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","石板大道");
	set( "build", 24 );
  set ("long", @LONG
你正走在一條又寬又平坦的石板大道上 . 自從楓林建港之後
倭寇便不斷來襲 , 朝廷有鑑於僅憑守衛隊兵力並不足於確保港口
安全 , 所以在此建立水軍 , 以抵禦外敵 . 北邊即為水軍總督府
 , 東邊是個閱武場 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/gblade/navy/room/d1-2.c",
	"east" : "/open/gblade/navy/room/d1-4.c",
]));
	set("objects",([
	]));

  setup();
}
