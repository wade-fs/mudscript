//降龍絕學 v1.00 by Santo
//增加連擊招式 by Dico 1999,6,18

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me, object victim, object weapon, int damage);
void attack2(object me, object victim, object weapon, int damage);
void attack3(object me, object victim, object weapon, int damage);
void again1(object me, object victim, object weapon, int damage);


mapping *action = ({
//0
(["action":"$N左腿微曲，右臂內彎，右掌畫了個圓圈，起手「"+HIY"亢龍有悔"NOR+"」，呼的一聲向外推去，
掌勁直直的掃向$n的$l。",
"dodge":-60,
"parry":50,
"force":60,
"damage":325,
"damage_type" : "瘀傷",
]),
//1
(["action":"$N凝神提氣，雙腳一蹬，身體不住高躍，雙掌如刀似剪，一招「"+HIY"飛龍在天"NOR+"」，掌掌往
$n的$l削去。",
"dodge":-60,
"parry":50,
"force":70,
"damage":330,
"damage_type" : "瘀傷",
]),
//2
(["action":"$N的掌勢萬馬奔騰，有若開天闢地般，「"+HIY"戰龍在野"NOR+"」如一條狂龍般撲向$n，勢不可檔。",
"dodge":-90,
"parry":80,
"force":100,
"damage":335,
"damage_type" : "瘀傷",
]),
//3
(["action":"$N右手屈起食中兩指，半拳半掌，向$n的$l打去，「"+HIY"潛龍勿用"NOR+"」招意蜒曲不窮，左手
同時向裏鉤拿，右推左鉤，極難閃避。",
"dodge":-90,
"parry":80,
"force":100,
"damage":340,
"damage_type" : "瘀傷",
]),
//4
(["action":"$N右掌一開，左掌跟著一握，力聚於掌，「"+HIY"利涉大川"NOR+"」氣勢大開大闔，掌勁盡透剛氣，
向$n不斷推去。",
"dodge":-90,
"parry":80,
"force":100,
"damage":345,
"damage_type" : "瘀傷",
]),
//5
(["action":"$N雙掌一提，雙臂內彎真氣隨之一吐，「"+HIY"鴻漸於陸"NOR+"」掌勢由隱而明，平平的推向$n。",
"dodge":-90,
"parry":80,
"force":100,
"damage":350,
"damage_type" : "瘀傷",
]),
//6
(["action":"$N身形緩慢推動，倏地間雙掌順勢一推，「"+HIY"突如其來"NOR+"」彷如暴雨驟至，掌勁如狂風般地
襲向$n。",
"dodge":-100,
"parry":80,
"force":100,
"damage":355,
"damage_type" : "瘀傷",
]),
//7
(["action":"$N掌勢大開大闔，體內真氣不斷向外放射，招式亦隨著真氣向$n攻去，「"+HIY"震驚百里"NOR+"」如
爆雷般驚人。",
"dodge":-100,
"parry":80,
"force":100,
"damage":360,
"damage_type" : "瘀傷",
]),
//8
(["action":"$N瞬時吸一口氣，左掌前探，右掌倏地從左掌底下穿了出去，強招「"+HIY"或躍在淵"NOR+"」直擊
向$n的$l。",
"dodge":-100,
"parry":80,
"force":110,
"damage":365,
"damage_type" : "瘀傷",
]),
//9
(["action":"$N形如猛虎出柵，狠招「"+HIY"神龍擺\尾"NOR+"」呼之欲出，隨即反手一劈，擊向$n的$l。",
"dodge":-100,
"parry":90,
"force":110,
"damage":370,
"damage_type" : "瘀傷",
]),
//10
(["action":"$N掌收於胸，招式璞\而不華，雙手撒掌一合，「"+HIY"見龍在田"NOR+"」筆直的擊向$n的$l。",
"dodge":-100,
"parry":90,
"force":110,
"damage":375,
"damage_type" : "瘀傷",
]),
//11
(["action":"$N雙掌同時一舉，跟著背脊往前一挺，雙掌齊發，一招「"+HIY"雙龍取水"NOR+"」攻向$n。",
"dodge":-100,
"parry":90,
"force":110,
"damage":380,
"damage_type" : "瘀傷",
]),
//12
(["action":"$N掌勁一鬆，力透黏勁，左掌一帶，牽動$n四方氣流，「"+HIY"群龍無首"NOR+"」雙掌如狂雨擊出，
掌勁虛幻飄渺令$n眼花撩亂。",
"dodge":-100,
"parry":90,
"force":110,
"damage":385,
"damage_type" : "瘀傷",
]),
//13
(["action":"$N身形不斷晃動，步移$n六方，突然間，六方掌影同時狂襲而至，「"+HIY"時乘六龍"NOR+"」如群龍
逆噬，盡擊向$n。",
"dodge":-100,
"parry":100,
"force":200,
"damage":390,
"damage_type" : "瘀傷",
]),
//14
(["action":"$N掌影守住全身，並不搶攻，$n卻反被$N繁密的掌影所退，守招「"+HIM"密雲不雨"NOR+"」如大雨欲
來，一掌又一掌環繞$n。",
"dodge":-110,
"parry":100,
"force":200,
"damage":395,
"damage_type" : "瘀傷",
]),
//15
(["action":HIW"                $N使出降龍失傳絕學第一式\n"
"             －＝"HIG"「V損－則－有－孚]」"HIW"＝－\n"
"          內息不斷提昇，突然真氣爆吐，內勁反由雙掌蘊生\n"
"            招意被"HIG"洗髓勁"HIW"所激發，由裡而外不斷侵襲$n。\n"NOR,
"dodge":-110,
"parry":100,
"force":220,
"damage":400,
"damage_type" : "內傷",
"post_action" : (: attack1 :),
]),
//16
(["action":HIW"                $N使出降龍失傳絕學第二式\n"
"             －＝"HIC"「W履－霜－冰－至\\」"HIW"＝－\n"
"$N稍稍吐了一口氣，逆運體內洗髓經，將"HIR"陽剛之氣"HIW"轉化為"HIB"陰柔之勁\n"HIW
"   兩肘往上微抬，將陰柔之勁運至雙臂，右拳左掌，直擊橫推\n"
"     幻化出兩道"HIC"冰龍"HIW"，剛柔並濟，一快一慢的打向$n的$l。\n"NOR,
"dodge":-120,
"parry":100,
"force":250,
"damage":400,
"damage_type" : "凍傷",
"post_action" : (: attack2 :),
]),
//17
(["action":HIW"                $N使出降龍失傳絕學第三式\n"
"             －＝"HIM"「X羝－羊－觸－藩[」"HIW"＝－\n"
"          $N運起洗髓經十成功\力，將真氣運至雙手，凝氣為劍\n"
"連劍帶掌，無數"HIY"光芒"HIW"有如"YEL"迅"HIY"雷"BLU"疾"HIB"風"HIW"向$n相互激盪而去，掌意劍意同時擊向$n。\n"NOR,
"dodge":-150,
"parry":100,
"force":250,
"damage":400,
"damage_type" : "刺傷",
"post_action" : (: attack3 :),
]),
//18
(["action":HIW"$N向後翻身一躍，退後數尺，全力鼓催體內的"HIY"降龍勁"HIW"，內勁如潮暴湧，牽動四方氣流，渾身冒出陣陣白煙。\n"
"白煙繚繞，身後幻化出如真似假的"HIC"龍形氣勁"HIW"，四周氣流相互激盪，震的$n血脈紊亂。\n"
"只見$N傲然聳立，狀甚平靜，但其身後的"HIB"龍形氣勁"HIW"，卻如箭在弦，有飛龍在天之威。\n\n"NOR
"       霎時$N"HIY"豪光"NOR"暴現，體內降龍勁破體而出，使出降龍最終奧義。\n"NOR
HIW"            ─＝"HIR"Y 龍  嘯  九  天 Z"HIW"＝─"NOR,
"dodge":-100,
"parry":100,
"force":150,
"damage":400,
"post_action":  (: again1 :),
"damage_type" : "瘀傷",
]),

});


