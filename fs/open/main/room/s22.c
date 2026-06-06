// Room: /open/main/room/s22.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set( "build", 12 );
	set("long", "這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
");

 set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"s21",
  "south" : __DIR__"m22",
  "north" : __DIR__"s18",
  "east":"/open/quests/snake/r-01",
]) );

  set("outdoors", "/open/main" );

  setup();
}
