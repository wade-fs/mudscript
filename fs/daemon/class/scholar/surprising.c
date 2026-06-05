//天皇驚天皇氣.....一氣鎮山河
#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
int fun;
int perform(object me, object target)
{
        string *ATTACK_MSG=({
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIY + "一氣鎮山河～之～驚天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIR + "一氣鎮山河～之～破天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIY + "一氣鎮山河～之～震天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIG + "一氣鎮山河～之～開天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIG + "一氣鎮山河～之～瀰天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIR + "一氣鎮山河～之～焚天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIW + "一氣鎮山河～之～分天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIC + "一氣鎮山河～之～落天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIM + "一氣鎮山河～之～敝天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIC + "一氣鎮山河～之～護天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR,
WHT + "              $N翩然而立，瞬間風捲殘雲，隨即而出的乃是《驚天皇氣》中的一式
                                  "BLINK+HIB + "一氣鎮山河～之～敬天真氣" + NOR + "" + WHT + "
      只見$N由百匯升出裊裊金煙，隨即四周方圓百里漸漸凝聚一道淡金色光芒，若隱逤現的閃爍著。
      接著$n身上即感到一股莫名的、強大的、不可摧的強撼壓力，隴照著$n如影隨形!!\n" + NOR
        });
        int action,range,sur,k;
        int force_cost;
        object weapon;
        weapon= me->query_temp("weapon");
        fun=me->query("functions/surprising/level");
        sur=(int)(me->query_skill("surprise-ten",1));
        if(fun<=35) k=2;
        if(fun>=36&&fun<=89) k=5;
        if(fun>=90) k=10;
          range = (me->query_skill("surprise-ten",1)+me->query_function("surprising"))/10;
        if( range > sizeof(ATTACK_MSG) )
          range = sizeof(ATTACK_MSG);
          action = random(range);
          //six = (me->query_skill("surprise-ten",1))/10;
          force_cost = 500;
        if( sur<=90 )
          return notify_fail("你所學的驚天十式未達爐火存菁之境界。\n");
        if( !me->is_fighting(target) )
          return notify_fail("你只能在戰鬥中使出「一氣鎮山河」。\n");
        if( target == me )
          return notify_fail("不能對付自己呀!!\n");
        if( me->query("force") < 3000 )
          return notify_fail("你的內力不夠。\n");
        if(weapon&&weapon->query("skill_type")!="unarmed")
          return notify_fail("'雞絲'不對喔。\n");
        if( !target )
          target = offensive_target(me);
        if(target->is_busy())
          return notify_fail("一氣鎮山河無法用在忙亂中的人\n");
/*暫時不限門派
      if(me->query("family/family_name")!="段家")
      return notify_fail("不是段家不能用。\n");
*/
          message_vision("\n"+ATTACK_MSG[action]+"\n",me,target);
if(95>random(100))
        {
          message_vision(HIW + "$n給$N強大的氣勁所鎮鎖住了，臉上露出極痛苦的神情，無奈動彈不得!!!\n" + NOR,me,target);
          target->start_busy(k);
            if ( (random(10) >9 ) && me->query("force_factor",1) > 9)
            {
          message_vision(HIR + "$N見天賜良機，運足真氣、瀟灑飄逸的朝$n快攻而去!!!\n" + NOR,me,target);
          me->set_temp("super",1);
            }
          if(me->query_function("surprising")<100)
            {
function_improved("surprising",random(500));
            }
        }
        else
        {
          message_vision("可惜被$n閃過了..\n",me);
      if(me->query_function("surprising")<100)
            {
        function_improved("surprising",random(800));
            }
        }
        me->add("force",-force_cost);
        me->start_busy(1);
        return 1;
}
