// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","十字街口");
	set( "build", 127 );
  set ("long", @LONG
這裡是中央大街和東西兩大街的交叉口 . 這裡每到晚上會形
成夜市 , 販賣的商品種類層出不窮 , 時常會有些各國的商人到
此交易 , 使楓林港抹上繽紛的異國情調 , 來到這裡你要留心點
 , 說不定能買到奇珍異品 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r3-2",
	"south" : "/open/port/room/r2-1",
	"west" : "/open/port/room/r4-3",
	"north" : "/open/port/room/r1-4",
]));
	set("objects",([
	]));

  setup();
}
