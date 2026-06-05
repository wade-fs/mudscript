//seventy-two.c
//排版(此技能看起來為純普攻 且skill lv1 或lv100 效果都一樣為無附攻、無連擊、連傷害也無關…等) by blazakira 2011/10/9
//調整為降殺氣的技能 by blazakira 2011/10/14

#include <combat.h>
#include <ansi.h>
inherit SKILL;

mapping *action = ({
//0
  (["action"     : HIW + "$N" + HIW + "氣凝丹田，一式" + HIC + "「青龍出洞」" + HIW + "，手中的$w" + HIW + "挾著呼呼風聲向$n" + HIW + "$l橫掃過去。" + NOR,
    "damage"     : 40,
    "dodge"      : 10,
    "parry"      : -20,
    "damage_type": "擊傷",
  ]),
//1
  (["action"     : HIW + "$N" + HIW + "一個縱躍，手中$w" + HIW + "斜引，一招" + HIR + "「伏虎勢」" + HIW + "，似有千鈞之力，從半空中直搗而下。" + NOR,
    "damage"     : 50,
    "dodge"      : 20,
    "parry"      : -30,
    "damage_type": "擊傷"
  ]),
//2
  (["action"     : HIW + "$N" + HIW + "雙目精光四射，口呼佛號，一招" + HIB + "「苦海無涯」" + HIW + "，手中$w" + HIW + "迅捷無倫的迎向$n" + HIW + "$l。" + NOR,
    "damage"     : 70,
    "dodge"      : 0,
    "parry"      : -50,
    "force"      : 100,
    "damage_type": "擊傷"
  ]),
//3
  (["action"     : HIW + "$N" + HIW + "口中念念有辭，運起" + HIM + "「般若懺」" + HIW + "，手中的$w" + HIW + "鳴聲大作，嗡嗡地震的$n" + HIW + "心中一顫。" + NOR,
    "damage"     : 80,
    "dodge"      : -30,
    "parry"      : 10,
    "post_action":  (: call_other,__FILE__,"belldown" :),
    "damage_type": "擊傷"
  ]),
//4
  (["action"     : HIW + "$N" + HIW + "略一吐勁，力透經脈，全身骨骼爆起輕響，一招" + HIY + "「破魔障」" + HIW + "，$w" + HIW + "遊龍似的往$n" + HIW + "$l捲去。" + NOR,
    "damage"     : 100,
    "force"      : 100,
    "parry"      : -30,
    "dodge"      : -10,
    "damage_type": "擊傷"
  ]),
//5
  (["action"     : HIW + "$N" + HIW + "力隨意轉，意守氣海，一招" + HIC + "「降妖伏魔」" + HIW + "，將手中的$w" + HIW + "舞成一片。" + NOR,
    "damage"     : 130,
    "force"      : 130,
    "parry"      : -20,
    "dodge"      : 0,
    "post_action":  (: call_other,__FILE__,"belldown" :),
    "damage_type": "擊傷"
  ]),
});

mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

int valid_learn(object me)
{
  object ob;

  if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff" )
    return notify_fail("你必須先找一根禪杖才能練杖法\n");
  return 1;
}

int valid_enable(string usage)
{
  return (usage=="staff") || usage=="parry";
}

void belldown(object me,object target,object weapon,int damage)
{
  int skill,limit,m,k;
  if( !me || !target || me->query("sec_kee") != "dhyana" || me->query("force") < 300 ||
      target->query("bellicosity",1) < 100 || me->query_temp("conti") ||
      me->query_temp("berserk") || me->query_temp("devast") || me->query_temp("devast2") ) return;
  skill=(int)me->query_skill("fumostaff", 1);
  if( !skill ) skill=(int)me->query_skill("seventy-two", 1);
  limit=(int)skill/10+1;
  tell_object(me,"1st 來自於技能等級的極限值為："+limit+"\n");
  m=me->query("bellicosity",1);
  if( !userp(target) ) limit=limit*2; //max=(100/10+1)*2=22
  tell_object(me,"2nd 其對手非玩家時的極限值為："+limit+"\n");
  if( m > 100 ) limit=(int)limit*0.5+1; //如果自己有殺氣 效果減弱 //max=(100/10+1)*0.5+1=6.5 //對手為npc則為13
  tell_object(me,"3rd 自己的殺氣太高時極限值為："+limit+"\n");
  k=(int)limit*0.5+random(limit);
  me->add("force",-(20+limit)); //需要額外再設扣除佛法值
  me->add("s_kee",-1); //需要額外再設扣除佛法值
  message_vision("口中念佛經\n",me,target);
  if( random(target->query("combat_exp")) < random(me->query("combat_exp")) )
  {
    if( wizardp(me) )
      tell_object(me,GRN+BWHT+target->query("name")+"("+target->query("id")+GRN+BWHT+")殺氣為【"+target->query("bellicosity")+"】，因佛法而殺氣扣值【"+k+"點】。\n" + NOR);
    message_vision(HIY+BYEL + "乍聞佛法，$n" + HIY + "忽有領悟，心中殺意略消。\n" + NOR,me,target);
    target->add("bellicosity",-k); //數值不高 是因為有多人圍毆的可能 //max=6.5/2+6.5=9.75
  }
  else
    message_vision("招架$N的攻勢使得$n心思一分，也就不受影響。\n" + NOR,me,target);
}

int practice_skill(object me)
{
//  object weapon;
//  if(me->query("max_force")/10<me->query_skill("gold-blade",1))
//    return notify_fail("你內力不足，強硬練習，只會受害。\n");
//  if( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type")!="blade")
//    return notify_fail("你要有適合的武器才能練習紫金六陽刀法。\n");

  if((int)me->query("kee")<30)
    return notify_fail("氣不夠囉，休息一下再練吧。\n");
  me->receive_damage("kee",30,me);
  return 1;
}
//此技能沒有per 所以暫時關閉此段 by blazakira
/*
string perform_action_file(string action)
{
  return CLASS_D("bonze")+"/seventy-two/"+action;
}
*/
