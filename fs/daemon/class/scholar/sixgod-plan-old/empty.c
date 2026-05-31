// By Swy 最後修正 QC 98/6/20
#include <ansi.h>
int perform(object me,object target)
{
    int i,flag=0;
	object *all = me->query_enemy();
        if(!me->is_fighting())
		return notify_fail("空城計只能在戰鬥中使用。\n");
	if( me->query("sen") < 5 )
		return notify_fail("你的精神不夠集中﹐無法使用三十六計。\n");
	if( me->query_skill("plan",1) < 30 )
		return notify_fail("你的謀略能力不夠。\n");
		if( all[i]->query_temp("empty")==1 )
			return notify_fail("相同的謀略﹐再使用就失效了。\n");
    me->add("sen",-10);
// 不是儒門的化....
        if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
		message_vision( HIC + @LONG
$N使用孔明兵法之中的空城計﹐使敵方生疑﹗
LONG + NOR , me );
		for( i = 0 ; i < sizeof(all) ; i ++ ) 
		all[i]->set_temp("empty",1);
      for(i=0;i<sizeof(all);i++)
      {
      if(all[i]->query_temp("no_plan") || all[i]->query("no_plan"))
      {
    flag=1;
      message_vision("$N嘿嘿笑道:對我使用空城計???哈哈,你搞錯對象了吧!!\n",all[i]);
      all[i]->kill_ob(me);
      me->start_busy(2);
      }
      }
    if(!flag)
		me->remove_all_killer();
        return 1;
}

