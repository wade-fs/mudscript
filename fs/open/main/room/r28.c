// Room: /open/main/room/r28.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 1 );
	set("long", @LONG
出了中央驛站，往東是一條筆直的道路，北方是
一座台地，但這兒沒有路可以上去，南方則是橫亙大
陸中央的天山山脈的一部份，壯觀的景色令人嘆為觀
止。可惜四處都找不到路可以上。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r27",
  "east" : __DIR__"r29",
]) );
  set("outdoors", "/open/main" );     
  setup();
}
