#include <ansi.h>

int exert(object me, object target)
{
  if(!target->query("highsworder",1)){
                tell_object(me, HIR"這是血魔心法的功\能，必須劍士解謎後方能才能用\n"NOR);
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
        if( (int)me->query("force") < 100 ) {
                tell_object(me, "你的內力不夠，無法使用極火功\來療傷。\n");
                return 1;
        }
	if( me->query_condition("mogi") )
        return notify_fail("[1;32m身上的入滅之毒忽然發作,使內息受到影響無法運氣療傷[0m\n");

        message_vision(HBRED"你席地運起『血魔心法』中的療傷心法，一股血氣自$N身上竄出，瞬間$N內傷已漸漸好轉。\n"NOR,me);
        me->receive_curing("kee", ( 10 + (int)me->query_skill("force")/10 + (int)me->query_skill("blood_force")/8 ));
        me->add("force", -60 );
        if( me->query("force") < 0 )
        me->set("force", 0);
        return 1;
}
