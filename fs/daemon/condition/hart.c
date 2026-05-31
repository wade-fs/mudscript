// Chan 1/5重新修正
// 用於瀧山的武學之中
//排版 by blazakira 2011/10/9

#include <ansi.h>

int update_condition(object me, int duration)
{
  if(duration==0) return 0;
  if( duration >= 1 )
  {
    tell_object(me,HIY"你的內傷發作，只覺得全身經脈好像移位般，十分痛苦!!\n"NOR);
    message("vision",me->name()+"[1;37m暗傷發作，整個人屈在地上表現出極為痛苦的表情。[0m\n",environment(me),me);
    if(me->is_fighting()) me->start_busy(1);
    me->add("kee",-150);
    me->add("force",-150);
    if( me->query("force") < 0 ) me->set("force",0);
    me->apply_condition("hart",duration -1);
    COMBAT_D->report_status(me, 1);
  }
  return 1;
}
