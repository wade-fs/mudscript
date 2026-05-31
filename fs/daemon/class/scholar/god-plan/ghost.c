#include <ansi.h>
// By Swy 最後修正 QC 98/6/20
int perform(object me,object target)
{
	int i, dec;
        object *all = me->query_enemy();

        if(!me->is_fighting())
                return notify_fail("只能在戰鬥中使用。\n");
	if( me->query("sen") < 10 )
		return notify_fail("你的精神不夠﹐無法使用。\n");
        if( me->query_skill("plan",1) < 30 )
		return notify_fail("你的謀略程度不夠。\n");
      
 
 me->add("sen",-10);
// 不是儒門
   if( me->query("family/family_name") != "儒門")
      return notify_fail("不是儒生，不給你用咧！！^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
   for( i = 0 ; i < sizeof(all) ; i ++ )
   {
      if(all[i]->query_temp("ghost")==1)
         return notify_fail("對同一人只能用一次。\n");
      message_vision( RED + @LONG
$N突然地對使用$n欺敵之計﹐令$n手忙腳亂不知所措﹗
LONG + NOR , me , all[i] );
      all[i]->start_busy(2);
      all[i]->set_temp("ghost",1);
   }
      me->start_busy(1);
      return 1;
}

