//增加對手存在與否的判斷 by blazakira 2011/9/14

#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;

int fun,skl,fk;
int conjure(object me, object target)
{
  string msg;
  fun=me->query("spells/meteor/level");
  skl = (int)(me->query_skill("dremagic", 1));
  fk=(fun+skl)/2;
  if (!me->query("spells/meteor/level"))
    return 0;
  if( !target ) target = offensive_target(me);
  if(!me->is_fighting(target) )
    return notify_fail("這法術只能對戰鬥中的對手使用。\n");
  if(me->query("allow_meteor")!=1)
    return notify_fail("偷學的不能使用喔\n");
  if((me->query("family/family_name")!="夜夢小築")&&(me->query("id")!="cgy"))
    return notify_fail("只有舞者才能使用。\n");
  if((int)me->query("atman") < 300)
    return notify_fail("你的法力不夠﹗\n");
  if((int)me->query("gin") < 30 )
    return notify_fail("你的精神沒有辦法有效集中﹗\n");
  if(me->query_temp("meteor")==1)
    return notify_fail("你正在施法中\n");

  me->add("atman", -300);
  me->receive_damage("gin", 30);
  msg = CYN "$N突然將雙手向上高舉口中唸著：\n" NOR ;
  msg += HIC "天上的星辰啊！傾聽我的請求！用妳的烈焰燃燒一切邪惡！" NOR ;
  msg += HIW "終極火焰術"HIR"  流  星  雨  \n" NOR;
//  msg += HIR ": : : : : : : : : : : : : : : : : : : : : : : : : :: : : : : : : : : : : : : : : : : : : : : \n" NOR;
//  msg += HIR ": : : : : : : : : : : : : : : : : : : : : : : : : :: : : : : : : : : : : : : : : : : : : : : \n" NOR;
//  msg += HIR ": : : : : : : : : : : : : : : : : : : : : : : : : :: : : : : : : : : : : : : : : : : : : : : \n" NOR;
//  msg += HIR ": : : : : : : : : : : : : : : : : : : : : : : : : :: : : : : : : : : : : : : : : : : : : : : \n" NOR;
//  msg += HIR ": : : : : : : : : : : : : : : : : : : : : : : : : :: : : : : : : : : : : : : : : : : : : : : \n" NOR;
//  msg += HIR ": : : : : : : : : : : : : : : : : : : : : : : : : :: : : : : : : : : : : : : : : : : : : : : \n" NOR;
//  msg += HIR ": : : : : : : : : : : : : : : : : : : : : : : : : :: : : : : : : : : : : : : : : : : : : : : \n" NOR;
//  msg += HIR ": : : : : : : : : : : : : : : : : : : : : : : : : :: : : : : : : : : : : : : : : : : : : : : \n" NOR;
  message_vision(msg, me, target);
  me->set_temp("meteor",1);
  call_out("act1",1,msg,target,me,fun,fk);
  return 1;
}

int act1(string msg,object target,object me,int fun,int fk)
{
  int i;
  object *enemy;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  if(!enemy) return 1;
  me->set_temp("meteor",0);
  if(environment(me)->query("no_fight")) { tell_object(me,"施法中斷了！\n"); }
  for( i=0; i<sizeof(enemy); i++ )
  {
//    if( enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && !enemy[i]->query("no_kill") && enemy[i]!=me && !in_edit(enemy[i]) && !in_input(enemy[i]) && !enemy[i]->query_temp("netdead") && !wizardp(enemy[i]))
//    {
//      if(!(me->query("env/no_meteor_ppl") && userp(enemy[i])))
//      {
    if(random(fk)>10)
    {
      msg = HIM "結果"+enemy[i]->query("name")+"被從天而降的隕石打中！\n" NOR;
//      enemy[i]->kill_ob(me);
//      me->kill_ob(enemy[i]);
      enemy[i]->receive_damage("kee", fun*9+100,me);  
      message_vision(msg, me, target);
      COMBAT_D->report_status(enemy[i]);   
    } 
    else 
    {
      msg = CYN "可是"+enemy[i]->query("name")+"以極快的速度躲開了隕石。\n" NOR;
      message_vision(msg, me, target);
      COMBAT_D->report_status(enemy[i]);
    }
  }        
//    }
//  }
  if(fun<100) spell_improved("meteor",random(500));
//  me->start_busy(1); call_out四回合最大損傷1050還會被不相干的mob打, 故取消
  return 1;
}
