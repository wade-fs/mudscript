inherit SSERVER;
#include <ansi.h>
#include <combat.h>
inherit SKILL;
void whip(object me, object victim, object weapon, int damage);

string *parry_msg =
    ({
      "$n回身抽鞭，使出"+YEL+"〔"+MAG+"邪靈"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"防禦式，將$N的攻勢一一化去\n",
      "只見$n身形一轉，輕抖手中$l，圈出一個鞭花，往$N的$w捲去\n",
      "$n氣運$l，將$l舞成一個圈圈，護住身周五尺內\n",
      "$n急忙之際，使出一招『靈蛇出洞』，進身直攻，逼的$N收勢防守\n",
      "$n改守為攻，運氣於$l，$l頓時堅硬無比，$n看準了$N的攻勢，手持$l硬生生接下$N的招勢\n",
    });

mapping *action = ({
([ "action":"$N輕揮手中的$w，$w彷彿脫手毒蛇般，快速的打向$n",

        "dodge"	:	-20,
        "parry"	:	-25,
        "damage":	300,
        "damage_type":	    "鞭傷",

]),

([ "action":"$N挑高$w握柄處，順勢下揮，$w上下起伏，令$n無法捉摸$N的鞭路",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	350,
        "damage_type":	    "鞭傷",

]),

([ "action":"$N將$w脫手拋於天空，使出"+YEL+"〔"+MAG+"邪靈"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"-毒牙，只見$w急勢揮向$n",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	350,
        "damage_type":	    "鞭傷",
        "post_action":	(: whip :),

]),

([ "action":"$N揮動$w，一招"+YEL+"〔"+MAG+"邪靈"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"-綑獸術，$w在天空畫出一道圓弧，直撲$n",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	400,
        "damage_type":	    "鞭傷",
        "post_action":	(: whip :),

]),

([ "action":"$N快速揮動$w，$w猶如數萬條毒蛇爬行於地，一招"+YEL+"〔"+MAG+"邪靈"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"--群蛇鞭法直擊$n各路穴道",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	450,
        "damage_type":	    "鞭傷",
        "post_action":	(: whip :),

]),

([ "action":"$N手一抖，一招"+YEL+"〔"+MAG+"邪靈"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"--幽雷暴雨，已經迅然直攻$n",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	500,
        "damage_type":	    "鞭傷",
        "post_action":	(: whip :),

]),

([ "action":"$N揮鞭併足，以腳技搶攻$n的下半身，又以$w使出"+YEL+"〔"+MAG+"邪靈"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"--"+HBWHT+HIR+"邪靈幻化"+NOR+"，直逼$n",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	550,
        "damage_type":	    "鞭傷",
        "post_action":	(: whip :),

]),

([ "action":"$N輕揮$w，一招"+YEL+"〔"+MAG+"邪靈"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"--"+HBWHT+"無招無勢"+NOR+"，鞭子已經撲向$n",
 
        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	600,
        "damage_type":	    "鞭傷",
        "post_action":	(: whip :),

]),

});

void whip(object me,object victim,object weapon,int damage)
{
int i,j,k;

	i = (int)me->query_skill("whip");
	j = (int)victim->query_skill("dodge");

	if( i < random(j) )
	{
		message_vision(HIR+"$N"+HIR+"鞭法突然雜亂無章...$n"+HIR+"一個躲避不及～被鞭子劃過了身旁～\n"NOR,me,victim);
		victim->receive_wound("kee",100);
		COMBAT_D->report_status(victim,1);
	}
	
	if( (int)victim->query_busy() < 2 && random(100) < 20 )
	{
		message_vision(HIY+"$N"+HIY+"的鞭法捆住了$n"+HIY+"，令$n"+HIY+"頓時無法動彈～\n"NOR,me,victim);
		victim->start_busy(1);
	}
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
