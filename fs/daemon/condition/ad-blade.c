// 秦嘯天 - 狂龍七斬訣專用
#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("no_power",1);
    tell_object( me , HIY + "你身上的無極刀傷發作，雷霆刀意腐蝕全身，頓時四肢無力，使不出勁。\n" + NOR);
    message("vision",HIC+me->name()+"體內" + HIM + "無極刀意" + HIC + "發作，雷霆電擊遊走全身，臉上顯示痛苦無比的表情！\n" + NOR,environment(me),me);
    me->add("kee",-350);
    me->add("eff_kee",-350);
    me->add("sen",-200);
    me->add("gin",-200);
    me->set_temp("no_power",1);
	me->set_temp("ad-blade",1);
    me->apply_condition("ad-blade",duration-1);
	COMBAT_D->report_status(me);
    if (duration < 1) {
    me->delete_temp("no_power",1);
	me->delete_temp("ad-blade",1);
    return 0;
    }
    return 1;
}
