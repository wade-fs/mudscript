//poison-evil.c
//毒蠱蠶心術 by Guetenr /2003/5/

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;

int perform(object me, object target)
{
  int funlv,qpoi,adup;
  int mykee,mygin,mysen;
  mykee = me->query("sen")/2;
  mygin = me->query("gin")/2;
  mysen = me->query("sen")/2;
  qpoi  = (int)me->query("poison");
  funlv=(int)me->query("functions/evil-poison/level");

  if(me->query("force") < 500+(int)query_function("evil-poison")*5)
        return notify_fail("您沒有深厚的內力，怎麼可以蠱己自殘呢??\n");
  if ( me->query("class") !="poisoner" )
        return notify_fail("閣下並非魔教徒, 自然不知毒蠱之術, 怎會用之?\n");
  if((string)me->query_skill_mapped("poison") != "coldpoison")
        return notify_fail("毒蠱之術需要有天冰奇毒作為搭配方可使用。\n");
  if((int)me->query_skill("coldpoison",1) < 100)
        return notify_fail("閣下天冰奇毒還未到可使用此法的階段...!!\n");
  if(me->query_temp("evil-poison")==1)
        return notify_fail("您已朝自己下蠱, 莫再自蠱蠱人。\n");
  if((string)me->query_skill_mapped("force") != "poisonforce")
        return notify_fail("毒蠱之術需搭配冥蠱心法方可使用。\n");
  if((int)me->query_skill("poisonforce",1)<100)
        return notify_fail("閣下的冥蠱心法還無法使用這麼高階的降蠱術。\n");
  if(!me->query("marks/evil-poison"))
        return notify_fail("沒有高人的指導, 擅自對自己下蠱是沒有益處的!!\n");
  if(me->query("kee")<mykee || me->query("gin")<mygin || me->query("sen")<mysen)
        return notify_fail("請先將自己調整到最佳狀態, 再對自己下蠱吧!!\n");

  if(qpoi/5000 < funlv)   { adup=funlv;  } //當體內毒素/500小於fun level
  adup=qpoi/2500;
  if(adup  > 200)         { adup = 200;  } //當體內毒素/500大於fun level
  me->add("force",-1000);
  me->add("kee",-mykee);
  me->add("gin",-mygin);
  me->add("sen",-mysen);  
  me->set_temp("evil-poison",1);
  
  if(funlv < 25)
  {
   message_vision(
"               "HIG"$N食下一攤黑色血水，突然變得面目可憎˙˙˙˙˙˙\n"NOR
"           "HIR"只見一道青煙自"HIW"$N"HIR"的"HIY"靈台穴"HIR"竄出，使$N的力量源源不絕˙˙˙˙˙˙\n"
"                "HIB"【"HIM"※※※※※"HIY"真"HIB"˙"HIG"毒蠱蠶心  初毒醒"HIM"※※※※※ "HIB"】\n"NOR,me);
         me->add_temp("apply/attack",adup);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, adup, funlv, qpoi :), funlv);
         if( me->is_fighting() ) 
         {
           message_vision(RED"$N急於在戰鬥中食蠱，身體一陣蠱動，暫時無法動彈!!\n"NOR,me);
           me->start_busy(3);
         }
         return 1;

  } else if ( funlv < 50 && funlv >= 25)
  {
   message_vision(
"               "HIC"$N食下一之巨大蜘蛛，突然變得面目可憎˙˙˙˙˙˙\n"NOR
"          "HIR"只見一道青煙自"HIW"$N"HIR"的"HIY"靈台穴"HIR"竄出，使$N的力量源源不絕˙˙˙˙˙˙\n"
"              "HIB"【"HIM"※※※※※"HIY"真"HIB"˙"HIG"毒蠱蠶心  "HIC"仲蠶牲"HIM"※※※※※"HIB"】\n"NOR,me);
         me->add_temp("apply/attack",adup);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, adup, funlv, qpoi :), funlv);
         if( me->is_fighting() ) 
         {
           message_vision(RED"$N急於在戰鬥中食蠱，身體一陣蠱動，暫時無法動彈!!\n"NOR,me);
           me->start_busy(3);
         }
         return 1;
  } else if ( funlv < 75 && funlv >= 50)
  { 
   message_vision(
"               "HIB"$N食下數隻劇毒蜈蚣，突然變得面目可憎˙˙˙˙˙˙\n"NOR
"         "HIR"只見一道青煙自"HIW"$N"HIR"的"HIY"靈台穴"HIR"竄出，使$N的力量源源不絕˙˙˙˙˙˙\n"
"                "HIB"【"HIM"※※※※※"HIY"真"HIB"˙"HIG"毒蠱蠶心  "HIY"季邪續"HIM"※※※※※"HIB"】\n"NOR,me);
         me->add_temp("apply/attack",adup);
         me->add_temp("apply/defense",adup);
         me->add_temp("apply/whip",adup);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, adup, funlv, qpoi :), funlv);
          if( me->is_fighting() ) 
         {
           message_vision(RED"$N急於在戰鬥中食蠱，身體一陣蠱動，暫時無法動彈!!\n"NOR,me);
           me->start_busy(3);
         }
         return 1;
  } else if ( funlv < 100 && funlv >= 75)
  { 
   message_vision(
"               "HBGRN"$N食下萬條紅血蠱蟲，突然變得面目可憎˙˙˙˙˙˙\n"NOR
"         "HIR"只見一道青煙自"HIW"$N"HIR"的"HIY"靈台穴"HIR"竄出，使$N的力量源源不絕˙˙˙˙˙˙\n"
"                "HIB"【"HIM"※※※※※"HIY"真"HIB"˙"HIG"毒蠱蠶心  "HIC"末釹懾"HIM"※※※※※"HIB"】\n"NOR,me);
         me->add_temp("apply/attack",adup);
         me->add_temp("apply/defense",adup);
         me->add_temp("apply/whip",adup);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, adup, funlv, qpoi :), funlv);
          if( me->is_fighting() ) 
         {
           message_vision(RED"$N急於在戰鬥中食蠱，身體一陣蠱動，暫時無法動彈!!\n"NOR,me);
           me->start_busy(3);
         }
         return 1;
}  else if ( funlv >= 100 )
  {
   message_vision(
"           "HIC"$N食下蜈蚣，蜘蛛及數隻毒蛇，大吼大叫，萬蠱蠶心術最及至˙˙˙˙˙˙\n"NOR
"          "HIR"只見一道青煙自"HIW"$N"HIR"的"HIY"靈台穴"HIR"竄出，使$N的力量源源不絕˙˙˙˙˙˙\n"
"           "HIB"【"HIM"※※※※※"HIY"真"HIB"˙"HIG"毒蠱蠶心  "HIR"萬蠱蠶其身而不死  終蠱破"HIM"※※※※※"HIB"】\n"NOR,me);
         me->add_temp("apply/attack",adup);
         me->add_temp("apply/defense",adup);
         me->add_temp("apply/whip",adup);
         me->add_temp("apply/dodge",adup);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, adup, funlv, qpoi :), funlv);
         if( me->is_fighting() ) 
         {
           message_vision(RED"$N急於在戰鬥中食蠱，身體一陣蠱動，暫時無法動彈!!\n"NOR,me);
           me->start_busy(3);
         }
         return 1;
  }
 } 
 
 void remove_effect(object me, int adup,int funlv,int qpoi)
 { 
  me->delete_temp("evil-poison");
  message_vision(BLU"$N"HIR"毒蠱蠶心"BLU"的效果消失了。\n"NOR,me);
   if(funlv<100) function_improved("evil-poison",funlv*2+random(300));
  if(funlv<25)
  {
    me->add_temp("apply/attack",-adup);
  } 
  else if(funlv<50)
  {
    me->add_temp("apply/attack",-adup);
  } 
  else if(funlv<75)
  {
    me->add_temp("apply/attack",-adup);
    me->add_temp("apply/defense",-adup);
    me->add_temp("apply/whip",-adup);
  } 
   else if(funlv<100)
  {
    me->add_temp("apply/attack",-adup);
    me->add_temp("apply/defense",-adup);
    me->add_temp("apply/whip",-adup);
    me->set("poison",qpoi);
  } 
  else
  {
    message_vision(HIW"蠱毒的毒素還殘留餘$N的身體中，毒素並無損失太多。\n"NOR,me);
    me->add_temp("apply/attack",-adup);
    me->add_temp("apply/defense",-adup);
    me->add_temp("apply/whip",-adup);
    me->add_temp("apply/dodge",-adup);
    me->set("poison",qpoi);
  }
 }


