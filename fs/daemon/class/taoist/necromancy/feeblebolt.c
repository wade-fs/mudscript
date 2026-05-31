#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_SPELL;
void remove_effect (object me,object target);
void remove_effect2 (object me,object target);
int cast(object me, object target)
{
        int funlvl;
        if( !target ) target = offensive_target(me);
        if( !target
                ||        !target->is_character()
                ||        target->is_corpse()
                ||        target==me)
                return notify_fail("你要對誰施展這個法術﹖\n");
		
        if( !funlvl = me->query("spells/feeblebolt/level") )
                return notify_fail("你並不會這項法術。\n");
        if(me->query_temp("tt"))
                return notify_fail("你的法術還沒施完！！\n");
        if(me->query("mana") < funlvl/2 )
                return notify_fail("你的法力不夠﹗\n");
        me->add("mana", -funlvl/2);
        me->set_temp("tt",1);
if(me->query("adv_taoist")&&me->query("class")=="taoist")
{message_vision(HIY"
   $N腳踏兩儀之位，退守乾坤之眼，喃喃唸起道家至高咒語︰
   \n             　"HIM"蒼 天 借 法
   "BLU"冥界為引  "HIW"～               ～  "HIR"焰日催魂
   　               "HIC"陰月索命
"HIG"\n瞬間天地為之撼動，天際出現百年難得一見的日月同昇，日光月影受$N咒語所牽動降下
一股天地靈氣，$N迅速將天地靈氣化成一道蒼冥之箭以迅雷不及掩耳之勢射向"+target->query("name")+"。\n"NOR, me);
me->start_call_out((:call_other,__FILE__,"remove_effect2",me,target:),5);
}
else{
        message_vision(HIW"\n\n$N口中默念咒語並將所有法力聚於雙指!!\n\n"NOR,me);
me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),5);
}
return 1;
}

void remove_effect (object me,object target)
{
        int spell,cas,vkar,vfun,msen,tdodge,pp,mypp;

        me->set_temp("tt", 0);
        if( !target ) return;
        if( environment(me) != environment(target) ) return;
        if(!present(target,environment(me))) {
                write("你的獵物不在這裡ㄛ!!\n");
                return ;
        }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else                target->kill_ob(me);
                }
                me->kill_ob(target);
                target->kill_ob(me);
        }
        spell = me->query_skill("spells");
        vfun = me->query("spells/feeblebolt/level");
        if(me->query("class") != "taoist") {
                spell /= 3;
                vfun /= 2;
        }
        switch(spell) {
                case 0..40 :    cas = random(2);        break;
                case 41..70 :   cas = random(3);        break;
                case 71..100 :  cas = 1 + random(4);    break;
                case 101..130 : cas = 1 + random(5);    break;
                default :       cas = 1 + random(6);    break;
        }

     me->improve_skill("necromancy", 1);

        if( me->query("spells/feeblebolt/level") < 100)
                spell_improved ("feeblebolt", random(spell)*7);

        switch(cas) {
                case 0:
                        message_vision("$N雙手一招『"HIB"箭射蒼穹"NOR"』法力從指中如閃電般射出。\n"NOR,me,target);
                        break;
                case 1:
                        message_vision("$N忽地一式『"HIW"白虹貫日"NOR"』，勁風逼人一條白光筆直地射向$n。\n"NOR,me,target);
                        break;
                case 2:
                        message_vision("$N憑風而立，雙手一揚!上方兩道光芒急射而來，正是一招『"HIR"雙芒趕月"NOR"』。\n"NOR,me,target);
                        break;
                case 3:
                        message_vision("$N身法飄忽，忽然掌中并出兩道虛實難辨的『"HIB"無定流星"NOR"』，光芒極盡靈活，以不可思議的角度向$n射去。\n"NOR,me,target);
                        break;
                case 4:
                        message_vision("$N長嘯一聲，洛書河圖極招『"HIY"點落八方"NOR"』隨手而出，只見$N十指連點八道青光自四面八方撲向$n，一時間已將$n吞噬～～\n"NOR,me,target);
                        break;
                case 5:
                        message_vision("$N轉身撤步，反手一招『"HIC"星羅棋布"NOR"』將洛書河圖所載『已退為進，攻敵之奇』發揮得淋漓盡致，天空青光交錯縱橫$n全身已盡在此招籠罩之下。\n"NOR,me,target);
                        break;
                case 6:
                        message_vision("\n\n"HIW"$N忽然醒悟了『清淨無為，神游太虛』精髓，一式蒼冥之箭最強殺招----『"HIC"金劍穿雲"HIW"』----化繁為簡\n       "HIY"$N雙手一合祭起一道浩瀚無匹的奪目金光，挾著破空之聲直向$n衝來\n"NOR,me,target);
                        break;
                default:
                        break;
        }

        if( 80 > random(100) ) {
                message_vision("嗤的一聲，"HIG"蒼冥之箭"NOR"從$n身上透體而過，拖出一條長長的黑氣直射兩三丈外的地下。\n",me,target);
                if(me->query("class")!="taoist" ) {
                me->start_busy(1);
                }
                target->kill_ob(me);
                switch(cas)
                {
    case 0: target->receive_damage("sen",vfun*2);
    break;
    case 1: target->receive_damage("sen",vfun*3);
    break;
    case 2: target->receive_damage("sen",vfun*4 , me);
    break;
    case 3: target->receive_damage("sen",vfun*5,me);
    break;
    case 4: target->receive_damage("sen",vfun*6, me);
    break;
    case 5: target->receive_damage("sen",vfun*7, me);
    break;
    case 6: target->receive_damage("sen",vfun*8, me);
    break;
    default:
    break;
 }
 COMBAT_D->report_status(target);
 } else {
    message_vision(HIW"結果$n人比招快，躲了開來!\n"NOR,me,target);
    me->start_busy(1);
 }

  return;
}
void remove_effect2 (object me,object target)
{
 int vfun;
  if(!me) return ;
 vfun = me->query("spells/feeblebolt/level");
 me->delete_temp("tt");
  if(!target) return ;
   if( environment(me) != environment(target) ) return;
 if( 80 > random(100) ) 
  {
  message_vision(BRED+HIW"$n身受蒼冥之箭陰寒之氣所引，內息一陣翻騰不定，口吐鮮血，臉色倉白。\n",me,target);
  target->receive_damage("sen",vfun*5, me);
  target->receive_damage("gin",vfun*5, me);
  target->receive_wound("kee",vfun*5, me);
  target->kill_ob(me);
  COMBAT_D->report_status(target);
  }
  else {
    message_vision(BBLU+HIW"$n眼見蒼冥之箭急射而至，腦中奇招忽現，一個翻身躲過蒼冥之箭的攻勢。\n"NOR,me,target);
 //   me->start_busy(1);
  }
        if( me->query("spells/feeblebolt/level") < 150)
                spell_improved ("feeblebolt", random(vfun)*7);

  return;
}
