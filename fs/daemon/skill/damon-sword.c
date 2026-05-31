//調整skill 為了整合在seventy-two中 與判斷使用者或被攻擊方是否存在的判斷 by blazakira 2010/10/20

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void movedown(object me, object victim, object weapon, int damage);
void sp_att3(object me, object victim, object  weapon, int damage);
void dragon(object me, object victim, object weapon, int damage);
void suck(object me, object victim, object weapon, int damage);
void sp_att1(object me, object victim, object  weapon, int damage);
void sp_att2(object me, object victim, object  weapon, int damage);
int kar,cps,str,cor,int1,spi;
int i;

mapping *action = ({
//1
  (["action"     : "$N縱身而上，身形一轉，使出"HIR"「一葦渡江」"NOR"，手中$w如直線般往$n直刺過去。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 110,
    "force"      : 160,
    "damage_type": "刺傷",
  ]),
//2
  (["action"     : "$N運氣於$w，一招"HIR"「臥山觀雲」"NOR"從四方起招，氣勢雄霸，直壓四方。", //四方劍起，劍氣雄霸
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 120,
    "force"      : 160,
    "damage_type": "刺傷",
  ]),
//3
  (["action"     : "$N運起元功\，將真氣貫注$w，一招"HIY"「冉冉風塵」"NOR"有如看破紅塵般直破$n。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 130,
    "force"      : 160,
    "damage_type": "創傷",
  ]),
//4
  (["action"     : "$N手中$w以慢制快，一招"HIY"「披星戴月」"NOR"忽地挺出直搗$n。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 140,
    "force"      : 160,
    "damage_type": "創傷",
  ]),
//5
  (["action"     : "$N一招"HIG"「為山千仞」"NOR"手中$w從四方八落飛舞形成一片密密麻麻的網，籠罩四方。", //一片劍網
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 150,
    "force"      : 160,
    "damage_type": "劈傷",
  ]),
//6
  (["action"     : "$N揮動手中$w使出"HIG"「江流石轉」"NOR"只見$w不轉、招不轉、人轉，使$w直搗要害。", //劍不轉
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 160,
    "force"      : 160,
    "damage_type": "劈傷",
  ]),
//7
  (["action"     : "$N使出"HIM"「七步蓮花」"NOR"，只見$w快似閃電已在$n身上留下七道傷痕。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 170,
    "force"      : 160,
    "damage_type": "割傷",
  ]),
//8

  (["action"     : "$N持$w一揚，使出"HIM"「捻花笑佛」"NOR"，氣勢萬鈞，似柔似軟無勁的劈向$n。", //劍勢萬鈞
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 180,
    "force"      : 160,
    "damage_type": "割傷",
  ]),
//9
  (["action"     : "$N使出達摩第九式，"HIB"【苦海無涯～回頭是岸】"NOR"，拋棄一切招式，讓$w自由帶動，以繁化簡。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 190,
    "force"      : 160,
    "post_action":  (: call_other,__FILE__,"sp_att3" :),
    "damage_type": "砍傷",
  ]),
//10
  (["action"     : "$N使出達摩第十式，"HIB"【集思成智～水到渠成】"NOR"，手中$w蘊含無比的內勁直撩$n。",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 200,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"movedown" :),
    "damage_type": "砍傷",
  ]),
//11
  (["action"     : "$N眼見$n陷入瘋狂，手中$w一橫，使出"HIC"【滅～魔～去～惡】"NOR"只見\n"
                   "$n躲也不是擋也不是，只覺面前掃過一陣狂風卻已傷及奇筋八脈！",
    "dodge"      : -10,
    "parry"      : -30,
    "damage"     : 220,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"suck" :),
    "damage_type":  "筋脈斷傷",
  ]),
//12
  (["action"     : "$N使出達摩最終式，手中$w一橫一豎，使出"HIC"【道～成～槃～涅】"NOR"猶見\n"
                   "$N身形變幻無形，與$w合一，其形在霎那間，時空凍結，一道幻化人影已衝出$n體外！", //人劍合一
    "dodge"      : -10,
    "parry"      : -30,
    "force"      : 160,
    "post_action": (: call_other,__FILE__,"dragon" :),
    "damage"     : 220,
    "damage_type": "五殘之傷",
  ]),
});

mapping query_action(object me, object weapon)
{
  int skill, limit, f;
  skill=(int)(me->query_skill("damon-sword", 1));
  if( !skill ) skill=(int)(me->query_skill("seventy-two", 1));
  limit=(int)(skill/10);
  f=me->query("bellicosity",1);
  kar=me->query_kar();
  cps=me->query_cps();
  str=me->query_str();
  cor=me->query_cor();
  int1=me->query_int();
  spi=me->query_spi();

// 殺氣越少越強
  if(f< 50 && limit==10){return action[random(4)+8];}
  else if(limit<2){return action[random(2)];}
  else if(limit<3){return action[random(3)];}
  else if(limit<4){return action[random(4)];}
  else if(limit<5){return action[random(5)];}
  else if(limit<6){return action[random(6)];}
  else if(limit<7){return action[random(7)];}
  else if(limit<8){return action[random(8)];}
  else if(limit<9){return action[random(9)];}
  else if(limit<10){return action[random(10)];}
  else{return action[random(12)];}
}

