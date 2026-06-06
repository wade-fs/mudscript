#include <ansi.h>
int floor,i;
void init()
{
  object me = this_player(),room = this_object();
  string dir;
  floor = me->query_temp("floor");
  if(!userp(me))  return;
  room->set("short",HIR + "不死鳥ソ塔"HIY + "第"+chinese_number(me->query_temp("floor"))+"層" + NOR);
  if(me->query_temp("pass") == (1+me->query_temp("floor"))*2)
  room->pass();
  else{
         if(!me->query_temp("phoenix"))    //剛進塔時定義所有樓層的正確路徑
         {
          for(i=0;i<100;i++)
           {
              switch(random(4))
               {
                case 0:
                       dir = "north";
                break;
                case 1:
                       dir = "south";
                break;
                case 2:
                       dir = "west";
                break;
                case 3:
                       dir = "east";
                break;
               }
              me->set_temp("phoenix/way"+i,dir);
            }
          }
     if(!me->query_temp("ko_phoenix")){
       if( floor > 43 && me->query_temp("ko_lion") <11)
          {
             new("/open/beggar/npc/tower/mob1")->move(room);
             room->set_temp("block",1);
           }else if( floor > 36 && floor < 43 && me->query_temp("ko_seal")<11)
                 {
                   new("/open/beggar/npc/tower/mob2")->move(room);
                   room->set_temp("block",1);
                 }else if( floor > 29 && floor < 36 && me->query_temp("ko_walrus")<11)
                 {
                   new("/open/beggar/npc/tower/mob3.c")->move(room);
                   room->set_temp("block",1);
                 }else if( floor > 22 && floor < 29 && me->query_temp("ko_seal")<11)
                 {
                   new("/open/beggar/npc/tower/mob2")->move(room);
                   room->set_temp("block",1);
                 }else if( floor > 15 && floor < 22 && me->query_temp("ko_seal")<11)
                 {
                   new("/open/beggar/npc/tower/mob2")->move(room);
                   room->set_temp("block",1);
                 }else if( floor > 8 && floor < 15 && me->query_temp("ko_walrus")<11)
                 {
                   new("/open/beggar/npc/tower/mob3")->move(room);
                   room->set_temp("block",1);
                 }else if( floor < 8 && me->query_temp("ko_bear")<11)
                 {
                   new("/open/beggar/npc/tower/mob4")->move(room);
                   room->set_temp("block",1);
                 }
                 }else{
       if(!me->query_temp("ko_liung") && floor > 43)
          {
             new("/open/beggar/npc/tower/liung.c")->move(room);
             room->set_temp("block",1);
           }else if(!me->query_temp("ko_lan") && floor > 36 && floor < 43)
                 {
                   new("/open/beggar/npc/tower/lan.c")->move(room);
                   room->set_temp("block",1);
                 }else if(!me->query_temp("ko_pin") && floor > 29 && floor < 36)
                 {
                   new("/open/beggar/npc/tower/pin.c")->move(room);
                   room->set_temp("block",1);
                 }else if(!me->query_temp("ko_hung") && floor > 22 && floor < 29)
                 {
                   new("/open/beggar/npc/tower/hung.c")->move(room);
                   room->set_temp("block",1);
                 }else if(!me->query_temp("ko_chung") && floor > 15 && floor < 22)
                 {
                   new("/open/beggar/npc/tower/chung.c")->move(room);
                   room->set_temp("block",1);
                 }else if(!me->query_temp("ko_cow") && floor > 8 && floor < 15)
                 {
                   new("/open/beggar/npc/tower/cow.c")->move(room);
                   room->set_temp("block",1);
                 }else if(!me->query_temp("ko_lee") && floor < 8)
                 {
                   new("/open/beggar/npc/tower/lee.c")->move(room);
                   room->set_temp("block",1);
                 } 
                 }
        }
}


int pass()
{
  object me,stair,tower1,tower2;
  me = this_player();
  if(me->query_temp("floor") == 49)
  {
   message_vision(HIY + "\n費盡千辛萬苦，$N終於抵達了不死鳥之塔最上部。\n\n" + NOR,me);
   if (me->query_temp("ko_phoenix")==1)
   {
    me->move("/open/common/room/inn");
    new("open/beggar/tower/door")->delete_temp("have_player");
   }
   else
   {
    me->move(__DIR__"stair2.c"); 
    new("/open/beggar/tower/door")->delete_temp("have_player");
   }
  }
  else
  {
   stair = me->query_temp("stair");
   tower1 = me->query_temp("tower1");
   tower2 = me->query_temp("tower2");
   message_vision(HIR + "\n突然間，赤紅靈光大盛，你在紅色光幕的籠罩之下，身影逐漸消失...\n\n" + NOR,me);
   if(me->query_temp("floor") < 44) me->add_temp("floor",1+random(5));
   else me->add_temp("floor",1);
   me->set_temp("pass",2*me->query_temp("floor"));
   stair->set("short",HIR + "不死鳥ソ塔"HIG + "第"+chinese_number(me->query_temp("floor"))+"階" + NOR);
   tower1->set("short",HIR + "不死鳥ソ塔"HIY + "第"+chinese_number(me->query_temp("floor"))+"層" + NOR);
   tower2->set("short",HIR + "不死鳥ソ塔"HIY + "第"+chinese_number(me->query_temp("floor"))+"層" + NOR);
   me->move(stair);
  }
}

