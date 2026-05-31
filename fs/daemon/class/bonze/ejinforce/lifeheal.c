// lifeheal.c  by detail

#include <ansi.h>

int exert(object me, object target)
{
        if( !target )
                return notify_fail("你要用真氣為誰療傷﹖\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("戰鬥中無法運功\療傷﹗\n");

        if( (int)me->query("force") < 150 )
                return notify_fail("你的真氣不夠。\n");

        if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
                return notify_fail( target->name() + "已經受傷過重﹐經受不起易筋經強烈的真氣震盪﹗\n");

        message_vision(
                HIW "$N雙膝盤起,運起易筋經﹐將手掌貼在$n背心﹐緩緩地將真氣輸入$n體內....\n\n"
                "過了不久﹐$n臉色由青轉紅﹐吁了一口長氣,傷勢已大為好轉。\n" NOR,
                me, target );

        target->receive_curing("kee", 100 + (int)me->query_skill("force") );
        if( (int)target->query("eff_kee") > (int)target->query("max_kee") )
        me->set("force_factor", 0);
        if( me->query("force")<0 )
                me->set("force", 0);

        return 1;
}
