//Written By AceLan 98.7.22 趁火打劫之計...
// 改為可重複使用，不過命中率逐次降低。 by frequency 2003 7/29
#include <ansi.h>

int perform(object me, object target)
{
   if( !target ) return notify_fail("你要對誰用計？\n");

   if( !target->is_fighting() || !target->is_killing())
      return notify_fail("趁火打劫之計只能趁敵人陷入危戰之時，趁其不備，發動攻擊。\n");

   if( me->is_fighting() || me->is_killing())
      return notify_fail("泥菩薩過江，自身難保了，怎麼還會有餘力來趁火打劫呢？\n");

   if( me->query("sen") < 20 )
      return notify_fail("你的精神力不夠﹐無法用計。\n");

/*if(target->query_temp("rob")==1)
return notify_fail("同一計謀只能用一次！！\n");*/
   if( me->query_skill("plan",1) < 30)
      return notify_fail("你的謀略能力不夠。\n");
// 不是儒門
   if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
   me->start_busy(1);
   me->add("sen",-20);
   if(random(5+target->query_temp("rob")) < 4)
   {
    target->start_busy(4);
    target->add_temp("rob",1);
      message_vision("$N使出趁火打劫之計, 趁敵之危, 就勢取利, 向敵人發動猛攻\n", me);
      me->kill_ob( target);
   }else{
	      message_vision( HIG + @LONG
$n識破了$N的趁火打劫之計﹐盛怒之下展開猛攻。
LONG + NOR ,me , target );
              target->kill_ob(me);
	      }
   return 1;
}

