// mogi npc skill 之 穴殺鬼蜂
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void throw_weapon(object,object,object,int);
mapping *action = ({
	([	"action":		"$N繞圓快速地移動使出了一式"HIR"『奔舞』"NOR"，手中$w以巧妙的時間差毫無空隙地飛向$n的眉心",
		"dodge":        -40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
		"post_action":  (: throw_weapon :),
	]),
	([	"action":		"$N一式穴殺鬼蜂中的"HIR"『慘影』"NOR"激起陣陣陰氣，$w猶如流影飛星，虛幻若隱地疾",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
		"post_action":	(: throw_weapon :),
	]),
	([	"action":		"$N向天飛手一擲立時飛身與$n纏鬥，就在$n專心應戰之際，$N瞬間向後一躍，$w如暴雨驟落直刺向$n，此式便是穴殺鬼蜂中的"HIR"『滅絕』"NOR,
		"dodge":	-40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
		"post_action":	(: throw_weapon :),
	]),
	([	"action":		"$N踏天飛縱使出了穴殺鬼蜂中的一式"HIR"『鬼哭』"NOR"，剎那間鬼影幢幢，$w劃破空氣發出妖吼奔竄$n的胸腹要穴",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
		"post_action":	(: throw_weapon :),
	]),
        ([      "action":              "$N迅雷不及掩耳地將手裡的$w向$n的咽喉直擲，$n急速迴手一擋，卻不知影子裡竟藏著另一枚$w直指$n心窩",
                "dodge":        -25,
                "damage":       250,
                "force":        250,
                "parry":        -10,
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
