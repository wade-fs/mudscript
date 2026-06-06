// Room: /open/main/room/s13.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set( "build", 48 );
	set("long", "這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"s12",
  "south" : __DIR__"p5",
  "north" : __DIR__"d13",
  "east" : __DIR__"s14",
]) );

  set("outdoors", "/open/main" );

  setup();
}
