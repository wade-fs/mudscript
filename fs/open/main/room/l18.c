// Room: /open/main/room/L18.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
");

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"L17",
  "north" : __DIR__"L11",
  "south" : __DIR__"L21",
]) );

  set("outdoors", "/open/main" );


  setup();
}
