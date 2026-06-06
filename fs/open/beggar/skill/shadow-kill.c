// shadow-kill written by mtl on May 9th, 1996
// Ver 1.02 modified by mtl on Jul 9th, 1996
// 為了避免衝突，規則的enable三項skills的上限，所以加入限制霸雨螫魂的enable
// By Swy 最後修正 QC 98/6/23
#include <ansi.h>
#include <combat.h>
inherit SKILL;
void busyk(object me,object victim,object weapon, int damage);
void devour(object me, object victim, object weapon, int damage);
void bloodk(object me, object victim, object weapon, int damage);
void reversek(object me, object victim, object weapon, int damage);
void shadowk(object me, object victim, object weapon, int damage);
void devast(object me, object victim, object weapon, int damage);

mapping *action = ({
([ "action":"$N斗然使出『停雲催雪，地落八荒』的絕情殺著，氣吞萬里如虎，銀虹流星墜雨般的向$n罩去，讓$n避無可避。",
"dodge": -30,
"parry": 10,
"damage": 10,
"force": 30,
"damage_type": "刺傷",
]),
([ "action":"$N喟然嘆道：不恨古人吾不見，恨古人、不見吾狂耳～驟然隨著那悵然殺意，使出『雲山千疊，駭浪覆頂』向$n層層遞去，招招指向要害。",
"dodge": -40,
"parry": 20,
"damage": 20,
"force": 0,
"damage_type":  "刺傷",
"post_action": (: devour :),
]),
([ "action":"$N似笑非笑，悽悽唸起『棄魂散魄』心訣。只見$N手上的$w一抹紫孽蒸起，不住旋動，激起一道風刃向$n腰間急劈。",
"dodge": -40,
"parry": 25,
"damage": 30,
"force": 40,
"damage_type": "割傷",
"post_action": (: bloodk :),
]),
([ "action":"$N逆走幻星步法，使出『亂象錯形』的奧秘，陷$n於五行易位之闇黑空間。劍首寂然指向京房卦之血脈卦位，只見$n正向跌跌撞撞地向$w奔去....",
"dodge": 10,
"parry": 0,
"damage": 40,
"force": 0,
"damage_type": "刺傷",
"post_action": (: reversek :),
]),
([ "action":"$N意念一起一息之間，身形已然『如入不動魔地』，手中$w影如來如去，無聲亦無息地遞向$n$l....",
"dodge": 15,
"parry": 5,
"damage": 50,
"force": 60,
"damage_type": "刺傷",
"post_action": (: shadowk :),
]),
([ "action":"$N內照形軀、守竅通關，豁然頓悟了"+BLINK+BOLD+"『一切有形招式，"+YEL+"如夢幻泡影"+WHT+"，"+BLU+"如露亦如電"+WHT+"』"+NOR+"。過去所學的闇影匕首，一時之間融會貫通，源源不斷在手中使出，化為不可思量之勢湧向$n....",
"dodge": -30,
"parry": 10,
"damage": 60,
"force": 60,
"damage_type": "刺傷",
"post_action": (: devast :),
]),
([ "action":"$N斗然使出『停雲催雪，地落八荒』的絕情殺著，氣吞萬里如虎，銀虹流星墜雨般的向$n罩去，讓$n避無可避。",
"dodge": -30,
"parry": 20,
"damage": 70,
"force": 50,
"damage_type": "刺傷",
]),
([ "action":"$N喟然嘆道：不恨古人吾不見，恨古人、不見吾狂耳～驟然隨著那悵然殺意，使出『雲山千疊，駭浪覆頂』向$n層層遞去，招招指向要害。",
"dodge": -30,
"parry": 25,
"damage": 70,
"force":  0,
"damage_type":  "刺傷",
"post_action": (: devour :),
]),
([ "action":"$N似笑非笑，悽悽唸起『棄魂散魄』心訣。只見$N手上的$w一抹紫孽蒸起，不住旋動，激起一道風刃向$n腰間急劈。",
"dodge": -40,
"parry": 30,
"damage": 70,
"force": 50,
"damage_type": "割傷",
]),
([ "action":"$N逆走幻星步法，使出『亂象錯形』的奧秘，陷$n於五行易位之闇黑空間。劍首寂然指向京房卦之血脈卦位，只見$n正向跌跌撞撞地向$w奔去....",
"dodge": 10,
"parry": 10,
"damage": 70,
"force": 0,
"damage_type": "刺傷",
"post_action": (: reversek :),
]),
([ "action":"$N意念一起一息之間，身形已然『如入不動魔地』，手中$w影如來如去，無聲亦無息地遞向$n$l....",
"dodge": 15,
"parry": 15,
"damage": 70,
"force": 70,
"damage_type": "刺傷",
"post_action": (: shadowk :),
]),
([ "action":"$N搖來晃去...感到一陣噁心...難道是有了????....還是走火入魔的現象??",
"dodge": 0,
"parry": 0,
"force": 0,
"damage_type": "刺傷",
]),
});

