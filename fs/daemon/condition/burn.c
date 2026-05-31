// 增加def_fire判斷 by obs
// burn.c Desigh by Chan
//有問題請post
//排版 by blazakira 2011/10/9

#include <combat.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me,int duration)
{
  if((me->query_temp("def_fire")))
  {
    tell_object(me,HIW"你身上的"HIR"『焰氣訣』"HIW"效力化解了灼傷的傷勢。\n"NOR);
    message("vision",HIW+me->name()+"身上的"HIR"『焰氣訣』"HIW"效力頓時化解了身上的灼傷。\n"NOR,environment(me),me);
    me->clear_condition("burn");
    duration=1;
  }
  else
  {
    if( !living(me) )
    {
      message("vision",HIR+me->name()+"身上的灼傷尚未痊癒，但是覺得似乎油盡燈枯\了!!\n"NOR,environment(me),me);
    }
    else if( duration > 10)
    {
      tell_object(me,HIR"你的灼傷似乎很嚴重，傷口焦黑。\n"NOR);
      message("vision",HIR+me->name()+"身上發熱巨痛，並有嚴重脫水的現象。\n"NOR,environment(me),me);
      me->receive_wound("kee",300,me);
      me->receive_damage("kee",300,me);
      if( (int)me->query("water")>=50 ) me->add("water",-50);
      else me->set("water",0);
    }
    else if( duration > 5 )
    {
      tell_object(me,HIR"你覺得身上的灼傷開始褪皮了，傷口紅腫疼痛。\n"NOR);
      message("vision",HIR+me->name()+"傷口仍發熱腫痛，但脫水症狀有所減輕。\n"NOR,environment(me),me);
      me->receive_wound("kee",200,me);
      me->receive_damage("kee",200,me);
      if( (int)me->query("water")>=30 ) me->add("water",-30);
      else me->set("water",0);
    }
    else if( duration > 1)
    {
      tell_object(me,HIW"你身上的灼傷開始結疤了，也感覺不到痛苦了。\n"NOR);
      message("vision",HIR+me->name()+"的身上有一道新疤，好像受到不輕的傷害。\n"NOR,environment(me),me);
      me->receive_wound("kee",100,me);
      me->receive_damage("kee",100,me);
      me->add("kee",-2);
      if( (int)me->query("water")>=10 ) me->add("water",-10);
      else me->set("water",0);
    }
  }
  me->apply_condition("burn",duration - 1);
  COMBAT_D->report_status(me);
  if( duration < 2 ) return 0;
  return 1;
}
