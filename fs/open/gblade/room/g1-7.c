inherit ROOM;

void create ()
{
  set ("short", "飯廳");
  set ("long", @LONG

飯桌上擺著好些精緻的小點心，藕粉桂花糖糕，松子鵝油捲，真不知道人
的手可以這麼巧妙做出這樣精緻的東西，還有一壺香冽異常的酒，你問了
問旁邊的婢女，才知道原來這壺酒是有名目的，喚作『萬豔同盃』也不知
道是用什麼釀成的。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"g1-8.c",
  "west" : __DIR__"g1-6",
]));

  set("light_up", 1);

  setup();
}
