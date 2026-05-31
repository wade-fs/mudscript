#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_FUNCTION;
int perform(object me, object target)
{
object ob;
int fun,k,b;
fun=me->query("functions/power-dest/level");
k=random(100)+1;
b=me->query_skill("blade")*6;
if(me->query("family/family_name")!="魔刀門" &&
me->query("family/family_name")!="魔刀莫測")
return notify_fail("你不是本派不能用。\n");
if( !target ) target = offensive_target(me);
if(me->query_skill("dragon-blade",1)<90)
       return notify_fail("你的狂龍刀法不夠熟練，不能聚氣於刀。\n");
if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="blade")
       return notify_fail("只有在裝備刀下，才能使用喔。\n");
       if(me->query("force")<100)
       return notify_fail("你的內力不夠。\n");
       if(me->query("kee")<20)
       return notify_fail("你的氣不夠。\n");
       if( !target
       ||      !target->is_character()
       ||      !me->is_fighting(target) )
       return notify_fail("『狂龍怒斬』只能在戰鬥中使用。\n");
if(k==100||me->query("id")=="swy"||(target->query("id")=="degu sa"&&random(10)==5)) {
message_vision(HIW
"$N突然領悟五式合一，把『狂龍怒斬』運行到最高境界。\n\n"NOR,me,target);
message_vision(HIW
"$N聚精會神，運起狂龍刀法的奧義『"HIR"狂龍怒斬～狂"HIW"』
$N把所聚狂氣釋放，瞬時一條狂龍飛舞奔向$n。\n\n"NOR,me,target);
message_vision(HIW
"$N聚精會神，運起狂龍刀法的奧義『"HIG"狂龍怒斬～龍"HIW"』
$N把所聚龍氣釋放，瞬時龍鬥氣破空飛斬向$n。\n\n"NOR,me,target);
message_vision(HIW
"$N聚精會神，運起狂龍刀法的奧義『"HIY"狂龍怒斬～怒"HIW"』
$N把所聚怒氣釋放，瞬時怒氣變成怨氣飛向$n。\n\n"NOR,me,target);
message_vision(HIW
"$N聚精會神，運起狂龍刀法的奧義『"HIB"狂龍怒斬～斬"HIW"』
$N把所聚集氣釋放，瞬時刀勁形成刀網撲向$n。\n\n"NOR,me,target);
message_vision(HIW
"$N聚精會神，運起狂龍刀法的最高奧義『"HIC"狂～龍～怒～斬"HIW"』
$N把所有氣同時釋放，瞬時一股強勢的刀勁已妖斬$n。\n"NOR,me,target);
// 機率 1% 所以為五倍傷害 by swy
b=b*5;
} else if(k<=20) {
message_vision(HIW
"$N聚精會神，運起狂龍刀法的奧義『"HIR"狂龍怒斬～狂"HIW"』\n
$N把所聚狂氣釋放，瞬時一條狂龍飛舞奔向$n。\n"NOR,me,target);
} else if(k<=40&&k>=21) {
message_vision(HIW
"$N聚精會神，運起狂龍刀法的奧義『"HIG"狂龍怒斬～龍"HIW"』\n
$N把所聚龍氣釋放，瞬時龍鬥氣破空飛斬向$n。\n"NOR,me,target);
} else if(k<=60&&k>=41) {
message_vision(HIW
"$N聚精會神，運起狂龍刀法的奧義『"HIY"狂龍怒斬～怒"HIW"』\n
$N把所聚怒氣釋放，瞬時怒氣變成怨氣飛向$n。\n"NOR,me,target);
} else if(k<=80&&k>=61) {
message_vision(HIW
"$N聚精會神，運起狂龍刀法的奧義『"HIB"狂龍怒斬～斬"HIW"』\n
$N把所聚集氣釋放，瞬時刀勁形成刀網撲向$n。\n"NOR,me,target);
} else {
message_vision(HIW
"$N聚精會神，運起狂龍刀法的最高奧義『"HIC"狂～龍～怒～斬"HIW"』\n
$N把所有氣同時釋放，瞬時一股強勢的刀勁已妖斬$n。\n"NOR,me,target);
}
          me->add("kee",-50);
          me->add("force",-100);
if(80>random(100))
  {
message_vision(HIW
"\n"+target->name()+"躲避不及，被刀勁貫穿而過，嘶嚎不斷。\n"NOR,me,target);
target->receive_wound("kee",b+fun,me);
// 對mob較強為了解sa by swy
if(userp(me)&&(!userp(target))) { target->receive_wound("kee",b+fun,me); }
        COMBAT_D->report_status(target);
        }
        else
      {
message_vision(YEL"$n在危急時刻猛然一閃，躲開了狂龍刀氣。\n"NOR,me,target);
       }
        message_vision(HIW
"『狂龍怒斬』使出後，大耗內力，無法移動。\n"NOR,me,target);
        me->start_busy(1);
if(fun<100) { function_improved("power-dest",random(500)); }
        return 1;
  }
