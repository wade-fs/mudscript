#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
int skill;
int perform(object me, object target)                                           
{                                                                               
    object ob;
                                                                                
skill=me->query("functions/bluesea/level");
        if( !target ) target = offensive_target(me);                            
                                                                                
        if(skill < 30  )
            return notify_fail("你的[34m靛滄海[0m練的不夠純熟﹐無法催運出[34m滔天勢[0m，須要30級。\n");      
        if( me->query_skill("superforce",1) < 110 )             
            return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須要110級。\n");
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("你不空手是無法使用[34m滔天勢[0m的！！\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("你不空手是無法使用[34m滔天勢[0m的!\n");
        }

        if(me->query("force")<300)
            return notify_fail("你的內力不夠。\n");
        if(me->query("kee")<140)
            return notify_fail("你的氣不夠。\n");
                                                                                
        if(!me->is_fighting(target))    
        {                                                                       
            tell_object(me,"[34m滔天勢[0m唯在戰鬥中才能使用。\n");
            return 1;
        }
        if(target->is_busy())
        return notify_fail("敵人 busy 中，快攻擊吧。\n");     

        message_vision("$N周遭澎湃的氣勁如急流一般地流竄，$N依照渾天寶鑑所記載的練功\口訣,將此一氣勁全數地收納起來 !!\n\n",me,target);
        message_vision("$N將這股氣勁射出﹐有如[34m浪潮滔天的氣勁[0m往敵人下方洶湧衝突而上 ﹗\n",me,target);                 
                                                                                
        me->add("force",-skill*2);

if(80>random(100))
        {
                message_vision("$n被你[34m滔天勢[0m的內勁給拋上了天空，整個人失去了重心！﹗\n",me,target);                                                                   
                message_vision( NOR,me);                                        
                target->start_busy(2);
                COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {
                message_vision("$n忙使出千斤墜，將身形穩住，化解了[34m滔天勢[0m拋捲的氣勁 .。\n",me,target);                                                                            
                message_vision( NOR,me);                                        
                COMBAT_D->report_status(target);                                
        }
        message_vision("[34m「滔天勢」[0m使出後，$N急忙呼息調氣，重組戰鬥力",me,target); 
        me->start_busy(1);
        if(skill < 100) function_improved("bluesea",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
