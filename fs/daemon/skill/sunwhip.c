// 落日鞭法 ------by rence
// by hana 1997/3/2
 
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void hurt(object me, object victim, object weapon, int damage);
void bleed(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
int age , lv;

mapping *action = ({
        ([      "action":"\n$N使出落日鞭法第一式「日落西山」﹐手中$w橫掃$n的$l\n",
                "dodge":                -20,
                "damage":              30,
                "damage_type": "鞭傷",
        ]),

        ([      "action":"\n$N使出落日鞭法的第二式「日下無雙」﹐手中$w在空中連劃幾個圈之後向$n$l劈下\n",
                "dodge":                -20,
                "damage":                   40,
                "damage_type":  "割傷",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n$N一個飛身, 如大鷹覓食, 落日鞭法第三式「夸父追日」﹐手中$w拂向$n$l\n",
                "dodge":                -30,
                "damage":              50,
                "damage_type":  "割傷",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$N手中$w盤旋數圈﹐落日鞭法第四式「如日中天」對準$n$l由下往上直摜了過去\n",
                "dodge":                -40,
                "damage":              60,
                "damage_type":  "刺傷",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$N縱身一躍﹐手中$w使出第五式「日升月恆」往$n$l直直落下\n",
                "dodge":                -40,
                "damage":              70,
                "damage_type":  "淤傷",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$N的$w如長蛇遊戲一般﹐活靈活現, 第六式「扶搖直上」詭譎地向$n的$l捲去\n",
                "dodge":                -20,
                "damage":              80,
                "damage_type":  "刺傷",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n$N雙手握住$w﹐勁貫於上, 使出落日鞭法第七式「日月如梭」, 鞭尾化成利劍向$n$l刺去\n",
                "dodge":                -20,
                "damage":              90,
                "damage_type":  "刺傷",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$N大吼一聲﹐落日鞭法第八式「日月重光」在半空揮出一道圓弧後, 斜斜掃向$n$l\n",
                "dodge":                -30,
                "damage":               100,
                "damage_type":  "砍傷",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$N使出落日鞭法第九式「日落歸雁」，勁透長鞭, 手中$w如劍一般疾點$n的$l\n",
                "dodge":                -30,
                "damage":              110,
                "damage_type":  "刺傷",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$N身形連續打轉，使出鞭法第十式「日暮途窮」，$w化成弧光衝向$n的退路\n",
                "dodge":                -30,
                "damage":              120,
                "damage_type":  "瘀傷",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n\t\t突然間風聲大作，日月無光！$領悟了落日鞭法之最高境界！\n\n\t\t\t\t【 后 羿 射 日 】\n\n只見滿天鞭影密不透風地籠罩著$n\n",
                "dodge":                -30,
                "damage":              150,
                "damage_type":  "刺傷",
                "post_action": (: hurt :),
        ]),
});

void hurt(object me, object victim, object weapon, int damage)
{
        if( me->query("force_factor") > 5 )
        if( random(150) < random(lv))
        {
          victim->receive_damage("kee",lv*age/30);
          message_vision(HIM + "$N將真氣灌入鞭中射向$n，$n一陣哀嚎，顯然受了不小的內傷。\n" + NOR,me,victim);
          COMBAT_D->report_status(victim);
        }
}
void bleed(object me, object victim, object weapon, int damage)
{
        if(damage > 40)
        {
          victim->apply_condition("bleeding", random(lv*age)/100);
          message_vision("$N落日鞭法的氣勁貫穿$n，破體而出！\n",me,victim);
        }
}

void conti(object me, object victim, object weapon, int damage)
{
        int i;
        int lv1 = victim->query_skill("dodge",1);
        if( me->query("force_factor") >= 10 )
        {
          if( random(lv) > random(lv1) && me->query_temp("conti") == 0 )
            {
            me->set_temp("conti",1);
            message_vision("\n$N忽然頓悟落日鞭法的要訣，手中$w猛往$n身上招呼!!\n" ,me);
            for(i=0;  i <=   age/5  ;  i++)
            COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
            }
        }
}
int valid_learn(object me)
{
        object ob;
        //鞭法是第二專長, 將內力限制在50以上才能學  by hana
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的內力不夠﹐沒有辦法練\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("你必須先裝備鞭類武器才行。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
int age = this_player()->query("age",1);
int lv  = this_player()->query_skill("sunwhip",1);


        skill_level=(int)me->query_skill("sunwhip", 1);
        limit= (int)(skill_level/9);
        if (limit < 1 )
                return action[random(1)];
        if (limit < 2 )
                return action[random(2)];
        if (limit < 3 )
                return action[random(3)];
        if (limit < 4 )
                return action[random(4)];
        if (limit < 5 )
                return action[random(4)+1];
        if (limit < 6 )
                return action[random(4)+2];
        if (limit < 8 )
                return action[random(4)+3];
        else if (limit < 10)
                return action[random(4)+4];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        //鞭法不是聖火第一專長, 故氣與內力限制不必太嚴  by hana
        if ((int)me->query("kee") < 10)
        {
            return notify_fail("你的氣不足，無法練習落日鞭法。\n");
        } else if ((int)me->query("force") < 10)
        {
            return notify_fail("你的內力不夠，無法練習落日鞭法。\n");
        }
        me->receive_damage("kee", 10);
        me->add("force", -10);
        write("你按著所學練了一遍落日鞭法。\n");
        return 1;
}

