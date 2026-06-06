//陰陽掌法 by bss

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void cold(object me, object victim, object  weapon, int damage);
void fire(object me, object victim, object  weapon, int damage);
void again1(object me, object victim, object weapon, int damage);
void together(object me, object victim, object  weapon, int damage);

mapping *action = ({
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中"HIC"陰"NOR"招的起手式"HIC"「蒼松迎客」"NOR"，右掌平推而出，一道寒風由$N掌中拍出，令人不禁打起冷顫。\n",
"dodge":-60,
"parry":50,
"force":60,
"damage":50,
"damage_type" : "瘀傷",
]),
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中"HIR"陽"NOR"招的起手式"HIR"「開門輯盜」"NOR"，左掌由上而下猛劈而出，一股熱風隨著$N的掌勢而出，使人有種不舒服的悶熱感。\n",
"dodge":-60,
"parry":50,
"force":70,
"damage":55,
"damage_type" : "瘀傷",
]),
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「梅雪爭春」"NOR"，右掌如雪花翻飛擊向$n。\n",
"dodge":-90,
"parry":80,
"force":100,
"damage":60,
"damage_type" : "瘀傷",
]),
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「梅雪逢夏」"NOR"，左掌如連珠般向$n拍出了一十二掌。\n",
"dodge":-90,
"parry":80,
"force":100,
"damage":65,
"damage_type" : "瘀傷",
]),
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「老枝橫斜」"NOR"，左掌平舉，右掌由左脅下斜穿而出，擊向$n的$l。\n",
"dodge":-90,
"parry":80,
"force":100,
"damage":70,
"damage_type" : "瘀傷",
]),
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「長者折枝」"NOR"，左掌高舉，迅速地下拍擊向$n的$l。\n",
"dodge":-90,
"parry":80,
"force":100,
"damage":75,
"damage_type" : "瘀傷",
]),
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「明駝西來」"NOR"，右掌並指成劍，迅雷般刺向$n的$l。\n",
"dodge":-100,
"parry":80,
"force":100,
"damage":80,
"damage_type" : "刺傷",
]),
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「千鈞壓駝」"NOR"，左掌撮指成刀，疾電般劈向$n的$l。\n",
"dodge":-100,
"parry":80,
"force":100,
"damage":85,
"damage_type" : "砍傷",
]),

(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「風沙莽莽」"NOR"，右掌掌勢似有狂風黃沙之重壓，教$n透不過氣來。\n",
"dodge":-100,
"parry":80,
"force":110,
"damage":90,
"post_action":  (: cold :),
"damage_type" : "瘀傷",
]),
(["action":
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「大海沉沙」"NOR"，左掌掌勢如有怒海洪濤之洶湧，教$n心驚膽顫。\n",
"dodge":-100,
"parry":90,
"force":110,
"damage":95,
"post_action":  (: fire :),
"damage_type" : "瘀傷",
]),
(["action":
HIY"$N頓時領悟了「"HIC"陰"HIR"陽"NOR"循環，"HIB"生生不息"NOR"」的道理，將陰陽掌法融合後狂擊而出"
NOR,
"dodge":-100,
"parry":100,
"force":90,
"damage":40,
"post_action":  (: again1 :),
"damage_type" : "瘀傷",
]),
(["action":"$N頓悟「"HIC"陰"HIR"陽"NOR"合壁，地動天驚」之精義，左右兩掌將陰陽氣勁揉合後拍出，瞬間形成一龍捲風襲向$n。\n",
"dodge":-500,
"parry":-500,
"force":0,
"damage":-100,
"post_action":  (: together :),
"damage_type" : "瘀傷",
]),

});

