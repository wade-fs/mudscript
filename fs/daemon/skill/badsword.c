#include <combat.h>
#include <ansi.h>
inherit SKILL;
void berserk(object me, object victim, object  weapon, int damage);
void conti(object me, object victim, object  weapon, int damage);
void hurt(object me, object victim, object  weapon, int damage);
mapping *action = ({
//1
(["action":HIG + "《魔鷹蝕日》" + NOR + "
$N使一招魔日劍法中的" + HIG + "「魔鷹蝕日」" + NOR + "，手中$w如一條老鷹般直直刺向$n的$l。",
        "dodge":-20,
        "parry":-10,
        "force": 70,
        "damage":30,
        "damage_type":"刺傷",
]),//2
(["action":HIR + "《日光無影》" + NOR + "
$N使出魔日劍法中的" + HIR + "「日光無影」" + NOR + "，劍光霍霍斬向$n的$l。",
        "dodge":-20,
        "parry":-10,
        "force": 80,
        "damage":50,
        "damage_type":"割傷",
]),//3
(["action":HIY + "《御風而行》" + NOR + "
$N一招" + HIY+"「御風而行」" + NOR + "，身形陡然滑出數尺，手中$w斬向$n的$l，然而此乃招中有招。",
        "dodge":-30,
        "parry":-10,
        "force": 90,
        "damage":70,
        "damage_type":"割傷",
]),//4
(["action":HIB + "《日落西山》" + NOR + "
$N手中$w中宮直進，一式" + HIB + "「日落西山」" + NOR + "對準$n的$l狠狠刺出數劍。",
        "dodge":-40,
        "parry":-20,
        "force":100,
        "damage":70,
        "damage_type":"刺傷",
        "post_action": (: hurt :),
]),//5
(["action":HIY + "《金光瀉地》" + NOR + "
$N將氣勁灌入手中$w，縱身一躍，使一手" + HIY + "「金光瀉地」" + NOR + "頓時一片金光罩住$n全身。",
        "dodge":-40,
        "parry":-20,
        "force":110,
        "damage":100,
        "damage_type":"刺傷",
]),//6
(["action":HIM + "《豔陽高照》" + NOR + "
$N將$w憑空一指，一招魔日劍法中的" + HIM + "「豔陽高照」" + NOR + "快速的刺向$n的$l。",
        "dodge":20,
        "parry":-30,
        "damage":100,
        "force":120,
        "damage_type":"刺傷",
        "post_action": (: berserk :),
]),//7
(["action":HIC + "《柳暗花明》" + NOR + "
$N手中$w向外一分，使一招" + HIC + "「柳暗花明」" + NOR + "反手對準$n$l一劍刺去。",
        "dodge":-20,
        "parry":30,
        "force":130,
        "damage":110,
        "damage_type":"刺傷",
]),//8
(["action":HIY + "《旭日東升》" + NOR + "
$N橫劍上前，身形一轉手中$w使一招魔日劍法中的" + HIY + "「旭日東升」" + NOR + "畫出一道光弧斬向$n的$l。",
        "dodge":-30,
        "parry":-20,
        "force":140,
        "damage":120,
        "damage_type":"割傷",
        "post_action": (: conti :),
]),//9
(["action":HIB + "《撥雲見日》" + NOR + "
$N一轉身，使出一招魔日劍法中的" + HIB + "「撥雲見日」" + NOR + "，手中$w對準$n的$l刺出數劍。",
        "dodge":-20,
        "parry":-40,
        "force":150,
        "damage":130,
        "damage_type":"刺傷",
]),//10
(["action":HIR + "《天虹貫日》" + NOR + "
$N手中$w朝地一揮，使一招" + HIR + "「天虹貫日」" + NOR + "，地面裂出一道道劍痕，數道劍氣迅速的往$n身上砍去。",
        "dodge":-20,
        "parry":-10,
        "force":160,
        "damage":140,
        "damage_type":"刺傷",
        "post_action": (: berserk :),
]),//11
(["action":HIW + "《偷天換日》" + NOR + "
$N手中$w朝天空一丟，使一招" + HIW + "「偷天換日」" + NOR + "，$w射出萬丈光芒，擊出一道劍氣擊向$n。",
        "dodge":-20,
        "parry":-30,
        "damage":150,
        "damage_type":"刺傷",
        "post_action":(: conti :),
]),//end
// 讓別派不能用 by swy
(["action":"你不是惡人谷的人所以不能使出。",
   "damage":10,
"damage_type":"白癡傷",
]),
});
int valid_learn(object me)
{
        object wea1,wea2;
        wea1 = me->query_temp("weapon");
        wea2 = me->query_temp("secondary_weapon");
if(!me->query("get_badsword")) return notify_fail("你沒有資格學這個。\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的內力不夠，沒有辦法練魔日劍法。\n");
        if(me->query("class")!="bandit")
                return notify_fail("你怎麼樣都學不會魔日劍法。\n");
        if( (wea1 && wea1->query("skill_type")!="sword") || (wea2 && wea2->query("skill_type")!="sword") )
                return notify_fail("你必須先找一把劍才能練劍法。\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}
void hurt(object me, object victim, object  weapon, int damage)
{
        int bellpower;
        bellpower = (int)me->query("bellicosity") / 50+1;
        damage=bellpower*10;
        if( damage >400){damage=400;}
        if( random(10) >= 3 && !me->query_temp("conti"))
        {
          victim->receive_damage("kee", damage ,me);
message_vision(sprintf(BLU + "$N將全身之勁力注入劍中，順勢將劍刺向$n，$n瞬間被$N擊中數劍！！！\n" + NOR),me,victim);
          COMBAT_D->report_status(victim);
          me->add("force",-5*bellpower);
        }
}
void berserk(object me, object victim, object  weapon, int damage)
{

     message_vision( sprintf(HIW + "$N真氣凝聚，準備使出" + HIC+"「魔日裂風斬」" + HIW + "，$N身體四周爆發出一股旋風！！\n" + NOR),me,victim);
     message_vision(sprintf(HIW + "$N四周劍氣越轉越急，「咻」一聲化作一道光束朝$n激射而去。\n" + NOR),me,victim);
     if( random(10) >= 3 && !me->query_temp("conti") )
        {
            message_vision(sprintf(HIR + "劍氣直接命中$n，$n應聲而倒。\n" + NOR), me ,victim);
            victim->start_busy(1);
            me->add("force",-100);
        }
        else
        {
             message_vision(sprintf(HIR + "敵人縱身急避，躲開了這致命的一擊。\n" + NOR),me,victim);
             me->add("force",-100);
        }
}
void conti(object me, object victim, object weapon, int damage)
{
        int i,lose;
        int bellpower = (int)me->query("bellicosity")/500+1;
        if(bellpower>8)
        bellpower=8;
          if( me->query_temp("conti") == 0 && random(10) >= 3 && me->query("env/惡霸連擊")=="YES")
          {
            lose = (int)me->query_skill("badsword", 1)/50+2+bellpower;
            me->set_temp("conti",1);
message_vision("\n\n\t\t\t" + BRED+HIW + "☆魔★日☆再★現☆" + NOR + "\n\n" + NOR, me, victim);
            for(i=0;i<=lose;i++)      {
            COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_QUICK);
            }
            if(!me->query_temp("crazy"))   me->start_busy(1);
            me->delete_temp("conti");
          }
}
mapping query_action(object me, object weapon)
{
int skill_level;
    skill_level = (int)(me->query_skill("badsword",1));
if(userp(me) && me->query("class")!="bandit") return action[0];
    if(skill_level<40)
          return action[ random(4)];
    else if (skill_level<50)
          return action[ random(5)];
    else if (skill_level<60)
          return action[ random(6)];
    else if (skill_level<70)
          return action[ random(7)];
    else if (skill_level<80)
          return action[ random(8)];
    else if (skill_level<90)
          return action[ random(8)+1];
    else if (skill_level<100)
          return action[ random(10)+1];
    else
          return action[ random(8)+3];
}
int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
        return notify_fail("你的內力或氣不夠，沒有辦法練習魔日劍法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所學練了一遍魔日劍法。\n");
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("bandit") + "/badsword/" + action;
}
