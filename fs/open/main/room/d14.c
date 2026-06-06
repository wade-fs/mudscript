// Room: /open/main/room/d14.c

inherit ROOM;

void create()
{
	set("short", "沙漠");
	set( "build", 60 );
	set("long", "這兒是一望無際的撒哈拉沙漠，四周只現出閃閃發光的海市蜃樓
東邊一道高高的圍牆, 似乎就是所謂的萬里長城吧?
");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"d7",
  "south" : __DIR__"p6",
  "west" : __DIR__"d13",
]) );

  set("outdoors", "/open/main" );


  setup();
}
