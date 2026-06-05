#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
skill=this_player()->query("functions/ice/level");
        if(userp(me))
        return notify_fail("請改用 mixforce。\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("碧雪冰必須使用渾天心法才能發揮威力。\n");
        if( target != me ) return notify_fail("你只能用渾天心法提升內力威力。\n");
        if (me->query_skill("superforce",1) < 50)
            return notify_fail("你的渾天心法等級不足﹐須要 50 級。\n");
        if (me->query("force") < skill*5)
            return notify_fail("你的內力不夠﹐無法領悟碧雪冰的渾天內勁。\n");
        if( (int)me->query("max_force") < 600 )
        return notify_fail("你的內力根基不足,無法完全發揮出碧雪冰雄渾的內勁。\n");

        if(me->query_temp("ice")) return notify_fail("你已經在用了。\n");
        if(me->query_temp("purple")) return notify_fail("你已經在運行[32m紫星河心法[0m了。\n");
        if(me->query_temp("white")) return notify_fail("你已經在運行[37m白雲煙心法[0m了。\n");
        if(me->query_temp("nine")) return notify_fail("你已經在使用[35m玫蕩霞心法[0m了。\n");
        if(me->query_temp("gen")) return notify_fail("你已經在使用[35m土崑崙心法[0m了。\n");
        if(me->query_temp("black")) return notify_fail("你已經在運行[30m玄混沌[0m了。\n");
        if(me->query_temp("bluesea")) return notify_fail("你已經在催運[34m靛滄海[0m內勁了。\n");
        if(me->query_temp("goldsun")) return notify_fail("你已經在強運[33m金晨曦[0m內勁了。\n");
        if(me->query_temp("blood")) return notify_fail("你已經在催鼓[31m血穹蒼[0m內勁了。\n");
        if(me->query_temp("green")) return notify_fail("你已經在運行[32m玄宇宙[0m內勁了。\n");

        me->set_temp("ice",1);
        message_vision(
HIC + "$N運起渾天心法第四層的" + HIW + "碧雪冰" + HIC + "﹐身上發出如寒霜般的寒勁,四周的空氣似乎也為之凍結!!\n" + NOR,me);

        me->add_temp("apply/force", 5);
        me->add_temp("apply/move", 5);
        me->add_temp("apply/stick", 5);
        me->add_temp("apply/parry", 5);
        me->add_temp("apply/dodge", 5);
        me->add_temp("apply/unarmed", 5);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->set_temp("ice",0);
        me->add_temp("apply/force", -5);
        me->add_temp("apply/move", -5);
        me->add_temp("apply/stick", -5);
        me->add_temp("apply/parry", -5);
        me->add_temp("apply/dodge", -5);
        me->add_temp("apply/unarmed", -5);
        tell_object(me,"你身上的碧雪冰氣勁慢慢的消退中,四周寒意也隨之降低。\n");
        if(skill < 50)
        function_improved("ice",random(700));
}
