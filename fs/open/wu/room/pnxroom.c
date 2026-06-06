// 瀧山聖獸所在地-by nike-
//調整銀針門save_die解謎線索與調整判斷邏輯 by blazakira 2011/3/19

#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIM"瀧山聖地"NOR);
  set ("long", @LONG
這裡就是那瀧山派傳說中的聖地，據說這裡生有一隻美麗的火鳳，以
其生命不熄之火，源源不斷的供給瀧山派的護派聖火之永遠不滅，老一輩
的人都稱之為『鎮派聖獸』—「赤羽火鳳」，牠那美麗的尾羽，據傳便是
宇內五禽之一的「火鳳羽」，聽說價值相當不斐！
LONG);
  set("exits", ([
  "out" : __DIR__"luroom22",
]));

  setup();
}

void init()
{
  object me, ob;
  me = this_player();
  ob = new("/open/doctor/npc/pnx");

  if(present("delfire-mark",me) && !present("fire phoenix",environment(me)))
  {
    ob->move(environment(me));
  }
}
