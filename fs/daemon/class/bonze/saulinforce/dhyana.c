// 05/15/2010 by blazakira
#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me,object target)
{
   int ski_lv;
   if (me->query("bellicosity")<340) //因為內功最多學到lv231 所以 設為下限
      return notify_fail("你心中淡定，波瀾不驚。\n");
   if (!me->query_skill("saulinforce",1))
      return notify_fail("hmm，似乎你哪裡搞錯了！\n");
   if (me->query("class") != "bonze")
      return notify_fail("你的職業體會不到佛法。\n");
   if (me->query("force")<100)
      return notify_fail("內力不足，容易引來心魔！\n");
   if (me->query("max_s_kee")<10)
      return notify_fail("你尚未初見佛的真理。\n");
   ski_lv=me->query_skill("saulinforce",1)*10;
          me->add("bellicosity",-1*(random(ski_lv)+100)); //避免等級低的時候感覺像雞肋 所以給予基礎值
          me->add("force",-50); //支付內力作為普通限制
          me->add("max_s_kee",-1); //消耗佛法的最大值作為消除殺氣的代價
          message_vision(HIY + "$N聽聞佛法而心有覺悟，從而消除自己的業障。\n" + NOR,me);
          return 1;
}
