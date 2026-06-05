// 由於加上 killup 所以付出的也要大 by swy

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

array *action = ({
//1
       ([    "action" :
"$N縱身而上，身形一轉，使出" + HIW + "狂龍八斬" + NOR + "之" + HIR + "「迴龍逆斬」" + NOR + "，手中$w往$n橫劈過去。",
             "dodge"  :       -10,
             "parry"  :       -30,
             "damage" :       200,
             "force"  :       200,
             "damage_type": "砍傷",
        ]),
//2
       ([    "action" :
"$N運氣於$w，一招" + HIW + "狂龍八斬" + NOR + "之" + HIR + "「江山易手」" + NOR + "刀氣雄霸，直逼$n。",
             "dodge" :   -10,
             "parry" :   -30,
             "damage" :  200,
             "force"  :  200,
             "damage_type" :   "砍傷",
         ]),
//3
        ([   "action" :
"$N運起元功\，將真力貫注$w，一招" + HIW + "狂龍八斬" + NOR + "之" + HIG + "「呼龍嘯天」" + NOR + "直劈$n。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         200,
             "force"  :         200,
             "damage_type":  "砍傷",
        ]),
//4
        ([   "action" :
"$N手中$w連劃，一招" + HIW + "狂龍八斬" + NOR + "之" + HIG + "「夜龍一炬」" + NOR + "忽地挺出直砍$n。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         250,
             "force"  :         250,
             "damage_type":  "砍傷",
        ]),
//5
        ([   "action" :
"$N一招" + HIW + "狂龍八斬" + NOR + "之" + HIY + "「萬劫盡捨」" + NOR + "手中$w舞成一片刀網，籠罩$n。",
             "dodge"  :        -10,
             "parry"  :        -30,
             "damage" :        250,
             "force"  :        250,
             "damage_type":  "砍傷",
        ]),
//6
        ([   "action" :
"$N揮動手中刀刃，使出" + HIW + "狂龍八斬" + NOR + "之" + HIB + "「一字刀法」" + NOR + "只見$w像一道閃電，直劈而下。",
             "dodge"  :       -10,
             "parry"  :       -30,
             "damage" :       250,
             "force"  :       250,
             "damage_type":  "砍傷",
        ]),
//7
        ([   "action" :
"$N使出" + HIW + "狂龍八斬" + NOR + "之" + HIM + "「離刀旋斬」" + NOR + "，只見$w像白雪般紛紛落下。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         300,
             "force"  :         300,
             "damage_type":  "砍傷",
        ]),
//8

        ([      "action":
"$N持$w一揚，使出" + HIW + "狂龍八斬" + NOR + "之" + HIC + "「亢龍有悔」" + NOR + "，刀勢萬鈞，劈向$n。",
                "dodge":  -10,
                "parry":  -30,
                "damage": 300,
                "force":  300,
                "damage_type":  "劈傷",
        ]),
//9
        ([      "action":
"$N使出狂龍必殺技，" + HIM + "【蟠龍鎖關】" + HIY + "『忌天～～～恨地～～～魚龍再現』\n" + NOR + "拋起$w，空中轉體三周半，氣勢磅礡。",
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "post_action":  (: sp_att3 :),
                "damage_type":  "砍傷",
        ]),
//10
       ([      "action" :
"$N使出狂龍連舞擊，" + HIM + "【魔性六斬】" + HIY + "『驚天～～～滅地～～～血花紛飛』\n" + NOR + "手中$w在炙空下舞動，織成一道刀網。",
               "dodge":         -10,
               "parry":         -30,
               "damage":        350,
               "force":         350,
               "post_action":  (: movedown :),
               "damage_type":   "砍傷",
        ]),
//11
       ([      "action" :
"$N突然陷入瘋狂，口中大喊，" + HIM + "【蒼天已死～魔刀當立～看攝魂屠仙大法】" + NOR + "只見$N\n"
"以$w指向$n的傷口，凌空吸取$n的鮮血！",
                "dodge" :       -10,
                "parry" :       -30,
                "damage":       350,
                "force" :       350,
                "post_action":  (: suck :),
                "damage_type":  "砍傷",
        ]),
//12
       ([ "action" :
"$N聚集九天之氣，使出[35m【三斬歸元～邪龍斬元】[0m\n"
"[1;32m．．．[1;37m『" + HIY + "魔" + HIC + "龍" + HIY + "嗜" + HIC + "血" + HIW + "～～" + HIR + "焚" + HIW + "天" + HIB + "邪" + HIC + "月" + HIW + "』[1;32m．．．[0m\n"
"$n驚愕之於，只見$N把$w插於地上，唸起秘咒，瞬時火燄歕張\n"
"淹漫整個天際。",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: dragon :),
"damage": 400,
"damage_type": "燒傷",
]),
//13
([ "action" :
"$N運用九地之氣，使出[35m【三斬歸元～魚龍嗜元】[0m\n"
"[1;32m．．．[1;37m『" + HIY + "魚" + HIC + "龍" + HIY + "毒" + HIC + "鴆" + HIW + "～～" + HIY + "煌" + HIM + "嵐" + HIG + "叢" + HIR + "滅" + HIW + "』[1;32m．．．[0m\n"
"祕咒語音猶在耳，霎那間，從$w竄出九彩煙霧，瞬時邊旁周圍的生物死之殆盡。",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: sp_att1 :),
"damage": 400,
"damage_type": "毒傷",
]),
//14
([ "action" :
"$N施展九人之氣，使出[35m【三斬歸元～雪影化元】[0m\n"
"[1;32m．．．[1;37m『" + HIY + "狂" + HIC + "龍" + HIY + "怒" + HIC + "震" + HIW + "～～" + HIC + "雪" + HIM + "影" + HIB + "寒" + HIC + "霜" + HIW + "』[1;32m．．．[0m\n"
"$N運起真元，手持$w往天一揮，頓時，山搖地動，風雲變色，以擾亂了\n"
"四季的運轉，蒼天突然地飄下漫天雪彩。",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: sp_att2 :),
"damage": 400,
"damage_type": "凍傷",
]),
});

