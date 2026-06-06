// Room: /open/capital/room/r63.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋大街");
  set ("long", @LONG
這裡是丞相府的出入口，富麗堂皇的畫簷雕閣顯示出此人的奢侈與
虛榮，比鄰而居的是城內首富乾通天，由此可見兩人之交誼非淺，乾通
天能在城中擁有如此多的資產恐怕也都是因為丞相的幫助吧。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/capital/room/premier",
  "west" : "/open/capital/room/r62",
  "east" : "/open/capital/room/r64",
]));

  set("outdoors", "/open/capital");

  setup();
}
