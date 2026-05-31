#include <ansi.h>
// By Swy 最後修正 QC 98/6/20
int perform(object me,object target)
{
	if( me->query("sen") < 10 )
		return notify_fail("你的精神不夠﹐無法使用。\n");
        if( me->query_skill("plan",1) < 60 )
		return notify_fail("你的謀略程度不夠。\n");
	if( !target ) return notify_fail("你要對誰用計 ?\n");
	if(me->is_fighting(target))	
		return notify_fail("奇襲之計只能在戰鬥前使用。\n");
  if( environment(me)->query("no_fight")==1 )
  return notify_fail("這裡不準戰鬥。\n");
if( userp(target) && target->query("age")<16)
    return notify_fail("不能對未滿16歲奇襲喔。\n");
  if(target->query("no_speed")==1)
  return notify_fail("奇襲對他無效！\n");
   if( target->query_temp("speed")==1 )
                return notify_fail("相同的計策對同一個人沒有效。\n");
	me->add("sen",-15);
// 不是儒門
   if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
    me->start_busy(1);
	message_vision( RED + @LONG
$N突然地對$n發動奇襲﹐殺得$n措手不及﹗
LONG + NOR , me , target );
	if(me->query_temp("invis")==1)
	{
        me->delete_temp("invis");
target->set_temp("speed",1);
target->start_busy(4);
        me->kill_ob(target);
        target->kill_ob(me);
	}
	else
        target->start_busy(3);
        target->set_temp("speed",1);
	me->kill_ob(target);
	target->kill_ob(me);
	return 1;
}

