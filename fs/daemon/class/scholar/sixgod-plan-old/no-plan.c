#include <ansi.h>
// By Sueplan 策免計 - 儒門本身不怕計謀
//考濾要不要加call_out時間讓plan的temp消掉
//這個計謀只能用來擋諸葛神算的plan, 不能擋sixgod-plan
inherit SSERVER;
object me=this_player();
int perform(object me,object target)
{
        if( me->query("sen") < 100 )
                return notify_fail("你的精神不夠﹐無法使用。\n");
        if( target != me ) 
                return notify_fail("你要對誰用計 ?\n");
        if(me->is_fighting(target))     
                return notify_fail("策免計只能在戰鬥前使用。\n");
        if( me->query("force") < 2500 )
                return notify_fail("以你的內力不足以用此計。\n");
        if( me->query_temp("no-plan") == 1 )
        return notify_fail("你已經使出策免計了。\n");
message_vision(HIY"$N以六韜奇略中的策免計，使自己不怕別的計謀。\n"NOR,me);
        me->set_temp("speed",1);
        me->set_temp("empty",1);
        me->set_temp("mount",1);
        me->set_temp("false",1);
        me->set_temp("lock-link",1);
        me->set_temp("ghost",1);
        me->set_temp("rob",1);  
        me->set_temp("no-plan",1);
        me->add("force",-2000);
        return 1;
}
