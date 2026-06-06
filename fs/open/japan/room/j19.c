inherit ROOM;

void create()
{
  set ("short", "南町南十字路口");
  set ("long", @LONG
寬闊平坦的路面分別向四方延伸，路邊茶攤的老闆娘正親切的招待
每一位遠來的客人。而商人們也在此稍微歇腳，並趁機交換著各地
不同的小席。路旁的告示牌(card)指示著方向。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("item_desc", ([ /* sizeof() == 1 */
    "card" : ""+
      "┌───────────┐\n"+
      "│       南  町         │\n"+
      "│         ↑           │\n"+
      "│臨港村←    →海軍基地│\n"+
      "│         ↓           │\n"+
      "│       關  卡         │\n"+
      "└───────────┘\n",
  ]));
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"j20.c",
    "west" : __DIR__"j22.c",
    "south" : __DIR__"j18.c",
  ]));
  setup();
}
