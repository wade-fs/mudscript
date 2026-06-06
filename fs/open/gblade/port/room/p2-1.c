// Room: /open/gblade/port/room/p2-1.c
inherit ROOM;

void create ()
{
    set("short" , "石板大道");
  set ("long", @LONG
這裡是楓林港最繁榮的商業中心 , 一堆攤販沿路兜售 , 璘瑯滿
目的貨品 , 真是令人目不暇給 , 仔細看看 , 也許你會買到奇珍異
寶喔 , 北邊是全國有數的大錢莊 , 南邊的商店 , 貨物之齊全 ,在
全國也是數一數二的 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 4 */
/*
  "south" : __DIR__"p2-6.c",
*/
  "north" : __DIR__"p2-5.c",
  "west" : __DIR__"p2-2.c",
  "east" : __DIR__"p1-3",
]));
	set("objects",([
	"/open/gblade/port/npc/man":1,
	]));

  setup();
}
