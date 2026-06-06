// Room: /open/main/room/d2.c

inherit ROOM;

void create()
{
	set("short", "沙漠");
	set( "build", 72 );
	set("long", "這兒是一望無際的撒哈拉沙漠，東邊有一棟建築依勢而建，
從這兒看過去, 卻看不到入口, 不知它的門是在哪一邊?
");

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"d9",
  "west" : __DIR__"d1",
]) );

  set("outdoors", "/open/main" );


  setup();
}
