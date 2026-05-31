#include <ansi.h>
inherit SSERVER;

int update_condition(object me, int duration)
{
        int now_level,i;
        object *enemy;

        if(duration==0)
        {
          return 0;
        }
        me->apply_condition("level_up",1);
        if(!now_level=me->query_temp("level/now_level"))
          me->clear_condition("level_up");
  if(!me->query_temp("leveluping"))
  switch(now_level){
    case 1:
      if(!me->query_temp("leveluping"))
      message_vision(HIY"金色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 2:
      if(!me->query_temp("leveluping"))
      message_vision(HIC"藍色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 3:
      if(!me->query_temp("leveluping"))
      message_vision(HIM"紫色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 4:
      if(!me->query_temp("leveluping"))
      message_vision(HBRED+HIW"紅色和白色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 5:
      if(!me->query_temp("leveluping"))
      message_vision(HBRED+HIY"紅色和金色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 6:
      if(!me->query_temp("leveluping"))
      message_vision(HBRED+HIC"紅色和藍色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 7:
      if(!me->query_temp("leveluping"))
      message_vision(HBRED+HIM"紅色和紫色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 8:
      if(!me->query_temp("leveluping"))
      message_vision(HBCYN+HIW"藍色和白色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 9:
      if(!me->query_temp("leveluping"))
      message_vision(HBCYN+HIY"藍色和金色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 10:
      if(!me->query_temp("leveluping"))
      message_vision(HBCYN+HIM"藍色和紫色的鬥氣不斷的在$N身邊翻滾著!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    default:
      return 1;
  }
  if(me->is_fighting()){
    enemy=me->query_enemy();
    for(i=0;i<sizeof(enemy);i++){
      if(enemy[i])
        if(500 > random(1000))
          enemy[i]->start_busy(1);
        else
          enemy[i]->start_busy(now_level);
    }
    message_vision(BLINK+HIY"$N身邊的敵人受到$N身旁鬥氣的影響，行動受到了牽制!!\n"NOR,me);
  }
        return 1;
}
