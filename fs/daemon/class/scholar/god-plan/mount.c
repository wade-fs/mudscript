//增加出口是否存在的判斷 by blazakira 2011/9/26

#include <ansi.h>

int perform(object me, object target)
{
  mapping exit = environment( me )->query("exits");
  string *dirs;
  int i;
  seteuid(getuid());
  if( !target || target == me ) return notify_fail("你要對誰用計？\n");
  if( sizeof(exit) < 1 || !exit ) return notify_fail("這裡無處可逃！\n");
  if( me->query("sen") < 10 )
    return notify_fail("你的精神力不夠，無法用計。\n");
  if(environment(me)->query("no_plan"))
    return notify_fail("此地方無法用計。\n");
  if( target->query_temp("mount")==1)
    return notify_fail("對同一人只能用一次。\n");
  if(target->query("no_mount")==1)
    return notify_fail("此計對此人無效。\n");
  if( me->query_skill("plan", 1) < 20)
    return notify_fail("你的謀略能力不夠。\n");
// 不是儒門
  if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！^_^\n");
  if( !me->query("quests/god-plan"))
    return notify_fail("你沒解過孔明兵法的謎，不給你用咧！^_^\n");
  me->add("sen",-10);
  message_vision("$N對"+ target->name()+ "使出調虎離山之計，誘敵出山，使我就範。\n",me,target);
  if(target->query_temp("no_plan") || target->query("no_plan"))
  {
    message_vision("$N大喝道：調虎離山？你用錯地方了，去死吧!!\n",target);
    target->kill_ob(me);
    me->start_busy(3);
  }
  else {
    message_vision(""+ target->name()+ "中計後便口中念念有詞的跑開了...\n",me,target);
    dirs = keys( exit );
    i = random( sizeof(dirs) );
    load_object( exit[dirs[i]] );
    target->move( exit[dirs[i]] );
  }
  target->set_temp("mount",1);
  return 1;
}
