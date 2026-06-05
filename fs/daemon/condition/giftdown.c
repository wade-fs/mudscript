// 用 condition 來控制以免造成 crash 時屬性降不下來的問題 by swy
//giftout.c
//調整為少林版 由於是初級fun 所以弱化 且依據新表達式撰寫 by blazakira
#include <ansi.h>
inherit F_FUNCTION;
int update_condition(object me, int duration)
{
	int fun = me->query("functions/basicup/level"),g;
	if(duration==0 && me && me->query_temp("basicup")) {
		g=me->query_temp("setgift-bonze"); //因為重登 所以此數值不存在 >> g=0 所以 以下皆沒有影響
		me->delete_temp("basicup");
		me->add_temp("apply/str",-g); //因為為初階fun 所以最多數值+10
		me->add_temp("apply/cps",-g);
		me->add_temp("apply/cor",-g);
		me->add_temp("apply/int",-g);
		me->add_temp("apply/spi",-g);
		me->add_temp("apply/kar",-g);
		if(fun<100) { function_improved("basicup",random(500)+fun); }
		tell_object(me,WHT + "你覺得「印契」之力流失了。\n" + NOR);
		return 0;
		}
	else if(!me->query_temp("basicup")) {return 0;} //避免離線後 仍有訊息
	else {//其他就是當duration >0 的情況
	tell_object(me,HIG + "你『" + MAG + "舒筋活骨" + HIG + "』後彷彿身材變得更加魁梧了。\n" + NOR); //由於少林只有男性所以不考慮女性形容
	message("vision",HIG+me->name()+"散發出一種『" + MAG + "舒筋活骨" + HIG + "』後帶來的震攝力，使附近的人感受到一股威壓。\n" + NOR,environment(me),me);
	me->apply_condition("giftdown",duration-1);
	return 1;
	}
}
