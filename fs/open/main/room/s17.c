// Room: /open/main/room/s17.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set( "build", 36 );
	set("long", "	在往北就是京城的鎮南門，這片草原十分的遼闊，
	南方有個御林軍的操練場。

");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"s16",
  "south" : __DIR__"s21",
   "north" : "/open/capital/room/D03",
  "east" : __DIR__"s18",
]) );

  set("outdoors", "/open/main" );

  setup();
}
