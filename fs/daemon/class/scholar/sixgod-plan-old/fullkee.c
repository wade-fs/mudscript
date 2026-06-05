//完復計 by sueplan - 快速回復kee所傷到的最大值
#include <ansi.h>
inherit SSERVER;
int delfullkee(object);
int perform(object me, object target)
{
        int force=me->query_skill("force");
        if( me->query("force") < 1000 )
        return notify_fail("你的內力不夠。\n");
        if( me->is_fighting() )
        return notify_fail("戰鬥中不能使用。\n");
        if( target != me)   
        return notify_fail("此計只能對自己用。\n");
        if( me->query_temp("fullkee") == 1 )
        return notify_fail("你已經用了完復計，請等會再用。\n");
          message_vision(HIW + "$N用出六韜奇略中的完復計，一陣白煙在$N天頂前掠過。\n" + NOR,me);
        message_vision(HIG + "$N感受到身上一股氣勁，覺得氣力回復了不少。\n" + NOR,me);
        me->receive_curing("kee",force*3);
        me->set_temp("fullkee",1);
        me->add("force",-500);
        call_out("delfullkee",10,me);
        return 1;
}
int delfullkee(object me)
{

        if(me) {
        me->delete_temp("fullkee");
        }
        return 1;
}


