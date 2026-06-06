#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
int skill;
int perform(object me, object target)                                           
{                                                                               
    object ob;
if(!this_player()) return 0;
skill=this_player()->query("functions/bluesea/level");
        if( !target ) target = offensive_target(me);                            
                                                                                
        if(!target) return notify_fail("你找不到敵人!!\n");
        if(skill < 90  )
            return notify_fail("你的靛滄海練的不夠純熟﹐無法催運出鯨吞勢，須90級。\n");      
        if( me->query_skill("superforce",1) < 110 )             
            return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須110級。\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("你不空手是無法使用鯨吞勢的！！\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("你不空手是無法使用鯨吞勢的!\n");                      
        }
        if(me->query("force")<300)                                            
            return notify_fail("你的內力不夠。\n");              
        if(me->query("kee")<140)                                      
            return notify_fail("你的氣不夠。\n");                
                                                                                
        if(!me->is_fighting(target))          
        {                                                                       
        tell_object(me,"鯨吞勢唯在戰鬥中才能使用。\n");              
        return 1;
        }                         
        if(target->is_busy())
        return notify_fail("敵人 busy 中，快攻擊吧。\n");                                              
        message_vision("$N周遭澎湃的氣勁如海中鯨魚行進時的氣勢磅礡，$N依照渾天寶鑑所記載的練功\口訣,將此氣勁發揮的淋漓盡致 !!\n\n",me,target);
        message_vision("$N雙臂一揮﹐鯨吞勢的氣勁如同海浪一般籠罩而下 ﹗\n",me,target);                 
                                                                                
        me->add("force",-skill*4);

if(80>random(100))
        {                                                                       
                message_vision("$n被你的內勁給吞噬住，絲毫無法動彈﹗\n",me,target);                                                                   
                message_vision( NOR,me);                                        
             target->start_busy(4);
                COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
                message_vision("$n急中生智，將鯨吞勢的內勁集中在手上後，盡瀉於地 。反而使得$N失去了著力點，喪失了平衡感!!\n",me,target);
                COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("「鯨吞勢」使出後，$N急忙呼息調氣，重組戰鬥力\n",me,target); 
        me->start_busy(1);
        if(skill < 100) function_improved("bluesea",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
