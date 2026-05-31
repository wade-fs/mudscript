//mk-blade addbasic
//調整為少林版 由於是初級fun 所以弱化 且依據新表達式撰寫 by blazakira
#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int fun,k,g,saulinforce;
	fun = me->query("functions/basicup/level");
	k=(int)(fun/5);
	if( k < 1 ) k=1;
	g=(int)(fun/10);
	if( g < 1 ) g=1;
	if( me->query("force") < 300 )
		return notify_fail("你的內力不夠。\n");
	if( me->is_fighting() )
		return notify_fail("戰鬥中不能使用。\n");
	if (me->query("class") != "bonze")
		return notify_fail("你的職業體會不到佛法。\n");
//	if( !me->query("bonze/force/ponaforce") )
//		return notify_fail("要用大手印得先學會破衲功\才行。\n");
	if( (string)me->query_skill_mapped("force")!= "saulinforce" )
		return notify_fail("大手印要以少林內功\做基礎。\n");
//	if( me->query("env/force") != "ponaforce" && me->query("env/force") != "破衲功\" )
//		return notify_fail("大手印要用破衲功\來啟動。\n");
	if (me->query("s_kee") < 100) //因為等級最高為100 且 限制並非指最大值
		return notify_fail("你佛法領悟不足，無法聚神使出大手印。\n");
	if( me->query_temp("basicup") == 1 )
		return notify_fail("你已手結「印契」使身體機能活化。\n");
	message_vision(HIW"$N雙手迅速結出各種藏傳「印契」與自身經絡相呼應。\n"NOR,me);
	message_vision(HIW"陣陣暖流流經你的四肢百骸與五臟六腑後，$N的筋骨發出一陣爆響。\n"NOR,me);
	if (fun > 100) fun = 100; //直接鎖死數值
		me->add_temp("apply/str",g); //因為為初階fun 所以最多數值+10
		me->add_temp("apply/cps",g);
		me->add_temp("apply/cor",g);
		me->add_temp("apply/int",g);
		me->add_temp("apply/spi",g);
		me->add_temp("apply/kar",g);
		me->set_temp("setgift-bonze",g); //作為數值紀錄 給予condition做判斷
		me->apply_condition("giftdown",k); //因為增加數值的減少 所以增加時間作為交換
		me->set_temp("basicup",1);
		me->add("force",-fun*10);
		me->add("s_kee",-fun); //增加與佛法的相關性
		return 1;
}
