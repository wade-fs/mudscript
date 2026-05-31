// 醫生的金針封穴
// design by chan
// (改版) by nike
// 將金針封穴改為打全體之招式...

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me,object target)
{
    object *enemy, ob, weapon;
    int i,value, sk_lv, em_lv, stab, attack, str;
    enemy=me->query_enemy();
    i=sizeof(enemy);

    if(!me->is_fighting(target))
	return notify_fail("金針封穴只能在戰鬥中使用。\n");
    if(!weapon=me->query_temp("weapon") || weapon->query("skill_type")!="stabber" )
	return notify_fail("要有適合的武器才能用金針封穴。\n");
    if( me->query("family/family_name") != "銀針門" )
	return notify_fail("金針封穴只有銀針門的門人才可以使用。\n");
    if((int)me->query_skill("yu-needle",1) < 40)
	return notify_fail("你的七奇針訣不夠純熟，無法使出金針封穴。\n");
    if((int)me->query("force")<300)
	return notify_fail("你的內力不夠使出金針封穴。\n");
    if(target->is_busy() || enemy[i]->is_busy())
	return notify_fail("敵人現在不能動,快攻擊吧!!!!\n");

	me->add("force",-300);
	value=query_function("gold-needle");
	sk_lv=me->query_skill("yu-needle",1);
	em_lv=target->query_skill("dodge"); //是算出enable dodge的值!!
	em_lv=em_lv /3;
	message_vision("
 "HIW"                $N暗運真氣，手上的閃放出如"HIC"繁星"HIW"般的針芒，真氣從針尖激射而出～\n\n"NOR""
""HIW"                            $N眼視$n全身大穴，繁星般點點使出～～\n\n"NOR""
""HIY"                                    "HIC+HBBLU"ψ "HIY"金 "HIW"-- "HIY"針 "HIW"-- "HIY"封 "HIW"-- "HIY"穴 "HIC"ψ\n\n"NOR""
""HIC"                        突然間～"HIY"漫天針芒"HIW"～向$n的全身大穴急襲而去！！！\n\n"NOR,me,target);
	stab = (int)me->query_skill("stabber",1);
	if(stab > 120) stab = 120;
	sk_lv=random(sk_lv);
	value=random(value);
	str = (int)me->query_str();

    if((value > 80) && (sk_lv > em_lv))
{
	message_vision(HIW"$n身上的奇經八脈被$N金針封住，身上的真氣無法運行！\n" NOR,me,target);
	attack=stab*6;
	enemy[i]->receive_wound("kee",attack);
	str=str*2;
    if(100-str > 100)
	enemy[i]->start_busy(random(3)+2);
    else
	target->start_busy(3);
}
    else if((value > 60) && (sk_lv > em_lv))
{
	message_vision(HIY"$N一招使出，招式未待變老，旋即挺針直取$n的曲池穴！\n" NOR,me,target);
	attack=stab*6;
	enemy[i]->receive_wound("kee",attack);
	str=str*2.5;
    if(100-str > 100)
	enemy[i]->start_busy(random(3)+1);
    else
	target->start_busy(2);
}
    else if((value > 40) && (sk_lv > em_lv))
{
	message_vision(HIY"$n身上的氣海穴被$N金針氣勁所侵，真氣運行為之一頓！\n" NOR,me,target);
	attack=stab*5;
	enemy[i]->receive_wound("kee",attack);
	str=str*3;
    if(100-str > 100)
	enemy[i]->start_busy(1);
    else
	target->start_busy(1);
}
    else if((value > 20 ) && (sk_lv > em_lv))
{
	message_vision(GRN"結果$n手太陰經脈諸穴被$N金針封住，功\力大打折扣！\n" NOR,me,target);
	attack=stab*4;
	enemy[i]->start_busy(1);
	enemy[i]->receive_wound("kee",attack);
}
    else if((value > 0 ) && (sk_lv > em_lv))
{
	message_vision(GRN"$N翻身騰空，扶搖躍起，以迅雷不及掩耳之勢刺向$n的關元穴！\n" NOR,me,target);
	target->start_busy(2);
}
	else
{
	message_vision(MAG"$n看出針芒中有一空隙，使出步法避開$N的攻擊範圍！\n" NOR,me,target);
}
	message_vision(HIR"$N使出金針封穴後，內勁損耗過大，趕緊運氣調息！\n"NOR,me);
	me->start_busy(1);
	COMBAT_D->report_status(enemy[i],1);
	value = (int)query_function("gold-needle");
    if(value < 100)
	function_improved("gold-needle",random(me->query("max_force")/15+me->query_skill("yu-needle",1)/2));
	return 1;
}
