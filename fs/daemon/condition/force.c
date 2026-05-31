#include <ansi.h>
#include <localtime.h>

string * msg = ({
 HIW "一陣內力從$N的丹田流出，緩緩的穿過全身，最後再回到丹田之處。\n"NOR,
 HIW "$N集中心智將引導內力在體內做幾個週天循環。\n"NOR,
 HIW "$N的內息簡直如同江河一般，在體內奔騰不息。\n"NOR,
 HIW "$N的內息變成一條條清晰的水流，進而水流越來越急，經脈隨之被擴張。\n"NOR,

    });
int update_condition(object me, int duration)
{
  int not_robot = 1;
  int *ttime = localtime(time());

  if(me->query_temp("not_robot") > time() || 
    (ttime[LT_HOUR] > 0 && ttime[LT_HOUR] < 8 ))
  {
    not_robot = 0;
  }
  if( duration < 1  )
  {
    return 0;
  }
  if(me->is_fighting()) {
    me->start_busy(2);
    me->apply_condition("hart",me->query_skill("force")/10);
    message_vision(HIY"$N一陣內力亂竄，內息一滯，運行的內功\竟然走岔了！\n"NOR , me);
    me->set("force",0);
    me->apply_condition("force",0);
    return 0;
  }
  if(me->query("force") < 300)
  {
    message_vision(HIY"$N的內力不足以驅動全身的內息。\n"NOR , me);
    me->apply_condition("force",0);
    return 0;
  }
  if(duration < 2 ) 
  {
    int force = me->query_skill("force")/5;
    me->improve_skill( "force", force + random(force), not_robot );
    me->add("force",-force);
    message_vision(
        HIW "$N到了最後收功\的時刻了。\n"NOR,me);

  }
  else
  {
    int force = me->query_skill("force")/2;
    if(me->query_skill("force",1) > 1000) force = force / 2;
    me->add("force",-force);
    me->improve_skill( "force", force + random(force), not_robot );
    message_vision(msg[random(sizeof(msg))] , me);

  }
  me->apply_condition("force",duration-1);
  return 1;
}
