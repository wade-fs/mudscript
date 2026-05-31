// 金風細雨樓skill 之 盤古開天刀法
//第一樓樓主刁千刃武功
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N收刀聚氣，蓄勢待發，空氣逐漸凝結，就在$n步入刀界的瞬間$N一式"HIR"『劈天破日』"NOR"渾厚的刀氣激烈地向$n拂掃而去",
		"damage":	600,
                "force":        600,
                "damage_type" : "砍傷"
	]),
	([	"action":		"$N雙握$w，單足踮步拔身數丈以高制低，一式"HIY"『剖天斷月』"NOR"凝重了空氣，刀光如弧月劃天直直朝$n落下",
		"damage":	600,
                "force":        600,
                "damage_type" : "砍傷"	
	]),
	([	"action":		"$N拔足飛身使出一式"HIC"『擎天挾宇』"NOR"朝$n追去，激起碎天刀氣隨風而揚急追$n",
		"damage":	600,
                "force":        600,
                "damage_type" : "砍傷"	
	]),
	([	"action":		"$N御氣飛刀，一式"HIW"『吞天推谷』"NOR"手裡$w已迴繞至$n背後，如迅雷一瞬，人刀錯位，卻在眨眼間刀已回鞘",
		"damage":	600,
                "force":        600,
                "damage_type" : "劈傷"		
	]),
        ([      "action":              "$N貫力一式"HIC"『盤古開天刀法』"NOR"中的"HIC"『劃天落命』"NOR"，迅速地向前揮刀而去，猛烈的力道將$n震浮飛空，瞬間反手倏上，刀光直突上天",
		"damage":	600,
                "force":        600,
                "damage_type" : "劈傷"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

