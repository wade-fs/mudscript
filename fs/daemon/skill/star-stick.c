//調整skill 為了整合在seventy-two中 與receive_damage()攻擊方參數 by blazakira 2010/10/20

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack(object me, object victim, object weapon, int damage);
int kar,cps,str,cor,int1,spi;

mapping *action = ({
//1
  (["action"     : HIW"$N一招"HIR"「星火燎原」"HIW"，舉起$w"HIW"，擊向$n的列缺穴。"NOR,
    "damage"     : 150,
    "force"      : 150,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "穴傷",
  ]),
//2
  (["action"     : HIW"$N一招"HIG"「星羅棋布」"HIW"，挺起$w"HIW"，擊向$n的太淵穴。"NOR,
    "damage"     : 150,
    "force"      : 150,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "穴傷",
   ]),
//3
  (["action"     : HIW"$N一招"HIY"「星曜九天」"HIW"，拿起$w"HIW"，擊向$n的百會穴。"NOR,
    "damage"     : 200,
    "force"      : 200,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type":  "穴傷",
  ]),
//4
  (["action"     : HIW"$N一招"HIM"「流星追月」"HIW"，架起$w"HIW"，擊向$n的淵液穴。"NOR,
    "damage"     : 200,
    "force"      : 200,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type":  "穴傷",
  ]),
//5
  (["action"     : HIW"$N一招"HIB"「披星戴月」"HIW"，舉起$w"HIW"，擊向$n的陰谷穴。"NOR,
    "damage"     : 250,
    "force"      : 250,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type":  "穴傷",
  ]),
//6
  (["action"     : HIC"$N一招"HIW"「日換星移」"HIC"，挺起$w"HIC"，擊向$n的中府穴。"NOR,
    "damage"     : 250,
    "force"      : 250,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type":  "穴傷",
  ]),
//7
  (["action"     : HIC"$N一招"HIB"「風離星散」"HIC"，拿起$w"HIC"，擊向$n的曲池穴。"NOR,
    "damage"     : 250,
    "force"      : 250,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type":  "穴傷",
  ]),
//8

  (["action"     : HIC"$N一招"HIM"「風馳電擎」"HIC"，架起$w"HIC"，擊向$n的關元穴。"NOR,
    "damage"     : 300,
    "force"      : 300,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "穴傷",
  ]),
//9
  (["action"     : HIC"$N一招"HIY"「雲湧星迴」"HIC"，舉起$w"HIC"，擊向$n的氣海穴。"NOR,
    "damage"     : 300,
    "force"      : 300,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "穴傷",
  ]),
//10
  (["action"     : HIC"$N一招「"HIG"星辰"HIR"再現"HIC"」，挺起$w"HIC"，擊向$n的印堂穴。"NOR,
    "damage"     : 300,
    "force"      : 300,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "穴傷",
  ]),
});

mapping query_action(object me, object victim, object weapon)
{
  int skill, limit;
  kar=me->query_kar();
  cps=me->query_cps();
  str=me->query_str();
  cor=me->query_cor();
  int1=me->query_int();
  spi=me->query_spi();
  skill=(int)(me->query_skill("star-stick", 1));
  if( !skill ) skill=(int)(me->query_skill("seventy-two", 1));
  limit=(int)(skill/10);
  if(limit<3){return action[random(2)];}
  else if(limit<5){return action[random(4)];}
  else if(limit<7){return action[random(6)];}
  else if(limit<9){return action[random(8)];}
  else{return action[random(10)];}
}

int valid_learn(object me)
{
/*
  object ob;
  if((int)me->query("max_force",1)<3000)
    return notify_fail("你的內力不夠，不能練星辰棍法。\n");
  if((string)me->query_skill_mapped("force")!= "ejinforce")
    return notify_fail("燃木刀法必需配合易筋心法才能用。\n");
  if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="stick")
    return notify_fail("你必須有棍子才能練星辰棍法。\n");
*/
  return 1;
}

int valid_enable(string usage)
{
  return usage=="stick" || usage=="parry";
}
//此技能沒有per 所以暫時關閉此段 by blazakira
/*
string perform_action_file(string action)
{
  return CLASS_D("bonze") + "/seventy-two/" + action;
}
*/
void attack(object me, object victim, object weapon, int damage)
{
  int i,j;
  if( !me || !victim ) return;
  j=random(6);
//  if(me->query("id")=="swy") j=4;
  switch(j)
  {
    case 0:
      message_vision(sprintf(HIR"\n$N奮力往$n的要穴點去，頓時$n內息走岔，行動變緩。\n"NOR),me,victim);
      victim->start_busy(1);
      COMBAT_D->report_status(victim);
      break;
    case 1:
      message_vision("$N暗運丹田急欲搶攻，卻被$n看破，只好棄攻為守。\n",me,victim);
      break;
    case 2:
      damage = (str+cor+cps+kar+spi+int1)*2+50;
      message_vision(sprintf(HIR"\n$N雄厚內勁打擊$n的要穴，只覺的內息一震，已受了嚴重內傷。\n"NOR),me,victim);
      victim->receive_damage("kee",damage,me);
      victim->apply_condition("hart",5);
      COMBAT_D->report_status(victim);
      break;
    case 3:
      message_vision("$N見$n氣息錯亂，見機搶攻，卻被$n看破，無攻而反。\n",me,victim);
      break;
    case 4:
      damage=(cps+int1+str+cor+kar+spi)*2+50;
      message_vision(HIW"\n$N眼見$n露出破綻，機不可失，朝$n身上各大穴狂點而去，重創了$n。\n"NOR,me,victim);
      if( me->query_temp("conti") == 0 )
      {
        me->set_temp("conti",1);
        for(i=1;i<=3;i++) {
          COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK); }
        me->delete_temp("conti");
      }
      victim->start_busy(1);
      victim->receive_damage("kee",damage,me);
      COMBAT_D->report_status(victim);
      break;
    case 5:
      message_vision("$N運轉氣勁，卻無法即時吐吶，不得不暫緩攻勢。\n",me,victim);
      break;
  }
}
