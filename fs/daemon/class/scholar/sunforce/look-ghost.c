#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;
int perform(object me, object target)
{
        object *enemy,ob;
        int damage,i,fun,accept,e_force,e_f_c,flag;
        flag=0;
        enemy=me->query_enemy();
        i=sizeof(enemy);
          if(i > 4)
         {
         i=4;
       }
        fun=me->query("functions/north-force/level");
        if(me->query_skill("sunforce",1)< 100)
           return notify_fail("你的一陽心法根基不夠﹐"+
                              "沒辦法使出北冥神功\。\n");
        if(!me->query("marks/north-force"))
                return 0;
        if(me->query("family/family_name") != "段家")
                return notify_fail("非段家弟子不能用！！\n");
        if(!me->is_fighting(target))
                return notify_fail("北冥神功\只能在戰鬥中使用。\n");
        if(me->query("kee") < 1000)
                return notify_fail("你的氣不夠。\n");

        message_vision(HIG + "
                $N運起全身真勁，使得全身的骨骼不斷的霹啪作響，
                大喝一聲:"+BLINK+HIC+"「北冥神功\」" + NOR+HIG + "，右手開始不斷的在身前繞
                圈，越繞越快，漸漸地形成了一個漩渦力場，四週的
                人只覺得一股極大的吸力從力場中心發出，身體不由
                自主的朝力場投去。\n" + NOR,me);
        while(i--)
        {
               if(fun <= 20 && fun >=0)
                {
                        if(15 > random(100))
                        {
                                message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的一成!!!\n" + NOR,enemy[i],me);
                        flag=flag+1;
                        e_force=enemy[i]->query("force");
                        e_force=e_force*1/10;
                        enemy[i]->add("force",-(e_force));
                        me->add("force",e_force);
                                if(2 > random(100))
                                {
                                e_f_c=enemy[i]->query("force_factor");
                                e_f_c=e_f_c*2/10;
                                enemy[i]->add("force_factor",-(e_f_c));
                                }
                        COMBAT_D->report_status(enemy[i]);
                        }
                        else
                        {
               message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
                        }
                }
               if(fun <= 40 && fun >20)
                {
                        if(30 > random(100))
                        {
                                message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的兩成!!!\n" + NOR,enemy[i],me);
                        flag=flag+1;
                        e_force=enemy[i]->query("force");
                        e_force=e_force*2/10;
                        enemy[i]->add("force",-(e_force));
                        me->add("force",e_force);
                                if(4 > random(100))
                                {
                                e_f_c=enemy[i]->query("force_factor");
                                e_f_c=e_f_c*3/10;
                                enemy[i]->add("force_factor",-(e_f_c));
                                }
                        COMBAT_D->report_status(enemy[i]);
                        }
                        else
                        {
               message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
                        }
                }
               if(fun <= 60 && fun >40)
                {
                        if(45 > random(100))
                        {
                                message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的三成!!!\n" + NOR,enemy[i],me);
                        flag=flag+1;
                        e_force=enemy[i]->query("force");
                        e_force=e_force*3/10;
                        enemy[i]->add("force",-(e_force));
                        me->add("force",e_force);
                                if(6 > random(100))
                                {
                                e_f_c=enemy[i]->query("force_factor");
                                e_f_c=e_f_c*4/10;
                                enemy[i]->add("force_factor",-(e_f_c));
                                }
                        COMBAT_D->report_status(enemy[i]);
                        }
                        else
                        {
               message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
                        }
                }
               if(fun <= 80 && fun >60)
                {
                        if(60 > random(100))
                        {
                                message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的四成!!!\n" + NOR,enemy[i],me);
                        flag=flag+1;
                        e_force=enemy[i]->query("force");
                        e_force=e_force*4/10;
                        enemy[i]->add("force",-(e_force));
                        me->add("force",e_force);
                                if(8 > random(100))
                                {
                                e_f_c=enemy[i]->query("force_factor");
                                e_f_c=e_f_c*5/10;
                                enemy[i]->add("force_factor",-(e_f_c));
                                }
                        COMBAT_D->report_status(enemy[i]);
                        }
                        else
                        {
               message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
                        }
                }
                if(fun > 80)
                {
                        if(75 > random(100))
                        {
                                message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的五成!!!\n" + NOR,enemy[i],me);
                        flag=flag+1;
                        e_force=enemy[i]->query("force");
                        e_force=e_force*5/10;
                        enemy[i]->add("force",-(e_force));
                        me->add("force",e_force);
                                if(10 > random(100))
                                {
                                e_f_c=enemy[i]->query("force_factor");
                                e_f_c=e_f_c*6/10;
                                enemy[i]->add("force_factor",-(e_f_c));
                                }
                        COMBAT_D->report_status(enemy[i]);
                        }
                        else
                        {
               message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
                        }
                }
        }
        me->add("kee",-200);
        if(!flag) flag=1;
if(fun<100) { function_improved("north-force",random(300)*flag); }
        return 1;
}

