// sha-array by Roger 5/26/98

#include <ansi.h>
#include <array.h>
inherit SKILL;
void doing_array(object *,object);
int valid_enable(string usage) { return usage=="array";} 
int mean;
int form_array(object leader)
{
  object *member;
    int i,j,sworder=0,mean=0;
    int enable_array=0;
    int number;
    member = leader->query_team();
    i = sizeof(member) ;
       
        //  if(sworder!=number) return notify_fail("隊員要全是仙劍派弟子才能組仙劍劍陣。\n");
        for(j=0;j<i;j++){
 //         tell_object(find_player("whatup"),sprintf("%O:%O:%O",environment(member[j]),environment(leader),member[j]));
          if(environment(member[j]) != environment(leader)) {
            continue;
          }
          if(member[j]->query("family/family_name")=="仙劍派"){
            sworder=sworder+1;
            number++;
          }

          mean=mean+member[j]->query_skill("sha-array",1);
        }
  
      switch(number)
      {
        case 2:
        case 3:
        case 4:
        case 8:
          break;
        default:
          write("你的隊伍裡只有"+chinese_number(number)+"人，而此種人數的劍陣尚在研發中\n");

      return notify_fail("你的隊伍裡只有"+chinese_number(number)+"人，而此種人數的劍陣尚在研發中\n");
      }
 
    mean=mean/number;
    if(sworder!=sizeof(member)) 
    {
      leader->set_temp("no_power",1);
      leader->apply_condition("no_power",2);
      return notify_fail("隊員要全是仙劍派弟子才能組仙劍劍陣。\n");
      return 0;
    }
  
    if( leader->query_temp("use_form",1) )
      return notify_fail("劍陣正在施展中。\n");
        
        if(number < 1)
        {
          message_vision("你使用仙劍劍陣的bug 被appo 詛咒...\n",leader);
          leader->set_function("sha-kee",0);
          leader->set_function("swordkee",0);
          log_file("sword/array-bug",sprintf("%s(%s) 使用array bug 於 on %s\n",leader->query("name"),leader->query("id"),ctime(time()) ));
        }
        else if(number == 2)
        {
          if(leader->query_skill("sha-array",1) >= 30){
            if( leader->query("sen",1) >= 40)
            { 
              message_vision( HIG + "$N帶領眾人展開陰陽兩儀劍陣。\n" + NOR, leader);
                leader->add("sen",-40);
                leader->set_temp("form_mean",mean);
                leader->set_temp("form_number",number);
                doing_array(member,leader);
            }
            else
              message_vision("[1m你精神力不足以啟動劍陣\n[0m",leader);
          }
          else
            message_vision("[1m你仙劍劍陣不夠精熟，無法啟動兩儀劍陣\n[0m",leader);
              
        }
  
        else if( number == 3 )
        {
          if(leader->query_skill("sha-array",1) >= 50){
            if( leader->query("sen",1) >= 60)
            { 
              message_vision( HIG + "$N帶領眾人展開三才天地人劍陣。\n" + NOR, leader);
                leader->add("sen",-60);
                leader->set_temp("form_mean",mean);
                leader->set_temp("form_number",number);
                doing_array(member,leader);
            }
            else
              message_vision("[1m你精神力不足以啟動劍陣\n[0m",leader);
          }
          else
            message_vision("[1m你仙劍劍陣不夠精熟，無法啟動三才劍陣\n[0m",leader);
        }
  
        else if( number == 4 )
        {
          if(leader->query_skill("sha-array",1) >= 60){
            if( leader->query("sen",1) >= 100)
            { 
              message_vision( HIG + "$N帶領眾人展開四象旋磯劍陣。\n" + NOR, leader);
                leader->add("sen",-100);
                leader->set_temp("form_mean",mean);
                leader->set_temp("form_number",number);
                doing_array(member,leader);
            }
            else
              message_vision("[1m你精神力不足以啟動劍陣\n[0m",leader);
          }
          else
            message_vision("[1m你仙劍劍陣不夠精熟，無法啟動四象劍陣\n[0m",leader);
              
        }
        else if( number ==8)
        {
          if(leader->query_skill("sha-array",1) >= 80){
            if( leader->query("sen",1) >= 200)
            {
              message_vision( HIG + "$N帶領眾人展開八卦游龍劍陣。\n" + NOR, leader);
                leader->add("sen",-200);
                leader->set_temp("form_mean",mean);
                leader->set_temp("form_number",number);
                doing_array(member,leader);
            }
            else
              message_vision("[1m你精神力不足以啟動劍陣\n[0m",leader);
          }
          else
            message_vision("[1m你仙劍劍陣不夠精熟，無法啟動八卦遊龍劍陣\n[0m",leader);
        }          
  return 1;
    
}      

void doing_array(object *member,object leader)
{
  int i,mean,number;
    
    mean=leader->query_temp("form_mean",1);
    number=leader->query_temp("form_number",1);
    for(i= 0; i< sizeof(member);i++)
      if(present(member[i]->query("id"),environment(leader)))
      {
        member[i]->set_temp("use_form",1);
          member[i]->add_array_armor;
      }
  leader->start_call_out( (: call_other, __FILE__, "remove_array",
        member,leader,mean,number:), random(10)+leader->query_skill("sha-array",1));
}

void remove_array( object *member,object leader,int mean,int number)
{
  int i;
    if(leader->query_temp("use_form",1))
    {
      message_vision("[1m$N突然心神一分，陣已不成陣，必須重組。\n[0m",leader);
        for(i=0; i<sizeof(member);i ++){
          if(!member[i]) continue;
          member[i]->delete_temp("use_form",1);
            member[i]->sub_array_armor;
        }
    }
  
} 


