// 傳送內力

int exert(object me, object target)
{
	if( target == me ) 
		return notify_fail("你只能傳內力道別人身上。\n");	
	if( !target->is_character() || !living(target) )
		return notify_fail("這東西並不是活物。\n");
	if( target->query_skill_mapped("force") != me->query_skill_mapped("force") )
      if(!(target->query("class")=="doctor" && target->query_temp("saving_die")))
		return notify_fail("對方內功\的種類與你相異, 無法輸送。\n");
	if( target->is_fighting() || me->is_fighting() )
		return notify_fail("戰鬥中無法運功\。\n");
	if( (int)me->query("force") < 100 )
		return notify_fail("你的內力不夠。\n");

	me->add("force", -100);
	target->add("force",60);
	if( target->query("force") > target->query("max_force") )
		target->set("force",target->query("max_force"));
	message_vision("[36m$N將雙手置於$n百會與膻中兩大穴﹐一股內勁由$N的手掌鑽入$n體內﹐與$n本身內力互相融合。[0m\n", me, target);

	return 1;
}
