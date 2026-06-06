//天水一字槍法 by frequency
#include <ansi.h>
#include <combat.h>
void busy(object me,object victim,object weapon,int damage);
void sp1(object me,object victim,object weapon,int damage);
void sp2(object me,object victim,object weapon,int damage);
void berserk(object me,object victim,object weapon);
inherit SKILL;

string *parry_msg=({
        "$n兩手將槍平舉，$w將$N的殺招往頂上一格，盡數盪了開去。\n",
        "$n手中的$w舞成一個槍花，槍上勁力將$N的殺招牽引得歪歪斜斜，失去準頭。\n",
        "$n丈著長槍之利，在猛招臨頭的一刻驟然刺向$N，後發先至，逼得他不得不撤招!\n",
        });

mapping *action = ({
        ([
                "action"     :
"$N使出" + HIC + "天水一字槍法" + NOR + "起手式" + HIR + "「" + HIC + "天水各一方" + HIR + "」" + NOR + "，倒轉手中$w向$n掃去，招式大開大闔，
若遭掃中極有可能當場昏厥，逼得$n不得不運起最高功\力全心抵擋，\n",
                "dodge"      :                -200,
                "damage"     :                250,
                "damage_type":               "內傷",
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N勁貫$w，使出" + HIC + "天水一字槍法" + NOR + "中的" + HIR + "「" + HIC + "氣撼九重天" + HIR + "」" + NOR + "，$w槍尖發出驚人嗤嗤聲響，
當者披靡，$n不敢正面接招，只能左閃右躲，好不狼狽。\n",
                "dodge"      :                -200,
                "damage"     :                260,
                "damage_type":               "刺傷",
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N使出" + HIC + "天水一字槍法" + HIR + "「" + HIW + "水襲浪千重" + HIR + "」" + NOR + "，手中$w激烈震盪，舞出飄忽不定的槍花，
$n完全無法預知$w下一刻將瞄準自己身上的哪個部位。\n",
                "dodge"      :               -200,
                "damage"     :                265,
                "damage_type":               "刺傷",
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N使出" + HIC + "天水一字槍法" + NOR + "之" + HIR + "「" + BBLU+HIW + "銀星耀長天" + NOR + "" + HIR + "」" + NOR + "，挾著無匹內勁的$w如流星般劃破長空，
，在天上留下一道耀眼槍影，$n雙目無法睜開，因而看不清楚槍頭走勢...\n",
                "dodge"      :                -200,
                "damage"     :                280,
                "damage_type":                "札傷",
                "post_action":  (:sp2:),
         ]),
         ([
                "action"     :
"$N使出" + HIC + "天水一字槍法" + NOR + "之" + HIW + "「" + HIG + "反客為主" + HIR + "」" + NOR + "，突然將$w插在地上，就在$n感到困惑之時，
$N身形暴起，竟捨長槍而以腿法攻敵，$n登時險像迭生。\n",
                "dodge"      :                -200,
                "damage"     :                250,
                "damage_type":                "踹傷",
                "post_action":  (:sp2:),
         ]),
         ([
                "action"     :
"$N使出" + HIC + "天水一字槍法" + NOR + "之" + HIR + "「" + HIG + "水動風雲變" + HIR + "」" + NOR + "，槍尖如風，捉摸不定。槍桿如雲，柔似流水，
這飄忽無定的陰柔極招，自四面八方，密密麻麻的包圍住$n。\n",
                "dodge"      :                -200,
                "damage"     :                300,
                "damage_type":                "割傷",
                "post_action":  (:sp2:),
         ]),
         ([
                "action"     :
"$N一聲清嘯，使出" + HIC + "天水一字槍法" + NOR + "之" + HIR + "「" + BLINK+HBBLU+HIY + "天水月流轉" + NOR + "" + HIR + "」" + NOR + "，槍影舞成數不清的槍花，
駭人攻勢如怒濤席捲、如巨浪無盡，殺招一個接一個降臨，看得$n腿都軟了。\n",
                "dodge"      :                -240,
                "damage"     :                300,
                "damage_type":                "札傷",
                "post_action":  (:berserk:),

         ]),
        ([
                "action"     :
"$N手中$w槍尖直指$n，使出" + HIC + "天水一字槍法" + NOR + "之" + HIR + "「" + HIG + "殊途同歸" + HIR + "」" + NOR + "，$w順著$n招式遞了上去，
看似要與$n同歸於盡，然而佔著兵器之長，竟能後發先至，槍尖早一步送上$n$l。\n",
                "dodge"      :                -220,
                "damage"     :                300,
                "damage_type":               "刺傷",
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N眼中精神大振，使出" + HIC + "天水一字槍法" + NOR + "中的" + HIR + "「" + HIW + "浪捲無盡槍" + HIR + "」" + NOR + "，千重槍花，逼使$n忙於格檔，
卻盡是虛招，待得$n筋疲力盡之時，才一槍直朔而出，$n哪裡還有多餘氣力接招。\n",
                "dodge"      :               -280,
                "damage"     :                320,
                "damage_type":               "刺傷",
                "post_action":  (:berserk:),
        ]),
        ([
                "action"     :
"$N突然使出" + HIC + "天水一字槍法" + NOR + "之" + HIR + "「" + BLINK+BBLU+HIW + "天風捲千鈞" + NOR + "" + HIR + "」" + NOR + "，手中$w以槍桿中點為圓心不住旋轉，
激起的風暴迫使$n步法紊亂，勉強攻上也立遭槍影彈回，更可怕的，是這旋轉的槍影仍
步步逼近，攻防一體的戰陣，將$n逼至毫無還手之力的境地。\n",
                "dodge"      :                -300,
                "damage"     :                400,
                "damage_type":               "掃傷",
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N手中$w朝天一指，" + HIC + "天水一字槍法" + NOR + "之" + HIR + "「" + HIW + "天光流水映" + HIR + "」" + NOR + "使槍尖反射了日月之光，
發出一道攝人寒光飛向$n，刺得他雙眼灼痛異常，無法視物，待好不容易睜開眼皮時，
卻只見$w槍頭幾乎已刺進自己的$l\n",
                "dodge"      :                -300,
                "damage"     :                350,
                "damage_type":               "貫體槍傷",
                "post_action":  (:busy:),
        ]),
        ([
                "action"     :HIM + "$N喃喃唸道：" + HIB + "『 " + HIY + "曳槍無巧工  重勁透戟鋒  疾如天光閃  勢如浪無窮 " + HIB + "』" + NOR + "

      " + HIR + "看  極殺之招     
    --------------------" + HIG + "「 " + HIW+BLINK+BBLU + "天水一字槍" + NOR + "" + HIG + " 」" + NOR + "--------------------

       " + HIB + "一道耀眼寒光在$n眼前劃過。
\n",
                "dodge"      :                -480,
                "damage"     :                700,
                "damage_type":               "貫體槍傷",
                "post_action":  (:sp1:),
        ]),
});
int valid_learn(object me)
{
        return 1;
}
int valid_enable(string usage)
{
        return (usage=="lance" || usage=="lance");
}
mapping query_action(object me, object weapon)
{
                return action[random(sizeof(action))];
}


