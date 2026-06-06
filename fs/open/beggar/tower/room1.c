inherit ROOM;
#include <ansi.h>
#include "check.c"
#include "tower.msg"
string *exit = ({ __DIR__"room2",__DIR__"room2",__DIR__"room2",__DIR__"room2",});
object room = this_object();
void create()
{
        set("short",HIR + "不死鳥ソ塔" + NOR);
        set("long", (: printf_msg :) );
        set("exits", ([
        "south" : exit[random(sizeof(exit))],
        "north" : exit[random(sizeof(exit))],
        "east"  : exit[random(sizeof(exit))],
        "west"  : exit[random(sizeof(exit))],
        ]));
        set("light", 1);
        set("no_auc", 1);
        set("no_quit", 1);
        set("no_scale",1);
        set("no_chome", 1);
        set("no_transmit",1);
        setup();

}

int valid_leave(object me,string dir)
{
      int num;
      object stair,tower1,tower2;
      me = this_player();
      me->set_temp("tower1",room);
      stair = me->query_temp("stair");
      tower1 = me->query_temp("tower1");
      tower2 = me->query_temp("tower2");
      if(room->query_temp("block"))   return notify_fail("先打倒面前的敵人再說吧!!\n");
      if(dir == me->query_temp("phoenix/way"+me->query_temp("pass")))
       {
        me->add_temp("pass",1);
        return ::valid_leave( me, dir );
       }else{
         message_vision(HIG + "塔頂的不死鳥發出一陣悲鳴，震得$N頭昏眼花，重重跌落。\n" + NOR,me);
         num = random(me->query_temp("floor"));
         me->set_temp("floor",num);
         me->set_temp("pass",2*num);
         stair->set("short",HIR + "不死鳥ソ塔" + HIG + "第"+chinese_number(me->query_temp("floor"))+"階" + NOR);
         tower1->set("short",HIR + "不死鳥ソ塔" + HIY + "第"+chinese_number(me->query_temp("floor"))+"層" + NOR);
         if(tower2)  tower2->set("short",HIR + "不死鳥ソ塔" + HIY + "第"+chinese_number(me->query_temp("floor"))+"層" + NOR);
         me->move(stair);
            }
}
