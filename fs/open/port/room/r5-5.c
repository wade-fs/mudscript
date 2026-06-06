// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","漁戶");
	set( "build", 12 );
  set ("long", @LONG
這是一間簡陋的平房 , 房子僅簡單的擺著一些家具 . 牆壁
十分的破舊 , 隨時都有倒塌的可能 , 你很難想像在富庶的楓林
港內竟然會有這種房子 , 不過看到他們臉上洋溢的笑容 , 似乎
過的比任何人都快樂呢 !

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/port/room/r5-3",
]));
	set("objects",([
	"/open/port/npc/boy":1,
	"/open/port/npc/wangma":1,
	]));

  setup();
}
