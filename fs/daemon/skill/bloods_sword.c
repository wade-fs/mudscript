//為npc所使用簡化sk
//將add("kee",-xxx)的判定轉為receive的形式 by blazakira 2011/4/7

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void at_head(object me, object victim, object  weapon, int damage);
void at_hand(object me, object victim, object  weapon, int damage);
void at_foot(object me, object victim, object  weapon, int damage);
void at_miss(object me, object victim, object  weapon, int damage);
void at_wind(object me, object victim, object  weapon, int damage);
void at_quick(object me, object victim, object  weapon, int damage);
int kar,cps,str,cor,int1,spi;
int sp_value;

mapping *action = ({
  (["action":"$N雙手微抬，腳步緩緩移動，不斷積蓄內勁，只見$N雙眼放射出慘綠的光茫，突地平地一聲響，$N大喝一聲"HIR"【血氣方剛】"NOR+"$n只覺腦中一震，全身呆滯，而$N稱此機會, 手中長劍幻化出無數劍影, 向$n的全身罩下．",
    "dodge"      :                -105,
    "parry"      :                -100,
    "damage"     :                 300,
    "force"      :                 300,
    "damage_type":                 "瘀傷"
  ]),
  (["action":"$N將手中長劍暗藏於後，側身橫移數步，地下深印出數個腳印，口中唸唸有詞，隨著長劍的揮舞，數道劍氣由劍中射出，正是"HIR"『血魔』"NOR+"殺招之一"HIM"【血肉橫飛】"NOR+"霎時滿天劍氣縱橫在$n身上劃去．",
    "dodge"      :                -100,
    "parry"      :                -100,
    "damage"     :                 330,
    "force"      :                 330,
    "damage_type":                 "割傷"
  ]),
  (["action" :"$N臉部青絲暴露，濃烈的殺氣從$N的雙眼透出，只見$N不停揮舞佩劍，勁氣中夾帶著令人聞之喪膽的殺氣，正是"HIW"『血魔』"NOR+"絕學之一"CYN"【血染江湖】"NOR+"天空倏然一片血紅，$n也受到血氣包圍．",
    "dodge"      :                -110,
    "parry"      :                -120,
    "damage"     :                 360,
    "force"      :                 350,
    "post_action":                 (: at_head :),
    "damage_type":                 "刺傷"
  ]),
  (["action" : "$N將"HIR"血魔劍招"NOR+"發揮到極限，瞻之在前，忽焉在後，如鬼魅般穿梭在$n四周，只見$N身形一弓，長劍，一道半月形的勁氣猛然像$n湧去，",
    "dodge"      :                -120,
    "parry"      :                -120,
    "damage"     :                 380,
    "force"      :                 350,
    "post_action":                 (: at_hand :),
    "damage_type":                 "劈傷",
  ]),
  (["action" : "$N屈體弓身，將長劍插入地中，全身籠罩在一片藍光中，地面宛如波濤般浮動，隨著蓄積的內勁，藍光不斷增加，倏然藍光一瞬，一道駭人藍箭以由地底向$n疾射而去",
    "dodge"       :               -130,
    "parry"      :                -140,
    "damage"     :                 390,
    "force"      :                 380,
    "post_action":                 (: at_foot :),
    "damage_type":                 "刺傷",
  ]),
  (["action" :"$N猛然躍至青空，幻化出無數身影，一道道傲人劍影持續不斷的殺向$n",
    "parry"      :                -165,
    "damage"     :                 400,
    "force"      :                 400,
    "damage_type":                 "刺傷"
  ]),
  (["action"     :HIW"$N使出血魔殺第一式"NOR"
             "+HIY"----萬魔無盡血劍無式----"NOR"
"+HIW"$N感受四面八方的魔氣，無窮無盡的勁力由四周湧入$N體內，只見$N長劍吸食萬魔魔氣，早已渴望血的滋味.忽然見到$n.彷彿天賜干霖似的....朝$n直奔而去"NOR"
"+HIC"$N瞬間消失在空間中..."NOR,
    "dodge"      :                -170,
    "parry"      :                -160,
    "damage"     :                 430,
    "force"      :                 300,
    "post_action":                 (: at_miss :),
    "damage_type":                 "割傷",
  ]),
  (["action"     :HIW"$N使出血魔殺之第二式"NOR"
             "+HIR" ----血染紅塵----"NOR"
"+HIW"$N將長劍拋往上空...隨著魔氣不斷上揚...劍身也漸漸轉化為紅色.只見血氣以罩滿劍身."NOR"
"+HIR"忽然間.血劍一個跳耀..瞬間殺至$n眼前...."NOR,
    "dodge"      :                -180,
    "parry"      :                -180,
    "damage"     :                 450,
    "force"      :                 500,
    "post_action":                 (: at_wind :),
    "damage_type":                 "割傷",
  ]),
   (["action"     :HIW"$N使出血魔破仙劍之奧義"NOR"
"+HIM"----血霧刃---"NOR"
"+HIW"隨著一陣陣的血霧$N以消失於陣陣血霧中，只見血霧漸漸包圍$n，並在$n週遭幻化為無數血劍無情的吞噬$n"NOR,
    "dodge"      :                -190,
    "parry"      :                -190,
    "damage"     :                 500,
    "force"      :                 500,
    "post_action":                 (: at_quick :),
    "damage_type":                 "劍傷",
  ]),
});

