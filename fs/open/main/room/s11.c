// Room: /open/main/room/s11.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set( "build", 72 );
	set("long", "這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"p3",
  "west" : __DIR__"s10",
  "north" : __DIR__"d11",
  "east" : __DIR__"s12",
]) );

  set("outdoors", "/open/main" );

  setup();
}
