// Room: /open/main/room/L13.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set( "build", 12 );
	set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s23",
  "south" : __DIR__"r41",
  "east" : __DIR__"L14",
]) );

  set("outdoors", "/open/main" );

  setup();
}
