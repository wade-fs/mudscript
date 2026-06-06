// Room: /open/gblade/port/room/p2-2.c
inherit ROOM;

void create ()
{
   set("short", "石板大道");
  set ("long", @LONG
這裡是楓林港最繁榮的商業中心 , 一堆攤販沿路兜售 , 璘瑯滿
目的貨品 , 真是令人目不暇給 , 仔細看看 , 也許你會買到奇珍異
寶喔 , 走在這裡 , 你要當心點 , 自己的荷包可要看緊啊 ! 北邊是
一家破破的當鋪 , 看來也撐不久了 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p2-7.c",
  "west" : __DIR__"p2-3.c",
  "east" : __DIR__"p2-1",
]));

  setup();
}
