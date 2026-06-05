// 05/15/2010 by blazakira
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void special_force_damage(object me, object victim, object weapon, int damage);

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) //{ return 1; }
{ //增加與技能【大乘佛法】【小乘佛法】的相關性
	if( me->query_skill("buddhism",1)  && me->query_skill("selfhood",1) ) //第一個限制 得先知道佛法
		{
			if( me->query_skill("saulinforce",1) < 40 ) //可學到lv40
				{
				return 1; //return 1 則可以繼續學習
				}
			else if ( me->query_skill("saulinforce",1) < 80 && ( me->query("bonze/force/kingforce",1) || me->query("bonze/force/ponaforce",1) ) )
				{//第二階段 得選擇 金剛伏魔神通 與 破衲功 之一的內功才可繼續學習
				return 1;
				}
			else if ( me->query("bonze/force/arhatforce",1) || me->query("bonze/force/shenzuforce",1) )
				{//第三階段 選擇 羅漢伏魔神功 與 神足經 之一的內功才可繼續學習
				return 1;
				}
			else return notify_fail(HIY + "由於你辛勤不已的向師父請教少林內功\總綱上的疑惑，你終於到了「抉擇」的時刻了。\n" + NOR); //都不滿足的情況下
		}
	else //既然少林內功總綱<40 也沒學會其他四種內功 所以這個else應該針對第一個限制??
		{
//		tell_object(me, HIY + " 你得先知道什麼是佛法。\n" + NOR); //因為本程式會檢查兩次 所以改用其他方式回應
//		return 0; //為0時 則否
		return notify_fail(HIY + "你得先知道什麼是佛法。\n" + NOR);
		}
}

mapping *force_action = ({
([      "post_action": (: special_force_damage :) ])
});

int practice_skill(object me)
{
    return notify_fail("少林內功\總綱只能用學的﹐或是從(exert)中獲的熟練度。\n");
}

mapping query_action(object me, object weapon)
{
    return force_action[random(sizeof(force_action))];
}

string exert_function_file(string func)
{
    return CLASS_D("bonze")+"/saulinforce/"+func;
}
string perform_action_file(string action)
{
    return CLASS_D("bonze")+"/saulinforce/"+action;
}
        
void special_force_damage(object me, object victim, object weapon, int damage)
{
//   object target;
//   target=offensive_target(me);
    if( me->query("force_factor") == 10
            && me->query("force") >= 10 && damage > 0
            && me->query("bellicosity") < 100) //增加殺氣的判斷
        {
            message_vision("$N散發出一股浩然的" + HIY + "佛光" + NOR + "，渡化$n心中的殺意。\n", me, victim);
            victim->add("bellicosity", -1*me->query_skill("force")/3);
        }
}

void skill_improved(object me)
{
    int s;
    tell_object(me, HIY + "於禪坐中你漸漸進入更深沈的禪定，體會到了佛心，於是你的少林內功\總綱更上一層樓了！\n" + NOR);
    s = me->query_skill("saulinforce", 1);
    if( s%10==9 && random(s)>(int)me->query("max_force")/30) {
        tell_object(me, HIY + "你對於佛法禪義有了更深刻的了解，你體內的佛力被激發出來了。\n" + NOR);
        me->add("max_force", random((int)s/30)+1);
    }
}