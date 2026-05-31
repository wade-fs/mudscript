// by swy 用於 mk-blade
// 修改 by frequency
#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) return 0;
if(me->query("family/family_name") == "金刀門")
{
 tell_object(me , HIW"你的『"HIG"刃葉刀鎧"HIW"』浮動包圍保護全身。\n" NOR);
message("vision",HIY+me->name()+"週身落葉懸浮『"HIG"刃葉刀鎧"HIY"』將身上破綻圍得如鐵筒般密實。\n"NOR,environment(me),me);
}else{
     tell_object(me , HIW"你的『"HIR"血氣鬥鎧"HIW"』，迅速漫延保護全身。\n" NOR);
     message("vision",HIC+me->name()+"全身發紅『"HIR"血氣鬥鎧"HIC"』散佈全身，方圓十里都隴罩在血光之下。\n"NOR,environment(me),me);
     }
me->apply_condition("bloodcloth",duration-1);
if (duration < 1) return 0;
return 1;
}
