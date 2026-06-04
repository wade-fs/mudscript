#include <ansi.h>

int exert(object me, object target)
{
	int mkee = me->query("max_kee");
	if(!target->query("quest/new_gold_fire",1)){
                tell_object(me, "這是極火功\新功\能，必須重解謎才能用\n");
                return 1;
        }
        if( target!=me ) {
                tell_object(me, "你只能幫自己療傷。\n");
                return 1;
        }
        if( me->is_fighting() ) {
                tell_object(me, "戰鬥中運功\療傷﹖找死嗎﹖\n");
                return 1;
        }
	if(me->query("eff_kee") >= mkee)
	{
	tell_object(me, "你並沒有受傷。\n");
	return 1;
	}
        if( (int)me->query("force") < 50 ) {
                tell_object(me, "你的內力不夠，無法使用極火功\來療傷。\n");
                return 1;
        }
	if( me->query_condition("mogi") )
        return notify_fail("[1;32m身上的入滅之毒忽然發作,使內息受到影響無法運氣療傷[0m\n");

        write( HIR + "你席地運起『極火功\』中的療傷心法，一股火焰在身上不停燃燒，內傷已漸漸化解。\n" + NOR);
        message("vision",me->name()+"運起『極火功\』中的療傷心法，一股火焰在身上不停燃燒，不久，吐出一口瘀血，看起來好多了。\n",environment(me), me);

        me->receive_curing("kee", ( 10 + (int)me->query_skill("force")/20 + (int)me->query_skill("fireforce")/10 ));
        me->add("force", -35 );
        if( me->query("force") < 0 )
                me->set("force", 0);

        return 1;
}
