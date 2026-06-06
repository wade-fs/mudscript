// Room: /open/main/room/r27.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 13 );
	set("long", "	出了中央驛站，往東是一條筆直的道路，北方是
	座台地，但這兒沒有路可以上去，南方是橫亙大
	陸中央的天山山脈，壯觀的景色令人嘆為觀止。


");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/center/room/road4",
  "east" : __DIR__"r28",
]) );
  set("outdoors", "/open/main" );

  setup();
}
