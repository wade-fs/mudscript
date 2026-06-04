//ѷӤFswy]M]sZ覡Fcode
//YswyʨoɡAAHAǫhӭץa  by Neverend
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
  if( !target) return notify_fail("S󪺹\n");
	if(!me->is_fighting(target))
	return notify_fail("CPʥޥub԰ϥΡC\n");
	if(!(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!= "stabber" )
	return notify_fail("nAXZ~ΤCPʥޡC\n");
	if(me->query("force") < 100)
	return notify_fail("AOC\n");
	if( me->query("family/family_name") != "")
	return notify_fail("O͡AAΫII^_^\n");
	if( target->is_busy())
	return notify_fail("ĤH{b,֧a!!!!\n");
	me->add("force",-100);
        message_vision(HIG + "$NϥX涳ykuCPʥޡv$nW޹DsIT\n" + NOR,me,target);

      message_vision("\n
 [34m    .   .[0m....
 [34m   ......[0m......[36mzii[0m@
 [34m    .....[0m......[36mx[0;1;32m[1mi[1m[1m[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m[1m[1m[1mx[1m[1m[0m
[0;1m [1;34m [1m [1m [1m [1m [1m [1m.[1m.[1m.[0m......[36m|ii[0m 
 [34m        .[0m....                                                            

      " + NOR,me,target);


	for( i = 0; i < sizeof(all); i++ ) 
	{
	if(environment(me)!=environment(all[i])) continue;  
	  if(random(100) < 80) 
	  {
          message_vision(HIW + "\n(" + HIC + "G$nQ$NIA޹DQʡI" + HIW + ")\n" + NOR,me,target);
     //      all[i]->start_busy(random(3)+1);
      all[i]->start_busy(random(2)+2);
	  }else{
      message_vision(HIW + "\n(" + HIC + "GQ$nѯ}MSRC" + HIW + ")\n" + NOR,me,target);
	  }
	}
	if(fun<100 && me)
	function_improved("movedown",random(500));
	me->start_busy(1);
	return 1;
}

