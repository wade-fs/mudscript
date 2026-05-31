// By Swy 最後修正 QC 98/6/20
//補上遇到沒有出口 或出口會消失時 使用技能會出錯的問題 by blazakira 2011/6/25

#include <ansi.h>
int perform(object me,object target)
{
  mapping exit = environment( me )->query("exits");
  string *dirs;
  int i;
  seteuid(getuid());
  if(!me->is_fighting(target))
    return notify_fail("三十六計只能在戰鬥中使用。\n");
  if( me->query("sen") < 5 ) 
    return notify_fail("你的精神不夠集中﹐無法使用三十六計。\n");
// 不是儒門
  if( me->query("family/family_name") != "儒門")
    return notify_fail("不是儒生，不給你用咧！！^_^\n");
  if( !me->query("quests/god-plan"))
    return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
  if( !exit ) return notify_fail("這裡無處可逃﹗\n");
  me->add("sen",-5);
  me->add("gin",-50);
  if(80>random(100)) {
    message_vision( HIY + @LONG
$N見情勢不利﹐使用第三十六計﹐離開了現場﹗
LONG + NOR , me );
    dirs = keys( exit );
    if( sizeof(dirs)==0 ) {
      message_vision( HIC + @LONG

糟糕！出口勒！！！$N找不到出口又重新出現在戰場上了。

LONG + NOR , me );
      return 1;
    }
    i = random( sizeof(dirs) );
    load_object( exit[dirs[i]] );
    me->move( exit[dirs[i]] );
  } else {
    message_vision( HIW + @LONG
$N見情勢不利﹐使用第三十六計﹐但被敵人識破了﹗
LONG + NOR , me );
    me->start_busy(1);
  }
  return 1;
}
