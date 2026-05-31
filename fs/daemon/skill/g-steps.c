// by airke
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string reattack();

string *dodge_msg=({
      "$n使出追星步中的『"HIW"亂心訣"NOR"』﹐幻化出數個殘影。$N攻擊盡數打在空氣之中....\n",
      "$n步法交錯﹐正是『移星換位』，身形瞬時移動﹐避了開去。\n",
      "$n氣游全身，身體飄如浮萍，『天星換斗』斜斜地閃開攻擊。\n",
"$n逆轉真氣，倒踩『天罡\步法』，一瞬間已到了$N的背後。\n",
      "$n不慌不忙地使出『"HIB"追月連星步"NOR"』一連跨出數步，早已離開$N的攻擊範圍。\n",
"$n使出『"HIC"飛仙越浪"NOR"』罕世輕功\，輕輕一躍閃過這記快招。\n",
// (: reattack :),
    });

string reattack()
{
	object me , target;
	int react;
	string msg;
	me=this_player();
        react = (me->query_skill("g-steps",1) / 4) +5;
	target = offensive_target(me);
	target->receive_damage("kee",react);
	msg = me->query("name") + "使出一招" + HIR "逆轉乾坤" NOR + "將" +
	target->query("name") + "反擊回去。\n";
	return msg;
}	

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
  return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_enable(string usage) 
{
  return usage == "dodge" || usage == "move";
}


int practice_skill(object me)
{
	if( (int)me->query("gin") < 30 )
		return notify_fail("你的精不夠﹐不能練追星步法。\n");
	me->receive_damage("gin", 30);
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("taoist")+ "/g-steps/" +action;
}
