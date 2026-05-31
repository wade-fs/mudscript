inherit SKILL;
#include <ansi.h>
#include <array.h>
int mean;
int valid_enable(string usage) { return usage=="array"; }
void doing_array(object *member,object leader);
int form_array(object leader)
{
        object *member;
        int i,bandit=0,mean=0;
        int enable_array=0;
        int number;
        member = leader->query_team();
        if( sizeof(member) == 2)
             number = 2;
        else if( sizeof(member) == 3)
             number = 3;
        else if( sizeof(member) == 4)
             number = 4;
        else if (sizeof(member) == 5)
             number = 5;
        else
             return notify_fail("這種混戰方法還沒有人研究出來啦 !\n");
        if( leader->query_temp("use_form",1) )
             return notify_fail("你們正在打混戰。\n");
        for(i=0;i<sizeof(member);i++)
        if ( sizeof(member) == 2)
        {
if( leader->query("sen",1) > 30 && leader->query("bellicosity",1) > 50)
            {
              message_vision("[1;32m$N大喝一聲 ,施出了惡人邪陣中的[1;33m狼狽為奸 ,\n[1;32m你和同伴瞬間化成兩道黑影向對手衝去。[0m\n",leader);
              leader->add("sen",-20);
              doing_array(member,leader);
             }
           else
              message_vision("你精神力不足以打混戰\n",leader);
         }

        else if( sizeof(member) == 3)
         {
if( leader->query("sen",1) > 45 && leader->query("bellicosity",1) > 100)
              {
               message_vision("[1;32m$N指示眾人左右狂竄，施展惡人邪陣中的[1;34m神出鬼沒 ,\n[1;32m瞬間將敵人包圍住。\n[0m\n",leader);
               leader->add("sen",-35);
               doing_array(member,leader);
              }
             else
               message_vision("你精神力不足以打混戰\n",leader);
          }

        else if( sizeof(member) == 4)
         {
if( leader->query("sen",1) > 50 && leader->query("bellicosity",1)> 150)
              {
               message_vision("[1;32m$N帶領眾人施展惡人邪陣中的[1;35m龍蛇雜處\n[1;32m在一瞬間便混淆敵人視線。[0m\n",leader);
               leader->add("sen",-40);
               doing_array(member,leader);
              }
             else
               message_vision("你精神力不足以打混戰\n",leader);
          }
        else if (sizeof(member) == 5)
         {
if( leader->query("sen",1) > 70 && leader->query("bellicosity",1)> 200)
             {
              message_vision("[1;32m$N帶領眾人施出惡人邪陣中的[1;31m百鬼夜行 ,\n[1;32m忽然風雲變色，風沙竄飛。[0m\n",leader);
               leader->add("sen",-60);
               doing_array(member,leader);
              }
            else
               message_vision("你精神力不足以打混戰\n",leader);
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
           member,leader :), 1+leader->query_skill("bad-array",1)/2);
}

void remove_array( object *member,object leader)
 {
    int i;
   if(leader->query_temp("use_form",1))
   {
     message_vision("[1;37m$N突然心神一分，錯失出手良機，必須重新來過。[0m\n",leader);
     for(i=0; i<sizeof(member);i ++)
       member[i]->delete_temp("use_form",1);
   }
  }
