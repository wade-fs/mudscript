#include <ansi.h>
#include "valuecheck.c"
#include "funexp.c"
int perform(object me)
{
        int force,funlv;

        force = me->query("force");
        funlv = me->query("functions/heal-song/level");

        if ( force < 20 )       return notify_fail("你的內力不足。\n");
        if ( !valuecheck(me) )  return notify_fail("你沒有受傷。\n");

        me->set_temp("singing",1);
        message_vision(HIW + "$N雙手五指相接，五指空握處，散發著零星的光芒！\n" + NOR,me);
        me->receive_heal("gin",funlv*20);
        me->receive_heal("kee",funlv*20);
        me->receive_heal("sen",funlv*20);
        me->add("force",-20);
        COMBAT_D->report_status(me,1);
        funexp(me,"heal-song",3*funlv);
        call_out("sing",1,me);
return 1;
}

int sing(object me)
{
        me->delete_temp("singing");
        tell_object(me,"你結束詠唱"+to_chinese("heal-song")+"\n");
return 1;
}
