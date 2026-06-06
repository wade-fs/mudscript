// Room: /u/f/funkcat/sample/j1
inherit ROOM;

void create ()
{
  set ("short", "地下密室");
  set ("long", @LONG
位於地下的密室。四面都是生滿青苔的大石塊，頭頂不時的有水滴
落下來，這裡大概是黑幫大本營的密室，不過奇怪的是遠遠傳來的交談
聲似乎不是中土的語言，難道...

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "up" : (: look_door,     "up" :),
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"j2",
  "up" : __DIR__"wulaih2",
]));
   create_door("up","暗門","down");

  setup();
}