void busyk(object me, object victim, object weapon, int damage)
{
if(random(1000) < me->query("bellicosity"))
if((random(150)<me->query_skill("shadow-kill",1))&&!me->query_temp("devast")) 
{
  victim->set("start_busy",2);
  message_vision(sprintf(HIB"趁著$n忙於招架這密如繁星般的攻擊之際，$N見機不可失，劍勢疾迴，意欲再進一招....\n"NOR),me,victim);
}
}

void devour(object me, object victim, object weapon, int damage)
{
int my_bell = (int) (me->query("bellicosity")/20);
if( my_bell > 60 ) my_bell = 60;

if( random(30) < my_bell )
if(random(150)<me->query_skill("shadow-kill",1)&&!me->query_temp("devast"))
{
  victim->receive_damage("kee", 2*me->query("force_factor") + random( my_bell ) );
  message_vision(sprintf(HIC"$N 匕首上枉死的冤魂，受不住$N陣陣殺氣的催動，從匕首脫出，向$n撲噬而去。\n"NOR),me,victim);
}
}

void bloodk(object me, object victim, object weapon, int damage)
{
if( random(250) < me->query_skill("force")+me->query_skill("shadow-kill",1) )
if( damage > 10 && !me->query_temp("devast"))
{
  victim->add("sen",-15);
  victim->receive_damage("kee", 2*me->query("force_factor") +
    random( (int)me->query_skill("rain-throwing",1)/2 ) );
  message_vision(sprintf(HIM"只見從$n傷口噴灑而出的鮮血，突然凝成無數血柱，如靈蛇般向$n竄去，攝走$n的魂魄。\n"NOR),me,victim);
}
}

void reversek(object me, object victim, object weapon, int damage)
{        
int my_shadow=me->query_skill("shadow-kill",1);
if(random(250)<me->query_skill("shade-steps",1)+my_shadow)
{
  victim->apply_condition("bleeding",(int)me->query_skill("cure")/5 +
  random( (int)my_shadow/10 + (int)me->query_skill("parry")/10 ) );
  message_vision(sprintf(HIR"$N雙手倒握匕首，往自己胸口送去－－卻見到$n胸口一道血柱如飛泉般噴出。\n"NOR),me,victim);
}
}

void shadowk(object me, object victim, object weapon, int damage)
{
int my_shadow=me->query_skill("shadow-kill",1);
if((random(500)<me->query_skill("force")+me->query_skill("shade-steps",1)+my_shadow)&&!me->query_temp("devast"))
{           
   victim->recieve_damage("kee",3*me->query("force_factor") +
     random( (int)my_shadow/2 ) );
   message_vision(sprintf(HIG"$N召喚風影化身與$n廝殺。$N的法身逕向$n背後繞去，雙手提劍往$n天靈直落。\n"NOR),me,victim);
}
}

void devast(object me,object victim, object weapon, int damage)
{
int i;
int my_shadow=me->query_skill("shadow-kill",1);
int time=(int) my_shadow/10+2;

if( me->query("force_factor") >= 10 )
{
  if( me->query_temp("devast") == 0 )
  {
    me->set_temp("devast",1);
    for(i=0;i<time;i++)
    {
      if( random(1600) < me->query("bellicosity")+200)
      if( random(100) < my_shadow )
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }       
    me->start_busy(1);
    message_vision(sprintf(HIY"你仰天一嘆～明白這並非招式之極致，正所謂「飄風不終朝，驟雨不終日」。於是氣歸元牝，周流六虛....\n"NOR),me,victim);
    me->delete_temp("devast");
  }
}
}

mapping query_action(object me, object weapon)
{
int skill_level=(int)(me->query_skill("shadow-kill",1)/10);
object wea=me->query_temp("weapon");

if (me->query("class") != "killer")
return action[11];
if (skill_level<= 5)
  return action[random(skill_level)];
if (skill_level>=6)
  return action[5+random(6)];
}

int valid_learn(object me)
{
  object wea;

if ( me->query_skill_map("rain-throwing") == 1)
  return notify_fail("閻影匕首與霸雨螫魂內勁相衝，請勿裝備霸雨螫魂\n");

if( !(wea = me->query_temp("weapon"))
  || (string)wea->query("skill_type") != "dagger" )
  return notify_fail("你必須先找一把匕首才能練招式。\n");
if( (int)me->query("max_force") < 700)
  return notify_fail("你的內力上限不足, 不可以練闇影匕首。\n");
if(me->query_skill("blackforce",1)*3 <= me->query_skill("shadow-kill",1))
  return notify_fail("你的黑牙神功\技能不足，無法練闇影匕首。\n");
if(me->query_skill("shade-steps",1)*2 <= me->query_skill("shadow-kill",1))
  return notify_fail("你的幻星步法技能不足，無法體會闇影匕首裡，移形換位之精義。\n");
return 1;
}

int valid_enable(string usage) 
{
   return usage=="dagger";
}

int practice_skill(object me)
{

object wea;

if( !(wea = me->query_temp("weapon"))
  || (string)wea->query("skill_type") != "dagger" )
  return notify_fail("練闇影匕首還是要有把匕首吧....\n");
if( (int)me->query("kee") < 30 )
  return notify_fail("體力不夠囉,休息一下再繼續練吧.\n");
me->receive_damage("kee", 30);
return 1;
}
