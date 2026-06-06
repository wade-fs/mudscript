// 給基本 force
#define ALLOW ({"fighter","bonze","prayer","doctor"})
int exert(object me,object target)
{
	int power;
int max=me->query("max_kee",1);
int maxt;
if(target)
maxt=target->query("max_kee",1);
	if( (int)me->query("force") < 30 )
		return notify_fail("你的內力不夠。\n");
	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("戰鬥中無法療傷。\n");
    if( member_array(me->query("class"), ALLOW) == -1 && !wizardp(me))
		return notify_fail("你的職業無法療傷。\n");
if(me->query("eff_kee")==max && !target)
return notify_fail("你沒有受傷。\n");
if(target)
  if(target->query("eff_kee") >= maxt)
    return notify_fail(target->query("name")+"沒有受傷\n");
      if(me->query_condition("mogi"))
        return notify_fail("身上的入滅之毒忽然發作,使內息受到影響無法運氣療傷\n");
       if(target->query_condition("mogi"))
        return notify_fail("對方身上的入滅之毒,使你無法幫他運氣療傷\n");
        power = 5 + (int)me->query_skill("force")/10;
	if( target==me ){
		message_vision("$N盤腿席地而坐﹐運行全身內力療傷﹐一陣白氣從$N頭頂冒出後, 傷勢已慢慢轉好。\n", me);
	}
	else{
		message_vision("$N盤腿席地而坐﹐運行全身內力幫助$n療傷, 一陣白氣從頭頂冒出後, $n傷勢已慢慢轉好。\n", me, target);
                power = power/2;
	}
        me->receive_curing("kee", power );
        if(wizardp(me)) me->clear_condition();
    if(target)
      if(target != me) target->receive_curing("kee",power);
	me->add("force", -30);
	return 1;
}
