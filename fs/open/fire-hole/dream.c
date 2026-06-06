#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIC + "夢之大地" + NOR);
  set ("long", @LONG
你感到兩股莫名強大的氣息在夜空中徘徊著，這兩股氣勁都有著魔族特有的陰森詭譎，
然而亦有令人神馳目眩的嫵媚形影，奇怪的是，他們同時也散發著古老的氣息，你試著回想
起一生聽過的各種武林異聞，這兩氣勁主人的真實身分已呼之欲出......
LONG);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/open/fire-hole/npc/nightmare1" : 1,
  "/open/fire-hole/npc/nightmare2" : 1,
                   ]));
  setup();
}

void init()
{
      call_out("do_check",1,this_player()); 
}


void do_check(object me)
{
    object wave;
    me = this_player();
    if(me->query_temp("find_scroll") == 3)
    {
     me->start_busy(500);
     me->delete_temp("got_help");
     wave = present( "wave heart",environment(me) );
     if(wave) destruct(present("wave heart"));
     call_out("do_help",1,me);
    }
}

int do_help( object me )
{
	object wave;
	me = this_player();
        remove_call_out("do_help");
	if(me->query("gin") < 0.4*me->query("max_gin") ||
	   me->query("kee") < 0.4*me->query("max_kee") ||
	   me->query("sen") < 0.4*me->query("max_sen"))
	   {
	     if(me->is_unconcious())  me->revive();
             me->set("kee",me->query("max_kee"));
             me->set("sen",me->query("max_sen"));
             me->set("gin",me->query("max_gin"));
	     message_vision(HIW + "
	     正當$N將要敗戰的同時，一道耀眼光芒劃破寂靜的夜空，直達$N身前，
	     如天神般阻擋了雙妖進攻。他，終於出現了，夜夢雙妖的宿敵
	     
	                      " + HIR + "──" + HIM + "浪清心" + HIR + "──\n\n" + NOR,me);
             wave = new("/open/fire-hole/npc/wave");
             wave->move(environment(me));
             me->remove_all_killer();
             me->set_temp("got_help",1);
             me->start_busy(90);
             call_out("check_end",1,me);
           }else{
                  call_out("do_help",1,me);
                 }
        return 1;
}

int check_end()
{
   object nightmare1,nightmare2,wave,me;
   me = this_player();
   nightmare1 = present( "nightmare en",environment(me) );
   nightmare2 = present( "nightmare lan",environment(me) );	
   wave = present( "wave heart",environment(me) );
   if(!nightmare1 && !nightmare2 && wave)
   {
     message_vision(HIW + "\n激戰過後，$N在人界還陽的時限也到了，身體逐漸崩毀...\n" + NOR,wave);
     wave->delete_temp("supertengin");
     call_out("do_end1",5,me);
   }else{call_out("check_end",2,me);}
   return 1;
}

int do_end1()
{
   object wave,me;
   me = this_player();
   wave = present( "wave heart",environment(me) );
   message_vision(HIW + "\n$n回頭對$N一笑，彷彿再也沒有任何牽掛，接著，化作一股清煙，飛向天際而去。\n" + NOR,me,wave);
   destruct(present("wave heart"));
   call_out("do_end2",8,me);
   return 1;
}

int do_end2(object me)
{
    me = this_player();
   message_vision(HIC + "\n$N全身脫力，再也支撐不住，終於倒在地上，不省人事。\n" + NOR,me);
   me->unconcious();
   call_out("do_end3",8,me);
   me->set_temp("find_scroll",4);
    me->move( __DIR__"scroll_room.c");
   return 1;
}

int do_end3(object me)
{
   me = this_player();
   me->revive();
   return 1;
}
