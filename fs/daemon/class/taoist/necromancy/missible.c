#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_SPELL;
void remove_effect (object me);
int cast(object me, object target)
{
  int spell,cas,vfun,mkee,tdodge;
  if( !target ) target = offensive_target(me);
  if( !target
      ||        !target->is_character()
      ||        target->is_corpse()
      ||        target==me)
                return notify_fail("你要對誰施展這個法術﹖\n");
  if( !me->query("spells/missible/level") )
     return notify_fail("看不懂啦, 請用 help cmds 查一般指令!\n");
  if(me->query_temp("ttt"))
                return notify_fail("你的法術還沒施完！！\n");
  if(me->query("mana") < 50 )
     return notify_fail("你的法力不夠﹗\n");
  me->add("mana", -25);
  me->start_busy(1);
  spell = me->query_skill("spells");
  vfun = me->query("spells/missible/level");
  if(me->query("class") != "taoist") {
    spell=spell/3;
    vfun=vfun/2; }
if(me->query("adv_taoist")&&me->query("class")=="taoist")
  cas=6;
  else if(spell < 40)
    cas=random(2);
  else if(spell < 80)
    cas=random(4);
  else if(spell <= 120)
    cas=random(5);
  else if(spell > 120)
    cas=random(6);
  me->improve_skill("necromancy", 1);
  if(  me->query("spells/missible/level") < 100 )
  spell_improved ("missible", random(spell*7));
  switch(cas)
  {
    case 0:
    message_vision("$N一招『" + HIB + "箭射蒼穹" + NOR + "』法力從手中如閃電般射出。\n" + NOR,me,target);
    break;
    case 1:
    message_vision("$N一式『" + HIW + "水流雲" + NOR + "』心靜如水一道白光自手中騰出，有如天上隨風起舞的銀白緞帶彎彎曲曲地鑽向$n。\n" + NOR,me,target);
    break;
    case 2:
    message_vision("$N縱身躍起，雙手一劃上空兩道光芒急射而出，正是一招『" + HIC + "雙芒趕月" + NOR + "』。\n" + NOR,me,target);
    break;
    case 3:
    message_vision("$N陡然使出天道派法術精華--『" + HIB + "銀星掠空" + NOR + "』，只見兩枚光球似有靈性一般自$N手裡竄出，以不可思議的角度鑽向$n。\n" + NOR,me,target);
    break;
    case 4:
    message_vision("$N大喝一聲，猛招『" + HIY + "百尺竿頭" + NOR + "』砰然射出，威力直達百尺外的地面。\n" + NOR,me,target);
    break;
    case 5:
    message_vision("\n\n$N運指如飛，使出天道最高絕學-------『" + HIR + "八卦千輪指" + NOR + "』--------\n\n " + MAG + "八條紫光在天空劃出優美的弧線，如影似幻，盡聚射$n的八處要穴!!\n\n" + NOR,me,target);
    break;
	case 6:
	message_vision(HIG + "
   $N領悟道家沖虛精神，體內法力源源不絕形成一股強大能量
   \n " + HIW + "     ～　" + YEL + "紫  幽  之  箭
                                   " + HIC + "流　星　" + HIM + "追　月　" + HIW + "～
" + HIW + "\n只見$N周身散放出耀眼光茫，空氣之中迴盪著一股龐大的氣流，瞬間數道
       光茫如流星般向"+target->query("name")+"周遭急射而去，形成一道龐大的氣勁攻向"+target->query("name")+"。\n" + NOR, me);
	   me->set_temp("ttt",1);
    break;
    default:
    break;
 }

 if( 80 >random(100) ) {
  switch(cas)
  { 
   case 0..5:
  message_vision("嗤的一聲，" + MAG + "紫幽之箭" + NOR + "的光芒伴著血箭自$n的身體穿透而出。\n" + NOR,me,target);
  break;
   case 6:
   message_vision(BRED+MAG + "紫幽之箭疾如閃電，迅速射向$n，大地瞬間被強大氣流轟出一個大洞。\n" + NOR,me,target);
   break;
   default:
   break;
   }
  switch(cas)
  {
    case 0: target->receive_damage("kee",vfun*2);
    break;
    case 1: target->receive_damage("kee",vfun*3);
    break;
    case 2: target->receive_damage("kee",vfun*4, me);
    break;
    case 3: target->receive_damage("kee",vfun*5 , me);
    break;
    case 4: target->receive_damage("kee",vfun*6,me);
    break;
    case 5: target->receive_damage("kee",vfun*8, me);
    break;
	case 6: target->receive_damage("kee",vfun*12, me);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me:),5);
    break;
    default:
    break;

 }
 COMBAT_D->report_status(target);
 } else {
   switch(cas)
   {
    case 0..5:
    message_vision(HIW + "$n身體一側，不急不徐地躲開....\n" + NOR,me,target);
	break;
	case 6:
	message_vision(HIW + "$n眼明手快，施展輕功\躍上天際，雖避開紫幽之箭但仍心有餘悸，驚慌不已。\n" + NOR,me,target);
    break;
    default:
    break;
   }

 }

 if( !target->is_fighting(me) ) {
        if( living(target) ) {
                if( userp(target) ) target->fight_ob(me);
                else                    target->kill_ob(me);
        }
        me->kill_ob(target);
 }
//me->start_call_out((:call_other,__FILE__,"remove_effect",me:),3);
  call_out("remove_effect",3,me);

 return 1;

}

void remove_effect (object me)
{
  if(!me) return ;
  me->set_temp("ttt",0);
  return;
}
