//調整skill 為了整合在seventy-two中 與判斷使用者或被攻擊方是否存在的判斷 by blazakira 2011/10/9

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void attack(object me, object victim, object weapon, int damage);
int kar,cps,str,cor,int1,spi;
int i;

mapping *action = ({
//1
  (["action"     : "$N足地一點，身形一變，使出"HIR"「入木三分」"NOR"，手中$w往$n橫劈過去。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 110,
    "force"      : 160,
    "damage_type": "砍傷",
  ]),
//2
  (["action"     : "$N運氣於$w，一招"HIR"「移花接木」"NOR"趁$n接招之時，左手翻掌對準$n弱點一擊。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 120,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "掌傷",
   ]),
//3
  (["action"     : "$N運起內勁，將真氣貫注$w，一招"HIG"「木已成舟」"NOR"刀氣雄霸直劈$n。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 130,
    "force"      : 160,
    "damage_type": "砍傷",
  ]),
//4
  (["action"     : "$N踿躍而起，凌空聚氣，一招"HIG"「一刀二斷」"NOR"刀鋒冷凜直劈$n。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 140,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "砍傷",
  ]),
//5
  (["action"     : "$N一招"HIY"「星火燎原」"NOR"手中$w有如閃電般快速砍下，周邊空氣有如燃燒般爆出火光。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 150,
    "force"      : 160,
    "damage_type": "砍傷",
  ]),
//6
  (["action"     : "$N揮動手中$w使出"HIY"「緣木求魚」"NOR"只見$w像一道刀網把$n封閉在其中。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 160,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "砍傷",
  ]),
//7
  (["action"     : "$N使出"HIB"「釜底抽薪」"NOR"，只見$w刀刀相連直砍$n，$N再順勢移轉至$n背後補上一刀。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 170,
    "force"      : 160,
    "damage_type": "骨斷之傷",
  ]),
//8
  (["action"     : "$N持$w一揚，使出"HIB"「燃木生火」"NOR"，刀刀皆帶炙熱刀氣，氣勁直劈$n。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 180,
    "force"      : 160,
    "damage_type": "灼傷",
  ]),
//9
  (["action"     : HIW
"$N內勁一吐，使出"HIM"「朽木可雕」"HIW"，把所有真氣貫注於$w"HIW"，往$n飛射而去\n"
"$n知此招不能硬擋，避重就輕就要閃過此招，卻不知鬼影幻形，$N早就在一旁等候\n"
"逮住機會雙掌相併而下，造成$w"HIW"攔腰貫體而過。"NOR,
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 190,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "破體之傷",
  ]),
//10
  (["action"     : HIW
"$N內勁狂吐，使出"HIM"「披荊斬蕀」"HIW"，運轉了十成功\力，分別注於左掌與$w"HIW"，眼見\n"
"$n搶攻過來，$N不徐不避，左掌一揮硬是把攻勢給擋了下來，就在同時，右手$w"HIW"橫劈\n"
"而去，$n無從遁形被深深的砍及要害。"NOR,
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 200,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "血肉之傷",
  ]),
//11
  (["action"     : HIC
"$N加運內息，逆轉筋脈，使出"HIB"「杯水車薪」"HIC"，只見出招無一順序，由後而前，由下而上\n"
"$n頓時反應不及硬是吃了$w"HIC"一記。"NOR,
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 220,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage_type": "砍傷",
  ]),
//12
  (["action"     : HIC
"$N使出燃木刀法精華，一招"HIW"「火樹銀花」"HIC"，以慢制快，以輕馭重，以柔剋剛，加上雄厚的內勁\n"
"使$n招招不敵，$N見機加快攻勢，$w"HIC"直挺而出直搗$n。"NOR,
    "dodge"      : -10,
    "parry"      : -30,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"attack" :),
    "damage"     : 220,
    "damage_type": "砍傷",
  ]),
});

mapping query_action(object me, object weapon)
{
  int skill, limit;
  kar=me->query_kar();
  cps=me->query_cps();
  str=me->query_str();
  cor=me->query_cor();
  int1=me->query_int();
  spi=me->query_spi();

  skill=(int)(me->query_skill("fire-blade", 1));
  if( !skill ) skill=(int)(me->query_skill("seventy-two", 1));
  limit=(int)(skill/10);
  if(limit<3)
  {
    return action[random(2)];
  }
  else if(limit<4)
  {
    return action[random(3)];
  }
  else if(limit<5)
  {
    return action[random(4)];
  }
  else if(limit<6)
  {
    return action[random(5)];
  }
  else if(limit<7)
  {
    return action[random(6)];
  }
  else if(limit<8)
  {
    return action[random(7)];
  }
  else if(limit<9)
  {
    return action[random(8)];
  }
  else if(limit<10)
  {
    return action[random(10)];
  }
  else
  {
    return action[random(12)];
  }
}

int valid_learn(object me)
{
  object ob;
  if((int)me->query("max_force",1)<1000)
    return notify_fail("你的內力不夠，不能練燃木刀法。\n");
//  if((string)me->query_skill_mapped("force")!= "woodforce")
//    return notify_fail("燃木刀法必需配合木訣心法才能用。\n");
  if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="blade")
    return notify_fail("你必須有刀才能練刀法。\n");
  return 1;
}

int valid_enable(string usage)
{
  return usage=="blade" || usage=="parry";
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
  int a,lv;
  if( !me || !victim ) return;
  lv=(int)(me->query_skill("fire-blade", 1));
  if( !lv ) lv=(int)(me->query_skill("seventy-two", 1));
  if( lv >= 80 ) { a=7; }
  else a=4;
  switch(random(a))
  {
    case 0:
      damage = 4*(str+cor)+cps+kar+spi+int1;
      message_vision(sprintf(HIW"\n$N確實命中$n要害，$n頓時血流滿地。\n"NOR),me,victim);
      victim->receive_damage("kee",damage);
      COMBAT_D->report_status(victim);
      break;
    case 1:
      message_vision("$N暗運丹田急欲搶攻，卻被$n看破，只好棄攻為守。\n",me,victim);
      break;
    case 2:
      message_vision(sprintf(HIW"\n$N的一記強攻使$n攻勢慢了下來。\n"NOR),me,victim);
      victim->start_busy(random(2)+1);
      COMBAT_D->report_status(victim);
      break;
    case 3:
      message_vision("$N見$n氣息錯亂，見機搶攻，卻被$n看破，無攻而反。\n",me,victim);
      break;
    case 4:
      damage=4*(cps+int1)+str+cor+kar+spi;
      message_vision(HIW"\n$N故作破綻，讓$n搶攻，趁搶攻之時，左指反伸而點，化去了$n大半真氣。\n"NOR,me,victim);
      if(victim->query("force",1)>0)
      { victim->add("force",-(victim->query("force",1)/2)); }
      victim->add("kee",-damage);
      COMBAT_D->report_status(victim);
      break;
    case 5:
      message_vision("$N運轉氣勁，卻無法即時吐吶，不得不暫緩攻勢。\n",me,victim);
      break;
    case 6:
      message_vision(sprintf(HIW"\n$N運起十成功\力，運行於身上各大穴，準備伺機給$n極大傷害。\n"NOR),me,victim);
      me->set_temp("addpower",1);
      break;
  }
}
