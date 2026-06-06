// Room: /open/main/room/L25.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set( "build", 48 );
	set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s35",
  "west" : __DIR__"L24",
  "north" : __DIR__"r44",
  "east" : __DIR__"s29",
]) );

  set("outdoors", "/open/main" );


  setup();
}
