//調整skill 為了整合在seventy-two中 與receive_damage()攻擊方參數 by blazakira 2011/10/9

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void attack(object me, object victim, object weapon, int damage);

int kar,cps,str,cor,int1,spi;
mapping *action = ({
//1
  (["action"     : HIW
"$N"HIW"凝氣於掌，掌變化成爪，一招"HIR"「雙龍吐珠」"HIW"，雙爪有如靈龍搶珠般，飛快的\n"
"抓向$n"HIW"各要害，$n"HIW"眼見雙爪齊攻只能閃避，但還是晚了一步，$l差點慘遭分家之痛。"NOR,
    "damage"     : 150,
    "force"      : 150,
    "damage_type": "抓傷",
  ]),
//2
  (["action"     : HIW
"$N"HIW"一招"HIR"「蟠龍鎖關」"HIW"單爪直下，帶者猛烈的剛氣，順沿著$n"HIW"的攻勢，反客為主的封鎖住\n"
"$n"HIW"的攻勢，$n"HIW"頓時無以招架，被$N"HIW"深深的擊中胸膛，差點吐出血來。"NOR,
    "damage"     : 150,
    "force"      : 150,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "抓傷",
   ]),
//3
  (["action"     : HIW
"$N"HIW"暗運內息，一招"HIM"「龍鳳呈祥」"HIW"，左爪右掌分別擊向$n"HIW"的弱點，$n顧此失彼拆卸了\n"
"$N"HIW"的左爪卻無從閃避，紮紮實實吃了$N"HIW"一記右掌，造成氣血失調。"NOR,
    "damage"     : 200,
    "force"      : 200,
    "damage_type": "掌傷",
  ]),
//4
  (["action"     : HIW
"$N"HIW"跳躍而起，身形輕盈，一招"HIM"「九天龍吟」"HIW"雙掌從四面八方齊攻而下，氣勢有如狂風大浪般\n"
"似要把$n"HIW"淹沒，$n"HIW"見此招運起所有功\力全面抵擋，二氣勁硬碰硬，差點震的$n"HIW"狂吐鮮血。"NOR,
    "damage"     : 200,
    "force"      : 200,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "掌傷",
  ]),
//5
  (["action"     : HIW
"$N"HIW"氣沉丹田，側身一翻，一招"HIG"「狂龍捲浪」"HIW"雙爪凜烈，圍繞著$n"HIW"伺機給予重擊，瞬間$N"HIW"看\n"
"破$n"HIW"弱點，雙爪挾帶凜烈的氣勁，往$n"HIW"身上抓去，$n"HIW"急速閃避但還是被強大的氣勁割傷。"NOR,
    "damage"     : 250,
    "force"      : 250,
    "damage_type": "割傷",
  ]),
//6
  (["action"     : HIC
"$N"HIC"穩固下盤，真氣運走全身，一招"HIG"「虎掌生風」"HIC"雙掌凝勁，$N"HIC"見機行事呼哮的擊出\n"
"雙掌，雙掌氣勁狂掃而去與$n"HIC"氣勁相互對沖，二氣勁相碰造成$n"HIC"差點摔倒在地。"NOR,
    "damage"     : 250,
    "force"      : 250,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "掌傷",
  ]),
//7
  (["action"     : HIC
"$N"HIC"吐納內息，伺機而動，眼見$n"HIC"內息不繼，氣喘噓噓，一招"HIB"「荒山虎嘯」"HIC"，毫不猶豫的手肘\n"
"快頂而出，瞬時變化身形配合雙拳，直向$n"HIC"弱點直打而去，$n"HIC"登時被打的氣血賁騰，脈像雜亂。"NOR,
    "damage"     : 250,
    "force"      : 250,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "瘀傷",
  ]),
//8

  (["action"     : HIC
"$N"HIC"急吐內勁，運轉周天，一招"HIB"「臥龍在野」"HIC"，$n"HIC"看其氣勁似柔似軟，運起氣勁，硬是要把其\n"
"勁擋下，其內勁看似平常無力卻蘊涵無窮的內勁，等$n"HIC"發覺時，氣勁早已貫穿而震傷了五臟六腑。"NOR,
    "damage"     : 300,
    "force"      : 300,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "震傷",
  ]),
//9
  (["action"     : HIC
"$N"HIC"氣轉至雙爪，一招"HIY"「蛟龍出水」"HIC"，雙爪帶鉤，由下而上，由後至前，向$n"HIC"猛攻而去\n"
"$n"HIC"頓時，對這有如波濤洶湧的巨浪氣勁手足無措，登時被巨浪氣勁吞嗜，造成嚴重出血。"NOR,
    "damage"     : 300,
    "force"      : 300,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "內傷",
  ]),
//10
  (["action"     : HIC
"$N"HIC"運起全身功\力，氣勁遊走全身，不吐不快，一招"HIY"「金龍攫珠」"HIC"，挾帶強大力勁往$n"HIC"身上擊出\n"
"數十招，招招皆擊向$n"HIC"身上各大穴，$n"HIC"運起全身功\力全力抵擋，卻無法卸其鋒，慘遭內勁拼擊。"NOR,
    "damage"     : 300,
    "force"      : 300,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "經脈盡斷",
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
  skill=(int)(me->query_skill("dragon-claw", 1));
  if( !skill ) skill=(int)(me->query_skill("seventy-two", 1));
  limit=(int)(skill/10);
  if(random(100) < 60)
  {
    if(!me->query_temp("goldheal")&&random(100)<50)
    {
      message_vision(sprintf(HIY"\n$N大喝一聲使出少林絕學『金鐘罩』，頓時金光閃閃一道金牆籠罩在$N身旁。\n"NOR),me);
      me->set_temp("goldheal",1);
    } else if(!me->query_temp("unsuck")) {
      message_vision(sprintf(HIY"\n$N鼓運全身內勁使出十成『金鐘罩』，試圖要把敵人攻擊反震回去。\n"NOR),me);
      me->set_temp("unsuck",1);
    }
  }
  if(limit<3)
  {
    return action[random(2)];
  }
  else if(limit<5)
  {
    return action[random(4)];
  }
  else if(limit<7)
  {
    return action[random(6)];
  }
  else if(limit<9)
  {
    return action[random(8)];
  }
  else
  {
    return action[random(10)];
  }
}

int valid_learn(object me)
{
  object ob;
  if((int)me->query("max_force",1)<3000)
    return notify_fail("你的內力不夠，不能練龍爪手。\n");
//  if((string)me->query_skill_mapped("force")!= "dragonforce")
//    return notify_fail("燃木刀法必需配合擒龍功\才能用。\n");
  if(ob=me->query_temp("weapon"))
    return notify_fail("你必須放下武器才能練龍爪手。\n");
  return 1;
}

int valid_enable(string usage)
{
  return usage=="unarmed" || usage=="parry";
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
  if( !me || !victim ) return;
  switch(random(6))
  {
    case 0:
      damage = (str+cor+cps+kar+spi+int1)+120;
      message_vision(sprintf(HIR"\n$N"HIR"的龍爪手確確實實命中$n"HIR"，$n"HIR"頓時血流滿地，行動變緩。\n"NOR),me,victim);
      victim->receive_damage("kee",damage,me);
      victim->start_busy(1);
      victim->apply_condition("bleeding",10);
      COMBAT_D->report_status(victim);
      break;
    case 1:
      message_vision("$N暗運丹田急欲搶攻，卻被$n看破，只好棄攻為守。\n",me,victim);
      break;
    case 2:
      damage = (str+cor+cps+kar+spi+int1)*2+50;
      message_vision(sprintf(HIR"\n$N擒龍功\的內勁潛入$n體內，只見$n臉一陣青一陣白，似忽受傷嚴重。\n"NOR),me,victim);
      victim->receive_damage("kee",damage,me);
      victim->apply_condition("hart",5);
      COMBAT_D->report_status(victim);
      break;
    case 3:
      message_vision("$N見$n氣息錯亂，見機搶攻，卻被$n看破，無攻而反。\n",me,victim);
      break;
    case 4:
      damage=(cps+int1+str+cor+kar+spi)*2+50;
      message_vision(HIW"\n$N"HIW"的擒龍勁與龍爪勁相互輝映，二股內勁重創$n"HIW"，使$n"HIW"鮮血狂吐，無法聚氣。\n"NOR,me,victim);
      if(victim->query("force",1)>0) victim->add("force",-(damage*5));
      victim->receive_damage("gin",damage,me);
      victim->receive_damage("kee",damage,me);
      victim->receive_damage("sen",damage,me);
      COMBAT_D->report_status(victim);
      break;
    case 5:
      message_vision("$N運轉氣勁，卻無法即時吐吶，不得不暫緩攻勢。\n",me,victim);
      break;
  }
}
