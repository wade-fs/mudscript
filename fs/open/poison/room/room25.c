inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
除了那個守衛外 ,這裡真是再平凡不過了 ,東邊是一所農家的院
子 ,你可以試著到裡面看看 ,看看有沒有人能告訴你 ,這裡到底
是啥地方 .北邊嘩啦嘩啦 ,好像有流水的聲音 .

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room28",
  "north" : __DIR__"room26",
  "south" : __DIR__"room24",
]));
  setup();
}


