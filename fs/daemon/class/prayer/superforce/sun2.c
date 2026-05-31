#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/goldsun/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/10;
	if(me->query("class")!="prayer")
          return notify_fail("你的職業無法使用此技能。\n");
    if( hurt_value > 900) hurt_value=900;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if(!target) return notify_fail("你找不到敵人!!\n");
                                                                                
        if( lv1 < 60  )
            return notify_fail("你的[33m金晨曦[0m練的不夠純熟﹐無法催運出[33m金晨曦[0m的霸氣，須60級。\n");
        if( me->query_skill("superforce",1) < 170 )             
            return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須170級。\n");
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("你不空手是無法使用[33m雙星趕月[0m的！！\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("你不空手是無法使用[33m雙星趕月[0m的!\n");
        }
        if(me->query("force")<400)                                            
            return notify_fail("你的內力不夠。\n");
        if(me->query("kee")<140)                                      
            return notify_fail("你的氣不夠。\n");
                                                                                
        if(!me->is_fighting(target))        
        {                                                                       
            tell_object(me,"[33m雙星趕月[0m唯在戰鬥中才能使用。\n");
            return 1;
        }                                                                       
        message_vision("\t$N全身[33m金光閃閃[0m，光華奪目，[33m金色的真氣[0m在身旁旋繞，\n\t$N整個人飛昇在數丈高的半空中!!光芒四射宛若驕陽!!\n\n",me,target);
        message_vision("$N雙拳一握，兩團[33m耀眼金光[0m匯聚成球，呼嘯而出！此招有如雙龍出海，金光刺目，直逼敵人上下兩路﹗\n",me,target);
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(80>random(100))
        {                                                                       
        message_vision("$n竭力抵擋，仍被這兩團氣勁轟中，頓時身首無存，屍骸遍地！﹗\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/4);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n竭力閃避，避開了[33m雙星趕月[0m正面的攻擊，兩團[33m金光[0m轟向地面將地面炸了開來。\n",me,target);
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/12);
        target->add("force",-hurt_value/14);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[33m「雙星趕月」[0m使出後，$N面露笑容，似乎很滿意此招的攻擊能力",me,target); 
        me->start_busy(1);
        if(lv1 < 150) function_improved("goldsun",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