mapping query_action(object me, object *weapon)
{
   int skill;

   skill=me->query_skill("dragonfist", 1);

   if( me->query("family/family_name")!="丐幫" || !me->query("read_page_1",1)
       || !me->query("read_page_2",1) || !me->query("read_page_3",1)
       || !me->query("read_dragonfist",1) )
   {
    if( skill < 50)
       return action[random(7)];
    else if( skill < 60)
       return action[random(10)];
    else if( skill < 70)
       return action[random(12)];
    else if( skill < 80)
       return action[random(14)];
    else
       return action[random(15)];
   } else {if (random(100) > 80 )
       return action[random(10)+9];
    else 
       return action[random(9)+9];
   }
}
void attack1(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("dragonfist", 1);
 att_value = random(2*skill);
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIG"$N雙掌蘊含的洗髓勁有如厲雷疾風的向$n飛奔而去，$n硬擋之下洗髓勁已穿體而過，震傷了$n的心脈\n"NOR,me,victim);
   victim->add("force",-att_value);
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("hart",random(15));
  }
}
void attack2(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("dragonfist", 1);
 busy_value = skill / 50;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIC"兩道陰柔冷冽勁氣竄入$N的體內，奇寒蝕骨使$N一時無法行動。\n"NOR,victim);
   victim->start_busy( random(busy_value) );
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("cold",random(15));
  }
}


void attack3(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("dragonfist",1);
 att_value=random(2*skill);
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
 {
  message_vision(HIM"$N低喝一聲，將掌中劍氣射向$n，無數劍茫激射而去，$n避無可避，慘遭劍氣穿體。\n"NOR,me,victim);
  victim->add("kee",-att_value);
  COMBAT_D->report_status(victim,1);
  victim->apply_condition("swordkee",random(15));
 }
}

