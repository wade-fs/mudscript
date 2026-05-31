//增加使用者的判斷 by blazakira 2011/8/28

#include <combat.h>
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
//  int funlvl=me->query("functions/snow-powerup/level");
  int funlvl=me->query("functions/kang_power/level");  //修正functions判斷錯誤 by unfinished
  int forlvl=me->query_skill("force");
  if( !me ) return 0;
  if( !living(me) )
  {
    message("vision",me->name() + HIY"身旁烈焰浩氣的火勁漸漸的消散了....\n"NOR,environment(me), me);
  }
  else if( duration > 9 )
  {
    tell_object(me,HIR"你感到週身大穴無一不充滿著勁力，烈陽般的鬥氣有如末日籠罩！\n"NOR);
    message("vision", me->name() + HIR"全身逼發出一股幟熱的鬥氣，彷彿要將四周的空氣蒸發！\n"NOR,environment(me), me);
    if((int)me->query("force")<2*(int)me->query("max_force"))
      me->add("force",100);
    if((int)me->query("force_factor") < 80 && forlvl > 500 )
      me->set("force_factor",80);
    if(funlvl < 100 && me)
      function_improved("kang_power",random(funlvl*10)+6);
  }
  else if( duration > 7 )
  {
    tell_object(me, HIR"你感覺丹田氣海被烈焰浩氣的火勁充塞著，全身上下暢快無比！\n"NOR);
    message("vision", me->name() + HIR"的全身上下被一股火紅的鬥氣包圍著！\n"NOR,environment(me), me);
    if((int)me->query("force")<2*(int)me->query("max_force"))
      me->add("force",50);
    if((int)me->query("force_factor") < 80 && forlvl > 500 )
      me->set("force_factor",80);
    if(funlvl < 100 && me)
      function_improved("kang_power",random(funlvl*10)+5);
  }
  else if( duration > 5 )
  {
    tell_object(me, HIR"你的護身鬥氣不斷地注入氣海中，感覺似乎充滿了勁道！\n"NOR);
    message("vision", me->name() + HIR"的身軀隱隱散發出逼人的火勁！\n"NOR,environment(me), me);
    if((int)me->query("force")<2*(int)me->query("max_force"))
      me->add("force",50);
    if((int)me->query("force_factor") < 80 && forlvl > 500 )
      me->set("force_factor",80);
    if(funlvl < 100 && me)
      function_improved("kang_power",random(funlvl*10)+4);
  }
  else if( duration > 3)
  {
    tell_object(me,HIR"你感到烈焰浩氣慢慢的由丹田延流至全身....\n"NOR);
    message("vision",me->name() + HIR"體內的烈焰浩氣慢慢的擴散至全身...\n"NOR,environment(me),me);
    if((int)me->query("force")<2*(int)me->query("max_force"))
      me->add("force",20);
    if((int)me->query("force_factor") < 80 && forlvl > 500 )
      me->set("force_factor",80);
    if(funlvl < 100 && me)
      function_improved("kang_power",random(funlvl*10)+3);
  }
  else if( duration >= 1)
  {
    tell_object(me, HIR"你感到火勁在體內流轉，運勁通暢無比！\n"NOR);
    message("vision", me->name() + HIR"的護身烈焰漸漸地凝聚在丹田... \n"NOR,environment(me), me);
    if((int)me->query("force")<2*(int)me->query("max_force"))
      me->add("force",10);
    if((int)me->query("force_factor") < 80 && forlvl > 500 )
      me->set("force_factor",80);
    if(funlvl < 100 && me)
      function_improved("kang_power",random(funlvl*10)+2);
  }
  if( duration == 0 )
  {
    me->set("force_factor", 10); 
    tell_object(me,HIY"你運的烈焰浩氣開始消散了。\n"NOR);
    me->delete_temp("kang-power");
    me->delete("fire_add_force");
    if(funlvl < 100 && me)
      function_improved("kang_power",random(funlvl*10)+1);
    return 0;
  }
  if(me->query_skill_mapped("unarmed")!= "lungshan")
  {
    write("由於你使用別派武學，導致體內的烈焰浩氣不受控制致使身受內傷。\n");
    //為避免不夠氣時會死亡故加入此判斷。     
    if(me->query("kee")>200) me->add("kee",-200);
    me->apply_condition("hart",50);
    me->set("force",0);
    duration=1;
  }
  if(me->query_skill_mapped("parry")!= "fire-kee") 
  {
    write("由於你沒使用護身氣勁，導致體內的烈焰浩氣不受控制致使身受內傷。\n");
    if(me->query("kee")>300) me->add("kee",-300);
    me->apply_condition("hart",50);
    me->set("force",0);
    duration=1;
  }
  me->apply_condition("kang-power",duration-1);
  return 1;
}
