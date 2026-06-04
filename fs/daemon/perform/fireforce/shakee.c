#include <ansi.h>

int exert(object me, object target)
{
        if( target!=me ) {
                tell_object(me, "你只能幫自己回復。\n");
                return 1;
        }
        if( me->is_fighting() ) {
                tell_object(me, "戰鬥中運功\﹖找死嗎﹖\n");
                return 1;
        }
     if(me->query_condition("shakeeload") != 1)
     {
                tell_object(me, "你現在並無萬劍訣的壓力。\n");
                return 1;
        }

        write( HIC + "你抖抖身體，將身上仙劍元氣發揮至極限，頓時將萬劍訣反噬的威力完全消除。\n" + NOR);
        message("vision",me->name()+"運起體內元氣，臉色頓時輕鬆無比\n",environment(me), me);

     me->apply_condition("shakeeload",0);
     me->delete_temp("shakeeload",1);
        return 1;
}
