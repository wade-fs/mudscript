//調整skill 為了整合在seventy-two中 by blazakira 2010/10/20

#include <ansi.h>
inherit SKILL;

string delay();
string *parry_msg = ({
  HIW"$n"HIW"一招"HIY"『禮敬如來』"HIW"，雙掌一合，擋住了$N"HIW"的殺招。\n"NOR,
  HIC"$n"HIC"足跟不動，足尖左磨，成右引左箭步，輕輕巧巧的卸開了$N"HIC"的攻勢。\n"NOR,
  HIW"$n"HIW"袖袍一拂，一股輕柔渾和的氣旋，把$N"HIW"攻擊的力道化為無形。\n"NOR,
});

string delay()
{
  object enemy = call_stack(1)[<1];
  enemy->start_busy(1);
  return HIC"$n"HIC"緩過氣來緊接著將另一袖袍也使出【袖裡乾坤】一拂，一股渾重的氣旋，把$N"HIY"攻擊的身形再度一滯。\n\n"NOR;
}

int valid_enable(string usage)
{
//  int family;
  object me=this_player();
//  if ( me->query("family/family_name") == "少林派")
  if ( me->query("class") == "bonze")
    return (usage=="parry");
  else
    return notify_fail("只有少林弟子才能使用少林護身勁！\n");
}

string query_parry_msg(string limb,object me,object attacker)
{
  object ppl;
  int parry_pow;
  string d;
  int my_exp = me->query("combat_exp") /2 ; 
//  tell_object(find_player("whatup"),sprintf("me = %O\nvictim = %O\n",me,attacker));
  d = parry_msg[random(sizeof(parry_msg))];
  if( !attacker->is_busy() &&
      me->query("class") == "bonze" && 
      me->query_skill("saulin-kee",1) > 80 && 
      me->query("quests/saulin-kee") &&
      me->query("force") > 300 &&
      random(8) == 0 && // 還是加上不會出的機率，否則 exp 少的一定出不了手
      my_exp + random(my_exp) > random(attacker->query("combat_exp")) )
  {
    attacker->start_busy(1);
    me->add("force",-50);
    d += HIY"但$n"HIY"袖袍一拂使出【袖裡乾坤】，一股渾重的氣旋，讓$N"HIY"的身形一滯。\n"NOR;
    if( me->query_skill("saulin-kee",1)-60 > random(100) ) //前述已限制80 此時機率為 80~100-60 > random(100) = 20%~40%
      d += delay();
  }
  ppl=find_player("blazakira");
//魚缸@台北 說: call_stack(1)[<1] 就是把一路 call 過的物件中取最後一個，還是最前面一個
  if( ppl && me->query("id")=="blazakira" ) {
//    tell_object(ppl,sprintf("%O",call_stack(1))); //此參數於此處時 可查看相關物件來debug by blazakira
    tell_object( ppl,RED+BYEL"\n目前對手 "+attacker->query("name")+"("+attacker->query("id")+") 來自少林護身勁的 busy回合為："+attacker->query_busy()+"\n\n"NOR );
  }
  return d;
}
/*
string query_parry_msg(string limb)
{
  return parry_msg[random(sizeof(parry_msg))];
}
*/
int valid_learn(object me)
{
/*
  if(me->query_skill("ejinforce",1) < 80 )
    return notify_fail("你的易筋經不夠精湛！！無法修習少林護身勁。\n");
  if(me->query_skill("buddhaism",1) <= me->query_skill("saulin-kee",1))
    return notify_fail("你的佛法修為不足！！無法修習少林護身勁。\n");
*/
  return 1;
}

int practice_skill(object me)
{
  if((int)me->query("kee")<100)
    return notify_fail("你的氣不夠，不能修習少林護身勁。\n");
  me->receive_wound("kee",10,me);
  return 1;
}
//此技能沒有per 所以關閉此段 by blazakira
/*
string perform_action_file(string action)
{
  return CLASS_D("bonze")+"/saulin-kee/"+action;
}
*/
