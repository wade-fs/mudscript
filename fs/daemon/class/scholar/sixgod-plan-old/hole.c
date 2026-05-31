// By Swy 最後修正 QC 98/6/20
#include <ansi.h>
int perform(object me,object target)
{
	int i;
	string myhole;
	myhole = me->query("name") + "hole";
	if( !target )
	{
	if( me->query("kee") < 20 )
		return notify_fail("你氣力不夠﹐如何製做陷阱。\n");
	if( me->query_skill("plan",1) < 90 )
		return notify_fail("你的謀略能力不夠。\n");
        if(me->is_fighting(target))
                return notify_fail("陷阱只能在戰鬥前使用。\n");
	if( environment(me)->query_temp(myhole) )
		return notify_fail("你的陷阱已經做好﹐不需要再做了。\n");
    me->add("kee",-15);
// 儒門...
        if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
		message_vision(HIG + @LONG
在一陣忙碌之後﹐$N成功的做好了陷阱。
LONG + NOR , me );
		environment(me)->set_temp(myhole,1);
}
	else
	{
	if( me->query("sen") < 30 )
		return notify_fail("你的精神力不夠﹐無法用計。\n");	
	if( me->query_skill("plan",1) < 90 )
		return notify_fail("你的謀略能力不夠。\n");
	if( !environment(me)->query_temp(myhole))
	return notify_fail("你並沒有在此做陷阱﹐無法使用此計。\n");
   if(target->query("no_hole")==1)
   return notify_fail("陷阱對他無效！\n");
  if(target->is_busy())
  return notify_fail("敵人busy中，快攻擊吧！\n");
	me->add("sen",-30);
 if(80>random(100))
	{
	message_vision(RED + @STRING
$n一聲驚呼﹐陷入$N的陷阱之中﹐無法動彈﹗﹗
STRING + NOR,me,target );
		if(target->query_temp("follow")==1)
		{
 target->start_busy(4);
 environment(me)->delete_temp(myhole);
 target->kill_ob(me);
 target->delete_temp("follow");
		}
		else
		{ 
target->start_busy(3);
		environment(me)->delete_temp(myhole);
		}
	}
        else
        message_vision(CYN + @STRING
$n眼明腳快﹐躲開了$N所佈下的陷阱。
STRING + NOR,me,target );        
}
   me->start_busy(1);
        return 1;
}




