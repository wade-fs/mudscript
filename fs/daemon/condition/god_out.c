// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{

			  int max_cure = me->query("max_s_kee")
				   + me->query("s_kee");
				if(duration==0)
				{
								me->delete_temp("super_god");
								return 0;
				}
				if(((int)me->query("kee")) < ((int)me->query("max_kee")))
				{
								me->receive_heal("kee",max_cure*2 );
								me->receive_curing("kee",max_cure );
				}
				if(((int)me->query("gin")) < ((int)me->query("max_gin")))
				{
					
								me->receive_heal("gin",max_cure );

								me->receive_curing("gin",max_cure );
				}
				if(((int)me->query("sen")) < ((int)me->query("max_sen")))
				{
								me->receive_heal("sen",max_cure );

								me->receive_curing("sen",max_cure );
				}

				if(me->query("force") < me->query("max_force"))
				{

								me->add("force",max_cure);
				}

				me->apply_condition("god_out",duration-1);
				message_vision(
												HIM "$N的仙雲之氣發出柔和的光茫，$N感覺身上的傷痕恢復且精力充沛。\n" NOR,me);
				if( duration < 1 ) return 0;
				return 1;
}
