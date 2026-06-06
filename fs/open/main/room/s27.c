// Room: /open/main/room/s27.c

inherit ROOM;

void create()
{
	set("short","道路");
	set( "build", 12 );
	set("long",
"道路兩旁是一望無際的大草原 , 北邊是一片原始森林 ,
你看到南方有座新興的城市 , 大概就是近年來拜通航所賜而
快速發展的楓林港吧 !

");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s31",
  "north" : __DIR__"f22",
  "west" : __DIR__"s26",
  "east" : __DIR__"s28",
]) );

  set("outdoors", "/open/main" );

  setup();
}
