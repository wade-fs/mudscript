// mirage-steps.c  //離影迷縱步// write by cch

inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
	"$n雙袖一揚,"CYN".......一陣青煙從地底冒出........ "+NOR",
一招"HIC"『煙霧瀰三江』"+NOR",$n已不知去向,$N似忽陷入迷境,不知如何出招。\n",
	"只見$n身影一晃,騰空而起,使出"HIB"『星垂暗影落』"+NOR",身驅有如星拋丸擲,
畫出一條曼妙的圓弧,$n的招式早以落空。\n",
	"$n使出離影迷蹤步之"HIY"『凌風無形跡』"+NOR",身形如燕,身影隨風幻化方位,
$N的招式始終差了三寸,瀟灑的避過每一招。\n",
	"$n隨意使出一招"HIG"『翠影映波瀾』"+NOR",左足一點,身形一閃,早以繞到$N身後。\n",
	"$n身影微動,腳踏醉仙望月步,正是一招"HIW"『舞影醉人痴』"+NOR",身形飄緲虛幻,
穿梭在$N的攻勢之下,$n竟仍留於原地。\n",
	"$n凌空飛起,使出一招"HIC"『縈迴盪秋波』"+NOR",擰身一折,忽左忽右的飄開,
$N招式未到,$n早以飄落三尺開外之處。\n",
        "$n頓時心無雜念,意隨念轉,眼看$N攻勢逼進,口中喃喃自語,霎那間,一靈三化,
$N顯然以分不出虛實,招招向殘影擊去. \n",  
      
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if(me->query ("combat_exp") <= (me->query_skill("mirage-steps",1)*6) )
                return notify_fail("你的實戰經驗不足,無法體會步訣之精奧。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的內力不夠,無法練離影迷縱步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 10 )  
             return notify_fail("你的氣不夠﹐不能練『離影迷縱步』。\n");
        if( (int)me->query("force") < 30 )
             return notify_fail("你的內力不夠﹐無法練『離影迷縱步』。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
