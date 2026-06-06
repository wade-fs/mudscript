// Room: /open/main/room/L3.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set( "build", 24 );
	set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L4",
  "west" : __DIR__"L2",
  "north" : __DIR__"s9",
  "east" : __DIR__"r3",
]) );

  set("outdoors", "/open/main" );


  setup();
}