int valid_learn(object me)
{
  if(!me->query("bloodsword")!=2){
    tell_object(me,"你還不夠資格練血魔劍呢。\n");
    return 0;
  }
  if( !me->query_temp("weapon")){
    tell_object(me,"練血魔劍必需先拿把劍。\n");
    return 0;
  }
  if( (me->query("potential") - me->query("learned_points")) < 15 ) {
    tell_object(me, "你的潛能不到十五點，無法練此劍法。\n");
    return 0;
// 與sun_moon_sword 均衡
  }
  me->add("potential", -15);
  return 1;
}

mapping query_action(object me, object weapon)
{
  int skill_level, limit;
  kar=me->query_kar();
  cps=me->query_cps();
  str=me->query_str();
  cor=me->query_cor();
  int1=me->query_int();
  spi=me->query_spi();
  skill_level = (int)(me->query_skill("blood_sword", 1));
  limit= (int)(skill_level/10);
  if (limit < 2 )
    return action[random(3)];
  else if (limit < 3 )
    return action[random(4)];
  else if (limit < 4)
    return action[random(4)+1];
  else if (limit < 5) 
    return action[random(4)+2];
  else if (limit < 7) 
    return action[random(5)+2];
  else if (limit < 9)
    return action[random(6)+2];
  else
    return action[random(6)+3];
}

int valid_enable(string usage)
{
  return ( usage=="sword" || usage=="parry" );
}

void at_head(object me, object victim, object  weapon, int damage)
{
  sp_value =3*(str+cor)+cps+kar+spi+int1;
  victim->receive_damage("kee",sp_value,me);
  COMBAT_D->report_status(victim);
}

void at_hand(object me, object victim, object  weapon, int damage)
{
  sp_value =3*(str+cor)+cps+2*kar+2*spi+int1;
  victim->receive_damage("kee",sp_value,me);
  COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void at_foot(object me, object victim, object  weapon, int damage)
{
  sp_value =4*(str+cor)+cps+2*kar+2*spi+int1;
  victim->receive_damage("kee",sp_value,me);
  COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void at_miss(object me, object victim, object  weapon, int damage)
{
  sp_value =random(300)+4*cps+4*cor;
  me->set_temp("at_miss",1);
  message_vision(sprintf(HBRED"$N以血劍幻出一道無比巨大的劍芒，瞬間破碎為無數劍氣射向$n..$n無法閃避四面八方的攻擊而慘遭血光吞噬\n"NOR),me,victim);
  victim->receive_damage("kee",sp_value,me);
  if(!me->query_temp("conti"))
  victim->start_busy(1);
  COMBAT_D->report_status(victim);
}

void at_wind(object me, object victim, object  weapon, int damage)
{
  sp_value =2*(cor)+int1+str+spi+cps+kar;
  if(!victim->query_temp("at_wind") && random(me->query("max_force")) > random(victim->query_skill("force")+sp_value) && damage > 0)
  {
    message_vision(sprintf(HIC"$N趁長劍殺到$n面前，腳踩七星，悄悄的來到$n身後手中頓時又冒出另一把長劍....此時$n眼前長劍瞬時血化,$n此時已經無法防禦後方來的攻勢了...\n"NOR),me,victim);
    victim->set_temp("at_wind",1);
    call_out("wind",1,me,victim);
  }
  else if(damage > 0 && !victim->query_temp("at_wind")){
    message_vision(sprintf(HIC"$N逆轉的真氣一滯，反而使的身形一滯，$n趁勢攻擊\n"NOR),me,victim);
// 讓對手有出招機會
    COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"),  TYPE_REGULAR);
  }
}

int wind(object me,object victim)
{
  if(environment(victim) && victim->query_temp("at_wind") && me->query_skill("sword") > random(victim->query_skill("dodge")) && me->is_fighting())
  {
    message_vision(sprintf(BCYN"$N無情的砍殺著毫無防備的$n\n"NOR),me,victim);
    victim->receive_damage("kee",1*me->query("max_kee")/10,me);
    me->add("force",-40);
    COMBAT_D->report_status(victim, 1);
  }
  if(victim->query_temp("at_wind") && environment(me) == environment(victim))
    call_out("wind",3,me,victim);
  if(random(me->query_skill("sword")) < random(victim->query_skill("dodge")+victim->query_skill("parry")))
  {
    victim->delete_temp("at_wind");
  }
  return 1;
}

void at_quick(object me, object victim, object  weapon, int damage)
{
  int i;
  int time=random(cps/10)+random(cor/10);
    me->set_temp("conti",1);
  if( cor > random(10))
    victim->start_busy(1);
  for(i=0;i<=time;i++)
  {
    message_vision(sprintf(HIR"陣陣血霧...片片殺意\n"NOR),me,victim);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    COMBAT_D->report_status(victim, 1);
  }
  me->delete_temp("conti");
}

string perform_action_file(string action)
{
  return CLASS_D("swordsman")+"/blood_sword/"+action;
}
