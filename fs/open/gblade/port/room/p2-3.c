// Room: /open/gblade/port/room/p2-3.c
inherit ROOM;

void create ()
{
   set("short", "石板大道");
  set ("long", @LONG
這裡是楓林港最繁榮的商業中心 , 一堆攤販沿路兜售 , 璘瑯滿
目的貨品 , 真是令人目不暇給 , 仔細看看 , 也許你會買到奇珍異
寶喔 , 走在這裡 , 你要當心點 , 自己的荷包可要看緊啊 ! 西邊是
一家寵物店 , 進去看看吧 ! 北邊是皇帝最賞識的麵包師退休後所開
的店 , 買幾塊麵包捧捧場吧 !

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p2-9.c",
  "west" : __DIR__"p2-4.c",
  "east" : __DIR__"p2-2",
]));
	set("objects",([
	"/open/gblade/port/npc/man":1,
	]));

  setup();
}
