//修正ten_kee unfinished 2004/2/7
//在敵人沒有busy的時候減少傷害
//敵人在busy的時候由原本的無法使用改為可以使用但是不再busy敵人
//敵人busy時傷害增加
//用來增加marksman招式的變化性與趣味性
//最高傷害為1300 比原本多出400 稍能符合現今需求
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
        int ski_value,fun;
        string msg;
        object ob;
        fun=me->query("functions/ten_kee/level");
        if( !target ) target = offensive_target(me);
        if(!target) return notify_fail("你找不到敵人!!!\n");
        if( me->query_skill("god-shooting",1) < 20 )
        return notify_fail("你的箭法技巧不足。\n");
if( me->query("family/family_name") != "射日派" && me->query("id")!="swy" )
        return notify_fail("只有射日派的弟子才能用十萬火急\n");
if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="archery")
return notify_fail("要裝備弓才能用吧。\n");
        if(me->query("force")<150)
        return notify_fail("你的內力不夠。\n");
        if(me->query("kee")<150)
        return notify_fail("你的氣不夠。\n");
        if(!me->is_fighting(target))
        return notify_fail("十萬火急在戰鬥中才能使用。\n");
if(target->is_busy())
{
ski_value=random(50)+fun*2;
message_vision(HIG"
       $N趁著敵人慌亂之時，在體內運起雙重真氣並將真氣換形成幽冥之箭

       配合著縹緲的身法在$n四周環繞，幽冥箭正凝聚在弓上蓄勢待發

           $N使出全力將雙重幽冥箭放出，使出十萬火急之第二擊

                              『"HIC"幽冥雙箭"HIG"』

              幽冥箭如兩顆流星一般，帶著熊熊火焰劃破天際！

"NOR,me,target);
if(80>random(100)) {
        if( ski_value <= 25 ) {
           me->add("force",-100);
          write(HIR"在攻向敵人之前，幽冥箭漸漸消逝。\n"NOR);
          }
          else if( ski_value < 80 )
          {
          me->add("force",-100);
          target->receive_damage("kee",(fun*6)+100,me);
       //   target->start_busy(1);
          write ( "自己發覺箭術不夠精湛，且內力不夠精純。\n");
          }
          else if( ski_value < 120)
          {
           me->add("force",-100);
          // target->start_busy(2);
           target->receive_damage("kee",(fun*7)+200,me);
           write(HIR"幽冥箭已能從敵人身邊呼嘯而過，使的敵人受創不小。\n"NOR);
                 }
          else if( ski_value < 160 )
          {
           me->add("force",-100);
         //  target->start_busy(3);
           target->receive_damage("kee",(fun*8)+300,me);
           write(HIR"幽冥箭已能八成機率命中對方，使敵人受到嚴重的射傷。\n"NOR);
          }
          else
          {
           me->add("force",-100);
        //   target->start_busy(4);
           target->receive_damage("kee",(fun*9)+400,me);
           write(HIR"在你的攻擊之下，幽冥箭正確的命中敵人，敵人痛苦的倒在地上呻吟。\n"NOR);
           }
           }
else {
message_vision(HIW"$N的幽冥箭全數被$n躲過了。\n"NOR,me,target);
}
}

if(!target->is_busy())
{
ski_value=random(50)+fun*2;
message_vision(HIR"
       $N體內功\力潛運，真氣源源不斷在體內流轉，將真氣換形成幽冥之箭

       配合著縹緲的身法在$n四周環繞，幽冥箭正凝聚在弓上蓄勢待發

                    $N將幽冥箭放出，形成流星箭法之最終式

                                 『"HIM"十萬火急"HIR"』

       幽冥箭因急速放出，而燃燒四周空氣引起火燄，瞬時一片火光！

"NOR,me,target);
// 加上成功率 by swy
// 再給我偷改我就 ooxx by swy
if(80>random(100)) {
        if( ski_value <= 25 ) {
           me->add("force",-100);
          write(HIR"在攻向敵人之前，幽冥箭漸漸消逝。\n"NOR);
          }
          else if( ski_value < 80 )
          {
          me->add("force",-100);
          target->receive_damage("kee",(fun*2),me);
          target->start_busy(1);
          write ( "自己發覺箭術不夠精湛，且內力不夠精純。\n");
          }
          else if( ski_value < 120)
          {
           me->add("force",-100);
           target->start_busy(2);
           target->receive_damage("kee",(fun*3),me);
           write(HIR"幽冥箭已能從敵人身邊呼嘯而過，使的敵人受創不小。\n"NOR);
                 }
          else if( ski_value < 160 )
          {
           me->add("force",-100);
           target->start_busy(3);
           target->receive_damage("kee",(fun*4),me);
           write(HIR"幽冥箭已能八成機率命中對方，使敵人受到嚴重的射傷。\n"NOR);
          }
          else
          {
           me->add("force",-100);
           target->start_busy(4);
           target->receive_damage("kee",(fun*5),me);
           write(HIR"在你的攻擊之下，幽冥箭正確的命中敵人，敵人痛苦的倒在地上呻吟。\n"NOR);
           }
           }
else {
message_vision(HIW"$N的幽冥箭全數被$n躲過了。\n"NOR,me,target);
}}
        if(fun < 100) {
        function_improved("ten_kee",random(500)); }
        me->start_busy(1);
        COMBAT_D->report_status(target);
        message_vision( NOR,me);
        return 1;
}