void again1(object me, object victim, object weapon, int damage)
{
 int skilv,maxlv,i,j,mydamage;
 skilv=random(me->query_skill("dragonfist",1));
 maxlv=me->query_skill("dragonfist",1);
 j=skilv/10;
 if(j>9) {j=9;}
 for(i=0;i<=j;i++)
 {
  switch(i)
  {
  case 0:
  message_vision("$N左腿微曲，右臂內彎，右掌畫了個圓圈，起手「"+HIY"亢龍有悔"NOR+"」，呼的一聲向外推去，掌勁直直的掃向$n。\n",me,victim);
  break;
  case 1:
  message_vision("$N凝神提氣，雙腳一蹬，身體不住高躍，雙掌如刀似剪，一招「"+HIY"飛龍在天"NOR+"」，掌掌往$n四肢剪去。\n",me,victim);
  break;
  case 2:
  message_vision("$N的掌勢萬馬奔騰，有若開天闢地般，「"+HIY"戰龍在野"NOR+"」如一條狂龍般撲向$n，勢不可檔。\n",me,victim);
  break;
  case 3:
  message_vision("$N右手屈起食中兩指，半拳半掌，向$n打去，「"+HIY"潛龍勿用"NOR+"」招意蜒曲不窮，左手同時向裏鉤拿，右推左鉤，極難閃避。\n",me,victim);
  break;
  case 4:
  message_vision("$N形如猛虎出柵，狠招「"+HIY"神龍擺\尾"NOR+"」呼之欲出，隨即反手一劈，擊向$n。\n",me,victim);
  break;
  case 5:
  message_vision("$N掌收於胸，招式璞\而不華，雙手撒掌一合，「"+HIY"見龍在田"NOR+"」筆直的擊向$n。\n",me,victim);
  break;
  case 6:
  message_vision("$N雙掌同時一舉，跟著背脊往前一挺，雙掌齊發，一招「"+HIY"雙龍取水"NOR+"」攻向$n。\n",me,victim);                                             break;
  case 7:
  message_vision("$N掌勁一鬆，力透黏勁，左掌一帶，牽動$n四方氣流，「"+HIY"群龍無首"NOR+"」雙掌如狂雨擊出，掌勁虛幻飄渺令$n眼花撩亂。\n",me,victim);
  break;
  case 8:
  message_vision("$N身形不斷晃動，步移$n六方，突然間，六方掌影同時狂襲而至，「"+HIY"時乘六龍"NOR+"」如群龍逆噬，盡擊向$n。\n",me,victim);
  break;
  }
   if( ((int)victim->query_skill("move",1)
        + random((int)victim->query_skill("dodge",1))*5)
        < skilv+random((int)me->query_skill("dodge",1)*i
        + (int)victim->query_skill("move",1)) )
    {
     message_vision(HIC"$N的勁力澎湃洶湧，$n一時招架不住，被$N一掌轟中，「哇！」一聲吐出一口鮮血！！\n"NOR,me,victim);
     victim->receive_damage("kee",(skilv*i/10));
     COMBAT_D->report_status(victim,1);
     me->add("force",-(skilv*maxlv/100));
     mydamage = mydamage+(skilv*i)/10;
   } else
   {
    message_vision(HIW"$n在掌影的包圍之下，看出$N的破綻，左閃右躲的躲過了$N凌厲的殺招\n"NOR,me,victim);
     me->add("force",-skilv*maxlv/100);
     mydamage = mydamage+(skilv*i)/10;
   }
 }
 if(i>=9)
 {
  message_vision(HIR"$N使出龍嘯九天後內力耗損過巨，氣息大亂，呼吸沉重四肢酸痛難奈，不得不趕緊運氣調息。\n"NOR,me);
        me->start_busy((skilv+maxlv)/50);
        COMBAT_D->report_status(victim,1);
 } else {
 message_vision(HIR"$N擊出"+chinese_number(i)+"掌後，真氣一散，內力無以為繼，反被降龍勁所傷，吐出一口鮮血！\n"NOR,me);
 me->start_busy((skilv+maxlv)/100);
 me->receive_damage("kee",mydamage);
 COMBAT_D->report_status(victim,1);
 }
}

int practice_skill(object me)
{
  if ((int) me->query("max_force")<1000)
  return notify_fail("你武學知識不足，無法參透降龍絕學的精妙之處\n");
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/dragonfist/"+action;
}
int valid_learn(object me)
    {
        if( me->query("max_force") < 1500 ) {
            tell_object(me, "你的內力修為不夠, 最少要有一千五百點。\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "只有丐幫弟子才能學降龍絕學。\n");
            return 0;
        }
        if(!(me->query("beggar/quests 10") == 1 )) {
            tell_object(me, "丐幫弟子要完成任務十才能學。\n");
            return 0;
        }
        if( me->query_str() < 20) {
            tell_object(me, "你的臂力不夠不能學降龍絕學。\n");
            return 0;
        }
        if( me->query("force") < 500 ) {
            tell_object(me, "你目前的內力不到五百點, 無法練此絕學。\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 3 ) {
            tell_object(me, "你的潛能不到三點, 無法練此絕學。\n");
            return 0;
        }
       if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
       return   notify_fail("學降龍十八掌必須空手。\n");

        tell_object(me, "學此絕學需扣潛能三點。\n");
        me->add("potential", -3);
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="unarmed" )||(usage=="parry");
}


