//極火金身
// 沒enable fireforce 放的出來？修正為要enable 才行...by whatup 2004/01/03
#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,force,fireforce,temp;
        force=me->query("max_force"); 
        fireforce=me->query_skill("fireforce",1);

        if( !me->query("quest/gold-fire") ) return notify_fail("你沒有學會此心法\n");

     if( (string)me->query_skill_mapped("force")!= "fireforce" && !wizardp(me))
     return notify_fail("極火金身要用極火功\來啟動。\n");
    
        if (me->query("force") < force/6)
        return notify_fail("你的內力不夠，不能運起極火金身。\n");

        if(me->query_temp("gold-fire")==1) return notify_fail("你已經在用了。\n");

        temp=me->query("functions/gold-fire/level","gold-fire");
        skill = temp;
	if( skill >= fireforce ) skill = fireforce;
        if (skill > 90) skill = 90;
        me->add("force",-force/6);
        me->set_temp("gold-fire",1);
if (skill < 14){
        message_vision(
        HIM + "$N運起極火金身第一層「天極身」，全身四周籠罩在一股紫色的護身氣勁內！。\n" + NOR,me);
	me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);
 
        return 1;
                       }
if (skill >=14 && skill < 28){
        message_vision(
        HIG + "$N運起極火金身第二層「地極身」，全身四周籠罩在一股綠色的護身氣勁內！。\n" + NOR,me);
	me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
                       }
if (skill >= 28 && skill < 42){
        message_vision(
        HIW + "$N運起極火金身第三層「人極身」，全身四周籠罩在一股白色的護身氣勁內！。\n" + NOR,me);
	me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
                       }
if (skill >=42 && skill < 56){
        message_vision(
        HIB + "$N運起極火金身第四層「魔極身」，全身四周籠罩在一股藍色的護身氣勁內！。\n" + NOR,me);
	me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
                       }
if (skill >=56 && skill < 70){
        message_vision(
        HIC + "$N運起極火金身第五層「龍極身」，全身四周籠罩在一股青色的護身氣勁內！。\n" + NOR,me);
	me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
                       }
if (skill >=70 && skill < 84){
        message_vision(
        HIR + "$N運起極火金身第六層「火極身」，全身四周籠罩在一股火紅的護身氣勁內！。\n" + NOR,me);
	me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
                       }
if (skill >=84){
        message_vision(
        HIY + "$N運起極火金身頂級功\力「極火金身」，四周金光暴現，並有熊熊烈火環繞在$N的四周！。\n" + NOR,me);
	me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
                       }
}
 
void remove_effect(object me, int skill)
{
   int fireforce=me->query_skill("fireforce",1);
   if(skill >= 90) me->set("functions/gold-fire/level",90);
        else if(skill < fireforce )
        function_improved("gold-fire",(skill*7+random(skill*8)));

        me->delete_temp("gold-fire");
        me->add_temp("apply/defense",-skill);
        message_vision("$N的護身氣勁開始崩潰渙散了。\n",me);
}
