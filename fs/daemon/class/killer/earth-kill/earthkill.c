#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target,object *enemy)
{
int fun,damage;
string msg;
string *name;
if( !target ) target = offensive_target(me);
if(me->query("class") != "killer")
return notify_fail("你的職業無法使用。\n");
if((me->query_skill("earth-kill",1) < 40))
return notify_fail("你的地斬修為不足，無法使出此奧義。\n");
if((string)me->query_skill_mapped("dagger")!= "earth-kill")
return notify_fail("裏˙伊賀流奧義必須使用『地斬』!!\n");
if( me->query("family/family_name") != "黑牙聯" )
return notify_fail("裏˙伊賀流奧義只有伊賀派的門人才可以使用。\n");
if(me->query("force")<300)
return notify_fail("你的內力不夠。\n");
if(me->query("bellicosity")<50)
return notify_fail("你的殺氣不夠。\n");
if(!me->is_fighting(target))
return notify_fail("裏˙伊賀流奧義只能在戰鬥中才能使用。\n");
fun=me->query("functions/earthkill/level");
damage=me->query("functions/manakee/level")+fun+me->query_skill("earth-kill",1);
message_vision(GRN + "裏 ˙ 伊 賀 流 奧 義" + HIW + " －－" + HIY + "『" + YEL + " 地    斬 " + HIY + "』\n\n" + NOR,me);
if( 20 < random(100) )
{
message_vision(MAG + "\n$n被$N的第一招奧義" + RED + "烈火蜂" + MAG + "擊中, 造成極為嚴重的燒傷!!\n" + NOR,me,target);
target->receive_wound("kee",damage);
target->apply_condition("burn",10);
me->add("force",-30);
me->add("bellicosity",-10);
COMBAT_D->report_status(target, 1);
if (fun > 20)
{
message_vision(MAG + "\n$n被$N的第二招奧義" + HIB + "寒冰蝶" + MAG + "擊中, 造成極為嚴重的凍傷!!\n" + NOR,me,target);
target->receive_wound("kee",damage);
target->apply_condition("cold",10);
me->add("force",-30);
me->add("bellicosity",-10);
COMBAT_D->report_status(target, 1);
}
if (fun > 40)
{
message_vision(MAG + "\n$n被$N的第三招奧義" + HIY + "毒  牙" + MAG + "擊中, 造成極為嚴重的毒傷!!\n" + NOR,me,target);
target->receive_wound("kee",damage);
target->apply_condition("snake_poison",10);
me->add("force",-30);
me->add("bellicosity",-10);
COMBAT_D->report_status(target, 1);
}
if (fun > 60)
{
message_vision(MAG + "\n$n被$N的第四招奧義" + HIW + "氣  戟" + MAG + "刺中, 造成極為嚴重的內傷!!\n" + NOR,me,target);
target->receive_wound("kee",damage);
target->apply_condition("hart",10);
me->add("force",-300);
me->add("bellicosity",-50);
COMBAT_D->report_status(target, 1);
}
if (fun > 80)
{
message_vision(MAG + "\n$n被$N的第五招奧義" + HIR + "血  刃" + MAG + "劈中, 造成極為嚴重的外傷!!\n" + NOR,me,target);
target->receive_wound("kee",damage);
target->apply_condition("bleeding",10);
me->add("force",-300);
me->add("bellicosity",-50);
COMBAT_D->report_status(target, 1);
}
if (fun > 99)
{
message_vision(MAG + "\n$n被$N的最終之奧義" + HIC + "空  蟬" + MAG + "劈中, 造成極為嚴重的震傷!!\n" + NOR,me,target);
target->receive_wound("kee",damage);
target->start_busy(1);
me->add("force",-30);
me->add("bellicosity",-10);
COMBAT_D->report_status(target, 1);
} 
}
else
{
message_vision(HIC + "\n$N在千均一刻之際，躲過地斬奧義的連續攻擊!!\n" + NOR,target);
}
message_vision(HIW + "\n$N使出地斬奧義的連續攻擊後內勁損耗過大, 蹲在一旁喘息。\n" + NOR,me);
me->start_busy(1);
if(me->query("functions/earthkill/level") < 100)
{
function_improved("earthkill",random(50));
}
message_vision( NOR,me);
return 1;
}

