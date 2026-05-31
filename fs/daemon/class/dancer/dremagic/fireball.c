#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
int k;
int conjure (object me, object target)
{
string msg;
fun=me->query("spells/fireball/level");
if (!me->query("spells/fireball/level")) return 0;

if(me->query("class")!="dancer")
return notify_fail("這法術只有舞者能用。\n");

if( !target ) target = offensive_target(me); 
if(!target) return notify_fail("你找不到對手!!\n");

if(!me->is_fighting(target) )
 return notify_fail("這法術只能對戰鬥中的對手使用。\n");

if(me->query("atman") < 50 )
return notify_fail("你的法力不足\n");

if(me->query_temp("fireball")==1)
return notify_fail("你正在施法中\n");

if( fun <= 20) {
msg = CYN "$N突然唸著：" NOR ;
msg += HIR "幻～火！\n" NOR ;
msg += HIW "$N祭起一團火球轟向$n。\n" NOR;
k=fun*2;
} else if( fun>=21&&fun<=40) {
msg=CYN "$N突然唸著：" NOR ;
msg+= HIR "妖～火！\n" NOR;
msg += HIW "$N祭起一團火球轟向$n。\n" NOR;
k=fun*3;
} else if( fun>=41&&fun<=60) {
msg=CYN "$N突然唸著：" NOR ;
msg+= HIR "三～昧～真～火！\n" NOR;
msg += HIW "$N祭起一團火球轟向$n。\n" NOR;
k=fun*4;
} else if( fun>=61&&fun<=80) {
msg=CYN "$N突然唸著：" NOR ;
msg+= HIR "天～火！"+HIY+"地～火！"+HIB+"陰～火！\n" NOR;
msg += HIW "$N祭起三團火球轟向$n。\n" NOR;
k=fun*5;
} else if( fun>=81 && me->query("adv_dancer")==1)
{
msg=CYN "$N突然大喊：" NOR ;
msg+= HIR "怒"+HIW+"～"+HIR+"火"+HIW+"～"+HIR+"燒"+HIW+"～"+HIR+"盡"+HIW+"～"+HIR+"九"+HIW+"～"+HIR+"重"+HIW+"～"+HIR+"天！\n" NOR;
msg += HIW "只見$n身旁盡是無邊無際的火海。\n" NOR;
k=fun*8;
}
else{
msg=CYN "$N突然唸著：" NOR ;
msg+= HIM "熔～岩～煉～獄～波！\n" NOR;
msg += HIW "$N祭起一片火海轟向$n。\n" NOR;
k=fun*6;
}

message_vision(msg, me, target);
me->set_temp("fireball",1);
call_out("act1",1,msg,target,me,fun,k);
return 1;

}

int act1(string msg,object target,object me,int fun,int k) {
if(!me) return 1;
me->set_temp("fireball",0);
if(!target || !me) return 1;
if(!target) return 1;
if(me->is_fighting(target)) {
if(80>random(100))
{
msg = HIM "結果$p被$P的火球術擊中！\n" NOR;
target->receive_wound("kee",k+200,me);
target->apply_condition("burn",random(10) +fun/10);
} 
else
{
msg = CYN "結果$p躲過了$P的火球術。\n" NOR;
}
me->add("atman",-50);
message_vision(msg, me, target);
COMBAT_D->report_status(target);
if(fun<100) spell_improved("fireball",random(500));
}
        return 1;
}
