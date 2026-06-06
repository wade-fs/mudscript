// Room: /open/main/room/d13.c

inherit ROOM;

void create()
{
	set("short", "沙漠");
	set( "build", 36 );
	set("long", "這兒是一望無際的撒哈拉沙漠，四周只現出閃閃發光的海市蜃樓
也不知哪裡是出口, 不時還出現沙漠特有的風暴, 恐怕難逃生天了吧?!
");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"d12",
  "south" : __DIR__"s13",
  "north" : __DIR__"d6",
  "east" : __DIR__"d14",
]) );

  set("outdoors", "/open/main" );


  setup();
}
