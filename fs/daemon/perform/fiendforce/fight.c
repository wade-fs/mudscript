#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,force,fiendforce,temp,i;
	i=0;
        force=me->query("max_force");
        fiendforce=me->query_skill("fiendforce",1);
        if( (string)me->query_skill_mapped("force")!= "fiendforce")
            return notify_fail("修羅鬥氣要用修羅心法來啟動。\n");
        if (me->query("force") < force/6)
            return notify_fail("你的內力不夠，不能運起修羅鬥氣。\n");
        if(me->query_temp("ashura_fight")==1)
            return notify_fail("你已經運起修羅鬥氣的護身氣勁了。\n");
        temp=me->query("functions/fight/level","fight");

	if( userp(me) )
	{
	  if( me->query("class")!="taoist" )
	  {
          skill = temp/10;
	  i=30-skill;
          me->add("force",-force/10);
	  }else{
          skill = temp;
	  i = random(20);
          me->add("force",-force/20);
	  }
	}else{
        skill = temp;
        me->add("force",-force/10);
	}

        me->set_temp("ashura_fight",1);

if (temp < 15){
        message_vision(
        HIW "$N運起『"HIM"修羅鬥氣"HIW"』第一重「[1;5;31m氣臨山河動[0m"HIW"」，全身四周籠罩在一股白色的修羅鬥氣之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), temp);
        if( me->is_fighting() ) me->start_busy(2);
        if( temp < fiendforce )
        function_improved("fight",random(skill)+i);
        return 1;
                       }
if (temp >= 15 && temp < 30){
        message_vision(
        HIW "$N運起『"HIM"修羅鬥氣"HIW"』第二重「[1;5;36m雷鼓震山川[0m"HIW"」，全身四周籠罩在一股綠色的修羅鬥氣之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), temp);
        if( me->is_fighting() ) me->start_busy(2);
        if( temp < fiendforce )
        function_improved("fight",random(skill)+i);
        return 1;
                       }
if (temp >= 30 && temp < 45){
        message_vision(
        HIW "$N運起『"HIM"修羅鬥氣"HIW"』第三重「[1;5;32m水精勢絕倫[0m"HIW"」，全身四周籠罩在一股青色的修羅鬥氣之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), temp);
        if( me->is_fighting() ) me->start_busy(2);
        if( temp < fiendforce )
        function_improved("fight",random(skill+2*2)+1);
        return 1;
                       }
if (temp >=45 && temp < 60){
        message_vision(
        HIW "$N運起『"HIM"修羅鬥氣"HIW"』第四重「[1;5;34m風沙暗夜吼[0m"HIW"」，全身四周籠罩在一股紫色的修羅鬥氣之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), temp);
        if( me->is_fighting() ) me->start_busy(2);
        if( temp < fiendforce )
        function_improved("fight",random(skill+3*2)+2);
        return 1;
                       }
if (temp >=60 && temp < 75){
        message_vision(
        HIW "$N運起『"HIM"修羅鬥氣"HIW"』第五重「[1;5;33m火光燎天戈[0m"HIW"」，全身四周籠罩在一股紅色的修羅鬥氣之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), temp);
        if( me->is_fighting() ) me->start_busy(2);
        if( temp < fiendforce )
        function_improved("fight",random(skill+4*2)+3);
        return 1;
                       }
if (temp >=75 && temp < 90){
        message_vision(
        HIW "$N運起『"HIM"修羅鬥氣"HIW"』第六重「[1;5;35m雨凝破山石[0m"HIW"」，全身四周籠罩在一股黃色的修羅鬥氣之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), temp);
        if( me->is_fighting() ) me->start_busy(2);
        if( temp < fiendforce )
        function_improved("fight",random(skill+5*2)+4);
        return 1;
                       }
if (temp >=90 && temp <105){
        message_vision(
        HIW "$N運起『"HIM"修羅鬥氣"HIW"』第七重「[1;5;31m電花照天河[0m"HIW"」，全身四周籠罩在一股銀色的修羅鬥氣之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), temp);
        if( me->is_fighting() ) me->start_busy(2);
        if( temp < fiendforce )
        function_improved("fight",random(skill+6*3)+5);
        return 1;
                       }
if (temp >=105 ){
        message_vision(
        HIW "$N運起『"HIM"修羅鬥氣"HIW"』"HIB"最終奧義"HIW"「[1;5;33m冰寒囓人心[0m"HIW"」，全身四周籠罩在一股金色的修羅鬥氣之內。\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), temp);
        if( me->is_fighting() ) me->start_busy(2);
        if( temp < 120 )
        function_improved("fight",random(skill+7*4)+6);
        return 1;
                       }
}

void remove_effect(object me, int skill)
{

        me->delete_temp("ashura_fight");
        me->add_temp("apply/dodge",-skill);
        me->add_temp("apply/parry",-skill);
        me->add_temp("apply/attack",-skill);
        me->add_temp("apply/defense",-50);
        message_vision("$N"HIW"『修羅鬥氣』"NOR"所形成的護身氣勁開始崩潰渙散了。\n"NOR,me);
}


