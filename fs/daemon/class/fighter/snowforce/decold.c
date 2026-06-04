// defire.c
// 消除灼傷及寒傷的condition by Chan Design
// 雪蒼派專用
#include <ansi.h>
int exert(object me)
{
  int need;
if(me->query_skill("force")/2+me->query_skill("snowforce", 1) < 120)
   return notify_fail(HIW + "你的雪蒼寒勁練得不夠精深，無法調理身上傷勢。\n" + NOR);
  if( me->is_fighting() )
    return notify_fail(HIW + "戰鬥中沒時間調理傷勢。\n" + NOR);
  if(me->query("family/family_name")!="雪蒼派")
    return notify_fail(HIW + "只有雪蒼弟子才能調理身上的傷勢\n" + NOR);
  if( (string)me->query_skill_mapped("force") != "snowforce")
    return notify_fail(HIW + "你沒有使用雪蒼內功\，要怎麼調理傷勢呢!!!\n" + NOR);
  if((int)me->query("kee")<200 || (int)me->query("sen")<90 )
    return notify_fail("你的氣或注意力不夠﹐無法全心調理傷勢。\n");
  if((need=me->query_condition("cold")*100)!=0)
  {
     if((int)me->query("force")< need)
      {
       message_vision(
       HIW + "$N席地而坐,強行運起雪蒼心法調理體內亂走寒勁!!但由於內力不足,造成寒勁反撲,反而加重身上的寒傷\n" + NOR, me);
       me->add("force",-need);
       me->apply_condition("cold", 15);
       me->add("kee",-200);
       return notify_fail(HIR + "你感覺丹田被寒勁入侵,有如刀割一般!!。\n" + NOR);
      }
     message_vision(
     HIW + "$N席地而坐,運起雪蒼心法一股至寒氣勁從丹田運至全身,將所受的寒傷完全消除了。\n" + NOR, me);
     me->add("force", -need);
     me->apply_condition("cold", 0);
  }
  else if((need=me->query_condition("burn")*130)!=0)
  {
     if((int)me->query("force")< need)
      {
       message_vision(
       HIW + "$N席地而坐,強行運起雪蒼心法調理在體內的浩日氣勁!!由於內力不足,造成熱勁反撲,反而加重身上的灼傷\n" + NOR, me);
       me->add("force",-need/2);
       me->apply_condition("burn", 15);
       me->add("kee",-200);
       return notify_fail(HIR + "你感覺喉頭一甜!!!吐了一口鮮血出來!!。\n" + NOR);
      }
     message_vision(
     HIW + "$N席地而坐,運起雪蒼心法一股炙熱內勁從丹田運至全身,頭上散出絲絲熱氣,你將大部份的熱勁逼出體外了。\n" + NOR, me);
     me->add("force", -need/2);
     me->apply_condition("burn",0);
  }
 else
    return notify_fail("你並無受寒傷或灼傷,所以不用調理傷勢!!!。\n");
    return 1;
}
