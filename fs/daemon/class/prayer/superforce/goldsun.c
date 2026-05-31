#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
if(!me) return notify_fail("發生問題了!!!\n");
        if(userp(me))
        return notify_fail("請改用 mixforce。\n");
skill=me->query("functions/goldsun/level");
if(me->query("class")!="prayer")
          return notify_fail("你的職業無法使用此技能。\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("金晨曦必須使用渾天心法才能發揮威力。\n");

        if( target != me ) return notify_fail("你只能用渾天心法提升內力威力。\n");
        if (me->query_skill("superforce",1) < 150)
            return notify_fail("你的渾天心法等級不足﹐須要 150 級。\n");
        if (me->query("force") < 450+skill*5)
            return notify_fail("你的內力不夠﹐無法使用金晨曦。\n");
        if( (int)me->query("max_force") < 1600 )
        return notify_fail("你的內力根基不足,無法抑制金晨曦的氣勁。\n");
        if(me->query_temp("goldsun")) return notify_fail("你已經在用了。\n");
        if(me->query_temp("purple")) return notify_fail("你已經在運行[32m紫星河心法[0m了。\n");
        if(me->query_temp("white")) return notify_fail("你已經在運行[37m白雲煙心法[0m了。\n");
        if(me->query_temp("nine")) return notify_fail("你已經在運行[35m玖蕩霞心法[0m了。\n");
        if(me->query_temp("gen")) return notify_fail("你已經在使用[35m土崑崙心法[0m了。\n");
        if(me->query_temp("ice")) return notify_fail("你已經在運轉[37m碧雪冰心法[0m了。\n");
        if(me->query_temp("black")) return notify_fail("你已經在運行[30m玄混沌[0m了。\n");
        if(me->query_temp("bluesea")) return notify_fail("你已經在催運[34m靛滄海[0m內勁了。\n");
        if(me->query_temp("blood")) return notify_fail("你已經在催鼓[31m血穹蒼[0m內勁了。\n");
        if(me->query_temp("green")) return notify_fail("你已經在運行[32m玄宇宙[0m內勁了。\n");

        me->set_temp("goldsun",1);
        message_vision(
        HIC "$N運起渾天心法第八層"HIY"[金晨曦]"HIC"﹐真氣鼓漲﹐剎時全身爆出"HIY"萬道金色的光芒"NOR"!!\n" NOR,me);

        me->add_temp("apply/force", 50);
        me->add_temp("apply/parry", -10);
        me->add_temp("apply/unarmed", 50);
        me->add_temp("apply/stick", 50);
        me->add_temp("apply/move", -30);
        me->add_temp("apply/dodge", -30);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return ;
        me->set_temp("goldsun",0);
        me->add_temp("apply/force", -50);
        me->add_temp("apply/parry", 10);
        me->add_temp("apply/unarmed", -50);
        me->add_temp("apply/stick", -50);
        me->add_temp("apply/move", 30);
        me->add_temp("apply/dodge", 30);
        tell_object(me,"只見你身上[33m金晨曦[0m所發出的萬丈金光忽地消失。\n");
        if(skill < 150)
        function_improved("goldsun",random(900));
}
