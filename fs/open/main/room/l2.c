// Room: /open/main/room/L2.c

inherit ROOM;

void create ()
{
  set ("short", "台地");
	set( "build", 12 );
  set ("long", @LONG
這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/main/room/s8",
  "west" : "/open/main/room/L1",
  "east" : "/open/main/room/L3",
]));

  set("outdoors", "/open/main");

  setup();
}
