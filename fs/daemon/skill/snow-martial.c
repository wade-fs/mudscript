// 全新更正修改 by swy 2001/7/22
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void diy(object me, object victim, object weapon, int damage);
void ice(object me, object victim, object weapon, int damage);
mapping *action = ({
//1
 (["action":"$N使出雪蒼武學中的" + HIG + "『盪風勢』" + NOR + "，雙掌一推，勢如疾風暴雨般的一股狂風襲向$n的胸前",

                "dodge":                -30,
                "parry":                -20,
                "force":                 500,
                "damage":                500,
                "damage_type": "瘀傷",

       ]),
//2
(["action":"$N氣運丹田﹐一招" + HIM + "『喚雨勢』" + NOR + "展出無數幽靈掌影往$n各處拍去",

                  "dodge":     -20,
                  "parry":     -30,
                  "force":      500,
                  "damage":     500,
                  "damage_type":     "瘀傷",

                 ]),
//3
(["action":"$N掌勢驚天破雲,使出雪蒼武學之『" + HIW + "排雲掌" + NOR + "』，瞬時將$n的攻勢如流雲般洩去，並在$n的胸前烙下沈重一掌",
                  "dodge":     -20,
                  "parry":     -10,
                  "force":      500,
                  "damage":     500,
                  "damage_type":     "瘀傷",
                  "post_action":               (: diy:),

                 ]),
//4
(["action":"身形一低，一招『" + HIW + "破水勢" + NOR + "』雙拳宛如蛟龍破水而出，蘊含著內勁由下而上往$n頭部暴射而去",
                  "dodge":     -20,
                  "parry":     -30,
                  "force":      500,
                  "damage":     500,
                  "damage_type":     "瘀傷",
                 ]),
//5
(["action":"$N狂喝一聲,一招雪蒼武學之" + HIW + "『掃雪式』" + NOR + "勢如鷹撲捲起萬丈暴雪般擊向$n",
                  "dodge":     -30,
                  "parry":     -30,
                  "force":      500,
                  "damage":     500,
                  "damage_type":     "內傷",

                 ]),

//6
 (["action":"$N施展狂風無影身法轉到$n的身後，反手抓住$n使出雪蒼武學中的" + HIC + "『冰龍墜』" + NOR + "，將$n重重的摔向地上",
                  "dodge":     -30,
                  "parry":     -45,
                  "force":     500,
                  "damage":    500,
                  "damage_type":     "摔傷",
                  "post_action":               (: diy:),

                 ]),
//7
(["action":"$N掌勁一迴，使出一招" + HIC + "『重雲深鎖』" + NOR + "，瞬時將$n的招式緊緊扣住，並以雪蒼內勁硬震$n的內力",
                  "dodge":     -40,
                  "parry":     -70,
                  "force":      500,
                  "damage":     500,
                  "damage_type":    "內傷",

            ]),
//8
 (["action":"$N配合著無影身法，使出" + HIW + "『雲路魅影』" + NOR + "，身影令$n捉摸不定，忽然身形一滯，聚力萬鈞的一掌伺機往$n的$l拍去",

                  "dodge":     -70,
                  "parry":     -40,
                  "force":     500,
                  "damage":    500,
                  "damage_type":     "瘀傷",

                 ]),
//9
(["action":"$N兩掌平推而去，使出雪蒼武學的精華『" + HIB + "崩雲落" + NOR + "』，掌勁所至石屑紛飛，只見$n被強大的內勁壓的喘不過氣",

                  "dodge":     -50,
                  "parry":     -40,
                  "force":     500,
                  "damage":    500,
                  "damage_type":     "內傷",
                  "post_action":               (: diy:),

                 ]),
//10
 (["action":"$N使出雪蒼派的鬼影腳，一招" + HIM + "『陰府求魂』" + NOR + "往$n身上連踢數腳，$n頓時筋折骨裂，鮮血狂噴",

                "dodge":                -65,
                "parry":                -50,
                "force":                500,
                "damage":               500,
                "damage_type":  "瘀傷",
                 ]),
//11
 (["action":"$N使出鬼影腳中的精髓" + HIR + "『風捲殘雲』" + NOR + "身形急旋下右腳如利劍般往$n的$l踢去",
                     "dodge":     -65,
                     "parry":     -60,
                     "force":     500,
                     "damage":    500,
                     "damage_type":    "刺傷",

       ]),
//12
 (["action":"$N使出鬼影腳中的精髓『" + GRN + "寒梅三翦" + NOR + "』腿勢忽變，連環三腿如影隨形而至$n只感到勁風撲面襲來，命懸一線",

                     "dodge":     -65,
                     "parry":     -45,
                     "force":     500,
                     "damage_type":    "瘀傷",
                     "damage":    500,
                     "post_action":               (: diy:),

       ]),
//13
 (["action":"$N腿勢暴起，踢出一招『" + HIB + "浪捲千里" + NOR + "』勁力有如巨浪噬地綿延不絕直把$n逼的連退數十步",

                     "dodge":     -75,
                     "parry":     -75,
                     "force":     500,
                     "damage_type":    "震傷",
                     "damage":    500,

       ]),
//14
 (["action":"$N揉身而起以高制低，打出雪蒼武學之精華『" + HIC + "落雪漫天" + NOR + "』霎時只見漫天強橫掌影如雪花紛飛般壓向$n",

                     "dodge":     -80,
                     "parry":     -75,
                     "force":     500,
                     "damage":    500,
                     "damage_type":    "凍傷",
                     "post_action":               (: ice:),

       ]),
//15
 (["action":"$N使出雪蒼武學之精華『" + HIW + "玄冰掌" + NOR + "』，剎那間$N的四周寒氣襲人，手臂上浮現一層厚冰挾著駭人氣勢擊向$n",

                     "dodge":     -60,
                     "parry":     -70,
                     "force":     500,
                     "damage":    500,
                     "damage_type":    "凍傷",
                     "post_action":               (: ice:),
       ]),

});

