inherit ROOM;
#include <ansi.h>
object me = this_player();
void create()
{
        set("short",HIY"不死鳥ソ塔最上部"NOR);
        set ("long", @LONG 
在這距接近雲端的塔頂上，雖然刮著強勁的颶風，
但更有無盡千年不滅焰火正生生不息的燃燒著，這象徵
破壞原力和永世不息生命的轉生之焰，如今正異常旺盛
的燃燒著，是否將這古老巨塔將橫生異變？
LONG);

        set("light", 1);
        set("no_auc", 1);
        set("no_quit", 1);
        set("no_scale",1);
        set("no_chome", 1);
        set("no_transmit",1);
        set("objects", ([ /* sizeof() == 1 */
        "/open/beggar/npc/tower/phoenix.c" : 1,
        "/open/beggar/tower/sign" : 1,
                ]));
  set("exits", ([ /* sizeof() == 8 */
      "enter" : "/open/beggar/tower/top1",
]));

        setup();
}


void init()
{
  add_action("do_jump","jump");
}

int do_jump(string str){
  object me;
  me = this_player();
  if(!str || str != "tower")
  {
     tell_object(me,"你想跳到那裡？\n");
     return 1;
  }
if (me->query("beggar/got_phoenix")==1) { me->add("sen",-100);tell_object(me,"你縱身往塔外一跳，頓時神智昏迷，迷迷糊糊中被傳到某一地方.....。\n");me->move("/open/north-polar/store");return 1;   }
  if(!me->query_temp("ko_phoenix"))
  {
    tell_object(me,"你還沒打敗鳳凰就想逃跑？至少先打過一次吧！\n");
    return 1;
  }
  me->add("sen",-100);
  tell_object(me,"你縱身往塔外一跳，頓時神智昏迷，迷迷糊糊中被傳到某一地方.....。\n");
  me->move("/open/north-polar/store");
  return 1;           
}

