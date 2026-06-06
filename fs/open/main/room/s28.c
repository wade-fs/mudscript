// Room: /open/main/room/s28.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set( "build", 36 );
	set("long", "這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s32",
  "north" : __DIR__"f23",
  "west" : __DIR__"s27",
  "east" : __DIR__"f25",
]) );

  set("outdoors", "/open/main" );

  setup();
}
