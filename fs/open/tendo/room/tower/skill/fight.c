#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,force,fiendforce,temp;
        force=me->query("max_force");
        fiendforce=me->query_skill("fiendforce",1);
        if( (string)me->query_skill_mapped("force")!= "fiendforce")
            return notify_fail("修羅鬥氣要用修羅心法來啟動。\n");
        if (me->query("force") < force/6)
            return notify_fail("你的內力不夠，不能運起修羅鬥氣。\n");
        if(me->query_temp("fight")==1)
            return notify_fail("你已經運起修羅鬥氣的護身氣勁了。\n");
        temp=me->query("functions/fight/level","fight");
        skill = temp;
        me->add("force",-force/10);
        me->set_temp("fight",1);
if (skill < 10){
        message_vision(
        HIW + "$N運起『" + HIM + "修羅鬥氣" + HIW + "』第一重「氣臨山河動" + HIW + "」，全身四周籠罩在一股白色的修羅鬥氣之內。。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
         me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*18)+80);
        return 1;
                       }
if (skill >= 10 && skill < 20){
        message_vision(
        HIW + "$N運起『" + HIM + "修羅鬥氣" + HIW + "』第二重「雷鼓震山川" + HIW + "」，全身四周籠罩在一股綠色的修羅鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*17)+80);
        return 1;
                       }
if (skill >= 20 && skill < 30){
        message_vision(
        HIW + "$N運起『" + HIM + "修羅鬥氣" + HIW + "』第三重「水精勢絕倫" + HIW + "」，全身四周籠罩在一股青色的修羅鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*16)+80);
        return 1;
                       }
if (skill >=30 && skill < 40){
        message_vision(
        HIW + "$N運起『" + HIM + "修羅鬥氣" + HIW + "』第四重「風沙暗夜吼" + HIW + "」，全身四周籠罩在一股紫色的修羅鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*15)+80);
        return 1;
                       }
if (skill >=40 && skill < 50){
        message_vision(
        HIW + "$N運起『" + HIM + "修羅鬥氣" + HIW + "』第五重「火光燎天戈" + HIW + "」，全身四周籠罩在一股紅色的修羅鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*14)+80);
        return 1;
                       }
if (skill >=50 && skill < 60){
        message_vision(
        HIW + "$N運起『" + HIM + "修羅鬥氣" + HIW + "』第六重「雨凝破山石" + HIW + "」，全身四周籠罩在一股黃色的修羅鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*13)+80);
        return 1;
                       }
if (skill >=60 && skill <70){
        message_vision(
        HIW + "$N運起『" + HIM + "修羅鬥氣" + HIW + "』第七重「電花照天河" + HIW + "」，全身四周籠罩在一股銀色的修羅鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
         me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*12)+80);
        return 1;
                       }
if (skill >=70 ){
        message_vision(
        HIW + "$N運起『" + HIM + "修羅鬥氣" + HIW + "』" + HIB + "最終奧義" + HIW + "「冰寒囓人心" + HIW + "」，全身四周籠罩在一股金色的修羅鬥氣之內。。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*11)+80);
        return 1;
                       }
}

void remove_effect(object me, int skill)
{

        me->delete_temp("fight");
        me->add_temp("apply/dodge",-skill);
        me->add_temp("apply/parry",-skill);
        me->add_temp("apply/attack",-skill);
        me->add_temp("apply/defense",-50);
        message_vision("$N" + HIW + "『修羅鬥氣』" + NOR + "所形成的護身氣勁開始崩潰渙散了。\n" + NOR,me);
}



