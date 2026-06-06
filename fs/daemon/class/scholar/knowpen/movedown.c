//挶茪Fswy]M]sZ閬；code
//Yswy囧o氶AAHAヱh茩蚰a  by Neverend
#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
int fun;
int k;
int perform(object me,object target)
{
	object weapon;
	object *all = me->query_enemy();
	int i,j, fun=me->query("functions/movedown/level");
	if( fun < 20) k=1;
	if( fun>=20 && fun < 70) k=random(2)+1;
	if( fun >= 70) k=random(3)+1;
	if( !target ) target = offensive_target(me);
  if( !target) return notify_fail("S顗犒\n");
	if(!me->is_fighting(target))
	return notify_fail("CP吤犍ub埶洏峞C\n");
	if(!(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!= "stabber" )
	return notify_fail("nAXZ~峇CP吤煄C\n");
	if(me->query("force") < 100)
	return notify_fail("AOC\n");
	if( me->query("family/family_name") != "")
	return notify_fail("O矷AA峆II^_^\n");
	if( target->is_busy())
	return notify_fail("臚H{b,盓a!!!!\n");
	me->add("force",-100);
        message_vision(HIG + "$N洏X瘨造kuCP吤煄v$nW瑐DsIT\n" + NOR,me,target);

      message_vision("\n
     .   .....
    ............zii@
     ...........xi                                                     x
       .........|ii 
         .....                                                            

      " + NOR,me,target);


	for( i = 0; i < sizeof(all); i++ ) 
	{
	if(environment(me)!=environment(all[i])) continue;  
	  if(random(100) < 80) 
	  {
          message_vision(HIW + "\n(" + HIC + "G$nQ$NIA瑐DQ吽I" + HIW + ")\n" + NOR,me,target);
     //      all[i]->start_busy(random(3)+1);
      all[i]->start_busy(random(2)+2);
	  }else{
      message_vision(HIW + "\n(" + HIC + "GQ$n戙}MSRC" + HIW + ")\n" + NOR,me,target);
	  }
	}
	if(fun<100 && me)
	function_improved("movedown",random(500));
	me->start_busy(1);
	return 1;
}

