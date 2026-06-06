// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","中央大街");
  set ("long", @LONG
你正走在楓林港最熱鬧的中央大街上 . 這一帶是楓林港的鬧
區 , 街道兩旁擠滿了攤販 , 行人 , 各式各樣的商品令人目不暇
給 東邊是藥鋪 ,西邊則是驛站.

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r1-8",
    "west" : "/open/trans/room/room10",
	"south" : "/open/port/room/r1-4",
	"north" : "/open/port/room/r1-2",
]));
	set("objects",([
	]));

  setup();
}
