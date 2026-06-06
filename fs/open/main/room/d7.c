// Room: /open/main/room/d7.c

inherit ROOM;

void create ()
{
  set ("short", "沙漠");
	set( "build", 132 );
  set ("long", @LONG
這兒是一望無際的撒哈拉沙漠，四周只現出閃閃發光的海市蜃樓
東邊一道高高的圍牆, 似乎就是所謂的萬里長城吧?
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"d6",
  "south" : __DIR__"d14",
  "east" : __DIR__"gy1.c",
  "north" : "/open/ping/questsfan/richrm1",
]));
  set("outdoors", "/open/main");

  setup();
}
