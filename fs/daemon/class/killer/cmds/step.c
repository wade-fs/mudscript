// 分功化影身法 之 化 影
// 這一個command僅是提供玩家決定是否驅動化影術或是分功
// 所以並不會去扣掉玩家的任何東西，
// 一切消耗會在事後計算
// 因為此系統將會影響玩家的exp取得
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me, string arg)
{
        int i;
        
        if( !arg )
             return notify_fail("指令格式﹕cmd step shadow/share/none \n");
        
   if (arg=="none")
   {
        	if (me->query_temp("step-shadow"))
        	{
        		me->delete_temp("step-shadow");
        		return notify_fail("你已經停止使用化影術\n");
	        	}
        		if (me->query_temp("step-share"))
	        	{
        			me->delete_temp("step-share");
        			return notify_fail("你已經停止使用分功\術\n");
	        	}
        		return notify_fail("笨蛋，你又沒有使用身法\n");
       }
        if (arg=="shadow")
        {
             if (!me->query("dark-steps/shadow/enable"))
             	return notify_fail("你根本沒有學過化影術\n");
             if (me->query_temp("step-shadow"))
                 return notify_fail("你已經使用了化影術\n");
             if (me->query_temp("step-share") ||  !me->query_temp("step-shadow"))
             {
                 message_vision(HIC + "$N默運化影術的步法......。\n" + NOR,me);
                 me->set_temp("step-shadow",1);
                 me->delete_temp("step-share",1);
                 return notify_fail("分功\術的效用逐漸失去\n");
             }
        }
        if (arg=="share")
        {
             if (!me->query("dark-steps/share/enable"))
             	return notify_fail("你根本沒有學過分功\術\n");
             if (me->query_temp("step-share"))
                 return notify_fail("你已經使用分功\術\n");
             if (me->query_temp("step-shadow")|| !me->query_temp("step-share"))
             {
                 message_vision(HIC + "$N默運分功\術的步法......。\n" + NOR,me);
                 me->set_temp("step-share",1);
                 me->delete_temp("step-shadow",1);
                 return notify_fail("化影術的效用逐漸失去\n");
             }
       }
       return 0;
}

int help(object me)
{
    write(@HELP
 
指令格式﹕ cmd step shadow/share/none
 
說明﹕決定使用分功化影身法的化影術或是分功術
      
HELP
);
     return 1;
}

