
inherit SKILL;

string *dodge_msg = ({
    "$n一個「月上柳柣頭」，隨著$N的攻勢飄起，從容躲過這一招。\n",
    "$n使出一招「大漠孤煙直」，猛然縱起丈餘，結果$N撲了個空。\n",
    "$n身形一搖，喚出幾個人，一招「碎影舞斜陽」躲過了$N的攻勢。\n",
    "$n一招「燕子三抄水」縱身躍起，倏忽已落至$N身後。\n",
    "$n左一搖，右一晃，一招「雲深不知處」已輕鬆閃過。\n",
    "$n雙足一點，斜斜飛起，使出「斜日杏花飛」已閃到$N身側。\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
            return notify_fail("你的體力太差了，不能練暗影浮香。\n");
        if (me->query_skill("yan-shuangfei", 1) < 30)
	        me->receive_damage("kee", 10);
		me->receive_damage("kee", 20);
        return 1;
}
