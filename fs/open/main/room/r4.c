// Room: /open/main/room/r4.c

inherit ROOM;

void create()
{
	set("short", "蜀中隘口");
	set( "build", 10 );
	set("long", "道路到此突然急劇的狹礙，兩旁的山壁直迫路前，在此形成
一到隘口，擁有一夫當關，萬夫莫敵的氣勢，蜀中城靠此天險，
不知渡過多少大風大浪. 道路在此呈南北走向.
");

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"[2]",
  "south" : __DIR__"r6",
]) );

  set("outdoors", "/open/main" );

  setup();
}
