#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("block_sweat",1);
     tell_object(me , "你內息受到蒙汗藥的抑制，無法使用部分武學。\n" + NOR);
     me->set_temp("block_sweat",1);
     me->apply_condition("block_sweat",duration-1);
 if (duration < 1) {
     me->delete_temp("block_sweat",1);
	 tell_object(me , "你體內的蒙汗藥已失去效用了。\n" + NOR);
     return 0;
                   }
        return 1;
}
