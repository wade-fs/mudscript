//dragon-kee.c
//降龍勁 by Dico

#include <ansi.h>
 inherit F_FUNCTION;
 inherit SSERVER;
 inherit F_CLEAN_UP;

 int perform(object me, object target)
 {
  int skill,funlv,siseforce,temp;

  if(me->query("force")<50+(int)query_function("dragon-kee")*5)
        return notify_fail("你的內力不夠，無法運起降龍勁氣。\n");
  if(me->query("family/family_name") != "丐幫")
        return notify_fail("你不是丐幫弟子，無法駕馭降龍勁氣。\n");
  if((string)me->query_skill_mapped("unarmed") != "dragonfist")
        return notify_fail("降龍勁氣必須配合降龍絕學方可發揮。\n");
  if(me->query_temp("dragon-kee")==1)
        return notify_fail("你已經在用了。\n");

  temp=me->query("functions/dragon-kee/level","dragon-kee");
  skill = temp;
  siseforce=me->query_skill("siseforce",1);
  funlv=(int)me->query("functions/snow-powerup/level");
  me->add("force",-(50+skill*3));
  me->set_temp("dragon-kee",1);

  if(skill < 25)
  {
   message_vision(
"               $N運起洗髓經第一層功\力" + HIW + "－＝" + HIR + "V遊－龍－勁]" + HIW + "＝－" + NOR
"               只見一道遊龍之氣從$N的靈台穴竄出，使$N的力量源源不絕\n",me);
         me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
         if( me->is_fighting() ) me->start_busy(3);
         if(skill < siseforce)
         function_improved("dragon-kee",random(skill*20)+100);
         return 1;
  } else if ( skill < 50 )
  {
  message_vision(
"               $N運起洗髓經第二層功\力" + HIW + "－＝" + HIG + "W怒－龍－勁\\" + HIW + "＝－" + NOR
"               怒龍之氣從$N的後頂、風池兩穴爆出，使$N的內勁有如狂濤般一波強似一波\n",me);
         me->add_temp("apply/attack",skill);
         me->add("force_factor",skill/10);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
         if( me->is_fighting() ) me->start_busy(3);
         if(skill < siseforce )
         function_improved("dragon-kee",random(skill*18)+100);
         return 1;
  } else if ( skill < 75 )
  { 
   message_vision(
"                $N運起洗髓經第三層功\力" + HIW + "－＝" + HIY + "X狂－龍－勁[" + HIW + "＝－" + NOR
"                $N只覺全身內力遊走迅速，一瞬間，狂龍之氣從百會、風府、大椎、神道四穴射出，使你擁有排山倒海的勁氣\n",me);
         me->add_temp("apply/attack",skill);
         me->add("force_factor",skill/10);
         me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
         if( me->is_fighting() ) me->start_busy(3);
         if(skill < siseforce )
         function_improved("dragon-kee",random(skill*16)+100);
         return 1;
  } else if ( skill >= 100 )
  {
   message_vision(
"                $N運起洗髓經最上乘功\力" + HIW + "－＝" + HIB + "Y降－龍－勁Z" + HIW + "＝－" + NOR
"                $N以畢生功\力打通全身的奇經八脈，只見降龍氣勁從天而降護住$N全身要穴\n",me);
         me->add_temp("apply/attack",skill);
         me->add("force_factor",skill/10);
         me->add_temp("apply/defense",skill);
         me->add_temp("apply/unarmed",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
         if( me->is_fighting() ) me->start_busy(3);
         if(skill < siseforce )
         function_improved("dragon-kee",random(skill*14)+100);
         return 1;
  }
 } 
 
 void remove_effect(object me, int skill)
 { 
  me->delete_temp("dragon-kee");
  message_vision("$N的" + HIC + "降龍勁" + NOR + "開始崩潰渙散了。\n" + NOR,me);
  if(skill<25)
  {
  me->add_temp("apply/attack",-skill);
  } else if(skill<50)
  {
  me->add_temp("apply/attack",-skill);
  me->set("force_factor",10);
  } else if(skill<75)
  {
  me->add_temp("apply/attack",-skill);
  me->set("force_factor",10);
  me->add_temp("apply/defense",-skill);
  } else
  {
  me->add_temp("apply/attack",-skill);
  me->set("force_factor",10);
  me->add_temp("apply/defense",-skill);
  me->add_temp("apply/unarmed",-skill);
  }
 }

