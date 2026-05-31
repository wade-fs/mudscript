// By Swy 最後修正 QC 98/6/20
// Modify by AceLan 調整命中率 99/04/05
#include <ansi.h>
int perform(object me,object target)
{
   int i;
   object *all = me->query_enemy();
   if(!me->is_fighting())
      return notify_fail("連環計只能在戰鬥中使用。\n");
   if( me->query("sen") < 30 )
      return notify_fail("你的精神力不夠﹐無法用計。\n");
   if( me->query_skill("plan",1) < 105 )
      return notify_fail("你的謀略能力不夠。\n");
   if(all[i]->query_temp("lock-link")==1)
   return notify_fail("此計對同一敵人只能用一次。\n");
   if(all[i]->is_busy())
     return notify_fail("敵人正受你計謀所困,快趁機攻擊吧!\n");
   me->add("sen",-20);
// 不是儒門
   if( me->query("family/family_name") != "儒門")
      return notify_fail("不是儒生，不給你用咧！！^_^\n");
    message_vision( HIB + @LONG
$N使用兵法中的鐵鎖連環計﹐企圖牽制敵人的行動﹗
LONG + NOR , me , target );
   for( i = 0 ; i < sizeof(all) ; i ++ ) 
   {
         message_vision( CYN + @LONG
$n中了$N的鐵鎖連環之計﹐行動被牽制住了﹗
LONG + NOR , me , all[i] );
         all[i]->start_busy(3);
         all[i]->set_temp("lock-link",1);
}
   me->start_busy(1);
   return 1;
}

