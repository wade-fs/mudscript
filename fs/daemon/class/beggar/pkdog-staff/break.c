inherit F_FUNCTION;
inherit SSERVER;
#include <ansi.h>

int perform (object me, object target, object  weapon)
{
        object ob;
        object weaponn;
        int sklv = me->query_skill("pkdog-staff",1);
        int corr = me->query_cor(1);
        if (!target) target = offensive_target(me);
        if (!me->is_fighting() )
           return notify_fail("瘋狗嚙刃只能在戰鬥中使用！\n");
        if (sklv < 100)
           return notify_fail("你的技巧不足，叫不出瘋狗哦！\n");
        if (me->query("class")!="beggar")
           return notify_fail("不是丐幫之人是無法領會的！\n");
        if (corr < 20)
           return notify_fail("你太膽小了，連狗狗也不屑出來幫你了。\n");
        if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff")
           return notify_fail("你沒拿武器哦！\n");
        if (!target->query_temp("weapon"))
           {message_vision(HIC + "對手已經沒有武器了，快攻擊吧！\n" + NOR,me);
            me->delete_busy();return 1;}
        else
        {
            weaponn = target->query_temp("weapon");
                        if (weaponn->query("id")=="evil-mblade")
                                return notify_fail("人家辛苦得來的東東不能亂打掉！\n");

           if (random(me->query_str(1)) > random(target->query_str(1)))
              {
                weaponn->unequip();
                message_vision(HIR + "$N暗地運勁，把$n的"+weaponn->query("name")+"給震掉了\n" + NOR,me,target);
                tell_object(RED + "你的武器鬆手了，快點裝上吧！\n" + NOR,me);
               }
            else if (random(5) > 3)
               {
                 message_vision(HIB + "$N的武器被$n打掉了！\n" + NOR,target,me);
                 tell_object(target,HIY + "你的武器被敵人打掉了，快撿起來吧。\n" + NOR);
                 weaponn->move(environment(me));
                }
             else
                {
                  message_vision(HIR + "$N企圖想打掉$n的武器，可惜被發現了\n" + NOR,me,target);
                }
                  return 1;
         }

}

