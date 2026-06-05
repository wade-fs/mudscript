#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
int conjure (object me,object target)
{
fun=me->query("spells/mirror/level");
	if (!me->query("spells/mirror/level"))
     		return 0;
	if(me->query("class")!="dancer")
		return notify_fail("這法術只有舞者能用。\n");
	if( !target ) target = offensive_target(me);
	if(me->query_temp("mirror")==1)
		return notify_fail("妳的神靈尚未歸位!!\n");
  if(!target) 
    return notify_fail("施法要有對像！\n");
		message_vision(HIW + "$N三魂之一的神靈飛入了$n的體內!!\n" + NOR,me,target);
		tell_object(me,HIM + "         ※※※※※※" + HIW+target->query("name")+HIM + "※※※※※※" + NOR + "
        
                " + HIW + "經驗："+target->query("combat_exp")+"\n" + NOR);
	if(fun>20)
		tell_object(me,HIW + "\n                精力："+target->query("gin")+NOR + "

                " + HIW + "氣血："+target->query("kee")+NOR + "

                " + HIW + "神瞑："+target->query("sen")+NOR + "

                " + HIW + "內力："+target->query("force")+"\n" + NOR);
	if(fun>60)
		tell_object(me,HIW + "\n                運行功\力："+target->query("force_factor")+"\n" + NOR);
		me->set_temp("mirror",1);
		call_out("message",30,me);
        return 1;
}

int message()
{
object me=this_player();
	message_vision(HIW + "$N的神靈回歸本位了。\n" + NOR,me);
	if(fun<100) spell_improved("mirror",random(500));
		me->delete_temp("mirror");
return 1;
}
