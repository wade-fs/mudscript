// Room: /open/main/room/L7.c

inherit ROOM;

void create ()
{
  set ("short", "台地");
  set ("long", @LONG
這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/main/room/L5",
  "east" : "/open/main/room/L8",
]));

  set("outdoors", "/open/main");

  setup();
}
