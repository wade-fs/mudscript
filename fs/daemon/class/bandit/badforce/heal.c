// heal.c by ice
// modify by oda (96/4/19)

#include <ansi.h>

int exert(object me, object target)
{
	int bellpower=me->query("bellicosity")/100 + 1;

	if( target!=me ) {
		tell_object(me, "你只能幫自己療傷。\n");
		return 1;
	}
	if( me->is_fighting() ) {
		tell_object(me, "戰鬥中運功\療傷﹖找死嗎﹖\n");
		return 1;
	}
	if( me->query_condition("mogi") ) {
		tell_object(me, HIG"你身上的入滅之毒忽然發作,使內息受到影響無法運氣療傷\n"NOR);
		return 1;
	}
	if( (int)me->query("force") < 50 ) {
		tell_object(me, "你的內力不夠，無法使用天魔金身的心法來療傷。\n");
		return 1;
	}

/*
	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("你已經受傷過重，只怕一運真氣便有生命危險！\n");
*/
        if(me->query("class") != "bandit")
        return notify_fail("只有惡人能用天魔金身療傷。\n");
	write( HIW "你席地運起" + HIY "『天魔金身』" + HIW "中的療傷心法，一股邪惡的殺氣充滿全身，令你覺得舒服多了。\n" NOR);
	message("vision",
		me->name() + "運起天魔金身開始療傷，泛著金光的身上不停的冒出汗珠，不久，吐出一口瘀血，看起來好多了。\n",
		environment(me), me);

me->receive_curing("kee", ( 10 + (int)me->query_skill("force",1)/10 + (int)me->query_skill("badforce",1)/10 ) * bellpower );
	me->add("force", -( 45 + bellpower * 3 ) );
	if( me->query("force")<0 )
		me->set("force", 0);

	return 1;
}
