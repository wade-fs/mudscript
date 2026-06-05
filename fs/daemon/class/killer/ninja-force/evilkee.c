#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target,object *enemy)
{
int fun,damage;
string msg;
string *name;
if( !target ) target = offensive_target(me);
if((me->query_skill("darkforce",1) < 100))
return notify_fail("你的真˙黑牙神功\修為不足，無法使出此奧義。\n");
if((string)me->query_skill_mapped("force")!= "darkforce")
return notify_fail("真˙魔氣殺必須使用『真˙黑牙神功\』!!\n");
if( me->query("family/family_name") != "黑牙聯" )
return notify_fail("真˙魔氣殺只有伊賀派的門人才可以使用。\n");
if(me->query("force") < 300)
return notify_fail("你的內力不夠。\n");
if(me->query("bellicosity") < 50 ) 
return notify_fail("你的殺氣不夠。\n");
if(!me->is_fighting())
return notify_fail("真˙魔氣殺只能在戰鬥中才能使用。\n");
if(target->query_busy() > 0)
return notify_fail("對手正動彈不得。\n");
fun=me->query("functions/evilkee/level");
damage=me->query("functions/manakee/level")*4+fun*6;
message_vision(CYN + "
                   $N瞬間殺意狂升,以殺意換成魔氣。
                     " + MAG + "$N身上發出一股強大的魔氣……
           " + HIW + "■" + HIB + "$N身上魔氣逐漸地往四處散發, 四周光線頓時消失" + HIW + "■
                           " + HIY + "黑牙神功\秘奧義
                       " + HIC + "––" + HIW + "「" + GRN + "真˙魔氣殺" + HIW + "」" + HIC + "––
\n" + NOR,me);
if( 20 < random(100) )
{
if(fun >= 0 && fun < 20 )
{
message_vision(HIG + "$N受到魔氣傷害全身無法動彈並受到輕微凍傷!!\n" + NOR,target);
target->add("kee",-damage);
target->start_busy(1);
target->apply_condition("cold",5);
me->add("bellicosity",-100);
COMBAT_D->report_status(target, 1);
}
if (fun >= 20 && fun < 40 )
{
message_vision(HIG + "$N受到魔氣傷害全身無法動彈並受到輕微灼傷!!\n" + NOR,target);
target->add("kee",-damage);
target->start_busy(2);
target->apply_condition("burn",5);
me->add("bellicosity",-100);
COMBAT_D->report_status(target, 1);
}
if (fun >= 40 && fun < 60)
{
message_vision(HIG + "$N受到魔氣傷害全身無法動彈並受到嚴重內傷!!\n" + NOR,target);
target->add("kee",-damage);
target->start_busy(2);
target->apply_condition("hart",10);
me->add("bellicosity",-100);
COMBAT_D->report_status(target, 1);
}
if (fun >= 60 && fun < 80)
{
message_vision(HIG + "$N受到魔氣傷害全身無法動彈並受到魔氣纏身!!\n" + NOR,target);
target->add("kee",-damage);
target->start_busy(3);
target->apply_condition("mkill_out",10);
me->add("bellicosity",-100);
COMBAT_D->report_status(target, 1);
}
if (fun >= 80 && fun < 100)
{
message_vision(HIG + "$N受到魔氣傷害全身無法動彈並且氣血失調!!\n" + NOR,target);
target->add("kee",-damage);
target->start_busy(3);
target->apply_condition("ff_poison",10);
me->add("bellicosity",-100);
COMBAT_D->report_status(target, 1);
}
if (fun == 100)
{
message_vision(HIG + "$N受到魔氣傷害全身無法動彈並且氣血失調, 失去心智!!\n" + NOR,target);
target->add("kee",-damage);
target->start_busy(3);
target->apply_condition("mess",2);
target->apply_condition("ff_poison",10);
me->add("bellicosity",-100);
COMBAT_D->report_status(target, 1);
}}
else
{
message_vision(HIC + "$N心境空明, 識破了這個以魔氣所佈下的幻覺!!\n" + NOR,target);
}
if(me->query("functions/evilkee/level") < 100)
{
function_improved("evilkee",random(100));
}
message_vision( NOR,me);
return 1;
}

