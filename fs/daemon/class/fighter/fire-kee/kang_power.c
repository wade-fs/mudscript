// by frequency  改自snow-powerup
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;
int perform(object me, object target)
{
  int flv,value;
  int tim;

   if(me->query("max_force") < 2000)
          return notify_fail("你的內力不夠﹐不能使用烈焰浩氣。 \n");
   if( me->query("family/family_name") != "瀧山派" )
          return notify_fail("烈焰浩氣為瀧山派內傳之技巧。\n");
   if( (string)me->query_skill_mapped("unarmed")!= "lungshan")
          return notify_fail("烈焰浩氣必須配合瀧山絕學。\n");
   if( (string)me->query_skill_mapped("parry")!= "fire-kee")
          return notify_fail("使用烈焰浩氣必須要有烈日護身勁。\n");
   if(me->query_temp("kang-power"))
          return notify_fail("你已經在用了。\n");
   flv=(int)me->query_skill("force")/5;
   if(flv>90) flv=90;
   value = (int)me->query("functions/kang_power/level");
   if ( value > 80 )
   { 
      message_vision(HIR"
                 $N全身內勁突增，將烈日護身勁提升到最後一層

"HIW"----------╣"HIY" 末 "HIM"≡ — ≡ "HIY"日 "HIM"≡ — ≡ "HIY"陽 "HIM"≡ — ≡ "HIY"炎 "HIM"≡ — ≡ "HIY"勁 "HIW"╠----------"NOR""HIR"
	             
               $N週身爆發出耀眼的光芒，體內火炎鬥氣無止境的提升！\n"NOR,me);
	me->set("force_factor",flv);
if(!me->query("fire_add_force")) { 
me->add("force",me->query("max_force"));
me->set("fire_add_force",1); } 
    } else if ( value > 60 )
    {
     message_vision(
     HIR"$N運起烈焰浩氣之最高功\力"HIG"---"HIY"烈陽蝕晴"HIG"---"HIR"全身發出幟熱的焚風。\n
         $N感覺體內的鬥氣充盈欲爆!!內力隨之增強!!!\n" NOR,me);
     me->set("force_factor",flv);
    }else if ( value > 40 )
    {
     message_vision(
     HIR"$N運起烈焰浩氣第三層之"HIG"---"HIY"赤陽掩空"HIG"---"HIR"身軀散發出陣陣逼人熱氣。\n
         $N感覺體內的炎氣流動不息!!內力隨之增強!!!\n" NOR,me);
      me->set("force_factor",flv);
    }else if ( value > 20 )
    {
     message_vision(
      HIR"$N運起烈焰浩氣第二層之"HIG"---"HIY"朝陽穿雲."HIG"---"HIR"真氣如朝陽溫暖而綿延。\n
         $N感覺體內的火勁源遠流長!!內力隨之增強!!!\n" NOR,me);
     me->set("force_factor",flv);
    }else
    {
     message_vision(
     HIR"$N運起烈焰浩氣第一層"HIG"---"HIY"初陽勃發"HIG"---"HIR"丹田暖烘烘的甚是舒暢。\n
         $N感覺全身的內勁源源不斷!!內力隨之增強!!!\n" NOR,me);
     me->set("force_factor",flv);
    }
    me->add ("force", -250);
    me->set_temp("kang-power",1);
    me->apply_condition("kang-power",1+value/10);	
  return 1;
}

