#include <ansi.h>
// by sueplan 寂靜計
// busy型
int perform(object me,object target)
{
	int i, dec;
        object *all = me->query_enemy();

        if(!me->is_fighting())
        return notify_fail("只能在戰鬥中使用。\n");
        if( me->query("sen") < 100 )
		return notify_fail("你的精神不夠﹐無法使用。\n");
// 不是儒門
        if( me->query("family/family_name") != "儒門")
        return notify_fail("不是儒生，不給你用咧！！^_^\n");
   if(all[i]->is_busy())
     return notify_fail("敵人正受你計謀所困,快趁機攻擊吧!\n");
        me->add("sen",-20);
        me->add("force",-50);
   for( i = 0 ; i < sizeof(all) ; i ++ )
   {
      if(all[i]->query_temp("busy-plan")==3)
         return notify_fail("此計只能對同一人只能用三次。\n");
      message_vision( HIY + @LONG
$N使出了六韜奇略中的寂靜計, $n跟本察覺不到自己已經面臨危機!!!
LONG + NOR , me , all[i] );
        all[i]->start_busy(4);
     all[i]->add_temp("busy-plan",1);
   }
      me->start_busy(1);
      return 1;
}

