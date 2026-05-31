// By Swy 最後修正 QC 98/6/20
// Modify by AceLan 調整命中率 99/04/05
// 改為可重複使用，不過命中率逐次降低。 by frequency 2003 7/29
#include <ansi.h>
int perform(object me,object target)
{
   int i;
   object *all = me->query_enemy();
   if(!me->is_fighting())
      return notify_fail("虛兵之計只能在戰鬥中使用。\n");
   if( me->query("sen") < 10 )
      return notify_fail("你的精神力不夠﹐無法用計。\n");
/*   if(all[i]->query_temp("false")==1)
   return notify_fail("此計對同一人無效。\n");*/
   if(all[i]->is_busy())
      return notify_fail("敵人正受你計謀所困,快趁機攻擊吧!\n");
   me->add("sen",-10);
// 不是儒門
   if( me->query("family/family_name") != "儒門")
      return notify_fail("不是儒生，不給你用咧！！^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");

   message_vision( HIG + @LONG
$N使用兵法中的虛兵之計﹐企圖牽制敵人的行動﹗
LONG + NOR , me , target );
   for( i = 0 ; i < sizeof(all) ; i ++ ) 
   {
   	if(random(5+all[i]->query_temp("false")) < 4)
   	{
         message_vision( HIG + @LONG
$n中了$N的虛兵之計﹐突然遲疑了一下﹐$N就在這個時後發動猛攻﹗
LONG + NOR ,me , all[i] );
         all[i]->start_busy(3);
	 all[i]->add_temp("false",1);
	}else{
	      message_vision( HIG + @LONG
$n識破了$N的虛兵之計﹐盛怒之下展開猛攻。
LONG + NOR ,me , all[i] );
              all[i]->kill_ob(me);
	      }
   }
   me->start_busy(1);
   return 1;
}

