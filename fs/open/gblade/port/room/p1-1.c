// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","楓林港北門");
  set ("long", @LONG
這是一棟剛建好不久的城門 , 幾個守衛在此看著來來往往的
旅客 , 由於商業的繁榮 , 楓林港吸引了來自大陸各地的商人到
此交易 , 相對的 , 這裡的犯罪率也是全國最高 , 你最好先看緊
自己的荷包 , 以免錢丟的不明不白 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"north": "/open/main/room/s38",
  "south" : __DIR__"p1-2.c",
]));
	set("objects",([
	"/open/gblade/port/npc/guard":2,
	]));

  setup();
}