mapping query_action(object me, object weapon)
{
  int skill, limit, f;
  object victim;

  kar=me->query_kar();
  cps=me->query_cps();
  str=me->query_str();
  cor=me->query_cor();
  int1=me->query_int();
  spi=me->query_spi();

  skill=(int)(me->query_skill("dragon-blade", 1));
  limit=(int)(skill/10);
  f=random(6);
  victim=offensive_target(me);
  if(random(100)>=70&&me->query("combat_exp")>200000 && victim) {
    message_vision(HIW+@LONG

                    ◥▇◣                        ◥▇◣
                      ◥▇◣========================◥▇◣
========================◥▇◣========================◥▇◣
==========================▇▇==========================▇▇
========================◢▇◤========================◢▇◤
                      ◢▇◤========================◢▇◤
                    ◢▇◤                        ◢▇◤

LONG +NOR,me);
    message_vision(HIY + "$N大喝一聲發出雙刀氣，刀氣雄霸貫穿$n而過。\n" + NOR,me,victim);
    victim->receive_wound("kee",300,me);
    COMBAT_D->report_status(victim);
  }
  if((me->query("family/family_name")=="魔刀門"||me->query("family/family_name")=="魔刀莫測")&&
      me->query("m_blade")&&me->query("env/get_mblade")&&me->query("combat_exp")>3000000)
  {
    if(limit==12)
    {
      if(me->query_temp("mblade")==1) {
        return action[13];
      // 暫時先改這樣，不過我猜會少一招
      }
      if(me->query_temp("mblade2")==1) {
        return action[12];
      }
      if(me->query_temp("mblade3")==1) {
        return action[11];
      }
      if((int)me->query("force")>2000)
      {
        if(f>3) return action[random(3)+11];
        return action[random(3)+8];
      }
      if((int)me->query("force")>1500)
      {
        if(f>3) return action[random(2)+11];
        return action[random(3)+8];
      }
      if((int)me->query("force")>1000)
      {
        if(f>3) return action[random(1)+11];
        return action[random(3)+8];
      }
    }
  }
  if(limit<4)
  {
    return action[random(3)];
  }
  if(limit<5)
  {
    return action[random(4)];
  }
  if(limit<6)
  {
    return action[random(5)];
  }
  if(limit<7)
  {
    return action[random(6)];
  }
  if(limit<8)
  {
    return action[random(7)];
  }
  if(limit<9)
  {
    return action[random(9)];
  }
  if(limit<10)
  {
    return action[random(10)];
  }
  if(limit<11)
  {
    return action[random(10)];
  }
  if(limit<12)
  {
    return action[random(11)];
  }
  else
  {
    return action[random(11)];
  }
}

