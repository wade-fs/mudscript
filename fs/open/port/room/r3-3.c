// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","東大街");
  set ("long", @LONG
你正走在東大街上 , 這一帶是楓林的住宅區 , 不過街道兩
旁仍然有些店鋪 . 北邊大屋傳來了朗朗的讀書聲 , 那是一家學
堂 , 如果你大字不識一個 , 趕緊過去看看吧 !

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r3-2",
	"east" : "/open/port/room/r3-4",
	"north" : "/open/port/room/r3-5",
]));
	set("objects",([
	]));

  setup();
}
