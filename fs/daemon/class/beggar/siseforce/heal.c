
#include <ansi.h>

int exert(object me, object target)
{

        if( target!=me ) {
                tell_object(me, "你只能幫自己療傷。\n");
                return 1;
        }
        if( me->is_fighting() ) {
                tell_object(me, "戰鬥中運功\療傷﹖找死嗎﹖\n");
                return 1;
        }
        if( (int)me->query("force") < 50 ) {
                tell_object(me, "你的內力不足，無法使用洗髓經來療傷。\n");
                return 1;
        }

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 3 )
                return notify_fail("你已經受傷過重，只怕一運真氣會被洗髓勁反撲！\n");

        write( HIW "你盤坐在地，逆運洗髓經調理你全身的傷勢，使你的傷勢好多了。\n" NOR);
        message("vision",
                me->name() + "運起洗髓經開始療傷，一股真氣從頭上冒出，吐出一口瘀血，看起來好多了。\n",
                environment(me), me);

        me->receive_curing("kee", ( 10 + (int)me->query_skill("force")/10 + (int)me->query_skill("dragonforce")/10 ) * 3);
        me->add("force", -( 50 ) );
        if( me->query("force")<0 )
                me->set("force", 0);

        return 1;
}
