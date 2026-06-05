#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
skill=this_player()->query("functions/green/level");
        if(userp(me))
        return notify_fail("請改用 mixforce。\n");
if(me->query("class")!="prayer")
          return notify_fail("你的職業無法使用此技能。\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("玄宇宙必須使用渾天心法才能發揮威力。\n");
        if( target != me ) return notify_fail("你只能用渾天心法提升內力威力。\n");
        if (me->query_skill("superforce",1) < 250)
            return notify_fail("你的渾天心法等級不足﹐須要 250 級。\n");
        if (me->query("force") < 750+skill*5)
            return notify_fail("你的內力不夠﹐無法使用玄宇宙。\n");
        if( (int)me->query("max_force") < 2500 )
        return notify_fail("你的內力根基不足,無法控制玄宇宙氣勁。\n");
        if(me->query_temp("green")) return notify_fail("你已經在用了。\n");
        if(me->query_temp("purple")) return notify_fail("你已經在運行[32m紫星河心法[0m了。\n");
        if(me->query_temp("white")) return notify_fail("你已經在運行[37m白雲煙心法[0m了。\n");
        if(me->query_temp("nine")) return notify_fail("你已經在運行[35m玖蕩霞心法[0m了。\n");
        if(me->query_temp("gen")) return notify_fail("你已經在使用[35m土崑崙心法[0m了。\n");
        if(me->query_temp("ice")) return notify_fail("你已經在運轉[37m碧雪冰心法[0m了。\n");
        if(me->query_temp("black")) return notify_fail("你已經在運行[30m玄混沌[0m了。\n");
        if(me->query_temp("bluesea")) return notify_fail("你已經在催運[34m靛滄海[0m內勁了。\n");
        if(me->query_temp("goldsun")) return notify_fail("你已經在強運[33m金晨曦[0m內勁了。\n");
        if(me->query_temp("blood")) return notify_fail("你已經在催鼓[31m血穹蒼[0m內勁了。\n");

        me->set_temp("green",1);
        message_vision(
        HIC + "$N運起渾天心法第十層" + HIG + "[玄宇宙]" + HIC + "，剎時天空昏暗，萬星繁動，全身各條經脈均充滿了星晨所付予的氣勁!!\n" + NOR,me);
        me->add_temp("apply/force", 100);
        me->add_temp("apply/unarmed", 100);
        me->add_temp("apply/parry", 100);
        me->add_temp("apply/stick", 100);
        me->add_temp("apply/move", -50);
        me->add_temp("apply/dodge", -50);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return ;
        me->set_temp("green",0);
        me->add_temp("apply/force", -100);
        me->add_temp("apply/parry", -100);
        me->add_temp("apply/unarmed", -100);
        me->add_temp("apply/stick", -100);
        me->add_temp("apply/move", 50);
        me->add_temp("apply/dodge", 50);
        tell_object(me,"你身上的[32m玄宇宙[0m氣勁回歸天象，天空逐漸恢復蔚藍。\n");
        if(skill<250)
        function_improved("green",random(1200));
}
