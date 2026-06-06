inherit ROOM;

void create ()
{
  set ("short", "沙漠盡頭");
	set( "build", 192 );
  set ("long", @LONG
你來到了撒哈拉沙漠的盡頭，陣陣風飛沙吹的你眼睛
無法看清楚前方，但依然可以聽到交談聲，東邊似乎有些
  人正在賣命工作著，北方則隱隱約約浮現一巨大高山。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"d7.c",
    "north": __DIR__"fmount1.c",
/*
  "east" : "/open/island/room/port",
*/
]));
  set("outdoors", "/open/main");

  setup();
}