void suck(object me, object victim, object weapon, int damage)
{
  damage = 4*(str+cor)+cps+kar+spi+int1;
  if( !me || !victim || me->query("force",1) < 100 ) return;
  if(70>=random(100)&&me->query("force_factor",1)>=10)
  {
    message_vision(sprintf(HIW"\n$N"HIW"的易筋經內勁已侵入$n體中，正侵蝕著$n"HIW"的奇筋八脈。\n"NOR),me,victim);
    victim->receive_damage("kee",damage,me);
    victim->apply_condition("hart",5);
    COMBAT_D->report_status(victim);
    me->add("force",-80);
  } else
    message_vision(sprintf("結果$N的內勁被$n壓制住了。\n"),me,victim);
}

void movedown(object me, object victim, object weapon, int damage)
{
  int i;
  if( !me || !victim || me->query("force",1) < 100 ) return;
  if(70>=random(100)&&me->query("force_factor",1)>=5&&!me->query_temp("att"))
  {
    message_vision(sprintf(HIW"\n$N"HIW"內勁狂吐，劍劍相連，向$n"HIW"狂攻過去。\n"NOR),me,victim);
    me->set_temp("att",1);
    for(i=1;i<=3;i++)
    {
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
    me->add("force",-70);
  } else
    message_vision(sprintf("$N內息吐盡，頓而收招禦敵。\n"),me,victim);
  me->delete_temp("att");
}

int valid_learn(object me)
{
/*
  object ob;
  if((int)me->query("max_force")<2000)
    return notify_fail("你的內力不夠，不能練達摩劍法。\n");
  if((string)me->query_skill_mapped("force")!= "monforce")
    return notify_fail("達摩劍法必需配合摩詞心法才能用。\n");
  if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="sword")
    return notify_fail("你必須有劍才能練劍法。\n");
*/
  return 1;
}

int valid_enable(string usage)
{
  return usage=="sword" || usage=="parry";
}
//此技能沒有per 所以關閉此段 by blazakira
/*
string perform_action_file(string action)
{
  return CLASS_D("bonze") + "/seventy-two/" + action;
}
*/
void dragon(object me, object victim, object weapon, int damage)
{
  if( !me || !victim || me->query("force",1) < 300 ) return;
  if(80>=random(100)&&me->query("force_factor",1)>=10&&!me->query_temp("conti"))
  {
    string acti;
    mapping do_action;
    object *enemy,weaponn;
    int i,j,force,bell,dak,das,dag;
    force=me->query("force",1);
    enemy=me->query_enemy();
    i=random(sizeof(enemy));
    bell=me->query("bellicosity",1);
    message_vision(sprintf(HIW"\n$N"HIW"運起易經心法，人劍合一，暢快的使出達摩劍法！\n"NOR),me,enemy[i]);
    me->set_temp("conti",1);
    for(j=0; j < 12; j++) {
      do_action=action[j];
      acti = "\n";
      acti += do_action["action"];
      if(weaponn=me->query_temp("weapon") )
        acti=replace_string(acti, "$w", weaponn->name());
      message_vision(acti, me, enemy[i]);
      if(random(me->query("combat_exp"))>random(enemy[i]->query("combat_exp"))/10)
      {
        message_vision(HIR"\n$N"HIR"閃躲不過，身上頓時多了一道血跡斑斑的劍痕。\n"NOR,enemy[i]);
        dak=enemy[i]->query("max_kee",1)/20;
        if(dak > 150) dak=150;
        das=enemy[i]->query("max_sen",1)/30;
        if(das > 100) das=100;
        dag=enemy[i]->query("max_gin",1)/30;
        if(dag > 100) dag=100;
        enemy[i]->receive_wound("gin",dag,me);
        enemy[i]->receive_wound("kee",dak,me);
        enemy[i]->receive_wound("sen",das,me);
        me->add("force",-20);
        COMBAT_D->report_status(enemy[i],1);
      }
      else message_vision("\n$N趕緊提起兵刃一架，驚險地架開了這一劍招。\n" , enemy[i]);
    }
    if(random(me->query_cps()) < 7 )
    {
      message_vision("\n$N一連施展完達摩十二式，頓時氣血賁亂只好就地盤坐運氣。\n\n",me);
      me->start_busy(1);
    }
  }
  me->delete_temp("conti");
}

void sp_att3(object me, object victim, object  weapon, int damage)
{
  int sk_lv;
  if( !me || !victim || me->query("force",1) < 70 ) return;
  damage = 4*(kar+int1)+2*str+cor+cps+spi;
  sk_lv = (int)(me->query_skill("seventy-two",1));
  if( sk_lv >= 80 && 70 >= random(100) )
  {
    message_vision(sprintf(HIW"\n$N"HIW"突然領悟到"HIR"『有即是無～無即是有』"HIW"的道理，忘卻一切招式，以無拆招，以無化招"NOR),me,victim);
    message_vision(sprintf(HIW"\n$N"HIW"揮著兵刃，順著敵方的運息，進而見招拆招，一瞬間$n"HIW"破綻百出已受嚴重創傷。\n"NOR),me,victim);
    victim->receive_damage("kee",damage,me);
    victim->start_busy(random(2)+1);
    victim->apply_condition("swordkee",2); //將刀傷改為劍傷 by blazakira
    COMBAT_D->report_status(victim);
    me->add("force",-50);
  }
}
