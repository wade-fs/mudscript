// sword.c

#include <ansi.h>
inherit SKILL;
int mean;
int valid_enable(string usage) { return usage=="array";} 
void sp_attack(int number);
void doing_array(object *,object );
int form_array(object leader)
{
        object *member;
        int i;
        int number;
        member = leader->query_team();
        if( sizeof(member) == 2 )
              number =2;
        else if( sizeof(member)==4)
             number=4;
        else if( sizeof(member)==8)
             number=8;
        else 
             return notify_fail("此種人數的劍陣尚在研發中\n");                          
        if( leader->query_temp("use_form",1) )
             return notify_fail("劍陣正在施展中。\n");
        for(i=0;i<sizeof(member);i++)
        if( sizeof(member) == 2 )
        {
          if( leader->query("sen",1) > 30)
            { 
              message_vision( HIG + "$N帶領眾人展開陰陽兩儀劍陣。\n" + NOR, leader);
              leader->add("sen",-20);
              doing_array(member,leader);
             }
           else
              message_vision("[1m你精神力不足以啟動劍陣\n[0m",leader);
         }
        else if( sizeof(member) == 4 )
         {
            if( leader->query("sen",1) > 40)
              { 
               message_vision( HIG + "$N帶領眾人展開四象旋磯劍陣。\n" + NOR, leader);
               leader->add("sen",-40);
               doing_array(member,leader);
              }
             else
               message_vision("[1m你精神力不足以啟動劍陣\n[0m",leader);
          }
         else if( sizeof(member)==8)
         {
            if( leader->query("sen",1) > 60)
             {
              message_vision( HIG + "$N帶領眾人展開八卦游龍劍陣。\n" + NOR, leader);
               leader->add("sen",-60);
               doing_array(member,leader);
              }
            else
               message_vision("[1m你精神力不足以啟動劍陣\n[0m",leader);
         }          
          return 1;
         
  }      

void doing_array(object *member,object leader)
{
          int i;
          leader->set_temp("use_form",1);
          for(i= 0; i< sizeof(member);i++)
          if(present(member[i]->query("id"),environment(leader)))
            {
             member[i]->set_temp("use_form",1);
             }
       leader->start_call_out( (: call_other, __FILE__, "remove_array",
           member,leader :), random(10)+leader->query_skill("sha-array",1));
}

void remove_array( object *member,object leader)
 {
    int i;
   if(leader->query_temp("use_form",1))
   {
     message_vision("[1m$N突然心神一分，陣已不成陣，必須重組。\n[0m",leader);
     for(i=0; i<sizeof(member);i ++)
       member[i]->delete_temp("use_form",1);
   }
    
  } 

  
