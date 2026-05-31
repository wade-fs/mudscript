#include <ansi.h>
int update_condition(object me, int duration)
{
if( duration >= 1 )
  {
     tell_object(me,HIG"\n你身上散發出陣陣魔氣. \n"NOR);
     message("vision",me->name() + HIG"身上發出異於當今武林各大門派的魔氣！\n"NOR,
      environment(me), me);
   }
  if( duration < 1 )
  return 0;
  return 1;
}
