//調整無法使用的線索 by blazakira 2011/10/8

#include <ansi.h>

int wind(object me,int lv);
int perform(object me,object ob)
{
  int lv;
//  me=this_player();
  lv=me->query("functions/wind-steps/level");
  if(me->query("force") < 500 )return notify_fail("你的內力不夠，休息一下再用吧!!\n");
  if (me->query("ninja/firstpart") != 1)
    return 0;
  if( me->query_skill_mapped("dodge")!="dark-steps" )
    return notify_fail("你的分功\化步法勒????????????\n");
  if(me->query_temp("wind") ==1 ) return notify_fail("你已經使用清風術了!!\n");
  if(me->query("class") !="killer" ) return notify_fail("你的職業無法使用!!\n");
  if(me->is_fighting()) me->start_busy(1);
  message_vision(HIC + "$N運起分功\化影之清風術，身形步伐頓時變得輕快起來!!\n" + NOR,me);
  me->add("force",-500);
  me->set_temp("wind",1);
  me->add_temp("apply/dodge",lv);
  me->add_temp("apply/move",lv);
  me->add_temp("apply/parry",lv);
  me->add_temp("apply/armor",lv);
  me->add_temp("apply/defense",lv);
  call_out("wind",80+lv,me);
  return 1;
}

int wind(object me,int lv)
{
  if(!me) return 1;
  lv=me->query("functions/wind-steps/level");
  message_vision(HIY + "$N" + HIY + "身邊的清風漸漸消散, $N" + HIY + "行動也變得遲緩起來!!\n" + NOR,me);
  me->delete_temp("wind",1);
  me->add_temp("apply/dodge",-lv);
  me->add_temp("apply/move",-lv);
  me->add_temp("apply/parry",-lv);
  me->add_temp("apply/armor",-lv);
  me->add_temp("apply/defense",-lv);
  if(me->query_function("wind-steps",1) < 100)
  {
    me->function_improved("wind-steps",random(300)+100);
  }
  return 1;
}
