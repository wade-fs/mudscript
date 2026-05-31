//°ׁ·׃₪Fswy×÷ֵ]₪Mֵ]ְs³Z₪ט¦¡§ף§ן₪F³¡¥קcode
//­Yswy§ף°Ê¨ל³o®ֹ¡A¦A¥H§A×÷·ַ«h¨׃­׳¥¿§a  by Neverend
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
  if( !target) return notify_fail("¨S¦³¥פ¦ף×÷¹ן₪ג\n");
	if(!me->is_fighting(target))
	return notify_fail("₪C¬P«Ê¥Þ¥u¯א¦b¾װ°«₪₪¨ֿ¥־¡C\n");
	if(!(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!= "stabber" )
	return notify_fail("­n¦³¾A¦X×÷×Z¾¹₪~¯א¥־₪C¬P«Ê¥Þ¡C\n");
	if(me->query("force") < 100)
	return notify_fail("§A×÷₪÷₪O₪£°ק¡C\n");
	if( me->query("family/family_name") != "¾§×ש")
	return notify_fail("₪£¬O¾§¥ֽ¡A₪£µ¹§A¥־«¨¡I¡I^_^\n");
	if( target->is_busy())
	return notify_fail("¼ִ₪H²{¦b₪£¯א°Ê,§ײ§נְ»§a!!!!\n");
	me->add("force",-100);
        message_vision(HIG "$N¨ֿ¥X¦ז¶³¬y₪פµ§×k₪₪×÷¡u₪C¬P«Ê¥Þ¡v©¹$n¨­₪W×÷¥Þ¹D³sֲI¡T\n" NOR,me,target);

      message_vision("\n
 [34m    .   .[0m....
 [34m   ......[0m......[36m¢z¢i¢iשששששששששששששששששששששששששששששששששששששששששששששששששששש¢×[0m¢@
 [34m    .....[0m......[36m¢x[0;1;32m¢[1mi[1mש[1mר[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1mש[1mר[1m¢[1mx[1m¢[1m¡[0m
[0;1m [1;34m [1m [1m [1m [1m [1m [1m.[1m.[1m.[0m......[36m¢|¢i¢iשששששששששששששששששששששששששששששששששששששששששששששששששששש¢¨[0m¡‏ 
 [34m        .[0m....                                                            

      " NOR,me,target);


	for( i = 0; i < sizeof(all); i++ ) 
	{
	if(environment(me)!=environment(all[i])) continue;  
	  if(random(100) < 80) 
	  {
          message_vision(HIW"\n("HIC"µ²×G$n³Q$NֲI₪₪¡A¥Þ¹D³Q«Ê¡I"HIW")\n" NOR,me,target);
     //      all[i]->start_busy(random(3)+1);
      all[i]->start_busy(random(2)+2);
	  }else{
      message_vision(HIW"\n("HIC"µ²×G³Q$nֳׁ¯}¡M¨S¦³©R₪₪¡C"HIW")\n" NOR,me,target);
	  }
	}
	if(fun<100 && me)
	function_improved("movedown",random(500));
	me->start_busy(1);
	return 1;
}

