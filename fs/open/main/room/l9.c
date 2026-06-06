// Room: /open/main/room/L9.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set( "build", 12 );
	set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L19",
  "west" : __DIR__"r38",
  "north" : __DIR__"m28",
  "east" : __DIR__"L10",
]) );

  set("outdoors", "/open/main" );


  setup();
}
