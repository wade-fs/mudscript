#include <ansi.h>
// By Swy 最後修正 QC 98/6/20
// 改為可重複使用，不過命中率逐次降低。 by frequency 2003 7/29
int perform(object me,object target)
{
	if( me->query("sen") < 10 )
		return notify_fail("你的精神不夠﹐無法使用。\n");
        if( me->query_skill("plan",1) < 60 )
		return notify_fail("你的謀略程度不夠。\n");
	if( !target ) return notify_fail("你要對誰用計 ?\n");
	if(me->is_fighting(target))	
		return notify_fail("奇襲之計只能在戰鬥前使用。\n");
  if( environment(me)->query("no_fight")==1 )
  return notify_fail("這裡不準戰鬥。\n");
if( userp(target) && target->query("age")<16)
    return notify_fail("不能對未滿16歲奇襲喔。\n");
  if(target->query("no_speed")==1)
  return notify_fail("奇襲對他無效！\n");
  /* if( target->query_temp("speed")==1 )
                return notify_fail("相同的計策對同一個人沒有效。\n");*/
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
   if(target->query("family/privs") == -1 &&  uptime() % 900 < 300 )
     {
                return notify_fail("對不起，現在不是時候。\n");
       }
	me->add("sen",-15);
// 不是儒門
   if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
    me->start_busy(1);
	message_vision( RED + @LONG
$N突然地對$n發動奇襲﹐殺得$n措手不及﹗
LONG + NOR , me , target );
	if(me->query_temp("invis")==1)
	{
        me->delete_temp("invis");
target->add_temp("speed",1);
target->start_busy(4);
        me->kill_ob(target);
        target->kill_ob(me);
	}
	else
	    {
	     if(random(5+target->query_temp("speed")) < 4)
             {
              message_vision( RED + @LONG
$N對$n發動奇襲﹐殺得$n措手不及﹗
LONG + NOR , me , target );
              target->start_busy(3);
              target->add_temp("speed",1);
	      me->kill_ob(target);
	      target->kill_ob(me);
	     }else{
	      message_vision( HIG + @LONG
$n識破了$N的奇襲之計﹐盛怒之下展開猛攻。
LONG + NOR ,me , target );
              target->kill_ob(me);
              me->start_busy(1);
	      }
	    }
	return 1;
}

