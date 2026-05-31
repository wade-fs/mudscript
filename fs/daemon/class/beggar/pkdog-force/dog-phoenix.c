//phoenix  青龍(dodge)lv20 白虎(defense)/lv50 朱雀(staff enable)/v70 玄武(+enforce 2,4,)/lv90
inherit F_FUNCTION;
inherit F_CLEAN_UP;
inherit SSERVER;
#include <ansi.h>


int exert(object me)
{
        int fun = me->query("functions/dogup/level");
        int funlv = this_player()->query("functions/dog-phoenix/level");
        if (fun < 70)
                return notify_fail("你的犬化四象還不夠成熟呢！\n");
        if (me->query("class") != "beggar")
                return notify_fail("你不是丐幫子弟，不能使用！\n");
        if (me->query("force") < 50)
                return notify_fail("你內力不足！\n");
        if (me->query_temp("check-phoenix")==1)
                return notify_fail("你已在運行中了。\n");
        if (!me->is_fighting())
        {
                message_vision(HIR"$N全身漸漸散出火紅氣焰，一道烈焰護住了$N。\n"NOR,me);
                if (funlv < 30)
                {
                        message_vision(HIG"$N運起朱雀第一重\n"NOR,me);
                        me->set_temp("check-phoenix",1);
                        me->set_temp("time-phoenix",1);
                        me->add_temp("apply/staff",40);
                        me->add_temp("apply/attack",10);
                        me->add("force",-60);
                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
                else if (funlv >= 30 && funlv < 70)
                {
                        message_vision(HIY"$N運起朱雀第二重\n"NOR,me);
                        me->set_temp("check-phoenix",1);
                        me->set_temp("time-phoenix",2);
                        me->add_temp("apply/staff",80);
                        me->add_temp("apply/attack",20);
                        me->add("force",-60);
                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
                else
                {
                        message_vision(HIM"$N運起朱雀最終重\n"NOR,me);
                        me->set_temp("check-phoenix",1);
                        me->set_temp("time-phoenix",3);
                        me->add_temp("apply/staff",100);
                        me->add_temp("apply/attack",30);
                        me->add("force",-60);
                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
        }
        else { tell_object(me,"戰鬥中強行運功\會走火入魔！\n"); }
        return 1;
}

void remove_effect(object me)
{
        int funlv = this_player()->query("functions/dog-phoenix/level");
        if (me->query_temp("time-phoenix")==1)
        {
                me->add_temp("apply/staff",-40);
                me->add_temp("apply/attack",-10);
        }
        else if (me->query_temp("time-phoenix")==2)
        {
                me->add_temp("apply/staff",-80);
                me->add_temp("apply/attack",-20);
        }
        else
        {
                me->add_temp("apply/staff",-100);
                me->add_temp("apply/attack",-30);
        }
        me->delete_temp("check-phoenix");
        me->delete_temp("time-phoenix");
        message_vision(HIR"圍繞在$N身旁的朱雀火焰已漸漸散去了......\n"NOR,me);
        if (funlv <100)
        function_improved ("dog-phoenix" , random(100) + 100);
}


