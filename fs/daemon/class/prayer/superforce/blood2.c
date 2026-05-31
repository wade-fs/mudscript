#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
                                                                                
int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/blood/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/6;
  if( hurt_value > 2000) hurt_value=2000;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if(!target) return notify_fail("你找不到敵人!!!\n");
                                                                                
        if( lv1 < 70 )
           return notify_fail("你的[31m血穹蒼[0m練的不夠純熟﹐無法催運出[31m穹蒼血球[0m，須70級。\n");      
        if( me->query_skill("superforce",1) < 220 )             
           return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須220級。\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return   notify_fail("不空手怎麼將[31m穹蒼血球[0m聚於手上?\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
 if((string)ob->query("skill_type") != "unarmed")
            return   notify_fail("不空手怎麼將[31m穹蒼血球[0m聚於手上?\n");                      
        }                                                                     
        if(me->query("force")<500)                                            
            return notify_fail("你的內力不夠。\n");              
        if(me->query("kee")<180)                                      
            return notify_fail("你的氣不夠。\n");
                                                                                
        if(!me->is_fighting(target))        
        {                                                                       
            tell_object(me,"[31m穹蒼血球[0m唯在戰鬥中才能使用。\n");
            return 1;
        }                                                                       
        message_vision("\t\t$N體外[31m血紅的氣勁[0m隨意而走,\n\t\t只見$N身旁的[31m血紅色蒸氣[0m越來越濃厚!!\n\t\t$N大喝一聲,努力將氣勁聚於手掌之上, 形成了一團\n\t\t直徑寸許\的[31m血球[0m!!!\n\n",me,target);
        message_vision("$N運勁於雙掌，使勁一推,[31m穹蒼血球[0m朝敵人狂奔而去!\n",me,target);                 
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(70>random(100))
        {                                                                       
        message_vision("$n一見躲避已經無望，運起護身氣勁硬接下這團[31m血球[0m，無奈[31m血穹蒼氣勁[0m太猛，護身氣勁慘遭震碎，霎時高熱的血燄焚燒$n的全身﹐血液好似被蒸發而出!\n",me,target);
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/6);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n以全身的內力組成氣牆，與[0m血穹蒼氣勁[0m互鬥，[砰]的一聲，被震退數步，口吐鮮血。\n",me,target);                                                                            
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/10);
        target->add("force",-hurt_value/10);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[31m「穹蒼血球」[0m使出後，$N內力大量耗損、[36m心坎穴[0m驟然劇痛，$N黯然跌坐在地\n",me,target); 
     me->start_busy(1);
        if(lv1 < 150) function_improved("blood",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}                                                                               
