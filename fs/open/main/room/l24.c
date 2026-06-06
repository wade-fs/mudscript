// Room: /open/main/room/L24.c

inherit ROOM;

void create ()
{
  set ("short", "台地");
  set ("long", @LONG
這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/wolf" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"L23",
  "south" : __DIR__"s34",
  "north" : __DIR__"r43",
  "east" : __DIR__"L25",
]));

  setup();
}
