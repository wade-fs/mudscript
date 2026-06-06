// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","中央大街");
	set( "build", 57 );
  set ("long", @LONG
你正走在楓林港的大動脈 - 中央大街上 . 路中間用朱紅漆
的杈子圍了個區域 , 禁止人們通行 , 如此才能快速的流通貨物
 . 這裡時常有滿載商品的車隊經過 , 大概是在港口附近的原因
吧 ! 西邊是間香火鼎盛的廟宇 , 東邊的大宅就是威震江湖的武
威鏢局在楓林的分部 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 4 */
"east" : "/open/gblade/room/store",
	"west" : "/open/port/room/r2-3",
	"south" : "/open/port/room/r5-1",
	"north" : "/open/port/room/r2-1",
]));
	set("objects",([
	]));

  setup();
}
