#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
//1
	([	"action"     :    HIW + "$N雙手一揚" + HIY + "『" + HIC + "天集雲湧" + HIY + "～◎～" + HIC + "萬風具滅" + HIY + "』" + HIW + "，剎那間天地雲氣狂湧，$n" + HIW + "已被重重的雲氣所包圍！" + NOR,
		"dodge"      :    85,
		"parry"      :   -35,
		"damage"     :    80,
		"force"      :    80,
		"damage_type":   "天傷",
	]),
//2
	([	"action"     :    HIW + "$N輕聲隨喚" + HIY + "『" + HIC + "妖身不滅" + HIY + "～◎～" + HIC + "凌霄虛空" + HIY + "』" + HIW + "，以無比的力量向$n" + HIW + "衝飛而至！" + NOR,
		"dodge"      :    85,
		"parry"      :   -35,
		"damage"     :    70,
		"force"      :    70,
		"damage_type":   "妖傷",
	]),
//3
	([	"action"     :    HIW + "$N輕巧的使出" + HIY + "『" + HIC + "此消彼長" + HIY + "～◎～" + HIC + "魔性橫生" + HIY + "』" + HIW + "，魔性愈發之下，聚集所有的能量向$n" + HIW + "重重轟去！" + NOR,
		"dodge"      :    85,
		"parry"      :   -35,
		"damage"     :    120,
		"force"      :    80,
		"damage_type":   "魔傷",
	]),
//4
	([	"action"     :    HIW + "$N嘆道：" + HIY + "『" + HIC + "人心不古" + HIY + "～◎～" + HIC + "哀莫心死" + HIY + "』" + HIW + "，招式似有似無的向$n" + HIW + "飄忽而至嚇得$n" + HIW + "無法招架！" + NOR,
		"dodge"      :    85,
		"parry"      :   -35,
		"damage"     :    70,
		"force"      :    90,
		"damage_type":   "心傷",
	]),
//5
	([	"action"     :    HIW + "$N殺的性起，使出一式" + HIY + "『" + HIC + "劫空無我" + HIY + "～◎～" + HIC + "忘情隨風" + HIY + "』" + HIW + "，瞬間已經到達忘我之境，殺的$n" + HIW + "遍體鱗傷！" + NOR,
		"dodge"      :    85,
		"parry"      :   -35,
                "damage"     :    80,
                "force"      :    90,
                "damage_type":   "情傷",
	]),
//6
	([	"action"     :    HIW + "$N一聲招喚，" + HIY + "『" + HIC + "千妖狂飛" + HIY + "～◎～" + HIC + "萬魔舞動" + HIY + "』" + HIW + "，千妖萬魔已向$n" + HIW + "齊攻而去！" + NOR,
		"dodge"      :    85,
		"parry"      :   -35,
		"damage"     :    130,
		"force"      :    130,
		"damage_type":   "壓傷",
	]),
//7
	([	"action"     :    HIW + "$N身形著地，腳踏兩地使出" + HIY + "『" + HIC + "地動天光" + HIY + "～◎～" + HIC + "迴影殘聲" + HIY + "』" + HIW + "，剎時間天搖地動，$n" + HIW + "漸漸受不了這樣的壓力！" + NOR,
		"dodge"      :    85,
		"parry"      :   -35,
		"damage"     :    100,
		"force"      :    105,
		"damage_type":   "地傷",
	]),
//8
	([	"action"     :     HIW + "$N用生命領悟了天地的奧秘，左手狂龍，右手天鳳，對$n" + HIW + "使出了" + HIY + "『" + HIC + "天翔鳳舞" + HIY + "～◎～" + HIC + "狂龍嘯天" + HIY + "』" + NOR + "！" + NOR,
		"dodge"      :    85,
		"parry"      :   -50,
		"damage"     :    100,
		"force"      :    100,
		"damage_type":   "吼傷",
	]),
