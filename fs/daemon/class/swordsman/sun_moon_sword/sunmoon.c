#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount,int amount1);

int perform(object me, object target)
{
        int skill,skill1,force,sun_moon_force,temp;
        force=me->query("max_force");
        sun_moon_force=me->query_skill("sun_moon_force",1);
        if( (string)me->query_skill_mapped("force")!= "sun_moon_force")
            return notify_fail("昊玥罡\氣要用日月兩極心法來啟動。\n");
        if (me->query("force") < force/6)
            return notify_fail("你的內力不夠，不能運起昊玥罡\氣。\n");
        if(me->query_temp("sun-moon")==1)
            return notify_fail("你已經運起昊玥罡\氣的護身氣勁了。\n");
        temp=me->query("functions/sun-moon/level");
        skill = temp;
        me->add("force",-force/10);
        me->set_temp("sun-moon",1);
if (skill < 20){
        skill1=skill;
        message_vision(
        MAG "$N運起『"HIY"昊玥罡\氣"MAG"』之「"HIM"月極身 "MAG"」，全身四周籠罩在一股淡粉色的護身氣勁之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",-skill1);
        me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill,skill1:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < sun_moon_force )
        function_improved("sun-moon",random(skill*18)+80);
        me->apply_condition("sun-moon",1);
        return 1;
                       }
if (skill >= 20 && skill < 40){
        skill1=0.9*skill;
        message_vision(
        YEL "$N運起『"HIY"昊玥罡\氣"YEL"』之「"HIW"日極身 "YEL"」，全身四周籠罩在一股淡黃色的護身氣勁之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",-skill1);
        me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill,skill1:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < sun_moon_force )
        function_improved("sun-moon",random(skill*17)+80);
        me->apply_condition("sun-moon",1);
        return 1;
                       }
if (skill >=40 && skill < 65){
        skill1=0.8*skill;
        message_vision(
        RED "$N運起『"HIY"昊玥罡\氣"RED"』之「"HIW"日月兩極 "RED"」，全身四周籠罩在一股蘭色的護身氣勁之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",-skill1);
        me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill,skill1:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < sun_moon_force )
        function_improved("sun-moon",random(skill*15)+80);
        me->apply_condition("sun-moon",1);
        return 1;
                       }
if (skill >=65 && skill < 90){
        skill1=0.7*skill;
        message_vision(
        CYN "$N運起『"HIY"昊玥罡\氣"CYN"』之「"HIW"兩極護身勁 "CYN"」，全身四周籠罩在一股白色的護身氣勁之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill1);
        me->add_temp("apply/attack",-skill1);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill,skill1:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < sun_moon_force )
        function_improved("sun-moon",random(skill*14)+80);
        me->apply_condition("sun-moon",1);
        return 1;
                       }
if (skill >=90){
        skill1=0.5*skill;
        message_vision(
        HIW "$N大喝："HIY"釋天離華耀天地！乾坤無垠撼日月！\n"HIM"隨即運起『"HIY"昊玥罡\氣"HIM"』之終極威力"HIW"「"HBYEL"昊玥兩極護身罡\氣"NOR""HIW"」"HIM"，全身散發出無比黃光，四周瞬間籠罩在一股神聖之氣之中。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",-skill1);
        me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill,skill1:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < sun_moon_force )
        function_improved("sun-moon",random(skill*12)+80);
        me->apply_condition("sun-moon",1);
        return 1;
    }
}
void remove_effect(object me,int skill,int skill1)
{
me->delete_temp("sun-moon");
me->add_temp("apply/dodge",-skill);
me->add_temp("apply/parry",-skill);
me->add_temp("apply/attack",skill1);
me->add_temp("apply/defense",-skill);
message_vision(HIC"$N『"HIY"昊玥罡\氣"HIC"』"HIC"所形成的護身氣勁開始崩潰渙散了。\n"NOR,me);
}
