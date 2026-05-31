//shanwu  青龍(dodge)lv20 白虎(defense)/lv50 朱雀(staff enable)/v70 玄武(+enforce 2,4,)/lv90
inherit F_FUNCTION;
inherit F_CLEAN_UP;
inherit SSERVER;
#include <ansi.h>

int exert(object me)
{
        int enf = this_player()->query("force_factor");
        int force = this_player()->query_skill("force")/50;

        int fun = me->query("functions/dogup/level");
                me->set("old_enf",enf);
        if (fun < 90)
                return notify_fail("你的犬化四象還不夠成熟呢！\n");
        if (me->query("class") != "beggar")
                return notify_fail("你不是丐幫子弟，不能使用！\n");
        if (me->query("force") < 50)
                return notify_fail("你內力不足！\n");
        if (me->query_temp("check-shanwu")==1)
                return notify_fail("你已在運行中了。\n");
        if (!me->is_fighting())
        {
                if (force > 10) force =10;
                message_vision(HIB"$N氣運單田，再將真氣運至全身，只見青筋漸漸浮現....\n"NOR,me);
                me->set_temp("check-shanwu",1);
                me->set("force_factor",force+enf);
                me->add("force",-100);
                me->start_call_out((: call_other,__FILE__,"remove_effect",me :), fun*3/2);
        }
        else { tell_object(me,"戰鬥中強行運功\會走火入魔！\n"); }
        return 1;
}

void remove_effect(object me)
{
    int funlv = this_player()->query("functions/dog-shanwu/level");
    int enff = this_player()->query("old_enf");
    int force = this_player()->query_skill("force")/50;

    me->set("force_factor",enff);
    me->delete_temp("check-shanwu");
    message_vision(HIB"$N身上異常的青筋已漸漸消去....\n"NOR,me);

}


