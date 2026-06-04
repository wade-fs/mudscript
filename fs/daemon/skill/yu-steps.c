// 這一份若有要修改之處 spare, futzao, lopo 自行編寫與加入...
// 最中要一點:要以 [1;33m玩家[0m 的意見為主...[1;35m切記 切記[0m

#include <ansi.h>
inherit SKILL;

string delay();

string *dodge_msg = ({
  "\n$n使出『[1;37m蛇行訣[0m』身行一晃，如蛇行般輕靈，滑過$N的身旁，躲過了$N的攻擊。\n",
  "\n$n使出『[1;32m鶴沖天[0m』身形如鶴，飛身沖上雲端，輕易的閃過$N的攻擊。\n",
  "\n$n施展『[1;35m鷹凌霄[0m』$n好比飛鷹，繞著$N身子左盤又旋，兜圈急轉，趁隙發招。\n",
  "\n$n施展『[1;33m鳳蝶舞[0m』把$N的攻勢，借勁一送，結果$N的攻勢如沈入大海一般。\n",
  "\n$n施展『[1;34m龍吟行[0m』氣運單田，發出龍吟氣功\護體，把$N的攻勢，輕易瓦解。\n",
  "\n$n施展『[1;31m麟蹤火[0m』只見$n全身如火焚身般，如火麒麟附體，大顯神威，$N的攻勢完全無用。\n",
  "\n$n施展『[1;36m虎躍衝[0m』$n有如猛虎一般兇猛，動作靈活，結果把$N的攻勢，視若無睹。\n",
});

string delay()
{
  object enemy = call_stack(1)[<1];
//  object ppl;
  enemy->start_busy(2);
/*
  ppl=find_player("blazakira");
//魚缸@台北 說: call_stack(1)[<1] 就是把一路 call 過的物件中取最後一個，還是最前面一個
  if(ppl)
    tell_object(ppl,sprintf("%O",call_stack(1))); //此參數於此處時 可查看相關物件來debug by blazakira
*/
  return HIC + "\n$n眼見$N狂攻而至，雙腿連環，霎時之間連踢六腿，盡數中在$N心口，正是少林
七十二絕技之一的" + HIY + "『[1;37m如影隨形腿[0m" + HIY + "』" + HIC + "，一腿既出，第二腿如影隨形，緊跟而至，第二
腿隨即自影而變為形，而第三腿復如影子，跟隨踢到，直踢到第六腿，$N終就無法躲
開，一腳踢上$N的胸口，逼使$N的身形一滯。\n\n" + NOR;
}

int valid_enable(string usage)
{
  return (usage=="dodge")||(usage=="move");
}

int valid_learn(object me)
{
  return 1;
}

string query_dodge_msg(string limb,object me,object attacker)
{
  object ppl;
  string d;

  d = dodge_msg[random(sizeof(dodge_msg))];
  if( !attacker->is_busy() &&
      me->query("class") == "bonze" &&
      me->query_skill("yu-steps",1) > 80 && //更正判斷技能 saulin-kee >> yu-steps by blazakira
      me->query("quests/yu-steps") &&
      me->query("force") > 300 &&
      me->query("combat_exp") > random(attacker->query("combat_exp")) )
  {
    attacker->start_busy(1);
    me->add("force",-50);
    d += HIY + "\n$n隨著$N的攻擊使出【如影隨形腳】，一股渾重的氣旋，使$N攻擊的力量化為內勁反傷自已。\n\n" + NOR;
    if( me->query_skill("yu-steps",1)-60 > random(100) ) //前述已限制80 此時機率為 80~100-60 > random(100) = 20%~40%
      d += delay();
  }
  ppl=find_player("blazakira");
//魚缸@台北 說: call_stack(1)[<1] 就是把一路 call 過的物件中取最後一個，還是最前面一個
  if( ppl && me->query("id")=="blazakira" ) {
//    tell_object(ppl,sprintf("%O",call_stack(1))); //此參數於此處時 可查看相關物件來debug by blazakira
    tell_object( ppl,RED+BYEL + "\n目前對手 "+attacker->query("name")+"("+attacker->query("id")+") 來自七靈馭風訣的 busy回合為："+attacker->query_busy()+"\n\n" + NOR );
  }
  return d;
}

int practice_skill(object me)
{
  if((int)me->query("kee")<5)
    return notify_fail("你的氣不夠，不能練七靈馭風訣 。\n");
  me->receive_wound("kee",5,me);
  return 1;
}
