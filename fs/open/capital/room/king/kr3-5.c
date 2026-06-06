// Room: /open/capital/room/king/kr3-5
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "鳳息亭");
	set( "build", 24 );
  set ("long", @LONG
這是平常皇上後宮佳麗們聚會的地方，這裡百花片野，遍地飄香
，有時皇上也會和親信大臣來此地聊一聊國家大事，你看到亭裡的石
桌上擺著一些空酒瓶，酒杯，不知是誰來此地喝酒忘了收了。
LONG);

  set("outdoors", "/open/capital");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kr3-6",
]));

  setup();
}
void init()
{
        add_action("do_exert","exert");
}
int do_exert(string str)
{
 object me;
 me=this_player();
 if(str=="roar"){
 message_vision(HIC"皇宮守衛大聲的對你說:皇城禁地豈容你大聲喧嘩，還不快滾!!!\n"NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}
