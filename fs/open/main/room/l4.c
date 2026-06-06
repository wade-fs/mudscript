// Room: /open/main/room/L4.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"F11",
  "north" : __DIR__"L3",
  "east" : __DIR__"r5",
]) );

  set("outdoors", "/open/main" );


  setup();
}
