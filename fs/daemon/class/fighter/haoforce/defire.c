// defire.c
// 消除灼傷及寒傷的condition by Chan Design
// 瀧山派專用
#include <ansi.h>
int exert(object me)
{
  int need;
  if(me->query_skill("force")/2+me->query_skill("haoforce", 1)<120)
   return notify_fail(HIW"你的浩日內勁練得不夠精深，無法調理身上傷勢。\n"NOR);
  if( me->is_fighting() )
    return notify_fail(HIW"戰鬥中沒時間調理傷勢。\n"NOR);
  if(me->query("family/family_name")!="瀧山派")
    return notify_fail(HIW"只有瀧山弟子才能調理身上的傷勢\n"NOR);
  if( (string)me->query_skill_mapped("force") != "haoforce")
    return notify_fail(HIW"你沒有使用浩日心法，要怎麼調理傷勢呢!!!\n"NOR);
  if((int)me->query("kee")<200 || (int)me->query("sen")<90 )
    return notify_fail("你的氣或注意力不夠﹐無法全心調理傷勢。\n");
  if((need=me->query_condition("burn")*100)!=0)
  {
     if((int)me->query("force")< need)
      {
       message_vision(
       HIW"$N席地而坐,強行運起浩日心法調理體內炙熱氣勁!!由於內力不足,造成熱勁反撲,反而加重身上的灼傷\n"NOR, me);
       me->add("force",-need);
       me->apply_condition("burn", 15);
       me->add("kee",-200);
       return notify_fail(HIR"你感覺喉頭一甜!!!吐了一口鮮血出來!!。\n"NOR);
      }
     message_vision(
     HIW"$N席地而坐,運起浩日心法一股炙熱內勁從丹田運至全身,將所受的灼傷完全逼出體外了。\n"NOR, me);
     me->add("force", -need);
     me->apply_condition("burn", 0);
  }
  else if((need=me->query_condition("cold")*130)!=0)
  {
     if((int)me->query("force")< need)
      {
       message_vision(
       HIW"$N席地而坐,強行運起浩日心法調理在體內的雪蒼寒勁!!由於內力不足,造成寒傷加速惡化,反而加重身上的寒傷\n"NOR, me);
       me->add("force",-need/2);
       me->apply_condition("cold", 15);
       me->add("kee",-200);
       return notify_fail(HIR"你感覺喉頭一甜!!!吐了一口鮮血出來!!。\n"NOR);
      }
     message_vision(
     HIW"$N席地而坐,運起浩日心法一股炙熱內勁從丹田運至全身,雙手散出絲絲寒氣,你將大部份的寒勁逼出體外了。\n"NOR, me);
     me->add("force", -need/2);
     me->apply_condition("cold",0);
  }
 else
    return notify_fail("你並無受寒傷或灼傷,所以不用調理傷勢!!!。\n");
    return 1;
}
