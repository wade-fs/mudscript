#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
                                                                                
int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/blood/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/4;
	if(me->query("class")!="prayer")
          return notify_fail("你的職業無法使用此技能。\n");
 if( hurt_value > 3000) hurt_value=3000;
                                                                                
        if( !target ) target = offensive_target(me);                            
      if(!target) return notify_fail("你找不到敵人!!\n");
                                                                                
        if( lv1 < 105  )
            return notify_fail("你的[31m血穹蒼[0m練的不夠純熟﹐無法使出[31m穹蒼無悔[0m，須105級。\n");      
        if( me->query_skill("superforce",1) < 250 )             
            return notify_fail("你渾天寶鑑心法的火侯尚未足夠，須250級。\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        { if(me->query_temp("secondary_weapon"))                                
            return notify_fail("使用[31m穹蒼無悔[0m是不需要武器的!!\n");}                       
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
 if((string)ob->query("skill_type") != "unarmed")
            return   notify_fail("使用[31m穹蒼無悔[0m是需要拳腳功\夫的!!\n");                      
        }                                                                     
        if(me->query("force")<500)                                            
            return notify_fail("你的內力不夠。\n");              
        if(me->query("kee")<180)                                      
            return notify_fail("你的氣不夠。\n");                
                                                                                
        if(!me->is_fighting(target))         
        {                                                                       
            tell_object(me,"[31m穹蒼無悔[0m唯在戰鬥中才能使用。\n");
            return 1;
        }                                                                       

        message_vision("\t$N蔚藍的天空開始變成血紅色, 方圓十里之內如同掉入[31m阿修羅地獄[0m般!!\n\t$N近似瘋狂地唸著渾天寶鑑的練功\口訣, 滿天的[31m血紅氣勁[0m越來越濃郁!!\n\t[31m血龍捲風[0m應勁而生了!!\n\n",me,target);
        message_vision("$N吼道:是你逼我使用 [31m穹蒼無悔[0m的!!去見閻王吧!!\n\n",me,target);
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(70>random(100))
        {                                                                       
        message_vision("$n避無可避﹐霎時被高速而來的[31m血龍捲風[0m捲成一團﹐被旋風拉扯的痛楚有如撕肝裂肺﹗\n",me,target);                                                                   
        message_vision( NOR,me);                                        
  target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/2);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n運功\抵禦﹐雖然依舊被[31m血龍捲風[0m捲身而入﹐可是$n的內功\修為不俗, 所以仍然是撿回一條小命!!。\n",me,target);  
        target->receive_damage("kee",hurt_value/10);
        target->add("force",-hurt_value/10);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[31m「穹蒼無悔」[0m使出後，$N大耗內力、[36m天闕穴[0m驟然疼痛，頹然跪倒在地\n",me,target); 
   me->start_busy(1);
        if(lv1 < 150) function_improved("blood",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}                                                                               

