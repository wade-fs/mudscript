// By Swy 最後修正 QC 98/6/20
// Modify by AceLan 調整命中率 99/04/05
#include <ansi.h>
int perform(object me,object target)
{
   int i;
   if( !target ) return notify_fail("你要對誰用計 ?\n");
   if( userp(target) ) return notify_fail("這招對玩者沒用。\n");
   if( me->query("sen") < 20 )
      return notify_fail("你的精神力不夠﹐無法用計。\n");
   if( me->query_skill("plan",1) < 45 )
      return notify_fail("你的謀略能力不夠。\n");
   if( target->query_temp("follow")==1 )
      return notify_fail("相同的計策對同一個人沒有效。\n");
   if( target->query("no_plan_follow") == 1)
       return notify_fail("此計策無法對此人使用!!!\n");
   me->add("sen",-15);
// 儒門...
   if( me->query("family/family_name") != "儒門")
      return notify_fail("不是儒生，不給你用咧！！^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
   me->start_busy(1);

         if(target->query_temp("no_plan") || target->query("no_plan"))
         {
         message_vision("$N忽然大聲的說道,竟敢對我使出誘敵計,看來你是不想活了!!\n
         \n",target);
         target->kill_ob(me);
         me->start_busy(3);
         }
         else{
      message_vision(HIG + @LONG
$n中了$N的誘敵之計﹐突然勃然大怒﹐看來$n不殺死$N是不會甘休的﹗
LONG + NOR , me , target );
      target->set_leader(me);
target->kill_ob(me);
         }
      target->set_temp("follow",1);
   return 1;
}

