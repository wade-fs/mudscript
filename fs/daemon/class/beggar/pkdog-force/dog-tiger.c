//tiger  青龍(dodge)lv20 白虎(defense)/lv50 朱雀(staff enable)/v70 玄武(+enforce 2,4,)/lv90
inherit F_FUNCTION;
inherit F_CLEAN_UP;
inherit SSERVER;
#include <ansi.h>

int exert(object me)
{
        int funlv = this_player()->query("functions/dog-tiger/level");
        int fun = me->query("functions/dogup/level");
        if (fun < 50)
                return notify_fail("你的犬化四象還不夠成熟呢！\n");
        if (me->query("class") != "beggar")
                return notify_fail("你不是丐幫子弟，不能使用！\n");
        if (me->query("force") < 50)
                return notify_fail("你內力不足！\n");
        if (me->query_temp("check-tiger")==1)
                return notify_fail("你已在運行中了。\n");
        if (!me->is_fighting())
        {
                message_vision(HIW + "$N虎吼一聲，囂張氣焰有如白虎助陣！\n" + NOR,me);
                if (funlv < 30)
                {
                        message_vision(HIG + "$N運起白虎第一重\n" + NOR,me);
                        me->set_temp("check-tiger",1);
                        me->set_temp("time-tiger",1);
                        me->add_temp("apply/armor",20);
                        me->add_temp("apply/parry",30);
                        me->add("force",-60);
                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
                else if (funlv >= 30 && funlv < 70)
                {
                        message_vision(HIY + "$N運起白虎第二重\n" + NOR,me);
                        me->set_temp("check-tiger",1);
                        me->set_temp("time-tiger",2);
                        me->add_temp("apply/armor",40);
                        me->add_temp("apply/parry",60);
                        me->add("force",-60);
                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
                else
                {
                        message_vision(HIM + "$N運起白虎最終重\n" + NOR,me);
                        me->set_temp("check-tiger",1);
                        me->set_temp("time-tiger",3);
                        me->add_temp("apply/armor",60);
                        me->add_temp("apply/parry",90);
                        me->add("force",-60);


                        me->start_call_out((: call_other,__FILE__,"remove_effect",me :), funlv *3/2);
                }
        }
        else { tell_object(me,"戰鬥中強行運功\會走火入魔！\n"); }
        return 1;
}
void remove_effect(object me)
{
            int funlv = this_player()->query("functions/dog-tiger/level");
        if (me->query_temp("time-tiger")==1)
        {
                me->add_temp("apply/armor",-20);
                me->add_temp("apply/parry",-30);
        }
        else if (me->query_temp("time-tiger")==2)
        {
                me->add_temp("apply/armor",-40);
                me->add_temp("apply/parry",-60);
        }
        else
        {
                me->add_temp("apply/armor",-60);
                me->add_temp("apply/parry",-90);
        }
        me->delete_temp("check-tiger");
        me->delete_temp("time-tiger");
        message_vision(HIW + "覆蓋\在$N身上的白虎霸氣已漸漸散去了......\n" + NOR,me);
        if (funlv <100)
        function_improved ("dog-tiger" , random(100) + 100);
}