mapping query_action(object me, object weapon)
{
   int skill_level, limit;
   skill_level = (int)(me->query_skill("taiganfist", 1));
   limit= (int)( skill_level/ 10);
      if (limit < 2 )
         return action[random(4 )];
      else if (limit < 3 )
         return action[random(5 )];
      else if (limit < 4 )
         return action[random(6 )];
      else if (limit < 5 )
         return action[random(7)];
      else if (limit < 6 )
         return action[random(8 )];
      else if (limit < 7 )
         return action[random(10)];
      else if (limit < 8 )
         return action[random(11)];
         return action[random(12)];
}
void cold(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("taiganfist", 1);
   message_vision("$N受到陰陽掌法中陰氣的侵襲，看來是受到了凍傷了\n",victim);
   victim->add("kee", -(skill* 3));
   victim->apply_condition("cold",random(5)+((int)me->query_skill("taiganfist",1)/5));
   COMBAT_D->report_status(victim, 1);
}
void fire(object me, object victim, object  weapon, int damage)
{
   int skill = me->query_skill("taiganfist", 1);
   message_vision("$N受到陰陽掌法中陽氣的侵襲，看來是受到了灼傷了\n",victim);
   victim->add("kee",-(skill* 3));
   victim->apply_condition("burn",random(5)+((int)me->query_skill("taiganfist",1)/5));
   COMBAT_D->report_status(victim, 1);
}

void again1(object me, object victim, object weapon, int damage)
{
 int skill_level=me->query_skill("taiganfist",1),bound;
 bound = victim->query("max_kee"); //根據對手的kee來決定扣多少
 bound = (bound/100)*5;            //扣5%的kee
  if( random(100) < 80 && me->query("force",1) > 100 )
  {
       message_vision(
sprintf(HIW"\n$N運起太乙\罡\氣，全身朧罩在一片似藍似紅的氣勁下!!\n\n"NOR),me ,victim);
       message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中"HIC"陰"NOR"招的起手式"HIC"「蒼松迎客」"NOR"，右掌平推而出，一道寒風由$N掌中拍出，令人不禁打起冷顫。\n"),me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中"HIR"陽"NOR"招的起手式"HIR"「開門輯盜」"NOR"，左掌由上而下猛劈而出，一股熱風隨著$N的掌勢而出，使人有種不舒服的悶熱感。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「梅雪爭春」"NOR"，右掌如雪花翻飛擊向$n。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「梅雪逢夏」"NOR"，左掌如連珠般向$n拍出了一十二掌。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「老枝橫斜」"NOR"，左掌平舉，右掌由左脅下斜穿而出，擊向$n。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
      message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「長者折枝」"NOR"，左掌高舉，迅速地下拍擊向$n。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「明駝西來」"NOR"，右掌並指成劍，迅雷般刺向$n。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「千鈞壓駝」"NOR"，左掌撮指成刀，疾電般劈向$n。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「風沙莽莽」"NOR"，右掌掌勢似有狂風黃沙之重壓，教$n透不過氣來。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
      message_vision(
sprintf("$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「大海沉沙」"NOR"，左掌掌勢如有怒海洪濤之洶湧，教$n心驚膽顫。\n"), me ,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
        me->start_busy(1);
}
}
void together(object me, object victim, object  weapon, int damage)
 {
     int skill_level;
     skill_level = (int)(me->query_skill("taiyiforce", 1));
if (skill_level >= 90 )
{
message_vision(HIW"$n被$N的陰陽龍捲真氣，捲至半空中，～～～砰～～～的一聲，真氣爆裂開來，$n被爆震波震的老遠。\n"NOR,me,victim);
        victim->add("kee",-700);
        me->add("force",-170);
victim->apply_condition("hart",random(5)+((int)me->query_skill("taiyiforce",1)/10));
        victim->start_busy(1);
     COMBAT_D->report_status(victim, 1);
}
}

int valid_learn(object me)
{
        if(!(me->query("class") != "taigan")) {
            tell_object(me, "只有太監才能學陰陽掌法。\n");
            return 0;
        }
       if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
       return   notify_fail("學陰陽掌法必須空手。\n");

        return 1;
}

int valid_enable(string usage)
{
        return ( usage=="unarmed" );
}

