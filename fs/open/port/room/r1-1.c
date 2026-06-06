// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","楓林港北門");
  set ("long", @LONG
這裡是楓林港的北門 . 這是一棟兩層的樓台 , 高百尺 , 門
是大紅朱漆 , 配上金釘 , 屋頂是用琉璃瓦來蓋成 , 整座樓都是
朱欄彩檻 , 異常華麗 . 大門旁站著兩個守衛 , 注視著來來往往
的行人 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"north": "/open/main/room/s38",
	"south" : "/open/port/room/r1-2",
]));
	set("objects",([
	"/open/port/npc/guard":2,
	]));

  setup();
}
