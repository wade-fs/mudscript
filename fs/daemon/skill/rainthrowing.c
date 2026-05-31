//金風細雨樓skill之雨訣暗器 by roger&&taifar
//這是金風細雨樓一般護衛之skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void throw_weapon(object,object,object,int);
mapping *action = ({
	([	"action":		"$N一式『雨颯和山』，手裡$w漫天揮撒，瞬以指氣亂點制$n於招下，$w若暴雨驟落穿刺$n各處",
		"damage":	90,
                "force":        90,
		"post_action":  (: throw_weapon :),
	]),
	([	"action":		"$N十指輪彈使出一式『雨指平截』，十只$w以巧妙的排列和角度交錯縱橫，如一面流網穿梭飛向$n",
		"damage":	90,
                "force":        90,
		"post_action":	(: throw_weapon :),
	]),
	([	"action":		"$N踏樓迴落躬身飄散，使出一式『雨征橫曲』，$w如詭蛇旋繞曲竄，從出乎意料的方向射向$n"NOR,
		"damage":	90,
                "force":        90,
		"post_action":	(: throw_weapon :),
	]),
	([	"action":		"$N使出一式『雨朔斜虹』直射上中下三段，卻在$w出手的瞬間斜躍弧飛又朝$n顏胸腹射去",
		"damage":	90,
                "force":        90,
		"post_action":	(: throw_weapon :),
	]),
        ([      "action":              "$N屈身步塵使出一式『雨偽迴殤』，以掌欺敵的瞬間立刻踮步懸空，反手一擲，$w迅雷不及掩耳地射向$n",
		"damage":	90,
                "force":        90,
                "post_action":  (: throw_weapon :),
        ]),
});



int valid_enable(string usage)
{
        return usage=="throwing" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
             tell_object(me, "\n你的" + weapon->query("name") + "用完了﹗\n\n");
                }
                weapon->add_amount(-1);
        }
}
