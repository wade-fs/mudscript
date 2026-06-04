#include <ansi.h>//reflection by cgy
inherit F_SPELL;
inherit SSERVER;
int fun;

void remove_effect (object me);
int conjure(object me, object target)
{
string msg;
fun=me->query("spells/reflection/level");
if (!me->query("spells/reflection/level"))
     return 0;
  if((me->query("family/family_name")!="夜夢小築")&&(me->query("id")!="cgy"))
     return notify_fail ("只有舞者能用這種法術！\n");
  if (me->query ("atman") < 200)
     return notify_fail ("你的靈力不足!\n");
  if ((int)me->query_temp ("ref_shield", 1))
     return notify_fail ("你已經使用玄冰結界了。\n");
  if (me->query_temp("absorb"))
     return notify_fail ("妳已經受到太陰之氣的庇護了。\n");

if( me->is_fighting() ) me->start_busy(1); //在戰鬥中使用,要busy自己一回合 by chan

  msg = HIG + "$N集中全身靈力右手在身前劃了一個大圓，漸漸的在$N的身前出現了一面" + NOR;
  msg += HIG + "\n冰盾保護著$N，原來是夢玄法鑑中的" + HIR + "終極防禦術" + HIC + "「玄☆冰☆結☆界」\n" + NOR;
  message_vision(msg, me, target);
  me->add ("atman", -200);
  
if( me->query_temp("mana_shield"))    //同時使用dreamwinds和reflection時的增幅效果  by frequency 2003 /4/29
  {
  message_vision(HIY + "$N身上的" + HIW + "幻夢之翼" + HIY + "和" + HIC + "玄冰結界" + HIY + "發生強烈的共鳴，形成了" + HIR + "『" + HIM + "水月神鏡" + HIR + "』" + HIG + "。\n" + NOR,me);
  message_vision(HIY + "一道皎潔的月光由天上降下，$N頓時受到太陰之氣的庇護。\n" + NOR,me);
  me->delete_temp("ref_shield");
  me->delete_temp("mana_shield");
  me->start_call_out((: call_other, __FILE__, "remove_effect2",me:),me->query("spells/absorb/level")+20);
  if(me->query("moon_quest/water"))       me->set_temp("absorb",2);
  else if(me->query("moon_quest/moon"))   me->set_temp("absorb",3);
  else me->set_temp("absorb",1);
    return 1;
  }    
       
  message_vision (HIY + "$N感到自己有著所向無敵的防禦力。\n" + NOR, me,target);

// 設這個mark後就有ref_shield 了
  me->set_temp ("ref_shield", 1);
  me->start_call_out((: call_other, __FILE__, "remove_effect",me:),fun+20);
  

  return 1;
}

void remove_effect (object me)
{
// 刪除 ref_shield   
if(!me->query_temp("absorb"))
 {
  int fun=me->query("spells/reflection/level");
  me->delete_temp ("ref_shield");
  tell_object (me,HIW + "妳覺得自己的防禦力下降了許\多。\n" + NOR);
  if(fun<100) spell_improved("reflection",random(300));   
 }
  return;
}

void remove_effect2 (object me)
{
// 刪除 absorb  
int fun=me->query("spells/absorb/level");
  me->delete_temp ("absorb");
  tell_object (me, NOR + "太陰之氣逐漸從你身上消散，回歸天庭。\n" + NOR);
  if(fun<100) spell_improved("absorb",random(300));   
  return;
}
