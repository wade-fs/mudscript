#include <ansi.h>
int perform(object me,object target)
{
	int i;
	object *all;
	if( me->query("sen") < 10 )
		return notify_fail("你的精神不夠集中﹐無法用拋磚引玉之計。\n");
	if( me->query_temp("confused"))
		return notify_fail("你的計謀還在運行中，不需要再次運行\n");
// 儒門...
    if( me->query("family/family_name") != "儒門")
		return notify_fail("不是儒生，不給你用咧！！^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
  if(!me->query("quests/confused"))
    return notify_fail("你不懂這個兵法！\n");
     if( me->query_skill("plan",1) < 110 )
		return notify_fail("你的謀略程度不夠。\n");
    me->add("sen",-15);
	message_vision( CYN + @LONG
$N開始施行拋磚引玉之計，企圖用相似的東西去迷惑對方，可以讓對手做出錯誤的判斷。
LONG + NOR , me );
	me->set_temp("confused",1);
  me->start_busy(1);
  me->start_call_out((:call_other,__FILE__,"remove_effect",me:),60);

	return 1;
}


void remove_effect( object me)
{
  me->delete_temp("confused");
  tell_object(me,CYN"你精神一鬆，把拋磚引玉之計拋在腦後了。\n"NOR);
}

