// Room: /open/capital/room/r27.c

inherit ROOM;

void create()
{
	set("short","日落馳道");
	set( "build", 12 );
	set("long",@LONG
城西的車馬大道。為了方便大批禁衛軍的通行特地開闢的石板大道
。路面相當寬敞，比一般胡同大上五倍有餘，想想十幾年前與關外異族
打仗時軍隊在這來往奔馳的氣勢，就覺得神往不已。路旁種了兩排大榕
樹，這是和城東日升馳道唯一的不同。

LONG);

  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r28",
  "north" : __DIR__"r26",
]) );

  set("gopath", "north" );

  setup();
}
