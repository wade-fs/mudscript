#include <ansi.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        if( duration > 7 ) {
                tell_object(me, NOR"你感到一股慾火從丹田發出，但並不在意。\n"NOR);
                message("vision", me->name() + "看起來怪怪的。 \n",
                        environment(me), me);
        } else if( duration > 6 ) {
                tell_object(me, NOR"你感到慾火正往全身擴散，連忙收攝心神。 \n"NOR);
                message("vision", me->name() + "似乎不太舒服。 \n",
                        environment(me), me);
        } else if( duration > 5 ) {
                tell_object(me, "你感到已忍無可忍，看來不發洩一下不行了。 \n");
                message("vision", me->name() + "雙眼發紅，有若野獸。 \n",
                        environment(me), me);
        } else if( duration > 3 ) {
                tell_object(me, "你忍了太久，保住了聲名，但功\力大損中。 \n");
                message("vision", me->name() + "一臉痛苦，快爆了。 \n",
                        environment(me), me);     
                me->receive_damage("gin", me->query("max_gin",1)/2);
                me->add("force",-me->query("force",)/2);
                me->receive_damage("kee", me->query("max_kee",1)/2);
                me->receive_damage("sen", me->query("max_sen",1)/2);
        }
        me->apply_condition("sex_poison", duration - 1);
        COMBAT_D->report_status(me, 1);
        if( !duration )
                return 0;
        return 1;
}

