//犬化四象(Dogup)  
//需拿洗髓丹及一顆生生造化丹跟獨孤嵊人頭
//去找到一位丐幫神秘長老換取心經才可習得
inherit F_FUNCTION;
inherit F_CLEAN_UP;
inherit SSERVER;
#include <ansi.h>

int exert(object me)
{
        int funlv = this_player()->query("functions/dogup/level");
        int fun = me->query("functions/dogup/level");
        if (!me->query("beggar/got_dogup"))
                return notify_fail("你還不會犬化四象呢！\n");
        if (me->query("class") != "beggar")
                return notify_fail("你不是丐幫子弟，不能使用！\n");
        if (me->query("force") < 60)
                return notify_fail("你內力不足！\n");
        if (me->query_temp("check-dogup")==1)
                return notify_fail("你已在運行中了。\n");
        if (!me->is_fighting())
        {
                message_vision(HIY + "$N口中唸唸有詞，陣陣靈氣開始附於$N身上。\n" + NOR,me);
                message_vision(HIR + "\n
　　　　　　" + HIR + "　　╗　　" + HIM + "●　" + HIC + "╗╗　　　　" + HIW + "╔════╗" + HIY + "╔════╗" + NOR + "　
　　　　　　" + HIR + "╔═╬══╗　" + HIC + "║║　　　　" + HIW + "║　║║　║" + HIY + "╔════╗" + NOR + "
　　　　　　" + HIR + "　　║　　　　" + HIC + "║║　　　　" + HIW + "║　║║　║" + HIY + "╚══╩═╝" + NOR + "
　　　　　　" + HIR + "　　╚╗　　　" + HIC + "║║═══╝" + HIW + "║╚╝╚╝║" + HIY + "╚═　║╔╗" + NOR + "
　　　　　　" + HIR + "　╔　╚╗　　" + HIC + "║║　　　　" + HIW + "║　　　　║" + HIY + "╚═　║║  " + NOR + "
　　　　　　" + HIR + "╚╝　　╚╝　" + HIC + "╚╚═══╝" + HIW + "╚════╝" + HIY + "╚═　╝╚╝\n" + NOR,me);
                me->set_temp("check-dogup",1);
                me->set_temp("time-dogup",1);
                me->add("force",-60);
                me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
        }
        else { tell_object(me,"戰鬥中強行運功\會走火入魔！\n"); }
        return 1;
}

void remove_effect(object me)
{
        int funlv = this_player()->query("functions/dogup/level");
        if (me->query_temp("time-dogup")==1)
        {
        me->delete_temp("check-dogup");
        me->delete_temp("time-dogup");
        message_vision(YEL + "靈氣從$N身上漸漸散去，$N看起來平凡許\多！\n" + NOR,me);}
        if (funlv <100)
        function_improved ("dogup" , random(100) + 100);
}

