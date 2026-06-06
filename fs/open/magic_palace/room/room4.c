//玩家會藉由離線來避開傷害 因此先加上判斷來避開【系統】0(0): player:0 by blazakira 2011/1/13

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","魔宮");
  set("long",@LONG
你聞到空氣中傳了陣陣酸臭的味道，其中夾雜著硫磺硝石腐
屍的氣味，令人不禁作噁，地面上也不再見到濕滑的青苔，
取而代之的是泛黃的焦岩和冒著輕煙的滾燙裂石。

LONG);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("light_up",-1);
  set("exits", ([ /* sizeof() == 2 */
    "south"   : __DIR__"room3",
    "north"   : __DIR__"room5",
  ]));
  setup();
}

int valid_leave(object me, string dir)
{  
  me = this_player();
  if(!me || !environment(me)) return ;
  if (dir == "north")
  {        
    message_vision(HIG"$N不小心觸動機關，大量高熱強酸由牆壁中的縫隙湧出。\n"NOR,me);
    if ( !present("static_water",me) ) 
    {
      message_vision(HIR"$N身軀慘遭淹沒，雖運勁強撐，仍遭到難以想像的重創，全身焦爛。\n"NOR,me);
      me->add("eff_kee",-3000);
      me->add("eff_gin",-2000);
      me->add("eff_sen",-2000);
      me->add("kee",-4000); 
      me->add("gin",-2000);
      me->add("sen",-2000);
      COMBAT_D->report_status(me);
    }else{
      message_vision(HIW"$N身上的定水珠閃現一道強光，在面前形成一道障璧，完全阻隔了強酸的侵蝕。\n"NOR,me);
    }
    return 1;
  }
}
