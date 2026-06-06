#include <combat.h>
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
     int funlvl=me->query_function("snow-powerup");    
  if( !living(me) )
   {
     message("vision",me->name() + "身旁凌霜氣勁的寒勁漸漸的消散了....",
     environment(me), me);
   }
  else if( duration > 9)
   {
     tell_object(me,HIW + "你感到週身大穴無一不充滿著勁力，寒霜般的氣勁有如江河決提！\n" + NOR);
     message("vision", me->name() + 
HIW + "全身逼發出一股攝人的寒氣，彷彿要將四周的空氣凝結！\n" + NOR,
     environment(me), me);
     if((int)me->query("force")<2*(int)me->query("max_force"))
           me->add("force",100);
    }
  else if( duration > 7 )
     {
      tell_object(me, HIC + "你感覺四肢百賅被凌霜奇勁的寒勁充塞著，全身上下暢快無比！\n" + NOR);
      message("vision", me->name() + HIC + "的全身上下被一股淡藍色的氣勁包圍著！\n" + NOR,
      environment(me), me);
       if((int)me->query("force")<2*(int)me->query("max_force"))
           me->add("force",50);
      }
    else if( duration > 5 )
     {
      tell_object(me, HIC + "你的護身寒氣的氣勁不斷地注入雙手中，感覺似乎充滿了勁道！\n" + NOR);
      message("vision", me->name() + HIC + "的雙手隱隱散發出逼人的寒氣！\n" + NOR,
      environment(me), me);
       if((int)me->query("force")<2*(int)me->query("max_force"))
           me->add("force",50);
      }
     else if( duration > 3)
     {
         tell_object(me,CYN + "你感到凌霜奇勁慢慢的由雙手延流至氣海....\n" + NOR);
         message("vision",me->name() + CYN + "手上的奇勁慢慢的擴散至全身...\n" + NOR,	
         environment(me),me);
         if((int)me->query("force")<2*(int)me->query("max_force"))
         me->add("force",20);	
     }
      else if( duration > 1)
      {
       tell_object(me, CYN + "你感到寒氣在手上流轉，運勁通暢無比！\n" + NOR);
       message("vision", me->name() + CYN + "的護身寒氣漸漸地凝聚在雙手... \n" + NOR,
       environment(me), me);
       if((int)me->query("force")<2*(int)me->query("max_force"))
           me->add("force",10);
      }
  if( duration < 1 )
  {      
      object weapon=me->query_temp ("weapon");
      me->set("force_factor", 10); 
      tell_object(me,HIY + "你運的凌霜奇勁開始崩散了。\n" + NOR);
      me->delete("powerup_flag");
      return 0;
   }
        if(me->query_skill_mapped("unarmed")!= "snow-martial") 
     {
          write("由於你使用別派武學，導致體內的凌霜奇勁不受控制致使身受內傷\n");
//為避免不夠氣時會死亡故加入此判斷。     
          if(me->query("kee")>200)  me->add("kee",-200);
          me->apply_condition("cold",random(25) +((int)me->query_skill("snowforce", 1)/5));
          me->apply_condition("star-stial",random(30));
          duration=1;
     }
   if(me->query_skill_mapped("parry")!= "snow-kee") 
   {
     write("由於你沒使用護身氣勁，導致體內的凌霜奇勁不受控制致使身受內傷\n");
     if(me->query("kee")>300)  me->add("kee",-300);
     me->apply_condition("cold",random(30) +((int)me->query_skill("snowforce", 1)/5));
     me->apply_condition("star-stial",random(10));
     duration=1;
   }
   me->apply_condition("powerup",duration-1);
   me->add("force_factor",1);
  if(funlvl < 100)
  function_improved("snow-powerup",20*random(duration)+
  random(me->query("max_force")/20));
  return 1;
}

