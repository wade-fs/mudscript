// Room: /open/main/room/r2.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 48 );
	set("long", "這裡是從驛站通往北盧關必經的要道, 四周的景色實在是令人
永生難忘, 沙漠草原沼澤群集, 路上不時出現稀奇古怪的生物來。
");

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"r1",
  "southeast" : __DIR__"p1",
  "southwest" : __DIR__"r3",
  "northwest" : __DIR__"d9",
]) );

  set("outdoors", "/open/main" );

  setup();
}
