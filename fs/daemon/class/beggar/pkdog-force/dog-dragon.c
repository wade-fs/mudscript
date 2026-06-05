//dragon  青龍(dodge)lv20 白虎(defense)/lv50 朱雀(staff enable)/v70 玄武(+enforce 2,4,)/lv90
inherit F_FUNCTION;
inherit F_CLEAN_UP;
inherit SSERVER;
#include <ansi.h>


int exert(object me)
{
        int funlv = this_player()->query("functions/dog-dragon/level");
        int fun = me->query("functions/dogup/level");
        if (fun < 20)
                return notify_fail("你的犬化四象還不夠成熟呢！\n");
        if (me->query("class") != "beggar")
                return notify_fail("你不是丐幫子弟，不能使用！\n");
        if (me->query("force") < 50)
                return notify_fail("你內力不足！\n");
        if (me->query_temp("check-dragon")==1)
                return notify_fail("你已在運行中了。\n");
        if (!me->is_fighting())
        {
                message_vision(HIC + "一條青龍從天而降，迅速進入了$N體內！\n" + NOR,me);
                if (funlv < 30)
                {
                        message_vision(HIG + "$N運起青龍第一重\n" + NOR,me);
                        me->set_temp("check-dragon",1);
                        me->set_temp("time-dragon",1);
                        me->add_temp("apply/dodge",50);
                        me->add("force",-60);
                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
                else if (funlv >= 30 && funlv < 70)
                {
                        message_vision(HIY + "$N運起青龍第二重\n" + NOR,me);
                        me->set_temp("check-dragon",1);
                        me->set_temp("time-dragon",2);
                        me->add_temp("apply/dodge",100);
                        me->add("force",-60);
                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
                else
                {
                        message_vision(HIM + "$N運起青龍最終重\n" + NOR,me);
                        me->set_temp("check-dragon",1);
                        me->set_temp("time-dragon",3);
                        me->add_temp("apply/dodge",150);
                        me->add("force",-60);
                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
        }
        else { tell_object(me,"戰鬥中強行運功\會走火入魔！\n"); }
        return 1;
}

void remove_effect(object me)
{
        int funlv = this_player()->query("functions/dog-dragon/level");
        if (me->query_temp("time-dragon")==1)
        {
                me->add_temp("apply/dodge",-50);
        }
        else if (me->query_temp("time-dragon")==2)
        {
                me->add_temp("apply/dodge",-100);
        }
        else
        {
                me->add_temp("apply/dodge",-150);
        }
        me->delete_temp("check-dragon");
        me->delete_temp("time-dragon");
        message_vision(HIC + "圍繞在$N身旁的青龍圖騰已漸漸散去了......\n" + NOR,me);
        if (funlv <100)
        function_improved ("dog-dragon" , random(100) + 100);
}


