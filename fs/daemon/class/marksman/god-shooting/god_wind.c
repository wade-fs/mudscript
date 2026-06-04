#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
        int ski_value,fun,lv,a;
        string msg;
        object ob;
        fun=me->query("functions/god_wind/level");
lv = random(fun/19);
        if( !target ) 
        target = offensive_target(me);
        if(!target) 
        return notify_fail("你找不到敵人!!!\n");
        if( me->query_skill("god-shooting",1) < 100 )
        return notify_fail("你的箭法技巧不足。\n");
if( me->query("family/family_name") != "射日派" && me->query("id")!="superobs" )
        return notify_fail("只有射日派的弟子才能用十萬火急\n");
if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="archery")
        return notify_fail("要裝備弓才能用吧。\n");
        if(me->query("force")<400)
        return notify_fail("你的內力不夠。\n");
        if(me->query("kee")<150)
        return notify_fail("你的氣不夠。\n");
        if(!me->is_fighting(target))
        return notify_fail("神風舞九翎在戰鬥中才能使用。\n");
message_vision(HIR + "
$N體內功\力潛運，真氣源源不斷在體內流轉，手中箭翎在翻轉中箭化流星，直襲天際

                           流星箭法絕式之一

                       『" + HIM + "神風舞九翎" + HIR + "』

箭翎由空直取$n，箭翎因神風催動箭速燃燒四周空氣引起火燄，瞬時一片火光！

" + NOR,me,target);
if (70 > random (100))
{
   for( a=1;a<=lv;a++)
{
message_vision(HIW + "箭如" + HIC + "流星" + HIW + "，不斷由天際朝$n周身破綻襲去!" + NOR + "\n",me,target);
           target->receive_damage("kee",fun*3,me);
        function_improved("god_wind",random(500));
           COMBAT_D->report_status(target);
}
}
else
{
write(HIR + "箭的準頭失去，已偏離目標!" + NOR + "\n",me,target);
}
      }
