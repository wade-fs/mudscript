//將receive_damage的攻擊參數補上攻擊方之參數 by blazakira 2011/7/15

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
  int value,k_level,unit=1,i,hart=150;
  int other;
  string msg;
  object ob,victim = target;
  string *name;
  if( !target ) target = offensive_target(me);
  if(!target) return notify_fail("你找不到敵人!!\n");
  if((me->query_skill("snow-martial",1) < 50) || (me->query_skill("snowforce",1)<60) )
    return notify_fail("你的雪蒼武學及雪蒼心法不夠純熟，無法聚氣凝霜。\n");
  if( (string)me->query_skill_mapped("force")!= "snowforce")
    return notify_fail("雪影幻指必須使用雪蒼心法才能發揮威力。\n");
  if( me->query("family/family_name") != "雪蒼派" )
    return notify_fail("雪影幻指只有雪蒼派的門人才可以使用。\n");

  if(!(ob=me->query_temp("weapon")))
  {
    if(me->query_temp("secondary_weapon"))
      return notify_fail("寒氣被手上的武器給阻止了!!\n");}
    if(ob=me->query_temp("weapon"))
    {
      if((string)ob->query("skill_type") != "unarmed")
        return notify_fail("不空手怎麼使用幻指!!\n");
    }
    if(me->query("force")<500)
      return notify_fail("你的內力不夠。\n");
    if(me->query("kee")<200)
      return notify_fail("你的氣不夠。\n");
    if(!me->is_fighting(target))
    {
      tell_object(me,"雪影幻指只能在戰鬥中才能使用。\n");
      return 0;
    }
    value = me->query("functions/ice-fingers/level");
    if ( value < 10 ) value = 10;
    if ( value > 50 ) value = 50;
    value = value / 10;
    for (i=0;i<value;i++)
    {
      switch (i)
      {
        case 0:
          message_vision(HIW + "$N使出雪影幻指之「" + NOR + "" + CYN + "雪影憧憧" + HIW + "」,漫天指影、無數寒光向$n狂飆而至。\n" + NOR, me, target);
          break;
        case 1:
          message_vision(HIW + "$N使出雪影幻指之「" + CYN + "雪蒼漫漫" + HIW + "」,漫天掌勢、無數寒勁向$n狂襲而至。\n" + NOR, me, target);
          break;
        case 2:
          message_vision(HIW + "$N使出雪影幻指之「" + HIB + "大雪漫天" + HIW + "」,渾厚寒勁、無盡掌影向$n狂攻而至。\n" + NOR, me, target);
          break;
        case 3:
          message_vision(HIW + "$N使出雪影幻指之「" + HIM + "雪梅綻放" + HIW + "」,掌如梅花、凌厲寒勢向$n狂掃而至。\n" + NOR, me, target);
          break;
        case 4:
          message_vision(HIW + "$N使出雪幻奧義之「" + RED + "暴雪急襲" + HIW + "」,無窮掌影、無盡掌勢向$n狂擊而至。\n" + NOR, me, target);
          break;
      }
// 修正全數命中 by swy
      message_vision(MAG + "$n被$N的雪影幻指準確的命中要穴,$n身上己留下青紫色的指痕\n" + NOR, me, target);
      target->receive_damage("kee",hart,me);
      target->apply_condition("cold",random(15)+1);
      me->add("force",-40);
      COMBAT_D->report_status(target);
      hart = hart + (int)me->query("max_force")/100;
    }
    message_vision(HIR + "$N使出雪影幻指後!!內勁損耗過大，無法移動。\n" + NOR,me);
    me->start_busy(1);
    COMBAT_D->report_status(target, 1);

  if(me->query("functions/ice-fingers/level") < 100)
  {
    function_improved("ice-fingers",random(me->query("max_force")/15+me->query_skill("snow-martial")));
  }
  message_vision( NOR,me);
  return 1;
}
