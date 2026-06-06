inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

頭頂傳來喀喀的巨響，也不知道是誰走路所發出來的腳步聲，透過這裡特
殊的構造，所產生的迴音還真是嚇人，你最好是快一點離開，免得被這振
耳的巨響給弄聾了。
你往地道的深處望去，地道似乎很久沒有人走過了，不知道裡面隱藏了些
什麼危機，你想是不是該多準備一些東西再來走這個地道？

LONG);

  set("light_up",0);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"g1-2.c",
  "north" : __DIR__"c2.c",
]));

  setup();
}
