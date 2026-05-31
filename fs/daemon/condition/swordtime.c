#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("swordtime",1);
     message_vision(HIR"$N覺得時間一分一秒的逼近。\n"NOR,me);
     me->apply_condition("swordtime",duration-1);
 if (duration < 1) {
     me->delete_temp("swordtime",1);
    if (me->query("class") == "swordsman")
    {
     message_vision(HIW"劍聖歐陽無極正召喚$N。\n"NOR,me);

     me->set("swordquest/findball",1);
     me->move("/open/gsword/second/room/sword/s29.c");
    }
 if (me->query("class") == "blademan")
{
     message_vision(HIW"刀神龍震元正召喚$N。\n"NOR,me);
     me->set("swordquest/findball",1);
     me->move("/open/gsword/second/room/blade/b29.c");
 }
if (me->query("class") == "scholar")
{
     message_vision(HIW"儒俠文冠天正召喚$N。\n"NOR,me);
     me->set("swordquest/findball",1);
     me->move("/open/gsword/second/room/scholar/sch29.c");
 }
      return 0;
   }
    return 1;
}
