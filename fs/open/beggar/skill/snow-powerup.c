#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;
int perform(object me, object target)
{
  int skil,value,i;
  int tim;

   if(me->query("force")<50+(int)query_function("snow-powerup")*7)
          return notify_fail("你的內力不夠﹐不能使用凌霜奇勁訣。 \n");
   if( me->query("family/family_name") != "雪蒼派" )
          return notify_fail("凌霜奇勁訣為雪蒼派內傳之技巧。\n");
   if( (string)me->query_skill_mapped("unarmed")!= "snow-martial")
          return notify_fail("凌霜奇勁訣必須配合雪蒼武學。\n");
   if( (string)me->query_skill_mapped("parry")!= "snow-kee")
          return notify_fail("使用凌霜奇勁訣必須要有寒勁護體。\n");
   if(me->query("powerup_flag"))
          return notify_fail("你已經在用了。\n");
   skil = (int)me->query("functions/snow-powerup/level")/3+
(int)me->query_skill("snowforce",1)/15;
   if( skil > 20 ) skil = 20;
   value = (int)me->query("functions/snow-powerup/level");
   if ( value > 99 )
   { 
      message_vision(HIC + "
		$N以全身寒氣，逼使出凌霜奇勁之「無盡式」
	             " + NOR + "" + BWHT + "" + HIW + "●無＝－＝垠＝－＝霜＝－＝雪●" + NOR + "" + HIC + "
      	    $N周身包圍著寒氣，勁力似乎如大河決提般不吐不快！\n" + NOR,me);
	me->add("force_factor",35+me->query("max_force")/1000);
      me->add("force",me->query("max_force"));
    } else if ( value > 49 )
    {
     message_vision(
     HIW + "$N運起凌霜奇勁之最高功\力---" + HIC + "化霜成勁" + HIW + "---使你的掌上凝結一層寒霜。\n
         $N感覺手上的寒勁源源不斷!!內力隨之增強!!!\n" + NOR,me);
     me->add("force_factor",30);
    }else if ( value > 39 )
    {
     message_vision(
     HIW + "$N運起凌霜奇勁第三層功\力---" + HIC + "化雪成勁" + HIW + "---使你的掌上發出絲絲的雪氣。\n
         $N感覺手上的雪氣源源不斷!!內力隨之增強!!!\n" + NOR,me);
      me->add("force_factor",25);
    }else if ( value > 29 )
    {
     message_vision(
      HIW + "$N運起凌霜奇勁之第二層功\力---" + HIC + "化水成勁" + HIW + "---將你手中的水氣凝結成冰魄。\n
         $N感覺手上的水勁源源不斷!!內力隨之增強!!!\n" + NOR,me);
     me->add("force_factor",20);
    }else
    {
     message_vision(
     HIW + "$N運起凌霜奇勁之第一層功\力---" + HIC + "化氣成勁" + HIW + "---將丹田的內力凝結成力。\n
         $N感覺全身的內勁源源不斷!!內力隨之增強!!!\n" + NOR,me);
     me->add("force_factor",10);
    }
   me->add ("force", -(50+skil*3));
    me->set("powerup_flag",1);
    me->apply_condition("powerup",1+value/10);	
   if( me->is_fighting() ) me->start_busy(1);
  return 1;
}

