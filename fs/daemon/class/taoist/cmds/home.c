

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me, string arg)
{
  object room=environment(me);
  if( me->is_fighting() )
        return notify_fail("戰鬥中無法使用。\n");
  if(room->query("no_transmit"))
	return notify_fail("大神擊毀了你招來的雲朵\n");
  message_vision (HIY + "$N的袖子隨手一甩，使出「回歸」仙術。\n"+
		HIW + "只見一朵白雲托著$N向天際飛去。\n" + NOR,me);
  me->move("/open/tendo/room/t07");
  message_vision(
	HIW + "一朵白雲緩緩降下，$N從雲上瀟灑地走下來。\n" + NOR,me);

  return 1;
}




