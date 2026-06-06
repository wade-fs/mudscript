// white1.c                                                                   

#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int age=this_player()->query("age",1);
int lv1=this_player()->query_function("white1",1);
int lv=this_player()->query_skill("superforce",1);
int hurt_value=lv1*(age/4)+lv;


int perform(object me, object target)                                           
{    
        string msg;                                                             
        object ob;                                                              
        string *name;

      if( !target ) target = offensive_target(me);                            
                                                                               
      if(query_function("white") <= 20  )                                                                
          return notify_fail("你的白風雲練的不夠純熟﹐無法催運出風雲般飄忽不定的瀟灑氣勁。\n");      
      if( me->query_skill("superforce",1) < 50 )             
          return notify_fail("你渾天寶鑑心法的火侯尚未足夠。\n");       
                                                                                
      if(!(ob=me->query_temp("weapon")))                                        
        { if(me->query_temp("secondary_weapon"))                                
                 return notify_fail("你不空手是無法使用風兮破地的！！\n");}                       
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
         if((string)ob->query("skill_type") != "unarmed")                       
                  return notify_fail("你不空手是無法使用風兮破地的!\n");                      
         }
          if(me->query("force")<150)                                            
                           return notify_fail("你的內力不夠。\n");              
                  if(me->query("kee")<100)                                      
                           return notify_fail("你的氣不夠。\n");                
                                                                                
        if(!me->is_fighting())                                                  
        {                                                                       
                tell_object(me,"風兮破地唯在戰鬥中才能使用。\n");              

                return 0;                                                       
        }                                                                       
        message_vision("\t\t$N身上的衣物被鼓脹地如同氣球一般，氣勁如同青風白雲，$N整個人埋沒在\n
                這飄忽的氣勁之中!!風聲蕭蕭!! \n\n",me,target);

        message_vision("\t\t$N左抱拳右劍指，數道強風從天上襲擊而下，風兮破地應聲而發﹗\n",me,target);                 
                                                                                
            me->add("kee",-(hurt_value/10));                                                 
            me->add("force",-(hurt_value/2));
        if(random(me->query_skill("superforce")+20)>random(target->query_skill("dodge")))                                                                          
        {                                                                       
                message_vision("\t\t$n的眼睛被強風刮的張不開來，九天之氣只能照單全收，鮮血處處，傷痕累累！﹗\n",me,target);                                                                   
                message_vision( NOR,me);                                        
                target->receive_damage("kee",hurt_value);
                COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
      {                                                                         
                message_vision("$n竭力閃躲，雖避開了風兮破地強風的攻擊，不過卻暫時無法恢復視力。\n",me,target);
                message_vision( NOR,me);                                        
                target->start_busy(3);
                COMBAT_D->report_status(target);                                
       }                                                                        
        message_vision("「風兮破地」使出後，$N蓄勢待發，風雲之內勁綿綿不絕",me,target); 
        me->start_busy(1);                                                      
        function_improved("white1",random(me->query("force")/25));          
        message_vision( NOR,me);                                                
        return 1;                                                               
  }                                                                             
                                                                             
