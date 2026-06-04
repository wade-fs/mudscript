//將add(gin,sen)的傷害改為receive_damage by blazakira 2011/7/24

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
void sp_attack4(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);
void sp_attack6(object me, object victim, object  weapon, int damage);
void sp_attack7(object me, object victim, object  weapon, int damage);
void sp_attack8(object me, object victim, object  weapon, int damage);
void sp_attack9(object me, object victim, object  weapon, int damage);
void sp_attack10(object me, object victim, object  weapon, int damage);

int kar, cps , str , cor , int1 , spi ,
 white, nine , gen, ice, purple, black, bluesea, goldsun, blood, green;

int sp_value;

string *unarmed_parry_msg = ({
"\n$n暗運" + HIG + "玄宇宙心法" + NOR + "中之" + HIG + "『化劫』" + NOR + "，只見$n身邊浮現出綠色氣罩將$N攻勢檔開！\n" + NOR,
"\n$n暗運" + HIW + "白雲煙心法" + NOR + "中之" + HIC + "『雲煙嬝嬝』" + NOR + "，只見$n周身籠罩無限雲煙讓$N無法捉摸\n",
"\n$n暗運" + MAG + "紫星河心法" + NOR + "中之" + MAG + "『星河氣旋』" + NOR + "，$N身形被一道紫色氣流所牽引\n",
        });

mapping *action = ({
//1
        ([      
                "action"     :               HIW + "$N將體內真氣緩運周身，使出了渾天寶鑑第一式『白雲煙』，瞬時$N真氣化做嬝嬝雲煙籠罩住$n" + NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "內傷"
        ]),
//2
        ([     
                "action"     :               HIW + "$N凝聚真氣於雙掌，使出渾天寶鑑第二式" + HIM + "『玫蕩霞』" + HIW + "，掌中真氣化成一道霞光迅速的逼向$n" + NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "內傷"
        ]),
//3
        ([   
                "action"     :               HIW + "$N將內勁化成一股柔勁暗運於地上，使出了渾天寶鑑第三式" + HIY + "『土崑崙』" + HIW + "，暗勁猛然由地底爆發將$n籠罩其中 " + NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "內傷"
        ]),
//4
        ([  
                "action"     :               HIW + "$N凝聚體內陰寒內勁，使出了渾天寶鑑第四式" + HIC + "『碧雪冰』" + HIW + "，周遭水氣化成數道寒冰如刃向$n疾射而去" + NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "創傷"
        ]),
//5
        ([ 
                "action"     :               HIW + "$N雙掌朝天暗運渾天心法，使出了渾天寶鑑第五式" + MAG + "『紫星河』" + HIW + "，只見天上落下紫色星辰纏繞在$n周遭" + NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "內傷"
        ]),
//6
        ([
                "action"     :               HIW + "$N體內的真氣有如盤古開天地一般，真氣亂竄，使出渾天寶鑑第六式" + WHT + "『玄混沌』" + HIW + "，瞬時$n周遭只見一片黑暗，無法掌握$N之攻勢" + NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack6 :),
                "damage_type":               "內傷"
        ]),
//7
         ([     "action"     :               HIW + "$N周遭澎湃的氣勁如海嘯般翻騰，使出渾天寶鑑第七式" + HIB + "『靛滄海』" + HIW + "，氣勁如浪般一波一波的襲向$n" + NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack7 :),
                "damage_type":                "內傷",
           ]),
//8
         ([     "action"     :               HIW + "$N突然金光閃閃，光華奪目，金色的真氣在身旁旋繞，使出渾天寶鑑第八式" + HIY + "『金晨曦』" + HIW + "，$n瞬時被光華所惑，一時不知所措" + NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack8 :),
                "damage_type":                "內傷",
           ]),
//9
         ([     "action"     :               HIW + "$N$N凝聚穹蒼血勁，周遭化成一片血紅，使出渾天寶鑑第九式" + HIR + "『血穹蒼』" + HIW + "，$n自覺彷彿陷入了修羅地獄般呆立著" + NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack9 :),
                "damage_type":                "內傷",
           ]),
//10
         ([     "action"     :               HIW + "$N暗運渾天心法，使出渾天寶鑑最終式" + HIG + "『玄宇宙』" + HIW + "，瞬時天空昏暗，萬星繁動，全身各條經脈均充滿了星晨所付予的氣勁，將氣勁化成一道無形氣團朝$n襲去" + NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack10 :),
                "damage_type":                "內傷",
           ]),
});

int valid_learn(object me)
{
  if(!me->query("quest/super-unarmed",1)) {
    tell_object(me,"你還不夠資格練渾天寶鑑。\n");
    return 0;
  }
  else if( me->query_temp("weapon") || me->query_temp("secondary_weapon") ) {
    tell_object(me,"練渾天寶鑑必須要空手唷。\n");
    return 0;
  }
  else if(me->query_skill("superforce",1)<200) {
    write("你的渾天心法等級不夠﹐不能練渾天寶鑑。\n");
    return 0;
  }
  else if( me->query("class") != "prayer") {
    tell_object(me,"你不是聖火徒。\n");
    return 0;
  }
  else if( (me->query("potential") - me->query("learned_points")) < 15 ) {
    tell_object(me, "你的潛能不到十五點，無法練渾天寶鑑。\n");
    return 0;
  }
  me->add("potential", -15);
  return 1;
}

