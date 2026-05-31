#include <combat.h>
#include <ansi.h>

inherit SKILL;

void flower(object me, object victim,object weapon, int damage);
void dance(object me, object victim,object weapon, int damage);

mapping *action = ({
//1
	([	"action"     :    HIW"$N雙手一揚"HIY"『"HIC"天集雲湧"HIY"～◎～"HIC"萬風具滅"HIY"』"HIW"，剎那間天地雲氣狂湧，$n"HIW"已被重重的雲氣所包圍！"NOR,
		"dodge"      :   -35,
		"parry"      :	 -35,
		"damage"     :    80,
		"force"      :    80,
		"post_action":   (: dance :),
		"damage_type":   "天傷",
	]),
//2
	([	"action"     :    HIW"$N輕聲隨喚"HIY"『"HIC"妖身不滅"HIY"～◎～"HIC"凌霄虛空"HIY"』"HIW"，以無比的力量向$n"HIW"衝飛而至！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    70,
		"force"      :    70,
		"post_action":   (: dance :),
		"damage_type":   "妖傷",
	]),
//3
	([	"action"     :    HIW"$N輕巧的使出"HIY"『"HIC"此消彼長"HIY"～◎～"HIC"魔性橫生"HIY"』"HIW"，魔性愈發之下，聚集所有的能量向$n"HIW"重重轟去！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    120,
		"force"      :    80,
		"post_action":   (: dance :),
		"damage_type":   "魔傷",
	]),
//4
	([	"action"     :    HIW"$N嘆道："HIY"『"HIC"人心不古"HIY"～◎～"HIC"哀莫心死"HIY"』"HIW"，招式似有似無的向$n"HIW"飄忽而至嚇得$n"HIW"無法招架！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    70,
		"force"      :    90,
		"post_action":   (: dance :),
		"damage_type":   "心傷",
	]),
//5
	([	"action"     :    HIW"$N殺的性起，使出一式"HIY"『"HIC"劫空無我"HIY"～◎～"HIC"忘情隨風"HIY"』"HIW"，瞬間已經到達忘我之境，殺的$n"HIW"遍體鱗傷！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
                "damage"     :    80,
                "force"      :    90,
		"post_action":   (: dance :),
                "damage_type":   "情傷",
	]),
//6
	([	"action"     :    HIW"$N一聲招喚，"HIY"『"HIC"千妖狂飛"HIY"～◎～"HIC"萬魔舞動"HIY"』"HIW"，千妖萬魔已向$n"HIW"齊攻而去！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    130,
		"force"      :    130,
		"post_action":   (: dance :),
		"damage_type":   "壓傷",
	]),
//7
	([	"action"     :    HIW"$N身形著地，腳踏兩地使出"HIY"『"HIC"地動天光"HIY"～◎～"HIC"迴影殘聲"HIY"』"HIW"，剎時間天搖地動，$n"HIW"漸漸受不了這樣的壓力！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    100,
		"force"      :    105,
		"post_action":   (: dance :),
		"damage_type":   "地傷",
	]),
//8
	([	"action"     :     HIW"$N用生命領悟了天地的奧秘，左手狂龍，右手天鳳，對$n"HIW"使出了"HIY"『"HIC"天翔鳳舞"HIY"～◎～"HIC"狂龍嘯天"HIY"』"NOR"！"NOR,
		"dodge"      :    40,
		"parry"      :   -50,
		"damage"     :    100,
		"force"      :    100,
		"post_action":   (: dance :),
		"damage_type":   "吼傷",
	]),
//9
	([	"action"     :   HIW"四周一股香味飄散開來，$N襲出一式"HIC"【"HIM"花香處處"HIY"～◎～"HIM"迎風飄散"HIC"】"HIW"飄向$n"HIW"之要害!!"NOR,
                "dodge"      :    35,
                "parry"      :    60,
                "damage"     :    90,
                "force"      :    70,
		"post_action":   (: flower :),
                "damage_type":   "花傷",
	]),
//10
	([	"action"     :   HIW"$N喃喃道：詩有可解不可解"HIC"【"HIM"鏡花水月"HIY"～◎～"HIM"如夢一場"HIC"】"HIW"勿泥其跡可也!!"NOR,
                "dodge"      :    75,
                "parry"      :   -95,
                "damage"     :    40,
                "force"      :    90,
		"post_action":   (: flower :),
                "damage_type":   "鏡傷",
	]),
//11
	([	"action"     :   HIW"$N有感而發"HIC"【"HIM"稍蹤即逝"HIY"～◎～"HIM"曇花一現"HIC"】"HIW"片片的花瓣漸漸殺向$n"HIW"!!"NOR,
                "dodge"      :   -65,
                "parry"      :    95,
                "damage"     :    60,
                "force"      :    90,
		"post_action":   (: flower :),
                "damage_type":   "曇傷",
	]),
//12
	([	"action"     :   HIW"$N吟道："HIC"【"HIM"錦上添花"HIY"～◎～"HIM"多此一舉"HIC"】"HIW"只見漫天的花葉夾著幾許\的殺傷力，襲向$n"HIW"!!"NOR,
                "dodge"      :    135,
                "parry"      :    65,
                "damage"     :    70,
                "force"      :    90,
		"post_action":   (: flower :),
                "damage_type":   "錦傷",
	]),
//13
	([	"action"     :   HIW"$N輕然飄起，"HIC"【"HIM"山洪花海"HIY"～◎～"HIM"競走一瞬"HIC"】"HIW"，瞬間已經帶著山洪般的力量擊向$n"HIW"!!"NOR,
                "dodge"      :    65,
                "parry"      :    75,
                "damage"     :    110,
                "force"      :    110,
		"post_action":   (: flower :),
                "damage_type":   "情傷",
	]),
//14
	([	"action"     :   HIW"$N輕吟一喚，"HIC"【"HIM"凝香冰雨"HIY"～◎～"HIM"春寒一步"HIC"】"HIW"，輕盈的身形已攻至$n"HIW"的近身處!!"NOR,
                "dodge"      :    65,
                "parry"      :   -85,
                "damage"     :    100,
                "force"      :    110,
		"post_action":   (: flower :),
                "damage_type":   "雨傷",
	]),
//15
	([	"action"     :   HIW"$N身形飄轉，隨著心境一轉而使出"HIC"【"HIM"花雨繽紛"HIY"～◎～"HIM"封靈一動"HIC"】"HIW"，$n"HIW"漸漸迷失在花雨的幻境中!!"NOR,
                "dodge"      :   -65,
                "parry"      :    75,
                "damage"     :    110,
                "force"      :    80,
		"post_action":   (: flower :),
                "damage_type":   "靈傷",
	]),
//16
	([	"action"     :    HIW"$N隨身揚起無數花瓣，激起一式"HIC"【"HIM"天花漫舞"HIY"～◎～"HIM"飄搖之間"HIC"】"HIW"散落$n"HIW"周身!!"NOR,
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    90,
                "force"      :    90,
		"post_action":   (: flower :),
                "damage_type":   "舞傷",
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
	return action[random(16)-8];
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

void dance(object me, object victim,object weapon, int damage)
{
	object *enemy;
	int i,j,k,pow,ext,tim=100;
	me=this_player();
	k=random(15)+5;
	ext = (int)(me->query("combat_exp",1)/1000000);

	if( ext <= 0 ) ext = 1;

	if( interactive(victim) )
	{
	pow=(int)(((100)*tim)/500);
	}else{
	pow=(int)(((100)*tim)/10);
	}
	enemy = me->query_enemy();
	for(i=0; i<sizeof(enemy); i++)
	{
	  if( !enemy[i] )	continue;
	  for( j=0; j < k; j++ )
	  {
	    if(random(me->query("combat_exp")*ext) > random(enemy[i]->query("combat_exp")))
	    {
        enemy[i]->receive_wound("kee",pow,me);
	    enemy[i]->receive_wound("gin",pow,me);
	    enemy[i]->receive_wound("sen",pow,me);
        COMBAT_D->report_status(enemy[i]);
	    }else{
        enemy[i]->receive_wound("kee",pow,me);
	    enemy[i]->receive_wound("gin",(int)(pow/2),me);
	    enemy[i]->receive_wound("sen",(int)(pow/2),me);
        COMBAT_D->report_status(enemy[i]);
	    }
	  }
	}
	victim->start_busy(1);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
	victim->apply_condition("five_poison",victim->query_condition("five_poison")+5);
	victim->set("force",0);
	COMBAT_D->report_status(victim);
}

void flower(object me, object victim,object weapon, int damage)
{
	int i;

	if( !me->query_temp("conti") )
	{
	me->set_temp("conti",1);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
	me->delete_temp("conti");
	}
	victim->start_busy(1);
	COMBAT_D->report_status(victim);
	victim->apply_condition("ghost",victim->query_condition("ghost")+5);
	victim->set("force_factor",0);
}