//9
	([	"action"     :   HIW + "四周一股香味飄散開來，$N襲出一式" + HIC + "【" + HIM + "花香處處" + HIY + "～◎～" + HIM + "迎風飄散" + HIC + "】" + HIW + "飄向$n" + HIW + "之要害!!" + NOR,
                "dodge"      :    85,
                "parry"      :    60,
                "damage"     :    90,
                "force"      :    70,
                "damage_type":   "花傷",
	]),
//10
	([	"action"     :   HIW + "$N喃喃道：詩有可解不可解" + HIC + "【" + HIM + "鏡花水月" + HIY + "～◎～" + HIM + "如夢一場" + HIC + "】" + HIW + "勿泥其跡可也!!" + NOR,
                "dodge"      :    85,
                "parry"      :   -95,
                "damage"     :    40,
                "force"      :    90,
                "damage_type":   "鏡傷",
	]),
//11
	([	"action"     :   HIW + "$N有感而發" + HIC + "【" + HIM + "稍蹤即逝" + HIY + "～◎～" + HIM + "曇花一現" + HIC + "】" + HIW + "片片的花瓣漸漸殺向$n" + HIW + "!!" + NOR,
                "dodge"      :    85,
                "parry"      :    95,
                "damage"     :    60,
                "force"      :    90,
                "damage_type":   "曇傷",
	]),
//12
	([	"action"     :   HIW + "$N吟道：" + HIC + "【" + HIM + "錦上添花" + HIY + "～◎～" + HIM + "多此一舉" + HIC + "】" + HIW + "只見漫天的花葉夾著幾許\的殺傷力，襲向$n" + HIW + "!!" + NOR,
                "dodge"      :    85,
                "parry"      :    65,
                "damage"     :    70,
                "force"      :    90,
                "damage_type":   "錦傷",
	]),
//13
	([	"action"     :   HIW + "$N輕然飄起，" + HIC + "【" + HIM + "山洪花海" + HIY + "～◎～" + HIM + "競走一瞬" + HIC + "】" + HIW + "，瞬間已經帶著山洪般的力量擊向$n" + HIW + "!!" + NOR,
                "dodge"      :    85,
                "parry"      :    75,
                "damage"     :    110,
                "force"      :    110,
                "damage_type":   "情傷",
	]),
//14
	([	"action"     :   HIW + "$N輕吟一喚，" + HIC + "【" + HIM + "凝香冰雨" + HIY + "～◎～" + HIM + "春寒一步" + HIC + "】" + HIW + "，輕盈的身形已攻至$n" + HIW + "的近身處!!" + NOR,
                "dodge"      :    85,
                "parry"      :   -85,
                "damage"     :    100,
                "force"      :    110,
                "damage_type":   "壓傷",
	]),
//15
	([	"action"     :   HIW + "$N身形飄轉，隨著心境一轉而使出" + HIC + "【" + HIM + "花雨繽紛" + HIY + "～◎～" + HIM + "封靈一動" + HIC + "】" + HIW + "，$n" + HIW + "漸漸迷失在花雨的幻境中!!" + NOR,
                "dodge"      :    85,
                "parry"      :    75,
                "damage"     :    110,
                "force"      :    80,
                "damage_type":   "地傷",
	]),
//16
	([	"action"     :    HIW + "$N隨身揚起無數花瓣，激起一式" + HIC + "【" + HIM + "天花漫舞" + HIY + "～◎～" + HIM + "飄搖之間" + HIC + "】" + HIW + "散落$n" + HIW + "周身!!" + NOR,
                "dodge"      :    85,
                "parry"      :   -50,
                "damage"     :    90,
                "force"      :    90,
                "damage_type":   "吼傷",
	]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
	return ( usage=="unarmed" || usage=="parry" );
}

mapping query_action(object me, object weapon)
{
	if( me->query("id")=="dance wind")
	{
	return action[random(8)];
	}
	else if( me->query("id")=="tzan yuo")
	{
	return action[random(8)+8];
	}
	else
	{
        return action[random(sizeof(action))];
	}
}

int practice_skill(object me)
{
        return 1;
}
