#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
skill=this_player()->query("functions/bluesea/level");
        if(userp(me))
        return notify_fail("請改用 mixforce。\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("靛滄海必須使用渾天心法才能發揮威力。\n");
        if( target != me ) return notify_fail("你只能用渾天心法提升內力威力。\n");
        if (me->query_skill("superforce",1) < 110)
            return notify_fail("你的渾天心法等級不足﹐須要 110 級。\n");
        if (me->query("force") < 350+skill*5)
            return notify_fail("你的內力不夠﹐無法使用靛滄海。\n");
        if( (int)me->query("max_force") < 1300 )
        return notify_fail("你的內力根基不足,無法完全發揮出靛滄海澎湃的內勁。\n");
        if(me->query_temp("bluesea")) return notify_fail("你已經在用了。\n");
        if(me->query_temp("purple")) return notify_fail("你已經在運行紫星河心法了。\n");
        if(me->query_temp("white")) return notify_fail("你已經在運行白雲煙心法了。\n");
        if(me->query_temp("nine")) return notify_fail("你已經在運行玖蕩霞心法了。\n");
        if(me->query_temp("gen")) return notify_fail("你已經在使用土崑崙心法了。\n");
        if(me->query_temp("ice")) return notify_fail("你已經在運轉碧雪冰心法了。\n");
        if(me->query_temp("black")) return notify_fail("你已經在運行玄混沌了。\n");
        if(me->query_temp("goldsun")) return notify_fail("你已經在強運金晨曦內勁了。\n");
        if(me->query_temp("blood")) return notify_fail("你已經在催鼓血穹蒼內勁了。\n");
        if(me->query_temp("green")) return notify_fail("你已經在運行玄宇宙內勁了。\n");

        me->set_temp("bluesea",1);
        message_vision(
        HIC + "$N運起渾天心法第七層" + HIB + "[靛滄海]" + HIC + "﹐真氣流竄﹐暮地周圍出現" + HIB + "海嘯般的內勁" + HIB + "!!\n" + NOR,me);

        me->add_temp("apply/parry", 30);
        me->add_temp("apply/unarmed", -20);
        me->add_temp("apply/stick", -20);
        me->add_temp("apply/force", 20);
        me->add_temp("apply/move", 20);
        me->add_temp("apply/dodge", 20);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return ;
        me->set_temp("bluesea",0);
        me->add_temp("apply/parry", -30);
        me->add_temp("apply/unarmed", 20);
        me->add_temp("apply/stick", 20);
        me->add_temp("apply/force", -20);
        me->add_temp("apply/move", -20);
        me->add_temp("apply/dodge", -20);
        tell_object(me,"你所散發出來的靛滄海氣勁倏地消失無蹤。\n");
        if(skill<100)
        function_improved("bluesea",random(800));
}