void diy(object me, object victim, object weapon, int damage)
{
 int bound,dam;
 bound=(int)me->query_skill("snowforce",1);
 dam=victim->query("max_kee",1)/30;
// if(bound > 250) bound=250;
      if( me->query("force_factor") >= 5 && random(100) > 50)
      {
        if (me->query("force") > bound*2) {

message_vision(HIB + "～雪蒼寒勁～" + NOR + "
" + HIC + "            $N的寒勁一提，使出雪蒼氣勁中之" + NOR + "
"BLINK+HIC + "                －『 凝 霜 勁 』－" + NOR + "
" + HIC + "        拳勢將$n籠罩，周圍氣溫瞬間下降，將$n凝結。\n" + NOR,me,victim);
              victim->receive_damage("kee",(bound+50),me);
              COMBAT_D->report_status(victim);

message_vision(HIC + "～雪蒼冰勁～" + NOR + "
" + HIY + "           $N將內勁往掌上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+HIG + "                 －『 玄 冰 勁 』－" + NOR + "
" + HIY + "        掌上勁力瞬時提升數倍，澎湃的掌勁向$n襲捲而去。\n" + NOR,me,victim);
              victim->receive_wound("kee",(bound+50),me);
              COMBAT_D->report_status(victim);
              me->add("force",-bound*2);

         }
       }
}

void ice(object me, object victim, object weapon, int damage)
{
int bound,age,me_exp;
bound=(int)me->query_skill("snowforce",1);
//if(bound > 250) bound=250;
        if( me->query("force",1) >= 500  &&
        random(100)>50)
           {
message_vision(HIW + "\n$N的寒勁更使得$n的身上結成一層薄冰，造成嚴重凍傷，功\力大減。\n\n" + NOR,me,victim);
              victim->apply_condition("cold",random(15)+1);
              victim->receive_wound("kee",(bound+350),me);
              victim->add("force",-140);
              COMBAT_D->report_status(victim);
              me->add("force",-200);
           }
}


int valid_learn(object me)
{

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") ) {
               write("學雪蒼武學必需空手。\n");
               return 0;
        }
        if(me->query("max_force")<50) {
                write("喂! 小子, 內力上限要 50 喔﹐等你長大點再來。\n");
                return 0;
        }
        if(me->query_skill("snowforce",1)<10) {
                write("你的雪蒼派內功\火候不夠﹐不能練雪蒼武學。\n");
                return 0;
        }
        if(me->query("family/family_name") != "雪蒼派")
        {
               write("只有雪蒼弟子可以學!!!!\n");
               return 0;
           }

        return 1;
}

int valid_enable(string  usage)  {

            return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
 int i,j,k,force,kee,star,skill,bound,dam;
 object victim,*enemy;
 victim = offensive_target(me);
  if(!victim){
    enemy=me->query_enemy();
if(sizeof(enemy))
    victim=enemy[0];
  }

    if(!victim) return action[random(3)];
 dam=victim->query("max_kee",1)/50;
 if(dam > 2500) dam=2500;
 skill=me->query_skill("snow-martial",1);
 bound=skill;
 k=random(100);
//武器特功的部份..by chan
weapon=me->query_temp("weapon");
// 以下是合技的使用過的計號和消除 by swy
if(random(100)>80 && me->query_temp("use-two-power")) {
me->delete_temp("use-two-power");
}
if(weapon)
{
if(me->query("family/family_name")=="雪蒼派" && weapon->query("id")=="figring")
{
 if((skill>90)&&(k>80)&& victim)
  {
message_vision(HIW + "$N手上的" + HIC + "金鋼指環" + HIW + "被$N的雪蒼寒勁所引,$N全身發出數道光茫,變成一隻兇猛的雪虎!!\n" + NOR,me,victim);
message_vision(HIW+@LONG

                       _ __..-;''`--/'/ /.',-`-.
                   (`/' ` |  \ \ \\ / / / / .-'/`,_
                  /'`\ \   |  \ | \| // // / -.,/_,'-,
                 /<7' ;  \ \  | ; ||/ /| | \/    |`-/,/-.,_,/')
                /  _.-, `,-\,__|  _-| / \ \/|_/  |    '-/.;.\'
                `-`  f/ ;      / __/ \__ `/ |__/ |
                     `-'      |  -| =|\_  \  |-' |
                           __/   /_..-' `  ),'  //
                          ((__.-'((___..-'' \__.'

LONG+NOR,me);
message_vision(HIC + "殘暴的巨大雪虎,發出巨大嘯聲!!,對$n展開猛烈的攻擊!!!\n" + NOR,me,victim);
message_vision(HIW + "雪虎快速的揮舞銳利的爪子,$n閃躲不及全身皮綻肉裂!!\n" + NOR,me,victim);
victim->receive_wound("kee",200,me);
COMBAT_D->report_status(victim);
message_vision(HIW + "一道銳利的聲音破空而出,$n被雪虎的尾巴掃到,感覺全身被撕開!!\n" + NOR,me,victim);
victim->receive_wound("kee",200,me);
COMBAT_D->report_status(victim);
message_vision(HIW + "雪虎用銳利的牙咬住了$n的身体,強烈的寒氣從雪虎身上發出讓$n感覺生不如死!!\n" + NOR,me,victim);
victim->apply_condition("cold",random(15)+1);
victim->receive_wound("kee",200,me);
COMBAT_D->report_status(victim);
message_vision(HIY + "奇特的光茫從兇猛的雪虎身上發出,強光過後$N變成了人形了!!\n" + NOR,me);
me->add("force",-250);
}
}
}
if(me->query("force_factor")<80) {
if((me->query("quests/read_snow")==1) && skill >= 70 &&
me->query("family/family_name")=="雪蒼派"&&me->query("force",1) > 500){
if(random(100) > 80 && victim) {
   bound=bound+100;
   message_vision(HIM + "\n\n$N對$n使出了雪蒼武學之絕招 ---『 奪 命 三 掌 』!!\n" + NOR,me,victim);
   victim->apply_condition("cold",random(15)+1);
message_vision(HIC + "\n\n$N使出" + HIW + "奪命三掌第一招" + HIG + "『疾風狂襲』" + HIC + "，雙掌一推，勢如疾風暴雨般的一股狂風襲向$n的胸前\n" + NOR,me,victim);
         victim->receive_damage("kee",bound,me);
         COMBAT_D->report_status(victim);
      bound=bound+100;
message_vision(HIC + "\n\n$N氣運丹田，使出" + HIW + "奪命三掌第二招" + HIM + "『迷蹤亂雪』" + HIC + "展出無數幽靈掌影往$n各處拍去\n" + NOR,me,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim);
      bound=bound+100;
message_vision(HIC + "\n\n$N掌勢驚天排雲，使出雪蒼" + HIW + "奪命三掌最後一招『" + HIC + "奪" + HIW + "命" + HIC + "掌" + NOR + "』" + HIC + "，瞬時將$n的攻勢如雲般洩去，並在$n的胸前烙下沈重一掌\n" + NOR,me,victim);
   victim->receive_wound("kee",dam,me);
         me->add("force",-240);
         COMBAT_D->report_status(victim);
  }
 }

if((me->query("quests/read_snow")==2) && skill >= 70 &&
me->query("family/family_name")=="雪蒼派"&&me->query("force",1) > 500){
  if(random(100) > 80 && victim) {
 message_vision(HIG + "\n\n$N對$n使出了雪蒼武學之絕招 ---『 狂 風 無 影 腳 』!!\n" + NOR,me,victim);
 victim->apply_condition("cold",random(15)+1);
   for(j=1;j<=9;j++)
   {
  switch(1+random(4))
   {
case 1:
message_vision(HIR + "                 －－狂風鬼影腳－－" + NOR + "
" + HIW + "    $N將氣勁一轉，氣勁源源不斷的向腳上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+HIR + "                     ～『 狂 風 勁 』～" + NOR + "
" + HIW + "             $N的腳風如狂風般的腳勢向$n狂襲而去。\n" + NOR,me,victim);
               victim->receive_damage("kee",bound,me);
         me->add("force",-30);
         COMBAT_D->report_status(victim);
break;
case 2:
message_vision(GRN + "                 －－烈風亂影腳－－" + NOR + "
" + HIC + "    $N將內力一放，氣勁源源不斷的向腳上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+GRN + "                    ～『 烈 風 勁 』～" + NOR + "
" + HIC + "             $N的腳如閃電般的腳勢向$n殘踢而去。\n" + NOR,me,victim);
         victim->receive_damage("kee",bound,me);
         me->add("force",-30);
         COMBAT_D->report_status(victim);
break;
case 3:
message_vision(HIB + "                 －－旋風幻影腳－－" + NOR + "
" + HIC + "    $N將內力一收，氣勁源源不斷的向腳上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+HIB + "                    ～『 旋 風 勁 』～" + NOR + "
" + HIC + "             $N的腿順勢一轉由上至下向$n劈踢而去。\n" + NOR,me,victim);
         victim->receive_wound("kee",bound,me);
         me->add("force",-30);
         COMBAT_D->report_status(victim);
break;
case 4:
message_vision(HIY + "                 －－暴風滅影腳－－" + NOR + "
" + HIC + "    $N將內勁暴射，氣勁源源不斷的向腳上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+HIY + "                    ～『 暴 風 勁 』～" + NOR + "
" + HIC + "             $N強橫的內力挾帶著破風之聲向$n猛踢而去。\n" + NOR,me,victim);
           victim->receive_wound("kee",dam,me);
         me->add("force",-30);
         COMBAT_D->report_status(victim);
break;
}
   }
                       }
                       }
if((me->query("quests/read_snow")==3) && skill >= 70 &&
(me->query("family/family_name")=="雪蒼派") && (me->query("force",1) > 500)){
     if(random(100) > 80 && victim){
 message_vision(HIW + "\n\n$N對$n使出了雪蒼武學之絕招 ---『 " + HIY + "枯" + HIB + " 葉" + HIM + " 殘" + HIG + " 星" + HIW + " 掌 』" + NOR + "!!

            " + HIC + "$N體內的寒氣驀然爆發，忽然間一團星狀之真氣快速飛向$n
            剎那間$n的胸前立刻出現了一個紫黑色的傷痕，全身打顫不已!
\n\n" + NOR,me,victim);
     victim->receive_wound("kee",(100+bound*7),me);
     victim->apply_condition("star-stial",random(15)+1);
     me->add("force",-200);
     COMBAT_D->report_status(victim);
                         }
                         }
} else {
if(me->query("family/family_name")=="雪蒼派"&&skill==100&&me->query("force")>1000) {
if(random(100)>85&&victim) {
message_vision(HIW + "\n$N對$n使出了雪蒼武學之奧義 ---『 絕 學 三 連 擊 』---\n\n" + NOR,me,victim);
for(i=1;i<=8;i++) {
switch(i) {
case 1:
message_vision(HIY + "            ---『疾風狂襲』---" + NOR + "
" + HIC + "    $N雙掌一推，勢如疾風暴雨般的一股狂風襲向$n的胸前。\n" + NOR,me,victim);
               victim->receive_damage("kee",180,me);
               me->add("force",-100);
               COMBAT_D->report_status(victim);
break;
case 2:
message_vision(HIM + "            ---『迷蹤亂雪』---" + NOR + "
" + HIC + "    $N展出無數幽靈掌影往$n各處拍去。\n" + NOR,me,victim);
               victim->receive_wound("kee",240,me);
               me->add("force",-100);
               COMBAT_D->report_status(victim);
break;
case 3:
message_vision(HIW + "            ---『" + HIC + "奪" + HIW + "命" + HIC + "掌" + NOR + "』---" + NOR + "
" + HIC + "    $N瞬時將$n的攻勢如雲般洩去，並在$n的胸前烙下沈重一掌。\n" + NOR,me,victim);
               victim->receive_wound("kee",dam,me);
               me->add("force",-100);
               COMBAT_D->report_status(victim);
break;
case 4:
message_vision(HIR + "            ---『狂風鬼影腳』---" + NOR + "
" + HIW + "    $N將氣勁一轉，氣勁源源不斷的向腳上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+HIR + "                     ～『 狂 風 勁 』～" + NOR + "
" + HIW + "             $N的腳風如狂風般的腳勢向$n狂襲而去。\n" + NOR,me,victim);
               victim->receive_damage("kee",180,me);
               me->add("force",-100);
               COMBAT_D->report_status(victim);
break;
case 5:
message_vision(GRN + "            ---『烈風亂影腳』---" + NOR + "
" + HIC + "    $N將內力一放，氣勁源源不斷的向腳上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+GRN + "                    ～『 烈 風 勁 』～" + NOR + "
" + HIC + "             $N的腳如閃電般的腳勢向$n殘踢而去。\n" + NOR,me,victim);
         victim->receive_wound("kee",240,me);
         me->add("force",-100);
         COMBAT_D->report_status(victim);
break;
case 6:
message_vision(HIB + "            ---『旋風幻影腳』---" + NOR + "
" + HIC + "    $N將內力一收，氣勁源源不斷的向腳上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+HIB + "                    ～『 旋 風 勁 』～" + NOR + "
" + HIC + "             $N的腿順勢一轉由上至下向$n劈踢而去。\n" + NOR,me,victim);
         victim->receive_damage("kee",180,me);
         me->add("force",-100);
         COMBAT_D->report_status(victim);
break;
case 7:
message_vision(HIY + "            ---『暴風滅影腳』---" + NOR + "
" + HIC + "    $N將內勁暴射，氣勁源源不斷的向腳上凝聚，使出雪蒼氣勁之" + NOR + "
"BLINK+HIY + "                    ～『 暴 風 勁 』～" + NOR + "
" + HIC + "             $N強橫的內力挾帶著破風之聲向$n猛踢而去。\n" + NOR,me,victim);
           victim->receive_wound("kee",dam,me);
           me->add("force",-100);
           COMBAT_D->report_status(victim);
break;
case 8:
message_vision(HIW + "            ---『 " + HIY + "枯" + HIB + " 葉" + HIM + "殘" + HIG + " 星" + HIW + " 掌 』---" + NOR + "
" + HIC + "    $N體內的寒氣驀然爆發，忽然間一團星狀之真氣快速飛向$n" + NOR + "
" + HIC + "    剎那間$n的胸前立刻出現了一個紫黑色的傷痕，全身打顫不已。\n\n" + NOR,me,victim);
     victim->receive_wound("kee",dam*2,me);
     victim->apply_condition("star-stial",random(20)+1);
     victim->apply_condition("cold",random(20)+1);
     me->add("force",-150);
     COMBAT_D->report_status(victim);
break;
}
}
}
}
}
   if( skill < 20)
      return action[random(3)];
   else if( skill < 40)
      return action[random(5)];
   else if( skill < 50)
      return action[random(7)];
   else if( skill < 60)
      return action[random(6)+3];
   else if( skill < 80)
      return action[random(8)+3];
  else if( skill < 90)
      return action[random(8)+5];
   else
      return action[random(8)+7];
}
int practice_skill(object me)
{

        if( (int)me->query("kee") < 30 )
                      return  notify_fail("你的氣不夠﹐無法練習雪蒼武學。\n");
        if( (int)me->query("force") < 5 )
                   return  notify_fail("你的內力不夠﹐不能練習雪蒼武學。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("fighter")+"/snow-martial/"+action;
}

