// Room: /open/main/room/L17.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set( "build", 36 );
	set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"L16",
  "north" : __DIR__"L10",
  "south" : __DIR__"L20",
  "east" : __DIR__"L18",
]) );

  set("outdoors", "/open/main" );


  setup();
}
