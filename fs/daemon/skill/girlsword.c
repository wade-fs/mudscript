// girlsword.c
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me,object victim,object weapon,int damage);

mapping *action = ({
        ([      "action":               "$N使一招[32m「天女攔花捧」[0m﹐手中$w使將出來劍光有如一花籃般, 向$n的$l疾馳而下",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "刺傷"
        ]),
        ([      "action":               "$N使出天女散花劍法中的[32m「天女嚶嚶」[0m﹐劍光霍霍, 忽緩忽快地刺向$n的$l",
                "dodge":                -20,
                "damage":               40,
                "damage_type":  "割傷"
        ]),
        ([      "action":               "$N一招[32m「天女獻花」[0m﹐身形陡然跪倒在地﹐手中$w順勢斬向$n的$l",
                "dodge":                -30,
                "damage":               20,
                "damage_type":  "割傷"
        ]),
        ([      "action":               "$N手中$w中宮直進﹐一式[32m「千嬌百媚」[0m對準$n的$l刺出一劍",
                "dodge":                -40,
                "damage":               50,
                "damage_type":  "刺傷"
        ]),
        ([      "action":               "$N縱身一躍﹐便是一招[32m「春光無限」[0m, $w對準$n的$l送出一劍",
                "dodge":                -40,
                "damage":               45,
                "damage_type":  "刺傷"
        ]),
        ([      "action":               "$N將手上的$w拋向地上﹐雙臂環抱$n, 待$w一落地起腳一踏, 來招乃是[32m「妾意如蠍」[0m, $w直刺$n的$l",
                "dodge":                -20,
                "damage":               50,
                "damage_type":  "刺傷"
        ]),
        ([      "action":               "$N手中$w向外一分﹐使一招[32m「反覆無情」[0m反手對準$n$l一劍刺去",
                "dodge":                -20,
                "damage":               55,
                "damage_type":  "刺傷"
        ]),
        ([      "action":               "$N橫劍上前﹐身形一轉手中$w使一招[0m「散花如夢」[0m畫出一道光弧斬向$n的$l",
                "dodge":                -30,
                "damage":               60,
                "damage_type":  "割傷"
        ]),
        ([
                "action"     : "\t交手數十回合後, $N劍法使的越來越渾厚如意﹐對劍法的領悟也越上一層, \n
\t逐步將[36m〔玉女劍法的精髓〕[0m融會貫通, 所以一出手就是六式或七式合一的招式, \n
\t一招一式遞向$n$l\n",
                "dodge"      :               -35,
                "parry"      :               -45,
                "damage"     :                90,
                "force"      :                220,
                "post_action":               (: berserk :),
                "damage_type":               "刺傷"
        ]),
        ([      "action": "    [1;33m由於敵人的武學也不弱，急於取勝的心理作用下!$N只好使出玉女劍法的高級劍招!\n
\t\t\t\t『[1;31m蛇蠍美人心[1;33m』\n
\t$N幻化出無一時之間, 劍光霍霍, 如同天女下凡一般, 令$n眼花撩亂!!![0m\n",
                "parry":             -60,
                "dodge":             -60,
                "force":          350,
                "damage":         150,
                "damage_type":   "刺傷"
         ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的內力不夠﹐沒有辦法練天女散花劍法。\n");

        if( (string)me->query_skill_mapped("force")!= "fireforce")
                return notify_fail("天女散花劍法可以配合聖火內功\一起修練。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必須先找一把劍才能練劍法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("girlsword", 1);
        limit= (int)(skill_level/9);
        if (limit < 4 )
                return action[random(4)];
        if (limit < 8 )
                return action[random(limit)];
        else if (limit < 10)
                      return action[random(6)+2];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的內力或氣不夠﹐沒有辦法練習天女散花劍法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所學練了一遍天女散花劍法。\n");
        return 1;
}

void berserk(object me, object victim, object  weapon, int damage)
{
    int lose, i, un,un1;
        un1 = 0;
        un  = 0;
        if(!me->query_temp("berserk" ))
        {
                lose = (int)(me->query_skill("girlsword", 1)/10 + 1);
                me->set_temp("berserk", 1);
                for(i = 0;i < lose; i++)
                {
                          un = random(10)+1;
                          un1 = un1+0.5*un;
                        me->set_temp("apply/attack", un1);
                        message_vision(HIC + "$N隨意使來就是〔玉女劍法〕的數式合一，侖快的劍招左飄右盪, 讓$n招架不已。\n" + NOR, me, victim);
                        victim->receive_damage("kee",2*un1);
                        me->add("force",-3);
           COMBAT_D->report_status(victim);
                }
                me->delete_temp("apply/attack");
                me->delete_temp("berserk");
                message_vision(HIW + "使出數十招後，$N內息一時調不回來，杵著劍站在原地休息休息。\n" + NOR,me);
                me->start_busy(2);
        }
}
