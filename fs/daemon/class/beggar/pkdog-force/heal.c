// 原作為pana..
// 修正以及加上heal上限 by obs

#include <ansi.h>

int exert(object me, object target)
{
        if( target!=me ) {
                tell_object(me,"你只能幫自己療傷。\n");
                return 1;
        }
        if( me->is_fighting() ) {
                tell_object(me,"戰鬥中運功\療傷？找死嗎？\n");
                return 1;
        }
        if( me->query("force") < 50 ) {
                tell_object(me,"你的內力不夠，無法療傷。\n");
                return 1;
        }
        if( me->query("eff_kee") >= me->query("max_kee") ) {
                tell_object(me,"你身上已經沒有任何傷口。\n");
                return 1;
        }
                write(HIR + "你默唸起養狗口訣，四周揚起落葉，轉眼間你的傷勢已好了大半。\n" + NOR);
        message("vision",me->name()+"" + HIR + "默唸起養狗口訣，四周揚起落葉，轉眼間"+me->name()+"的傷勢已好了大半。\n" + NOR,environment(me), me);
        me->receive_curing("kee", ( 10 + (int)me->query_skill("force")/20 + (int)me->query_skill("pkdog-force")/10 ));
        me->add("force", -35 );
        if( me->query("force") < 0 )
            me->set("force", 0);
        return 1;
}

