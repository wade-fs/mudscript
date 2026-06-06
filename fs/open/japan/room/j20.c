inherit ROOM;

void create()
{
  set ("short", "南町南大路");
  set ("long", @LONG
寬闊平坦的路面，來來往往盡是衣著華利的商人，兩旁的小販正
叫賣著來自不同地方的商品。道路兩旁的房屋大而華麗，店家內商品
擺設多而齊全，恰似誇耀東瀛島的繁華。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"j21.c",
    "south" : __DIR__"j19.c",
  ]));
  setup();
}
