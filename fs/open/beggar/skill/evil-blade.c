// evil-blade.c by oda

#include <ansi.h>

inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
	int skill, level, bellpower, force, damage, i;
//減少不必要麻煩,拿掉wea 2
          object wea1, *enemy;
	skill = query_function("evil-blade");
	level = skill/10+1;
	bellpower = me->query("bellicosity")/20;
    if(bellpower > 300) //by chan fix 
      bellpower=300;
	force = me->query("force");
	enemy = me->query_enemy();
	i = sizeof(enemy);
	wea1 = me->query_temp("weapon");
//      wea2 = me->query_temp("secondary_weapon");

      if( me->query_skill_mapped("force")!="badforce" || me->query_skill_mapped("unarmed")!="badstrike" || (wea1 && wea1->query("skill_type")!="unarmed") )
		return notify_fail("只有在空手使用惡霸掌及惡化魔功\時才能發出天魔刀。\n");
	if( me->query_skill("badstrike",1)<20 )
		return notify_fail("你的惡霸掌技巧不足。\n");
	if( me->query_skill("badforce",1)<20 )
		return notify_fail("你的內功\不夠深厚，無法聚氣成刀。\n");
	if( force<90 ) return notify_fail("你的內力不足以聚起天魔刀芒。\n");
    if( !me->is_fighting(target) )
		return notify_fail("天魔刀只能在戰鬥中使用。\n");

	if( !target ) target = offensive_target(me);
	if( level>3 ) level=3;
	if( level==3 && me->query_skill("ghost-steps",1)<50 ) level=2;
	switch( random(level) ) {
		case 0:
		message_vision(HIW"\t$N將內勁聚於雙掌，祭起十成功\力之『"+HIR"天魔刀"+HIW"』！\n\n\t只見$N掌中逐漸形成兩個耀眼刀環，倏地向$n疾射而去！\n\n"NOR,me,target);
		me->add("force", -50);
        if ( random(9)<=3 ) {
			message_vision(HIM"只見$N刀勢雖猛，但似乎欠缺準頭，連$n的衣服都沒沾到。\n"NOR,me,target);
        me->start_busy(1);
			return 1;
		}
		damage = me->query_skill("badstrike",1)/2+me->query_skill("badforce",1)/2+skill*3+bellpower;
		target->receive_wound("kee", damage);
		message_vision(HIC"$n閃避不及，被$N的天魔刀芒貫體而過，當場血流如注！\n"NOR,me,target);
		COMBAT_D->report_status(target);
		me->start_busy(1);
		break;
		case 1:
		message_vision(HIW"\t$N雙掌合十，高舉過頂，順勢運起『"+HIR"大天魔刀"+HIW"』\n\n\t只見$N雙掌的天魔刀勁合而為一，形成一個巨大刀環。\n\n\t突然間$N真氣一提，舉起大天魔刀向$n直劈而下！\n\n"NOR,me,target);
		me->add("force", -65);
        if( random(9)<=2 ) {
			message_vision(HIM"只見$N刀勢雖猛，但似乎欠缺準頭，連$n的衣服都沒沾到。\n"NOR,me,target);
       me->start_busy(1);
			return 1;
		}
		damage = me->query_skill("badstrike",1)*2/3+me->query_skill("badforce",1)*2/3+skill*3/2+bellpower;
		target->receive_wound("kee", damage);
		message_vision(HIC"$n閃避不及，被$N的巨大刀環當場擊中，口中鮮血狂噴而出！\n"NOR,me,target);
		COMBAT_D->report_status(target);
		me->start_busy(1);
		break;
		case 2:
		message_vision(HIW"\t$N身形一變，施展出幽冥身法幻化為四個分身，將$n團團圍住。\n\n\t只見$N四個身形同時聚起連串天魔刀，準備使出惡霸掌中最強一式\n\n\t\t\t『"+HIR"天魔亂舞"+HIW"』\n\n\t霎時間$N八掌齊發，滿天刀芒向四周狂射而出！\n\n\n"NOR,me,target);
		me->add("force", -90);
		damage = me->query_skill("badstrike",1)+me->query_skill("badforce",1)+skill*2+bellpower;
		while(i--) {
            if (random(9)>=2) {
				enemy[i]->receive_wound("kee", damage);
				message_vision(HIC"$N一個失守，只好照單全收，霎時間刀芒如雨點般落在$N身上！\n"NOR,enemy[i]);
				COMBAT_D->report_status(enemy[i]);
			} else {
				message_vision(HIM"只見$N狼狽的從漫天刀網中鑽了出來，不過倒是沒受什麼傷。\n"NOR,enemy[i]);
				COMBAT_D->report_status(enemy[i]);
			}
        me->start_busy(1);
		break;
		}
	}
   if (me->query("functions/evil-blade/level") < 100) {

	function_improved("evil-blade",random(me->query("force")/10+bellpower/10));

   }
	return 1;
}

