// Room: /open/main/room/L16.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set( "build", 12 );
	set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"r40",
  "south" : __DIR__"L19",
  "north" : __DIR__"L9",
  "east" : __DIR__"L17",
]) );

  set("outdoors", "/open/main" );


  setup();
}
