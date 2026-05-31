inherit SSERVER;
#include <ansi.h>
int perform(object me, object target)
{
       string msg;
       int ski_value, kee_lv, bellpower, max_lv;
       ski_value= random(me->query_skill("rain-throwing",1));
       max_lv=me->query_skill("rain-throwing",1);
       bellpower= me->query("bellicosity")/5;
// func_rules By Swy
       if(bellpower > 1000) bellpower=1000;
       kee_lv=me->query_skill("rain-throwing",1)+bellpower;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("霸雨式只能對戰鬥中的對手使用。\n");

        if( me->query_skill_mapped("throwing")!="rain-throwing" )
         return notify_fail("你沒有裝備霸雨螫魂。 \n");
   if( me->query_skill("rain-throwing",1)<20 )
         return notify_fail("你的霸雨螫魂技巧不足。 \n");
   if( me->query_skill("throwing",1)<10 )
         return notify_fail("你的暗器準度不好。 \n");
   if(me->query("force")<60)
         return notify_fail("你的內力不夠。\n");
   if( target->is_busy() )
      return notify_fail(target->name() + "為了躲避你雨般地暗器,目前正自顧不暇!\n");

 msg ="          只見$N身上發出一股強大的殺氣,全身發出青淡的光芒。\n
 $N身上青淡的光芒逐漸地延著雙臂往雙手移去,在雙手上形成兩團深綠色的光圈。\n
              $N倏地大喝一聲～霸雨式～\n\n";

     if( ski_value == random(max_lv)){
     msg += "極端殺招 『魔血氣殺』\n\n$n遭到前所未有的打擊。\n";
     target->add("kee",-250-kee_lv);
     me->add("force",-50);  }
     
    else if( ski_value < 12 ){
      msg +="$N所聚集的殺氣不夠大,對敵人毫無影響。\n";
      me->add("force",-50); }

    else if( ski_value <  40 ){
     msg += "第一招 『殺雨無修』\n\n$n被$N攻了個措手不及,受了一點小傷﹗\n";
     target->add("kee",-20-kee_lv);
     me->add("force",-50);    }
    
    else if( ski_value <  60 ){
     msg += "第二招 『氣雨興鋒』\n\n$n被打中不少,受了一些輕傷﹗\n";
     target->add("kee",-60-kee_lv);
     me->add("force",-50);    }

     else  if( ski_value < 80){
     msg += "第三招 『血雨紛飛』\n\n$n被十之八九的光彈所打中,受到嚴重的創傷。\n";
     target->add("kee",-100-kee_lv);
     me->add("force",-50);  }

    else                    {
     msg += "第四招 『魔雨狂殊』\n\n$n無法躲避,被所有的光彈擊中,受到無法估計的傷害。\n";
     target->add("kee",-150-kee_lv);
     me->add("force",-50);  }
     message_vision(msg, me, target);
     me->start_busy(1);
        return 1;
}
