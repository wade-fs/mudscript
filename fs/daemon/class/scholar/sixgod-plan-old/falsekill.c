// 聲東擊西 By sueplan - 只能對同一ppl用一次
#include <ansi.h>
inherit SSERVER;
object me=this_player();
object target=me->query_enemy(me);
int perform(object me, object target)
{
        if( me->query("force") < 1000 )
        return notify_fail("以你的內力不足以用此計。\n");
        if( target->query_temp("no_falsekill") == 3 )
        return notify_fail("對方已被你的奸計所騙過三次了, 在笨也不會再受騙了吧。\n");
        if(me->query_temp("nouse")==1)
        return notify_fail("對方還對你的奸計無法直招架當中!!\n");
        if( me->query("sen") < 100 )
        return notify_fail("以你的神不足以用此計。\n");
        if( me->query("gin") < 100 )
        return notify_fail("以你的經不足以用此計。\n");
        if( me->query("family/family_name") != "儒門")
        return notify_fail("不是儒生，不給你用咧！！^_^\n");
        if(!me->is_fighting())
        return notify_fail("聲東擊西只能在戰鬥中使用。\n");
        me->add("sen",-30);
        me->start_busy(1);
message_vision(HIY"$N竟然使出了聲東擊西的奸計，令$n無法反應。\n"NOR,me,target);
        target->add_temp("no_falsekill",1);
        me->set_temp("nouse",1);
        target->set_temp("no_power",1);
        call_out("delnopower",60,target);
        return 1;
}

int delnopower()
{
        if (target) {
        target->detele_temp("no_power");
        me->delete_temp("nouse",1);
        }
        return 1;
}

