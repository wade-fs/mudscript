#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
skill=this_player()->query("functions/white/level");
        if(userp(me))
        return notify_fail("請改用 mixforce。\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("白雲煙必須使用渾天心法才能發揮威力。\n");
        if( target != me ) return notify_fail("你只能用渾天心法提升內力威力。\n");
        if (me->query_skill("superforce",1) < 20)
            return notify_fail("你的渾天心法等級不足，須要 20 級。\n");
        if (me->query("force") < skill*5)
            return notify_fail("你的內力不夠﹐無法領悟白雲煙的渾天內勁。\n");
        if(me->query_temp("white")) return notify_fail("你已經在用了。\n");
        if(me->query_temp("purple")) return notify_fail("你已經在運行紫星河心法了。\n");
        if(me->query_temp("nine")) return notify_fail("你已經在運行玖蕩霞心法了。\n");
        if(me->query_temp("gen")) return notify_fail("你已經在使用土崑崙心法了。\n");
        if(me->query_temp("ice")) return notify_fail("你已經在運轉碧雪冰心法了。\n");
        if(me->query_temp("black")) return notify_fail("你已經在運行玄混沌了。\n");
        if(me->query_temp("bluesea")) return notify_fail("你已經在催運靛滄海內勁了。\n");
        if(me->query_temp("goldsun")) return notify_fail("你已經在強運金晨曦內勁了。\n");
        if(me->query_temp("blood")) return notify_fail("你已經在催鼓血穹蒼內勁了。\n");
        if(me->query_temp("green")) return notify_fail("你已經在運行玄宇宙內勁了。\n");

        me->set_temp("white",1);
        message_vision(
        HIC + "$N運起渾天心法第一層的" + HIW + "白雲煙" + HIC + "﹐身上湧出如雲氣般的內勁形成無數的氣旋!!\n" + NOR,me);

        me->add_temp("apply/force", 1);
        me->add_temp("apply/move", 1);
        me->add_temp("apply/stick", 1);
        me->add_temp("apply/parry", 1);
        me->add_temp("apply/dodge", 1);
        me->add_temp("apply/unarmed", 1);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return ;
        me->set_temp("white",0);
        me->add_temp("apply/force", -1);
        me->add_temp("apply/move", -1);
        me->add_temp("apply/stick", -1);
        me->add_temp("apply/parry", -1);
        me->add_temp("apply/dodge", -1);
        me->add_temp("apply/unarmed", -1);
        tell_object(me,"你身上的白雲煙氣勁慢慢的消退中,氣旋也隨之崩散。\n");
        if(skill<50)
        function_improved("white",random(700));
}
