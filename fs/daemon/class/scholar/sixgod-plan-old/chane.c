// buy sueplane 金蟬脫殼
#include <ansi.h>
object user;
int perform(object me,object target)
{
    int i,flag=0;
	object *all = me->query_enemy();
    object ob;
        if(!me->is_fighting())
        return notify_fail("金蟬脫殼只能在戰鬥中使用。\n");
    if( me->query("sen") < 100 )
        return notify_fail("你的精神不夠集中﹐無法使用六韜奇略。\n");
    if( all[i]->query_temp("chane")==1 )
                  return notify_fail("相同的謀略﹐再使用就失效了。\n");
	if( me->query_skill("plan",1) < 30 )
        return notify_fail("你的謀略能力不夠。\n");
    me->add("sen",-10);
// 不是儒門的化....
        if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
        message_vision( HIW + @LONG
$N使用六韜奇略中的『金蟬脫殼』，留下本身的殘影戰鬥!!!
LONG + NOR , me );
		for( i = 0 ; i < sizeof(all) ; i ++ ) 
                all[i]->set_temp("chane",1);    //
      for(i=0;i<sizeof(all);i++)
      {
      if(all[i]->query_temp("no_plan") || all[i]->query("no_plan"))
      {
    flag=1;
message_vision("$N嘿嘿笑道:對我使用金蟬脫殼???哈哈,你搞錯對象了吧!!\n",all[i]);
      all[i]->kill_ob(me);
      me->start_busy(2);
      }
      }
    if(!flag)
     {
        user = this_player();
        ob=new("/u/s/sueplan/sixgod-plan/npc/yun.c");
        ob->move(environment(this_player()));
        ob->set_leader(me);
        ob->fight(all);
        ob->invocation(user);
		me->remove_all_killer();
    }
        return 1;
}

