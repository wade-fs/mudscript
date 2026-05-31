//修正一點小bug，幻指常常抓不到敵人還是照常發
//希望修正後可以避免這情形 by Neverend
#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
int fun;
int perform(object me,object target)
{
	object weapon;
	int k1,k2,k3;
	if( !target ) target = offensive_target(me);
	if( !target)	return notify_fail("沒有敵人，你封誰呀!!\n");
	fun=me->query("functions/finger/level");
	if( me->query("family/family_name") != "儒門")
	return notify_fail("儒門幻指豈是汝輩所能控制的了的...\n");
	if(!me->is_fighting(target))
	return notify_fail("儒門幻指只能在戰鬥中使用。\n");
	if(!(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="stabber" )
	return notify_fail("要有適合的武器才能用儒門幻指。\n");
	if(me->query("force") < 100)	return notify_fail("你的內力不夠。\n");
	me->add("kee",-50);
	me->add("force",-100);
        message_vision(
""HIW"$N突然從招式中的變化領悟到了行雲流水筆法的最終奧義
"HIR" ==================================================
 ==============   "HIM"儒   門   幻   指 "HIR" ==============
 ==================================================\n"
NOR,me,target);
	if( 80 > random(100))
	{
	message_vision(
""HIC"$n無法摸清儒門幻指的破綻﹐被幻指所困惑﹐令$n的精神渙散﹗\n"
NOR,me,target);
	k1=target->query("max_gin")/5;
	k2=target->query("max_kee")/5;
	k3=target->query("max_sen")/5;
	if(k1>300) k1=300;
	if(k2>500) k2=500;
	if(k3>300) k3=300;
	target->receive_damage("gin",(fun*4+k1));
	target->receive_damage("kee",(fun*8+k2));
	target->receive_damage("sen",(fun*4+k3));
	}else{
	message_vision(
""HIC"$n看透了幻指中精妙的變化﹐剛好從$n身邊擦過。\n"NOR,me,target);
	}
	if(fun<100)
	function_improved("finger",random(500));
    me->start_busy(1);
	return 1;
}

