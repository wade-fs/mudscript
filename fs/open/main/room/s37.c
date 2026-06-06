// Room: /open/main/room/s37.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set( "build", 12 );
	set("long", "這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s30",
  "west" : __DIR__"s36",
  "east" : __DIR__"s38",
]) );

  set("outdoors", "/open/main" );

  setup();
}
