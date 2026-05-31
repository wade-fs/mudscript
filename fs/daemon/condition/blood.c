#include <ansi.h>

int update_condition(object me, int duration)
{
     if(duration==0) return 0;
    if (me->query("max_force") < 400)
    { //force more high have differnce
       me->receive_wound("kee",55-me->query_skill("force",1)/20);
       me->receive_wound("sen",25-me->query_skill("spell",1)/20);
       me->receive_wound("gin",30-me->query_skill("magic",1)/20);
       me->start_busy(3);
       me->apply_condition("blood",duration-1);
       tell_object(me,HIM "你中了黑血神針之毒﹐內力微薄的你感到全身的神經都麻痺了\n" NOR);
       message("vision",HIM+me->name()+"動作遲緩，看來是中了黑血神針之毒\n" NOR,environment(me),me);
       if( duration < 1 ) return 0;
	return 1;
    }
    if (me->query("max_force") < 1000)
    { //force more high have differnce
       me->receive_wound("kee",50-me->query_skill("force",1)/20);
       me->receive_wound("sen",20-me->query_skill("spell",1)/20);
       me->receive_wound("gin",25-me->query_skill("magic",1)/20);
       me->start_busy(2);
       me->apply_condition("blood",duration-1);
       tell_object(me,HIM "靠內力壓制一部份黑血神針毒性，但仍感到毒性的強烈\n" NOR);
       message("vision",HIR+me->name()+"動作遲緩，看來是中了黑血神針之毒\n" NOR,environment(me),me);
       if( duration < 1 ) return 0;
	return 1;
    }
    if (me->query("max_force") < 2000)
    { //force more high have differnce
       me->receive_wound("kee",45-me->query_skill("force",1)/20);
       me->receive_wound("sen",20-me->query_skill("spell",1)/20);
       me->receive_wound("gin",25-me->query_skill("magic",1)/20);
       me->start_busy(2);
       me->apply_condition("blood",duration-1);
       tell_object(me,HIY "你靠內力壓制部分的神針毒性，但毒性仍侵蝕著你的身體\n" NOR);
       message("vision",HIM+me->name()+"動作遲緩，看來是中了黑血神針之毒\n" NOR,environment(me),me);
       if( duration < 1 ) return 0;
	return 1;
    }
    if (me->query("max_force") < 5000)
    { //force more high have differnce
       me->receive_wound("kee",40-me->query_skill("force",1)/20);
       me->receive_wound("sen",20-me->query_skill("spell",1)/20);
       me->receive_wound("gin",25-me->query_skill("magic",1)/20);
       me->start_busy(1);         //force is much so busy 1
       me->apply_condition("blood",duration-1);
       tell_object(me,HIG "你靠充沛的內力壓制黑血神針之毒﹐但身體仍受到神針的傷害\n" NOR);
       message("vision",HIM+me->name()+"動作遲緩，看來是中了黑血神針之毒\n" NOR,environment(me),me);
       if( duration < 1 ) return 0;
	return 1;
    }
//mean force point more than 5000
      me->receive_wound("kee",35-me->query_skill("force",1)/20);
      me->receive_wound("sen",15-me->query_skill("spell",1)/20);
      me->receive_wound("gin",20-me->query_skill("magic",1)/20);
      me->start_busy(1);
      me->apply_condition("blood",duration-1);
      tell_object(me,HIB"你以驚人的內力壓制神針之毒，但仍受到毒性的牽制\n" NOR);
      message("vision",HIM+me->name()+"動作遲緩，看來是中了黑血神針之毒\n" NOR,environment(me),me);
      if( duration < 1 ) return 0;
	return 1;
}

