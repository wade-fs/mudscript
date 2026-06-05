#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int exert(object me, object target)
{
        int fun,damage,i;
        object *enemy;
        if(!wizardp(me) && userp(me)) return 0;
        if(me->query_temp("using_threeforce"))
                return notify_fail("敵人正因你的氣勁而行動遲緩，快趁現在攻擊吧!!!\n");
        fun=me->query("functions/threeforce/level");
        if(!fun) fun=1;
        damage=fun*80;
        if(!me->is_fighting()) return notify_fail("戰鬥中才可以使出「疊浪三重」!!\n");
        enemy=me->query_enemy();
        target=enemy[random(sizeof(enemy))];
       if(!target) return notify_fail("找不到敵人!!\n");
        if(userp(target)) damage/=2;
        me->set_temp("using_threeforce",1);
        message_vision(HIG + "
只聽$N" + HIG + "狂喝一聲，在$N" + HIG + "與$n" + HIG + "接觸之時，體內三氣分作三重，化成滔天巨浪，剎那間
三波真氣全送入了$n" + HIG + "的體內!!!
「轟!」一聲勁氣交接的巨響，兩人同時被震退!!\n" + NOR,me,target);
        message_vision(HIR + "
可是$N" + HIR + "在退到一半的時候突然全身劇震，經脈受到了$n" + HIR + "第一重真氣的影響，
全身經脈如同被一股巨力重鎚，勁力登時喪失了許\多!!!\n" + NOR,target,me);
        target->add_temp("apply/damage",-(target->query_temp("apply/damage")/2));
        target->add_temp("apply/attack",-(target->query_temp("apply/attack")/2));
        target->add("force",-(target->query("force")/5));
        target->receive_wound("kee",damage,me);
        target->set_temp("no_power",1);
        target->apply_condition("no_power",3);
        COMBAT_D->report_status(target);
        call_out("action1",3,me,target,damage);
        return 1;
}
int action1(object me,object target,int damage)
{
        if(target)
        {
        if(target->is_fighting())
        {
        message_vision(HIB + "
就在$N" + HIB + "以為擺\拖了$n" + HIB + "的真氣攻擊時，$n" + HIB + "的第二波真氣開始發揮作用，陰渺難測的真氣
開始在$N" + HIB + "的體內亂竄，$N" + HIB + "全身經脈就如同被扭在一起，身體的靈活度登時變差了許\多!!\n" + NOR,target,me);
        target->add_temp("apply/defense",-(target->query_temp("apply/defense")/2));
        target->add_temp("apply/armor",-(target->query_temp("apply/armor")/2));
        target->add("force",-(target->query("force")/4));
        target->receive_wound("gin",damage,me);
        COMBAT_D->report_status(target);
        call_out("action2",3,me,target,damage);
        }
        else
        {
        call_out("add_fun",2,me);
        }
        }
        else
        {
        call_out("add_fun",2,me);
        }
        return 1;
}
int action2(object me,object target,int damage)
{
        if(target)
        {
        if(target->is_fighting())
        {
        message_vision(HIM + "
正當$N" + HIM + "憑藉著本身真氣將$n" + HIM + "第二重真氣引入地上時，$n" + HIM + "的第三重真氣卻已經全無預兆的
侵入到$N" + HIM + "的精神之中，$N" + HIM + "登時整個人飄飄蕩蕩，說不出的心顫魂搖，難受得要命，大腦
似若不再聽$N" + HIM + "的指揮，鬥志大減!!\n" + NOR,target,me);
        target->set_temp("apply/damage",1);
        target->set_temp("apply/attack",1);
        target->add("force",-(target->query("force")/3));
        target->receive_wound("sen",damage,me);
        COMBAT_D->report_status(target);
        call_out("add_fun",2,me);
        }
        else
        {
        call_out("add_fun",2,me);
        }
        }
        else
        {
        call_out("add_fun",2,me);
        }
        return 1;
}
int add_fun(object me)
{
        int fun;
        if(!me) return 1;
        me->delete_temp("using_threeforce");
        fun=me->query("functions/threeforce/level");
        if(!userp(me)) return 1;
        if(fun<100)
                function_improved("threeforce",random(2000));
}