void suck(object me, object victim, object weapon, int damage)
{
  if(70>=random(100)&&me->query("force_factor",1)>=10&&me->query_temp("conti")==0
      && me->query("bellicosity")>11)
  {
    victim->receive_wound("kee",400,me);
    me->receive_curing("kee",400);
    me->receive_heal("kee",400);
    me->add("bellicosity",-10);
    victim->apply_condition("blade",3);
    COMBAT_D->report_status(victim);
    me->add("force",-70);
  } else
    message_vision(sprintf("結果$N的妖術被$n破解。\n"),me,victim);
}

void movedown(object me, object victim, object weapon, int damage)
{
  int i,bell;
  bell=me->query("bellicosity",1)/300;
  if(bell < 1) bell=1;
  if(bell > 6) bell=6;
  if(70>=random(100)&&me->query("force_factor",1)>=5&&me->query_temp("conti")==0
      && me->query("env/魔性六斬")&& me->query("bellicosity")>11)
  {
    for(i=1;i<=bell;i++)
    {
      switch(i)
      {
        case 1:
          message_vision(sprintf("$N使出魔性六斬之" + HIR + "『快』" + NOR + "，手中刀刃斬向$n的胸膛。\n"),me,victim);
          break;
        case 2: 
          message_vision(sprintf("$N使出魔性六斬之" + HIG + "『狠』" + NOR + "，手中刀刃斬向$n的下陰。\n"),me,victim);
          break;
        case 3:
          message_vision(sprintf("$N使出魔性六斬之" + HIY + "『準』" + NOR + "，手中刀刃斬向$n的眼睛。\n"),me,victim);
          break;
        case 4:
          message_vision(sprintf("$N使出魔性六斬之" + HIM + "『空』" + NOR + "，手中刀刃斬向$n的手腕。\n"),me,victim);
          break;
        case 5:
          message_vision(sprintf("$N使出魔性六斬之" + HIB + "『破』" + NOR + "，手中刀刃斬向$n的足踝。\n"),me,victim);
          break;
        case 6: 
          message_vision(sprintf("$N使出魔性六斬之" + HIC + "『滅』" + NOR + "，手中刀刃斬向$n的頸子。\n"),me,victim);
          break;
     }
     message_vision(sprintf(HIW + "$N確實命中$n要害，$n頓時血流滿地。\n" + NOR),me,victim);
     victim->receive_wound("kee",140,me);
     COMBAT_D->report_status(victim);
    }
    if(!me->query_temp("six-hurt")) {
      me->start_busy(1);
    }
    me->add("force",-70);
    me->add("bellicosity",-10);
    victim->apply_condition("blade",3);
  } else
    message_vision(sprintf("結果$N的魔性不夠使不出來。\n"),me,victim);
}

int valid_learn(object me)
{
  object ob;
  if((int)me->query("max_force")<100)
    return notify_fail("你的內力不夠，不能練狂龍刀法。\n");
  if((string)me->query_skill_mapped("force")!= "powerforce")
  return notify_fail("狂龍刀法必需配合玄陽神功\才能用。\n");
  if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="blade")
    return notify_fail("你必須有刀才能練刀法。\n");
  return 1;
}

int valid_enable(string usage)
{
  return usage=="blade" || usage=="parry";
}

string perform_action_file(string action)
{
  return CLASS_D("blademan") + "/dragon-blade/" + action;
}

