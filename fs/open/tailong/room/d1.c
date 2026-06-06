inherit ROOM;

void create ()
{
  set ("short", "小徑");
  set ("long", @LONG
你進到了竹林裡的小徑，只聽到風吹過竹林所產生的沙沙聲
響，在你的正前方，隱隱約約可以看到一棟屋子，令你想要前去
一探究竟。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "back" : __DIR__"aa52",
  "north" : __DIR__"d2",
]));

  set("no_transmit",1);
  setup();
}
