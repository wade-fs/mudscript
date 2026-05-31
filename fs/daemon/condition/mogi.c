// 魔域npc 使用之魔界奇毒
// 此種condition 十分可怕，其它skill禁止亂加除非我同意
// By Roger
//排版 by blazakira 2011/9/4

#include <ansi.h>

int update_condition(object me, int duration)
{
  if( duration >= 30 )
  {
    tell_object(me,HIM"\n入滅之毒猛然發作，你剎時覺得天旋地轉口中黑血狂噴！\n"NOR);
    message("vision",me->name() + "毒傷猛然發作，口吐黑血痛苦地倒在地上哀號著！\n"NOR,
      environment(me), me);
    me->receive_wound("kee",1500);
    me->receive_damage("kee",1300);
    COMBAT_D->report_status(me, 1);
  }
  else if( duration >= 1 )
  {
    tell_object(me,HIM"\n入滅之毒隨著你的心跳越發劇痛，如似無數毒虫在你腦中噬著你的腦漿。\n"NOR);
    message("vision",me->name() + "毒傷驟發，突然吐出了不少黑黃血水，臉色比起死棺之人更加慘白了！\n"NOR,
      environment(me), me);
    me->receive_wound("kee",800);
    me->receive_damage("kee",400);
    COMBAT_D->report_status(me, 1);
  }
  if( duration < 1 )
    return 0;
  return 1;
}
