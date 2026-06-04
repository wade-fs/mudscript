#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

//void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,skill1,force,bloodforce,temp;
        force=me->query("max_force");
        bloodforce=me->query_skill("blood_force",1);
        if( (string)me->query_skill_mapped("force")!= "blood_force")
            return notify_fail("血魔鬥氣要用血魔心法來啟動。\n");
        if (me->query("force") < force/6)
            return notify_fail("你的內力不夠，不能運起血魔鬥氣。\n");
        if(me->query_temp("blood-fight")==1)
            return notify_fail("你已經運起血魔鬥氣的護身氣勁了。\n");
        temp=me->query("functions/bloodfight/level");
        skill = temp;
        me->add("force",-force/10);
        me->set_temp("blood-fight",1);
if (skill < 15){
        skill1=2*skill;
        message_vision(
        HIR + "$N運起『" + HIM + "血魔鬥氣" + HIR + "』第一層「" + HIC + "血氣方剛 " + HIR + "」，全身四周籠罩在一股淡紅色的血魔鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);   
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*18)+80);
        me->apply_condition("blood-fight",1);
        return 1;
                       }
if (skill >= 15 && skill < 30){
        skill1=1.5*skill;
        message_vision(
        HIR + "$N運起『" + HIM + "血魔鬥氣" + HIR + "』第二層「" + HIC + "血氣凌人 " + HIR + "」，全身四周籠罩在一股暗紅色的血魔鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*17)+80);
        me->apply_condition("blood-fight",1);
        return 1;
                       }
if (skill >=30 && skill < 50){
        skill1=1.2*skill;
        message_vision(
        HIW + "$N運起『" + HIM + "血魔鬥氣" + HIW + "』第三層「" + HIC + "血氣凌空耀四方" + HIW + "」，全身四周籠罩在一股紅色的血魔鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*15)+80);
        me->apply_condition("blood-fight",1);
        return 1;
                       }
if (skill >=50 && skill < 70){
        skill1=skill;
        message_vision(
        HIW + "$N運起『" + HIM + "血魔鬥氣" + HIW + "』第四層「" + HIY + "血霸四方" + HIW + "」，全身四周籠罩在一股紅色的血魔鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*14)+80);
        me->apply_condition("blood-fight",1);
        return 1;
                       }
if (skill >=70 && skill < 90){
        skill1=0.8*skill;
        message_vision(
        HIW + "$N運起『" + HIM + "血魔鬥氣" + HIW + "』第五層「" + HIR + "血染九重天 " + HIW + "」，全身四周籠罩在一股亮紅色的血魔鬥氣之內。\n" + NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*13)+80);
        me->apply_condition("blood-fight",1);
        return 1;
                       }
if (skill >=90){
        skill1=0.5*skill;
        message_vision(
        HIC + "$N大喝：" + HIR + "魔威蕩蕩聖佛懼，血霧濛濛神魔震！！\n" + HIC + "隨即運起『" + HIR + "血魔鬥氣" + HIC + "』之終極威力" + HIW + "「" + HBRED + "魔血滯空染紅塵" + NOR + "" + HIW + "」" + HIC + "，全身散發出無比紅光，四周瞬間籠罩在一股肅殺之氣之中。\n" + NOR,me);
		me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*12)+80);
        me->apply_condition("blood-fight",1);
        return 1;
    }
   }
void remove_effect(object me,int skill,int skill1)
{
me->delete_temp("blood-fight");
me->add_temp("apply/dodge",-skill);
me->add_temp("apply/parry",-skill);
me->add_temp("apply/attack",-skill);
me->add_temp("apply/defense",skill1);
message_vision("$N" + HIC + "『" + HIR + "血魔鬥氣" + HIC + "』" + NOR + "所形成的護身氣勁開始崩潰渙散了。\n" + NOR,me);
}