void busy(object me,object victim, object weapon,int damage)
{
 if(!me->query_temp("conti"))
 {
  message_vision(HIR + "\n$N竭力抵擋攻擊，消耗了非常驚人的內力，一時無法平息紊亂的內息。\n" + NOR,victim);
  victim->start_busy(1);
  victim->add("force",-1000);
  COMBAT_D->report_status(victim);
  if(random(3)!=1) COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
 }
}
void sp1(object me, object victim, object  weapon, int damage)
{
   message_vision(HIW + "\n$N以為$n攻勢去盡之際，追上正想反擊，誰料得$n一式『迴天長槍破』轉身就是一輪猛刺。\n" + NOR,victim,me);
   victim->receive_damage("kee",(victim->query("kee")/10),me);
   victim->receive_wound("kee",(victim->query("kee")/10),me);
   COMBAT_D->report_status(victim);
   if(random(3)!=1) COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void sp2(object me, object victim, object  weapon, int damage)
{
 int time,hurt,i;
 time = me->query_skill("water-lance",1);
 time = time/10;
 hurt = victim->query("max_kee");
 hurt = 2*(sqrt(hurt));
  if(!me->query_temp("conti"))
  {
    if(random(100) < 30 &&  weapon->query("id")=="sky-water-lance")
    {
      message_vision(sprintf(HIY + "\n$N冷笑道：" + HIB + "『" + HIW + "在" + HIG + "<<" + HIC + "雨散" + HIR + "梨花" + HIG + ">>" + HIW + "之下，任何人都休想活命，死吧!!!" + HIB + "』\n\n" + NOR),me);
      for(i=0;i<time;i++)
      {
       message_vision(sprintf(HIM + "$N手中"+weapon->query("name")+"" + HIM + "迅速晃動，舞成片片梨花，煞是好看!!，$n渾然不知已身中數槍。\n" + NOR),me ,victim);
       victim->receive_wound("kee",hurt,me);
       COMBAT_D->report_status(victim);
      }
     message_vision(sprintf(HIW + "\n$N盡使雨散梨花之後，消耗不少內力。\n\n" + NOR), me);
     me->add("force",-1000);
    }
   }
}

void berserk(object me,object victim,object weapon)
{
 int i,j;
 j = me->query_skill("water-lance",1);
 j = j/10;
 j = random(j);
 j = 1 + j;
 if(!victim) return;
 if(!me->is_fighting() || !victim->is_fighting())   return;
 if(!me->query_temp("conti"))
 {
   message_vision(RED + "$N戰意達到前所未有的巔峰，殺招一個又一個湧出，層出不窮。\n" + NOR,me,victim);
   me->set_temp("conti",1);
   for(i=0;i<j;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
   me->delete_temp("conti");
   me->add("force",-500);
   me->start_busy(1);
 }
}
