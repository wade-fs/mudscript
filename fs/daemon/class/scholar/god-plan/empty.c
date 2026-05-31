// By Swy 最後修正 QC 98/6/20
// 加入命中率限制 by frequency 2003 7/29
#include <ansi.h>
int perform(object me,object target)
{
    int i;
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
// 不是儒門的話....
    if( me->query("family/family_name") != "儒門")
		return notify_fail("不是儒生，不給你用咧！！^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");

		message_vision( HIC + @LONG
$N使用孔明兵法之中的空城計﹐使敵方生疑﹗
LONG + NOR , me );
		for( i = 0 ; i < sizeof(all) ; i ++ ) 
		all[i]->set_temp("empty",1);
		me->remove_all_killer();
      for(i=0;i<sizeof(all);i++)
      {
      if(all[i]->query_temp("no_plan") || all[i]->query("no_plan") || random(125)>100)
      {
      message_vision("$N嘿嘿笑道:對我使用空城計???哈哈,你搞錯對象了吧!!\n",all[i]);
      all[i]->kill_ob(me);
      }
      }
                me->start_busy(2);
        return 1;
}

