
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
object ob;
string *name;
if( !target ) target = offensive_target(me);
if(me->query_skill("gforce",1)<100)
return notify_fail("你的紫星河心法不夠熟練 , 不能凝神聚氣。\n");
if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="unarmed")
return notify_fail("只有在裝備武器時，才能使用啦。\n");
       if(me->query("force")<300)
       return notify_fail("你的內力不夠。\n");
if(me->query("class")!="taoist")
return notify_fail("歹勢!! 你不是道士，所以不能用天罡\戰氣。\n");
if( me->query_skill_mapped("dodge")!="g-steps")
return notify_fail("你沒有用追星步法。\n");
       if(me->query("kee")<150)
       return notify_fail("你的氣不夠。\n");
       if(me->query("combat_exp")<300000)
return notify_fail("你的經驗值不足 , 無法領悟天罡\戰氣。\n");
       if( !target
       ||      !target->is_character()
       ||      !me->is_fighting(target) )
return notify_fail("天罡\戰氣只能在戰鬥中使用。\n");
message_vision(""HIY"$N氣貫全身,以渾厚的內力氣通任督二脈\n"NOR""
  ""HIC"                 $N全身散發出一道道強大盛大的氣流\n"NOR""
  ""HIW"        $N週邊的氣流逐漸聚集在四周,漸漸在身邊圍繞成一氣團\n"NOR""
 ""HIG"                $N身形倏然跋起,在半空中環旋了三周半\n"NOR"",me,target);

message_vision(HIW"          只見$N翻身俯衝－－$N有如一氣柱往"+target->query("name")+"俯衝---\n
                 $N使用的招式乃是紫星河心法之
                      *  仙風雲體術  *

 "HIR"                     『 天 罡\ 戰 氣 』\n"NOR,me,target);
me->add("kee",-20);
me->add("force",-150);
if(random(me->query_skill("unarmed")-10)>random(target->query_skill("force")+10))
  {
        message_vision(
"\n"+target->name()+HIC"來不及反應，已被$N狠狠的貫穿而過，痛苦萬分。\n"NOR,me,target);
        message_vision( NOR,me);
target->receive_wound("kee",me->query_skill("g-steps",1)*3);
        COMBAT_D->report_status(target);

        }
        else
      {
message_vision(YEL"$n在直覺反應下猛然一閃，躲開了攻擊。\n"NOR,me,target);
       }
        message_vision(HIW
"使出『天罡\戰氣』後，大耗體力，要先休息一下。\n"NOR,me,target);
        me->start_busy(2);
        message_vision( NOR,me);
        return 1;
  }
 
