//金風細雨樓skill 之不見風雨
//這是金風細雨樓npc的標誌,使用這一個parry skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
 "$n使出一式" + HIY + "『熡羽飄金』" + NOR + "，由下傾上貫足全力直往$N的來勢對峙，彈開了$N的攻擊\n",
 "$n一式" + HIC + "『紗捲天風』" + NOR + "迴手振袖毫不猶豫地捲向$n的來襲，只在一扶一探之間已錯換了兩人的位置\n",
 "$n靜步止身摒息而視，$N的一舉一動盡在$n眼下，瞬間，$n飛對而衝使出" + HIW + "『千粉渀細』" + NOR + "點開了$N的攻擊\n",
 "$n飛身數丈瞬又旋迴而墜使出" + HIG + "『泓竹棻雨』" + NOR + "，如落雨千萬點點指向$N分化了$N的力量\n",
 "$n元轉雙足使出一式" + HIM + "『馥傾真樓』" + NOR + "，疾速迴轉，在身周織成一片光環成網，使$N的攻擊盡化成灰\n",
});

int valid_enable(string usage)
{
	return (usage=="parry");
}


string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}


