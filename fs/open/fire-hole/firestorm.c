#include <ansi.h>
void init()
{
      if( 25 > random(this_player()->query_kar()) && this_player()->query("family/family_name") != "火龍窟")
       {
	this_player()->set_temp("firestorm",1);
	tell_object(this_player(),HIR + "\n一到刺眼的高熱焚風襲來，瞬間你感覺猶如身處煉獄。\n" + NOR);
       }
      call_out("do_check",1,this_player()); 
}
void do_check(object me)
{
   int damage;
if(!me) return ;
   if(me->query_temp("firestorm"))
    {
      if(me->query_temp("def_fire"))
      {
      	if(!me->query_temp("def_fire1"))
      	{
      	 tell_object (me,HIG + "你身上的焰氣訣降低了火焰的傷害。\n" + NOR);
      	 damage = 150;
        }
      	else
      	    {
      	    tell_object (me,HIC + "你身上的焰氣訣和龍王焰靈大幅降低了火焰的傷害。\n" + NOR);
      	    damage = 50;
            }
        }else if(me->query_temp("def_fire1"))
                         {
                          tell_object (me,HIM + "你身上的龍王焰靈減弱了火焰的傷害。\n" + NOR);
      	                  damage = 160;
                         }else{
                               tell_object (me,HIR + "你全身上下遭到相當嚴重的灼傷。\n" + NOR);
                               damage = 240;
                               }
       me->receive_damage("kee",damage);
       COMBAT_D->report_status(me);
       me->delete_temp("firestorm");
     }

      if(me->query("combat_exp" ) < 5000000 && userp(me) && living(me))
       {
        message_vision(HIR + "$N抵抗不了火龍幻界的熱度，被天神傳送回起點！\n" + NOR,me);
        me->move(me->query("startroom"));
        me->set( "clan/out","/open/center/room/inn");
       }else  
             me->set_temp("check_ok",1);
}
