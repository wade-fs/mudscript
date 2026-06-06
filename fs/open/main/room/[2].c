// Room: /open/main/room/[2].c

inherit ROOM;

void create()
{
	set("short", "蜀中城郊");
	set( "build", 34 );
	set("long", "你看到你的北方有一座城，屋瓦比臨，煞是熱鬧，那應該是蜀
州要城蜀中城了. 你可以到那裡看看，也許\有你想要的東西. 道路
在此呈南北走向.
");

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r4",
  "north" : "/open/gsword/room/su0",
]) );


  set("outdoors","/open/gsword");
  setup();
}
