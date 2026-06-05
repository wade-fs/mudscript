// winter-steps.c
#include <combat.h>
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({

"" + HIW + "$n展現" + HIC + "『冬霜初降』" + HIW + "身形忽隱忽現，令$N捉摸不定，就輕易閃開" + NOR + "\n",

"" + HIW + "$n使出" + HIB + "『霜雪紛紛』" + HIW + "身形化為千影，迅速移位，殘像遍佈，頃刻如霜雪般在$N四週" + NOR + "\n",

"" + HIW + "$n面對$N的攻勢，任何一招都會令你受傷不輕，於是$n利用" + HIC + "『霜雪難辨』" + HIW + "閃開" + NOR + "\n",

"" + HIW + "$n使出" + HIB + "『凝氣成霜』" + HIW + "，瞬間四周的溫度劇降，將$N定住不動！" + NOR + "\n",

"" + HIW + "$n施展" + HIB + "『冬霜冰雪步』" + HIW + "身法式" + HIC + "『霜雪紛飛』" + HIW + "，身隨意轉，遊走於$N四周，避開$N攻擊" + NOR + "\n",

"" + HIW + "$n展現" + HIB + "『冬霜冰雪步』" + HIW + "拆卸式" + HIC + "『霜融為水』" + HIW + "，身形如水般的轉開，靜觀$N的弱點" + NOR + "\n",

"" + HIW + "$n使出" + HIB + "『冬霜冰雪步』" + HIW + "攻擊式" + HIC + "『暴風雪』" + HIW + "，綿綿不斷向$N展開攻擊" + NOR + "\n",

"" + HIW + "$n打出" + HIB + "『冬霜冰雪步』" + HIW + "困住式" + HIC + "『霜雪急凍』" + HIW + "，霜雪不斷凝聚在$N身邊，將$N凍結" + NOR + "\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
     if(me->query_skill("literate",1) < 10)
           return notify_fail("你的讀書識字不夠﹐沒辦法領悟冬雪寒霜步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
              if((int)me->query("sen")<60)
                 return notify_fail("你的神不夠不能練冬雪寒霜步。\n");
           me->receive_damage("sen",60);
           me->improve_skill("winter-steps",me->query_skill("literate")/10+1);
	return 1;
}
