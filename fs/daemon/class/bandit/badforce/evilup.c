#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me,object target)
{
   int ski_lv;
   if (me->query("quests/evilup")!=1)
      return notify_fail("你在幹嘛 ?\n");
   if (me->query("bellicosity")>=4000)
      return notify_fail("有殺氣了還要運嗎?\n");
   if (me->query_skill("badforce",1)<30)
      return notify_fail("你尚未感染惡化魔功\的邪惡精義 ,再多加練習吧\n");
   if (me->query("class") != "bandit")
      return notify_fail("你的職業無法使用提升殺氣的絕招\n");
   if (me->query("force")<100)
      return notify_fail("想死啊 ?沒內力還吸 ?\n");
   ski_lv=me->query_skill("badforce",1)*10;
          me->add("bellicosity",random(ski_lv)+1);
          me->add("force",-50);
          message_vision(
"$N利用惡化魔功\所隱含的邪惡精義 ,嘗試增加自己的殺意。\n結果一股黑氣從$N的頭上冒出 ,$N四周殺氣騰騰﹏n",me);
          return 1;

}
      
