#include <ansi.h>
#include <command.h>
inherit SSERVER;
inherit F_CLEAN_UP;
void remove_effect(object me);
int perform(object me, object target)
{
   if( target != me)
   return notify_fail("此計只能對自己用。\n");
   if( me->is_fighting())
      return notify_fail("沒有水...哪來的魚摸ㄚ...\n");

   if( me->query_temp("defense")==1)
      return notify_fail("你已經在摸魚了, 還嫌摸的不夠ㄚ...\n");

   if( me->query("sen") < 20 )
      return notify_fail("你的精神力不夠﹐無法用計。\n");

   if( me->query_skill("plan", 1) < 50 )
      return notify_fail("你的謀略能力不夠。\n");
// 不是儒門
   if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
   me->add("sen",-20);
   me->start_busy(2);           //不管有沒有成功 先 delay 再說....
   me->set_temp("defense", 1);
   me->add_temp("apply/defense", me->query_skill("god-plan",1)/2);
me->start_call_out((:call_other,__FILE__,"remove_effect",me:),30);
   message_vision("$N使出混水摸魚之計, 製造混亂, 企圖躲過敵人的攻擊\n", me);
   return 1;
}

void remove_effect( object me)
{
  me->delete_temp("defense");
  me->add_temp("apply/defense",-me->query_skill("god-plan",1)/2);
  tell_object( me, "魚勒...魚勒...好像已經沒有魚讓你摸了...\n");
}
