// Room: /open/tendo/room/t10.c

inherit ROOM;

void create()
{
        set("short", "天道旁院");
	set( "build", 12 );
	set("long", @LONG
不同於一般的院子，這裡四季如春，豁草皆盛開，陣陣的香味撲
鼻而來讓你飄飄然、怡然舒暢，這些都是陸清風的專家所培育出來的
新品種，身價非凡。除了盛開的花朵外，還有鳥禽昆虫在此地駐居，
有時還會演奏出美妙的樂章,宛如天賴......

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"t09",
  "south" : __DIR__"t05",
	"east" : __DIR__"t11",
]));
	set("light_up",1);
	setup();
}
