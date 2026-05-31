// ironhand.c
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
	([	"action":"    $N使出鐵沙掌的第一式[33m「開門迎賓」[0m﹐通紅的右掌向$n的$l直直而去\n",
		"dodge":    -20,
		"force":    20,
		"damage":   30,
		"damage_type":	"瘀傷"
	]),
	([	"action":"    $N使出鐵沙掌第二式[33m「動如脫兔」[0m﹐左掌虛晃, 右掌趁勢忽緩忽快地擊向$n的
$l\n",
		"dodge":	-20,
                "force":        50,
		"damage":	40,
		"damage_type":	"瘀傷"
	]),
	([	"action":"    $N招式一變, 鐵沙掌第三式[33m「左右不分」[0m﹐左掌與右掌化拳向$n攻去, 待接觸
到敵人之前雙拳陡地化為雙掌, 順勢拍向$n的$l\n",
		"dodge":	-30,
                "force":        80,
		"damage":	55,
		"damage_type":	"瘀傷"
	]),
	([	"action":"    $N使出第四式--[33m「如影隨行」[0m, 剎時掌影翻動, 一路對準$n的$l, 時機成熟後,
重擊而下\n",
		"dodge":	-40,
                "force":        100,
		"damage":	75,
		"damage_type":	"瘀傷"
	]),
	([	"action":"    $N雙掌使將開來, 掌氣凌人﹐第五式[33m「千軍萬馬」[0m一經施展, 掌風呼呼朝向$n的
$l不斷地送出\n",
		"dodge":	-40,
                "force":        120,
		"damage":	90,
		"damage_type":	"瘀傷"
	]),
	([	"action":"    $N向前一撲﹐雙臂平伸, 雙掌向外, 待$n起掌來迎時, 猛然翻掌上下合擊, 
來招乃是鐵沙掌之第六式[33m「上下齊手」[0m, 掌勁直透$n的$l\n",
		"dodge":	-20,
                "force":        130,
		"damage":	105,
		"damage_type":	"瘀傷"
	]),
	([	"action":"    $N身形左右飄動﹐雙掌蓄勁而出, 擊在空中發出[轟轟]之聲, 敵人之思緒受
擾, 趁此之時, 鐵沙掌第七式[33m「鬼影幢幢」[0m 後發先至, 左掌從下三路朝$n$l一路直進\n",
		"dodge":	-20,
                "force":        180,
		"damage":	115,
		"damage_type":	"瘀傷"
	]),
	([	"action":"    $N馬步穩紮﹐雙腿前弓後箭, 氣運雙臂, 鐵沙掌之第八式[33m「氣勢磅礡」[0m挾著
山河之勢, 向$n襲捲而去, $n的$l登時被掌勁所籠罩\n",
		"dodge":	-30,
                "force":        250,
		"damage":	130,
		"damage_type":	"瘀傷"
	]),
        ([      "action": "    [1;33m由於敵人頑強抵抗，$N靈機一動, 將內力鼓催起來, 掌風呼嘯, 氣流飛湧, 鐵沙掌之\n
\t\t\t\t『[1;31m八式合一[1;33m』\n
\t$N化成一團紅色光圈, 如同一頭巨熊, 拔山倒樹而來!!![0m\n",
                "parry":          -60,
                "dodge":          -60,
                "force":          350,
                "damage":         150,
                "damage_type":   "瘀傷"
         ]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的內力不夠﹐沒有辦法練鐵沙掌法。\n");

	if( (string)me->query_skill_mapped("force")!= "fireforce")
		return notify_fail("鐵沙掌法可以配合聖火內功\一起修練。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("這是一套掌法又不是劍法或是刀法!!\n");

        if( me->query("family/master_name") != "司徒榮" && !me->query("study/ironhand",1)  )
        return notify_fail("沒有司徒榮本人的教導要怎麼練??\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("ironhand", 1);
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
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的內力或氣不夠﹐沒有辦法練習鐵沙掌法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著師父所授, 練了一遍鐵沙掌法。\n");
	return 1;
}


