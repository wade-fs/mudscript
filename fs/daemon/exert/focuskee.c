// focuskee.c
#include <ansi.h>
int exert(object me)
{
	object weapon;
	if(me->query("class") != "blademan")
	return notify_fail("只有刀客才能將真力灌入刀身。\n");
	if(me->query("force")<me->query_skill("blade")/10+50)
	  return notify_fail("你的內力不夠。\n");
	if(!objectp(weapon=me->query_temp("weapon"))
	|| (string)weapon->query("skill_type")!="blade")
	  return notify_fail("要有刀才能用聚氣刀術。\n");
	if(weapon->query_temp("focuskee")==1)
	  return notify_fail("你已經在用了。\n");
 if(me->query_temp("usebladekee"))
 return notify_fail("你已經在用了。\n");  
	me->add("force",-50-me->query_skill("blade")/10);
	message_vision(
	HIR + "$N發出一陣狂吼﹐將真力貫入手中的$n﹐使$n發出一陣輕爆聲。\n" + NOR,me,weapon);
me->set_temp("usebladekee",1);
	me->add_temp("apply/damage",me->query_skill("force")/10+me->query_skill("blade")/5+15);
	weapon->set_temp("focuskee",1);
	me->start_call_out( (: call_other,__FILE__,"remove_effect",weapon,me :),me->query_skill("force")/2);
	return 1;
}
void remove_effect(object weapon,object me)
{
    if(!me || !weapon) return ;
	me->add_temp("apply/damage",-me->query_skill("force")/10-me->query_skill("blade")/5-15);
	weapon->delete_temp("focuskee");
 me->delete_temp("usebladekee");
message_vision("$N手中的$n所散發出的霸氣消失了。\n",me,weapon);
}
