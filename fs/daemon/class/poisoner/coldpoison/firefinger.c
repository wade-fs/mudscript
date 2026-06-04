#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	object ob;
	string *name;
        int fun=me->query("functions/firefinger/level");
	if( !target ) target = offensive_target(me);
    if(!target) return notify_fail("你找不到敵人!!\n");
//不能攻擊自己by bss
    if(target==me) return notify_fail("攻擊自己??找死嗎?\n");
        if(me->query("class")!="poisoner")
        return notify_fail("只有魔教徒能用。\n");
	if(!me->is_fighting(target))
	return notify_fail("火雲柔指要在戰鬥中才能使用。\n");
	if(me->query("force")<110)
	return notify_fail("你的內力不夠。\n");
	if(me->query_skill("coldpoison",1)<30)
	return notify_fail("你的天冰奇毒火喉不夠﹐無法使用火雲柔指。\n");
	message_vision( HIR + "$N身形一轉﹐右手食指指尖散出紅光﹐忽地一指伸出﹐往$n點去﹗\n",me,target);
if(80>random(100))
	{
message_vision( HIC + "$n一發覺不妙﹐可惜已經來不及了﹐$N右手指尖已在$n劃出一道傷痕。\n",me,target);
target->apply_condition("fire_poison",5);
if(target->query_temp("poison/fire_poison"))
  target->set_temp("poison/fire_poison",target->query_temp("poison/fire_poison") - ({ me }) - ({ 0 }) + ({ me }) );
else
  target->set_temp("poison/fire_poison",({ me }));

target->receive_damage("kee",(100+(7*fun)));
	}
	else
	message_vision( HIC + "$n發覺不妙﹐身子輕輕一縱﹐一個轉身避了開去。\n",me,target);
	me->add("force",-100);
        me->start_busy(1);
if(fun<100) function_improved("firefinger",random(500));
	message_vision( NOR,me);
	return 1;
}
