// break-kee.c
// 破穴指 : 注意:bleeding 次數, 所損內力, 和升級點數.
// 重新改寫..by chan
// 分階段降低對手的攻擊力及防禦力、內力.屬特別武技
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
void remove_effect(object target, int amount);
int perform(object me, object target)
{
   string msg,*name;
   object ob,weapon;
   int value,sk_lv,em_lv,level,skill,sub_force,hurt;
if( !target ) target = offensive_target(me);
if(!target) return notify_fail("你找不到敵人!!\n");
 if(!(weapon=me->query_temp("weapon"))
 ||      (string)weapon->query("skill_type")!="stabber" )
         return notify_fail("要有適合的武器才能用破穴針。\n");
if(me->query_skill("yu-needle",1)<60)
return notify_fail("你的七奇針訣程度不夠﹐無法使用破穴指。\n");
if(!me->is_fighting(target))
return notify_fail("破穴指要在戰鬥中才能使用。\n");
if(me->query("family/family_name")!="銀針門")
return notify_fail("這種武功\只有銀針門的門人才可以使用。\n");
if((int)me->query("force")<150)
return notify_fail("你的內力不夠。\n");
if(target->query_temp("break-kee"))
return notify_fail("對方以經中了,破穴指了。\n");
 if(target->is_busy())
   level = 95;
 else
   level = 75;

 value = (int)query_function("break-kee");
 me->add("force",-150);
 sk_lv=me->query_skill("stabber");
 em_lv=target->query_skill("dodge"); //是算出enable dodge的值!!
 em_lv=em_lv / (random(2)+3);
 // 加點亂數，免得完全不會中

message_vision("
" + HIW + "                 $N氣貫全身，以渾厚的內力運起「" + HIG + "七奇針訣" + HIW + "－" + HIR + "破穴指" + HIW + "－」\n\n" + NOR + ""
"" + HIC + "                         $N將體內的真氣凝聚於針，隨即又使出～\n\n" + NOR + ""
"" + HIW + "                                  " + HIY + "ζ " + HIW + "影 " + HIM + "幻．" + HIR + "破 " + HIG + "穴 " + HIC + "針 " + HIY + "ζ\n\n" + NOR + ""
"" + HIY + "                         突然間～$N手中的針尖泛起一簇" + HIR + "紅色星芒" + HIW + "～\n\n" + NOR + ""
"" + HIW + "                       只見$N身影身形百化，無數的" + HIM + "幻影" + HIW + "攻擊著$n！！\n\n" + NOR,me,target);
value=random(value);
sk_lv=random(sk_lv);
sub_force=target->query("force");
if(random(100)<level) {//對方若沒有busy只有2成的成功率....有的話有七成 //提高命中率 by unfinished
if((value > 80) && (sk_lv > em_lv))
{
 message_vision(HIW + "$N的破穴針,剌中了$n的膻中穴,身上的真氣無法運行,使得攻擊力、防禦力、內力下降八成!!!\n" + NOR,me,target);
 skill=80;
 message_vision(HIY + "$N的破穴針,剌中了$n的膻中穴,勁力直透$n要害, 造成極大的傷害!!\n" + NOR,me,target);
 hurt=target->query("max_kee")/10;
 if (hurt > 10000) hurt = 10000;  //用來輔助對付新區域的大型mob
 sub_force=(sub_force*80)/100;
 target->add_temp("apply/dodge",-skill);
 target->add_temp("apply/parry",-skill);
 target->add_temp("apply/attack",-skill);
 target->add("force",-sub_force);
 target->set_temp("break-kee",1);
 target->receive_damage("kee",hurt);
 call_out("remove_effect",10,target,skill);
          }
else if((value > 60) && (sk_lv > em_lv)) {
 message_vision(HIW + "$N的破穴針,剌中了$n的膻中穴,身上的真氣無法運行,使得攻擊力、防禦力、內力下降八成!!!\n" + NOR,me,target);
 message_vision(HIY + "$N的破穴針,剌中了$n的膻中穴,勁力直透$n要害, 造成極大的傷害!!\n" + NOR,me,target);
 hurt=target->query("max_kee")/10;
 if (hurt > 8000) hurt = 8000;  //用來輔助對付新區域的大型mob
 skill=80;
 sub_force=(sub_force*80)/100;
 target->add_temp("apply/dodge",-skill);
 target->add_temp("apply/parry",-skill);
 target->add_temp("apply/attack",-skill);
 target->add("force",-sub_force);
 target->set_temp("break-kee",1);
 target->receive_damage("kee",hurt);
 call_out("remove_effect",10,target,skill);
          }
else if((value > 40) && (sk_lv > em_lv)) {
 message_vision(HIW + "$N的破穴針,剌中了$n的巨闕穴,身上的真氣無法運行,使得攻擊力、防禦力、內力下降六成!!!\n" + NOR,me,target);
 message_vision(HIY + "$N的破穴針,剌中了$n的膻中穴,勁力直透$n要害, 造成極大的傷害!!\n" + NOR,me,target);
 hurt=target->query("max_kee")/10;
 if (hurt > 6000) hurt = 6000;  //用來輔助對付新區域的大型mob
 skill=60;
 sub_force=(sub_force*60)/100;
 target->add_temp("apply/dodge",-skill);
 target->add_temp("apply/parry",-skill);
 target->add_temp("apply/attack",-skill);
 target->add("force",-sub_force);
 target->set_temp("break-kee",1);
 target->receive_damage("kee",hurt);
 call_out("remove_effect",10,target,skill);
          }
else if((value > 20 ) && (sk_lv > em_lv)) {
 message_vision(HIW + "$N的破穴針,剌中了$n的氣海穴,身上的真氣無法運行,使得攻擊力、防禦力、內力下降四成!!!\n" + NOR,me,target);
 message_vision(HIY + "$N的破穴針,剌中了$n的膻中穴,勁力直透$n要害, 造成極大的傷害!!\n" + NOR,me,target);
 hurt=target->query("max_kee")/10;
 if (hurt > 4000) hurt = 4000;  //用來輔助對付新區域的大型mob
 skill=40;
 sub_force=(sub_force*40)/100;
 target->add_temp("apply/dodge",-skill);
 target->add_temp("apply/parry",-skill);
 target->add_temp("apply/attack",-skill);
 target->add("force",-sub_force);
 target->set_temp("break-kee",1);
 target->receive_damage("kee",hurt);
 call_out("remove_effect",10,target,skill);
// target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill:), skill/2);
          }
else {
 message_vision(HIW + "$N的破穴針,剌中了$n的天突穴,身上的真氣無法運行,使得攻擊力、防禦力、內力下降二成!!!\n" + NOR,me,target);
 message_vision(HIY + "$N的破穴針,剌中了$n的膻中穴,勁力直透$n要害, 造成極大的傷害!!\n" + NOR,me,target);
 hurt=target->query("max_kee")/10;
 if (hurt > 2000) hurt = 2000;  //用來輔助對付新區域的大型mob
 skill=20;
 sub_force=(sub_force*20)/100;
 target->add_temp("apply/dodge",-skill);
 target->add_temp("apply/parry",-skill);
 target->add_temp("apply/attack",-skill);
 target->add("force",-sub_force);
 target->set_temp("break-kee",1);
 target->receive_damage("kee",hurt);
 call_out("remove_effect",10,target,skill);
     }
}
else
message_vision(MAG + "$n急使輕功\!!千均一刻之際!!避開$N的可怕攻擊!!!\n" + NOR,me,target); 

message_vision(HIR + "$N使出破穴針後!!內勁損耗過大，趕緊運氣調息。\n" + NOR,me);
me->start_busy(1);
COMBAT_D->report_status(target, 1);
 value = (int)query_function("break-kee");
if(value < 100)
function_improved("break-kee",random(me->query("max_force")/15+me->query_skill("yu-needle",1)/2));
        return 1;
}

void remove_effect(object target, int skill)
{
if(!target) return ;
target->delete_temp("break-kee");
target->add_temp("apply/dodge",skill);
target->add_temp("apply/parry",skill);
target->add_temp("apply/attack",skill);
message_vision(HIY + "$N被封住穴道慢慢解開了,所喪失的功\力也慢慢恢復了!!!。\n" + NOR,target);
}
