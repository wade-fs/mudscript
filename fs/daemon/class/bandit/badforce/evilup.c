#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me,object target)
{
   int ski_lv;
   if (me->query("quests/evilup")!=1)
      return notify_fail("§A¦b·F¹À ?\n");
   if (me->query("bellicosity")>=4000)
      return notify_fail("¦³±þ®ð¤FÁÙ­n¹B¶Ü?\n");
   if (me->query_skill("badforce",1)<30)
      return notify_fail("§A©|¥¼·P¬V´c¤ÆÅ]¥\\ªº¨¸´cºë¸q ,¦A¦h¥[½m²ß§a\n");
   if (me->query("class") != "bandit")
      return notify_fail("§AªºÂ¾·~µLªk¨Ï¥Î´£¤É±þ®ðªºµ´©Û\n");
   if (me->query("force")<100)
      return notify_fail("·Q¦º°Ú ?¨S¤º¤OÁÙ§l ?\n");
   ski_lv=me->query_skill("badforce",1)*10;
          me->add("bellicosity",random(ski_lv)+1);
          me->add("force",-50);
          message_vision(
"[1;33m$N§Q¥Î´c¤ÆÅ]¥\\©ÒÁô§tªº¨¸´cºë¸q ,¹Á¸Õ¼W¥[¦Û¤vªº±þ·N¡C[0m\n[35mµ²ªG¤@ªÑ¶Â®ð±q$NªºÀY¤W«_¥X ,$N¥|©P±þ®ðÄËÄË¡[0m\n",me);
          return 1;

}
      
