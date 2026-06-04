//重新編寫為天道的cast類技能 by neverend 2007.04.21

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_SPELL;

void remove_effect(object me, object target);

int cast(object me, object target)
{
	string msg,*name;
	object ob;
	int i,j,k,skill,mexp,texp,cexp;

	skill = me->query("spells/godfight/level");
	i = 102-skill;

	if( !target ) target = offensive_target(me);

	if( me->query_skill("gforce",1) < 100 )
	return notify_fail("你的紫星河心法不夠熟練 , 不能凝神聚氣。\n");

//	if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="unarmed")
//	return notify_fail("只有在裝備武器時，才能使用啦。\n");

	if( me->query("mana")< (skill*10+300) )
	return notify_fail("你的法力不夠。\n");

	if( me->query("class")!="taoist" )
	return notify_fail("歹勢!! 你不是道士，所以不能用天罡\戰氣。\n");

	if( me->query_skill_mapped("dodge") != "g-steps" )
	return notify_fail("你沒有用追星步法。\n");

	if( me->query("kee") < ((me->query("max_kee")/i)+1000) )
	return notify_fail("你的氣不夠運行天罡\戰氣。\n");

	if( !me->query("marks/god-kee") )
	return notify_fail("你還無法領悟這麼深的懊義。\n");

	if(me->query("combat_exp") < 300000 )
	return notify_fail("你的經驗值不足 , 無法領悟天罡\戰氣。\n");

	if( !target ||	!target->is_character() || !me->is_fighting(target) )
	return notify_fail("天罡\戰氣只能在戰鬥中使用。\n");

	if( me->query_temp("godfight") == 1 )
	return notify_fail("你的真氣不足以運行天罡\戰氣。\n");

	me->set_temp("godfight",1);
	me->improve_skill("necromancy", 1);

	if( skill < 10 )
	{
	message_vision("" + HIY + "$N聚起了一個小氣團朝" + HIW+target->query("name")+HIY + "撲去，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 起手第一式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 一 氣 飛 昇　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+3));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),10);
	}

	if( skill >= 10 && skill < 20 )
	{
	message_vision("" + HIY + "$N聚起了二個小氣團急速推向" + HIW+target->query("name")+HIY + "，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第二式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 氣 分 雙 星　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+5));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),10);
	}

	if( skill >= 20 && skill < 30 )
	{
	message_vision("" + HIY + "$N聚起了三個小氣團分做三個方向朝" + HIW+target->query("name")+HIY + "射去，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第三式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 三 元 擊 氣　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+7));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),11);
	}

	if( skill >= 30 && skill < 40 )
	{
	message_vision("" + HIY + "$N聚起了數個小氣團急速推向" + HIW+target->query("name")+HIY + "，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第四式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 氣 象 四 歸　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+9));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),11);
	}

	if( skill >= 40 && skill < 50 )
	{
	message_vision("" + HIY + "$N聚起了無數個小氣團分向" + HIW+target->query("name")+HIY + "急速撲去，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第五式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 氣 靈 五 轉　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+11));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),12);
	}

	if( skill >= 50 && skill < 60 )
	{
	message_vision("" + HIY + "$N體悟了精要的一式，氣走全身盈滿的真氣轉化為一擊攻向" + HIW+target->query("name")+HIY + "，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第六式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 氣 吞 六 神　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+13));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),12);
	}

	if( skill >= 60 && skill < 70 )
	{
	message_vision("" + HIY + "$N聚精會神的凝起了數個氣勁，轉化為實質可見的氣團一一擊向" + HIW+target->query("name")+HIY + "，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第七式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 氣 迴 七 穹　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+15));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),13);
	}

	if( skill >= 70 && skill < 80 )
	{
	message_vision("" + HIY + "$N氣走全身，周身大穴皆凝聚無數真氣，蓄勢待發的一擊，迅速的擊向" + HIW+target->query("name")+HIY + "，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第八式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 氣 游 八 仙　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+17));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),13);
	}

	if( skill >= 80 && skill < 90 )
	{
	message_vision("" + HIY + "$N真氣凝聚全身，一身的氣勁充盈不吐不快，身隨心轉氣隨意發擊向" + HIW+target->query("name")+HIY + "，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第九式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 氣 貫 九 天　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+19));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),14);
	}

	if( skill >= 90 && skill < 100 )
	{
	message_vision("" + HIY + "$N氣貫全身聚起了數道氣流圍繞周身，轉瞬間已朝" + HIW+target->query("name")+HIY + "衝去，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 流轉第十式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 霸 氣 匯 宗　ξ\n" + NOR,me,target);
	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	spell_improved ("godfight", random(skill+21));
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),14);
	}

	if( skill == 100 )
	{
	message_vision("" + HIY + "$N氣貫全身，以渾厚的內力氣通任督二脈，全身散發出一道道強大盛大的氣流聚集在$N四周圍繞成一氣團\n$N身形倏然跋起，在半空中環旋了三周半，有如一氣柱往" + HIW+target->query("name")+HIY + "俯衝，正是乃是紫星河心法之\n" + HIG + "
	－－－＊  仙風雲體術 － 終極破壞式  ＊－－－" + HIR + "
	     ξ　天 罡\ 戰 氣 ˙ 氣 撼 山 河　ξ\n" + NOR,me,target);

	me->receive_damage("kee",me->query("max_kee")/i);
	me->add("mana",-skill*10);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,target:),15);
	}

	mexp = me->query("combat_exp");
	texp = target->query("combat_exp");

	if( ((texp-mexp) / 100000) < 100 )
	cexp = 100;

	if( cexp > 800 )
	cexp = 800;

	if( random(cexp) < 80 )
	{
//	message_vision("\n"+target->name()+HIC + "來不及反應，已被天罡\戰氣擊中，痛苦萬分。\n" + NOR,me,target);
	message_vision("\n" + HIC + "$n來不及反應，已被天罡\戰氣擊中，痛苦萬分。\n" + NOR,me,target);
	target->receive_damage("kee",( me->query("max_kee")/i)*2 + random((me->query("max_kee")/i)*3) );
	target->receive_damage("sen",( me->query("max_sen")/i) + random((me->query("max_sen")/i)) );

	COMBAT_D->report_status(target);
	}else{
	message_vision(YEL + "\n$n在直覺反應下猛然一閃，躲開了攻擊。\n" + NOR,me,target);
	}

	tell_object(me,HIR + "使出『天罡\戰氣』後，大耗體力，要先休息一下。\n" + NOR);
//	message_vision(HIW + "$N使出『天罡\戰氣』後，大耗體力，要先休息一下。\n" + NOR,me,target);
	return 1;
  }
 
void remove_effect(object me,object target)
{

	me->delete_temp("godfight");
	tell_object(me,HIW + "體內的真氣開始盈滿了。\n" + NOR);
//	message_vision("$N體內的真氣開始盈滿了。\n",me);
	return;
}
