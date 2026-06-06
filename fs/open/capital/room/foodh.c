// Room: /open/capital/npc/foodh
inherit ROOM;

void create ()
{
  set ("short", "糧倉");
  set ("long", @LONG
一進門，發現眼前堆滿了一袋袋用麻布做成的米袋，排列整齊，好
像小山一樣高。辛苦的士兵赤裸著上身聽著長官的指示整理著這些重要
的米糧。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/capital/room/farm",
]));


  set("light_up", 1);
  set("objects",([
  "/open/capital/npc/managerwu":1,
  ]));

  setup();
}
