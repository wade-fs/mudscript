// 用於 mk-blade 的狂暴 condition by swy
#include <ansi.h>
inherit F_FUNCTION;
int update_condition(object me, int duration)
{
if(duration==0) {
object wname=me->query_temp("secondary_weapon");
int fun = me->query("functions/powerup/level");
        if(me) {
      if(me->query_temp("powerup")) {
        me->delete_temp("powerup");
        me->add_temp("apply/dodge",20);
        me->add_temp("apply/move",20);
        me->add_temp("apply/parry",20);
        me->add_temp("apply/attack",-((fun*2)+30));
       if(wname) wname->delete("nodrop");
      }
      if(me->query("family/family_name") == "金刀門")
      {
      	message_vision(HIW"$N覺得聚集於刀上的落葉漸漸消散了。\n"NOR,me);
      }else{
           message_vision(HIW"$N覺得刀的血氣消失了。\n"NOR,me);
        }
        if(fun<100) { function_improved("powerup",random(700)); }
        }
return 0;
}
if(me->query("family/family_name") == "金刀門")
{
tell_object(me ,HIW"你『"HIY"殺意無限"HIW"』，突然很想痛快的斬殺敵人。\n"NOR);
message("vision",HIC+me->name()+"『"HIY"殺意無限"HIC"』，就快要喪失理性了。\n"NOR,environment(me),me);
me->apply_condition("mkpowerup",duration-1);
}else{
     tell_object(me ,HIW"你『"HIY"嗜血狂暴"HIW"』，突然很想痛快的砍殺敵人。\n"NOR);
     message("vision",HIC+me->name()+"『"HIY"嗜血狂暴"HIC"』，就快要喪失理性了。\n"NOR,environment(me),me);
     me->apply_condition("mkpowerup",duration-1);
     }

return 1;
}

