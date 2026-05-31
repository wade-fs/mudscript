//By sueplan取走敵人的weapon - 運天行道 2000.7.27
#include <ansi.h>
inherit SSERVER;
object me=this_player();
int perform(object me, object target)
{
        if( me->query("force") < 1000 )
        return notify_fail("以你的內力不足以用此計。\n");
        if( target != me)   
        return notify_fail("此計只能對自己用。\n");
        if( me->is_fighting() )
        return notify_fail("戰鬥中不能使用。\n");
        if( me->query_temp("usesky") == 1 )
        return notify_fail("天時地利人合已經被你掌握住了。\n");
message_vision(HIC"$N以六韜奇略中的觀星說文之計，將自己立於不敗之地。\n"NOR,me);
message_vision(HIC"$N感到自己刺術技巧又更上一層了。\n"NOR,me);
        me->add_temp("apply/stabber",30);
        me->set_temp("usesky",1);
        me->add("force",-500);
        return 1;
}




