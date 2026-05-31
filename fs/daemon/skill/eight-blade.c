// eight-blade.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出井中八法之「不攻」$w猛抖，腳踏奇步，$w登時湧起凜冽刀氣，遙罩$n，似攻非攻，似守非守。",
		"damage":		200,
		"dodge":		70,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N使出井中八法之「擊奇」，只見滿場$w刀光勁氣驀然收斂，$N身隨刀走，刀勁化作長虹，直朝$n射去。",
		"damage":		250,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N使出井中八法之「用謀」，$N將己身處於地利之中，將萬千刀影化成無形刀陣自顧己身，並將$n困於刀陣之中",
		"damage":		300,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N使出井中八法之「兵詐」，只見滿場$w刀光勁氣，$w刀影虛則實之，實則虛之，將$n籠罩在刀影之中。",
		"damage":		350,
		"damage_type":	"斲傷"
	]),
     ([  "action":       "$N使出井中八法之「棋奕」，將積聚至頂峰的氣勁，從$w刀鋒山洪暴發般洩出，形成一波又一波的氣勁，如裂岸的驚濤般鋪天蓋\地往$n湧去。",
		"damage":		400,
		"damage_type":	"斲傷"
	]),
	([	"action":		"$N使出井中八法之「戰定」，令$n看得目瞪口呆的連續百多刀，每一刀均從不同角度往$n攻去，刀刀妙至毫顛，似有意若無意，既態趣橫生，又是凶險至極點",
		"damage":		450,
		"damage_type":	"斲傷"
	]),
     ([  "action":       "$N使出井中八法之「速戰」，$w刀芒暴張，運刀疾刺，時間角度拿捏得精準無匹，刀鋒彷似貫注全身功\力感情，充滿一去無還的慘烈氣勢。",
		"damage":		500,
		"damage_type":	"斲傷"
	]),
        ([	"action":		"$N使出井中八法之「方圓」，氣牆為方，刀勁為圓，竟是隔三丈的距離，一柱圓渾的刀氣，從刀尖以螺旋的奇異方式江河暴漲地狂湧而出，往$n攻去。",
		"damage":		550,
		"damage_type":	"斲傷"
	]),
});

int valid_learn(object me)
{
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必須先找一把刀﹐才能練刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的體力不夠練這門刀法﹐還是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}
