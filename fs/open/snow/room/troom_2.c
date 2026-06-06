// Room: /u/e/eiei/work/troom_2.c
inherit ROOM;

void create ()
{
  set ("short", "林間小路");
  set ("long", @LONG
    走著走著，你發現似乎越往山上走，路上所看到的
    奇花異草種類越來越怪異，其中有一些花的顏色在平常
    是根本不可能看到的，而且花所飄散出來的芳香也是你
    從來沒有聞過的，聞了以後竟讓人有一種飄飄欲仙的感
    覺！
LONG);

  set("outdoors", "/u/e/eiei/workroom");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"troom_3.c",
  "south" : __DIR__"troom_1.c",
]));

  setup();
}
