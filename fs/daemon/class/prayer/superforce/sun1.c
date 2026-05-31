#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/goldsun/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/12;
    if( hurt_value > 800) hurt_value=800;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if( !target ) return notify_fail("你找不到敵人!!\n");
        if( lv1 < 30  )
            return notify_fail("你的[33m金晨曦[0m練的不夠純熟﹐無法催運出[33m金晨曦[0m的霸氣，須30級。\n");      
        if( me->query_skill("superforce",1) < 150 )             
            return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須150級。\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("你不空手是無法使用[33m金劍穿雲[0m的！！\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
        if((string)ob->query("skill_type") != "unarmed")                       
            return notify_fail("你不空手是無法使用[33m金劍穿雲[0m的!\n");                      
        }
        if(me->query("force")<400)                                            
            return notify_fail("你的內力不夠。\n");              
        if(me->query("kee")<140)                                      
            return notify_fail("你的氣不夠。\n");                
                                                                                
        if(!me->is_fighting(target))    
        {                                                                       
            tell_object(me,"[33m金劍穿雲[0m唯在戰鬥中才能使用。\n");
            return 1;
        }                                                                       
        message_vision("\t$N全身[33m金光閃閃[0m，光華奪目，[33m金色的真氣[0m在身旁旋繞，\n\t$N整個人飛昇在數丈高的半空中!!光芒四射宛若驕陽!! \n\n",me,target);
        message_vision("$N單手一指，一道耀眼金光激射而出，正是霸招[33m金劍穿雲[0m！此招有如飛龍撲日，豪光萬千﹗\n",me,target);                 
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(80>random(100))
        {                                                                       
        message_vision("$n竭力抵擋，仍被霸道的[33m金晨曦內勁[0m射中，頓時[33m金光爆體[0m，向四方亂射！﹗\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/4);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n竭力抵擋，雖避開了[33m金劍穿雲[0m正面的攻擊，不過右手卻還是被射穿了。\n",me,target); 
        message_vision( NOR,me);                                        
                target->receive_damage("kee",hurt_value/13);
                target->add("force",-hurt_value/16);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[33m「金劍穿雲」[0m使出後，$N面露笑容，在半空中俾睨著$n",me,target); 
        me->start_busy(1);
        if(lv1 < 150) function_improved("goldsun",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
