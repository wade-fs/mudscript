// Room: /open/main/room/r25.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 12 );
	set("long", "你正走在一條山谷中, 也因此這兒車馬相接, 絡繹不絕, 最吸
引人的是, 這附近的山區常常有特種藥草出現, 因此採藥草的武林
人士不遠千里而來. 道路在此呈東西走向.
");
 
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"m12",
  "west" : __DIR__"r24",
  "south" : __DIR__"m17",
  "east" : __DIR__"r26",
]) );

  set("outdoors", "/open/main" );
  

  setup();
}
