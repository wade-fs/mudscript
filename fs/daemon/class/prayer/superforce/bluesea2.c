#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
int skill;
int perform(object me, object target)                                           
{                                                                               
    object ob;
skill=this_player()->query("functions/bluesea/level");
        if( !target ) target = offensive_target(me);                            
        if(!target) return notify_fail("找不到敵人!!\n");
                                                                                
        if(skill < 60  )
            return notify_fail("你的靛滄海練的不夠純熟﹐無法催運出繭困勢，須要60級。\n");      
        if( me->query_skill("superforce",1) < 110 )             
            return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須要110級。\n");
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("你不空手是無法使用繭困勢的！！\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("你不空手是無法使用繭困勢的!\n");
        }
        if(me->query("force")<200)
           return notify_fail("你的內力不夠。\n");              
        if(me->query("kee")<140)                                      
           return notify_fail("你的氣不夠。\n");                
                                                                                
        if(!me->is_fighting(target))                   
        {                                                                       
        tell_object(me,"繭困勢唯在戰鬥中才能使用。\n");              
        return 1;
        }                                                                       
        if(target->is_busy())
        return notify_fail("敵人 busy 中，快攻擊吧。\n");
        message_vision("$N周遭澎湃的氣勁如潮水般地快速奔走，$N將此一氣勁越旋越快!!\n\n",me,target);
        message_vision("忽然$N內勁一送﹐整個繭困勢的氣勁越旋越緊地向敵人席捲而下 ﹗\n",me,target);
                                                                                
        me->add("force",-skill*3);

if(80>random(100))
        {                                                                       
        message_vision("$n被你的繭困勢內勁給緊緊的困住，無法動彈！﹗\n",me,target); 
        message_vision( NOR,me);                                        
        target->start_busy(3);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n護身氣勁受到感應，股地將全身的內勁爆發出來，化解了繭困勢窒礙的氣流 。\n",me,target);                                                                            
        message_vision( NOR,me);                                        
        COMBAT_D->report_status(target);                                
        }
        message_vision("「繭困勢」使出後，$N急忙呼息調氣，重組戰鬥力",me,target); 
        me->start_busy(1);
        if(skill < 100) function_improved("bluesea",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
