//dragon-kee.c
//sl by Dico

#include <ansi.h>
 inherit F_FUNCTION;
 inherit SSERVER;
 inherit F_CLEAN_UP;

 int perform(object me, object target)
 {
  int skill,funlv,siseforce,temp;

  if(me->query("force")<50+(int)query_function("dragon-kee")*5)
        return notify_fail("AOALkB_slC\n");
  if(me->query("family/family_name") != "")
        return notify_fail("AO怳lALkrslC\n");
  if((string)me->query_skill_mapped("unarmed") != "dragonfist")
        return notify_fail("sl藆眸tXsリioC\n");
  if(me->query_temp("dragon-kee")==1)
        return notify_fail("Awgb峇FC\n");

  temp=me->query("functions/dragon-kee/level","dragon-kee");
  skill = temp;
  siseforce=me->query_skill("siseforce",1);
  funlv=(int)me->query("functions/snow-powerup/level");
  me->add("force",-(50+skill*3));
  me->set_temp("dragon-kee",1);

  if(skill < 25)
  {
   message_vision(
"               $NB_~g臚@h\\O" + HIW + "苤" + HIR + "VCs衎l]" + HIW + "蛂" + NOR + "               u@DCsq$NFx竄XA$NOq\n",me);
         me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
         if( me->is_fighting() ) me->start_busy(3);
         if(skill < siseforce)
         function_improved("dragon-kee",random(skill*20)+100);
         return 1;
  } else if ( skill < 50 )
  {
  message_vision(
"               $NB_~g臚Gh\\O" + HIW + "苤" + HIG + "Ws衎l" + HIW + "蛂" + NOR + "               sq$N幙翡zXA$Nlpg鳦@ij@i\n",me);
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
"                $NB_~g臚Th\\O" + HIW + "苤" + HIY + "Xgs衎l[" + HIW + "蛂" + NOR + "                $Nu覺OCtA@Agsq妢|BBj捸BD|獀gXA洇A皉々s阨l\n",me);
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
"                $NB_~g怳W\\O" + HIW + "苤" + HIB + "Ys衎lZ" + HIW + "蛂" + NOR + "                $NH穸\\Oq_gK腄Auslq悁茩@$Nn\n",me);
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
  message_vision("$N" + HIC + "sl" + NOR + "}lYAFC\n" + NOR,me);
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

