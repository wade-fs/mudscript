// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","中央大街");
  set ("long", @LONG
你正走在楓林港最熱鬧的中央大街上 . 這一帶是楓林港的鬧
區 . 擠在人群中 , 看著兩旁的街景 , 攤販的叫賣聲 , 商人的
交易聲 , 此起彼落 , 讓你見識到了這裡的繁華 . 西邊有家大商
店 , 也許你可以進去看看 . 東邊是家雜貨鋪 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/port/room/r3-1",
	"east" : "/open/port/room/r1-9",
	"west" : "/open/port/room/r1-7",
	"north" : "/open/port/room/r1-3",
]));
	set("objects",([
	]));

  setup();
}
