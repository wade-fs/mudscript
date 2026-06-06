#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/black/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/18;
    if( hurt_value > 600) hurt_value=600;
                                                                                
        if( !target ) target = offensive_target(me);                            
                                                                                
        if(lv1<30)
  return notify_fail("你的玄混沌練的不夠純熟﹐須要玄混沌 30 級。\n");
        if( me->query_skill("superforce",1) < 80 )             
            return notify_fail("你渾天寶鑑心法的火侯尚未到家，須要80級。\n");                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("你不空手是無法使用混沌天爆拳的！！\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("你不空手是無法使用混沌天爆拳的!\n");                      
        }
        if(me->query("force")<200)                                            
            return notify_fail("你的內力不夠。\n");              
        if(me->query("kee")<140)                                      
            return notify_fail("你的氣不夠。\n");                
                                                                                
        if(!me->is_fighting(target))
        {                                                                       
            tell_object(me,"混沌天爆拳唯在戰鬥中才能使用。\n");
            return 1;
        }                                                                       
        message_vision("\t$N體內的真氣有如盤古開天地一般，真氣亂竄，\n\t$N依照渾天寶鑑所記載的練功\口訣將此一氣勁融入本身的內力修為之中!!\n\t內功\瞬時暴增了數十倍!!\n",me,target);
        message_vision("$N內勁狂吐﹐雙拳漫佈混沌氣勁，一招混沌天爆拳瞬時向四方炸射開來 ﹗\n",me,target);
                                                                                
        me->add("kee",-hurt_value/10);
        me->add("force",-hurt_value);
        if(80 > random(100))
        {                                                                       
        message_vision("$n被你的混沌天爆拳砸中後，$n全身的經脈被混沌內勁所傷，拳勁透身而出！﹗\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/5);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n身形急轉，盡鼓全身氣勁，化解了混沌天爆拳的衝擊力 .。\n",me,target);
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/15);
        target->add("force",-hurt_value/20);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("「混沌天爆拳」使出後，$N立刻翻身向後一躍，伺機而動",me,target); 
        me->start_busy(1);
        if(lv1 < 100) function_improved("black",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
