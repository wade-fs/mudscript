// recover.c

int exert(object me, object target)
{
        if(target!=me)
          return notify_fail("你只能用內功\恢復自己的靈氣。\n");
        if(!me->query("sec_kee"))
	  return notify_fail("你的身上沒有靈氣。\n");
	if( (int)me->query("force") < 20 )
	  return notify_fail("你的內力不夠。\n");

        me->add("s_kee",1+(int)me->query_skill("force")/10);
        if(me->query("s_kee")>me->query("max_s_kee"))
          me->set("s_kee",me->query("max_s_kee"));
	me->add("force", -20);

//        message_vision("[36m$N將體中的內力化成靈氣﹐使靈氣轉強。[0m\n",me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