int valid_enable(string usage)
{
  return ( usage=="unarmed" || usage=="parry" );
}

mapping query_action(object me, object *weapon)
{
  int skill_level,limit,i;

  kar=me->query_kar();
  cps=me->query_cps();
  str=me->query_str();
  cor=me->query_cor();
  int1=me->query_int();
  spi=me->query_spi();
  white=me->query("/functions/white/level",1);
  nine=me->query("/functions/nine/level",1);
  gen=me->query("/functions/gen/level",1);
  ice=me->query("/functions/ice/level",1);
  purple=me->query("/functions/purple/level",1);
  black=me->query("/functions/black/level",1);
  bluesea=me->query("/functions/bluesea/level",1);
  goldsun=me->query("/functions/goldsun/level",1);
  blood=me->query("/functions/blood/level",1);
  green=me->query("/functions/green/level",1);

  skill_level = (int)(me->query_skill("super-unarmed",1));
  limit= skill_level;
  if(me->query("family/family_name")!="聖火教")
    return action[1];
  if (limit < 10)
    return action[random(1)];
  else if (limit < 20)
    return action[random(2)];
  else if (limit < 30)
    return action[random(3)];
  else if (limit < 40)
    return action[random(4)];
  else if (limit < 50)
    return action[random(5)];
  else if (limit < 60)
    return action[random(6)];
  else if (limit < 70)
    return action[random(7)];
  else if (limit < 80)
    return action[random(8)];
  else if (limit < 90)
    return action[random(9)];
  else
    return action[random(10)]; 
}

string perform_action_file(string action)
{
  return CLASS_D("prayer")+"/super-unarmed/"+action;
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIW + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIC + "
天晶配合著渾天心法中的" + HIW + "『白雲煙』" + HIC + "，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
\n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(sp_value/2);
    COMBAT_D->report_status(victim);
  }
   else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(sp_value/4);
    COMBAT_D->report_status(victim);
  }
}

void sp_attack2(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =(nine+spi);   
  message_vision(HIM + "$n只見一片霞光朝自己迎面而來\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIC + "
天晶配合著渾天心法中的" + HIM + "『玫蕩霞』" + HIC + "，水晶彷彿與心法互相應和
一道道霞光從天晶向$n狂襲而去，只見$n心神不寧
\n" + NOR,me,victim);
    victim->receive_wound("kee",nine*10,me);
    victim->receive_damage("gin",sp_value*5,me);
    victim->receive_damage("sen",sp_value*5,me);
//    victim->add("gin",-(sp_value*5));
//    victim->add("sen",-(sp_value*5));
	COMBAT_D->report_status(victim);
  }
   else {
    victim->receive_wound("kee",nine*5,me);
    victim->receive_damage("gin",sp_value*2,me);
    victim->receive_damage("sen",sp_value*2,me);
//    victim->add("gin",-(sp_value*2));
//    victim->add("sen",-(sp_value*2));
    COMBAT_D->report_status(victim);
  }
}

void sp_attack3(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIY + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIY + "
天晶配合著渾天心法中的『白雲煙』，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
      \n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/2);
    COMBAT_D->report_status(victim);
  }
   else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/4);
    COMBAT_D->report_status(victim);
  }
}

void sp_attack4(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIY + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIY + "
天晶配合著渾天心法中的『白雲煙』，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
      \n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/2);
    COMBAT_D->report_status(victim);
  }
   else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/4);
    COMBAT_D->report_status(victim);
  }
}

void sp_attack5(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIY + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIY + "
天晶配合著渾天心法中的『白雲煙』，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
      \n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/2);
    COMBAT_D->report_status(victim);
  }
   else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/4);
    COMBAT_D->report_status(victim);
  }
}

void sp_attack6(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIY + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIY + "
天晶配合著渾天心法中的『白雲煙』，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
      \n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/2);
    COMBAT_D->report_status(victim);
  }
  else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/4);
    COMBAT_D->report_status(victim);
  }
}

void sp_attack7(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIY + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIY + "
天晶配合著渾天心法中的『白雲煙』，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
      \n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/2);
    COMBAT_D->report_status(victim);
  }
  else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/4);
    COMBAT_D->report_status(victim);
  }
}

void sp_attack8(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIY + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIY + "
天晶配合著渾天心法中的『白雲煙』，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
      \n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/2);
    COMBAT_D->report_status(victim);
  }
  else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/4);
    COMBAT_D->report_status(victim);
  }
}

void sp_attack9(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIY + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIY + "
天晶配合著渾天心法中的『白雲煙』，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
      \n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/2);
    COMBAT_D->report_status(victim);
  }
  else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/4);
    COMBAT_D->report_status(victim);
  }
}

void sp_attack10(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =((ice/50)+(spi/5));   
  message_vision(HIY + "瞬間只見嬝嬝雲煙籠罩著$n，$n突然動彈不得\n" + NOR,me,victim);
  if( weapon->query("id")=="green-crystal") {
    message_vision(HIY + "
天晶配合著渾天心法中的『白雲煙』，水晶彷彿與心法互相應和
$N周遭嬝嬝雲煙瞬時已籠罩在方圓十里，$n自覺自己身處在一片雲海之中
      \n" + NOR,me,victim);
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/2);
    COMBAT_D->report_status(victim);
  }
  else {
    victim->receive_wound("kee",ice*5,me);
    victim->start_busy(ice/4);
    COMBAT_D->report_status(victim);
  }
}
