// Room: /u/w/whatup/area/shinyang/2-1.c
inherit ROOM;

void create ()
{
  set ("short", "城牆");
  set ("long", @LONG
這是保障襄陽城中的老百姓生命財產安全的關鍵，高約20丈的高
度近乎垂直的角度，就算是輕功再好的俠客似乎也無法一躍而上，整
齊劃一的衛兵們正在城牆上不停來回的巡邏，加強守備著襄陽城的安
全，不經令你感到欽佩。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"1-10.c",
  "south" : __DIR__"1-8.c",
]));
  set("no_auc", 1);
  set("outdoors", "/open");

  setup();
}
