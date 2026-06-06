inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
你爬出了地道 ,立時被刺眼的陽光照的睜不開眼睛 ,這裡到底是
哪裡ㄋ ?左看右看 ,附近一個人都沒有 ,真是奇怪 ,看來得繼續
前進才能一探究竟了 .....

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room22.c",
  "north" : __DIR__"room24.c",
]));

  setup();
}
