#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;
                                                                
int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/black/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/16;
	if(me->query("class")!="prayer")
          return notify_fail("你的職業無法使用此技能。\n");
    if( hurt_value > 700) hurt_value=700;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if( !target ) return notify_fail("你找不到敵人!!\n");
                                                                                
        if( lv1 < 60  )
        return notify_fail("你的玄混沌練的不夠純熟﹐須要玄混沌 60 級。\n");      
        if( me->query_skill("superforce",1) < 90 )             
        return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須要90級。\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("你不空手是無法使用混沌地裂掌的！！\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("你不空手是無法使用混沌地裂掌的!\n");                      
        }
        if(me->query("force")<200)                                            
            return notify_fail("你的內力不夠。\n");              
        if(me->query("kee")<140)                                      
            return notify_fail("你的氣不夠。\n");                
                                                                                
        if(!me->is_fighting(target))                                                  
        {                                                                       
            tell_object(me,"混沌地裂掌唯在戰鬥中才能使用。\n");
            return 1;
        }                                                                       
        message_vision("\t$N體內的真氣有如盤古開天地一般，真氣亂竄，\n\t似乎就要爆體而出, 只有將此一氣勁運輸到你的雙掌間中!!\n\t只見你雙手的筋肉暴漲了數倍之多!!\n",me,target);
        message_vision("$N雙拳漫佈混沌氣勁，只覺不吐不快，強招混沌地裂掌挾著轟然之勢向敵人而去 .﹗\n",me,target);
                                                                                
        me->add("kee",-hurt_value/10);
        me->add("force",-hurt_value);
        if(80 > random(100))
        {                                                                       
        message_vision("$n的雙掌與混沌地裂掌相交較勁，卻慘遭雄渾的混沌內勁震斷雙臂，掌勁觸體後另你馬上開腸破肚！﹗\n",me,target);                                   
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/10);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n奮力向後一躍，閃避了混沌地裂掌的開山裂碑的殺傷力。\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/14);
        target->add("force",-hurt_value/18);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("「混沌地裂掌」使出後，$N立刻縱身撲進$n，繼續搶攻",me,target); 
        me->start_busy(1);
        if(lv1 < 100) function_improved("black",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
