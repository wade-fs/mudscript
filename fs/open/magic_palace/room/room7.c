//玩家會藉由離線來避開傷害 因此先加上判斷來避開【系統】0(0): player:0 by blazakira 2011/1/13

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","魔宮-火硫酸池");
  set("long",@LONG
你身處魔宮的強酸池中，仍完全無懼週圍惡劣的環境，
但情況並不是那麼的樂觀，你最好還是趕快想辦法離開這個
危險的池子，盡快想辦法找到出路吧。

LONG);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("light_up",-1);
  set("exits", ([ /* sizeof() == 2 */
    "north"   : __DIR__"room10",
    "west"    : __DIR__"room5",
  ]));
  setup();
}

void init()
{
  call_out("do_check",1,this_player());
}

void do_check(object me)
{  
  me = this_player();
  if(!me || !environment(me)) return ;
  if ( !present("static_water",me) && environment(me) == this_object() )
  {
    message_vision(HIM + "強酸不斷的沖刷腐蝕著$N的身軀...。\n" + NOR,me);
    me->add("kee",-500); 
    me->add("gin",-300);
    me->add("sen",-300);                
    COMBAT_D->report_status(me);
  }
  call_out("do_check",1,this_player());
}