void dragon(object me, object victim, object weapon, int damage)
{
  if(me->query_temp("mblade3")==1) {
    me->set_temp("mblade3",0);
  }
  if(me->query("bellicosity")<21) return;
  if(me->query("env/邪刀連擊")) {
    if(weapon->query("id")=="shi-blade" || (weapon->query("id")=="evil-mblade" &&
        weapon->query("mblade-mark")))
    {
      string acti;
      mapping do_action;
      object enemy,weaponn;
      int j,force,bell,dak,das,dag;
      force=me->query("force",1);
      enemy=offensive_target(me);
      bell=me->query("bellicosity",1);
      if(bell>=9000&&force>700&&me->query_temp("conti")==0)
      {
        message_vision(sprintf(HIM + "
$N運起三斬歸元功\，只見$N整個人充滿戾氣，舉刀向$n連砍而來！\n" + NOR),me,enemy);
        me->set_temp("conti",1);
        for(j=0; j < 14; j++) {
          do_action=action[j];
          acti = "\n";
          acti += do_action["action"];
          if(weaponn=me->query_temp("weapon") )
            acti=replace_string(acti, "$w", weaponn->name());
          message_vision(acti, me, enemy);
          if(random(me->query("combat_exp"))>random(enemy->query("combat_exp"))/10) {
            message_vision(HIR + "\n$N閃躲不過，身上頓時多了一道傷及見骨的刀痕。\n" + NOR,enemy);
            dak=enemy->query("max_kee")/30;
            if(dak > 160) dak=160;
            das=enemy->query("max_sen")/30;
            if(das > 100) das=100;
            dag=enemy->query("max_gin")/30;
            if(dag > 100) dag=100;
            enemy->receive_wound("gin",dag,me);
            enemy->receive_wound("kee",dak,me);
            enemy->receive_wound("sen",das,me);
            me->add("force",-20);
            COMBAT_D->report_status(enemy);
          }
          else message_vision("\n$N運功\一躍，驚險地閃過了這一刀招。\n" , enemy);
        }
        if(random(me->query_cps()) < 6 )
        {
          message_vision("\n$N體內殺氣湧上膻中無以聚力，只好釋放些許\。\n",me);
          me->start_busy(1);
          me->add("bellicosity",-20);
        }
        me->delete_temp("conti");
      }
    } else {
      int sp_1=4*(cps+kar)+str+cor+spi+int1;
      int bell=me->query("bellicosity")/500;
      if(bell < 1) bell=1;
      if(bell > 8) bell=8;
      for(i=1;i<=bell;i++)
      {
        message_vision(HIW + "你祭起刀刃，氣沉丹田，流暢快意的施展狂龍刀法！\n" + NOR,me,victim);
        switch(i)
        {
          case 1:
            message_vision(sprintf("$N使出第一式『" + HIC + "迴龍逆斬" + NOR + "』斬向$n。\n"),me,victim);
            break;
          case 2:
            message_vision(sprintf("$N使出第二式『" + HIC + "江山易手" + NOR + "』斬向$n。\n"),me,victim);
            break;
          case 3:
            message_vision(sprintf("$N使出第三式『" + HIC + "呼龍嘯天" + NOR + "』斬向$n。\n"),me,victim);
            break;
          case 4:
            message_vision(sprintf("$N使出第四式『" + HIC + "夜龍一炬" + NOR + "』斬向$n。\n"),me,victim);
            break;
          case 5:
            message_vision(sprintf("$N使出第五式『" + HIC + "萬劫盡捨" + NOR + "』斬向$n。\n"),me,victim);
            break;
          case 6:
            message_vision(sprintf("$N使出第六式『" + HIC + "一字刀法" + NOR + "』斬向$n。\n"),me,victim);
            break;
          case 7:
            message_vision(sprintf("$N使出第七式『" + HIC + "離刀旋斬" + NOR + "』斬向$n。\n"),me,victim);
            break;
          case 8:
            message_vision(sprintf("$N使出第八式『" + HIC + "亢龍有悔" + NOR + "』斬向$n。\n"),me,victim);
            break;
        }
        victim->receive_wound("kee",sp_1/2,me);
        message_vision(sprintf(HIR + "$n露出破綻，被刀刃直斬要害，鮮血直流。\n" + NOR),me,victim);
        COMBAT_D->report_status(victim);
      }
      me->add("force",-50);
      me->add("bellicosity",-20);
      me->start_busy(1);
    }
  }
  victim->apply_condition("blade",5);
}

void sp_att1(object me, object victim, object weapon, int damage)
{
  int sp_2 = 4*(str+cor)+cps+kar+spi+int1;
  if(me->query_temp("mblade2")==1) {
    me->set_temp("mblade2",0);
    me->set_temp("mblade3",1);
  }
  if(me->query("bellicosity")<21) return;
  if(weapon->query("id")=="ublade" || (weapon->query("id")=="evil-mblade" &&
      weapon->query("mblade-mark")))
  {
    message_vision(HIY + "你吸收滿天毒霧運氣於刀，霎那間手中刀刃散發出驚人駭毒，籠罩四方。\n" + NOR,me,victim);
    message_vision(sprintf(HIB + "$n臉色發黑，似乎中了劇毒。\n" + NOR),me,victim);
    victim->receive_wound("kee",sp_2*2,me);
    victim->apply_condition("blade",7);
    victim->apply_condition("u-stial",7);
    victim->start_busy(1);
    COMBAT_D->report_status(victim);
    me->add("force",-120);
  }
  else
  {
    if(me->query_temp("conti")==0) {
      message_vision(HIY + "你運氣於刀，暗使真元，只見刀騰空飛出，直奔$n的胸膛。\n" + NOR,me,victim);
      victim->receive_wound("kee",sp_2,me);
      victim->apply_condition("blade",7);
      COMBAT_D->report_status(victim);
      me->add("force",-60);
    }
  }
  me->add("bellicosity",-20);
}

void sp_att2(object me, object victim, object weapon, int damage)
{
  int sp_3 = 4*(kar+int1)+2*str+cor+cps+spi;
  if(me->query_temp("mblade")==1) {
    me->set_temp("mblade",0);
    me->set_temp("mblade2",1);
  }
  if(me->query("bellicosity")<21) return;
  if(weapon->query("id")=="iceblade" || (weapon->query("id")=="evil-mblade" &&
      weapon->query("mblade-mark")))
  {
    message_vision(HIC + "手中刀刃，似有似無，編織漫天雪彩，只見$n困在其中。\n" + NOR,me,victim);
    victim->start_busy(1);
    victim->receive_wound("kee",sp_3*2,me);
    victim->apply_condition("blade",9);
    COMBAT_D->report_status(victim);
    me->add("force",-150);
  }
  else
  {
    if(me->query_temp("conti")==0) {
      message_vision(HIC + "漫天雪彩，只見$n看的失魂，已被刀刃所傷。\n" + NOR,me,victim);
      victim->receive_wound("kee",sp_3,me);
      victim->apply_condition("blade",9);
      COMBAT_D->report_status(victim);
      me->add("force",-75);
    }
  }
  me->add("bellicosity",-20);
}

void sp_att3(object me, object victim, object  weapon, int damage)
{
  int sk_lv;
  sk_lv = me->query_skill("dragon-blade",1);
  if(sk_lv>=105&&me->query_temp("conti")==0&&me->query("bellicosity")>11
      &&70>=random(100)&&me->query("force",1)>70&&me->query("have_book",1))
  {
    message_vision(sprintf(HIR + "
突然$N眼露紅光向天怒吼，狂暴運起元功\，使出魔刀失傳之奧義" + HIW + "『盧山不動一劍痕』\n" + NOR),me,victim);
message_vision(sprintf(HIB + "$N揮著刀刃，順著四季的運轉，向$n砍出『春雨』『夏夜』"+
"『秋風』『冬雪』\n" + HIY + "$n被這股狂霸刀氣震嚇住，一瞬間$n身上已留下深及見骨的四道傷痕\n\n" + NOR),me,victim);
    victim->receive_wound("kee",400,me);
    victim->start_busy(1);
    victim->apply_condition("blade",3);
    COMBAT_D->report_status(victim);
    me->add("force",-50);
    me->add("bellicosity",-10);
  }
}
