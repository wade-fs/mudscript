// Room: /u/g/guetenr/beggar/room/beg2/clr15.c
inherit ROOM;

void create ()
{
  set ("short", "太君山腳");
  set ("long", @LONG
樹木蒼翠，時有昆蟲獸鳴聲，不遠處正有幾個乞丐布袋裡拿出小
蛇，有黑有紅，有長有短，附近全是過膝的長草，或許已經有幾條小
蛇埋伏在你身邊了，你心下不禁慌亂，只覺毛骨悚然，若不想給咬上
一口，身中奇毒，最好夾起尾巴，迅速逃離此處吧。
LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"clr6.c",
  "west" : __DIR__"clr16.c",
]));

  setup();
}
