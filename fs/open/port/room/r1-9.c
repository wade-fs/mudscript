// Room: /open/gblade/port/room/p1-6.c
inherit ROOM;

void create()
{
	set("short","王氏雜貨鋪");
  set ("long", @LONG
這是一家雜貨鋪 , 販賣著火把 , 地圖等日常所需的東西 .
你看到店裡琳瑯滿目的陳列著各種商品 , 如果你有什麼在別家店
裡買不到的東西 , 也許可以在這裡找到 !

LONG);

  set("light_up", 1);
	set("objects",([
	"/open/port/npc/keeper_wang":1,
	]));
  set("exits", ([ /* sizeof() == 1 */
	"west" : "/open/port/room/r1-4",
]));
  setup();
}
