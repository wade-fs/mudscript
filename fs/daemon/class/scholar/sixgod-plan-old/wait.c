// By Swy 最後修正 QC 98/6/20
#include <ansi.h>
int perform(object me,object target)
{
	int i;
	object *all;
	if( me->query("sen") < 10 )
		return notify_fail("你的精神不夠集中﹐無法用伏兵之計。\n");
	if( me->query_temp("invis")==1)
		return notify_fail("你尚未被發覺﹐不須再使用此計。\n");
// 儒門...
        if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
     if( me->query_skill("plan",1) < 75 )
		return notify_fail("你的謀略程度不夠。\n");
    me->add("sen",-15);
	message_vision( CYN + @LONG
$N開始埋伏起來﹐等待時機﹗
LONG + NOR , me );
	me->set_temp("invis",1);
	all = all_inventory(environment(me));
	for( i = 0 ; i < sizeof(all) ; i ++ ) 
	if( living(all[i]) ) all[i]->set_temp("see-wait",me);
	return 1;
}



