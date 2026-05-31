// 增加def_cold判斷 by obs
// cold.c Desigh by Chan
//排版 by blazakira 2011/10/9

#include <combat.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if((me->query_temp("def_cold")))
  {
    tell_object(me,HIW"你身上的"HIC"『凍氣訣』"HIW"效力化解了凍傷的傷勢。\n"NOR);
    message("vision",HIW+me->name()+"身上的"HIR"『凍氣訣』"HIW"效力頓時化解了身上的凍傷。\n"NOR,environment(me),me);
    me->clear_condition("cold");
    duration=1;
  }
  else if( !living(me) )
  {
    message("vision",HIC+me->name()+"身上所受凍傷尚未痊癒，使寒氣在身體之中無法驅出了!!\n"NOR,environment(me),me);
  }
  else if( duration > 10 )
  {
    tell_object(me,HIW"你受的凍傷十分嚴重，使傳導神經受阻讓四肢沒有任何知覺。\n"NOR);
    message("vision",CYN+me->name()+"全身受到寒氣所侵，寒斑點點，使之丹田內的內息無法運轉如常。\n"NOR,environment(me),me);
    me->receive_wound("kee",300,me);
    me->receive_damage("kee",300,me);
    if(me->is_fighting()) me->start_busy(1);
    if( (int)me->query("food")>=50 ) me->add("food", -50);
    else me->set("food", 0);
  }
  else if( duration > 5 )
  {
    tell_object(me,HIW"你默運內功\將寒氣慢慢逼出，感覺身上的凍傷減輕不少，也慢慢有血色了。\n"NOR);
    message("vision",CYN+me->name()+"雖然全身四肢仍無知覺，但內息己慢慢能運轉如常。\n"NOR,environment(me),me);
    if(me->is_fighting()) me->start_busy(1);
    me->receive_wound("kee",200,me);
    me->receive_damage("kee",200,me);
    if( (int)me->query("food")>=30 ) me->add("food", -30);
    else me->set("food", 0);
  }
  else if( duration > 1 )
  {
    tell_object(me,HIW"你運起內功\將你身上的寒氣完全消除了，內息恢復成往常一樣了。\n"NOR);
    message("vision",CYN+me->name()+"雖然寒氣消除了，但身上還留下寒氣所侵的痕跡。\n"NOR,environment(me),me);
    me->receive_wound("kee",100,me);
    me->receive_damage("kee",100,me);
    if( (int)me->query("food")>=10 ) me->add("food", -10);
    else me->set("food", 0);
  }
  me->apply_condition("cold", duration - 1);
  COMBAT_D->report_status(me);
  if( duration < 2 ) return 0;
  return 1;
}
