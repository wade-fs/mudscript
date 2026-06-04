// 給基本 force
#define ALLOW ({"doctor","dancer"})
#include <ansi.h>
int exert(object me, object target)
{
	int power;
	if( (int)me->query("force") < 30 )
		return notify_fail("你的內力不夠。\n");
	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("戰鬥中無法凝神療傷。\n");
	if( member_array(me->query("class"), ALLOW) == -1 )
		return notify_fail("你的職業無法凝神療傷。\n");
        power = 5 + (int)me->query_skill("force")/10;
    if(!target) target=me;
		if(target->query("max_gin") <= target->query("eff_gin"))
		    return notify_fail("已經不用再療精了！\n");
	if( target==me ){
message_vision(HIC + "$N盤腿而坐，連運內息之後，精力充足。\n" + NOR, me);
	}
	else{

message_vision(HIC + "$N運行全身內力幫助$n凝氣療傷，幾個內息之後，$n已慢慢精力充足起來。\n" + NOR, me, target);
                power = power/2;
	}
        target->receive_curing("gin", power );
	me->add("force", -power/2);
	return 1;
}
