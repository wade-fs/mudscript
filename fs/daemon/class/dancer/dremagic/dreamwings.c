#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
void remove_effect (object me);
int conjure(object me, object target)
{
fun=me->query("spells/dreamwings/level");
if (!me->query("spells/dreamwings/level"))
     return 0;
  if (me->query ("atman") < 50)
     return notify_fail ("你的靈力不足!\n");
  if ((int)me->query_temp ("mana_shield", 1))
     return notify_fail ("你已經使用幻夢之翼了。\n");
  if ((int)me->query_temp ("mana_shield2", 1))
     return notify_fail ("你已經使用幻夢之翼了。\n");
  if ((int)me->query_temp ("mana_shield3", 1))
     return notify_fail ("你已經使用幻夢之翼了。\n");
  if ((int)me->query_temp ("mana_shield4", 1))
     return notify_fail ("你已經使用幻夢之翼了。\n");
  if (me->query_temp ("absorb"))
     return notify_fail ("妳已經受到太陰之氣的庇護了。\n");

if( me->is_fighting() ) me->start_busy(1); //在戰鬥中使用,要busy自己一回合 by chan

  message_vision ("$N使出夢玄法鑑中的"HIC"「幻夢之翼」"NOR"\n",me,target);
  me->add ("atman", -50);

if( me->query_temp("ref_shield"))    //同時使用dreamwinds和reflection時的增幅效果  by frequency 2003 /4/29
  {
  message_vision(HIY"$N身上的"HIW"幻夢之翼"HIY"和"HIC"玄冰結界"HIY"發生強烈的共鳴，形成了"HIR"『"HIM"水月神鏡"HIR"』"HIG"。\n"NOR,me);
  message_vision(HIY"一道皎潔的月光由天上降下，$N頓時受到太陰之氣的庇護。\n"NOR,me);
  me->delete_temp("ref_shield");
  me->delete_temp("mana_shield");
  me->start_call_out((: call_other, __FILE__, "remove_effect2",me:),me->query("spells/absorb/level")+20);
  if(me->query("moon_quest/water"))       me->set_temp("absorb",2);
  else if(me->query("moon_quest/moon"))   me->set_temp("absorb",3);
  else me->set_temp("absorb",1);
  return 1;
  }    

  message_vision (HIG"$N感到有一股神秘的力量保護著自己。\n"NOR, me,target);
// 設這個mark後就有manashield 了
  if(me->query("class")=="dancer")
  {
   me->set_temp ("mana_shield", 1);
   }
   else if(me->query("class")=="fighter")
  {
  me->set_temp ("mana_shield3", 1);
  }
  else if (me->query("family/family_name")=="魔刀莫測")
  {
  me->set_temp ("mana_shield4", 1);
  }
  else {me->set_temp ("mana_shield2", 1);}
me->remove_call_out((:call_other, __FILE__, "remove_effect",me:));
if(me->query("class")=="dancer")
{
  me->start_call_out((: call_other, __FILE__, "remove_effect",me:),fun+20);
}
else if(me->query("class")=="fighter")
{
me->start_call_out((: call_other, __FILE__, "remove_effect",me:),fun/2+10);
}
else 
{
me->start_call_out((: call_other, __FILE__, "remove_effect",me:),fun/2+20);
}
  return 1;
}

void remove_effect (object me)
{
// 刪除 manashield
if(!me->query_temp("absorb"))   
 {
  int fun=me->query("spells/dreamwings/level");
   me->delete_temp ("mana_shield");
   me->delete_temp("mana_shield2");
   me->delete_temp("mana_shield3");
   me->delete_temp("mana_shield4");
  tell_object (me, NOR"妳覺得自己變虛弱了。\n"NOR);
  if(fun<100) spell_improved("dreamwings",random(500));   
 }
  return;
}

void remove_effect2 (object me)
{
// 刪除 absorb  
int fun=me->query("spells/absorb/level");
  me->delete_temp ("absorb");
  tell_object (me, NOR"太陰之氣逐漸從你身上消散，回歸天庭。\n"NOR);
  if(fun<100) spell_improved("absorb",random(300));   
  return;
}
