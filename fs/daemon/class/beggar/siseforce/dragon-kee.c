//dragon-kee.c
//­°Às«l by Dico

#include <ansi.h>
 inherit F_FUNCTION;
 inherit SSERVER;
 inherit F_CLEAN_UP;

 int perform(object me, object target)
 {
  int skill,funlv,siseforce,temp;

  if(me->query("force")<50+(int)query_function("dragon-kee")*5)
        return notify_fail("§Aªº¤º¤O¤£°÷¡AµLªk¹B°_­°Às«l®ð¡C\n");
  if(me->query("family/family_name") != "¤¢À°")
        return notify_fail("§A¤£¬O¤¢À°§Ì¤l¡AµLªk¾r¶¿­°Às«l®ð¡C\n");
  if((string)me->query_skill_mapped("unarmed") != "dragonfist")
        return notify_fail("­°Às«l®ð¥²¶·°t¦X­°Àsµ´¾Ç¤è¥iµo´§¡C\n");
  if(me->query_temp("dragon-kee")==1)
        return notify_fail("§A¤w¸g¦b¥Î¤F¡C\n");

  temp=me->query("functions/dragon-kee/level","dragon-kee");
  skill = temp;
  siseforce=me->query_skill("siseforce",1);
  funlv=(int)me->query("functions/snow-powerup/level");
  me->add("force",-(50+skill*3));
  me->set_temp("dragon-kee",1);

  if(skill < 25)
  {
   message_vision(
"               $N¹B°_¬~Åè¸g²Ä¤@¼h¥\\¤O"HIW"¡Ð¡×"HIR"ŸV¹C¡ÐÀs¡Ð«lŸ]"HIW"¡×¡Ð"NOR
"               ¥u¨£¤@¹D¹CÀs¤§®ð±q$NªºÆF¥x¥ÞÂ«¥X¡A¨Ï$Nªº¤O¶q·½·½¤£µ´\n",me);
         me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
         if( me->is_fighting() ) me->start_busy(3);
         if(skill < siseforce)
         function_improved("dragon-kee",random(skill*20)+100);
         return 1;
  } else if ( skill < 50 )
  {
  message_vision(
"               $N¹B°_¬~Åè¸g²Ä¤G¼h¥\\¤O"HIW"¡Ð¡×"HIG"ŸW«ã¡ÐÀs¡Ð«lŸ\\"HIW"¡×¡Ð"NOR
"               «ãÀs¤§®ð±q$Nªº«á³»¡B­·¦À¨â¥ÞÃz¥X¡A¨Ï$Nªº¤º«l¦³¦p¨gÀÜ¯ë¤@ªi±j¦ü¤@ªi\n",me);
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
"                $N¹B°_¬~Åè¸g²Ä¤T¼h¥\\¤O"HIW"¡Ð¡×"HIY"ŸX¨g¡ÐÀs¡Ð«lŸ["HIW"¡×¡Ð"NOR
"                $N¥uÄ±¥þ¨­¤º¤O¹C¨«¨³³t¡A¤@Àþ¶¡¡A¨gÀs¤§®ð±q¦Ê·|¡B­·©²¡B¤j´Õ¡B¯«¹D¥|¥Þ®g¥X¡A¨Ï§A¾Ö¦³±Æ¤s­Ë®üªº«l®ð\n",me);
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
"                $N¹B°_¬~Åè¸g³Ì¤W­¼¥\\¤O"HIW"¡Ð¡×"HIB"ŸY­°¡ÐÀs¡Ð«lŸZ"HIW"¡×¡Ð"NOR
"                $N¥H²¦¥Í¥\\¤O¥´³q¥þ¨­ªº©_¸g¤K¯ß¡A¥u¨£­°Às®ð«l±q¤Ñ¦Ó­°Å@¦í$N¥þ¨­­n¥Þ\n",me);
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
  message_vision("$Nªº"HIC"­°Às«l"NOR"¶}©l±Y¼ìµA´²¤F¡C\n"NOR,me);
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

