// gather.c 
#include <combat.h> 
#include <ansi.h>
inherit SSERVER; 

int kee_out(object me,object target)
{
        if(me->query("s_kee")<10)
        {
            tell_object(me,"你的靈氣修練不夠。\n");
            return 1;
        }
        if(me->query_temp("super_god")==1) 
        {
            tell_object(me,"你已經在使用【仙雲之氣】了!!!。\n");
            return 1; 
        }
        message_vision(
          HIW + "$N口中唸唸有詞!!護身靈氣浮動﹐" + HIM + "仙雲之氣" + HIW + "騰出﹗\n" + NOR,me);
        message_vision(
          HIY + "$N的全身被仙雲之氣所覆，發出奇幻般的光芒!!\n" + NOR,me,target);
				if(((int)me->query("kee")) < ((int)me->query("max_kee")))
				{
								int max_cure = me->query("max_s_kee");
								me->receive_curing("kee",max_cure*5 );
				}
				if(((int)me->query("gin")) < ((int)me->query("max_gin")))
				{
								int max_cure = me->query("max_s_kee");
								me->receive_curing("gin",max_cure*5 );
				}
				if(((int)me->query("sen")) < ((int)me->query("max_sen")))
				{
								int max_cure = me->query("max_s_kee");
								me->receive_curing("sen",max_cure*5 );
				}

				if(me->query("force") < me->query("max_force"))
				{
								int max_cure = me->query("max_s_kee");

								me->add("force",max_cure);
				}

        me->set_temp("super_god",1);
        me->apply_condition("god_out",me->query("s_kee")/10);
        me->set("s_kee",0);
        return 1;
}
