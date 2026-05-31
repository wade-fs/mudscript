#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
                                                                                
int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/blood/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/8;
    if( hurt_value > 1000) hurt_value=1000;
                                                                                
        if( !target ) target = offensive_target(me);                            
                                                                                
        if( lv1 < 35  )
            return notify_fail("你的[31m血穹蒼[0m練的不夠純熟﹐無法催運出[31m穹蒼氣勁[0m，須35級。\n");      
        if( me->query_skill("superforce",1) < 200 )             
            return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須200級。\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return   notify_fail("必需放棄身上的武器才能將[31m穹蒼氣勁[0m化為[31m血海無涯[0m!!\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
 if((string)ob->query("skill_type") != "unarmed")
            return   notify_fail("必需空手才能將[31m穹蒼氣勁[0m聚於雙掌之上!!\n");                      
        }                                                                     
        if(me->query("force")<500)                                            
            return notify_fail("你的內力不夠。\n");              
        if(me->query("kee")<180)                                      
            return notify_fail("你的氣不夠。\n");                
                                                                                
        if(!me->is_fighting(target))      
        {                                                                       
            tell_object(me,"[31m血海無涯[0m唯在戰鬥中才能使用。\n");
            return 1;
        }                                                                       
        message_vision("\t只見$N身旁的[31m血紅色蒸氣[0m越來越濃厚!!\n\t之後$N大喝一聲, [31m穹蒼內勁[0m豁然聚於雙掌之上!!\n\n",me,target);
        message_vision("$N雙掌一連發出數招[31m「血海無涯」[0m, 將敵人的全身周圍佈滿了[31m穹蒼氣勁[0m﹗\n",me,target);                 
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(70>random(100))
        {                                                                       
        message_vision("$n將全身周圍守的密不透風，企圖接下這一擊，無奈[31m穹蒼氣勁[0m似有還無，仍被拍中數掌，霎時高熱的血燄竄流$n的全身！﹗\n",me,target);                                                                   
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/5);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n以全身的內力與[31m血穹蒼氣勁[0m互鬥，”澎””砰”之聲不絕於耳，交手過後$N被震的受了內傷。\n",me,target);
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/10);
        target->add("force",-hurt_value/12);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[31m「血海無涯」[0m使出後，$N內力大量耗損、經脈不順，$N立刻盤坐在地運息調理\n",me,target); 
     me->start_busy(1);
        if(lv1 < 150) function_improved("blood",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}                                                                               
